/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** EntitySerializer.hpp
*/

#include <Network/Byte.hpp>
#include <ECS/Components/Position/PositionComponent.hpp>
#include <ECS/Components/Velocity/Velocity.hpp>
#include <ECS/Components/Renderable/Renderable.hpp>
#include <ECS/Components/Network/NetworkComponent.hpp>
#include <ECS/Components/Scale/ScaleComponent.hpp>

#ifndef ENTITYSERIALIZER_HPP
#define ENTITYSERIALIZER_HPP

class EntitySerializer {
    public:
    static void DeserializeEntity(
        Network::Byte &byte, std::shared_ptr<Entity> &Entity
    );
    static void SerializeEntity(
        Network::Byte &byte, std::shared_ptr<Entity> &Entity
    );
};

#endif //ENTITYSERIALIZER_HPP
