/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Renderable
*/

#include "Renderable.hpp"

Renderable::Renderable(SpriteType type)
{
    _type = Components::RENDERABLE;
    _sprite_type = type;
    auto textures = rtype::SpriteLoader::getTextures();
    if (textures == nullptr)
        return;
    _sprite.setTexture(textures->at(type));
    
}

Renderable::Renderable(const Renderable &other)
{
    _type = Components::RENDERABLE;
    _sprite_type = other._sprite_type;
    auto textures = rtype::SpriteLoader::getTextures();
    if (textures == nullptr)
        return;
    _sprite.setTexture(textures->at(_sprite_type));
}

Renderable &Renderable::operator=(const Renderable &other)
{
    _type = Components::RENDERABLE;
    _sprite_type = other._sprite_type;
    auto textures = rtype::SpriteLoader::getTextures();
    if (textures == nullptr)
        return *this;
    _sprite.setTexture(textures->at(_sprite_type));
    return *this;
}


std::ostream &operator<<(std::ostream &os, const Renderable &renderable)
{
    os << "Renderable{ texturePath: " << spritePaths.at(renderable._sprite_type) << " }";
    return os;
}

sf::FloatRect Renderable::getHitbox() const
{
    return _sprite.getGlobalBounds();
}