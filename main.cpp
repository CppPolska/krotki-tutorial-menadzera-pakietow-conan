#include <iostream>
#include <fstream>
#include <sstream>
#include <Poco/Base64Encoder.h>

std::string readFile(std::string path) {
    std::ifstream input(path);
    if (!input.good()) {
        throw std::exception();
    }

    return std::string((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
}

std::string base64Encode(std::string input) {
    std::stringstream stream;
    stream.str("");

    Poco::Base64Encoder encoder(stream);
    encoder << input;
    encoder.close();

    return stream.str();
}

int main(int argc, char* argv[]) {
    try {
        if (argc < 2) {
            std::cerr << "No input file specified";
            return -1;
        }

        std::string fileContent = readFile(argv[1]);
        std::string base64Output = base64Encode(fileContent);
        std::cout << base64Output << std::endl;
        return 0;
    } catch (std::exception &e) {
        std::cerr << "Input file is not readable or does not exist";
        return -2;
    }
}