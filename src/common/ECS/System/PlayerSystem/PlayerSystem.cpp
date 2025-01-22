/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Player
*/

#include "PlayerSystem.hpp"

#include "ECS/Components/Augments/Augments.hpp"

PlayerSystem::PlayerSystem()
{
}

PlayerSystem::~PlayerSystem()
{
}

std::shared_ptr<std::vector<std::shared_ptr<Entity>>> PlayerSystem::getEntites()
{
    return _entities;
}

void PlayerSystem::keyPressed(std::shared_ptr<Entity> &entity, auto &controllable, auto &velo, auto &rect, auto &ev)
{
    auto sounds = rtype::SoundLoader::getSoundBuffers();
    velo.x = 0;
    velo.y = 0;
    rect._currentPlayerFrame = 2;
    if (sf::Keyboard::isKeyPressed(controllable.up)) {
        velo.y = -VELOCITY_SPEED_PLAYER;
        rect._upKeyPressed = true;
        rect._keyHoldClock.restart();
        if (rect._currentPlayerFrame < 4) {
            ++rect._currentPlayerFrame;
        }
        // if (rect._keyHoldClock.getElapsedTime().asSeconds() > ANIM_SPEED) {
        //     if (rect._currentPlayerFrame < 4) {
        //         ++rect._currentPlayerFrame;
        //     }
        // }
    }
    if (sf::Keyboard::isKeyPressed(controllable.down)) {
        velo.y = VELOCITY_SPEED_PLAYER;
        rect._downKeyPressed = true;
        rect._keyHoldClock.restart();
        if (rect._currentPlayerFrame > 0) {
            --rect._currentPlayerFrame;
        }
        // if (rect._keyHoldClock.getElapsedTime().asSeconds() > ANIM_SPEED) {
        //     if (rect._currentPlayerFrame > 0) {
        //         --rect._currentPlayerFrame;
        //     }
        // }
    }
    if (sf::Keyboard::isKeyPressed(controllable.left)) {
        velo.x = -VELOCITY_SPEED_PLAYER;
    }
    if (sf::Keyboard::isKeyPressed(controllable.right)) {
        velo.x = VELOCITY_SPEED_PLAYER;
    }
    if (ev.type == sf::Event::KeyPressed) {
        if (entity && entity->hasComponent<Augments>() && entity->getComponent<Augments>()._augments[0]) {
            if (ev.key.code ==  controllable.laser && !controllable.isLoadingLaser) {
                controllable.isLoadingLaser = true;
                controllable.isLoadedLaser = true;
                _loadingLaserEntity = EntityManager::createLaserLoading(
                        entity->getComponent<PositionComponent>().x + 100,
                        entity->getComponent<PositionComponent>().y + 30);
                _entities->push_back(_loadingLaserEntity);
                if (sounds == nullptr)
                    return;
                static sf::Sound sound;
                sound.setBuffer(sounds->at(LASER_1));
                sound.setVolume(50);
                sound.play();
                return;
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(controllable.shoot) && controllable.shootDelay > 10 &&
                                            !controllable.isLoadingLaser) {
        controllable.shootDelay = 0;
        std::shared_ptr<Entity> bullet = EntityManager::createBullet(
            entity->getComponent<PositionComponent>().x + 100,
            entity->getComponent<PositionComponent>().y + 30);
        _entities->push_back(bullet);
    }
}

void PlayerSystem::KeyReleased(std::shared_ptr<Entity> &entity, auto &controllable, auto &velo, auto &rect, auto &ev)
{
    auto sounds = rtype::SoundLoader::getSoundBuffers();
    if (ev.type == sf::Event::KeyReleased) {
        if (ev.key.code == controllable.laser && controllable.isLoadingLaser &&
            controllable.isLoadedLaser) {
            controllable.isLoadingLaser = false;
            controllable.isLoadedLaser = false;

            if (_loadingLaserEntity) {
                _entities->erase(std::find(_entities->begin(), _entities->end(), _loadingLaserEntity));
                controllable.isLoadedLaser = false;
            }

            std::shared_ptr<Entity> bullet = EntityManager::createLaser(
                    entity->getComponent<PositionComponent>().x + 100,
                    entity->getComponent<PositionComponent>().y + 5);
            _entities->push_back(bullet);
            if (sounds == nullptr)
                return;
            static sf::Sound sound;
            sound.setBuffer(sounds->at(LASER_2));
            sound.setVolume(50);
            sound.play();
            return;
        }
    }
}

void PlayerSystem::update()
{
    for (size_t i = 0; i < _entities.get()->size(); i++) {
        std::shared_ptr<Entity> &entity = (*_entities.get())[i];
        if (!entity->hasComponent<ControllableComponent>()) {
            continue;
        }

        auto &controllable = entity->getComponent<ControllableComponent>();
        auto &velo = entity->getComponent<Velocity>();
        auto &pos = entity->getComponent<PositionComponent>();
        auto &rect = entity->getComponent<Rectable>();
        controllable.shootDelay++;
        for (auto ev : *_inputs.get()) {
            keyPressed(entity, controllable, velo, rect, ev);
            KeyReleased(entity, controllable, velo, rect, ev);
        }
        // TODO make it with localbound of player sprite
        if (pos.x + velo.x < 0 || pos.x + velo.x > WIDTH - 70)
            velo.x = 0;
        if (pos.y + velo.y < 0 || pos.y + velo.y > HEIGHT - 70)
            velo.y = 0;
    }

}

void PlayerSystem::addEntity(std::shared_ptr<Entity> &entity)
{
}