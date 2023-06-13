#include <vector>
#include "generator.h"

int main() {
    int start = 10;
    int end = 1010;
    int step = 50;

    // Генерация полных графов
    for (int n = start; n <= end; n += step) {
        std::vector<std::vector<int>> completeGraph = generateCompleteGraph(n);


    }

    // Генерация связных графов
    double density = 0.4;
    for (int n = start; n <= end; n += step) {
        std::vector<std::vector<int>> connectedGraph = generateConnectedGraph(n, density);



        // Увеличиваем коэффициент плотности для следующего графа
        density += 0.1;
    }

    // Генерация разреженных графов (деревьев)
    for (int n = start; n <= end; n += step) {
        std::vector<std::vector<int>> sparseGraph = generateSparseGraph(n);


    }

    return 0;
}
