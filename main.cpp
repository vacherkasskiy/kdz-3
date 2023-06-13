#include <vector>
#include <random>
#include <chrono>
#include "generator.h"
#include "algorithms.h"

auto clock_start = std::chrono::high_resolution_clock::now();
auto elapsed = std::chrono::high_resolution_clock::now() - clock_start;
long long nanoseconds;
long long sum = 0;

int getRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int main() {
    int start = 10;
    int end = 1010;
    int step = 50;

    // Полные графы
    for (int n = start; n <= end; n += step) {
        // генерация полных графов
        std::vector<std::vector<int>> completeGraph = generateCompleteGraph(n);

        for (int i = 0; i < 5; ++i) {
            // основной код
            int a = getRandomNumber(0, n), b = getRandomNumber(0, n);

            sum = 0;
            clock_start = std::chrono::high_resolution_clock::now();
            dijkstra(completeGraph, a, b);
            elapsed = std::chrono::high_resolution_clock::now() - clock_start;
            nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
            sum += nanoseconds / 5;
            // записать результаты

            sum = 0;
            clock_start = std::chrono::high_resolution_clock::now();
            floydWarshall(completeGraph, a, b);
            elapsed = std::chrono::high_resolution_clock::now() - clock_start;
            nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
            sum += nanoseconds / 5;
            // записать результаты

            sum = 0;
            clock_start = std::chrono::high_resolution_clock::now();
            fordBellman(completeGraph, a, b);
            elapsed = std::chrono::high_resolution_clock::now() - clock_start;
            nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
            sum += nanoseconds / 5;
            // записать результаты
        }

    }

    // Связные графы
    double density = 0.4;
    for (int n = start; n <= end; n += step) {
        // генерация связных графов
        std::vector<std::vector<int>> connectedGraph = generateConnectedGraph(n, density);

        // тело

        // Увеличиваем коэффициент плотности для следующего графа
        density += 0.1;
    }

    // Генерация разреженных графов (деревьев)
    for (int n = start; n <= end; n += step) {
        std::vector<std::vector<int>> sparseGraph = generateSparseGraph(n);

        // тело
    }

    return 0;
}
