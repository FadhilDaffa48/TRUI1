#include "TsvHandler.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<std::string> TsvHandler::split(const std::string& line, char delim) {
    std::vector<std::string> out;
    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, delim)) out.push_back(item);
    return out;
}

bool TsvHandler::load(std::string filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cerr << "Error: Could not open " << filename << "\n";
        return false;
    }

    headers.clear();
    rows.clear();

    std::string line;

    // header line
    if (!std::getline(in, line)) {
        std::cerr << "Error: Empty file\n";
        return false;
    }
    headers = split(line, '\t');

    // data lines
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        rows.push_back(split(line, '\t'));
    }

    return true;
}

std::vector<std::string> TsvHandler::getColumn(std::string selector) {
    std::vector<std::string> col;

    int idx = -1;
    try {
        idx = std::stoi(selector); // selector kamu memang index string
    } catch (...) {
        std::cerr << "Error: Column Index must be a number\n";
        return col;
    }

    if (idx < 0 || idx >= (int)headers.size()) {
        std::cerr << "Error: Column index out of range\n";
        return col;
    }

    col.reserve(rows.size());
    for (const auto& r : rows) {
        if (idx < (int)r.size()) col.push_back(r[idx]);
        else col.push_back("");
    }

    return col;
}

void TsvHandler::appendColumn(std::string newHeader, const std::vector<std::string>& values) {
    headers.push_back(newHeader);

    // pastikan setiap row punya slot baru
    for (size_t i = 0; i < rows.size(); ++i) {
        if (i < values.size()) rows[i].push_back(values[i]);
        else rows[i].push_back("Error");
    }
}

void TsvHandler::save(std::string filename) {
    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cerr << "Error: Could not write " << filename << "\n";
        return;
    }

    // write headers
    for (size_t i = 0; i < headers.size(); ++i) {
        out << headers[i];
        if (i + 1 < headers.size()) out << '\t';
    }
    out << "\n";

    // write rows
    for (const auto& r : rows) {
        for (size_t i = 0; i < headers.size(); ++i) {
            if (i < r.size()) out << r[i];
            if (i + 1 < headers.size()) out << '\t';
        }
        out << "\n";
    }
}
