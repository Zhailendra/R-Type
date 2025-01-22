/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Rectable.cpp
*/

#include "Rectable.hpp"

Rectable::Rectable(int frameNumber, int nbFrames) {
    _type = Components::RECTABLE;
    _currentPlayerFrame = frameNumber;
    _nbFrames = nbFrames;
}

std::ostream &operator<<(std::ostream &os, const Rectable &rectable) {
    os << "Rectable{" << "keyHoldClock: " << rectable._keyHoldClock.getElapsedTime().asMilliseconds()
       << ", upKeyPressed: " << rectable._upKeyPressed
       << ", downKeyPressed: " << rectable._downKeyPressed
       << ", currentPlayerFrame: " << rectable._currentPlayerFrame
       << ", nbFrames: " << rectable._nbFrames
       << '}';
    return os;
}

Rectable::Rectable(int frameNumber, int nbFrames, int nbFramesHeight)
{
    _type = Components::RECTABLE;
    _currentPlayerFrame = frameNumber;
    _nbFrames = nbFrames;
    _nbFramesHeight = nbFramesHeight;
}
