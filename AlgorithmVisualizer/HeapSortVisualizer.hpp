#ifndef HEAPSORTVISUALIZER_HPP
#define HEAPSORTVISUALIZER_HPP

#include "Visualizer.hpp"
#include <queue>
#include <vector>

class HeapSortVisualizer : public Visualizer {
public:
	HeapSortVisualizer();
	void step() override;
	void draw(sf::RenderWindow&) override;

private:
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	int initialSize;
	std::vector<int> sortedItems;
	std::vector<int> shuffledItems;

	bool isPriorityQueueSorted();
	void generateRandomArray();
};

#endif