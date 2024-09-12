#include <stdio.h>

// function definition
int fib(int a){
	if (a == 0)
		return 0;
	else if (a == 1)
		return 1;
	else 
		return fib(a-1)+fib(a-2);
}
void main (){
	
	for (int i = 0; i < 10; i++){
		printf("%d", fib(i));
	}
	
}