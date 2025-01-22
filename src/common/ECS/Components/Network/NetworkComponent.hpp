/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** NetworkComponent.hpp
*/

#ifndef NETWORKCOMPONENT_HPP
#define NETWORKCOMPONENT_HPP

#include <ECS/Components/AComponent.hpp>
#include <ECS/System/NetworkSystem/Controller.hpp>
#include <Network/Client.hpp>
#include <chrono>

class NetworkComponent : public AComponent {
public:
    NetworkComponent() { _type = Components::NETWORK; };
    NetworkComponent(sf::IpAddress ip, unsigned short port);
    ~NetworkComponent() { delete _client; };

    void setInit(bool isInit) { _isInit = isInit; };
    void setClient(Network::Client<TemplateRefClient> *client) { _client = client; };

    friend std::ostream &operator<<(std::ostream &os, const NetworkComponent &networkComponent);

    sf::IpAddress _ip{};
    unsigned short _port{};
    Network::Client<TemplateRefClient>* _client = nullptr;
    bool _isInit = false;
    std::map<std::uint32_t, Network::Byte> _checksums;
    // interval to send data
    std::chrono::microseconds _interval = std::chrono::milliseconds(1000 / 10);
    std::chrono::time_point<std::chrono::system_clock> _lastSend = std::chrono::system_clock::now();
};

#endif //NETWORKCOMPONENT_HPP
