//
// Created by Simon BANDIERA on 09/01/2024.
//

#include "TextSystem.hpp"

TextSystem::TextSystem()
{
    _font.loadFromFile("assets/arial.ttf");
}

void TextSystem::update()
{
    for (auto &entity : *_entities) {
        if (!entity->hasComponent<TextComponent>())
            continue;
        auto &textComponent = entity->getComponent<TextComponent>();
        const auto &posComponent = entity->getComponent<PositionComponent>();
        if (!textComponent._fontLoaded) {
            textComponent._text.setFont(_font);
            textComponent._fontLoaded = true;
        }
        if (entity->hasComponent<ButtonComponent>()) {
            auto rect = textComponent._text.getLocalBounds();
            textComponent._text.setOrigin(rect.left + rect.width / 2.0f,
                rect.top + rect.height / 2.0f);
            auto &buttonComponent = entity->getComponent<ButtonComponent>();
            buttonComponent._rect.setOrigin(buttonComponent._size.x / 2, buttonComponent._size.y / 2);
            buttonComponent._rect.setPosition(posComponent.x, posComponent.y);
        }
        if (entity->hasComponent<InputComponent>()) {
            auto rect = textComponent._text.getLocalBounds();
            textComponent._text.setOrigin(rect.left + rect.width / 2.0f,
                rect.top + rect.height / 2.0f);
            auto &buttonComponent = entity->getComponent<InputComponent>();
            buttonComponent._rect.setOrigin(buttonComponent._size.x / 2, buttonComponent._size.y / 2);
            buttonComponent._rect.setPosition(posComponent.x, posComponent.y);
        }

        textComponent._text.setPosition(posComponent.x, posComponent.y);
        textComponent._text.setString(textComponent._textString);
    }
}

std::shared_ptr<std::vector<std::shared_ptr<Entity>>> TextSystem::getEntites()
{
    return _entities;
}

void TextSystem::addEntity(std::shared_ptr<Entity> &entity)
{
    _entities->push_back(entity);
}
