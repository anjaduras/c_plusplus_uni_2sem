#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

struct Faculty {
    std::string name;
    int numGroups;
    int totalStudents;
};

void writeDataToFile(const std::vector<Faculty>& faculties, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& faculty : faculties) {
            file << faculty.name << " " << faculty.numGroups << " " << faculty.totalStudents << std::endl;
        }
        file.close();
        std::cout << "Дані були успішно записані до файлу." << std::endl;
    } else {
        std::cout << "Помилка при відкритті файлу." << std::endl;
    }
}

std::vector<Faculty> readDataFromFile(const std::string& filename) {
    std::vector<Faculty> faculties;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            Faculty faculty;
            if (iss >> faculty.name >> faculty.numGroups >> faculty.totalStudents) {
                faculties.push_back(faculty);
            }
        }
        file.close();
        std::cout << "Дані були успішно зчитані з файлу." << std::endl;
    } else {
        std::cout << "Помилка при відкритті файлу." << std::endl;
    }
    return faculties;
}

void processFaculties(const std::vector<Faculty>& faculties) {
    std::map<int, std::vector<std::string>> studentCountMap;

    int totalStudents = 0;

    for (const auto& faculty : faculties) {
        studentCountMap[faculty.totalStudents].push_back(faculty.name);
        totalStudents += faculty.totalStudents;
    }

    std::cout << "Всього в університеті " << totalStudents << " студентів." << std::endl;

    std::cout << "Факультети з однаковою кількістю студентів:" << std::endl;
    for (const auto& entry : studentCountMap) {
        int studentCount = entry.first;
        const std::vector<std::string>& facultyNames = entry.second;

        if (facultyNames.size() > 1) {
            std::cout << "Кількість студентів (" << studentCount << "): ";
            for (size_t i = 0; i < facultyNames.size(); ++i) {
                std::cout << facultyNames[i];
                if (i < facultyNames.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    std::vector<Faculty> faculties = {
        {"ФМТ", 1, 124},
        {"ФПТ", 2, 102},
        {"ФІС", 2, 167},
        {"ФЕМ", 1, 124}
    };

    std::string filename = "faculties.txt";
    writeDataToFile(faculties, filename);

    std::vector<Faculty> readFaculties = readDataFromFile(filename);

    processFaculties(readFaculties);

    return 0;
}
