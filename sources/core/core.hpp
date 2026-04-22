#ifndef CORE_HPP
#define CORE_HPP

#include <fstream>
#include <string>
#include <vector>

#include "domain/definitions.hpp"
#include "domain/time.hpp"

#include "game/gameplay.hpp"
#include "gui/gui.hpp"

class Core
{
public:
    Core() = default;
    void run();

private:
    Time time;
    Gui gui;
    void routeEvents(std::vector<sf::Event>& events);
    std::vector<sf::Event> eventVecForGame;
    std::vector<sf::Event> eventVecForMenu;
};

#endif // !CORE_HPP