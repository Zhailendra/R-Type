/*
** EPITECH PROJECT, 2024
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** CreationMap
*/

#ifndef CREATIONMAP_HPP_
#define CREATIONMAP_HPP_

#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "../../Utils/Path.hpp"

typedef struct sprite_s {
    std::shared_ptr<sf::Sprite> sprite;
    std::shared_ptr<sf::Texture> texture;
} sprite_t;

class CreationMap {
    public:
        CreationMap(int width, int height, std::string filename);
        ~CreationMap();
        bool isRunning();

        void initSprites();
        sprite_t loadSprite(std::string path, float scale, sf::Vector2f pos = sf::Vector2f(0, 0));
        int writeMap(int enemy, float dtSeconds, float x, float y);
        bool mapEvent();
        void mapClose();
        void mapDraw();

        void mouseClicked();
        void scrollScreen();

        void mapDisplay();
        sf::Event mapGetEvent();

    protected:
    private:
        sf::RenderWindow _window;
        std::string _filename;
        sf::Event _event;
        std::vector<sprite_t> _enemyList;
        bool _mouseClicked = false;
        bool _select = false;
        sprite_t _mouseSprite;
        std::vector<sf::Sprite> _allEnemies;
        std::vector<sprite_t> _backgrounds;

        int enemy = 1;
};

#endif /* !CREATIONMAP_HPP_ */
