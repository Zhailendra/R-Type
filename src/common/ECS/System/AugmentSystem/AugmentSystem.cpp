/*
** EPITECH PROJECT, 2024
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** AugmentSystem
*/

#include "AugmentSystem.hpp"
#include <ECS/Components/Shield/ShieldComponent.hpp>
#include <ECS/Components/Position/PositionComponent.hpp>
#include <ECS/Components/Laser/LaserLoadingComponent.hpp>

AugmentSystem::AugmentSystem()
{
}

AugmentSystem::~AugmentSystem()
{
}

void AugmentSystem::setAugments(Augments &augmentComp, PositionComponent posComp, std::vector<bool> augments)
{
    if (!_setAugments[1] &&  augments[1]) {
        _setAugments[1] = true;
        std::shared_ptr<Entity> shield = EntityManager::createShield(posComp.x - 15, posComp.y - 30);
        _entities->push_back(shield);
    }
}

void AugmentSystem::updateAugments(PositionComponent posComp)
{
    for (const auto &augmentTypeEntity: *_entities) {
        if (!augmentTypeEntity->hasComponent<ShieldComponent>() &&
        !augmentTypeEntity->hasComponent<LaserLoadingComponent>()) {
            continue;
        }
        auto &PosComp = augmentTypeEntity->getComponent<PositionComponent>();
        if (augmentTypeEntity->hasComponent<ShieldComponent>()) {
            PosComp.x = posComp.x - 15;
            PosComp.y = posComp.y - 30;
        }
        if (augmentTypeEntity->hasComponent<LaserLoadingComponent>()) {
            PosComp.x = posComp.x + 100;
            PosComp.y = posComp.y + 5;
        }
    }
}

void AugmentSystem::update()
{
    for (const auto &entity: *_entities) {
        if (!entity.get()->hasComponent<Augments>()) {
            continue;
        }
        Augments &augmentComp = entity.get()->getComponent<Augments>();
        PositionComponent posComp = entity.get()->getComponent<PositionComponent>();
        std::vector<bool> augments = augmentComp._augments;
        setAugments(augmentComp, posComp, augments);
        updateAugments(posComp);
    }
}

std::shared_ptr<std::vector<std::shared_ptr<Entity>>> AugmentSystem::getEntites()
{
    return _entities;
}

void AugmentSystem::addEntity(std::shared_ptr<Entity> &entity)
{
    _entities.get()->push_back(entity);
}