/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** InputSystem.cpp
*/
#include "InputSystem.hpp"

void InputSystem::update()
{
    for (auto &entity: *_entities) {
        if (!entity->hasComponent<InputComponent>() ||
            !entity->hasComponent<TextComponent>())
            continue;
        auto &input = entity->getComponent<InputComponent>();
        auto &text = entity->getComponent<TextComponent>();
        input._cursorShow = (input._cursorShow + 1) % 60;
        if (input._cursorShow < 30 && input._isFocused && text._textString.back() != 'I')
            text._textString.insert(input._cursorPos, 1, 'I');
        if (input._cursorShow >= 30 && text._textString.back() == 'I')
            text._textString.erase(input._cursorPos, 1);
        for (auto &e: *_inputs) {
            if (e.type == sf::Event::MouseButtonPressed &&
                e.mouseButton.button == sf::Mouse::Left) {
                if (input._rect.getGlobalBounds().contains(e.mouseButton.x,
                    e.mouseButton.y)) {
                    input._isFocused = true;
                } else {
                    input._isFocused = false;
                }
            }
            if (e.type == sf::Event::TextEntered && input._isFocused) {
                if (e.text.unicode == 8 && input._cursorPos > 0) {
                    input._cursorPos--;
                    text._textString.erase(input._cursorPos, 1);
                    if (input._callback)
                        input._callback(text._textString.substr(0, input._cursorPos));
                } else if (e.text.unicode < 128 && input._cursorPos < 20 && e.text.unicode != 8) {
                    input._cursorPos++;
                    text._textString.insert(input._cursorPos - 1, 1,
                        e.text.unicode);
                    if (input._callback)
                        input._callback(
                            text._textString.substr(0, input._cursorPos));
                }
            }
        }
    }
}

std::shared_ptr<std::vector<std::shared_ptr<Entity>>> InputSystem::getEntites()
{
    return _entities;
}

void InputSystem::addEntity(std::shared_ptr<Entity> &entity)
{
    _entities->push_back(entity);
}