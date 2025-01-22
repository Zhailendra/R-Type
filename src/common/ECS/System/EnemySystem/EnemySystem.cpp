/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Player
*/

#include "EnemySystem.hpp"

#include "../ASystem.hpp"
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>
#include "../../../OstreamHelper.hpp"

#include "../../EntityManager.hpp"
#include "../../Components/Position/PositionComponent.hpp"
#include "../../Components/Renderable/Renderable.hpp"
#include "../../Components/Velocity/Velocity.hpp"
#include "../../Components/Controllable/ControllableComponent.hpp"
#include "../../Components/Rectable/Rectable.hpp"
#include "../../Components/Enemy/EnemyComponent.hpp"
#include "../../Components/SendOverNetwork/SendOverNetworkComponent.hpp"
#include "../../Components/Bullet/BulletComponent.hpp"
#include "ECS/Components/Scale/ScaleComponent.hpp"

EnemySystem::EnemySystem()
{
}

EnemySystem::~EnemySystem()
{
}

std::shared_ptr<std::vector<std::shared_ptr<Entity>>> EnemySystem::getEntites()
{
    return _entities;
}

void EnemySystem::enemyOne(std::shared_ptr<Entity> &entity)
{
    Velocity &velo = entity.get()->getComponent<Velocity>();
    Rectable &rect = entity.get()->getComponent<Rectable>();
    EnemyComponent &ene = entity.get()->getComponent<EnemyComponent>();

    velo.x = -VELOCITY_SPEED_ENNEMIES * 2;
    if (rect._keyHoldClock.getElapsedTime().asSeconds() > 0.12) {
        if (rect._currentPlayerFrame < rect._nbFrames)
            rect._currentPlayerFrame++;
        if (rect._currentPlayerFrame == rect._nbFrames - 1)
            rect._currentPlayerFrame = 0;
        rect._keyHoldClock.restart();
    }
    if (ene._clockEnemy.getElapsedTime().asSeconds() < 1) {
        velo.y = -VELOCITY_SPEED_ENNEMIES * 0.7;
    } else if (ene._clockEnemy.getElapsedTime().asSeconds() > 1 && ene._clockEnemy.getElapsedTime().asSeconds() < 2) {
        velo.y = VELOCITY_SPEED_ENNEMIES * 0.7;
    } else {
        ene._clockEnemy.restart();
    }
}

void EnemySystem::enemyTwo(std::shared_ptr<Entity> &entity)
{
    Velocity &velo = entity.get()->getComponent<Velocity>();
    Rectable &rect = entity.get()->getComponent<Rectable>();
    EnemyComponent &ene = entity.get()->getComponent<EnemyComponent>();

    velo.x = -VELOCITY_SPEED_ENNEMIES * 1.5;
    if (ene._clockEnemy.getElapsedTime().asSeconds() < 2) {
        float veloSpeed = -VELOCITY_SPEED_ENNEMIES * (1 - (ene._clockEnemy.getElapsedTime().asSeconds()));
        velo.y = veloSpeed;
        if (veloSpeed < 0) {
            rect._currentPlayerFrame = 2;
        } else {
            rect._currentPlayerFrame = 5;
        }
    } else {
        ene._clockEnemy.restart();
    }
}

void EnemySystem::enemyThree(std::shared_ptr<Entity> &entity)
{
    std::srand(static_cast<unsigned>(std::time(0)));
    float randomX = static_cast<float>(std::rand() % WIDTH);
    float randomY = static_cast<float>(std::rand() % HEIGHT);
    Velocity &velo = entity.get()->getComponent<Velocity>();
    Rectable &rect = entity.get()->getComponent<Rectable>();
    EnemyComponent &ene = entity.get()->getComponent<EnemyComponent>();
    PositionComponent &pos = entity.get()->getComponent<PositionComponent>();

    velo.x = -VELOCITY_SPEED_ENNEMIES;
    if (rect._keyHoldClock.getElapsedTime().asSeconds() > 0.12) {
        if (rect._currentPlayerFrame < rect._nbFrames)
            rect._currentPlayerFrame++;
        if (rect._currentPlayerFrame == rect._nbFrames - 1)
            rect._currentPlayerFrame = 0;
        rect._keyHoldClock.restart();
    }
    if (ene._clockEnemy.getElapsedTime().asSeconds() >= 0.5) {
        sf::Vector2f direction = sf::Vector2f(randomX - pos.x, randomY - pos.y);
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        float projectileSpeed = 5.0f;
        sf::Vector2f normalizedDirection = direction / length;
        sf::Vector2f finalVelocity = sf::Vector2f(-std::abs(projectileSpeed), std::abs(projectileSpeed) * normalizedDirection.y);
        _entities.get()->push_back(EntityManager::createBulletEnemy(_entities.get()->size() - 1,
            entity.get()->getComponent<PositionComponent>().x,
            entity.get()->getComponent<PositionComponent>().y +
                    (entity.get()->getComponent<Renderable>()._sprite.getGlobalBounds().height / 2),
            4, finalVelocity));
        ene._clockEnemy.restart();
    }
}

