#include <stdio.h>
int f(int a, int* b);
int main() {
           int a = 3, b = 7, c = 4;
           c = f(b, &a) + 3;
           printf("a=%d, b=%d, c=%d\n", a, b, c);
           b = f(a, &c);
           printf("a=%d, b=%d, c=%d\n", a, b, c);
           return 0;
}
int f(int a, int* b) {
           *b = (a+3)*2 + (*b)%4;
           a = *b - a%6;
           printf("a=%d, b=%d\n", a, *b);
           return 2*a - (*b);
}