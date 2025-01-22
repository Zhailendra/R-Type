/*
** EPITECH PROJECT, 2024
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Health
*/

#ifndef HEALTH_HPP_
#define HEALTH_HPP_

#include "../AComponent.hpp"

class Health : public AComponent {
    public:
        Health() { _type = Components::HEALTH; };
        Health(int hp);
        ~Health();

        int _hp = 0;
    protected:
    private:
};

#endif /* !HEALTH_HPP_ */
