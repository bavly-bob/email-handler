#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include "utils.hpp"

int main() {
    std::map<std::string, std::string> users;
    bool is_logged_in = false;
    std::string current_user = "";

    while (true) {
        std::cout << "\n--- Menu ---\n";
        if (!is_logged_in) {
            std::cout << "1. Sign up\n";
            std::cout << "2. Login\n";
        } else {
            std::cout << "3. Logout\n";
        }
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 0) {
            std::cout << "Exiting program.\n";
            break;
        }

        if (!is_logged_in) {
            if (choice == 1) { // Sign up
                std::string email, password;
                std::cout << "Enter email: ";
                std::cin >> email;
                try {
                    check_email(email);
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << "\n";
                    continue;
                }

                if (users.find(email) != users.end()) {
                    std::cout << "User already exists.\n";
                    continue;
                }

                std::cout << "Enter password: ";
                std::cin >> password;
                users[email] = password;
                std::cout << "Sign up successful.\n";
            } else if (choice == 2) { // Login
                std::string email, password;
                std::cout << "Enter email: ";
                std::cin >> email;
                std::cout << "Enter password: ";
                std::cin >> password;

                auto it = users.find(email);
                if (it != users.end() && it->second == password) {
                    is_logged_in = true;
                    current_user = email;
                    std::cout << "Login successful. Welcome " << current_user << "!\n";
                } else {
                    std::cout << "Invalid email or password.\n";
                }
            } else {
                std::cout << "Invalid option.\n";
            }
        } else { // Logged in
            if (choice == 3) { // Logout
                is_logged_in = false;
                current_user = "";
                std::cout << "Logged out successfully.\n";
            } else {
                std::cout << "Invalid option.\n";
            }
        }
    }

    return 0;
}
