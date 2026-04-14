#include <iostream>
#include <string>
#include <stdexcept>
#include "utils.hpp"

int main() {
    std::string email;
    while (true) {
        std::cout << "Enter your email address: ";
        std::cin >> email;
        try {
            check_email(email);
            std::cout << "Valid email entered. Exiting..." << std::endl;
            break;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << " Please try again.\n";
        }
    }
    return 0;
}
