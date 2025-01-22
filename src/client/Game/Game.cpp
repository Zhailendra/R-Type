/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** Game
*/

#include "Game.hpp"

#include "ECS/Components/Position/PositionComponent.hpp"
#include "ECS/Components/Text/TextComponent.hpp"
#include "ECS/Components/Button/ButtonComponent.hpp"
#include "ECS/Components/Input/InputComponent.hpp"
#include "ECS/Components/Enemy/EnemyComponent.hpp"

Game::Game(int width, int height, EntityManager &entityManager) : _window(sf::VideoMode(width, height), "R-Type", sf::Style::Titlebar | sf::Style::Close),
                                    _animations() , _parallax(), _vectorContainer(), _entityManager(entityManager), _state(MENU)
{
    _window.setFramerateLimit(60);
    nw = NetworkSystem();
    nw.setEntities(entityManager.getEntity());
}

Game::~Game()
{
}

bool Game::isRunning()
{
    if (int((_fpsClock.getElapsedTime().asSeconds() * 100) / 10) % 3 == 0) {
        _end_point_fps = std::chrono::high_resolution_clock::now();
        _fps = std::round((float) 1e9 /
            (float) std::chrono::duration_cast<std::chrono::nanoseconds>(
                _end_point_fps - _start_point_fps).count());
        _fpsEntity->getComponent<TextComponent>()._textString =
            "fps: " + std::to_string(int(_fps));
        _EntityCounter->getComponent<TextComponent>()._textString =
            "Entities: " + std::to_string(_entityManager.getSize());
    }
    if (int((_fpsClock.getElapsedTime().asSeconds() * 100) / 10) % 3 == 0) {
        _start_point_fps = std::chrono::high_resolution_clock::now();
    }
    return _window.isOpen();
}

void Game::drawHitbox(std::shared_ptr<Entity> entity)
{
    if (!entity.get()->hasComponent<Renderable>())
        return;
    Renderable &renderable = entity.get()->getComponent<Renderable>();
    sf::RectangleShape border;
    if (entity->hasComponent<Rectable>()) {
        Rectable &rectable = entity.get()->getComponent<Rectable>();
        border = sf::RectangleShape(sf::Vector2f(renderable._sprite.getGlobalBounds().width / rectable._nbFrames, renderable._sprite.getGlobalBounds().height / rectable._nbFramesHeight));
    } else {
        border = sf::RectangleShape(sf::Vector2f(renderable._sprite.getGlobalBounds().width, renderable._sprite.getGlobalBounds().height));
    }
    border.setPosition(renderable._sprite.getPosition());
    border.setOutlineThickness(2); // Set the thickness of the border
    border.setOutlineColor(sf::Color::Red);
    border.setFillColor(sf::Color::Transparent);
    _window.draw(border);
}

void Game::draw()
{

    _window.clear();
    // parallax
    updateParallax(getDeltaTime());
    for (const auto& entity : *_entityManager.getEntity()) {
        if (_state != MENU && std::find(_MenuEntities.begin(), _MenuEntities.end(), entity) != _MenuEntities.end())
            continue;
        if (_state != SETTINGS && std::find(_SettingsEntities.begin(), _SettingsEntities.end(), entity) != _SettingsEntities.end())
            continue;
        if (_state != GAMEMULTISETTINGS && std::find(_GameMultiSettingsEntities.begin(), _GameMultiSettingsEntities.end(), entity) != _GameMultiSettingsEntities.end())
            continue;
        if (entity->hasComponent<ButtonComponent>()) {
            auto &button = entity->getComponent<ButtonComponent>();
            _window.draw(button._rect);
        }
        if (entity->hasComponent<InputComponent>()) {
            auto &input = entity->getComponent<InputComponent>();
            _window.draw(input._rect);
        }
        if (entity->hasComponent<TextComponent>()) {
            auto &text = entity->getComponent<TextComponent>();
            if (text._debugMode) {
                if (debugMode)
                    _window.draw(entity->getComponent<TextComponent>()._text);
                continue;
            }
            _window.draw(entity->getComponent<TextComponent>()._text);
        }
        if (entity->hasComponent<Renderable>()) {
            sf::Sprite displayableSprite;
            if (entity->hasComponent<Rectable>()) {
                if (entity->hasComponent<EnemyComponent>()) {
                    if (entity->getComponent<EnemyComponent>()._isBoss) {
                        displayableSprite = _animations.updateSpriteAnimationV2(entity->getComponent<Renderable>()._sprite,
                                                                                getClock(),
                                                                                entity->getComponent<Rectable>()._currentPlayerFrame,
                                                                                entity->getComponent<Rectable>()._nbFrames,
                                                                                entity->getComponent<Rectable>()._nbFramesHeight,
                                                                                entity->getComponent<Rectable>()._switchTop,
                                                                                entity->getComponent<Rectable>()._frameHeightMultiplier);
                    } else {
                        displayableSprite = _animations.updateSpriteAnimation(entity->getComponent<Renderable>()._sprite,
                                                                              getClock(),
                                                                              entity->getComponent<Rectable>()._currentPlayerFrame,
                                                                              entity->getComponent<Rectable>()._nbFrames);
                    }
                } else {
                    displayableSprite = _animations.updateSpriteAnimation(entity->getComponent<Renderable>()._sprite,
                                                                          getClock(),
                                                                          entity->getComponent<Rectable>()._currentPlayerFrame,
                                                                          entity->getComponent<Rectable>()._nbFrames);
                }
                entity->getComponent<Rectable>()._frameSizeWidth = displayableSprite.getGlobalBounds().width;
                entity->getComponent<Rectable>()._frameSizeHeight = displayableSprite.getGlobalBounds().height / entity->getComponent<Rectable>()._nbFramesHeight;
            } else {
                displayableSprite = entity->getComponent<Renderable>()._sprite;
            }
            _window.draw(displayableSprite);
            if (debugMode)
                drawHitbox(entity);
        }
    }
    _window.display();
    try {
        nw.update();
        if (_state == GAMEMULTISETTINGS && _networkEntity != nullptr) {
            _state = GAMEMULTI;
            _entityManager.createPlayer();
        }
    } catch (const std::exception &e) {
        EntityManager::destroyEntity(_entityManager.getEntity(), _networkEntity->getId());
        _networkEntity = nullptr;
        _state = GAMEMULTISETTINGS;
        this->_error_ip = e.what();
    }
    _GameMultiSettingsEntities[2]->getComponent<TextComponent>()._textString = _error_ip;
}

