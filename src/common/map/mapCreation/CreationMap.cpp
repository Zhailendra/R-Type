/*
** EPITECH PROJECT, 2024
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** CreationMap
*/

#include "CreationMap.hpp"

CreationMap::CreationMap(int width, int height, std::string filename) :  _window(sf::VideoMode(width, height), "R-Type", sf::Style::Titlebar | sf::Style::Close), _filename(filename)
{
};

CreationMap::~CreationMap()
{
}

bool CreationMap::isRunning()
{
    return _window.isOpen();
}

bool CreationMap::mapEvent()
{
    return _window.pollEvent(_event);
}

void CreationMap::mapClose()
{
    _window.close();
}

void CreationMap::mapDisplay()
{
    _window.display();
}

void CreationMap::mapDraw()
{
    _window.clear(sf::Color::Black);

    for (auto &background : _backgrounds)
        _window.draw(*background.sprite);

    for (auto &enemy : _allEnemies) {
        _window.draw(enemy);
    }

    _window.draw(*_mouseSprite.sprite);

    for (auto &enemy : _enemyList) {
        _window.draw(*enemy.sprite);
    }
}

sf::Event CreationMap::mapGetEvent()
{
    return _event;
}

sprite_t CreationMap::loadSprite(std::string path, float scale, sf::Vector2f pos)
{
    sprite_t spriteTexture;

    spriteTexture.texture = std::make_shared<sf::Texture>();
    spriteTexture.sprite = std::make_shared<sf::Sprite>();

    if (!spriteTexture.texture->loadFromFile(path)) {
        std::cerr << "ERROR: Could not load texture " << path << std::endl;
        exit(84);
    }

    spriteTexture.sprite->setTexture(*spriteTexture.texture);
    spriteTexture.sprite->setScale(scale, scale);
    spriteTexture.sprite->setPosition(pos);

    return spriteTexture;
}

void CreationMap::initSprites()
{
    int x = 0;
    int y = 30;

    _mouseSprite = loadSprite("./src/common/map/enemiesSprites/enemy1.png", 2, _window.mapPixelToCoords(sf::Mouse::getPosition(_window)));

    for (int i = 1; i < 4; i++)
        _backgrounds.push_back(loadSprite("./assets/Backgrounds/Background0" + std::to_string(i) + ".png", 2));

    for (std::uint16_t i = 17, a = 1; i < 33; i++, a++, x += 90) {
        if (i == 25) {
            x = 0;
            y = 110;
        }
        _enemyList.push_back(loadSprite("./src/common/map/enemiesSprites/enemy" + std::to_string(a) + ".png", 1.5, sf::Vector2f(y, 20 + x)));
    }
}

void CreationMap::mouseClicked()
{
    sf::Vector2f mousePos = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !_mouseClicked) {
        sf::Vector2f mousePosition = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));

        size_t i = 0;
        for (; i < _enemyList.size(); i++) {
            if (_enemyList[i].sprite->getGlobalBounds().contains(mousePosition)) {
                _select = true;
                _mouseSprite.sprite->setTexture(*_enemyList[i].sprite->getTexture());
                _mouseSprite.sprite->setScale(2, 2);
                enemy = i + 1;
                break;
            }
        }
        if (!_select) {
            sf::Sprite newSprite;
            newSprite.setTexture(*_mouseSprite.sprite->getTexture());
            newSprite.setPosition(mousePosition.x - 40, mousePosition.y - 40);
            newSprite.setScale(2, 2);

            sf::Color color = newSprite.getColor();
            color.a = 128;
            newSprite.setColor(color);

            _allEnemies.push_back(newSprite);
            float pos = _backgrounds[0].sprite->getPosition().x - mousePosition.x;
            float time = (pos - pos - pos ) * 2 / 1000 + 1;

            writeMap(enemy, time * 2, mousePosition.x - 40, mousePosition.y - 40);
        }
        _mouseClicked = true;
        _select = false;
    }

    if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        _mouseClicked = false;

    _mouseSprite.sprite->setPosition(mousePos.x - 40, mousePos.y - 40);
}

int CreationMap::writeMap(int enemy, float dtSeconds, float x, float y)
{
    std::ofstream file(_filename, std::ios::app);

    if (file.is_open()) {
        file << enemy << " " << dtSeconds << " " << x << " " << y << "\n";
        file.close();
    } else
        std::cerr << "ERROR : Impossible d'ouvrir le fichier." << std::endl;

    return 0;
}

void CreationMap::scrollScreen()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        float speed = 0.5f;
        for (size_t i = 0; i < _backgrounds.size(); i++) {
            speed += 0.25f;
            sf::Vector2f pos = _backgrounds[i].sprite->getPosition();
            if (_backgrounds[2].sprite->getPosition().x < -4680)
                return;
            _backgrounds[i].sprite->setPosition(pos.x - speed, pos.y);
        }
        for (auto &enemy : _allEnemies) {
            sf::Vector2f pos = enemy.getPosition();
            enemy.setPosition(pos.x - speed, pos.y);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        float speed = 0.5f;
        for (auto &background : _backgrounds) {
            speed += 0.25f;
            sf::Vector2f pos = background.sprite->getPosition();
            if (pos.x == 0) {
                return;
            }

            background.sprite->setPosition(pos.x + speed, pos.y);
        }
        for (auto &enemy : _allEnemies) {
            sf::Vector2f pos = enemy.getPosition();
            enemy.setPosition(pos.x + speed, pos.y);
        }
    }
}
