//
// Created by cherk on 14.06.2023.
//

#include <vector>
#include <string>
#include <chrono>
#include "records.h"
#include "algorithms.h"
#include "writer.h"

auto clock_start = std::chrono::high_resolution_clock::now();
auto elapsed = std::chrono::high_resolution_clock::now() - clock_start;
long long nanoseconds;
long long sum = 0;

void recordDijkstra(
        std::ofstream &file,
        const std::vector<std::vector<int>> &g,
        int start,
        int end,
        int numEdges,
        const std::string &name){

    sum = 0;
    int size = g.size();
    int runsNum = 5;

    for (int i = 0; i < runsNum; ++i) {
        clock_start = std::chrono::high_resolution_clock::now();
        dijkstra(g, start, end);
        elapsed = std::chrono::high_resolution_clock::now() - clock_start;
        nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
        sum += nanoseconds / runsNum;
    }

    writeCsv(file, name, sum, size, numEdges);
}

void recordFloyd(
        std::ofstream &file,
        const std::vector<std::vector<int>> &g,
        int start,
        int end,
        int numEdges,
        const std::string &name) {
    sum = 0;
    int size = g.size();
    int runsNum = 5;

    for (int i = 0; i < runsNum; ++i) {
        clock_start = std::chrono::high_resolution_clock::now();
        floydWarshall(g, start, end);
        elapsed = std::chrono::high_resolution_clock::now() - clock_start;
        nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
        sum += nanoseconds / runsNum;
    }

    writeCsv(file, name, sum, size, numEdges);
}

void recordFord(
        std::ofstream &file,
        const std::vector<std::vector<int>> &g,
        int start,
        int end,
        int numEdges,
        const std::string &name) {
    sum = 0;
    int size = g.size();
    int runsNum = 5;

    for (int i = 0; i < runsNum; ++i) {
        clock_start = std::chrono::high_resolution_clock::now();
        fordBellman(g, start, end);
        elapsed = std::chrono::high_resolution_clock::now() - clock_start;
        nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
        sum += nanoseconds / runsNum;
    }

    writeCsv(file, name, sum, size, numEdges);
}