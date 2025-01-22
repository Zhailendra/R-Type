/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** NetworkSystem.hpp
*/

#ifndef NETWORKSYSTEM_HPP
#define NETWORKSYSTEM_HPP

#include <ECS/System/ASystem.hpp>
#include <ECS/Components/Position/PositionComponent.hpp>
#include <ECS/Components/Velocity/Velocity.hpp>
#include <ECS/Components/Renderable/Renderable.hpp>
#include <ECS/Components/Network/NetworkComponent.hpp>
#include <Network/EntitySerializer.hpp>
#include <ECS/System/NetworkSystem/Controller.hpp>
#include "ECS/Components/SendOverNetwork/SendOverNetworkComponent.hpp"

class NetworkSystem : public ASystem {
    public:
        NetworkSystem() = default;
        ~NetworkSystem() = default;

        std::shared_ptr<std::vector<std::shared_ptr<Entity>>> getEntites() final;
        void addEntity(std::shared_ptr<Entity> &entity) final;
        void update() final;
    private:
        std::shared_ptr<Entity> _networkEntity;
        std::vector<std::uint32_t> _ids_need_delete;
};

#endif //NETWORKSYSTEM_HPP
