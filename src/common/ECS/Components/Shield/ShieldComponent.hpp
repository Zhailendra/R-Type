/*
** EPITECH PROJECT, 2024
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** ShieldComponent
*/

#ifndef SHIELDCOMPONENT_HPP_
#define SHIELDCOMPONENT_HPP_

#include <ECS/Components/AComponent.hpp>

class ShieldComponent : public AComponent {
    public:
        ShieldComponent(int shieldHp) { _type = Components::SHIELD; _shieldHp = shieldHp;};
        ShieldComponent();
        ~ShieldComponent();

        int _shieldHp;
    protected:
    private:
};

#endif /* !SHIELDCOMPONENT_HPP_ */
