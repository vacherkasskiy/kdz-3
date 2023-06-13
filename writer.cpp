//
// Created by cherk on 14.06.2023.
//

#include <fstream>
#include "writer.h"

void writeCsv(std::ofstream &file, const std::string &name, int edgesAmount, int ribsAmount) {
    file << name << ";" << edgesAmount << ";" << ribsAmount << "\n";
}