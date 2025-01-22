#include "./TestASystem.hpp"
#include "criterion/criterion.h"

Test(ASystem_class, test_set_inputs) {
    std::shared_ptr<PlayerSystem> playerSystem = std::make_shared<PlayerSystem>();
    std::shared_ptr<ASystem> mySystem = std::make_shared<ASystem>();
    std::vector<sf::Event> events;
    sf::Keyboard::Key arrayOfKey [4] =
    {sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Up, sf::Keyboard::Down};
    
    for (int i = 0; i < 5; i++) {
        sf::Event event;
        event.type = sf::Event::EventType::KeyPressed;
        event.key.code = arrayOfKey[i];
        events.push_back(event);
    }

    std::shared_ptr<std::vector<sf::Event>> inputs = std::make_shared<std::vector<sf::Event>>(events);
    mySystem->setInputs(inputs);

    playerSystem->update();
}