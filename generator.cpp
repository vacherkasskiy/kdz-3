//
// Created by cherk on 13.06.2023.
//

#include "generator.h"
#include <iostream>
#include <vector>
#include <random>

// Функция для генерации полного графа с n вершинами
std::vector<std::vector<int>> generateCompleteGraph(int n) {
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 1));

    // Заполняем диагональные элементы нулями
    for (int i = 0; i < n; ++i) {
        graph[i][i] = 0;
    }

    return graph;
}

// Функция для генерации связного графа с n вершинами и коэффициентом плотности density
std::vector<std::vector<int>> generateConnectedGraph(int n, double density) {
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));

    // Создаем связный граф
    for (int i = 0; i < n - 1; ++i) {
        graph[i][i + 1] = 1;
        graph[i + 1][i] = 1;
    }

    // Генерируем оставшиеся ребра с вероятностью density
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 2; j < n; ++j) {
            if (dis(gen) < density) {
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }

    return graph;
}

// Функция для генерации разреженного графа (дерева) с n вершинами
std::vector<std::vector<int>> generateSparseGraph(int n) {
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));

    // Создаем дерево
    for (int i = 0; i < n - 1; ++i) {
        graph[i][i + 1] = 1;
        graph[i + 1][i] = 1;
    }

    return graph;
}