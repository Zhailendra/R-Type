/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** IController.hpp
*/

#ifndef ICONTROLLER_HPP
#define ICONTROLLER_HPP

#include <functional>
#include <ECS/EntityManager.hpp>
#include <Network/Server.hpp>

typedef EntityManager & TemplateRefServer;

typedef std::function<void(
    Network::INetwork<TemplateRefServer> &server, Network::Packet &packet,
    EntityManager &entityManager
)> ControllerHandlerServer;

class IController {
    public:
        IController() = default;
        ~IController() = default;
    virtual std::map<Network::PacketType, ControllerHandlerServer> getHandlers() = 0;
};

#endif //ICONTROLLER_HPP
