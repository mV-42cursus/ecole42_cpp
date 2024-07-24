#include <iostream>
#include <fstream>
#include <string>

std::string manipulateStr(const std::string &line, const std::string &targetStr, const std::string &replaceStr)
{
    std::string res = line;
    size_t pos = 0;

    if (targetStr.empty())
        return line;
    while ((pos = res.find(targetStr, pos)) != std::string::npos)
    {
        res.replace(pos, targetStr.length(), replaceStr);
        pos += replaceStr.length();
    }
    return res;
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <infile> <targetStr> <replaceStr>" << std::endl;
        return 1;
    }
    std::string infile = argv[1];
    std::string outfile = infile + ".replace";
    std::ifstream fdInfile(infile.c_str());
    if (!fdInfile) {
        std::cerr << "Error opening infile" << std::endl;
        return 1;
    }

    std::ofstream fdOutfile(outfile.c_str());
    if (!fdOutfile) {
        std::cerr << "Error opening outfile" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(fdInfile, line))
        fdOutfile << manipulateStr(line, argv[2], argv[3]) << std::endl;
    return 0;
}
