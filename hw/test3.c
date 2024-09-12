#include <stdio.h>
#include <string.h>
#include <math.h>

void main(){
	int v = 4;
	int w = 1;
	int x = 18;
	int y = 22;
	int z = 11;
	if(!((z % x == w || y - z == z) && (y - x == v && !(y % x == v))))
	{
		printf("W");
		
	}
	else if(y - z == 11){
		printf("L");
		
	}
	else{
		printf("K");
	}
}