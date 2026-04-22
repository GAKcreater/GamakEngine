#ifndef TIME_HPP
#define TIME_HPP

#include <SFML/Graphics.hpp>

class Time
{
public:
    void update();
    float getDeltaTime() const;

private:
    sf::Clock mainTime;
    float deltaTime = 0.0f;
};
#endif // !TIME_HPP