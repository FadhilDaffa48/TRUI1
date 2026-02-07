#ifndef TSV_HANDLER_H
#define TSV_HANDLER_H

#include "FileHandler.h"
#include <string>
#include <vector>

class TsvHandler : public FileHandler {
private:
    std::vector<std::string> headers;
    std::vector<std::vector<std::string>> rows;

    std::vector<std::string> split(const std::string& line, char delim);

public:
    bool load(std::string filename) override;

    std::vector<std::string> getColumn(std::string selector) override;

    void appendColumn(std::string newHeader,
                      const std::vector<std::string>& values) override;

    void save(std::string filename) override;
};

#endif
