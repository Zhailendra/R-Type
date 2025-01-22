/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Controller.cpp
*/

#include "Controller.hpp"

void Controller::NewEntity(
        Network::INetwork<TemplateRefClient> &client, Network::Packet &packet,
        TemplateRefClient Entities
) {
    Network::Client<TemplateRefClient> &clientRef =
            reinterpret_cast<Network::Client<TemplateRefClient> &>(client);
    Network::EntityId EntityId;
    packet.byte >> EntityId;
    for (auto &it: *Entities) {
        if (it->getId() == EntityId)
            return;
    }
    std::shared_ptr<Entity> obj = std::make_unique<Entity>(Entity(EntityId));
    Entities->push_back(obj);
    EntitySerializer::DeserializeEntity(packet.byte, obj);
    PositionComponent &pos = obj->getComponent<PositionComponent>();
    clientRef._lastPosition[EntityId] = pos;
}

void Controller::UpdateEntity(
        Network::INetwork<TemplateRefClient> &client, Network::Packet &packet,
        TemplateRefClient Entities
) {
    Network::Client<TemplateRefClient> &clientRef =
            reinterpret_cast<Network::Client<TemplateRefClient> &>(client);
    Network::EntityId EntityId;
    packet.byte >> EntityId;
    std::shared_ptr<Entity> OldEntity = nullptr;
    for (auto &it: *Entities) {
        if (it->getId() == EntityId)
            OldEntity = it;
    }
    if (OldEntity == nullptr)
        return;
    PositionComponent oldPos = clientRef._lastPosition[EntityId];
    std::shared_ptr<Entity>
            NextEntity = std::make_unique<Entity>(Entity(EntityId));
    EntitySerializer::DeserializeEntity(packet.byte, NextEntity);
    PositionComponent newPos = NextEntity->getComponent<PositionComponent>();
    auto &oldVelo = OldEntity->getComponent<Velocity>();
    clientRef._lastPosition[EntityId] = newPos;
    for (size_t i = 0; i < COMPONENTS_SIZE; i++) {
        if (i == POSITION || i == VELOCITY)
            continue;
        switch (i) {
            case RECTABLE: {
                if (OldEntity->hasComponent<Rectable>()) {
                    OldEntity->removeComponent<Rectable>();
                }
                if (NextEntity->hasComponent<Rectable>()) {
                    Rectable rectable = NextEntity->getComponent<Rectable>();
                    OldEntity->addComponent<Rectable>(rectable);
                }
            }
            default: {
                break;
            }
        }
    }
    if (newPos == oldPos)
        return;
    //calculate the difference between the two entities
    //apply the velocity to the old entity to make it move to the next entity
    OldEntity->getComponent<PositionComponent>().setPos(oldPos.x, oldPos.y);
    double dx = static_cast<double>(newPos.x) - static_cast<double>(oldPos.x);
    double dy = static_cast<double>(newPos.y) - static_cast<double>(oldPos.y);

    double magnitude = std::sqrt(dx * dx + dy * dy);
    if (magnitude > 0) {
        float vx = dx / magnitude;
        float vy = dy / magnitude;
        float velocity = VELOCITY_SPEED_PLAYER;
        if (OldEntity->hasComponent<BulletComponent>()) {
            velocity = VELOCITY_SPEED_BULLET;
        }
        oldVelo.x = vx * velocity;
        oldVelo.y = vy * velocity;
    } else {
        oldVelo.x = 0;
        oldVelo.y = 0;
    }
}

void Controller::DestroyEntity(
        Network::INetwork<TemplateRefClient> &client, Network::Packet &packet,
        TemplateRefClient Entities
) {
    Network::Client<TemplateRefClient> &clientRef =
            reinterpret_cast<Network::Client<TemplateRefClient> &>(client);
    Network::EntityId EntityId;
    while (packet.byte.getCursor() < packet.byte.getSize()) {
        packet.byte >> EntityId;
        EntityManager::destroyEntity(Entities, EntityId);
        clientRef._lastPosition.erase(EntityId);
    }
}
