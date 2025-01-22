/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** ScaleSystem.hpp
*/

#ifndef SCALESYSTEM_HPP
#define SCALESYSTEM_HPP

#include <ECS/System/ASystem.hpp>
#include <ECS/Components/Scale/ScaleComponent.hpp>
#include <ECS/Components/Renderable/Renderable.hpp>

class ScaleSystem : public ASystem {
public:
    ScaleSystem() = default;
    ~ScaleSystem() = default;

    std::shared_ptr<std::vector<std::shared_ptr<Entity>>> getEntites() final;
    void addEntity(std::shared_ptr<Entity> &entity) final;
    void update() final;
};

#endif //SCALESYSTEM_HPP
