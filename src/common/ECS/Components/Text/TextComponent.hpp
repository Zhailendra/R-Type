//
// Created by Simon BANDIERA on 09/01/2024.
//

#ifndef TEXTCOMPONENT_HPP
#define TEXTCOMPONENT_HPP

#include <ECS/Components/AComponent.hpp>
#include <SFML/Graphics.hpp>

class TextComponent : public AComponent {
    public:
        TextComponent();
        TextComponent(std::string text, sf::Color color, int size, bool debugMode = false);
        ~TextComponent() = default;

        sf::Text _text;
        std::string _textString;
        sf::Color _color;
        int _size;
        sf::Font _font;
        bool _fontLoaded = false;
        bool _debugMode = false;
    protected:
    private:

};



#endif //TEXTCOMPONENT_HPP
