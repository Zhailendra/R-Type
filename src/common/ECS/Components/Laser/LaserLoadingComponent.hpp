/*
** EPITECH PROJECT, 2024
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** LaserLoadingComponent.hpp
*/

#ifndef B_CPP_500_LIL_5_2_RTYPE_YACINE_OURTANANE_LASERLOADINGCOMPONENT_HPP
#define B_CPP_500_LIL_5_2_RTYPE_YACINE_OURTANANE_LASERLOADINGCOMPONENT_HPP

#include <ECS/Components/AComponent.hpp>

class LaserLoadingComponent : public AComponent {
    public:
        LaserLoadingComponent() { _type = Components::LASER_LOADING; };
        ~LaserLoadingComponent() = default;

    protected:
    private:
};

#endif