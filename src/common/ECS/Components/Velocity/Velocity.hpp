/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Velocity
*/

#ifndef VELOCITY_HPP_
#define VELOCITY_HPP_

#include "../AComponent.hpp"

class Velocity : public AComponent {
    public:
        Velocity(float x = 0, float y = 0, float z = 0);
        ~Velocity() = default;

        friend std::ostream &operator<<(std::ostream &os, const Velocity &velocity);

        float x;
        float y;
        float z;
};

#endif /* !VELOCITY_HPP_ */
