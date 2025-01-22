/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** main.cpp
*/

#include "../common/map/MapGenerating.hpp"
#include <iostream>
#include "../common/ECS/EntityManager.hpp"
#include "../common/ECS/System/PlayerSystem/PlayerSystem.hpp"
#include "./Game/Game.hpp"
#include "../common/OstreamHelper.hpp"
#include "../common/ECS/System/MovableSystem/MovableSystem.hpp"
#include "ECS/System/NetworkSystem/NetworkSystem.hpp"
#include "ECS/System/ScaleSystem/ScaleSystem.hpp"
#include "ECS/System/ClickableSystem/ClickableSystem.hpp"
#include "ECS/System/EnemySystem/EnemySystem.hpp"
#include <ECS/Components/Network/NetworkComponent.hpp>
#include <ECS/System/HitboxSystem/HitboxSystem.hpp>
#include <ECS/System/AugmentSystem/AugmentSystem.hpp>
#include <ECS/System/ProjectileSystem/ProjectileSystem.hpp>

#include "ECS/System/TextSystem/TextSystem.hpp"
#include "ECS/System/InputSystem/InputSystem.hpp"
#include <cstdlib>
#include <cmath>
#include <ctime>

static const std::map<std::string, std::vector<std::string>> collapse = {
    {"map1", {"map9", "map7", "map3"}},
    {"map2", {"map1", "map3", "map8"}},
    {"map3", {"map10", "map5", "map6"}},
    {"map4", {"map7", "map1", "map2"}},
    {"map5", {"map10", "map3", "map7"}},
    {"map6", {"map5", "map9", "map2"}},
    {"map7", {"map4", "map8", "map5"}},
    {"map8", {"map7", "map4", "map9"}},
    {"map9", {"map8", "map6", "map10"}},
    {"map10", {"map1", "map2", "map3"}}
};

std::vector<std::string> collapseFunctionMaps(
    std::map<std::string, std::vector<std::string>> maps, const int nbPattern,
    std::string startMap
)
{
    std::vector<std::string> mapResult;
    srand(time(NULL));

    for (int i = 0; i < nbPattern; i++) {
        mapResult.push_back(startMap);
        if (maps[startMap].empty())
            break;
        std::vector<std::string> possibleNextPattern = maps[startMap];
        startMap = possibleNextPattern[rand() % possibleNextPattern.size()];
    }
    return mapResult;
}

int main(int ac, char **av)
{
    rtype::SpriteLoader::loadAllTextures();
    rtype::SoundLoader::loadAllSounds();
    rtype::SoundLoader::playSound(MUSIC);
    EntityManager manager;
    Game game = Game(WIDTH, HEIGHT, manager);
    std::shared_ptr<std::vector<sf::Event>>
        events = std::make_shared<std::vector<sf::Event>>();

    PlayerSystem pl = PlayerSystem();
    MovableSystem mv = MovableSystem();
    ScaleSystem sc = ScaleSystem();
    ClickableSystem cl = ClickableSystem();
    EnemySystem en = EnemySystem();
    HitboxSystem hb = HitboxSystem();
    AugmentSystem ag = AugmentSystem();
    ProjectileSystem pr = ProjectileSystem();
    TextSystem ts = TextSystem();
    InputSystem is = InputSystem();

    std::vector<std::string> patterns;
    if (ac == 1) {
        patterns = collapseFunctionMaps(collapse, 10, "map1");
    } else {
        patterns = {std::string(av[1])};
    }
    std::vector<MapGenerating> maps;
    MapGenerating map;
    maps.reserve(patterns.size());
    for (auto &x: patterns) {
        maps.emplace_back(x + ".txt");
    }
    int currentMap = 0;
    sf::Clock gameTime;
    pl.setInputs(events);
    cl.setInputs(events);
    en.setInputs(events);
    is.setInputs(events);

    pl.setEntities(manager.getEntity());
    cl.setEntities(manager.getEntity());
    mv.setEntities(manager.getEntity());
    sc.setEntities(manager.getEntity());
    en.setEntities(manager.getEntity());
    hb.setEntities(manager.getEntity());
    ag.setEntities(manager.getEntity());
    pr.setEntities(manager.getEntity());
    ts.setEntities(manager.getEntity());
    is.setEntities(manager.getEntity());

    game.createDebug();
    game.createMenu();
    game.createMultiSettings();

    while (game.isRunning()) {
        // events
        sf::Event &event = game.getEvent();
        events->clear();
        while (game.pollEvent()) {
            if (event.type == sf::Event::Closed ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                std::cout << "Closing window" << std::endl;
                game.close();
                break;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3)) {
                game.setDebugMode(!game.getDebugMode());
                continue;
            }
            events->push_back(event);
        }

        // map
        if (game.getState() == State::GAMESOLO || game.getState() == State::GAMEMULTI) {
            sf::Time gameStartTime = gameTime.getElapsedTime();
            maps[currentMap].displayMap(gameStartTime.asSeconds(), manager,
                events);
            if (maps[currentMap].getToDisplay() >=
                maps[currentMap].getEnemies().size()) {
                // maps[currentMap].setToDisplay(0);
                currentMap++;
                if (currentMap >= maps.size())
                    currentMap = 0;
            }
        } else {
            gameTime.restart();
        }

        // update
        sc.update();
        mv.update();
        pl.update();
        cl.update();
        en.update();
        hb.update();
        ag.update();
        pr.update();
        ts.update();
        is.update();

        // draw
        game.draw();
    }
}
