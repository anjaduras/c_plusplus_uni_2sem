#include "array_operations.h"
#include <algorithm>
#include <cmath>
#include <iostream>

int count_negative_elements(const std::vector<double>& mas) {
    return std::count_if(mas.begin(), mas.end(), [](double num) {
        return num < 0;
    });
}

double sum_of_modulo_after_min(const std::vector<double>& mas) {
    auto min_it = std::min_element(mas.begin(), mas.end(), [](double a, double b) {
        return std::abs(a) < std::abs(b);
    });

    double sum = 0.0;
    bool add_sum = false;
    for (auto it = min_it; it != mas.end(); ++it) {
        if (add_sum) {
            sum += std::abs(*it);
        }
        if (it == min_it) {
            add_sum = true;
        }
    }
    return sum;
}

void replace_negatives_with_squares(std::vector<double>& mas) {
    std::transform(mas.begin(), mas.end(), mas.begin(), [](double num) {
        return num < 0 ? std::pow(num, 2) : num;
    });
}
void sort_array(std::vector<double>& mas) {
    std::sort(mas.begin(), mas.end());
}


