#include <iostream>
#include <cstddef>

int main() {
    int arr[] = {10, 20, 30, 40};
    std::size_t n = sizeof(arr) / sizeof(arr[0]);

    // array name decays to pointer to first element in expressions
    int *p = arr; // same as &arr[0]

    std::cout << "arr as address: " << static_cast<void*>(p) << "\n";
    std::cout << "&arr[0]:      " << static_cast<void*>(&arr[0]) << "\n";
    std::cout << "&arr[1]:      " << static_cast<void*>(&arr[1]) << "\n";

    // Pointer arithmetic advances by element size
    std::cout << "p = " << static_cast<void*>(p)
              << ", p+1 = " << static_cast<void*>(p+1)
              << ", difference in elements = " << (p+1 - p)
              << "\n";

    // Pointer subtraction -> ptrdiff_t (number of elements)
    std::ptrdiff_t diff = (&arr[3] - arr);
    std::cout << "(&arr[3] - arr) = " << diff << " elements\n";

    // One-past-the-end pointer is allowed for comparisons, but not dereference
    int *one_past = arr + n; // points just past last element
    std::cout << "last address: " << static_cast<void*>(&arr[n-1]) << "\n";
    std::cout << "one-past address: " << static_cast<void*>(one_past) << "\n";

    // Byte-wise arithmetic via char*
    char *byte_ptr = reinterpret_cast<char*>(arr);
    std::cout << "byte address of arr: " << static_cast<void*>(byte_ptr)
              << ", byte address + 1: " << static_cast<void*>(byte_ptr + 1)
              << " (difference in bytes = " << (byte_ptr + 1 - byte_ptr) << ")\n";

    // sizeof differences: sizeof(arr) gives total bytes, sizeof(&arr[0]) gives pointer size
    std::cout << "sizeof(arr) = " << sizeof(arr)
              << ", sizeof(arr[0]) = " << sizeof(arr[0]) << "\n";

    // Iterate using pointer arithmetic
    std::cout << "Elements via pointers: ";
    for (int *it = arr; it < arr + n; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}
