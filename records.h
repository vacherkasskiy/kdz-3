//
// Created by cherk on 14.06.2023.
//

#ifndef KDZ_3_RECORDS_H
#define KDZ_3_RECORDS_H

void recordDijkstra(std::ofstream &file, const std::vector<std::vector<int>> &g, int start, int numEdges, int end, const std::string& name);

void recordFloyd(std::ofstream &file, const std::vector<std::vector<int>> &g, int start, int end, int numEdges, const std::string& name);

void recordFord(std::ofstream &file, const std::vector<std::vector<int>> &g, int start, int end, int numEdges, const std::string& name);

#endif //KDZ_3_RECORDS_H
