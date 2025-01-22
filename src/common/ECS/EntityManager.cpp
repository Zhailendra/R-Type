/*
** EPITECH PROJECT, 2023
** rtype
** File description:
** Byte.hpp
*/

#include "EntityManager.hpp"

#include "Components/Health/Health.hpp"
#include "Components/Text/TextComponent.hpp"
#include "ECS/Components/SendOverNetwork/SendOverNetworkComponent.hpp"
#include "ECS/Components/Scale/ScaleComponent.hpp"
#include "ECS/Components/Enemy/EnemyComponent.hpp"
#include "ECS/Components/Bullet/BulletComponent.hpp"
#include "ECS/Components/Augments/Augments.hpp"
#include "ECS/Components/Shield/ShieldComponent.hpp"
#include "ECS/Components/Laser/LaserComponent.hpp"
#include "ECS/Components/Laser/LaserLoadingComponent.hpp"
#include "ECS/Components/Button/ButtonComponent.hpp"
#include "ECS/Components/Input/InputComponent.hpp"
#include "../Utils/Path.hpp"
#include "Components/Item/Item.hpp"

EntityManager::EntityManager()
{
    entities = std::make_shared<std::vector<std::shared_ptr<Entity>>>();
    std::random_device rd;
    gen = std::mt19937(rd());
    distribution = std::uniform_int_distribution<std::uint32_t>(0, std::numeric_limits<std::uint32_t>::max());
}

std::shared_ptr<Entity> EntityManager::createEntity() {
    std::uint32_t entity;
    std::shared_ptr<Entity> obj;

    if (!availableEntities.empty()) {
        entity = availableEntities.front();
        availableEntities.pop();
        obj = std::make_unique<Entity>(Entity(entity));
        entities->push_back(obj);
    } else {
        entity = static_cast<std::uint32_t>(distribution(gen));
        obj = std::make_unique<Entity>(Entity(entity));
        entities->push_back(obj);
    }

    return obj;
}

int EntityManager::getSize() const {
    return entities->size();
}

void EntityManager::destroyEntity(const std::shared_ptr<std::vector<std::shared_ptr<Entity>>>& entities, std::uint32_t entityToDestroy) {
    for (size_t i = 0; i < entities->size(); i++) {
        std::shared_ptr<Entity> &entity = (*entities)[i];
        if (entity->getId() == entityToDestroy) {
            entities->erase(entities->begin() + i);
            return;
        }
    }
}


std::shared_ptr<Entity> EntityManager::getEntity(std::uint32_t entity) const {
    for (auto &x : *entities) {
        if (x->getId() == entity)
            return x;
    }
    return nullptr;
}

std::shared_ptr<std::vector<std::shared_ptr<Entity>>> EntityManager::getEntity() const {
    return entities;
}

std::queue<std::uint32_t> EntityManager::getAvailableEntities() const {
    return availableEntities;
}

std::shared_ptr<Entity> EntityManager::createText(int x, int y, std::string message, int size, bool debug)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    auto distribution = std::uniform_int_distribution<std::uint32_t>(0, std::numeric_limits<std::uint32_t>::max());
    std::shared_ptr<Entity> text = std::make_shared<Entity>(Entity(distribution(gen)));

    text->addComponent(TextComponent(message, sf::Color::White, size, debug));
    text->addComponent<PositionComponent>(PositionComponent(x, y, -1));
    return text;
}

std::shared_ptr<Entity> EntityManager::createButton(int x, int y, sf::Vector2f size,
            std::string message, int sizeText, sf::Color TextColor, sf::Color BackgroundColor, std::function<void()> callback)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    auto distribution = std::uniform_int_distribution<std::uint32_t>(0, std::numeric_limits<std::uint32_t>::max());
    std::shared_ptr<Entity> button = std::make_shared<Entity>(Entity(distribution(gen)));

    button->addComponent<TextComponent>(TextComponent(message, TextColor, sizeText, false));
    button->addComponent<ButtonComponent>(ButtonComponent(size, BackgroundColor));
    button->addComponent<PositionComponent>(PositionComponent(x, y, -1));
    button->getComponent<ButtonComponent>().click(callback);
    return button;
}

