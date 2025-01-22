/*
** EPITECH PROJECT, 2024
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** LaserComponent.hpp
*/

#ifndef B_CPP_500_LIL_5_2_RTYPE_YACINE_OURTANANE_LASERCOMPONENT_HPP
#define B_CPP_500_LIL_5_2_RTYPE_YACINE_OURTANANE_LASERCOMPONENT_HPP

#include <ECS/Components/AComponent.hpp>

class LaserComponent : public AComponent {
    public:
        LaserComponent() { _type = Components::LASER; };
        ~LaserComponent() = default;

    protected:
    private:
};

#endif