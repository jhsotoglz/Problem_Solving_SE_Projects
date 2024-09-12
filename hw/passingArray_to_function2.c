#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 5

typedef struct car{
	int year;
	char model [50];
	char make [50];
}car;

int main(){
	car a [SIZE];
	for(int i=0; i < SIZE; i++){
		printf("Enter year of the car %d\n", i+1);
		scanf(" %d", &a.year[i]);
			printf("Enter model of the car %d\n", i+1);
			scanf(" %s", a.model[i]);
				printf("Enter make of the car %d\n", i+1);
				scanf(" %s", a.make[i]);
	}
	
	int y = a[0].year;
		for (int i = 0; i < SIZE; i++){
			if (y > a.year[i]){
				y = a.year[i];
			}
		}
		printf("%d\n", y);
		return 0;
}
		