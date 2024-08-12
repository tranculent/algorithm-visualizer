#include "HeapSortVisualizer.hpp"
#include <algorithm>
#include <random>
#include <iostream>

HeapSortVisualizer::HeapSortVisualizer() {
	generateRandomArray();
}

void HeapSortVisualizer::step() {
	if (pq.size() > 0) {
		sortedItems.push_back(pq.top());
		pq.pop();
	}
}

void HeapSortVisualizer::draw(sf::RenderWindow& window) {
	float barWidth = static_cast<float>(window.getSize().x) / initialSize;

	if (pq.empty()) {
		for (int i = 0; i < sortedItems.size(); i++) {
			sf::RectangleShape bar(sf::Vector2f(barWidth - 1, sortedItems[i]));
			bar.setPosition(i++ * barWidth, window.getSize().y - sortedItems[i]);
			bar.setFillColor(sf::Color::Green);  // Different color for sorted elements
			window.draw(bar);

			//drawBar(i, barWidth - 1, sortedItems[i], sf::Color::Green, window);
		}
	}

	int currentElementIndex = 0;

	// Draw the sorted elements
	for (int elem : sortedItems) {
		sf::RectangleShape bar(sf::Vector2f(barWidth - 1, elem));
		bar.setPosition(currentElementIndex++ * barWidth, window.getSize().y - elem);
		bar.setFillColor(sf::Color::Green);  // Different color for sorted elements
		window.draw(bar);
		//drawBar(currentElementIndex++, barWidth, window.getSize().y - elem, sf::Color::Green, window);
	}

	// Shuffle remaining elements to show they are not sorted yet
	std::shuffle(shuffledItems.begin() + (sortedItems.size() - 1), shuffledItems.end(), std::mt19937{ std::random_device{}() });

	for (int elem : shuffledItems) {
		sf::RectangleShape bar(sf::Vector2f(barWidth - 1, elem));
		bar.setPosition(currentElementIndex++ * barWidth, window.getSize().y - elem);
		bar.setFillColor(sf::Color::White);  // Color for unsorted elements
		window.draw(bar);
		//drawBar(currentElementIndex++, barWidth, window.getSize().y - elem, sf::Color::White, window);
	}
}

void HeapSortVisualizer::generateRandomArray() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(10, 400);
	initialSize = 100;
	sortedItems.clear();
	shuffledItems.clear();

	for (int i = 0; i < initialSize; i++) {
		int currNum = dis(gen);

		pq.push(currNum);
		shuffledItems.push_back(currNum);
	}
}

bool HeapSortVisualizer::isPriorityQueueSorted() {
	return pq.empty();
}