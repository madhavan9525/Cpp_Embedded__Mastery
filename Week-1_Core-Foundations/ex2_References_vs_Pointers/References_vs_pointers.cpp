#include <iostream>

void increment_ref(int& x) {
    x++;
}

void increment_ptr(int* x) {
    (*x)++;
}

int main() {
    int a = 10;
    int b = 10;

    increment_ref(a);
    //increment_ptr(&b);
    increment_ptr(nullptr);


    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
}

