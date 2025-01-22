/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Rectable.hpp
*/

#ifndef RECTABLE_HPP
#define RECTABLE_HPP

#include "../AComponent.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class Rectable : public AComponent {
    public:
        Rectable() { _type = Components::RECTABLE; };

        explicit Rectable(int frameNumber, int nbFrames);
        explicit Rectable(int frameNumber, int nbFrames, int nbFramesHeight);
        ~Rectable() override = default;

        friend std::ostream &operator<<(std::ostream &os, const Rectable &rectable);

        sf::Clock _keyHoldClock;
        sf::Clock _frameClock;
        bool _upKeyPressed = false;
        bool _downKeyPressed = false;
        bool _newFrame = false;
        bool _switchTop = false;
        int _frameNumber = 1;
        int _currentPlayerFrame = 0;
        int _nbFrames = 0;
        int _nbFramesHeight = 0;
        float _frameSizeWidth = 0;
        float _frameSizeHeight = 0;
        int _frameHeightMultiplier = 0;
};

#endif