/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Renderable
*/

#ifndef RENDERABLE_HPP_
#define RENDERABLE_HPP_

#include "../AComponent.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "../../../Utils/SpriteLoader.hpp"

class Renderable : public AComponent {
    public:
        Renderable() { _type = Components::RENDERABLE; }

        Renderable(SpriteType type);
        ~Renderable() = default;
        //copy constructor
        Renderable(const Renderable &other);
        Renderable &operator=(const Renderable &other);

        friend std::ostream &operator<<(std::ostream &os, const Renderable &renderable);

        sf::FloatRect getHitbox() const;

        sf::Sprite _sprite;
        SpriteType _sprite_type;
};

#endif /* !RENDERABLE_HPP_ */

