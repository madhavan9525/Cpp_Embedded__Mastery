#include<stdio.h>
#include<limits.h>

// Global variable
int a;

// ========== DEMONSTRATING STATIC VARIABLES ==========
// Static function - demonstrates static variable persistence
void demonstrateStaticVariable() {
    static int callCount = 0;  // Initialized only once, retains value between calls
    callCount++;
    printf("Function called %d times\n", callCount);
}

// ========== DEMONSTRATING CONST VARIABLES ==========
// Function to demonstrate const parameters
void printConstValue(const int value) {
    printf("Const parameter value: %d\n", value);
    // value = 10;  // ERROR: Cannot modify a const parameter
}

int main() {
    // ========== BASIC VARIABLE TYPES IN C ==========
    
    printf("======== FUNDAMENTAL DATA TYPES IN C ========\n\n");
    
    // 1. INTEGER TYPES
    printf("1. INTEGER TYPES:\n");
    int myInt = 42;
    short myShort = 100;
    long myLong = 1000000;
    unsigned int myUnsignedInt = 50;
    
    printf("int: %d (size: %zu bytes)\n", myInt, sizeof(int));
    printf("short: %d (size: %zu bytes)\n", myShort, sizeof(short));
    printf("long: %ld (size: %zu bytes)\n", myLong, sizeof(long));
    printf("unsigned int: %u (size: %zu bytes)\n\n", myUnsignedInt, sizeof(unsigned int));
    
    // 2. FLOATING POINT TYPES
    printf("2. FLOATING POINT TYPES:\n");
    float myFloat = 3.14f;
    double myDouble = 3.14159265;
    
    printf("float: %f (size: %zu bytes)\n", myFloat, sizeof(float));
    printf("double: %lf (size: %zu bytes)\n\n", myDouble, sizeof(double));
    
    // 3. CHARACTER TYPE
    printf("3. CHARACTER TYPE:\n");
    char myChar = 'A';
    printf("char: %c (ASCII value: %d, size: %zu bytes)\n\n", myChar, myChar, sizeof(char));
    
    // 4. BOOLEAN TYPE (using int, since C doesn't have native bool in standard C89)
    printf("4. BOOLEAN TYPE (using int):\n");
    int myBool = 1;  // 1 for true, 0 for false
    printf("bool (as int): %d (size: %zu bytes)\n\n", myBool, sizeof(int));
    
    // ========== VARIABLE SCOPE ==========
    printf("======== VARIABLE SCOPE ========\n");
    printf("Global variable 'a' value: %d\n", a);  // Global variable initialized to 0
    
    int localVar = 100;  // Local variable (scope limited to main function)
    printf("Local variable 'localVar': %d\n\n", localVar);
    
    // ========== DETAILED EXPLANATION: STATIC VARIABLES ==========
    printf("======== STATIC VARIABLES - DETAILED EXPLANATION ========\n");
    printf("Static variables are initialized only ONCE and retain their value between function calls.\n");
    printf("They are stored in the data segment of memory (not on the stack).\n\n");
    
    printf("Calling demonstrateStaticVariable():\n");
    demonstrateStaticVariable();  // callCount = 1
    demonstrateStaticVariable();  // callCount = 2 (retained from previous call!)
    demonstrateStaticVariable();  // callCount = 3
    printf("\nNote: The static variable 'callCount' retains its value across function calls.\n\n");
    
    // Local static variable example
    printf("Local static variable example:\n");
    static int localStaticVar = 10;
    printf("Local static var before: %d\n", localStaticVar);
    localStaticVar += 5;
    printf("Local static var after modification: %d\n\n", localStaticVar);
    
    // ========== DETAILED EXPLANATION: CONST VARIABLES ==========
    printf("======== CONST VARIABLES - DETAILED EXPLANATION ========\n");
    printf("Const variables are IMMUTABLE - their values cannot be changed after initialization.\n");
    printf("They provide data protection and make code safer and more predictable.\n\n");
    
    // 1. Const variable
    printf("1. CONST VARIABLE (immutable value):\n");
    const int myConstant = 42;
    printf("Const variable value: %d\n", myConstant);
    // myConstant = 50;  // ERROR: Assignment of read-only variable
    printf("Cannot modify a const variable after initialization.\n\n");
    
    // 2. Const with pointers
    printf("2. CONST WITH POINTERS:\n");
    int normalVar = 100;
    
    // Const pointer (pointer value is const, but what it points to can change)
    int * const constPointer = &normalVar;
    printf("Const pointer value: %d (pointing to normalVar)\n", *constPointer);
    // constPointer = &myInt;  // ERROR: Cannot change pointer address
    *constPointer = 150;  // OK: Can change the value it points to
    printf("After modification through const pointer: %d\n\n", normalVar);
    
    // Pointer to const (pointer can change, but value it points to cannot)
    const int * pointerToConst = &myConstant;
    printf("Pointer to const value: %d\n", *pointerToConst);
    pointerToConst = &normalVar;  // OK: Can change pointer address
    // *pointerToConst = 200;  // ERROR: Cannot modify const value through pointer
    printf("Pointer reassigned to point to normalVar: %d\n\n", *pointerToConst);
    
    // 3. Const in function parameters
    printf("3. CONST IN FUNCTION PARAMETERS:\n");
    printConstValue(50);  // Function won't modify the parameter
    printf("Parameter protection: function cannot modify const parameters.\n\n");
    
    // 4. Const with arrays
    printf("4. CONST WITH ARRAYS:\n");
    const int constArray[] = {10, 20, 30, 40, 50};
    printf("Const array: [%d, %d, %d, %d, %d]\n", constArray[0], constArray[1], 
           constArray[2], constArray[3], constArray[4]);
    // constArray[0] = 99;  // ERROR: Cannot modify array elements
    printf("Cannot modify elements of a const array.\n\n");
    
    // ========== RANGE OF DATA TYPES ==========
    printf("======== RANGE OF DATA TYPES ========\n");
    printf("int range: %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int range: 0 to %u\n\n", UINT_MAX);
    
    // ========== INTERACTIVE INPUT EXAMPLE ==========
    printf("======== INTERACTIVE EXAMPLE ========\n");
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("You entered: %d\n", a);
    
    return 0;
}

