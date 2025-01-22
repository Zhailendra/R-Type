/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** ASpritesAnimations.cpp
*/

#include "ASpritesAnimations.hpp"

namespace rtype {

    sf::Sprite& ASpritesAnimations::updateSpriteAnimation(sf::Sprite& sprite, sf::Clock& clock, int currentFrame, int nbFrames) {
        playerSprite = sprite;
        sf::FloatRect spriteSize = playerSprite.getGlobalBounds();

        float numberOfFrames = nbFrames * playerSprite.getScale().x;
        int frameWidth = spriteSize.width / numberOfFrames;

        sf::IntRect textureRect(currentFrame * frameWidth, 0, frameWidth, spriteSize.height);
        playerSprite.setTextureRect(textureRect);
        return playerSprite;
    }

    sf::Sprite &ASpritesAnimations::updateSpriteAnimationV2(sf::Sprite &sprite, sf::Clock &clock, int currentFrame, int nbFrames, int nbFramesHeight, bool switchTop, int frameHeightMultiplier) {
        playerSprite = sprite;
        sf::FloatRect spriteSize = playerSprite.getGlobalBounds();
        sf::IntRect textureRect;

        float numberOfFrames = nbFrames * playerSprite.getScale().x;
        float numberOfFramesHeight = nbFramesHeight * playerSprite.getScale().y;
        int frameWidth = spriteSize.width / numberOfFrames;
        int frameHeight = spriteSize.height / numberOfFramesHeight;

        if (!switchTop) {
            sf::IntRect rect(currentFrame * frameWidth, frameHeight * frameHeightMultiplier, frameWidth, frameHeight);
            textureRect = rect;
        } else {
            sf::IntRect rect(currentFrame * frameWidth, frameHeight, frameWidth, frameHeight);
            textureRect = rect;
        }
        playerSprite.setTextureRect(textureRect);

        return playerSprite;
    }

    void ASpritesAnimations::updatePlayersProjectileAnimation(SpriteType type, sf::RenderWindow &window, sf::Clock &clock) {
        projectileSprite.setTexture(SpriteLoader::getTextures()->at(type));

        static int frameCount = 3;
        static float frameWidth = 150;
        static int frameHeight = 432;
        static int currentFrame = 0;
        static float animationSpeed = 0.0005f;
        static float timeSinceLastUpdate = 0.0f;

        float elapsedSeconds = clock.getElapsedTime().asSeconds();
        clock.restart();
        timeSinceLastUpdate += elapsedSeconds;

        sf::IntRect textureRect(currentFrame * frameWidth + 45, 0, frameWidth, frameHeight);
        projectileSprite.setTextureRect(textureRect);

        if (timeSinceLastUpdate > animationSpeed) {
            currentFrame = (currentFrame + 1) % frameCount;
            timeSinceLastUpdate -= animationSpeed;
        }

        setProjectilePos();
        moveProjectile(window, elapsedSeconds);
    }

    void ASpritesAnimations::setProjectilePos() {
        sf::Vector2f playerPosition = playerSprite.getPosition();
        sf::Vector2f playerSize(playerSprite.getGlobalBounds().width, playerSprite.getGlobalBounds().height);

        float offsetX = playerPosition.x + playerSize.x + 200.0f;
        float offsetY = playerPosition.y + 10.0f;

        projectileSprite.setPosition(offsetX, offsetY);

        projectilePos = {offsetX, offsetY};

    }

    void ASpritesAnimations::moveProjectile(sf::RenderWindow &window, float elapsedSeconds) {
        static float projectileSpeed = 100.0f;
        static float timeElapsed = 0.0f;

        float deltaTime = elapsedSeconds - timeElapsed;
        timeElapsed = elapsedSeconds;

        sf::Vector2f currentPosition = projectileSprite.getPosition();

        float newXPosition = currentPosition.x + (projectileSpeed * deltaTime);

        if (newXPosition > window.getSize().x) {
            newXPosition = projectilePos.x;
        }

        projectileSprite.setPosition(newXPosition, currentPosition.y);
        window.draw(projectileSprite);
    }

}
