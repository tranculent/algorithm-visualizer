#include "BubbleSortVisualizer.hpp"
#include <algorithm>
#include <random>

BubbleSortVisualizer::BubbleSortVisualizer() : mCurrentIndex(0), mSorted(false) {
    generateRandomArray();
}

void BubbleSortVisualizer::step() {
    if (mSorted) return;

    if (mCurrentIndex < mArray.size() - 1) {
        if (mArray[mCurrentIndex] > mArray[mCurrentIndex + 1]) {
            std::swap(mArray[mCurrentIndex], mArray[mCurrentIndex + 1]);
        }
        mCurrentIndex++;
    }
    else {
        mCurrentIndex = 0;
        mSorted = std::is_sorted(mArray.begin(), mArray.end());
    }
}

void BubbleSortVisualizer::draw(sf::RenderWindow& window) {
    float barWidth = static_cast<float>(window.getSize().x) / mArray.size();
    for (size_t i = 0; i < mArray.size(); ++i) {
        drawBar(i, barWidth, mArray[i], sf::Color::White, window);
    }
}

void BubbleSortVisualizer::generateRandomArray() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10, 400);
    mArray.resize(100);
    for (auto& value : mArray) {
        value = dis(gen);
    }
}
