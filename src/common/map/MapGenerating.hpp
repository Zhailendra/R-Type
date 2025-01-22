/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** MapGenerating
*/

#ifndef MAPGENERATING_HPP_
#define MAPGENERATING_HPP_

#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>

#include "../ECS/System/EnemySystem/EnemySystem.hpp"
#include "../ECS/EntityManager.hpp"
#include "../ECS/Components/Position/PositionComponent.hpp"
#include "../ECS/Components/Renderable/Renderable.hpp"
#include "../ECS/Components/Velocity/Velocity.hpp"
#include "../ECS/Components/Rectable/Rectable.hpp"
#include "../ECS/System/PlayerSystem/PlayerSystem.hpp"
#include "../ECS/System/EnemySystem/EnemySystem.hpp"
#include "../../client/Game/Game.hpp"
#include "../OstreamHelper.hpp"
#include "../ECS/System/MovableSystem/MovableSystem.hpp"
#include "../ECS/EntityManager.hpp"

class MapGenerating {
    public:
        MapGenerating();
        MapGenerating(std::string map);
        ~MapGenerating();

        std::vector<std::vector<std::string>> getEnemies() { return _enemies ; };
        size_t getToDisplay() { return _toDisplay; };

        void readmap(std::string map);
        void displayMap(float dtSeconds, EntityManager manager, std::shared_ptr<std::vector<sf::Event>> events);
        void initMap();
        void setToDisplay(size_t toDisplay) { _toDisplay = toDisplay; };


        static bool sortTiming(const std::vector<std::string>& a, const std::vector<std::string>& b) { return atoi(a[1].c_str()) < atoi(b[1].c_str()); };
    
    protected:
    private:
        float _enemyOffsetX{};
        std::vector<std::string> _map;
        std::vector<std::vector<std::string>> _enemies;

        // A supprimer c'est pour les tests
        size_t _toDisplay = 0;
};

#endif /* !MAPGENERATING_HPP_ */
