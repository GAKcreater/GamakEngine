#include "gui/gui.hpp"

Gui::Gui()
    : mWindow(sf::VideoMode(500, 500), "TheBestGame"),
      mainPage(TEXTURES_PATH + "mainPage.png", 0, 0)
{
    interfacePageVector.push_back(&mainPage);
    mainPage.setButton(TEXTURES_PATH + "firstButton2.png", TEXTURES_PATH + "firstButton1.png", 82,
                       118, 340, 150);
    mWindow.setFramerateLimit(60);
}

void
Gui::addSprite(sf::Sprite& a)
{
    SpriteVector.push_back(&a);
}

void
Gui::renderElements()
{
    for (int i = 0; i < SpriteVector.size(); i++)
    {
        mWindow.draw(*SpriteVector[i]);
    }

    for (int i = 0; i < interfacePageVector.size(); i++)
    {
        for (int j = 0; j < interfacePageVector[i]->draw().size(); j++)
        {
            mWindow.draw(interfacePageVector[i]->draw()[j]);
        }
    }
}

std::vector<sf::Event>&
Gui::fetchEvents()
{
    return evObject.eventVec;
}

void
Gui::handleMouseClick(sf::Vector2i mousePos)
{
    sf::Vector2f floatMousePos(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    for (auto* page : interfacePageVector)
    {
        page->handleMouseClick(floatMousePos);
    }
}

void
Gui::handleMouseRelease(sf::Vector2i mousePos)
{
    sf::Vector2f floatMousePos(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    for (auto* page : interfacePageVector)
    {
        page->handleMouseRelease(floatMousePos);
    }
}

void
Gui::closeWindow()
{
    mWindow.close();
}

bool
Gui::isOpen() const
{
    return mWindow.isOpen();
}

void
Gui::pollEventsAndRender()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        evObject.pushEvent(event);
    }
    mWindow.clear();
    renderElements();
    mWindow.display();
}