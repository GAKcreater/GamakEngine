#ifndef GAME_HPP
#define GAME_HPP

#include "domain/const.hpp"
#include "domain/time.hpp"

#include "gui/gui.hpp"

class Gameplay
{
public:
    Gameplay();
    void update(std::vector<sf::Event>& events);

private:
    void processInputEvents(std::vector<sf::Event>& events);
    void doEvent();
    std::set<sf::Keyboard::Key> pressedKeys;
};

#endif // !GAME_HPP