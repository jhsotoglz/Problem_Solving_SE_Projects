#include <stdio.h>

//function definition
int fact(int a){
		if(a == 1)
			return 1;
		//recutsive case
		else
			return a * fact(a - 1);
}

void main () {
	printf("result = %d", fact(5));
}

/*
Interpretation of code
fact(4) -> 4 * fact(3) = 4 * 6 = 24
fact(3) -> 3 * fact(2) = 3 * 2 = 4
fact (2)-> 2 * fact(1) = 2*1 - 2
fact(1) -> 1

*/