#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include "Visualizer.hpp"

class Application {
public:
    Application();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow mWindow;
    Visualizer* mVisualizer; // Base class pointer to current visualizer
};

#endif // APPLICATION_HPP
