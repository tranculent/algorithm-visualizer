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

	int currentElementIndex = 0;

	// Draw the sorted elements
	for (int elem : sortedItems) {
		drawBar(currentElementIndex++, barWidth, elem, sf::Color::Green, window);
	}

	// Shuffle remaining elements to show they are not sorted yet
	std::shuffle(shuffledItems.begin() + (sortedItems.size() - 1), shuffledItems.end(), std::mt19937{ std::random_device{}() });

	for (int elem : shuffledItems) {
		drawBar(currentElementIndex++, barWidth, elem, sf::Color::Green, window);
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