/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** EntityController.cpp
*/

#include "EntityController.hpp"
#include "ECS/Components/SendOverNetwork/SendOverNetworkComponent.hpp"
#include <ECS/../OstreamHelper.hpp>

void EntityController::NewEntity(
    Network::INetwork<TemplateRefServer> &server, Network::Packet &packet,
    EntityManager &entityManager
)
{
    Network::EntityId EntityId;
    packet.byte >> EntityId;
    auto Entity = entityManager.createEntity();
    Entity->setId(EntityId);
    EntitySerializer::DeserializeEntity(packet.byte, Entity);
    server.broadcast(packet);
}

void EntityController::UpdateEntity(
    Network::INetwork<TemplateRefServer> &server, Network::Packet &packet,
    EntityManager &entityManager
)
{
    Network::EntityId EntityId;
    packet.byte >> EntityId;
    auto Entity = entityManager.getEntity(EntityId);
    if (Entity == nullptr)
        return;
    EntitySerializer::DeserializeEntity(packet.byte, Entity);
    server.broadcast(packet);
}

void EntityController::GatherAllEntities(
    Network::INetwork<TemplateRefServer> &server, Network::Packet &packet,
    EntityManager &entityManager
)
{
    auto Entities = entityManager.getEntity();
    for (auto &Entity : *Entities) {
        Network::Byte byte;
        Network::PacketNumber packetNumber = 0;
        byte << Network::PacketType::NewEntity;
        byte << packetNumber;
        byte << Entity->getId();
        EntitySerializer::SerializeEntity(byte, Entity);
        server.send(packet.ip, packet.port, byte);
    }
}

void EntityController::DestroyEntity(
    Network::INetwork<TemplateRefServer> &server, Network::Packet &packet,
    EntityManager &entityManager
)
{
    auto Entities = entityManager.getEntity();
    Network::EntityId EntityId;
    while (packet.byte.getCursor() < packet.byte.getSize()) {
        packet.byte >> EntityId;
        EntityManager::destroyEntity(Entities, EntityId);
    }
    server.broadcast(packet);
}

void EntityController::SendEntity(
    Network::INetwork<TemplateRefServer> &server,
    EntityManager &entityManager,
    Network::PacketType packetType
)
{
    for (auto &Entity : *entityManager.getEntity()) {
        if (!Entity) continue;
        if (!Entity->hasComponent<SendOverNetworkComponent>())
            continue;
        if (Entity->hasComponent<PositionComponent>() && Entity->hasComponent<Velocity>()) {
            PositionComponent &pos = Entity->getComponent<PositionComponent>();
            Velocity &vel = Entity->getComponent<Velocity>();
            if (pos.x < -64 || pos.y < -64) {
                EntityManager::destroyEntity(entityManager.getEntity(), Entity->getId());
                continue;
            }
            if (pos.x > WIDTH || pos.y > HEIGHT) {
                if (Entity->hasComponent<BulletComponent>()) {
                    EntityManager::destroyEntity(entityManager.getEntity(), Entity->getId());
                    continue;
                }
            }
            pos.setPos(pos.x + vel.x, pos.y + vel.y);
        }
        Network::Byte byte;
        Network::PacketNumber packetNumber = 0;
        byte << packetType;
        byte << packetNumber;
        byte << Entity->getId();
        EntitySerializer::SerializeEntity(byte, Entity);
        Network::Packet packet;
        packet.byte = byte;
        packet.ip = sf::IpAddress("1.0.0.0");
        packet.port = 4242;
        server.broadcast(packet);
    }
}