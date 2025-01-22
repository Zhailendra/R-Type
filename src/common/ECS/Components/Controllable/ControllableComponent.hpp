/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** ControllableComponent
*/

#ifndef CONTROLLABLECOMPONENT_HPP_
#define CONTROLLABLECOMPONENT_HPP_

#include "../AComponent.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>

class ControllableComponent : public AComponent {
    public:
        ControllableComponent(sf::Keyboard::Key up, sf::Keyboard::Key down, 
                              sf::Keyboard::Key left, sf::Keyboard::Key right, 
                              sf::Keyboard::Key shoot, sf::Keyboard::Key laser);
        ControllableComponent() {_type = Components::CONTROLLABLE;}
        ~ControllableComponent();


        sf::Keyboard::Key up;
        sf::Keyboard::Key down;
        sf::Keyboard::Key left;
        sf::Keyboard::Key right;
        sf::Keyboard::Key shoot;
        sf::Keyboard::Key laser;
        int shootDelay = 0;
        bool isLoadingLaser = false;
        bool isLoadedLaser = false;
        sf::Clock laserClock;

    protected:
    private:
};

#endif /* !CONTROLLABLECOMPONENT_HPP_ */
