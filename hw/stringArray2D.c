#include<stdio.h>

void main(){
	int n1, n2;//array size
	int i, j;//loop counter variable
	printf("\nEnter the size of the array: ");
	scanf("%d %d", &n1, &n2);
	char scores[n1][n2];//array declaration
	//array initialization
	for(i=0;i<n1;i++){
			printf("\nStudent%d name: ", i+1);
			scanf("%s", scores[i]);
	}
	//printing array
	printf("\n***printing array****");
	for(i=0; i<n1 ;i++){
		printf("\nStudent%d name = %s",i+1,scores[i]);
	}	
}