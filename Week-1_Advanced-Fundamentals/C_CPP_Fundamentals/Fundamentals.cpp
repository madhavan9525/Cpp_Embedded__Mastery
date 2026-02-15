#include<iostream>
#include<climits>
using namespace std;

// Global variable
int globalVar;

// ========== DEMONSTRATING STATIC VARIABLES ==========
// Static function - demonstrates static variable persistence
void demonstrateStaticVariable() {
    static int callCount = 0;  // Initialized only once, retains value between calls
    callCount++;
    cout << "Function called " << callCount << " times" << endl;
}

// ========== DEMONSTRATING CONST VARIABLES ==========
// Function to demonstrate const parameters
void printConstValue(const int value) {
    cout << "Const parameter value: " << value << endl;
    // value = 10;  // ERROR: Cannot modify a const parameter
}

// ========== DEMONSTRATING REFERENCES ==========
// C++ specific: Reference parameter (cannot be nullptr)
void modifyByReference(int& refVar) {
    refVar = refVar * 2;
}

// ========== DEMONSTRATING CONST REFERENCES ==========
void printByConstReference(const int& constRefVar) {
    cout << "Const reference value: " << constRefVar << endl;
    // constRefVar = 50;  // ERROR: Cannot modify through const reference
}

int main() {
    // ========== BASIC VARIABLE TYPES IN C++ ==========
    
    cout << "======== FUNDAMENTAL DATA TYPES IN C++ ========\n" << endl;
    
    // 1. INTEGER TYPES
    cout << "1. INTEGER TYPES:" << endl;
    int myInt = 42;
    short myShort = 100;
    long myLong = 1000000;
    unsigned int myUnsignedInt = 50;
    
    cout << "int: " << myInt << " (size: " << sizeof(int) << " bytes)" << endl;
    cout << "short: " << myShort << " (size: " << sizeof(short) << " bytes)" << endl;
    cout << "long: " << myLong << " (size: " << sizeof(long) << " bytes)" << endl;
    cout << "unsigned int: " << myUnsignedInt << " (size: " << sizeof(unsigned int) << " bytes)" << "\n" << endl;
    
    // 2. FLOATING POINT TYPES
    cout << "2. FLOATING POINT TYPES:" << endl;
    float myFloat = 3.14f;
    double myDouble = 3.14159265;
    
    cout << "float: " << myFloat << " (size: " << sizeof(float) << " bytes)" << endl;
    cout << "double: " << myDouble << " (size: " << sizeof(double) << " bytes)" << "\n" << endl;
    
    // 3. CHARACTER TYPE
    cout << "3. CHARACTER TYPE:" << endl;
    char myChar = 'A';
    cout << "char: " << myChar << " (ASCII value: " << (int)myChar << ", size: " << sizeof(char) << " bytes)" << "\n" << endl;
    
    // 4. BOOLEAN TYPE (C++ has native bool)
    cout << "4. BOOLEAN TYPE (C++ native):" << endl;
    bool myBool = true;
    cout << "bool: " << (myBool ? "true" : "false") << " (size: " << sizeof(bool) << " bytes)" << "\n" << endl;
    
    // ========== VARIABLE SCOPE ==========
    cout << "======== VARIABLE SCOPE ========" << endl;
    cout << "Global variable 'globalVar' value: " << globalVar << endl;  // Global variable initialized to 0
    
    int localVar = 100;  // Local variable (scope limited to main function)
    cout << "Local variable 'localVar': " << localVar << "\n" << endl;
    
    // ========== DETAILED EXPLANATION: STATIC VARIABLES ==========
    cout << "======== STATIC VARIABLES - DETAILED EXPLANATION ========" << endl;
    cout << "Static variables are initialized only ONCE and retain their value between function calls." << endl;
    cout << "They are stored in the data segment of memory (not on the stack).\n" << endl;
    
    cout << "Calling demonstrateStaticVariable():" << endl;
    demonstrateStaticVariable();  // callCount = 1
    demonstrateStaticVariable();  // callCount = 2 (retained from previous call!)
    demonstrateStaticVariable();  // callCount = 3
    cout << "Note: The static variable 'callCount' retains its value across function calls.\n" << endl;
    
    // Local static variable example
    cout << "Local static variable example:" << endl;
    static int localStaticVar = 10;
    cout << "Local static var before: " << localStaticVar << endl;
    localStaticVar += 5;
    cout << "Local static var after modification: " << localStaticVar << "\n" << endl;
    
    // ========== DETAILED EXPLANATION: CONST VARIABLES ==========
    cout << "======== CONST VARIABLES - DETAILED EXPLANATION ========" << endl;
    cout << "Const variables are IMMUTABLE - their values cannot be changed after initialization." << endl;
    cout << "They provide data protection and make code safer and more predictable.\n" << endl;
    
    // 1. Const variable
    cout << "1. CONST VARIABLE (immutable value):" << endl;
    const int myConstant = 42;
    cout << "Const variable value: " << myConstant << endl;
    // myConstant = 50;  // ERROR: Assignment of read-only variable
    cout << "Cannot modify a const variable after initialization.\n" << endl;
    
    // 2. Const with pointers
    cout << "2. CONST WITH POINTERS:" << endl;
    int normalVar = 100;
    
    // Const pointer (pointer value is const, but what it points to can change)
    int * const constPointer = &normalVar;
    cout << "Const pointer value: " << *constPointer << " (pointing to normalVar)" << endl;
    // constPointer = &myInt;  // ERROR: Cannot change pointer address
    *constPointer = 150;  // OK: Can change the value it points to
    cout << "After modification through const pointer: " << normalVar << "\n" << endl;
    
    // Pointer to const (pointer can change, but value it points to cannot)
    const int * pointerToConst = &myConstant;
    cout << "Pointer to const value: " << *pointerToConst << endl;
    pointerToConst = &normalVar;  // OK: Can change pointer address
    // *pointerToConst = 200;  // ERROR: Cannot modify const value through pointer
    cout << "Pointer reassigned to point to normalVar: " << *pointerToConst << "\n" << endl;
    
    // 3. Const in function parameters
    cout << "3. CONST IN FUNCTION PARAMETERS:" << endl;
    printConstValue(50);  // Function won't modify the parameter
    cout << "Parameter protection: function cannot modify const parameters.\n" << endl;
    
    // 4. Const with arrays
    cout << "4. CONST WITH ARRAYS:" << endl;
    const int constArray[] = {10, 20, 30, 40, 50};
    cout << "Const array: [" << constArray[0] << ", " << constArray[1] << ", " 
         << constArray[2] << ", " << constArray[3] << ", " << constArray[4] << "]" << endl;
    // constArray[0] = 99;  // ERROR: Cannot modify array elements
    cout << "Cannot modify elements of a const array.\n" << endl;
    
    // ========== C++ SPECIFIC FEATURES: REFERENCES ==========
    cout << "======== C++ SPECIFIC: REFERENCES ========" << endl;
    cout << "References are safer alternatives to pointers." << endl;
    cout << "They cannot be null and must be initialized.\n" << endl;
    
    int originalValue = 25;
    int& refVar = originalValue;  // Reference to originalValue
    cout << "Original value: " << originalValue << endl;
    cout << "Reference value: " << refVar << endl;
    refVar = 30;  // Modifying through reference
    cout << "After modifying through reference: " << originalValue << "\n" << endl;
    
    // Modifying by reference
    cout << "5. REFERENCES IN FUNCTION PARAMETERS:" << endl;
    cout << "Original value before function: " << originalValue << endl;
    modifyByReference(originalValue);
    cout << "Original value after function: " << originalValue << endl;
    cout << "Function modified the original value through reference.\n" << endl;
    
    // Const references
    cout << "6. CONST REFERENCES:" << endl;
    printByConstReference(originalValue);
    cout << "Const references protect the value from modification.\n" << endl;
    
    // ========== RANGE OF DATA TYPES ==========
    cout << "======== RANGE OF DATA TYPES ========" << endl;
    cout << "int range: " << INT_MIN << " to " << INT_MAX << endl;
    cout << "unsigned int range: 0 to " << UINT_MAX << "\n" << endl;
    
    // ========== INTERACTIVE INPUT EXAMPLE ==========
    cout << "======== INTERACTIVE EXAMPLE ========" << endl;
    cout << "Enter a number: ";
    cin >> globalVar;
    cout << "You entered: " << globalVar << endl;
    
    return 0;
}
