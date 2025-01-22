/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** ClickableSystem.cpp
*/

#include "ClickableSystem.hpp"

void ClickableSystem::ButtonComponentEvent(
    std::shared_ptr<Entity> &entity,
    std::shared_ptr<std::vector<sf::Event>> &event
)
{
    ButtonComponent &button = entity.get()->getComponent<ButtonComponent>();
    for (auto &e: *event) {
        if (e.type == sf::Event::MouseButtonPressed &&
            e.mouseButton.button == sf::Mouse::Left &&
            button._rect.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y) &&
            button._callback != nullptr) {
            button._callback();
        }
    }
}

void ClickableSystem::update()
{
    for (auto &entity: *_entities) {
        if (entity.get()->hasComponent<ButtonComponent>()) {
            ButtonComponentEvent(entity, _inputs);
        }
    }
}

std::shared_ptr<std::vector<std::shared_ptr<Entity>>> ClickableSystem::getEntites()
{
    return _entities;
}

void ClickableSystem::addEntity(std::shared_ptr<Entity> &entity)
{
    _entities.get()->push_back(entity);
}