/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** InputComponent.cpp
*/

#include "InputComponent.hpp"

InputComponent::InputComponent(sf::Vector2f size, sf::Color color)
{
    _type = Components::INPUT;
    _size = size;
    _color = color;
    _rect.setSize(_size);
    _rect.setFillColor(_color);
    _rect.setOrigin(_size.x / 2, _size.y / 2);
}

void InputComponent::input(std::function<void(std::string)> callback)
{
    _callback = callback;
}