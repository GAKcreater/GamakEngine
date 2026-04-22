#include "interface.hpp"

Interface::Interface(std::string path, float x, float y)
{
    pagePosition.x = x;
    pagePosition.y = y;
    pageTexture.loadFromFile(path);
    pageSprite.setTexture(pageTexture);
    pageSprite.setPosition(pagePosition);
}

void
Interface::setButton(std::string onClickTexturePath, std::string defaultTexturePath, float x,
                     float y, float xSize, float ySize)
{
    buttons.emplace_back(onClickTexturePath, defaultTexturePath, x, y, xSize, ySize);
}

void
Interface::handleMouseClick(sf::Vector2f mousePos)
{
    for (auto& button : buttons)
    {
        button.clicked(mousePos);
    }
}

void
Interface::handleMouseRelease(sf::Vector2f mousePos)
{
    for (auto& button : buttons)
    {
        button.released(mousePos);
    }
}

std::vector<sf::Sprite>
Interface::draw()
{
    std::vector<sf::Sprite> m;
    m.push_back(pageSprite);
    for (int i = 0; i < buttons.size(); i++)
    {
        m.push_back(buttons[i].buttonSprite);
    }
    return m;
}