/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include "../MapGenerating.hpp"
#include <fstream>
#include <sstream>
#include <iostream> 

typedef struct mapGenerating_s {
    std::vector<sf::RectangleShape> recEnemies;
    std::vector<std::vector<std::string>> realEnemies;
    size_t to_display = 0;
} mapGenerating_t;

void displayEnemies(sf::RenderWindow &window, float dtSeconds, std::shared_ptr<mapGenerating_t> map);

int setEnemies(std::shared_ptr<mapGenerating_t> map);

#endif /* !MY_H_ */
