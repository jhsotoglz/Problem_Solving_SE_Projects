#include <stdio.h>
#include <math.h>

// Funtion declaration
int power(int base, int exponent);


int main() {

    int base, exponent, result;
    printf("Enter number to power: (Ex. 2 to 3) ");
    scanf("%d to %d", &base, &exponent);
    result = power(base, exponent);
    printf("%d to the power of %d = %d", base, exponent, result);
    return 0;
}

// Function definition
int power(int base, int exponent) {
    if (exponent != 0)
        return (base * power(base, exponent - 1));
    else
        return 1;
}