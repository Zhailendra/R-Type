/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Explosion.hpp
*/

#ifndef RTYPE_EXPLOSION_HPP
#define RTYPE_EXPLOSION_HPP

#include "../AComponent.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Utils/SpriteLoader.hpp"

class Explosion : public AComponent {
    public:
        Explosion() { _type = Components::BOOM; }
        ~Explosion() = default;
};

#endif