/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** MapGenerating
*/

#include "MapGenerating.hpp"

MapGenerating::MapGenerating()
{
}

MapGenerating::MapGenerating(std::string map)
{
    readmap(map);
    initMap();
}

MapGenerating::~MapGenerating()
{
}

void MapGenerating::readmap(std::string map)
{
    std::ifstream file("./maps/" + map);
    std::regex pattern(R"(\d+\s\d+\.\d+\s\d+\s\d+)");

    if (file.is_open()) {
        std::string line;

        while (getline(file, line)) {
            if (line[0] == '#' || line[0] == '\n' || line.length() <= 0)
                continue;
            if (!std::regex_match(line, pattern)) {
                std::cout << "ERROR : Invalid syntax  (line : " << line << ")" << std::endl;
                continue;
            }
            _map.push_back(line);
        }
        file.close();
    } else
        std::cerr << "ERROR : Can't open file." << std::endl;
}

void MapGenerating::initMap()
{
    sf::RectangleShape rec(sf::Vector2f(100.0f, 100.0f));

    for (size_t i = 0; i < _map.size(); i++) {
        std::vector<std::string> enemy(4);
        if (i < _map.size() && !(_map[i].empty())) {
            std::istringstream iss(_map[i]);
            iss >> enemy[0] >> enemy[1] >> enemy[2] >> enemy[3];
            _enemies.push_back(enemy);
        } else {
            std::cerr << "ERROR : Invalid enemy  (line : " << i + 1 << ")" << std::endl;
        }
    }

    std::sort(_enemies.begin(), _enemies.end(), sortTiming);
}

void MapGenerating::displayMap(float dtSeconds, EntityManager manager, std::shared_ptr<std::vector<sf::Event>> events)
{
    while (_toDisplay < _enemies.size() && std::abs(dtSeconds - atoi(_enemies[_toDisplay][1].c_str())) < 0.1) {
        if (atoi(_enemies[_toDisplay][0].c_str()) >= 8 && atoi(_enemies[_toDisplay][0].c_str()) <= 18) {
            manager.getEntity()->push_back(manager.createBlock(atoi(_enemies[_toDisplay][2].c_str()), atoi(_enemies[_toDisplay][3].c_str()), atoi(_enemies[_toDisplay][0].c_str())));
        }
        else
           manager.createEnemy(atoi(_enemies[_toDisplay][2].c_str()), atoi(_enemies[_toDisplay][3].c_str()), atoi(_enemies[_toDisplay][0].c_str()));
        _toDisplay++;
    }
}
