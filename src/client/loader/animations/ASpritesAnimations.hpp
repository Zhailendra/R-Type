/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** ASpritesAnimations.hpp
*/

#ifndef RTYPE_ASPRITESANIMATIONS_HPP
#define RTYPE_ASPRITESANIMATIONS_HPP

#include "../../../common/Utils/SpriteLoader.hpp"

namespace rtype {

    class ASpritesAnimations {
        public:
            ASpritesAnimations() = default;

            sf::Sprite& updateSpriteAnimation(sf::Sprite& sprite, sf::Clock& clock, int currentFrame, int nbFrames);

            sf::Sprite& updateSpriteAnimationV2(sf::Sprite& sprite, sf::Clock& clock, int currentFrame, int nbFrames, int nbFramesHeight, bool switchTop, int frameHeightMultiplier);

            void updatePlayersProjectileAnimation(SpriteType type, sf::RenderWindow& window, sf::Clock& clock);

            void setProjectilePos();

            void moveProjectile(sf::RenderWindow &window, float elapsedSeconds);

            void setPauseAnimation(bool pause) {
                pauseAnimation = pause;
            }

        protected:

            bool pauseAnimation = false;

            sf::Sprite playerSprite;
            sf::Sprite projectileSprite;

            sf::Vector2f projectilePos;

    };

}

#endif
