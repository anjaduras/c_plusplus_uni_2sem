#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

// ANSI color codes
const std::string COLOR_RESET = "\033[0m";
const std::string COLOR_LIGHT_GREEN = "\033[1;32m";
const std::string COLOR_RED = "\033[1;31m";

struct Client {
    std::string phoneNumber;
    std::string name;
    std::string date;
    std::string typeOfWorks;
};

std::vector<Client> readClientsFromFile(const std::string& filename) {
    std::vector<Client> clients;

    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string phoneNumber, name, date, typeOfWorks;
            if (std::getline(iss, phoneNumber, ',') &&
                std::getline(iss, name, ',') &&
                std::getline(iss, date, ',') &&
                std::getline(iss, typeOfWorks)) {
                clients.push_back({phoneNumber, name, date, typeOfWorks});
            }
        }
        file.close();
    }

    return clients;
}

void writeClientsToFile(const std::string& filename, const std::vector<Client>& clients) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& client : clients) {
            file << client.phoneNumber << ',' << client.name << ',' << client.date << ',' << client.typeOfWorks << '\n';
        }
        file.close();
    }
}

void addClient(std::vector<Client>& clients) {
    std::string phoneNumber, name, date, typeOfWorks;

    std::cout << '\n';
    std::cout << "  Будь ласка, введіть номер телефону замовника: ";
    std::getline(std::cin, phoneNumber);

    std::cout << '\n';
    std::cout << "  Введіть ім'я замовника: ";
    std::getline(std::cin, name);

    std::cout << '\n';
    std::cout << "  Введіть дату замовлення(РРРР-ММ-ДД): ";
    std::getline(std::cin, date);

    std::cout << '\n';
    std::cout << "  Введіть вид робіт: ";
    std::getline(std::cin, typeOfWorks);

    clients.push_back({phoneNumber, name, date, typeOfWorks});

    std::cout << '\n';
    std::cout << COLOR_LIGHT_GREEN << "  Нового замовника успішно додано." << COLOR_RESET << '\n';
}

void editClient(std::vector<Client>& clients) {
    std::string phoneNumber;

    std::cout << '\n';
    std::cout << "  Введіть номер телефону замовника для редагування: ";
    std::getline(std::cin, phoneNumber);

    auto it = std::find_if(clients.begin(), clients.end(), [&](const Client& client) {
        return client.phoneNumber == phoneNumber;
    });

    if (it != clients.end()) {
        std::string name, date, typeOfWorks;

        std::cout << "  Введіть нове ім'я: ";
        std::getline(std::cin, name);

        std::cout << "  Введіть нову дату: ";
        std::getline(std::cin, date);

        std::cout << "  Введіть новий вид робіт: ";
        std::getline(std::cin, typeOfWorks);

        it->name = name;
        it->date = date;
        it->typeOfWorks = typeOfWorks;

        std::cout << '\n';
        std::cout << COLOR_LIGHT_GREEN << "  Дані замовника успішно оновлено." << COLOR_RESET << '\n';
    } else {
        std::cout << '\n';
        std::cout << COLOR_RED << "  Замовника не знайдено." << COLOR_RESET << '\n';
    }
}

void searchClients(const std::vector<Client>& clients) {
    std::string keyword;
    std::cout << '\n';
    std::cout << "Введіть ключове слово для пошуку: ";
    std::getline(std::cin, keyword);

    std::vector<Client> searchResults;

    for (const auto& client : clients) {
        if (client.phoneNumber.find(keyword) != std::string::npos ||
            client.name.find(keyword) != std::string::npos ||
            client.date.find(keyword) != std::string::npos ||
            client.typeOfWorks.find(keyword) != std::string::npos) {
            searchResults.push_back(client);
        }
    }

    if (!searchResults.empty()) {
        std::cout << "Search results:\n";
        for (const auto& client : searchResults) {
            std::cout << "  Телефон замовника: " << COLOR_LIGHT_GREEN << client.phoneNumber << COLOR_RESET << '\n';
            std::cout << "  Ім'я замовника: " << COLOR_LIGHT_GREEN << client.name << COLOR_RESET << '\n';
            std::cout << "  Дата замовлення: " << COLOR_RED << client.date << COLOR_RESET << '\n';
            std::cout << "  Тип будівельних робіт: " << client.typeOfWorks << '\n';
            std::cout << '\n';
        }
    } else {
        std::cout << '\n';
        std::cout << "  Замовників не знайдено.\n";
    }
}

void displayClients(const std::vector<Client>& clients) {
    if (!clients.empty()) {
        std::cout << '\n';
        std::cout << "       СПИСОК ЗАМОВНИКІВ: " << '\n' ;
        std::cout << '\n';
        for (const auto& client : clients) {
            std::cout << "****************************" << '\n';
            std::cout << "  Телефон замовника: " << COLOR_LIGHT_GREEN << client.phoneNumber << COLOR_RESET << '\n';
            std::cout << "  Ім'я замовника: " << COLOR_LIGHT_GREEN << client.name << COLOR_RESET << '\n';
            std::cout << "  Дата замовлення: " << COLOR_RED << client.date << COLOR_RESET << '\n';
            std::cout << "  Тип будівельних робіт: " << client.typeOfWorks << '\n';
            std::cout << '\n';
        }
    } else {
        std::cout << '\n';
        std::cout << "  Замовників не знайдено.\n";
    }
}

int main() {
    std::vector<Client> clients;

    // Load clients from file
    clients = readClientsFromFile("clients.csv");

    while (true) {
        std::cout << '\n';
        std::cout << "       МЕНЮ БД БУДІВЕЛЬНОЇ ФІРМИ" << '\n';
        std::cout << '\n';
        std::cout << "  1. Додати нового замовника\n";
        std::cout << "  2. Редагувати дані замовника\n";
        std::cout << "  3. Шукати замовника в базі\n";
        std::cout << "  4. Переглянути список замовників\n";
        std::cout << "  5. Вихід\n";
        std::cout << '\n';

        std::string choice;
        std::cout << "  Будь ласка, вкажіть ваш вибір: ";
        std::getline(std::cin, choice);

        if (choice == "1") {
            addClient(clients);
        } else if (choice == "2") {
            editClient(clients);
        } else if (choice == "3") {
            searchClients(clients);
        } else if (choice == "4") {
            displayClients(clients);
        } else if (choice == "5") {
            // Save clients to file
            writeClientsToFile("clients.csv", clients);
            break;
        } else {
            std::cout << '\n';
            std::cout << "Невірний вибір. Будь ласка спробуйте ще раз.\n";
        }

        std::cout << '\n';
    }

    return 0;
}
