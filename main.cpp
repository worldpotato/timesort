/**
 * @author      : worldpotato
 * @file        : main
 * @created     : Wednesday Aug 19, 2020 11:04:24 CEST
 */

#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

std::vector<int> values;
std::vector<std::thread> threadList;
std::vector<int> sortedValues;

constexpr int lowestRandomNumber = 1;
constexpr int highestRandomNumber = 100;

auto getNumberOfElements() -> int
{
    int n = 0;
    std::cout << "Number of elements to sort" << std::endl;
    std::cin >> n;
    return n;
}

auto generateRandomValue(int lowerBoundary, int upperBoundary) -> int
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(lowerBoundary, upperBoundary);

    return dist(mt);
}

auto createRandomValues(int numberOfElements) -> void
{
    for (int i = 0; i < numberOfElements; i++) {
        int randomValue = generateRandomValue(lowestRandomNumber, highestRandomNumber);
        values.emplace_back(randomValue);
    }
}

auto sort = [](int milliseconds) -> void {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    sortedValues.emplace_back(milliseconds);
};

auto createThreads() -> void
{
    for (int& milliseconds : values) {
        threadList.emplace_back(std::thread(sort, milliseconds));
    }
}

auto waitForThreadsToFinish() -> void
{
    for (std::thread& t : threadList) {
        t.join();
    }
}

auto printVector(std::vector<int> vector) -> void
{
    for (int& value : vector) {
        std::cout << value << std::endl;
    }
}

auto main() -> int
{
    int numberOfElements = getNumberOfElements();
    createRandomValues(numberOfElements);
    createThreads();
    waitForThreadsToFinish();
    printVector(sortedValues);
    return 0;
}

