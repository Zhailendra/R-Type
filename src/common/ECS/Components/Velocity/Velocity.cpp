/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Velocity
*/

#include "Velocity.hpp"

Velocity::Velocity(float x, float y, float z) : x(x), y(y), z(z)
{
    _type = Components::VELOCITY;
}

std::ostream &operator<<(std::ostream &os, const Velocity &velocity)
{
    os << "Velocity{ x: " << velocity.x << ", y: " << velocity.y << ", z: " << velocity.z << " }";
    return os;
}