/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** PositionComponent
*/

#include "PositionComponent.hpp"

PositionComponent::PositionComponent(float x, float y, float z) : x(x), y(y), z(z)
{
    _type = Components::POSITION;
}

void PositionComponent::setPos(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void PositionComponent::setPos(float x, float y)
{
    this->x = x;
    this->y = y;

    if (positionChangeCallback) {
        positionChangeCallback(x, y);
    }
}

std::ostream &operator<<(std::ostream &os, const PositionComponent &positionComponent)
{
    os << "PositionComponent{x: " << positionComponent.x << ", y: " << positionComponent.y << ", z: " << positionComponent.z << "}";
    return os;
}