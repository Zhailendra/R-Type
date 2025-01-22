/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** EntityController.hpp
*/

#ifndef ENTITYCONTROLLER_HPP
#define ENTITYCONTROLLER_HPP

#include "AController.hpp"
#include <Network/EntitySerializer.hpp>
#include <Network/Packet.hpp>

class EntityController : public AController {
public:
    EntityController() {
        this->handlers[Network::PacketType::NewEntity] = &EntityController::NewEntity;
        this->handlers[Network::PacketType::UpdateEntity] = &EntityController::UpdateEntity;
        this->handlers[Network::PacketType::GatherAllEntities] = &EntityController::GatherAllEntities;
        this->handlers[Network::PacketType::DestroyEntity] = &EntityController::DestroyEntity;
    }
    ~EntityController() = default;
    static void NewEntity(
        Network::INetwork<TemplateRefServer> &server, Network::Packet &packet,
        EntityManager &entityManager
    );
    static void UpdateEntity(
        Network::INetwork<TemplateRefServer> &server, Network::Packet &packet,
        EntityManager &entityManager
    );
    static void GatherAllEntities(
        Network::INetwork<TemplateRefServer> &server, Network::Packet &packet,
        EntityManager &entityManager
    );

    static void DestroyEntity(
        Network::INetwork<TemplateRefServer> &server, Network::Packet &packet,
        EntityManager &entityManager
    );

    static void SendEntity(
        Network::INetwork<TemplateRefServer> &server, EntityManager &manager, Network::PacketType type
    );
};

#endif //ENTITYCONTROLLER_HPP
