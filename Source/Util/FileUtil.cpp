#include "FileUtil.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

std::string getFileContent(const std::string& filePath, bool throws)
{
    std::ifstream inFile(filePath);
    if (!inFile.is_open())
    {
        std::string error = "Unable to open file: " + filePath + "!";
        if (throws)
        {
            throw std::runtime_error(error);
        }
        else
        {
            std::cerr << error << '\n';
        }
    }

    std::ostringstream stream;
    stream << inFile.rdbuf();
    return stream.str();
}
