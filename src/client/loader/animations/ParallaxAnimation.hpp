/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** ParallaxAnimation.hpp
*/

#ifndef RTYPE_PARALLAXANIMATION_HPP
#define RTYPE_PARALLAXANIMATION_HPP

#include "ASpritesAnimations.hpp"

namespace rtype {

    class ParallaxAnimation {
        private:
            SpriteLoader spriteLoader;
            std::map<SpriteType, float> speeds;

            float backgroundOffsetX{};
            float foregroundOffsetX{};
            float groundOffsetX{};

            static void loopSprite(sf::Sprite& sprite, float& offset, float speed, float windowWidth) {
                if (offset <= -windowWidth) {
                    offset = 0;
                }
                sprite.setPosition(offset, 0);
                offset -= speed;
            }

        public:

            ParallaxAnimation() = default;

            void update(float deltaTime, sf::RenderWindow& window, std::vector<sf::Sprite>& backgroundsVector, std::vector<float>& backgroundsSpeeds) {
                float windowWidth = static_cast<float>(window.getSize().x);

                for (size_t i = 0; i < backgroundsVector.size(); ++i) {
                    sf::Sprite& sprite = backgroundsVector[i];
                    float speed = backgroundsSpeeds[i % backgroundsSpeeds.size()];

                    if (i == 0) {
                        loopSprite(sprite, backgroundOffsetX, speed * deltaTime, windowWidth);
                    } else if (i == 1) {
                        loopSprite(sprite, foregroundOffsetX, speed * deltaTime, windowWidth);
                    } else {
                        loopSprite(sprite, groundOffsetX, speed * deltaTime, windowWidth);
                    }
                    window.draw(sprite);
                }
            }

            void updateBackgroundsAnim(float deltaTime, sf::RenderWindow& window, std::vector<sf::Sprite>& backgroundsAnimVector) {
                static float frameDuration = 0.2f;
                static float elapsed = 0.0f;

                elapsed += deltaTime;

                if (elapsed >= frameDuration) {
                    for (auto& sprite : backgroundsAnimVector) {
                        sf::IntRect textureRect = sprite.getTextureRect();
                        textureRect.left += textureRect.width;

                        if (textureRect.left >= sprite.getTexture()->getSize().x) {
                            textureRect.left = 0;
                        }

                        sprite.setTextureRect(textureRect);
                    }

                    elapsed = 0.0f;
                }

                for (auto& sprite : backgroundsAnimVector) {
                    window.draw(sprite);
                }
            }

    };

}

#endif //RTYPE_PARALLAXANIMATION_HPP
