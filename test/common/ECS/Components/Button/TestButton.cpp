#include <criterion/criterion.h>
#include <SFML/Graphics.hpp>
#include "../../../../../src/common/ECS/Components/Button/ButtonComponent.hpp"

// Test conctructor
Test(ButtonComponent, ConstructorWithValidValues)
{
    ButtonComponent button("Click me", sf::Vector2f(100, 100), sf::Vector2f(120, 50), sf::Color::Green,
                           sf::Color::White, "./assets/comicate.ttf");

    cr_assert_eq(button._text, "Click me");
    cr_assert_eq(button._position, sf::Vector2f(100, 100));
    cr_assert_eq(button._size, sf::Vector2f(120, 50));
    cr_assert_eq(button._color, sf::Color::Green);
    cr_assert_eq(button._textColor, sf::Color::White);
    cr_assert_eq(button._fontPath, "./assets/comicate.ttf");
}

// Test du callback après un clic
Test(ButtonComponent, CallbackAfterClick)
{
    ButtonComponent button("Click me", sf::Vector2f(100, 100), sf::Vector2f(120, 50), sf::Color::Green,
                           sf::Color::White, "./assets/comicate.ttf");

    bool callbackTriggered = false;

    auto callback = [&]() {
        callbackTriggered = true;
    };

    button.click(callback);

    cr_assert_not(callbackTriggered);

    button._callback();

    cr_assert(callbackTriggered);
}

// Test du click avec un callback nul
Test(ButtonComponent, ClickWithNullCallback)
{
    ButtonComponent button("Click me", sf::Vector2f(100, 100), sf::Vector2f(120, 50), sf::Color::Green,
                           sf::Color::White, "./assets/comicate.ttf");

    button.click(nullptr);

    cr_assert_eq(button._callback, nullptr);
}
