# GamakEngine

This is my personal 2D game engine project built with C++ and SFML. It started as a way to learn game architecture and grew into a modular system with separated logic, rendering, and event management.

## Current State
The project is currently in a refactored state. I've moved away from a monolithic structure to a more decoupled approach:
* **Core:** Manages the main game loop and distributes events.
* **Gui:** Handles everything related to SFML window and rendering.
* **Gameplay:** Where the game logic lives, including input processing and entity states.
* **Domain:** Common utilities like time management and filesystem paths.

## Tech
* **C++17**
* **SFML 2.6.1**
* **Box2D 2.4.1**
* **CMake** for building

## How to build
I'm using `FetchContent` in CMake, so you don't need to install SFML or Box2D manually. Just run:
```bash
mkdir build && cd build
cmake ..
cmake --build .
```
The executable will be placed in the `bin/` folder.

## Future Plans
* Finish Box2D integration for all entities.
* Add a proper state machine for switching between menu and game.
* Implement a simple ECS (Entity Component System).
