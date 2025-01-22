/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** AController.hpp
*/

#ifndef ACONTROLLER_HPP
#define ACONTROLLER_HPP

#include "IController.hpp"

class AController : public IController {
    public:
        AController() = default;
        ~AController() = default;
        std::map<Network::PacketType, ControllerHandlerServer> getHandlers() override;
    protected:
        std::map<Network::PacketType, ControllerHandlerServer> handlers;
};

#endif //ACONTROLLER_HPP
