/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** InputSystem.hpp
*/

#ifndef INPUTSYSTEM_HPP
#define INPUTSYSTEM_HPP

#include <ECS/Components/Text/TextComponent.hpp>
#include <ECS/Components/Button/ButtonComponent.hpp>
#include <ECS/System/ASystem.hpp>
#include <ECS/Components/Input/InputComponent.hpp>

class InputSystem : public ASystem {
public:
    InputSystem() = default;
    ~InputSystem() override = default;

    std::shared_ptr<std::vector<std::shared_ptr<Entity>>> getEntites() final;
    void addEntity(std::shared_ptr<Entity> &entity) final;
    void update() final;
protected:
private:
};

#endif //INPUTSYSTEM_HPP
