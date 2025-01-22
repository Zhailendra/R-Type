/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** MovableSystem
*/

#include "MovableSystem.hpp"
#include "../../../Utils/SpriteLoader.hpp"
#include "ECS/Components/Bullet/BulletComponent.hpp"
#include "ECS/Components/Shield/ShieldComponent.hpp"
#include "ECS/Components/Enemy/EnemyComponent.hpp"

MovableSystem::MovableSystem()
{
}

MovableSystem::~MovableSystem()
{
}

std::shared_ptr<std::vector<std::shared_ptr<Entity>>> MovableSystem::getEntites()
{
    return _entities;
}

void MovableSystem::addEntity(std::shared_ptr<Entity> &entity)
{
    _entities.get()->push_back(entity);
}

void MovableSystem::update()
{
    for (size_t i = 0; i < _entities->size(); i++) {
        std::shared_ptr<Entity> &entity = (*_entities.get())[i];
        if (!entity->hasComponent<PositionComponent>() || !entity->hasComponent<Velocity>())
            continue;
        auto &pos = entity->getComponent<PositionComponent>();
        auto &vel = entity->getComponent<Velocity>();

        if (pos.x < -64 || pos.y < -64) {
            if (!entity->hasComponent<ControllableComponent>() && !entity->hasComponent<ShieldComponent>()) {
                EntityManager::destroyEntity(_entities, entity->getId());
                continue;
            }
        }
        if (pos.x > WIDTH || pos.y > HEIGHT) {
            if (entity->hasComponent<BulletComponent>()) {
                EntityManager::destroyEntity(_entities, entity->getId());
                continue;
            }
        }
        pos.setPos(pos.x + vel.x, pos.y + vel.y);
    }
}