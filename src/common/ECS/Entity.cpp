/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(std::uint32_t id)
    : _id(id)
{
}

Entity::~Entity()
{
}

std::uint32_t Entity::getId() const
{
    return _id;
}

void Entity::setId(std::uint32_t id)
{
    _id = id;
}

std::ostream &operator<<(std::ostream &os, const Entity &Entity)
{
    os << "Entity{id: " << Entity._id;
    os << "}";

    return os;
}