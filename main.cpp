#include <iostream>
#include <fstream>
#include <sstream>
#include <Poco/Base64Encoder.h>

std::string readFile(const std::string &path) {
    std::ifstream input(path);
    if (!input.good()) {
        throw std::runtime_error(path + ": File doesn't exist");
    }

    return std::string((std::istreambuf_iterator<char>(input)), std::istreambuf_iterator<char>());
}

std::string base64Encode(const std::string &input) {
    std::stringstream stream;

    Poco::Base64Encoder encoder(stream);
    encoder << input;
    encoder.close();

    return stream.str();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "No input file specified";
        return -1;
    }

    try {
        const std::string fileContent = readFile(argv[1]);
        const std::string base64Output = base64Encode(fileContent);
        std::cout << base64Output << std::endl;
        return 0;
    } catch (std::runtime_error &e) {
        std::cerr << e.what();
        return -2;
    }
}