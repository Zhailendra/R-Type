/*
** EPITECH PROJECT, 2024
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** HitboxSystem
*/

#ifndef HitboxSystem_HPP_
#define HitboxSystem_HPP_

#include "ECS/System/ASystem.hpp"
#include "ECS/Components/Bullet/BulletComponent.hpp"
#include "ECS/Components/Health/Health.hpp"
#include "ECS/Components/Enemy/EnemyComponent.hpp"
#include "ECS/Components/Controllable/ControllableComponent.hpp"
#include "Utils/SoundLoader.hpp"

class HitboxSystem : public ASystem{
    public:
        HitboxSystem();
        ~HitboxSystem();

    std::shared_ptr<std::vector<std::shared_ptr<Entity>>> getEntites() final;
    void addEntity(std::shared_ptr<Entity> &entity) final;
    void update() final;
    bool checkPlayerCollision(std::shared_ptr<Entity> &entity);
    bool checkEnemyCollision(std::shared_ptr<Entity> &entity);
    void checkItemCollision(std::shared_ptr<Entity> &entity);


    bool handlePlayer(std::shared_ptr<Entity> &entity, std::shared_ptr<Entity> &entity2);
    bool handleShield(std::shared_ptr<Entity> &entity, std::shared_ptr<Entity> &entity2);

    protected:
    private:
};

#endif /* !HitboxSystem_HPP_ */
