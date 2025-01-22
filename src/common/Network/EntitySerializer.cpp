/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** EntitySerializer.cpp
*/
#include "EntitySerializer.hpp"

void EntitySerializer::DeserializeEntity(
    Network::Byte &byte, std::shared_ptr<Entity> &Entity
)
{
    while (byte.getCursor() < byte.getSize()) {
        Network::ComponentsType ComponentId;
        byte >> ComponentId;
        switch (static_cast<Components>(ComponentId)) {
        case POSITION: {
            PositionComponent positionComponent;
            byte >> positionComponent;
            if (Entity->hasComponent<PositionComponent>()) {
                Entity->removeComponent<PositionComponent>();
            }
            Entity->addComponent<PositionComponent>(positionComponent);
            break;
        }
        case VELOCITY: {
            Velocity velocity;
            byte >> velocity;
            if (Entity->hasComponent<Velocity>()) {
                Entity->removeComponent<Velocity>();
            }
            Entity->addComponent<Velocity>(velocity);
            break;
        }
        case RENDERABLE: {
            Renderable renderable;
            byte >> renderable;
            if (Entity->hasComponent<Renderable>()) {
                Entity->removeComponent<Renderable>();
            }
            Entity->addComponent<Renderable>(renderable);
            break;
        }
        case RECTABLE: {
            Rectable rectable;
            byte >> rectable;
            if (Entity->hasComponent<Rectable>()) {
                Entity->removeComponent<Rectable>();
            }
            Entity->addComponent<Rectable>(rectable);
            break;
        }
        case SCALE: {
            ScaleComponent scaleComponent;
            byte >> scaleComponent;
            if (Entity->hasComponent<ScaleComponent>()) {
                break;
            }
            Entity->addComponent<ScaleComponent>(scaleComponent);
            break;
        }
        case BULLET: {
            BulletComponent bulletComponent;
            byte >> bulletComponent;
            if (Entity->hasComponent<BulletComponent>()) {
                break;
            }
            Entity->addComponent<BulletComponent>(bulletComponent);
            break;
        }
        case ENEMY: {
            EnemyComponent enemyComponent;
            byte >> enemyComponent;
            if (Entity->hasComponent<EnemyComponent>()) {
                break;
            }
            Entity->addComponent<EnemyComponent>(enemyComponent);
            break;
        }
        default:
            break;
        }
    }
    if (Entity->hasComponent<PositionComponent>() && Entity->hasComponent<Renderable>()) {
        auto &sprite = Entity->getComponent<Renderable>()._sprite;
        Entity->getComponent<PositionComponent>().registerPositionChangeCallback([&sprite](float x, float y) {
            sprite.setPosition(x, y);
        });
    }
}

void EntitySerializer::SerializeEntity(
    Network::Byte &byte, std::shared_ptr<Entity> &Entity
)
{
    byte << Entity->getId();
    if (Entity->hasComponent<PositionComponent>()) {
        byte << static_cast<Network::ComponentsType>(POSITION);
        byte << Entity->getComponent<PositionComponent>();
    }
    if (Entity->hasComponent<Velocity>()) {
        byte << static_cast<Network::ComponentsType>(VELOCITY);
        byte << Entity->getComponent<Velocity>();
    }
    if (Entity->hasComponent<Rectable>()) {
        byte << static_cast<Network::ComponentsType>(RECTABLE);
        byte << Entity->getComponent<Rectable>();
    }
    if (Entity->hasComponent<ScaleComponent>()) {
        byte << static_cast<Network::ComponentsType>(SCALE);
        byte << Entity->getComponent<ScaleComponent>();
    }
    if (Entity->hasComponent<Renderable>()) {
        byte << static_cast<Network::ComponentsType>(RENDERABLE);
        byte << Entity->getComponent<Renderable>();
    }
    if (Entity->hasComponent<BulletComponent>()) {
        byte << static_cast<Network::ComponentsType>(BULLET);
        byte << Entity->getComponent<BulletComponent>();
    }
    if (Entity->hasComponent<EnemyComponent>()) {
        byte << static_cast<Network::ComponentsType>(ENEMY);
        byte << Entity->getComponent<EnemyComponent>();
    }
}