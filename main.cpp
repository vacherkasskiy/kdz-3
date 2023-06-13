#include <vector>
#include <random>
#include <fstream>
#include "generator.h"
#include "records.h"

int getRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int main() {
    std::ofstream file("data.csv", std::ios_base::app);

    int start = 10;
    int end = 300;
    int step = 50;

    // Полные графы
    for (int n = start; n <= end; n += step) {

        // генерация
        std::vector<std::vector<int>> completeGraph = generateCompleteGraph(n);
        int a = getRandomNumber(0, n), b = getRandomNumber(0, n);
        int numEdges = (n * (n - 1)) / 2;

        // алгоритмы
        recordDijkstra(file, completeGraph, a, b, numEdges, "complete graph, dijkstra");
        recordFloyd(file, completeGraph, a, b, numEdges, "complete graph, floyd");
        recordFord(file, completeGraph, a, b, numEdges, "complete graph, ford");
    }

    // Связные графы
    double density = 0.4;
    for (int n = start; n <= end; n += step) {
        // генерация связных графов
        auto info = generateConnectedGraph(n, density);
        int numEdges = info.first;
        auto g = info.second;

        // тело

        // Увеличиваем коэффициент плотности для следующего графа
        density += 0.1;
    }

    // Генерация разреженных графов (деревьев)
    for (int n = start; n <= end; n += step) {
        auto info = generateSparseGraph(n);
        int numEdges = info.first;
        auto g = info.second;

        // тело
    }

    file.close();

    return 0;
}
