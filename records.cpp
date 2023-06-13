//
// Created by cherk on 14.06.2023.
//

#include <vector>
#include <string>
#include <chrono>
#include "records.h"
#include "algorithms.h"

auto clock_start = std::chrono::high_resolution_clock::now();
auto elapsed = std::chrono::high_resolution_clock::now() - clock_start;
long long nanoseconds;
long long sum = 0;

void recordDijkstra(const std::vector<std::vector<int>> &g, int start, int end, std::string name) {
    sum = 0;

    for (int i = 0; i < 5; ++i) {
        clock_start = std::chrono::high_resolution_clock::now();
        dijkstra(g, start, end);
        elapsed = std::chrono::high_resolution_clock::now() - clock_start;
        nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
        sum += nanoseconds / 5;
    }

    // RECORD RESULTS
}

void recordFloyd(const std::vector<std::vector<int>> &g, int start, int end, std::string name) {
    sum = 0;

    for (int i = 0; i < 5; ++i) {
        clock_start = std::chrono::high_resolution_clock::now();
        floydWarshall(g, start, end);
        elapsed = std::chrono::high_resolution_clock::now() - clock_start;
        nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
        sum += nanoseconds / 5;
    }

    // RECORD RESULTS
}

void recordFord(const std::vector<std::vector<int>> &g, int start, int end, std::string name) {
    sum = 0;

    for (int i = 0; i < 5; ++i) {
        clock_start = std::chrono::high_resolution_clock::now();
        fordBellman(g, start, end);
        elapsed = std::chrono::high_resolution_clock::now() - clock_start;
        nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
        sum += nanoseconds / 5;
    }

    // RECORD RESULTS
}