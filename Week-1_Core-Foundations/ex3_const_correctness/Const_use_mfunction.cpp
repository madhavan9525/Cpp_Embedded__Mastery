#include <iostream>
class Counter {
    // const int value;
    int value;
public:
    Counter(int v) : value(v) {}

    int get() const {
       //alue++;  // ❌ try uncommenting this line
        return value;   // ✅ allowed
    }

    void increment() {
        value++;        // ✅ allowed
    }
};


int main() {
       Counter c(10);
//    const Counter c(10);
    std::cout << "Initial value: " << c.get() << "\n"; // Outputs: 10
    c.increment();
    std::cout << "After increment: " << c.get() << "\n"; // Outputs: 11
}