void EnemySystem::enemyFour(std::shared_ptr<Entity> &entity)
{
    std::srand(static_cast<unsigned>(std::time(0)));
    float randomX = static_cast<float>(std::rand() % WIDTH);
    float randomY = static_cast<float>(std::rand() % HEIGHT);
    Velocity &velo = entity.get()->getComponent<Velocity>();
    Rectable &rect = entity.get()->getComponent<Rectable>();
    EnemyComponent &ene = entity.get()->getComponent<EnemyComponent>();
    PositionComponent &pos = entity.get()->getComponent<PositionComponent>();

    if (rect._keyHoldClock.getElapsedTime().asSeconds() > 0.2) {
        if (rect._currentPlayerFrame < 4) {
            velo.x = -VELOCITY_SPEED_ENNEMIES * 6;
            rect._currentPlayerFrame++;
        }
        if (rect._currentPlayerFrame == 3)
            rect._currentPlayerFrame = 0;
        rect._keyHoldClock.restart();
        return;
    }
    velo.x = -VELOCITY_SPEED_ENNEMIES * 0;
    if (ene._clockEnemy.getElapsedTime().asSeconds() >= 0.5) {
        sf::Vector2f direction = sf::Vector2f(randomX - pos.x, randomY - pos.y);
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        float projectileSpeed = 5.0f;
        sf::Vector2f normalizedDirection = direction / length;
        sf::Vector2f finalVelocity = sf::Vector2f(-std::abs(projectileSpeed), std::abs(projectileSpeed) * normalizedDirection.y);
        _entities.get()->push_back(EntityManager::createBulletEnemy(_entities.get()->size() - 1,
            entity.get()->getComponent<PositionComponent>().x,
            entity.get()->getComponent<PositionComponent>().y +
                    (entity.get()->getComponent<Renderable>()._sprite.getGlobalBounds().height / 2),
            4, finalVelocity));

        ene._clockEnemy.restart();
    }
}

void EnemySystem::enemyFive(std::shared_ptr<Entity> &entity)
{
    std::srand(static_cast<unsigned>(std::time(0)));
    float randomX = static_cast<float>(std::rand() % WIDTH);
    float randomY = static_cast<float>(std::rand() % HEIGHT);
    Velocity &velo = entity.get()->getComponent<Velocity>();
    Rectable &rect = entity.get()->getComponent<Rectable>();
    EnemyComponent &ene = entity.get()->getComponent<EnemyComponent>();
    PositionComponent &pos = entity.get()->getComponent<PositionComponent>();

    if (ene._clockEnemy.getElapsedTime().asSeconds() > 2) {
        velo.x = VELOCITY_SPEED_ENNEMIES * 0.2;
        if (ene._clockEnemy.getElapsedTime().asSeconds() >= 0.5) {
            sf::Vector2f direction = sf::Vector2f(randomX - pos.x, randomY - pos.y);
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
            float projectileSpeed = 5.0f;
            sf::Vector2f normalizedDirection = direction / length;
            sf::Vector2f finalVelocity = sf::Vector2f(-std::abs(projectileSpeed), std::abs(projectileSpeed) * normalizedDirection.y);
            _entities.get()->push_back(EntityManager::createBulletEnemy(_entities.get()->size() - 1,
                    entity.get()->getComponent<PositionComponent>().x,
                    entity.get()->getComponent<PositionComponent>().y +
                            (entity.get()->getComponent<Renderable>()._sprite.getGlobalBounds().height / 2),
                    4, finalVelocity));
            ene._clockEnemy.restart();
        }
        rect._currentPlayerFrame = 2;
    } else {
        rect._currentPlayerFrame = 1;
        velo.x = -VELOCITY_SPEED_ENNEMIES * 1.2;
    }
}

