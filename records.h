//
// Created by cherk on 14.06.2023.
//

#ifndef KDZ_3_RECORDS_H
#define KDZ_3_RECORDS_H

void recordDijkstra(std::ofstream &file, const std::vector<std::vector<int>> &g, int start, int end, std::string name);

void recordFloyd(const std::vector<std::vector<int>> &g, int start, int end, std::string name);

void recordFord(const std::vector<std::vector<int>> &g, int start, int end, std::string name);

#endif //KDZ_3_RECORDS_H
