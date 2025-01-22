/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** NetworkComponent.cpp
*/

#include "NetworkComponent.hpp"

NetworkComponent::NetworkComponent(sf::IpAddress ip, unsigned short port)
{
    _type = Components::NETWORK;
    _ip = ip;
    _port = port;
}

std::ostream &operator<<(std::ostream &os, const NetworkComponent &networkComponent)
{
    os << "NetworkComponent{ip: " << networkComponent._ip << ", port: " << networkComponent._port << ", isInit: " << networkComponent._isInit << "}";
    return os;
}



