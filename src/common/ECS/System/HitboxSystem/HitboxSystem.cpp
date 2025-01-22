/*
** EPITECH PROJECT, 2024
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** HitboxSystem
*/

#include "HitboxSystem.hpp"

#include "ECS/Components/Augments/Augments.hpp"
#include "ECS/Components/Item/Item.hpp"
#include "ECS/Components/Shield/ShieldComponent.hpp"


HitboxSystem::HitboxSystem()
{
}

HitboxSystem::~HitboxSystem()
{
}

bool HitboxSystem::handlePlayer(std::shared_ptr<Entity> &entity, std::shared_ptr<Entity> &entity2)
{
    const Renderable &player = entity2->getComponent<Renderable>(); // hotfix need a & to work
    const Renderable &bullet = entity->getComponent<Renderable>();// hotfix need a & to work
    sf::FloatRect playerHitbox;
    sf::FloatRect bulletHitbox;

    if (entity2->hasComponent<Rectable>()) {
        const Rectable playerRect = entity2->getComponent<Rectable>();
        playerHitbox = player.getHitbox();
        playerHitbox.width = playerHitbox.width / playerRect._nbFrames;
    } else {
        playerHitbox = player.getHitbox();
    }
    if (entity->hasComponent<Rectable>()) {
        const Rectable bulletRect = entity->getComponent<Rectable>();
        bulletHitbox = bullet.getHitbox();
        bulletHitbox.width = bulletHitbox.width / bulletRect._nbFrames;
    } else {
        playerHitbox = player.getHitbox();
    }


    if (playerHitbox.intersects(bulletHitbox)) {
        if (entity != nullptr)
            EntityManager::destroyEntity(_entities, entity->getId());
        if (entity2 != nullptr) {
            if (entity2.get()->hasComponent<Health>()) {
                entity2.get()->getComponent<Health>()._hp -= 1;
                if (entity2.get()->getComponent<Health>()._hp <= 0) {
                    _entities->push_back(EntityManager::createExplosion(entity2->getComponent<PositionComponent>().x, entity2->getComponent<PositionComponent>().y));
                    EntityManager::destroyEntity(_entities, entity2->getId());
                }
            } else {
                _entities->push_back(EntityManager::createExplosion(entity2->getComponent<PositionComponent>().x, entity2->getComponent<PositionComponent>().y));
                EntityManager::destroyEntity(_entities, entity2->getId());
            }
        }
        auto sounds = rtype::SoundLoader::getSoundBuffers();
        static sf::Sound sound;
        if (sounds == nullptr)
            return true;
        sound.setBuffer(sounds->at(DAMAGE));
        sound.setVolume(50);
        sound.play();
        return true;
    }
    return false;
}

bool HitboxSystem::handleShield(std::shared_ptr<Entity> &entity, std::shared_ptr<Entity> &entity2)
{
    const Renderable bullet = entity->getComponent<Renderable>(); // hotfix need a & to work
    const auto shield = entity2->getComponent<Renderable>();
    sf::FloatRect bulletHitbox;

    if (entity->hasComponent<Rectable>()) {
        const Rectable bulletRect = entity->getComponent<Rectable>();
        bulletHitbox = bullet.getHitbox();
        bulletHitbox.width = bulletHitbox.width / bulletRect._nbFrames;
    } else {
        bulletHitbox = bullet.getHitbox();
    }

    if (shield.getHitbox().intersects(bulletHitbox)) {
        if (entity != nullptr)
            EntityManager::destroyEntity(_entities, entity->getId());
        if (entity2 != nullptr) {
            if (entity2.get()->hasComponent<Health>()) {
                entity2.get()->getComponent<Health>()._hp -= 1;
                if (entity2.get()->getComponent<Health>()._hp <= 0) {
                    EntityManager::destroyEntity(_entities, entity2->getId());
                }
            } else {
                EntityManager::destroyEntity(_entities, entity2->getId());
            }
        }
        return true;
    }
    return false;
}

