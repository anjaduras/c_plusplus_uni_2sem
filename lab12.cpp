#include <iostream>
#include <fstream>
#include <ctime>

int main() {
    std::string inputFileName = "input.txt";
    std::string outputFileName = "output.txt";

    std::ifstream inputFile(inputFileName);
    if (inputFile.is_open()) {
        std::string line;
        std::string fileContent;

        while (std::getline(inputFile, line)) {
            fileContent += line + "\n";
        }

        inputFile.close();

        std::ofstream outputFile(outputFileName);
        if (outputFile.is_open()) {
            // Отримання об'єму файлу
            std::streampos fileSize = fileContent.size();

            // Отримання поточної дати та часу
            std::time_t currentTime = std::time(nullptr);

            // Запис назви файлу, об'єму файлу та дати створення у новий файл
            outputFile << "Назва файлу: " << inputFileName << std::endl;
            outputFile << "Об'єм файлу: " << fileSize << " байт" << std::endl;
            outputFile << "Дата створення: " << std::asctime(std::localtime(&currentTime)) << std::endl << std::endl;

            // Вивід результатів обробки по стрічках
            std::string processedContent; // Змінна для обробленого вмісту

            // Реалізуйте обробку стрічок змінної fileContent згідно завдання

            outputFile << processedContent; // Запис обробленого вмісту у новий файл

            outputFile.close();

            std::cout << "Результати обробки записані у файл: " << outputFileName << std::endl;
        } else {
            std::cout << "Помилка при відкритті файлу для запису: " << outputFileName << std::endl;
        }
    } else {
        std::cout << "Помилка при відкритті файлу для читання: " << inputFileName << std::endl;
    }

    return 0;
}