std::shared_ptr<Entity> EntityManager::createInput(int x, int y, sf::Vector2f size,
    std::string message, int sizeText, sf::Color TextColor, sf::Color BackgroundColor, std::function<void(std::string)> callback)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    auto distribution = std::uniform_int_distribution<std::uint32_t>(0, std::numeric_limits<std::uint32_t>::max());
    std::shared_ptr<Entity> input = std::make_shared<Entity>(Entity(distribution(gen)));

    input->addComponent<TextComponent>(TextComponent(message, TextColor, sizeText, false));
    input->addComponent<InputComponent>(InputComponent(size, BackgroundColor));
    input->addComponent<PositionComponent>(PositionComponent(x, y, -1));
    input->getComponent<InputComponent>().input(callback);
    return input;
}

std::shared_ptr<Entity> EntityManager::createPlayer()
{
    std::shared_ptr<Entity> player = createEntity();

    player->addComponent<PositionComponent>(PositionComponent(100, 100, -1));
    player->addComponent<Augments>(Augments({false, false, false, false, false}));
    player->addComponent<Renderable>(Renderable(SpriteType::PLAYER_1));
    player->addComponent<Velocity>(Velocity(0, 0, 0));
    player->addComponent<Health>(Health(2));
    player->addComponent<Rectable>(Rectable(2, 5));
    player->addComponent<ScaleComponent>(ScaleComponent(3.5, 3.5));
    player->addComponent<SendOverNetworkComponent>(SendOverNetworkComponent());
    player->addComponent<ControllableComponent>(ControllableComponent(sf::Keyboard::Z,
    sf::Keyboard::S, sf::Keyboard::Q, sf::Keyboard::D, sf::Keyboard::Space, sf::Keyboard::E));
    auto &sprite = player->getComponent<Renderable>()._sprite;
    player->getComponent<PositionComponent>().registerPositionChangeCallback([&sprite] (float x, float y) {
        sprite.setPosition(x, y);
    });
    player->getComponent<PositionComponent>().setPos(100, 100);
    return player;
}

std::shared_ptr<Entity> EntityManager::createShield(int x, int y)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    auto distribution = std::uniform_int_distribution<std::uint32_t>(0, std::numeric_limits<std::uint32_t>::max());
    std::shared_ptr<Entity> shield = std::make_shared<Entity>(Entity(distribution(gen)));

    shield->addComponent<ShieldComponent>(ShieldComponent(3));
    shield->addComponent<Health>(Health(2));
    shield->addComponent<PositionComponent>(PositionComponent(x, y, -1));
    shield->addComponent<Renderable>(Renderable(SpriteType::SHIELD_SPRITE));
    shield->addComponent<Velocity>(Velocity(0, 0, 0));
    shield->addComponent<ScaleComponent>(ScaleComponent(2.5, 2.5));
    shield->addComponent<SendOverNetworkComponent>(SendOverNetworkComponent());
    auto &sprite = shield->getComponent<Renderable>()._sprite;
    shield->getComponent<PositionComponent>().registerPositionChangeCallback([&sprite] (float x, float y) {
        sprite.setPosition(x, y);
    });
    shield->getComponent<PositionComponent>().setPos(x, y);
    return shield;
}

std::shared_ptr<Entity> EntityManager::createBullet(int x, int y)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    auto distribution = std::uniform_int_distribution<std::uint32_t>(0, std::numeric_limits<std::uint32_t>::max());
    std::shared_ptr<Entity> bullet = std::make_shared<Entity>(Entity(distribution(gen)));
    bullet->addComponent<PositionComponent>(PositionComponent(x, y, -1));
    bullet->addComponent<Renderable>(Renderable(SpriteType::PLAYERS_PROJECTILE));
    bullet->addComponent<BulletComponent>(BulletComponent(BulletComponent::TYPE::PLAYER));
    bullet->addComponent<Velocity>(Velocity(12, 0, 0));
    bullet->addComponent<ScaleComponent>(ScaleComponent(2.5, 2.5));
    bullet->addComponent<SendOverNetworkComponent>(SendOverNetworkComponent());
    auto &sprite = bullet->getComponent<Renderable>()._sprite;
    bullet->getComponent<PositionComponent>().registerPositionChangeCallback([&sprite] (float x, float y) {
        sprite.setPosition(x, y);
    });
    bullet->getComponent<PositionComponent>().setPos(x, y);
    return bullet;
}

