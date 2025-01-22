/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** ASystem
*/

#include "ASystem.hpp"

ASystem::ASystem()
{
}

ASystem::~ASystem()
{
}

void ASystem::setInputs(std::shared_ptr<std::vector<sf::Event>> &inputs)
{
    _inputs = inputs;
}

void ASystem::setEntities(std::shared_ptr<std::vector<std::shared_ptr<Entity>>> entities)
{
    _entities = entities;
}
