/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** ControllableComponent
*/

#include "ControllableComponent.hpp"

ControllableComponent::ControllableComponent(sf::Keyboard::Key up, sf::Keyboard::Key down, 
                              sf::Keyboard::Key left, sf::Keyboard::Key right, 
                              sf::Keyboard::Key shoot, sf::Keyboard::Key laser)
{
    _type = Components::CONTROLLABLE;
    this->up = up;
    this->down = down;
    this->left = left;
    this->right = right;
    this->shoot = shoot;
    this->laser = laser;
}

ControllableComponent::~ControllableComponent()
{
}
