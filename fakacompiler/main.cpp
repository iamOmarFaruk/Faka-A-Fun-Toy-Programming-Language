#include "faka_compiler.cpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file.faka>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    
    // Check file extension
    if (filename.substr(filename.find_last_of(".") + 1) != "faka") {
        std::cerr << "Error: File must have .faka extension" << std::endl;
        return 1;
    }

    FakaCompiler compiler;
    if (!compiler.loadFile(filename)) {
        return 1;
    }

    if (!compiler.compile()) {
        return 1;
    }

    std::cout << "Program executed successfully!" << std::endl;
    return 0;
} 