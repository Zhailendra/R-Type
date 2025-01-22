/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** ScaleComponent.cpp
*/

#include "ScaleComponent.hpp"

std::ostream &operator<<(std::ostream &os, const ScaleComponent &sendOverNetworkComponent)
{
    os << "ScaleComponent: {x: " << sendOverNetworkComponent._x << ", y: " << sendOverNetworkComponent._y << "}";
    return os;
}