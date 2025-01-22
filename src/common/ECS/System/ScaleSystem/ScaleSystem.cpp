/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** ScaleSystem.cpp
*/

#include "ScaleSystem.hpp"

void ScaleSystem::update()
{
    for (auto &entity : *_entities) {
        if (!entity->hasComponent<ScaleComponent>() || !entity->hasComponent<Renderable>())
            continue;
        auto &scaleComponent = entity->getComponent<ScaleComponent>();
        auto &renderable = entity->getComponent<Renderable>();
        renderable._sprite.setScale(scaleComponent._x, scaleComponent._y);
    }
}

std::shared_ptr<std::vector<std::shared_ptr<Entity>>> ScaleSystem::getEntites()
{
    return _entities;
}

void ScaleSystem::addEntity(std::shared_ptr<Entity> &entity)
{
    _entities->push_back(entity);
}
