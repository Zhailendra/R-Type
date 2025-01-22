/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** BulletComponent.hpp
*/

#ifndef BULLETCOMPONENT_HPP
#define BULLETCOMPONENT_HPP

#include "../AComponent.hpp"

class BulletComponent : public AComponent {
public:
    using TYPE = enum : std::uint16_t {
        PLAYER = 0,
        ENEMY = 1
    };

    BulletComponent()
    {
        _type = Components::BULLET;
    };
    ~BulletComponent() = default;
    BulletComponent(TYPE type) : _typeBullet(type)
    {
        _type = Components::BULLET;
    };

    friend std::ostream &operator<<(std::ostream &os, const BulletComponent &BulletComponent);


    TYPE _typeBullet;
};

#endif //BULLETCOMPONENT_HPP
