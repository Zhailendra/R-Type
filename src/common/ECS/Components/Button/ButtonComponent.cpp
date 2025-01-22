/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** ButtonComponent.cpp
*/

#include "ButtonComponent.hpp"
#include <functional>
#include <utility>

ButtonComponent::ButtonComponent(sf::Vector2f size, sf::Color color)
{
    _type = Components::BUTTON;
    _size = size;
    _color = color;
    _rect.setSize(_size);
    _rect.setFillColor(_color);
    _rect.setOrigin(_size.x / 2, _size.y / 2);
}

void ButtonComponent::click(std::function<void()> callback)
{
    _callback = callback;
}

