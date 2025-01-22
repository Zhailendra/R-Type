/*
** EPITECH PROJECT, 2024
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** ProjectileSystem.hpp
*/

#ifndef B_CPP_500_LIL_5_2_RTYPE_YACINE_OURTANANE_PROJECTILESYSTEM_HPP
#define B_CPP_500_LIL_5_2_RTYPE_YACINE_OURTANANE_PROJECTILESYSTEM_HPP
#include "Utils/SoundLoader.hpp"
#include "../ASystem.hpp"
#include <ECS/Components/Position/PositionComponent.hpp>
#include <ECS/Components/Renderable/Renderable.hpp>
#include <ECS/Components/Velocity/Velocity.hpp>
#include <ECS/Components/Controllable/ControllableComponent.hpp>
#include <ECS/Components/Rectable/Rectable.hpp>
#include <ECS/Components/Laser/LaserComponent.hpp>
#include <ECS/Components/Laser/LaserLoadingComponent.hpp>
#include <ECS/Components/Bullet/BulletComponent.hpp>

class ProjectileSystem :  public ASystem {
    public:
        ProjectileSystem();
        ~ProjectileSystem();

        std::shared_ptr<std::vector<std::shared_ptr<Entity>>> getEntites() final;
        void addEntity(std::shared_ptr<Entity> &entity) final;

        void update() final;

    protected:
    private:
};

#endif