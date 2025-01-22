/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SpriteLoader.hpp
*/

#ifndef B_CPP_500_LIL_5_2_RTYPE_YACINE_OURTANANE_SPRITELOADER_HPP
#define B_CPP_500_LIL_5_2_RTYPE_YACINE_OURTANANE_SPRITELOADER_HPP

/* Standard Includes */

#include <map>
#include <string>
#include <iostream>
#include "SFML/Graphics.hpp"
#include <memory>

/* Class Includes */

#include "Path.hpp"
#include "../../client/ErrorHandler.hpp"
#include "../ECS/Types.hpp"


namespace rtype {

    class SpriteLoader {
        private:
            static sf::Texture loadTexture(const std::string& filename);
        public:
            static void loadAllTextures();
            static std::shared_ptr<std::map<SpriteType, sf::Texture>> getTextures(std::shared_ptr<std::map<SpriteType, sf::Texture>> textures_to_load = nullptr);
//            static void scaleSprite(sf::Sprite& sprite, float scaleX, float scaleY) {
//                sprite.setScale(scaleX, scaleY);
//            }
//
//            void setRect(SpriteType type) {
//                sf::IntRect backgroundRect(0, 0, textures[type].getSize().x / 9, textures[type].getSize().y);
//                sprites[type].setTextureRect(backgroundRect);
//            }

//            void primaryBackground() {
//                textures[BACKGROUND_1] = loadTexture(BASIC_BACKGROUND_1);
//                textures[FORGROUND_1] = loadTexture(BASIC_FORGROUND_1);
//                textures[GROUND_1] = loadTexture(BASIC_GROUND_1);
//
//                sprites[BACKGROUND_1].setTexture(textures[BACKGROUND_1]);
//                sprites[FORGROUND_1].setTexture(textures[FORGROUND_1]);
//                sprites[GROUND_1].setTexture(textures[GROUND_1]);
//
//                sf::Vector2u windowSize = _window.getSize();
//
//                auto desiredHeight = static_cast<float>(windowSize.y);
//
//                scaleSprite(sprites[BACKGROUND_1], 1.0f, desiredHeight / sprites[BACKGROUND_1].getGlobalBounds().height);
//                scaleSprite(sprites[FORGROUND_1], 1.0f, desiredHeight / sprites[FORGROUND_1].getGlobalBounds().height);
//                scaleSprite(sprites[GROUND_1], 1.0f, desiredHeight / sprites[GROUND_1].getGlobalBounds().height);
//            }

//            void secondaryBackground() {
//                textures[BLACK_HOLE] = loadTexture(BLACK_HOLE_PNG);
//                textures[STAR] = loadTexture(STAR_PNG);
//                textures[BIG_RED_STAR] = loadTexture(BIG_RED_STAR_PNG);
//                textures[BIG_GREEN_STAR] = loadTexture(BIG_GREEN_STAR_PNG);
//                textures[LITTLE_STAR] = loadTexture(LITTLE_STAR_PNG);
//
//                sprites[BLACK_HOLE].setTexture(textures[BLACK_HOLE]);
//                sprites[STAR].setTexture(textures[STAR]);
//                sprites[BIG_RED_STAR].setTexture(textures[BIG_RED_STAR]);
//                sprites[BIG_GREEN_STAR].setTexture(textures[BIG_GREEN_STAR]);
//                sprites[LITTLE_STAR].setTexture(textures[LITTLE_STAR]);
//
//                setRect(BLACK_HOLE);
//                setRect(STAR);
//                setRect(BIG_RED_STAR);
//                setRect(BIG_GREEN_STAR);
//                setRect(LITTLE_STAR);
//
//                sf::Vector2u windowSize = _window.getSize();
//
//                auto desiredWidth = static_cast<float>(windowSize.x);
//                auto desiredHeight = static_cast<float>(windowSize.y);
//
//                scaleSprite(sprites[BLACK_HOLE], desiredWidth / sprites[BLACK_HOLE].getGlobalBounds().width, desiredHeight / sprites[BLACK_HOLE].getGlobalBounds().height);
//                scaleSprite(sprites[STAR], desiredWidth / sprites[STAR].getGlobalBounds().width, desiredHeight / sprites[STAR].getGlobalBounds().height);
//                scaleSprite(sprites[BIG_RED_STAR], desiredWidth / sprites[BIG_RED_STAR].getGlobalBounds().width, desiredHeight / sprites[BIG_RED_STAR].getGlobalBounds().height);
//                scaleSprite(sprites[BIG_GREEN_STAR], desiredWidth / sprites[BIG_GREEN_STAR].getGlobalBounds().width, desiredHeight / sprites[BIG_GREEN_STAR].getGlobalBounds().height);
//                scaleSprite(sprites[LITTLE_STAR], desiredWidth / sprites[LITTLE_STAR].getGlobalBounds().width, desiredHeight / sprites[LITTLE_STAR].getGlobalBounds().height);
//            }

//            void loadBackgrounds() {
//                primaryBackground();
//                secondaryBackground();
//            }

//            void loadPlayers() {
//                textures[PLAYER_1] = loadTexture(PLAYER_1_SPRITE);
//                textures[PLAYER_2] = loadTexture(PLAYER_2_SPRITE);
//                textures[PLAYER_3] = loadTexture(PLAYER_3_SPRITE);
//                textures[PLAYER_4] = loadTexture(PLAYER_4_SPRITE);
//                textures[PLAYER_5] = loadTexture(PLAYER_5_SPRITE);
//
//                sprites[PLAYER_1].setTexture(textures[PLAYER_1]);
//                sprites[PLAYER_2].setTexture(textures[PLAYER_2]);
//                sprites[PLAYER_3].setTexture(textures[PLAYER_3]);
//                sprites[PLAYER_4].setTexture(textures[PLAYER_4]);
//                sprites[PLAYER_5].setTexture(textures[PLAYER_5]);
//
//                scaleSprite(sprites[PLAYER_1], 3.5f, 3.5f);
//                scaleSprite(sprites[PLAYER_2], 3.5f, 3.5f);
//                scaleSprite(sprites[PLAYER_3], 3.5f, 3.5f);
//                scaleSprite(sprites[PLAYER_4], 3.5f, 3.5f);
//                scaleSprite(sprites[PLAYER_5], 3.5f, 3.5f);
//            }

//            void loadProjectiles() {
//                textures[FIRE_PROJECTILE] = loadTexture(FIRE_PROJECTILE_SPRITE);
//
//                sprites[FIRE_PROJECTILE].setTexture(textures[FIRE_PROJECTILE]);
//
//                scaleSprite(sprites[FIRE_PROJECTILE], 0.6f, 0.6f);
//
//                float rotationAngle = 90.0f;
//                sprites[FIRE_PROJECTILE].setRotation(rotationAngle);
//            }
//
//            void loadEnemies() {
//                textures[ENEMY_1] = loadTexture(ENEMY_1_SPRITE);
//                textures[ENEMY_2] = loadTexture(ENEMY_2_SPRITE);
//                textures[ENEMY_3] = loadTexture(ENEMY_3_SPRITE);
//                textures[ENEMY_4] = loadTexture(ENEMY_4_SPRITE);
//
//                sprites[ENEMY_1].setTexture(textures[ENEMY_1]);
//                sprites[ENEMY_2].setTexture(textures[ENEMY_2]);
//                sprites[ENEMY_3].setTexture(textures[ENEMY_3]);
//                sprites[ENEMY_4].setTexture(textures[ENEMY_4]);
//            }

//        public:
//            explicit SpriteLoader(sf::RenderWindow& window) : _window(window) {
//                loadBackgrounds();
//                loadPlayers();
//            }
//
//            sf::Sprite& getSprite(SpriteType type) {
//                auto it = sprites.find(type);
//                if (it != sprites.end()) {
//                    return it->second;
//                } else {
//                    static sf::Sprite emptySprite;
//                    return emptySprite;
//                }
//            }

    };

}

#endif