std::shared_ptr<Entity> EntityManager::createLaserLoading(int x, int y)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    auto distribution = std::uniform_int_distribution<std::uint32_t>(0, std::numeric_limits<std::uint32_t>::max());
    std::shared_ptr<Entity> laser = std::make_shared<Entity>(Entity(distribution(gen)));

    laser->addComponent<LaserLoadingComponent>(LaserLoadingComponent());
    laser->addComponent<PositionComponent>(PositionComponent(0, 0, -1));
    laser->addComponent<Renderable>(Renderable(SpriteType::LOADING_LASER));
    laser->addComponent<Rectable>(Rectable(0, 8));
    laser->addComponent<Velocity>(Velocity(0, 0, 0));
    laser->addComponent<ScaleComponent>(ScaleComponent(2.5, 2.5));
    laser->addComponent<SendOverNetworkComponent>(SendOverNetworkComponent());
    auto &sprite = laser->getComponent<Renderable>()._sprite;
    laser->getComponent<PositionComponent>().registerPositionChangeCallback([&sprite] (float x, float y) {
        sprite.setPosition(x, y);
    });
    laser->getComponent<PositionComponent>().setPos(x, y);
    return laser;
}

std::shared_ptr<Entity> EntityManager::createLaser(int x, int y)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    auto distribution = std::uniform_int_distribution<std::uint32_t>(0, std::numeric_limits<std::uint32_t>::max());
    std::shared_ptr<Entity> laser = std::make_shared<Entity>(Entity(distribution(gen)));

    laser->addComponent<LaserComponent>(LaserComponent());
    laser->addComponent<PositionComponent>(PositionComponent(x, y, -1));
    laser->addComponent<Renderable>(Renderable(SpriteType::LASER_PROJECTILE));
    laser->addComponent<Rectable>(Rectable(3, 4));
    laser->addComponent<BulletComponent>(BulletComponent(BulletComponent::TYPE::PLAYER));
    laser->addComponent<Velocity>(Velocity(15, 0, 0));
    laser->addComponent<ScaleComponent>(ScaleComponent(2.5, 2.5));
    laser->addComponent<SendOverNetworkComponent>(SendOverNetworkComponent());
    auto &sprite = laser->getComponent<Renderable>()._sprite;
    laser->getComponent<PositionComponent>().registerPositionChangeCallback([&sprite] (float x, float y) {
        sprite.setPosition(x, y);
    });
    laser->getComponent<PositionComponent>().setPos(x, y);
    return laser;
}

std::shared_ptr<Entity> EntityManager::createEnemy(float x, float y, int type)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    auto distribution = std::uniform_int_distribution<std::uint32_t>(0, std::numeric_limits<std::uint32_t>::max());
    std::shared_ptr<Entity> enemy = std::make_shared<Entity>(Entity(distribution(gen)));

    enemy->addComponent<PositionComponent>(PositionComponent(WIDTH, y, -1));
    enemy->addComponent<EnemyComponent>(EnemyComponent(type));
    switch (type)
    {
        case 1:
            enemy->addComponent<Renderable>(Renderable(SpriteType::ENEMY_0));
            enemy->addComponent<ScaleComponent>(ScaleComponent(2.3, 2.3));
            enemy->addComponent<Rectable>(Rectable(0, 8));
            break;
        case 2:
            enemy->addComponent<Renderable>(Renderable(SpriteType::ENEMY_1));
            enemy->addComponent<ScaleComponent>(ScaleComponent(2.3, 2.3));
            enemy->addComponent<Rectable>(Rectable(0, 7));
            break;
        case 3:
            enemy->addComponent<Renderable>(Renderable(SpriteType::ENEMY_2));
            enemy->addComponent<ScaleComponent>(ScaleComponent(2.5, 2.5));
            enemy->addComponent<Rectable>(Rectable(0, 3));
            break;
        case 4:
            enemy->addComponent<Renderable>(Renderable(SpriteType::ENEMY_3));
            enemy->addComponent<ScaleComponent>(ScaleComponent(3, 3));
            enemy->addComponent<Rectable>(Rectable(0, 6));
            enemy->getComponent<PositionComponent>().setPos(WIDTH,
                    HEIGHT - enemy->getComponent<Renderable>()._sprite.getGlobalBounds().height * 4);
            break;
        case 5:
            enemy->addComponent<Renderable>(Renderable(SpriteType::ENEMY_4));
            enemy->addComponent<ScaleComponent>(ScaleComponent(3, 3));
            enemy->addComponent<Rectable>(Rectable(1, 3));
            enemy->getComponent<PositionComponent>().setPos(x,
                    HEIGHT - enemy->getComponent<Renderable>()._sprite.getGlobalBounds().height * 5);
            break;

        case 6:
            enemy->addComponent<Renderable>(Renderable(SpriteType::ENEMY_5));
            enemy->addComponent<ScaleComponent>(ScaleComponent(3, 3));
            enemy->addComponent<Rectable>(Rectable(1, 10));
            break;
        case 7:
            enemy->addComponent<Renderable>(Renderable(SpriteType::ENEMY_6));
            enemy->addComponent<ScaleComponent>(ScaleComponent(3, 3));
            enemy->addComponent<Rectable>(Rectable(3, 4));
            break;
        case 19:
            enemy->addComponent<Renderable>(Renderable(SpriteType::BOSS));
            enemy->addComponent<Health>(Health(10));
            enemy->addComponent<ScaleComponent>(ScaleComponent(2, 2));
            enemy->addComponent<Rectable>(Rectable(0, 4, 9));
            enemy->addComponent<PositionComponent>(PositionComponent(500, (HEIGHT - enemy->getComponent<Renderable>()._sprite.getGlobalBounds().height) / 2));
            enemy->getComponent<EnemyComponent>()._isBoss = true;
            break;
        default:
            break;
    }
    auto &sprite = enemy->getComponent<Renderable>()._sprite;
    auto &pos = enemy->getComponent<PositionComponent>();
    enemy->getComponent<PositionComponent>().registerPositionChangeCallback([&sprite](float x, float y) {
        sprite.setPosition(x, y);
    });
    enemy->getComponent<PositionComponent>().setPos(pos.x, pos.y);
    enemy->addComponent<Velocity>(Velocity(0, 0, 0));
    entities->push_back(enemy);
    return enemy;
}

