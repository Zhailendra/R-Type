/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** NetworkSystem.cpp
*/
#include "NetworkSystem.hpp"
#include <ECS/../OstreamHelper.hpp>

void NetworkSystem::update()
{
    if (_networkEntity == nullptr) {
        for (auto &entity: *_entities.get()) {
            if (entity != nullptr &&
                entity->hasComponent<NetworkComponent>() &&
                entity != nullptr) {
                _networkEntity = entity;
                break;
            }
        }
    }
    if (_networkEntity == nullptr) return;

    auto &networkComponent = _networkEntity->getComponent<NetworkComponent>();
    if (!networkComponent._isInit) {
        for (unsigned short i = 1234; i < 65535; i++) {
            try {
                networkComponent.setClient(
                    new Network::Client<TemplateRefClient>(i, _entities));
                break;
            } catch (Network::Error &e) {
                if (i == 65534)
                    throw Network::Error("No port available");
                delete networkComponent._client;
                continue;
            }
        }
        networkComponent.setInit(true);
        auto client = networkComponent._client;
        Controller controller;
        for (auto &controller: controller.getHandlers()) {
            client->use(controller.first, controller.second);
        }
    }

    auto client = networkComponent._client;
    if (!client->_isConnected) {
        try {
            client->checkConnection(networkComponent._ip,
                networkComponent._port);
        } catch (Network::Error &e) {
            _networkEntity = nullptr;
            throw Network::Error("Connection failed");
            return;
        }
        Network::PacketType packetType = Network::PacketType::GatherAllEntities;
        Network::PacketNumber packetNumber = 0; // Need to be changed
        Network::Byte GatherAllEntitiesPacket;
        GatherAllEntitiesPacket << packetType;
        GatherAllEntitiesPacket << packetNumber;
        client->send(networkComponent._ip, networkComponent._port,
            GatherAllEntitiesPacket);
    }

    while(client->run()){};

    for (auto &entity: *_entities) {
        Network::EntityId entityId = entity->getId();
        if (client->_lastPosition.find(entityId) != client->_lastPosition.end() &&
            entity->hasComponent<PositionComponent>() &&
            entity->hasComponent<Velocity>() &&
            !entity->hasComponent<BulletComponent>() &&
            std::abs(client->_lastPosition[entityId].x - entity->getComponent<PositionComponent>().x) <= VELOCITY_SPEED_PLAYER &&
            std::abs(client->_lastPosition[entityId].y - entity->getComponent<PositionComponent>().y) <= VELOCITY_SPEED_PLAYER) {
            Velocity &velocity = entity->getComponent<Velocity>();
            PositionComponent &position = entity->getComponent<PositionComponent>();
            velocity.x = 0;
            velocity.y = 0;
            position.x = client->_lastPosition[entityId].x;
            position.y = client->_lastPosition[entityId].y;
        }
    }

    if (std::chrono::system_clock::now() - networkComponent._lastSend <
        networkComponent._interval) {
        return;
    }
    networkComponent._lastSend = std::chrono::system_clock::now();

    for (auto &entity: *_entities) {
        if (entity->hasComponent<NetworkComponent>()) continue;
        if (!entity->hasComponent<SendOverNetworkComponent>()) continue;
        Network::Byte SerializeEntity;
        EntitySerializer::SerializeEntity(SerializeEntity, entity);
        Network::EntityId entityId = entity->getId();
        if (networkComponent._checksums.find(entityId) ==
            networkComponent._checksums.end()) {
            Network::PacketType packetType = Network::PacketType::NewEntity;
            Network::PacketNumber packetNumber = 0; // Need to be changed
            Network::Byte NewEntityPacket;
            NewEntityPacket << packetType;
            NewEntityPacket << packetNumber;
            EntitySerializer::SerializeEntity(NewEntityPacket, entity);
            client->send(networkComponent._ip, networkComponent._port,
                NewEntityPacket);
            networkComponent._checksums[entityId] = SerializeEntity;
        } else if (
            !entity->hasComponent<BulletComponent>() &&
            networkComponent._checksums[entityId] != SerializeEntity) {
            Network::PacketType packetType = Network::PacketType::UpdateEntity;
            Network::PacketNumber packetNumber = 0; // Need to be changed
            Network::Byte UpdateEntityPacket;
            UpdateEntityPacket << packetType;
            UpdateEntityPacket << packetNumber;
            EntitySerializer::SerializeEntity(UpdateEntityPacket, entity);
            client->send(networkComponent._ip, networkComponent._port,
                UpdateEntityPacket);
            networkComponent._checksums[entityId] = SerializeEntity;
        }

    }
    std::vector<Network::EntityId> toDelete;
    for (auto &id : _ids_need_delete) {
        toDelete.push_back(id);
    }
    _ids_need_delete.clear();
    for (auto &entity: *_entities) {
        if (entity->hasComponent<NetworkComponent>()) continue;
        if (!entity->hasComponent<SendOverNetworkComponent>() && !entity->hasComponent<EnemyComponent>()) continue;
        _ids_need_delete.push_back(entity->getId());
        toDelete.erase(std::remove(toDelete.begin(), toDelete.end(), entity->getId()), toDelete.end());
    }

    if (toDelete.empty()) return;

    Network::PacketType packetType = Network::PacketType::DestroyEntity;
    Network::PacketNumber packetNumber = 0;
    Network::Byte DeleteEntityPacket;
    DeleteEntityPacket << packetType;
    DeleteEntityPacket << packetNumber;
    for (auto &it: toDelete) {
        if (networkComponent._checksums.find(it) !=
            networkComponent._checksums.end())
            networkComponent._checksums.erase(it);
        DeleteEntityPacket << it;
    }
    client->send(networkComponent._ip, networkComponent._port, DeleteEntityPacket);
}

std::shared_ptr<std::vector<std::shared_ptr<Entity>>> NetworkSystem::getEntites()
{
    return _entities;
}

void NetworkSystem::addEntity(std::shared_ptr<Entity> &entity)
{
    _entities->push_back(entity);
}