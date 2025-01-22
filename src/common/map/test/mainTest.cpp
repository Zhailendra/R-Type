/*
** EPITECH PROJECT, 2023
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** mainTest
*/

#include "./my.h"

std::vector<sf::RectangleShape> makeEnemiesList()
{
    std::vector<sf::RectangleShape> enemiesList;
    std::vector<sf::Color> colors {sf::Color::Green, sf::Color::Blue, sf::Color::Cyan, sf::Color::Magenta, sf::Color::Red};

    for (int i = 0; i < 5; i++) {
        sf::RectangleShape enemy(sf::Vector2f(50, 50));
        enemy.setPosition(30, 100 + i * 100);
        enemy.setFillColor(colors[i]);
        enemiesList.push_back(enemy);
    }

    return enemiesList;
}

int writeMap(int enemy, float dtSeconds, float x, float y)
{
    std::ofstream file("./maps/map2.txt", std::ios::app);

    if (file.is_open()) {
        file << enemy << " " << dtSeconds << " " << x << " " << y << "\n";
        file.close();
    } else
        std::cerr << "ERROR : Impossible d'ouvrir le fichier." << std::endl;

    return 0;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "R-TYPE");
    sf::Clock gameTime;

    bool mouseClicked = false;
    bool select = false;
    int enemyType = 0;
    int enemies = 0;

    std::vector<sf::RectangleShape> enemiesList = makeEnemiesList();

    sf::RectangleShape newEnemy(sf::Vector2f(80.0f, 80.0));
    sf::RectangleShape enemyMouse(sf::Vector2f(70.0f, 70.0));

    std::vector<sf::RectangleShape> enemiesRec;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }
         if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !mouseClicked) {
            sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            sf::Time gameStartTime = gameTime.getElapsedTime();


            for (size_t i = 0; i < enemiesList.size(); ++i) {
                if (enemiesList[i].getGlobalBounds().contains(mousePosition)) {
                    enemyMouse.setFillColor(enemiesList[i].getFillColor());
                    newEnemy.setFillColor(enemyMouse.getFillColor());
                    select = true;
                    enemyType = i;
                }
            }
            if (!select) {
                writeMap(enemyType, gameStartTime.asSeconds(), mousePosition.x - 40, mousePosition.y - 40);
                enemiesRec.push_back(sf::RectangleShape(newEnemy));
                enemiesRec[enemies].setPosition(mousePosition.x - 40, mousePosition.y - 40);
                enemies++;
            }

            mouseClicked = true;
            select = false;
        }

        if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            mouseClicked = false;

        window.clear(sf::Color::Black);

        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        enemyMouse.setPosition(mousePos.x - 35, mousePos.y - 35);

        for (const auto& enemyRec : enemiesRec)
            window.draw(enemyRec);

        for (const auto& rectangle : enemiesList)
            window.draw(rectangle);


        window.draw(enemyMouse);

        window.display();
    }


    return 0;
}

// 90
// 70

// Mettre tout ce que j'ai dans ma classe
// Importe les sprites de tous les ennemis
// Mettre les sprites du parallax
// Changer l'oppacité des sprites quand ils sont placés

// Supplément

// Faire une scroll bar pour simuler toute la map et gérer le timing
// Faire la suppression des enemis sur la map