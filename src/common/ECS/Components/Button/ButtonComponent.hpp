/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** ButtonComponent.hpp
*/

#ifndef BUTTONCOMPONENT_HPP
#define BUTTONCOMPONENT_HPP

#include <ECS/Components/AComponent.hpp>
#include <SFML/Graphics.hpp>
#include <functional>

class ButtonComponent : public AComponent {
public:
    ButtonComponent() { _type = Components::BUTTON; };
    ButtonComponent(sf::Vector2f size, sf::Color color);
    ~ButtonComponent() = default;

    void click(std::function<void()> callback);

    sf::Vector2f _size;
    sf::Color _color;

    sf::RectangleShape _rect;

    std::function<void()> _callback = nullptr;
};

#endif //BUTTONCOMPONENT_HPP
