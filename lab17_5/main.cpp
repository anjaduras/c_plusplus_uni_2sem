#include <iostream>
#include <vector>
#include <cmath>
#include "array_operations.h"
#include "input_output.h"

int main() {
    std::vector<double> mas;
    input_mas(mas);

    int negative_count = count_negative_elements(mas);
    std::cout << "Кількість від'ємних елементів масиву: " << negative_count << std::endl;

    double sum_of_modulo = sum_of_modulo_after_min(mas);
    std::cout << "Сума модулів елементів масиву, розташованих після мінімального за модулем елемента: "
              << sum_of_modulo << std::endl;

    replace_negatives_with_squares(mas);
    sort_array(mas);
    print_mas(mas);

    return 0;
}
