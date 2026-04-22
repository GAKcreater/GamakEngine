#include "game/gameplay.hpp"

Gameplay::Gameplay()
{
}

void
Gameplay::processInputEvents(std::vector<sf::Event>& events)
{
    // Using a set to keep track of currently pressed keys.
    // This allows for smooth movement and handling multiple keys at once.
    for (int i = 0; i < events.size(); i++)
    {
        if (events[i].type == sf::Event::KeyPressed)
        {
            pressedKeys.insert(events[i].key.code);
        }
        else if (events[i].type == sf::Event::KeyReleased)
        {
            pressedKeys.erase(events[i].key.code);
        }
    }
}

void
Gameplay::update(std::vector<sf::Event>& events)
{
    processInputEvents(events);
    // TODO: Implement actual game logic/physics update here
}