void Game::createMenu()
{
    std::shared_ptr<Entity> solo_button =
        EntityManager::createButton(WIDTH/ 2,  HEIGHT / 3, sf::Vector2f(500, 100), "SOLO",
            30, sf::Color::Black, sf::Color::White,
            [this]() {
                if (this->_state == MENU) {
                    this->_state = GAMESOLO;
                    this->_entityManager.createPlayer();
                }
            });
    std::shared_ptr<Entity> multi_button =
        EntityManager::createButton(WIDTH/ 2,  HEIGHT / 3 + HEIGHT / 3, sf::Vector2f(500, 100), "MULTIPLAYER",
            30, sf::Color::Black, sf::Color::White,
            [this]() {
                if (this->_state == MENU) {
                    this->_state = GAMEMULTISETTINGS;
                }
            });
//    std::shared_ptr<Entity> settings_button =
//        EntityManager::createButton(WIDTH/ 2,  HEIGHT / 3 + HEIGHT / 3 + HEIGHT / 3, sf::Vector2f(500, 100), "SETTINGS",
//            30, sf::Color::Black, sf::Color::White,
//            [this]() {
//                if (this->_state == MENU) {
//                    this->_state = SETTINGS;
//                }
//            });
    _MenuEntities.push_back(solo_button);
    _MenuEntities.push_back(multi_button);
//    _MenuEntities.push_back(settings_button);
    _entityManager.getEntity()->push_back(solo_button);
    _entityManager.getEntity()->push_back(multi_button);
//    _entityManager.getEntity()->push_back(settings_button);
}

void Game::createMultiSettings()
{
    std::shared_ptr<Entity> ip_input =
        EntityManager::createInput(WIDTH/ 2,  HEIGHT / 3, sf::Vector2f(500, 100), "",
            30, sf::Color::Black, sf::Color::White,
            [this](const std::string& ip) {
                if (this->_state == GAMEMULTISETTINGS) {
                    this->_ip = ip;
                }
            });
    std::shared_ptr<Entity> error_text =
        EntityManager::createText(WIDTH/ 2 - 250,  HEIGHT / 3 + (HEIGHT / 3) / 2, "", 30, false);
    std::shared_ptr<Entity> validation_button =
        EntityManager::createButton(WIDTH/ 2,  HEIGHT / 3 + HEIGHT / 3, sf::Vector2f(500, 100), "CONNECT",
            30, sf::Color::Black, sf::Color::White,
            [this]() {
                if (this->_state == GAMEMULTISETTINGS) {
                    if (this->_ip.find(":") == std::string::npos) {
                        this->_error_ip = "Invalid ip";
                        return;
                    }
                    this->_networkEntity = _entityManager.createEntity();
                    std::string ip = this->_ip.substr(0, this->_ip.find(":"));
                    std::string port = this->_ip.substr(this->_ip.find(":") + 1,
                        this->_ip.size());
                    try {
                        this->_networkEntity->addComponent<NetworkComponent>(
                            NetworkComponent(ip, std::stoi(port)));
                    } catch (const std::exception &e) {
                        this->_error_ip = "Invalid ip";
                        EntityManager::destroyEntity(_entityManager.getEntity(), this->_networkEntity->getId());
                        this->_networkEntity = nullptr;
                        return;
                    }
                }
            });
    _GameMultiSettingsEntities.push_back(ip_input);
    _GameMultiSettingsEntities.push_back(validation_button);
    _GameMultiSettingsEntities.push_back(error_text);
    _entityManager.getEntity()->push_back(ip_input);
    _entityManager.getEntity()->push_back(validation_button);
    _entityManager.getEntity()->push_back(error_text);
}


void Game::createDebug()
{
    _fpsEntity = EntityManager::createText(1160, 20, "", 20, true);
    _EntityCounter = EntityManager::createText(1160, 50, "", 20, true);
    _entityManager.getEntity()->push_back(_fpsEntity);
    _entityManager.getEntity()->push_back(_EntityCounter);
}

sf::RenderWindow &Game::getWindow()
{
    return _window;
}

sf::Event &Game::getEvent()
{
    return _event;
}

rtype::ParallaxAnimation &Game::getParallax()
{
    return _parallax;
}

sf::Clock &Game::getClock()
{
    return _clock;
}

float Game::getDeltaTime()
{
    return _clock.restart().asSeconds();
}

void Game::updateParallax(float deltaTime)
{
    _vectorContainer.displayBackgrounds(_window, deltaTime);
}

void Game::drawParallax(sf::Sprite& sprite)
{
    _window.draw(sprite);
}

State Game::getState() const
{
    return _state;
}