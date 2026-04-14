#include "utils.hpp"
#include <regex>
#include <stdexcept>

void check_email(const std::string& email) {
    std::regex pattern(R"([a-zA-Z0-9._%+-]+@(email|gmail|yahoo|hotmail|outlook)+.com)");
    if (!std::regex_match(email, pattern)) {
        throw std::invalid_argument("Invalid email format");
    }
}
