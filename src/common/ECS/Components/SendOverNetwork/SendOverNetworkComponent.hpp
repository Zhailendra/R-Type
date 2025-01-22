/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** SendOverNetworkComponent.hpp
*/

#include <ECS/Components/AComponent.hpp>

#ifndef SENDOVERNETWORKCOMPONENT_HPP
#define SENDOVERNETWORKCOMPONENT_HPP

class SendOverNetworkComponent : public AComponent {
public:
    SendOverNetworkComponent() { _type = Components::SEND_OVER_NETWORK; };
    ~SendOverNetworkComponent() = default;

    friend std::ostream &operator<<(std::ostream &os, const SendOverNetworkComponent &sendOverNetworkComponent);
};

#endif //SENDOVERNETWORKCOMPONENT_HPP
