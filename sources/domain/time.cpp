#include "time.hpp"

void
Time::update()
{
    deltaTime = mainTime.restart().asSeconds();
}

float
Time::getDeltaTime() const
{
    return deltaTime;
}