#include <iostream>

int sum(const int& a, const int& b) {
    //a++;   // ❌ try uncommenting this line
    return a + b;
}

int main() {
    int x = 5;
    int y = 7;

    std::cout << sum(x, y) << "\n";
}

