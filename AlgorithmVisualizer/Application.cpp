#include "Application.hpp"
#include "BubbleSortVisualizer.hpp"
#include "HeapSortVisualizer.hpp"

Application::Application()
    : mWindow(sf::VideoMode(800, 600), "Algorithm Visualizer"), mVisualizer(new HeapSortVisualizer()) {
}

void Application::run() {
    while (mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Application::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void Application::update() {
    mVisualizer->step();
}

void Application::render() {
    mWindow.clear();
    mVisualizer->draw(mWindow);
    mWindow.display();
}
