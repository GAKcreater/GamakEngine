
#include "core/core.hpp"

void
Core::routeEvents(std::vector<sf::Event>& events)
{
    if (events.size() != 0)
    {
        for (int i = 0; i < events.size(); i++)
        {
            switch (events[i].type)
            {
                case sf::Event::Closed:
                    gui.closeWindow();
                    break;

                // Routing keyboard events to the gameplay layer
                case sf::Event::KeyPressed:
                    eventVecForGame.push_back(events[i]);
                    break;

                case sf::Event::KeyReleased:
                    eventVecForGame.push_back(events[i]);
                    break;

                // UI events are handled directly through the GUI system
                case sf::Event::MouseButtonPressed:
                    if (events[i].mouseButton.button == sf::Mouse::Left)
                    {
                        gui.handleMouseClick(sf::Vector2i(events[i].mouseButton.x, events[i].mouseButton.y));
                    }
                    break;

                case sf::Event::MouseButtonReleased:
                    if (events[i].mouseButton.button == sf::Mouse::Left)
                    {
                        gui.handleMouseRelease(sf::Vector2i(events[i].mouseButton.x, events[i].mouseButton.y));
                    }
                    break;

                default:
                    break;
            }
        }
    }
}

void
Core::run()
{
    Gameplay mainGame;
    
    // Main Game Loop
    while (gui.isOpen())
    {
        // Calculate delta time for frame-rate independent movement
        time.update();
        
        // Handle rendering and poll window events
        gui.pollEventsAndRender();
        
        // Get events from the window and sort them to appropriate systems
        std::vector<sf::Event>& a = gui.fetchEvents();
        routeEvents(a);
        a.clear();

        // Process game logic with filtered events
        mainGame.update(eventVecForGame);
        eventVecForGame.clear();
    }
}
