/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Controllers.hpp
*/

#ifndef CONTROLLERS_HPP
#define CONTROLLERS_HPP

#include "Helper.hpp"
#include "EntityController.hpp"

class Controllers {
public:
    Controllers() = default;
    ~Controllers() = default;

    static void gather(std::map<Network::PacketType, ControllerHandlerServer>&handlers, AController *controller) {
        for (auto &handler : controller->getHandlers()) {
            handlers[handler.first] = handler.second;
        }
    }
    static std::map<Network::PacketType, ControllerHandlerServer> getHandlers() {
        std::map<Network::PacketType, ControllerHandlerServer> handlers;
        std::vector<AController *> controllers = {
            new Helper(),
            new EntityController()
        };
        for (auto &controller : controllers) {
            gather(handlers, controller);
        }
        return handlers;
    }
};

#endif //CONTROLLERS_HPP
