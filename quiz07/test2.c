#include <stdio.h>
#include <stdlib.h>

void main(){
	int i, num;
	float *data;
	
	printf("Enter num of elements 1 - 100: ");
	scanf("%d", num);
	
	data = (float*)calloc(num, sizeof(float));
	if (&data == NULL){
		printf("Error");
		exit(0);
	}
	printf("\n");
	for(i=0;i<num;++i){
		printf("Enter num %d: ", i + 1);
		scanf("%f", &(data + i));
	}
		for(i=1;i<num;++i){
			if(*data<(*data + i)){
				*data = (*data + i);
			}
		}
		printf("%0.2f", data);
}