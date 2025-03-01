#ifndef FAKA_COMMENT_H
#define FAKA_COMMENT_H

#include <string>
#include <vector>

namespace faka {

    /**
     * Processes a Faka source code string to handle comments.
     * Comments in Faka start with '//' and end with '\\'.
     * Comments can span multiple lines.
     * 
     * @param source The source code to process
     * @return The source code with comments removed
     */
    std::string process_comments(const std::string& source) {
        std::string processed;
        bool in_comment = false;
        
        for (size_t i = 0; i < source.length(); ++i) {
            // Check for comment start
            if (i + 1 < source.length() && source[i] == '/' && source[i + 1] == '/') {
                in_comment = true;
                i++; // Skip the second '/'
                continue;
            }
            
            // Check for comment end
            if (in_comment && i + 1 < source.length() && source[i] == '\\' && source[i + 1] == '\\') {
                in_comment = false;
                i++; // Skip the second '\'
                continue;
            }
            
            // Only add characters to processed string if not in a comment
            if (!in_comment) {
                processed += source[i];
            }
        }
        
        return processed;
    }

    /**
     * Processes a vector of lines to handle comments.
     * This is an alternative approach that works line by line.
     * 
     * @param lines Vector of source code lines
     * @return Vector of processed lines with comments removed
     */
    std::vector<std::string> process_comments_by_lines(const std::vector<std::string>& lines) {
        std::vector<std::string> processed_lines;
        std::string current_line;
        bool in_comment = false;
        
        for (const auto& line : lines) {
            current_line = "";
            
            for (size_t i = 0; i < line.length(); ++i) {
                // Check for comment start
                if (!in_comment && i + 1 < line.length() && line[i] == '/' && line[i + 1] == '/') {
                    in_comment = true;
                    i++; // Skip the second '/'
                    continue;
                }
                
                // Check for comment end
                if (in_comment && i + 1 < line.length() && line[i] == '\\' && line[i + 1] == '\\') {
                    in_comment = false;
                    i++; // Skip the second '\'
                    continue;
                }
                
                // Only add characters if not in a comment
                if (!in_comment) {
                    current_line += line[i];
                }
            }
            
            processed_lines.push_back(current_line);
        }
        
        return processed_lines;
    }

} // namespace faka

#endif // FAKA_COMMENT_H 