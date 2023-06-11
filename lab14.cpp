#include <iostream>
#include <string>

using namespace std;

int divs(int N, int divisor = 2, int count = 0) {
    if (divisor >= N) {
        return count;
    }

    if (N % divisor == 0) {
        ++count;
    }

    return divs(N, divisor + 1, count);
}

int main() {
    int result = divs(18);
    std::cout << "divs(18) = " << result << std::endl; // Виведе: divs(18) = 4

    return 0;
}
