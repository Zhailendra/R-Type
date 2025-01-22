/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Helper.hpp
*/

#ifndef HELPER_HPP
#define HELPER_HPP

#include "AController.hpp"

class Helper : public AController {
public:
    Helper() {
        this->handlers[Network::PacketType::Ping] = &Helper::ping;
    }
    ~Helper() = default;
    static void ping(
        Network::INetwork<TemplateRefServer> &server, Network::Packet &packet,
        EntityManager &entityManager
    );
};

#endif //HELPER_HPP
