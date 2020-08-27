/**
 * @author      : worldpotato
 * @file        : timesort
 * @created     : Wednesday Aug 26, 2020 20:47:30 CEST
 */

#ifndef TIMESORT_HPP

#define TIMESORT_HPP

#include <thread>
#include <vector>

class timesort {
public:
    static auto sort(std::vector<int>& values) -> std::vector<int>;

private:
    static std::vector<int> values;
    static std::vector<std::thread> threadList;
    static std::vector<int> sortedValues;

    static auto putValuesInSortedVector(const int milliseconds) -> void;
    static auto createThreads() -> void;
    static auto waitForThreadsToFinish() -> void;
};

#endif /* end of include guard TIMESORT_HPP */

