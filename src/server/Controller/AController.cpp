/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** AController.cpp
*/

#include "AController.hpp"

std::map<Network::PacketType, ControllerHandlerServer> AController::getHandlers()
{
    return handlers;
}