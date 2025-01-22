/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** EnemySystem
*/

#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include "../ASystem.hpp"

class EnemySystem : public ASystem {
    public:
        EnemySystem();
        ~EnemySystem();

        std::shared_ptr<std::vector<std::shared_ptr<Entity>>> getEntites() final;
        void addEntity(std::shared_ptr<Entity> &entity) final;

        void enemyOne(std::shared_ptr<Entity> &entity);
        void enemyTwo(std::shared_ptr<Entity> &entity);
        void enemyThree(std::shared_ptr<Entity> &entity);
        void enemyFour(std::shared_ptr<Entity> &entity);
        void enemyFive(std::shared_ptr<Entity> &entity);
        void enemySix(std::shared_ptr<Entity> &entity);
        void enemySeven(std::shared_ptr<Entity> &entity);
        void boss(std::shared_ptr<Entity> &entity);

        void TopLeftBlock(std::shared_ptr<Entity> &entity);
        void TopRightBlock(std::shared_ptr<Entity> &entity);
        void TopMidBlock(std::shared_ptr<Entity> &entity);

        void BotLeftBlock(std::shared_ptr<Entity> &entity);
        void BotRightBlock(std::shared_ptr<Entity> &entity);
        void BotMidBlock(std::shared_ptr<Entity> &entity);

        void MidLeftBlock(std::shared_ptr<Entity> &entity);
        void MidRightBlock(std::shared_ptr<Entity> &entity);
        void MidMidBlock(std::shared_ptr<Entity> &entity);

        void spawnerBlock(std::shared_ptr<Entity> &entity);
        void mysteryBlock(std::shared_ptr<Entity> &entity);

        void update() final;
    private:
        float _posBossX = 0;
        float _posBossY = 0;
        float _sizeBossWidth = 0;
        float _sizeBossHeight = 0;
};

#endif /* !ENEMYSystEnemySystem_HPP_ */
