#include <stdio.h>


int linearSearch(int n[], int X){
	for(int i = 0; i < 7; i++){
		if(n[i] == X){
			return i;
		}	
	}
	return -1;
}



void main(){
	
	int a[7] = {38, 20, 16, 7, 37, 4, 43};
	int x;
	printf("\nEnter a number to search: ");
	scanf("%d", &x);
	int result = linearSearch(a, x);
	if(result == -1)
		printf("\nNumber not found!");
	else
		printf("\nFound number a[%d] = %d", result, a[result]);
}