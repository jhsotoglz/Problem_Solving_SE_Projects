#include <stdio.h>

void main(){
	
	int a[7];
	//read from file
	FILE* fp = fopen("data.txt","r");
		for (int i = 0; i < 7; i++){
		fscanf(fp, "%d", &a[i]);
		}
	
	printf("\nPrint the un-sorted array....\n");
	for (int i = 0; i < 7; i++){
		printf("%d ", a[i]);
	}
			
			
	int n = 0;
	while(n<7){
	for (int i = 0; i < 7; i++){
		if (a[i] < a[i + 1]){
			//swap
			int temp = a[i + 1];
			a[i + 1] = a[i];
			a[i] = temp;
			
			}
		}
	n++;
	}

	printf("\nPrint the sorted array....\n");
	for (int i = 0; i < 7; i++){
		printf("%d ", a[i]);
	}
	fclose(fp);
}