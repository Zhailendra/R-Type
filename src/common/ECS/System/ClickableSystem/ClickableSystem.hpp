/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** ClickableSystem.hpp
*/

#ifndef CLICKABLESYSTEM_HPP
#define CLICKABLESYSTEM_HPP

#include "ECS/System/ASystem.hpp"
#include "ECS/Components/Button/ButtonComponent.hpp"

class ClickableSystem : public ASystem {
public:
    ClickableSystem() = default;
    ~ClickableSystem() = default;

    static void ButtonComponentEvent(std::shared_ptr<Entity> &entity, std::shared_ptr<std::vector<sf::Event>> &event);

    std::shared_ptr<std::vector<std::shared_ptr<Entity>>> getEntites() final;
    void addEntity(std::shared_ptr<Entity> &entity) final;
    void update() final;
};

#endif //CLICKABLESYSTEM_HPP