std::shared_ptr<Entity> EntityManager::createBulletEnemy(int size, int x, int y, int projectileType, sf::Vector2f velo)
{
    std::random_device rd;
    std::uniform_int_distribution<std::uint32_t> distribution;
    std::mt19937 gen(rd());
    std::shared_ptr<Entity> bullet = std::make_shared<Entity>(Entity(distribution(gen)));

    bullet->addComponent<PositionComponent>(PositionComponent(0, 0, -1));
    bullet->addComponent<Renderable>(Renderable(SpriteType::ENEMY_PROJECTILE)); // Changer le sprite de l'ennemi avec un switch case
    bullet->addComponent<BulletComponent>(BulletComponent(BulletComponent::TYPE::ENEMY));
    bullet->addComponent<Velocity>(Velocity(velo.x, velo.y, 0));
    bullet->addComponent<ScaleComponent>(ScaleComponent(2, 2));
    bullet->addComponent<Rectable>(Rectable(0, 4));
    auto &sprite = bullet->getComponent<Renderable>()._sprite;
    bullet->getComponent<PositionComponent>().registerPositionChangeCallback([&sprite] (float x, float y) {
        sprite.setPosition(x, y);
    });
    bullet->getComponent<PositionComponent>().setPos(x, y);
    return bullet;
}

std::shared_ptr<Entity> EntityManager::createBulletBoss(float x, float y, sf::Vector2f velo)
{
    std::random_device rd;
    std::uniform_int_distribution<std::uint32_t> distribution;
    std::mt19937 gen(rd());
    std::shared_ptr<Entity> bullet = std::make_shared<Entity>(Entity(distribution(gen)));

    bullet->addComponent<PositionComponent>(PositionComponent(0, 0, -1));
    bullet->addComponent<Renderable>(Renderable(SpriteType::LITTLE_BOSS_PROJECTILE));
    bullet->addComponent<BulletComponent>(BulletComponent(BulletComponent::TYPE::ENEMY));
    bullet->addComponent<Velocity>(Velocity(velo.x, velo.y, 0));
    bullet->addComponent<ScaleComponent>(ScaleComponent(2, 2));
    bullet->addComponent<Rectable>(Rectable(0, 4));
    auto &sprite = bullet->getComponent<Renderable>()._sprite;
    bullet->getComponent<PositionComponent>().registerPositionChangeCallback([&sprite] (float x, float y) {
        sprite.setPosition(x, y);
    });
    bullet->getComponent<PositionComponent>().setPos(x, y);
    return bullet;
}

