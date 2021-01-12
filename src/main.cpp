#include <iostream>
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include <GameController.h>

int main() {

    /*auto rec = sf::RectangleShape({200,200});

    rec.setOrigin(100,100);

    std::cout << rec.getGlobalBounds().left << std::endl;
    std::cout << rec.getGlobalBounds().left + rec.getGlobalBounds().width << std::endl;
    std::cout << rec.getGlobalBounds().top << std::endl;
    std::cout << rec.getGlobalBounds().top + rec.getGlobalBounds().height << std::endl;

    auto window = sf::RenderWindow(sf::VideoMode({500,500}), " ");

    while(window.isOpen())
    {
        window.clear();
        window.draw(rec);
        window.display();
    }*/

    auto LodeRunner = GameController();

    LodeRunner.Run();

    return EXIT_SUCCESS;
}
