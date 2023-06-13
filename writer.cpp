//
// Created by cherk on 14.06.2023.
//

#include <fstream>
#include "writer.h"

void writeCsv(std::ofstream &file, const std::string &name, long long sum, int edgesAmount, int ribsAmount) {
    file << name << ";" << sum << ";" << edgesAmount << ";" << ribsAmount << "\n";
}