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
    increment_ptr(&b);
    //increment_ptr(nullptr);//causes segmentaion fault as the pointer is null and we are trying to dereference it


    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";
}

