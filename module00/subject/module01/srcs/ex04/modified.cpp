#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Function to read the entire content of a file into a string
std::string readFileContent(const std::string& filepath) {
    std::ifstream fileStream(filepath.c_str(), std::ios::in);
    std::stringstream buffer;
    buffer << fileStream.rdbuf(); // Read the file into the buffer
    return buffer.str(); // Convert the buffer into a string and return
}

// Function to replace all occurrences of a target character with another character in a string
std::string replaceNewlineWithCharacter(const std::string& text, char replaceWith) {
    std::string result = text;
    for (size_t pos = 0; pos < result.length(); ++pos) {
        if (result[pos] == '\n') {
            result[pos] = replaceWith; // Replace newline with the specified character
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <infile> <targetStr> <replaceStr>" << std::endl;
        return 1;
    }

    std::string infile = argv[1];
    std::string targetStr = argv[2];
    std::string replaceStr = argv[3];

    // Validate that targetStr is specifically a newline character
    if (targetStr != "\\n") {
        std::cerr << "This program is designed to replace newline characters only." << std::endl;
        return 1;
    }

    if (replaceStr.length() != 1) {
        std::cerr << "Replacement string must be a single character." << std::endl;
        return 1;
    }

    char replaceChar = replaceStr[0];

    std::string content = readFileContent(infile);
    std::string modifiedContent = replaceNewlineWithCharacter(content, replaceChar);

    std::string outfile = infile + ".replace";
    std::ofstream fdOutfile(outfile.c_str());
    if (!fdOutfile) {
        std::cerr << "Error opening outfile" << std::endl;
        return 1;
    }

    fdOutfile << modifiedContent; // Write the modified content to the outfile

    return 0;
}
