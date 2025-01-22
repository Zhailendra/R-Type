/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** main.cpp
*/

#include <ECS/EntityManager.hpp>
#include <Network/Server.hpp>
#include <thread>
#include "Controller/Controllers.hpp"
#include "ECS/System/MovableSystem/MovableSystem.hpp"
#include "ECS/System/EnemySystem/EnemySystem.hpp"
#include "map/MapGenerating.hpp"

int main(int ac, char **av)
{
    if (ac != 3) {
        std::cerr << "Usage: ./rtype_server [port] [map]" << std::endl;
        return 84;
    }
    try {
        std::ifstream file("./maps/" + std::string(av[2]));
        if (!file.is_open()) {
            std::cerr << "ERROR : Can't open file." << std::endl;
            return 84;
        }
        file.close();
    } catch (std::exception &e) {
        std::cerr << "ERROR : Can't open file." << std::endl;
        return 84;
    }
    MapGenerating map = MapGenerating(av[2]);
    EntityManager manager = EntityManager();
    sf::Clock gameTime;
    bool newEntity = true;
    try {
        auto server = Network::Server<EntityManager &>(std::atoi(av[1]), manager);
        EnemySystem es = EnemySystem();
        es.setEntities(manager.getEntity());
        for (auto &controller : Controllers::getHandlers()) {
            server.use(controller.first, controller.second);
        }
        sf::IpAddress ip("127.0.0.1");
        while (true) {
            while(server.run());
        }
    } catch (Network::Error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}