/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Helper.cpp
*/

#include "Helper.hpp"

void Helper::ping(
    Network::INetwork<TemplateRefServer> &server, Network::Packet &packet,
    EntityManager &entityManager
)
{
    Network::Byte byte;
    Network::PacketType packetType = Network::PacketType::Pong;
    Network::PacketNumber packetNumber = 0; //need to be changed
    byte << packetType;
    byte << packetNumber;
    server.response(packet, byte);

}