/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** VectorContainer.hpp
*/

#ifndef RTYPE_VECTORCONTAINER_HPP
#define RTYPE_VECTORCONTAINER_HPP

#include "../../common/Utils/SpriteLoader.hpp"
#include "./animations/ParallaxAnimation.hpp"
#include "../../common/ECS/Types.hpp"
#include <vector>

namespace rtype {

    class VectorContainer {
        public:
            VectorContainer() : _parallaxAnimation(ParallaxAnimation()) {
                setBackgrounds();
                _monster1Count = 0;
                _monster2Count = 0;
                _monster3Count = 0;
                _monster1Vector.push_back(0);
                _monster2Vector.push_back(0);
                _monster3Vector.push_back(0);
            };

            void setMonsterVector1(SpriteType type, sf::RenderWindow &window, sf::Clock& clock);
            void setMonsterVector2(SpriteType type, sf::RenderWindow &window, sf::Clock& clock);
            void setMonsterVector3(SpriteType type, sf::RenderWindow &window, sf::Clock& clock);

            void displayBackgrounds(sf::RenderWindow& window, float deltaTime) {
                _parallaxAnimation.update(deltaTime, window, _backgroundsVector, _backgroundsSpeeds);
                _parallaxAnimation.updateBackgroundsAnim(deltaTime, window, _backgroundsAnimVector);
            }

            void setBackgrounds() {
                auto textures = SpriteLoader::getTextures();

                auto desiredHeight = static_cast<float>(HEIGHT);
                auto desiredWidth = static_cast<float>(WIDTH);

                //parralax backgrounds
                static std::vector<SpriteType> backgrounds = {
                    BACKGROUND_1,
                    FORGROUND_1,
                    GROUND_1
                };
                for (auto type : backgrounds) {
                    sf::Sprite background = sf::Sprite(textures->at(type));
                    background.setScale(1.0f, desiredHeight / background.getGlobalBounds().height);
                    _backgroundsVector.emplace_back(background);
                }

                //Stars
                static std::vector<SpriteType> Stars = {
                    BLACK_HOLE,
                    STAR,
                    BIG_RED_STAR,
                    BIG_GREEN_STAR,
                    LITTLE_STAR
                };
                for (auto type : Stars) {
                    sf::Sprite star = sf::Sprite(textures->at(type));
                    sf::IntRect rect(0, 0, textures->at(type).getSize().x / 9, textures->at(type).getSize().y);
                    star.setTextureRect(rect);
                    star.setScale(desiredWidth / star.getGlobalBounds().width, desiredHeight / star.getGlobalBounds().height);
                    _backgroundsAnimVector.emplace_back(star);
                }
                _backgroundsSpeeds.push_back(37.5f);
                _backgroundsSpeeds.push_back(75.0f);
                _backgroundsSpeeds.push_back(150.0f);
            }

            std::vector<sf::Sprite>& getBackgroundsVector() {
                return _backgroundsVector;
            }

        private:
            ParallaxAnimation _parallaxAnimation;

            std::vector<sf::Sprite> _backgroundsVector;
            std::vector<float> _backgroundsSpeeds;

            std::vector<sf::Sprite> _backgroundsAnimVector;

            int _monster1Count;
            int _monster2Count;
            int _monster3Count;
            std::vector<int> _monster1Vector;
            std::vector<int> _monster2Vector;
            std::vector<int> _monster3Vector;
    };

}

#endif //RTYPE_VECTORCONTAINER_HPP
