/*
** EPITECH PROJECT, 2024
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Health
*/

#include "Health.hpp"

Health::Health(int hp)
{
    _type = Components::HEALTH; 
    _hp = hp;
}

Health::~Health()
{
}

