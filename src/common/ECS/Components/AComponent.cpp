/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Acomponent
*/

#include "AComponent.hpp"

AComponent::AComponent()
{
}

void AComponent::setType(Components type)
{
    _type = type;
}

Components AComponent::getType() const
{
    return _type;
}