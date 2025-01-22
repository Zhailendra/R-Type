//
// Created by Simon BANDIERA on 09/01/2024.
//

#include "TextComponent.hpp"

#include <utility>

TextComponent::TextComponent()
{
    _type = Components::TEXT;
}

TextComponent::TextComponent(std::string text, sf::Color color, int size, bool debugMode)
{
    _type = Components::TEXT;
    _text.setString(text);
    _textString = std::move(text);
    _text.setFillColor(color);
    _text.setCharacterSize(size);
    _debugMode = debugMode;
}