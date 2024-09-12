#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void main(){

char str[100] = "5 3";
int num1, num2;

sscanf(str, " %d, %d", &num1, &num2);

printf("%d", num2);

}