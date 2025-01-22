#include <criterion/criterion.h>
#include "../../../../../src/common/ECS/Components/Controllable/ControllableComponent.hpp"

//Test toutes les keys
Test(ControllableComponent, Creation)
{
    sf::Keyboard::Key upKey = sf::Keyboard::Key::Up;
    sf::Keyboard::Key downKey = sf::Keyboard::Key::Down;
    sf::Keyboard::Key leftKey = sf::Keyboard::Key::Left;
    sf::Keyboard::Key rightKey = sf::Keyboard::Key::Right;
    sf::Keyboard::Key shootKey = sf::Keyboard::Key::Space;

    ControllableComponent controllable(upKey, downKey, leftKey, rightKey, shootKey);

    cr_assert_eq(controllable.up, upKey, "La touche 'up' n'a pas été initialisée correctement.");
    cr_assert_eq(controllable.down, downKey, "La touche 'down' n'a pas été initialisée correctement.");
    cr_assert_eq(controllable.left, leftKey, "La touche 'left' n'a pas été initialisée correctement.");
    cr_assert_eq(controllable.right, rightKey, "La touche 'right' n'a pas été initialisée correctement.");
    cr_assert_eq(controllable.shoot, shootKey, "La touche 'shoot' n'a pas été initialisée correctement.");
}
