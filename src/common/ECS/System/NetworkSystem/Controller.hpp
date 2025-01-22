/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Controller.hpp
*/


#include "Network/Client.hpp"
#include "ECS/Entity.hpp"
#include "Network/EntitySerializer.hpp"
#include <ECS/System/ASystem.hpp>
#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

typedef std::shared_ptr<std::vector<std::shared_ptr<Entity>>> & TemplateRefClient;

typedef std::function<void(
    Network::INetwork<TemplateRefClient> &client, Network::Packet &packet,
    TemplateRefClient entityManager
)> ControllerHandlerClient;



class Controller {
    public:
        Controller() {
            this->handlers[Network::PacketType::NewEntity] = &Controller::NewEntity;
            this->handlers[Network::PacketType::UpdateEntity] = &Controller::UpdateEntity;
            this->handlers[Network::PacketType::DestroyEntity] = &Controller::DestroyEntity;
        };
        ~Controller() = default;
        static void NewEntity(
            Network::INetwork<TemplateRefClient> &client, Network::Packet &packet,
            TemplateRefClient Entities
        );

        static void UpdateEntity(
            Network::INetwork<TemplateRefClient> &client, Network::Packet &packet,
            TemplateRefClient Entities
        );

        static void DestroyEntity(
            Network::INetwork<TemplateRefClient> &client, Network::Packet &packet,
            TemplateRefClient Entities
        );

        std::map<Network::PacketType, ControllerHandlerClient> getHandlers() {
            return this->handlers;
        }
    private:
        std::map<Network::PacketType, ControllerHandlerClient> handlers;
};

#endif //CONTROLLER_HPP
