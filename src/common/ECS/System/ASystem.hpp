/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** ASystem
*/

#include "ISystem.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "../Entity.hpp"
#include "../EntityManager.hpp"

#ifndef ASYSTEM_HPP_
#define ASYSTEM_HPP_

static const float VELOCITY_SPEED_PLAYER = 6;
static const float VELOCITY_SPEED_ENNEMIES = 4;

static const float VELOCITY_SPEED_BULLET = 12;
static const float ANIM_SPEED = 0.5;

class ASystem : public ISystem {
    public:
        ASystem();
        virtual ~ASystem() = 0;

        virtual std::shared_ptr<std::vector<std::shared_ptr<Entity>>> getEntites() = 0;
        virtual void addEntity(std::shared_ptr<Entity> &entity) = 0;
        void setInputs(std::shared_ptr<std::vector<sf::Event>> &inputs);
        void setEntities(std::shared_ptr<std::vector<std::shared_ptr<Entity>>> entities);

        virtual void update() = 0;
    protected:
        std::shared_ptr<std::vector<sf::Event>> _inputs;
        std::shared_ptr<std::vector<std::shared_ptr<Entity>>> _entities;
        std::shared_ptr<Entity> _loadingLaserEntity = nullptr;
    private:
};

#endif /* !ASYSTEM_HPP_ */
