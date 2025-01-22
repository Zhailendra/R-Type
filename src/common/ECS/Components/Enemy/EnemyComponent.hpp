/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** EnemyComponent
*/

#ifndef ENEMYCOMPONENT_HPP_
#define ENEMYCOMPONENT_HPP_

#include "../AComponent.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class EnemyComponent : public AComponent {
    public:
        EnemyComponent();
        EnemyComponent(int enemyType);
        ~EnemyComponent();

        int _enemyType;
        sf::Clock _clockEnemy;
        bool _isBoss = false;

    protected:
    private:
};

#endif /* !ENEMYCOMPONENT_HPP_ */
