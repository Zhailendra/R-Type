/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** displayEnemies
*/

#include "../MapGenerating.hpp"
#include "./my.h"

int setEnemies(std::shared_ptr<mapGenerating_t> map)
{
    MapGenerating mapping("map1.txt");
    size_t nbEnemies = mapping.getEnemies().size();
    map->realEnemies = mapping.getEnemies();

    std::vector<sf::Color> colors {sf::Color::Blue, sf::Color::Yellow, sf::Color::Red, sf::Color::Green};
    sf::RectangleShape rec(sf::Vector2f(100.0f, 100.0f));

    for (size_t i = 0; i < nbEnemies; i++) {
        map->recEnemies.push_back(sf::RectangleShape(rec));
        map->recEnemies[i].setPosition(atoi(map->realEnemies[i][2].c_str()), atoi(map->realEnemies[i][3].c_str()));
        map->recEnemies[i].setFillColor(colors[atoi(map->realEnemies[i][0].c_str())]);
    }

    return 0;
}

void displayEnemies(sf::RenderWindow &window, float dtSeconds, std::shared_ptr<mapGenerating_t> map)
{
    if (map->to_display < map->realEnemies.size() && std::abs(dtSeconds - atoi(map->realEnemies[map->to_display][1].c_str())) < 0.1)
        map->to_display++;

    for (size_t i = 0; i < map->to_display; ++i)
        window.draw(map->recEnemies[i]);
}
