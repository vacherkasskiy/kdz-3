//
// Created by cherk on 13.06.2023.
//

#include "generator.h"
#include <iostream>
#include <vector>
#include <random>

// Функция для генерации полного графа с n вершинами
std::vector<std::vector<int>> generateCompleteGraph(int n) {
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));

    // Заполняем ребра случайными весами
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> weightDis(1, 10);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int weight = weightDis(gen);
            graph[i][j] = weight;
            graph[j][i] = weight;
        }
    }

    return graph;
}

// Функция для генерации связного графа с n вершинами и коэффициентом плотности density
std::pair<int, std::vector<std::vector<int>>> generateConnectedGraph(int n, double density) {
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));

    // Определяем случайное количество ребер
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, n * (n - 1) / 2);

    int numEdges = dis(gen);

    // Создаем связный граф
    std::uniform_int_distribution<> weightDis(1, 10);
    for (int k = 0; k < numEdges; ++k) {
        int i = 0, j = 0;
        do {
            i = std::uniform_int_distribution<>(0, n - 1)(gen);
            j = std::uniform_int_distribution<>(0, n - 1)(gen);
        } while (i == j || graph[i][j] != 0);
        int weight = weightDis(gen);
        graph[i][j] = weight;
        graph[j][i] = weight;
    }

    // Генерируем оставшиеся ребра с вероятностью density
    std::uniform_real_distribution<> probDis(0.0, 1.0);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (graph[i][j] == 0 && probDis(gen) < density) {
                int weight = weightDis(gen);
                graph[i][j] = weight;
                graph[j][i] = weight;
            }
        }
    }

    return std::make_pair(numEdges, graph);
}

// Функция для генерации разреженного графа (дерева) с n вершинами
std::pair<int, std::vector<std::vector<int>>> generateSparseGraph(int n) {
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> numEdgesDis(1, n - 1);  // Случайное количество ребер от 1 до n-1
    int numEdges = numEdgesDis(gen);

    for (int i = 0; i < numEdges; ++i) {
        int u = std::uniform_int_distribution<>(0, n - 1)(gen);
        int v = std::uniform_int_distribution<>(0, n - 1)(gen);
        while (u == v || graph[u][v] != 0) {
            u = std::uniform_int_distribution<>(0, n - 1)(gen);
            v = std::uniform_int_distribution<>(0, n - 1)(gen);
        }
        int weight = std::uniform_int_distribution<>(1, 10)(gen);
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    return std::make_pair(numEdges, graph);
}