std::shared_ptr<Entity> EntityManager::createExplosion(float x, float y)
{
    std::random_device rd;
    std::uniform_int_distribution<std::uint32_t> distribution;
    std::mt19937 gen(rd());
    std::shared_ptr<Entity> explosion = std::make_shared<Entity>(Entity(distribution(gen)));

    explosion->addComponent<PositionComponent>(PositionComponent(x, y, -1));
    explosion->addComponent<Renderable>(Renderable(SpriteType::EXPLOSION));
    explosion->addComponent<Explosion>(Explosion());
    explosion->addComponent<ScaleComponent>(ScaleComponent(3, 3));
    explosion->addComponent<Rectable>(Rectable(0, 5));
    auto &sprite = explosion->getComponent<Renderable>()._sprite;
    explosion->getComponent<PositionComponent>().registerPositionChangeCallback([&sprite] (float x, float y) {
        sprite.setPosition(x, y);
    });
    explosion->getComponent<PositionComponent>().setPos(x, y);
    return explosion;
}

std::shared_ptr<Entity> EntityManager::createItem(int x, int y, int type)
{
    std::random_device rd;
    std::uniform_int_distribution<std::uint32_t> distribution;
    std::mt19937 gen(rd());
    std::shared_ptr<Entity> item = std::make_shared<Entity>(Entity(distribution(gen)));

    item->addComponent<PositionComponent>(PositionComponent(x, y, -1));
    item->getComponent<PositionComponent>().setPos(x, y);
    if (type == -1)
        item->addComponent<ItemComponent>(ItemComponent(random() % 2));
    else
        item->addComponent<ItemComponent>(ItemComponent(type));
    item->addComponent<Renderable>(Renderable(SpriteType::ITEM_LOOTABLE));
    item->addComponent<ScaleComponent>(ScaleComponent(2, 2));
    item->addComponent<Rectable>(Rectable(0, 4));
    auto &sprite = item->getComponent<Renderable>()._sprite;
    item->getComponent<PositionComponent>().registerPositionChangeCallback([&sprite] (float x, float y) {
        sprite.setPosition(x, y);
    });
    item->getComponent<PositionComponent>().setPos(x, y);
    return item;
}


std::shared_ptr<Entity> EntityManager::createBlock(int x, int y, int type)
{
    std::random_device rd;
    std::uniform_int_distribution<std::uint32_t> distribution;
    std::mt19937 gen(rd());
    std::shared_ptr<Entity> block = std::make_shared<Entity>(Entity(distribution(gen)));

    block->addComponent<PositionComponent>(PositionComponent(WIDTH, y, -1));
    block->addComponent<EnemyComponent>(EnemyComponent(type));
    block->addComponent<ScaleComponent>(ScaleComponent(4, 4));
    block->getComponent<PositionComponent>().setPos(x, y);

    switch (type)
    {
        case 8:
            block->addComponent<Renderable>(Renderable(SpriteType::TOP_LEFT));
            break;
        case 9:
            block->addComponent<Renderable>(Renderable(SpriteType::TOP_MID));
            break;
        case 10:
            block->addComponent<Renderable>(Renderable(SpriteType::TOP_RIGHT));
            break;

        case 11:
            block->addComponent<Renderable>(Renderable(SpriteType::MID_LEFT));
            break;
        case 12:
            block->addComponent<Renderable>(Renderable(SpriteType::MID_MID));
            break;
        case 13:
            block->addComponent<Renderable>(Renderable(SpriteType::MID_RIGHT));
            break;

        case 14:
            block->addComponent<Renderable>(Renderable(SpriteType::BOTTOM_LEFT));
            break;
        case 15:
            block->addComponent<Renderable>(Renderable(SpriteType::BOTTOM_MID));
            break;
        case 16:
            block->addComponent<Renderable>(Renderable(SpriteType::BOTTOM_RIGHT));
            break;
        case 17:
            block->addComponent<Renderable>(Renderable(SpriteType::SPAWNER_BLOCK));
            break;
        case 18:
            block->addComponent<Renderable>(Renderable(SpriteType::MYSTERY_BLOCK));
            break;
        default:
            break;
    }
    auto &sprite = block->getComponent<Renderable>()._sprite;
    auto &pos = block->getComponent<PositionComponent>();
    block->getComponent<PositionComponent>().registerPositionChangeCallback([&sprite] (float x, float y) {
        sprite.setPosition(x, y);
    });
    block->getComponent<PositionComponent>().setPos(pos.x, pos.y);
    block->addComponent<Velocity>(Velocity(0, 0, 0));
    return block;
}

std::ostream &operator<<(std::ostream &os, const EntityManager &EntityManager)
{
    os << "EntityManager{";
    os << "Entites: ";
    os << EntityManager.getEntity();
    os << ", ";
    os << "Avaiables Entities: ";
    os << EntityManager.getAvailableEntities();
    os << "}";
    return os;
}
