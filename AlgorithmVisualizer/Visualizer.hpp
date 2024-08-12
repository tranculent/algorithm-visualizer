#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <SFML/Graphics.hpp>

class Visualizer {
private:
    
public:
    virtual ~Visualizer() = default;
    virtual void step() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    void drawBar(int widthMultiplyer, int barWidth, int barHeight, sf::Color color, sf::RenderWindow& window);
};

#endif // VISUALIZER_HPP