void EnemySystem::boss(std::shared_ptr<Entity> &entity)
{
    std::srand(static_cast<unsigned>(std::time(0)));
    float randomX = static_cast<float>(std::rand() % WIDTH);
    float randomY = static_cast<float>(std::rand() % HEIGHT);
    Velocity &velo = entity.get()->getComponent<Velocity>();
    Rectable &rect = entity.get()->getComponent<Rectable>();
    EnemyComponent &ene = entity.get()->getComponent<EnemyComponent>();

    velo.x = -VELOCITY_SPEED_ENNEMIES * 1.2;

    PositionComponent &pos = entity.get()->getComponent<PositionComponent>();

    const float frameDelay = 0.2f;

    if (rect._keyHoldClock.getElapsedTime().asSeconds() >= frameDelay / 100) {
        rect._keyHoldClock.restart();

        if (rect._frameNumber < rect._nbFramesHeight - 1) {
            rect._frameHeightMultiplier++;
            rect._frameNumber++;
        } else {
            if (rect._frameNumber >= (rect._nbFramesHeight - 1) && !rect._switchTop) {
                sf::Vector2f direction = sf::Vector2f(randomX - pos.x, randomY - pos.y);
                float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
                float projectileSpeed = 20.0f;
                sf::Vector2f normalizedDirection = direction / length;
                sf::Vector2f finalVelocity = sf::Vector2f(-std::abs(projectileSpeed), -std::abs(projectileSpeed) * normalizedDirection.y);
                _entities->push_back(
                        EntityManager::createBulletBoss(pos.x + (rect._frameSizeWidth / 2) - 50,
                                                        pos.y + (rect._frameSizeHeight * 4) + 20,
                                                        finalVelocity));
                rect._switchTop = true;
                rect._currentPlayerFrame++;
            } else {
                if (rect._currentPlayerFrame >= rect._nbFrames - 1) {
                    rect._frameNumber = 1;
                    rect._switchTop = false;
                    rect._currentPlayerFrame = 0;
                    rect._frameHeightMultiplier = 1;
                } else {
                    rect._switchTop = false;
                    rect._frameNumber = 1;
                    rect._frameHeightMultiplier = 1;
                }
            }
        }
    }

    if (pos.x <= WIDTH - (rect._frameSizeWidth + 20)) {
        velo.x = 0.0;
    }
}

void EnemySystem::enemySix(std::shared_ptr<Entity> &entity)
{
    Velocity &velo = entity.get()->getComponent<Velocity>();
    Rectable &rect = entity.get()->getComponent<Rectable>();
    EnemyComponent &ene = entity.get()->getComponent<EnemyComponent>();

    if (rect._keyHoldClock.getElapsedTime().asSeconds() > 0.15) {
        if (rect._currentPlayerFrame == 5)
            rect._currentPlayerFrame = 0;
        rect._currentPlayerFrame++;
        rect._keyHoldClock.restart();
    }
    if (ene._clockEnemy.getElapsedTime().asSeconds() > 5) {
        _entities.get()->push_back(EntityManager::createBulletEnemy(_entities.get()->size() - 1,
            entity.get()->getComponent<PositionComponent>().x,
            entity.get()->getComponent<PositionComponent>().y +
                (entity.get()->getComponent<Renderable>()._sprite.getGlobalBounds().height / 2),
            4, sf::Vector2f(-10, 0)));
    }
    if (ene._clockEnemy.getElapsedTime().asSeconds() > 7)
        ene._clockEnemy.restart();
    velo.x = -VELOCITY_SPEED_ENNEMIES;
}

void EnemySystem::enemySeven(std::shared_ptr<Entity> &entity)
{
    Velocity &velo = entity.get()->getComponent<Velocity>();
    Rectable &rect = entity.get()->getComponent<Rectable>();
    EnemyComponent &ene = entity.get()->getComponent<EnemyComponent>();

    velo.x = -VELOCITY_SPEED_ENNEMIES * 2;
    if (ene._clockEnemy.getElapsedTime().asSeconds() > 0.2) {
        _entities.get()->push_back(EntityManager::createBlock(entity.get()->getComponent<PositionComponent>().x +
                (entity->getComponent<Renderable>()._sprite.getGlobalBounds().height / 2) + 14,
            entity.get()->getComponent<PositionComponent>().y +
                (entity->getComponent<Renderable>()._sprite.getGlobalBounds().height / 2) - 14,
            17));
        ene._clockEnemy.restart();
    }
}


void EnemySystem::TopLeftBlock(std::shared_ptr<Entity> &entity)
{
    Velocity &velo = entity.get()->getComponent<Velocity>();

    velo.x = -VELOCITY_SPEED_ENNEMIES * 1.2;
}

