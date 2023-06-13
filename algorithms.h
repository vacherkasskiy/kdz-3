//
// Created by cherk on 13.06.2023.
//

#ifndef KDZ_3_ALGORITHMS_H
#define KDZ_3_ALGORITHMS_H

#include <vector>

// Алгоритм Дейкстры
int dijkstra(std::vector<std::vector<int>> g, int start, int end);

// Алгоритм Флойда-Уоршела
int floydWarshall(std::vector<std::vector<int>> g, int start, int end);

// Алгоритм Форда-Беллмана
int fordBellman(std::vector<std::vector<int>> g, int start, int end);

#endif //KDZ_3_ALGORITHMS_H