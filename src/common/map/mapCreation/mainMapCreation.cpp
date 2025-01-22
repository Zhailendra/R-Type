/*
** EPITECH PROJECT, 2024
** B-CPP-500-LIL-5-2-rtype-yacine.ourtanane
** File description:
** mainMapCreation
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "./CreationMap.hpp"

int writeMap(int enemy, float dtSeconds, float x, float y)
{
    std::ofstream file("./maps/map3.txt", std::ios::app);

    if (file.is_open()) {
        file << enemy << " " << dtSeconds << " " << x << " " << y << "\n";
        file.close();
    } else
        std::cerr << "ERROR : Impossible d'ouvrir le fichier." << std::endl;

    return 0;
}

// std::vector<sf::RectangleShape> CreationMap::makeEnemiesList()
// {
//     std::vector<sf::RectangleShape> enemiesList;
//     // std::map<sf::Texture, sf::Sprite> enemy;
//     std::vector<sf::Color> colors {sf::Color::Green, sf::Color::Blue, sf::Color::Cyan, sf::Color::Magenta, sf::Color::Red};
//     int x = 0;
//     int y = 30;
//     _enemiesList = std::make_shared<std::map<sf::Texture, sf::Sprite>>();

//     for (auto &spritePath : spritePaths) {
//         spritePath.second;
//     }

//     std::uint16_t index = 12;

//     index;

//     for (std::uint16_t i = 17, a = 0; i < 32; i++, a++, x += 90) {
//         spritePaths.at(SpriteType(index));
//         std::map<sf::Texture, sf::Sprite> enemy;
//         sf::Texture texture;
//         sf::Sprite sprite;
//         if (!texture.loadFromFile(spritePaths.at(SpriteType(i)))) {
//             std::cerr << "Error loading texture" << std::endl;
//             exit(84);
//         }
//         sprite.setTexture(texture);
//         if (i == 8) {
//             x = 0;
//             y = 110;
//         }
//         sf::RectangleShape enemy(sf::Vector2f(50, 50));
//         enemy.setPosition(y, 20 + x);
//         enemy.setFillColor(colors[a]);
//         if (a == 4)
//             a = 0;
//         enemiesList.push_back(enemy);
//     }

//     return enemiesList;
// }

int main()
{
    std::string filename = "./maps/map3.txt";
    std::cout << "Les informations sont écrites dans le fichier ./maps/map3.txt" << std::endl;
    // std::cout << "Choose a file name" << std::endl;
    // getline(std::cin, filename);

    CreationMap map(1280, 720, filename);

    sf::Clock gameTime;

    map.initSprites();

    while (map.isRunning()) {
        while (map.mapEvent()) {
            if (map.mapGetEvent().type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                map.mapClose();
        }

        map.mouseClicked();
        map.scrollScreen();
        map.mapDraw();
        map.mapDisplay();
    }


    return 0;
}
