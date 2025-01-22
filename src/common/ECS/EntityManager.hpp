/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Byte.hpp
*/

#ifndef EntityManager_HPP
#define EntityManager_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <random>
#include "Entity.hpp"
#include "../OstreamHelper.hpp"
#include "../Utils/SpriteLoader.hpp"
#include "../Utils/Path.hpp"

#include "Components/Position/PositionComponent.hpp"
#include "Components/Renderable/Renderable.hpp"
#include "Components/Velocity/Velocity.hpp"
#include "Components/Rectable/Rectable.hpp"
#include "Components/Controllable/ControllableComponent.hpp"
#include "Components/Explosion/Explosion.hpp"

class EntityManager {
    public:
        using MaxEntites = std::uint32_t;
    public:
        EntityManager();
        ~EntityManager() = default;

        std::shared_ptr<Entity> createEntity();
        static void destroyEntity(const std::shared_ptr<std::vector<std::shared_ptr<Entity>>>&, std::uint32_t entity);

        std::shared_ptr<Entity> getEntity(std::uint32_t entityId) const;
        std::shared_ptr<std::vector<std::shared_ptr<Entity>>> getEntity() const;
        std::queue<std::uint32_t> getAvailableEntities() const;
        int getSize() const;

        std::shared_ptr<Entity> createPlayer();
        static std::shared_ptr<Entity> createBullet(int x, int y);
        static std::shared_ptr<Entity> createLaserLoading(int x, int y);
        static std::shared_ptr<Entity> createLaser(int x, int y);
        static std::shared_ptr<Entity> createShield(int x, int y);
        static std::shared_ptr<Entity> createText(int x, int y, std::string message, int size, bool debug = false);
        static std::shared_ptr<Entity> createItem(int x, int y, int type = -1);
        static std::shared_ptr<Entity> createButton(
            int x, int y, sf::Vector2f size, std::string message, int sizeText,
            sf::Color TextColor, sf::Color BackgroundColor,
            std::function<void()> callback
        );
        static std::shared_ptr<Entity> createInput(
            int x, int y, sf::Vector2f size, std::string message, int sizeText,
            sf::Color TextColor, sf::Color BackgroundColor,
            std::function<void(std::string)> callback
        );

        static std::shared_ptr<Entity> createBlock(int x, int y, int type);
        std::shared_ptr<Entity> createEnemy(float x, float y, int type);
        static std::shared_ptr<Entity> createBulletEnemy(int size, int x, int y, int projectileType, sf::Vector2f velo);
        static std::shared_ptr<Entity> createBulletBoss(float x, float y, sf::Vector2f velo);
        static std::shared_ptr<Entity> createExplosion(float x, float y);

        friend std::ostream &operator<<(std::ostream &os, const EntityManager &EntityManager);
    private:
        std::shared_ptr<std::vector<std::shared_ptr<Entity>>> entities;
        std::queue<std::uint32_t> availableEntities;
        std::uniform_int_distribution<std::uint32_t> distribution;
        std::mt19937 gen;

        float _bossPosX = 0;
        float _bossPosY = 0;
};

#endif