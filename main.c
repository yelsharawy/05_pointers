#include <stdio.h>

int main() {
    // 1. Declare and initialize variables of types `char`, `int`, and `long`.
    char my_char = 'Y';
    int my_int = 17;
    long my_long = 1074229200000;
    // 2. Print out the addresses of each variable in hex and decimal.
    printf("Addresses (hex): %p  \t%p  \t%p\n", &my_char, &my_int, &my_long);
    printf("Addresses (dec): %lu  \t%lu  \t%lu\n\n", &my_char, &my_int, &my_long);
    // * Do you notice anything about the addresses?
    // The difference between the first and second is 1 (the size of a char).
    // The difference between the second and third is 2 (the size of an int).
    // HOWEVER, this no longer held true later in the assignment (after declaring more variables).
    // This also did not hold true on Windows.
    
    // 3. Declare and initialize pointers for each of your variables.
    char *cP = &my_char;
    int *iP = &my_int;
    long *lP = &my_long;
    
    // 4. Print out the values of each pointer.
    printf("Pointers (hex):  %p  \t%p  \t%p\n", cP, iP, lP);
    printf("Pointers (dec):  %lu  \t%lu  \t%lu\n\n", cP, iP, lP);
    
    // 5. Use the pointers to modify the values of the original variables and print out the new values.
    *cP = 'E';
    *iP = 2004;
    *lP = 16328609290000;
    
    printf("New values:\t%c\t%i\t%ld\n\n", *cP, *iP, *lP);
    
    // 6. Declare and initialize an `unsigned int` variable and 2 pointers that point to it, one should be an `int *` and the other should be a `char *`
    unsigned int my_uint = 558635572;
    int *uiP1 = &my_uint;
    char *uiP2 = &my_uint;
    
    // 7. Print out the value of each pointer (this should be the memory address), and de-reference each pointer to print out the value each points to.
    printf(" int*: %p   int* points to: %u\n", uiP1, *uiP1);
    printf("char*: %p  char* points to: %u\n\n", uiP2, *uiP2);
    
    // 8. Print out your `unsigned int` in decimal and hex.
    printf("Hex: %x\tDec: %u\n\n", my_uint, my_uint);
    
    // 9. Use the `char *` to print out each individual byte of your `unsigned int`.
    printf("Bytes (hex): %hhx %hhx %hhx %hhx\n", *uiP2, *(uiP2+1), *(uiP2+2), *(uiP2+3));
    // Note: LE on Windows
    printf("Bytes (dec): %hhu %hhu %hhu %hhu\n\n", *uiP2, *(uiP2+1), *(uiP2+2), *(uiP2+3));
    
    // 10. Use the `char *` to increment _each byte_ of the `unsigned int` by 1.
    {
        char *i = uiP2;
        for (; i < uiP2+4; i++) {
            (*i)++;
            printf("Hex: %x\tDec: %u\n", my_uint, my_uint);
        }
    }
    // When done, print out each byte like in step 9.
    printf("Bytes (hex): %hhx %hhx %hhx %hhx\n", *uiP2, *(uiP2+1), *(uiP2+2), *(uiP2+3));
    printf("Bytes (dec): %hhu %hhu %hhu %hhu\n\n", *uiP2, *(uiP2+1), *(uiP2+2), *(uiP2+3));
    
    // 11. Perform the same operation as in step 10, except add 16 to each byte.
    {
        char *i = uiP2;
        for (; i < uiP2+4; i++) {
            (*i) += 16;
            printf("Hex: %x\tDec: %u\n", my_uint, my_uint);
        }
    }
    printf("Bytes (hex): %hhx %hhx %hhx %hhx\n", *uiP2, *(uiP2+1), *(uiP2+2), *(uiP2+3));
    printf("Bytes (dec): %hhu %hhu %hhu %hhu\n", *uiP2, *(uiP2+1), *(uiP2+2), *(uiP2+3));
}