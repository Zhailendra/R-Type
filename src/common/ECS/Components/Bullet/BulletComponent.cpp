/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** BulletComponent.cpp
*/

#include "BulletComponent.hpp"

std::ostream &operator<<(std::ostream &os, const BulletComponent &BulletComponent)
{
    os << "BulletComponent{" << "type: " << BulletComponent._typeBullet << "}";
    return os;
}