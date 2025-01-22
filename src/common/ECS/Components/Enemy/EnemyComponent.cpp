/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** EnemyComponent
*/

#include "EnemyComponent.hpp"

EnemyComponent::EnemyComponent()
{
    _type = Components::ENEMY;
}

EnemyComponent::EnemyComponent(int enemyType)
{
    _type = Components::ENEMY;
    _enemyType = enemyType;
}

EnemyComponent::~EnemyComponent()
{
}
