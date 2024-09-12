#include <stdio.h>
#include <stdlib.h>

typedef struct numbers{
	int iNumber;
	int real;
}Num;

void main(){
	
	int sumr;
	int mulr;
	int subr;
	int sumi;
	int muli;
	int subi;
	
	Num Num1;
	Num Num2;
 
	
	printf("Enter real and imaginary numbers 1: ");
	scanf("%d %d", &Num1.real, &Num1.iNumber);
	
	printf("Enter real and imaginary numbers 2: ");
	scanf("%d %d", &Num2.real, &Num2.iNumber);
	
	sumr = Num1.real + Num2.real;
	subr = Num1.real - Num2.real;
	mulr = (Num1.real * Num2.real) - (Num1.iNumber * Num2.iNumber);
	
	sumi = Num1.iNumber + Num2.iNumber;
	muli = (Num1.real * Num2.iNumber) + (Num2.real * Num1.iNumber);
	subi = Num1.iNumber - Num2.iNumber;
	
	
	
	printf("\nADD = %d + %di\n", sumr, sumi);
	printf("SUB = %d + %di\n", subr, subi);
	printf("MUL = %d + %di\n", mulr, muli);

}