/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Types
*/

#ifndef TYPES_HPP_
#define TYPES_HPP_
#include <map>

static const int WIDTH = 1280;
static const int HEIGHT = 720;

// if you want to add a component, add it to the enum and increment COMPONENTS_SIZE
enum Components {
    POSITION = 0,
    RENDERABLE = 1,
    VELOCITY = 2,
    NETWORK = 3,
    PLAYER = 4,
    SEND_OVER_NETWORK = 5,
    CONTROLLABLE = 6,
    RECTABLE = 7,
    SCALE = 8,
    BUTTON = 9,
    ENEMY = 10,
    BULLET = 11,
    HEALTH = 12,
    AUGMENTS = 13,
    SHIELD = 14,
    LASER = 15,
    LASER_LOADING = 16,
    TEXT = 17,
    INPUT = 18,
    ITEMCOMP = 19,
    BOOM = 20,
};
#define COMPONENTS_SIZE 21

#endif /* !TYPES_HPP_ */
