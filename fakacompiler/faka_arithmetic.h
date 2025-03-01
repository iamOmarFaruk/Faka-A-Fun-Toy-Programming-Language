#ifndef FAKA_ARITHMETIC_H
#define FAKA_ARITHMETIC_H

#include <string>
#include <stdexcept>
#include <functional>

namespace faka {

class ArithmeticProcessor {
public:
    // Perform addition between two integers
    static int add(int a, int b) {
        return a + b;
    }
    
    // Perform subtraction between two integers
    static int subtract(int a, int b) {
        return a - b;
    }
    
    // Parse and evaluate a simple arithmetic expression
    // Currently supports only: VAR1 + VAR2 or VAR1 - VAR2
    static std::string evaluateExpression(const std::string& expr, 
                                         const std::function<std::string(const std::string&)>& getVarValue,
                                         const std::function<bool(const std::string&)>& checkVarExists) {
        // Find operator position
        size_t add_pos = expr.find('+');
        size_t sub_pos = expr.find('-');
        
        size_t op_pos = std::string::npos;
        char op = '\0';
        
        if (add_pos != std::string::npos) {
            op_pos = add_pos;
            op = '+';
        } else if (sub_pos != std::string::npos) {
            op_pos = sub_pos;
            op = '-';
        } else {
            throw std::runtime_error("No arithmetic operator found in expression");
        }
        
        // Extract variable names
        std::string left_var = expr.substr(0, op_pos);
        std::string right_var = expr.substr(op_pos + 1);
        
        // Trim whitespace
        left_var = trim(left_var);
        right_var = trim(right_var);
        
        // Check if variables exist
        if (!checkVarExists(left_var)) {
            throw std::runtime_error("Variable not found: " + left_var);
        }
        if (!checkVarExists(right_var)) {
            throw std::runtime_error("Variable not found: " + right_var);
        }
        
        // Get variable values
        std::string left_val = getVarValue(left_var);
        std::string right_val = getVarValue(right_var);
        
        // Perform operation
        try {
            int left_int = std::stoi(left_val);
            int right_int = std::stoi(right_val);
            
            int result;
            if (op == '+') {
                result = add(left_int, right_int);
            } else if (op == '-') {
                result = subtract(left_int, right_int);
            } else {
                throw std::runtime_error("Unsupported operator");
            }
            
            return std::to_string(result);
        } catch (const std::invalid_argument&) {
            throw std::runtime_error("Cannot perform arithmetic on non-integer values");
        }
    }
    
private:
    // Helper function to trim whitespace
    static std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(" \t");
        if (first == std::string::npos) return "";
        size_t last = str.find_last_not_of(" \t");
        return str.substr(first, (last - first + 1));
    }
};

} // namespace faka

#endif // FAKA_ARITHMETIC_H 