#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <set>
#include <vector>

#include "domain/definitions.hpp"

#include "core/events.hpp"

#include "interface.hpp"

class Gui
{
public:
    Gui();
    void pollEventsAndRender();
    void addSprite(sf::Sprite& a);
    Events evObject;
    std::vector<sf::Event>& fetchEvents();
    void handleMouseClick(sf::Vector2i mousePos);
    void handleMouseRelease(sf::Vector2i mousePos);
    void closeWindow();
    bool isOpen() const;
    std::vector<sf::Sprite*> SpriteVector;
    std::vector<Interface*> interfacePageVector;

private:
    void renderElements();
    sf::RenderWindow mWindow;
    // Pages//
    Interface mainPage;
    // Pages//
};
#endif // !GUI_HPP
