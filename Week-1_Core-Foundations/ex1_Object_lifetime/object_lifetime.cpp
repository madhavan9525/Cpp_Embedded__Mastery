#include <iostream>

class Led {
public:
    Led() {
        std::cout << "LED ON\n";
    }
      void blink() {
        std::cout << "LED BLINK\n";
    }

    ~Led() {
        std::cout << "LED OFF\n";
    }
};

void test() {
    // Led A;
    // std::cout << "Inside test()\n";

    std::cout << "test() start\n";

    {
        Led l;
        l.blink();
        std::cout << "Inside inner scope\n";
    } // 👈 scope ends HERE
    // l.blink(); // ERROR: 'l' is out of scope here

    std::cout << "test() end\n";

}

int main() {
    std::cout << "Main start\n";
    test();
    std::cout << "Main end\n";
}
