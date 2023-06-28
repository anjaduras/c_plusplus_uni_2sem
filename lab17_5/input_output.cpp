#include <iostream>
#include "input_output.h"

void input_mas(std::vector<double>& mas) {
    int n;
    std::cout << "Кількість елементів масиву: ";
    std::cin >> n;
    mas.resize(n);
    for (int i = 0; i < n; i++) {
        std::cout << "X[" << i << "]= ";
        std::cin >> mas[i];
    }
}

void print_mas(const std::vector<double>& mas) {
    std::cout << "Масив:" << std::endl;
    for (int i = 0; i < mas.size(); i++) {
        std::cout << mas[i] << " ";
    }
    std::cout << std::endl;
}