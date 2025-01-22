/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
#include "../../common/ECS/Entity.hpp"
#include "../../common/ECS/Components/Renderable/Renderable.hpp"
#include "../../common/ECS/Components/Rectable/Rectable.hpp"
#include "../../common/ECS/Components/Bullet/BulletComponent.hpp"
#include "../../common/ECS/Components/Controllable/ControllableComponent.hpp"
#include "../../common/Utils/SpriteLoader.hpp"
#include "../../common/Utils/SoundLoader.hpp"
#include "../loader/VectorContainer.hpp"
#include "../loader/animations/ParallaxAnimation.hpp"
#include "../loader/animations/ASpritesAnimations.hpp"
#include "../../common/ECS/EntityManager.hpp"
#include "../../common/ECS/System/NetworkSystem/NetworkSystem.hpp"

enum State {
    MENU,
    SETTINGS,
    GAMEMULTISETTINGS,
    GAMEMULTI,
    GAMESOLO,
};

class Game {
    public:
        Game(int width, int height, EntityManager &entityManager);
        ~Game();

        bool isRunning();
        bool pollEvent() { return _window.pollEvent(_event); }
        void close() { _window.close(); exit(0);}
        void draw();

        void drawParallax(sf::Sprite& sprite);
        sf::RenderWindow &getWindow();
        sf::Event &getEvent();
        rtype::ParallaxAnimation &getParallax();
        sf::Clock &getClock();
        void drawHitbox(std::shared_ptr<Entity> entity);

        float getDeltaTime();
        void updateParallax(float deltaTime);

        void setDebugMode(bool mode) { debugMode = mode; }
        bool &getDebugMode() { return debugMode; }
        State getState() const;

        void createMenu();
        void createDebug();
        void createMultiSettings();
    protected:
    private:
        sf::RenderWindow _window;
        sf::Event _event;
        rtype::ASpritesAnimations _animations;
        rtype::ParallaxAnimation _parallax;
        rtype::VectorContainer _vectorContainer;
        sf::Clock _clock;
        bool debugMode = false;
        EntityManager &_entityManager;
        State _state;
        std::vector<std::shared_ptr<Entity>> _MenuEntities;
        std::vector<std::shared_ptr<Entity>> _SettingsEntities;
        std::vector<std::shared_ptr<Entity>> _GameMultiSettingsEntities;

        std::chrono::high_resolution_clock::time_point _start_point_fps;
        std::chrono::high_resolution_clock::time_point _end_point_fps;
        sf::Clock _fpsClock;
        float _fps;

        std::shared_ptr<Entity> _fpsEntity;
        std::shared_ptr<Entity> _EntityCounter;

        std::string _ip;
        std::string _error_ip;

        NetworkSystem nw;

        std::shared_ptr<Entity> _networkEntity;

};

#endif /* !GAME_HPP_ */
