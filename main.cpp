/**
 * @author      : worldpotato
 * @file        : main
 * @created     : Wednesday Aug 19, 2020 11:04:24 CEST
 */

#include <iostream>
#include <random>
#include <vector>

#include "timesort.hpp"

constexpr int lowestRandomNumber = 1;
constexpr int highestRandomNumber = 100;

auto getNumberOfElementsFromUser() -> int
{
    int n = 0;
    std::cout << "Number of elements to sort" << std::endl;
    std::cin >> n;
    return n;
}

auto generateRandomValue(const int lowerBoundary, const int upperBoundary) -> int
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(lowerBoundary, upperBoundary);

    return dist(mt);
}

auto createRandomValues(int numberOfElements) -> std::vector<int>
{
    std::vector<int> values;

    for (int i = 0; i < numberOfElements; i++) {
        int randomValue = generateRandomValue(lowestRandomNumber, highestRandomNumber);
        values.emplace_back(randomValue);
    }

    return values;
}

auto printVector(std::vector<int> vector) -> void
{
    for (int& value : vector) {
        std::cout << value << std::endl;
    }
}

auto main() -> int
{
    int numberOfElements;
    std::vector<int> randomValues;
    std::vector<int> sortedValues;

    numberOfElements = getNumberOfElementsFromUser();
    randomValues = createRandomValues(numberOfElements);
    sortedValues = timesort::sort(randomValues);

    printVector(sortedValues);
    return 0;
}