bool HitboxSystem::checkEnemyCollision(std::shared_ptr<Entity> &entity)
{
    sf::FloatRect bulletHitbox = entity->getComponent<Renderable>().getHitbox();
    for (size_t i = 0; i < _entities->size(); i++) {
        std::shared_ptr<Entity> &entity2 = (*_entities)[i];
        if (entity2->hasComponent<EnemyComponent>() && entity2->hasComponent<Renderable>()) {
            auto &enemyType = entity2->getComponent<EnemyComponent>();
            auto &enemy = entity2->getComponent<Renderable>(); // hotfix need a & to work
            auto &pos = entity2->getComponent<PositionComponent>();
            sf::FloatRect enemyHitbox;
            if (entity2->hasComponent<Rectable>()) {
                auto &enemyRect = entity2->getComponent<Rectable>();
                enemyHitbox = enemy.getHitbox();
                enemyHitbox.width = enemyHitbox.width / enemyRect._nbFrames;
                enemyHitbox.height = enemyHitbox.height / enemyRect._nbFramesHeight;
            } else {
                enemyHitbox = enemy.getHitbox();
            }
            if (entity->hasComponent<Rectable>()) {
                const Rectable &rect = entity->getComponent<Rectable>();
                bulletHitbox.width = bulletHitbox.width / rect._nbFrames;
            }
            if (bulletHitbox.intersects(enemyHitbox)) {
                if (entity != nullptr)
                    EntityManager::destroyEntity(_entities, entity->getId());
                if (entity2 != nullptr) {
                    if (enemyType._enemyType == 18) {
                        auto item = EntityManager::createItem(pos.x, pos.y);
                        _entities->push_back(item);
                    }
                    auto enemytype = entity2->getComponent<EnemyComponent>()._enemyType;
                    if (!(enemytype >= 8 && enemytype <= 18))
                        _entities->push_back(EntityManager::createExplosion(entity2->getComponent<PositionComponent>().x, entity2->getComponent<PositionComponent>().y));
                    if (entity2.get()->hasComponent<Health>()) {
                        entity2.get()->getComponent<Health>()._hp -= 1;
                        if (entity2.get()->getComponent<Health>()._hp <= 0) {
                            EntityManager::destroyEntity(_entities, entity2->getId());
                        }
                    } else {
                        EntityManager::destroyEntity(_entities, entity2->getId());
                    }
                }
                // entity2.get()->getComponent<Health>()._hp -= 1;
                // if (entity2.get()->getComponent<Health>()._hp <= 0) {
                //     entity2.get()->getComponent<Health>()._hp = 0;
                // }
                return true;
            }
        }
    }
    return false;
}

bool HitboxSystem::checkPlayerCollision(std::shared_ptr<Entity> &entity)
{
    for (size_t i = 0; i < _entities->size(); i++) {
        std::shared_ptr<Entity> &entity2 = (*_entities)[i];
        if (!entity2->hasComponent<Renderable>() && !entity->hasComponent<Renderable>()) continue;
        if (entity2->hasComponent<ShieldComponent>()) {
            if (handleShield(entity, entity2))
                return true;
        }
        if (entity2->hasComponent<ControllableComponent>()) {
            if (handlePlayer(entity, entity2))
                return true;
        }
    }
    return false;
}

void HitboxSystem::checkItemCollision(std::shared_ptr<Entity> &entity)
{
    for (size_t i = 0; i < _entities->size(); i++) {
        std::shared_ptr<Entity> &entity2 = (*_entities)[i];
        if (entity2->hasComponent<ControllableComponent>()) {
            const Renderable &player = entity2->getComponent<Renderable>(); // hotfix need a & to work
            const Renderable &bullet = entity->getComponent<Renderable>();// hotfix need a & to work
            sf::FloatRect playerHitbox;
            sf::FloatRect itemHitbox;

            if (entity2->hasComponent<Rectable>()) {
                const Rectable playerRect = entity2->getComponent<Rectable>();
                playerHitbox = player.getHitbox();
                playerHitbox.width = playerHitbox.width / playerRect._nbFrames;
            } else {
                playerHitbox = player.getHitbox();
            }

            if (entity->hasComponent<Rectable>()) {
                const Rectable itemRect = entity->getComponent<Rectable>();
                itemHitbox = bullet.getHitbox();
                itemHitbox.width = itemHitbox.width / itemRect._nbFrames;
            } else {
                itemHitbox = bullet.getHitbox();
            }

            if (playerHitbox.intersects(itemHitbox)) {
                auto &aug = entity2->getComponent<Augments>();
                auto &item = entity->getComponent<ItemComponent>();

                aug._augments[item._indexType] = true;
                if (entity != nullptr)
                    EntityManager::destroyEntity(_entities, entity->getId());
            }
        }
    }
}

void HitboxSystem::update()
{
    for (size_t i = 0; i < _entities->size(); i++) {
        std::shared_ptr<Entity> &entity = (*_entities)[i];
        if (entity.get()->hasComponent<BulletComponent>() && entity.get()->hasComponent<Renderable>()) {
            const auto &bullet = entity.get()->getComponent<BulletComponent>();
            if (bullet._typeBullet == 0) {
                if (checkEnemyCollision(entity))
                    continue;
            } else
                if (checkPlayerCollision(entity))
                    continue;
        }
        if (entity->hasComponent<ControllableComponent>()) {
            checkEnemyCollision(entity);
        }
        if (entity->hasComponent<ItemComponent>()) {
            checkItemCollision(entity);
        }
    }
}

std::shared_ptr<std::vector<std::shared_ptr<Entity>>> HitboxSystem::getEntites()
{
    return _entities;
}

void HitboxSystem::addEntity(std::shared_ptr<Entity> &entity)
{
    _entities.get()->push_back(entity);
}