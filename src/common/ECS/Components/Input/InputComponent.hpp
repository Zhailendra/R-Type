/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** InputComponent.hpp
*/

#ifndef INPUTCOMPONENT_HPP
#define INPUTCOMPONENT_HPP

#include <ECS/Components/AComponent.hpp>
#include <SFML/Graphics.hpp>
#include <functional>

class InputComponent : public AComponent {
public:
    InputComponent() { _type = Components::INPUT; };
    InputComponent(sf::Vector2f size, sf::Color color);
    ~InputComponent() = default;


    void input(std::function<void(std::string)> callback);

    sf::Vector2f _size;
    sf::Color _color;

    sf::RectangleShape _rect;

    bool _isFocused = false;
    int _cursorShow = 0;
    int _cursorPos = 0;

    std::function<void(std::string)> _callback = nullptr;

};
#endif //INPUTCOMPONENT_HPP
