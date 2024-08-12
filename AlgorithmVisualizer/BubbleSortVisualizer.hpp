#ifndef BUBBLESORTVISUALIZER_HPP
#define BUBBLESORTVISUALIZER_HPP

#include "Visualizer.hpp"
#include <vector>

class BubbleSortVisualizer : public Visualizer {
public:
    BubbleSortVisualizer();
    void step() override;
    void draw(sf::RenderWindow& window) override;

private:
    std::vector<int> mArray;
    size_t mCurrentIndex;
    bool mSorted;

    void generateRandomArray();
};

#endif // BUBBLESORTVISUALIZER_HPP
