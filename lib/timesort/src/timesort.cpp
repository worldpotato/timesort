/**
 * @author      : worldpotato
 * @file        : timesort
 * @created     : Wednesday Aug 26, 2020 20:47:43 CEST
 */

#include "../include/timesort.hpp"

std::vector<int> timesort::values;
std::vector<std::thread> timesort::threadList;
std::vector<int> timesort::sortedValues;

auto timesort::putValuesInSortedVector(const int milliseconds) -> void
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    sortedValues.emplace_back(milliseconds);
};

auto timesort::createThreads() -> void
{
    for (int& milliseconds : timesort::values) {
        threadList.emplace_back(std::thread(putValuesInSortedVector, milliseconds));
    }
}

auto timesort::waitForThreadsToFinish() -> void
{
    for (std::thread& t : threadList) {
        t.join();
    }
}

auto timesort::sort(std::vector<int>& values) -> std::vector<int>
{
    timesort::values = values;
    createThreads();
    waitForThreadsToFinish();

    return sortedValues;
}

