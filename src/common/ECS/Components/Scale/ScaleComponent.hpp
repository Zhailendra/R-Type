/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** ScaleComponent.hpp
*/

#ifndef SCALECOMPONENT_HPP
#define SCALECOMPONENT_HPP

#include <ECS/Components/AComponent.hpp>

class ScaleComponent : public AComponent {
public:
    ScaleComponent(float x = 1, float y = 1) : _x(x), _y(y) { _type = Components::SCALE; };
    ~ScaleComponent() = default;

    friend std::ostream &operator<<(std::ostream &os, const ScaleComponent &sendOverNetworkComponent);

    float _x;
    float _y;
};

#endif //SCALECOMPONENT_HPP
