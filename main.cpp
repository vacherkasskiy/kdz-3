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
    //std::ofstream file("data.csv", std::ios_base::app);

    int start = 10;
    int end = 1010;
    int step = 50;

    // Полные графы
    for (int n = start; n <= end; n += step) {

        // генерация
        std::vector<std::vector<int>> completeGraph = generateCompleteGraph(n);
        int a = getRandomNumber(0, n), b = getRandomNumber(0, n);

        // алгоритмы
        recordDijkstra(completeGraph, a, b, "complete graph, dijkstra");
        recordFloyd(completeGraph, a, b, "complete graph, floyd");
        recordFord(completeGraph, a, b, "complete graph, ford");
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

    //file.close();

    return 0;
}
