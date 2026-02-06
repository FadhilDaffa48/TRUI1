#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>
#include <fstream>

class FileHandler {
public:
    virtual bool load(std::string filename) = 0;
    
    virtual std::vector<std::string> getColumn(std::string selector) = 0;

    virtual void appendColumn(std::string newHeader, const std::vector<std::string>& values) = 0;

    virtual void save(std::string filename) = 0;

    virtual ~FileHandler() = default;
};

#endif