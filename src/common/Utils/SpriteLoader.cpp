/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** SpriteLoader.cpp
*/

#include "SpriteLoader.hpp"

sf::Texture rtype::SpriteLoader::loadTexture(const std::string &filename) {
    sf::Texture texture;
    if (!texture.loadFromFile(filename)) {
        std::string errorMsg = "Failed to load texture from file: " + filename;
        throw rtype::ErrorHandler(errorMsg);
    }
    return texture;
}

std::shared_ptr<std::map<SpriteType, sf::Texture>> rtype::SpriteLoader::getTextures(
    std::shared_ptr<std::map<SpriteType, sf::Texture>> textures_to_load
)
{
    static std::shared_ptr<std::map<SpriteType, sf::Texture>> textures;
    if (textures_to_load != nullptr)
        textures = textures_to_load;
    else
        return textures;
    return nullptr;
}

void rtype::SpriteLoader::loadAllTextures()
{
    std::shared_ptr<std::map<SpriteType, sf::Texture>> textures = std::make_shared<std::map<SpriteType, sf::Texture>>();

    for (auto &spritePath : spritePaths) {
        try {
            // std::cout << "[DEBUG] Loading " << spritePath.second << std::endl;
            sf::Texture texture = loadTexture(spritePath.second);
            textures->insert(std::make_pair(spritePath.first, texture));
        } catch (const rtype::ErrorHandler &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        }
    }

    getTextures(textures);
}


