#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <regex>
#include <functional>
#include "faka_arithmetic.h"
#include "faka_comment.h"

enum class Type { INT, STRING, BOOLEAN };

struct Variable {
    std::string name;
    Type type;
    std::string value;
};

class FakaCompiler {
private:
    std::map<std::string, Variable> variables;
    std::vector<std::string> lines;
    bool started = false;
    bool ended = false;

public:
    bool loadFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return false;
        }

        std::string fileContent;
        std::string line;
        while (std::getline(file, line)) {
            fileContent += line + "\n";
        }
        file.close();
        
        // Process comments before parsing
        fileContent = faka::process_comments(fileContent);
        
        // Split the processed content into lines
        std::istringstream contentStream(fileContent);
        lines.clear();
        while (std::getline(contentStream, line)) {
            lines.push_back(line);
        }
        
        return true;
    }

    bool compile() {
        for (const std::string& line : lines) {
            std::string trimmed = trim(line);
            
            if (trimmed.empty()) continue;

            if (trimmed == "faka start") {
                started = true;
                continue;
            }
            
            if (trimmed == "faka end") {
                ended = true;
                break;
            }

            if (!started) {
                std::cerr << "Error: Code outside faka start/end block" << std::endl;
                return false;
            }

            // Variable declaration
            if (trimmed.find("variable will be") != std::string::npos) {
                if (!processVariableDeclaration(trimmed)) {
                    return false;
                }
            }
            // Print statement
            else if (trimmed.find("print") == 0) {
                if (!processPrintStatement(trimmed)) {
                    return false;
                }
            }
            // Arithmetic operation
            else if (trimmed.find("calculate") == 0 && trimmed.find("will be") != std::string::npos) {
                if (!processArithmeticOperation(trimmed)) {
                    return false;
                }
            }
            else {
                std::cerr << "Error: Unknown statement: " << trimmed << std::endl;
                return false;
            }
        }

        if (!started || !ended) {
            std::cerr << "Error: Missing faka start or faka end" << std::endl;
            return false;
        }

        return true;
    }

private:
    bool processVariableDeclaration(const std::string& line) {
        // Parse variable declaration: NAME variable will be TYPE = VALUE.
        std::regex pattern("(\\w+) variable will be (\\w+) = (.+)\\.");
        std::smatch matches;
        
        if (std::regex_search(line, matches, pattern) && matches.size() == 4) {
            std::string name = matches[1].str();
            std::string type_str = matches[2].str();
            std::string value = matches[3].str();
            
            Type type;
            if (type_str == "int") {
                type = Type::INT;
                // Validate int
                try {
                    std::stoi(value);
                } catch (...) {
                    std::cerr << "Error: Invalid int value: " << value << std::endl;
                    return false;
                }
            } 
            else if (type_str == "string") {
                type = Type::STRING;
                // Remove quotes if present
                if (value.front() == '"' && value.back() == '"') {
                    value = value.substr(1, value.length() - 2);
                }
            } 
            else if (type_str == "boolean") {
                type = Type::BOOLEAN;
                // Validate boolean
                if (value != "true" && value != "false") {
                    std::cerr << "Error: Invalid boolean value: " << value << std::endl;
                    return false;
                }
            } 
            else {
                std::cerr << "Error: Unknown type: " << type_str << std::endl;
                return false;
            }
            
            variables[name] = {name, type, value};
            return true;
        }
        
        std::cerr << "Error: Invalid variable declaration: " << line << std::endl;
        return false;
    }

    bool processPrintStatement(const std::string& line) {
        // Parse print statement: print NAME.
        std::regex pattern("print (\\w+)\\.");
        std::smatch matches;
        
        if (std::regex_search(line, matches, pattern) && matches.size() == 2) {
            std::string name = matches[1].str();
            
            if (variables.find(name) == variables.end()) {
                std::cerr << "Error: Variable not found: " << name << std::endl;
                return false;
            }
            
            // Store print command for execution
            std::cout << variables[name].value << std::endl;
            return true;
        }
        
        std::cerr << "Error: Invalid print statement: " << line << std::endl;
        return false;
    }

    bool processArithmeticOperation(const std::string& line) {
        // Parse arithmetic statement: calculate RESULT will be TYPE = EXPRESSION.
        std::regex pattern("calculate (\\w+) will be (\\w+) = (.+)\\.");
        std::smatch matches;
        
        if (std::regex_search(line, matches, pattern) && matches.size() == 4) {
            std::string result_var = matches[1].str();
            std::string type_str = matches[2].str();
            std::string expression = matches[3].str();
            
            // Verify type is int
            if (type_str != "int") {
                std::cerr << "Error: Arithmetic operations can only result in int type" << std::endl;
                return false;
            }
            
            try {
                // Create lambda functions to access variables
                auto getVarValue = [this](const std::string& name) -> std::string {
                    return this->variables[name].value;
                };
                
                auto checkVarExists = [this](const std::string& name) -> bool {
                    return this->variables.find(name) != this->variables.end();
                };
                
                // Evaluate the expression
                std::string result = faka::ArithmeticProcessor::evaluateExpression(
                    expression, getVarValue, checkVarExists);
                
                // Store the result in a new variable
                variables[result_var] = {result_var, Type::INT, result};
                return true;
            } catch (const std::runtime_error& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return false;
            }
        }
        
        std::cerr << "Error: Invalid arithmetic statement: " << line << std::endl;
        return false;
    }

    std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(" \t");
        if (first == std::string::npos) return "";
        size_t last = str.find_last_not_of(" \t");
        return str.substr(first, (last - first + 1));
    }
};