/*
** EPITECH PROJECT, 2024
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** ProjectileSystemp.cpp
*/

#include "ProjectileSystem.hpp"

ProjectileSystem::ProjectileSystem() {
}

ProjectileSystem::~ProjectileSystem() {
}

std::shared_ptr<std::vector<std::shared_ptr<Entity>>> ProjectileSystem::getEntites() {
    return _entities;
}

void ProjectileSystem::addEntity(std::shared_ptr<Entity> &entity) {

}

void ProjectileSystem::update()
{
    float frameDelay = 0.2f;
    bool isProjectile = true;

    for (size_t i = 0; i < _entities.get()->size(); i++) {
        std::shared_ptr<Entity> &entity = (*_entities.get())[i];

        if (!entity->hasComponent<Rectable>() || !entity->hasComponent<PositionComponent>())
            continue;

        Rectable &rect = entity.get()->getComponent<Rectable>();
        PositionComponent posComp = entity.get()->getComponent<PositionComponent>();

        if (entity->hasComponent<BulletComponent>() && !entity->hasComponent<LaserComponent>()) {
            if (rect._frameClock.getElapsedTime().asSeconds() >= frameDelay) {
                rect._frameClock.restart();
                if (rect._currentPlayerFrame < rect._nbFrames - 1) {
                    rect._currentPlayerFrame++;
                } else {
                    rect._currentPlayerFrame = 0;
                }
            }
            continue;
        } else if (entity->hasComponent<Explosion>()) {
            frameDelay = 0.1f;
            if (rect._frameClock.getElapsedTime().asSeconds() >= frameDelay) {
                rect._frameClock.restart();
                if (rect._currentPlayerFrame < rect._nbFrames - 1) {
                    rect._currentPlayerFrame++;
                } else {
                    EntityManager::destroyEntity(_entities, entity->getId());
                    rect._currentPlayerFrame = 0;
                }
            }
            continue;
        }

        if (!entity.get()->hasComponent<LaserComponent>() &&
        !entity.get()->hasComponent<LaserLoadingComponent>())
            continue;

        if (entity.get()->hasComponent<LaserLoadingComponent>()) {
            frameDelay = 0.05f;
            isProjectile = false;
        } else {
            frameDelay = 0.15f;
            isProjectile = true;
        }

        if (rect._frameClock.getElapsedTime().asSeconds() >= frameDelay) {
            rect._frameClock.restart();

            if (isProjectile) {
                if (!rect._newFrame) {
                    if (rect._currentPlayerFrame < rect._nbFrames - 1) {
                        rect._currentPlayerFrame++;
                    } else {
                        rect._newFrame = true;
                        rect._currentPlayerFrame = 2;
                    }
                } else {
                    if (rect._currentPlayerFrame > 0) {
                        rect._currentPlayerFrame--;
                    } else {
                        rect._currentPlayerFrame = 2;
                    }
                }
            } else {
                if (rect._currentPlayerFrame < rect._nbFrames - 1) {
                    rect._currentPlayerFrame++;
                } else {
                    rect._currentPlayerFrame = 1;
                }
            }
        }
    }
}