void EnemySystem::TopRightBlock(std::shared_ptr<Entity> &entity)
{
    Velocity &velo = entity.get()->getComponent<Velocity>();

    velo.x = -VELOCITY_SPEED_ENNEMIES * 1.2;
}

void EnemySystem::TopMidBlock(std::shared_ptr<Entity> &entity)
{
    Velocity &velo = entity.get()->getComponent<Velocity>();

    velo.x = -VELOCITY_SPEED_ENNEMIES * 1.2;
}


void EnemySystem::BotLeftBlock(std::shared_ptr<Entity> &entity)
{
    Velocity &velo = entity.get()->getComponent<Velocity>();

    velo.x = -VELOCITY_SPEED_ENNEMIES * 1.2;
}

void EnemySystem::BotRightBlock(std::shared_ptr<Entity> &entity)
{
    Velocity &velo = entity.get()->getComponent<Velocity>();

    velo.x = -VELOCITY_SPEED_ENNEMIES * 1.2;
}

void EnemySystem::BotMidBlock(std::shared_ptr<Entity> &entity)
{
    Velocity &velo = entity.get()->getComponent<Velocity>();

    velo.x = -VELOCITY_SPEED_ENNEMIES * 1.2;
}


void EnemySystem::MidLeftBlock(std::shared_ptr<Entity> &entity)
{
    Velocity &velo = entity.get()->getComponent<Velocity>();

    velo.x = -VELOCITY_SPEED_ENNEMIES * 1.2;
}

void EnemySystem::MidRightBlock(std::shared_ptr<Entity> &entity)
{
    Velocity &velo = entity.get()->getComponent<Velocity>();

    velo.x = -VELOCITY_SPEED_ENNEMIES * 1.2;
}

void EnemySystem::MidMidBlock(std::shared_ptr<Entity> &entity)
{
    Velocity &velo = entity.get()->getComponent<Velocity>();

    velo.x = -VELOCITY_SPEED_ENNEMIES * 1.2;
}

void EnemySystem::spawnerBlock(std::shared_ptr<Entity> &entity)
{
    Velocity &velo = entity.get()->getComponent<Velocity>();
    EnemyComponent &ene = entity.get()->getComponent<EnemyComponent>();
    ScaleComponent &scale = entity.get()->getComponent<ScaleComponent>();

    velo.x = -VELOCITY_SPEED_ENNEMIES * 1.2;
}

void EnemySystem::mysteryBlock(std::shared_ptr<Entity> &entity)
{
    Velocity &velo = entity.get()->getComponent<Velocity>();
    EnemyComponent &ene = entity.get()->getComponent<EnemyComponent>();
    ScaleComponent &scale = entity.get()->getComponent<ScaleComponent>();

    velo.x = -VELOCITY_SPEED_ENNEMIES * 1.2;
}

void EnemySystem::update()
{
    for (size_t i = 0; i < _entities.get()->size(); i++) {
        std::shared_ptr<Entity> &entity = (*_entities.get())[i];
        if (!entity) continue;
        if (!entity.get()->hasComponent<EnemyComponent>()) {
            continue;
        }
        EnemyComponent &ene = entity.get()->getComponent<EnemyComponent>();

        switch (entity.get()->getComponent<EnemyComponent>()._enemyType) {
            case 1:
                enemyOne(entity);
                break;
            case 2:
                enemyTwo(entity);
                break;
            case 3:
                enemyThree(entity);
                break;
            case 4:
                enemyFour(entity);
                break;
            case 5:
                enemyFive(entity);
                break;

            case 8:
                TopLeftBlock(entity);
                break;
            case 9:
                TopMidBlock(entity);
                break;
            case 10:
                TopRightBlock(entity);
                break;

            case 11:
                MidLeftBlock(entity);
                break;
            case 12:
                MidMidBlock(entity);
                break;
            case 13:
                MidRightBlock(entity);
                break;

            case 14:
                BotLeftBlock(entity);
                break;
            case 15:
                BotMidBlock(entity);
                break;
            case 16:
                BotRightBlock(entity);
                break;

            case 6:
                enemySix(entity);
                break;
            case 7:
                enemySeven(entity);
                break;
            case 17:
                spawnerBlock(entity);
                break;
            case 18:
                mysteryBlock(entity);
                break;
            case 19:
                boss(entity);
                break;
            default:
                break;
        }
    }
}

void EnemySystem::addEntity(std::shared_ptr<Entity> &entity)
{
}
