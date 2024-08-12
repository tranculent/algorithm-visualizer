#include "Visualizer.hpp"

void Visualizer::drawBar(int widthMultiplyer, int barWidth, int barHeight, sf::Color color, sf::RenderWindow& window) {
	sf::RectangleShape bar(sf::Vector2f(barWidth - 1, barHeight));
	bar.setPosition(widthMultiplyer * barWidth, window.getSize().y - barHeight);
	bar.setFillColor(color);

	window.draw(bar);
}