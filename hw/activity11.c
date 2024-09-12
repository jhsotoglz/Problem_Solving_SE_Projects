#include <stdio.h>
#include <string.h>

int main(){
	float A[6] = {1.0, 2.0, 1.0, 0.5, 3.0, 2.0}
	//find minimum
	float *min = A;
	// float *min = &A[0];
	float *ptr = A + 1;
	//float *ptr = &A[1];
	while (ptr <= A+5){ //ptr = &A[5]
		if(ptr < *min){
			min = ptr;
		}
		ptr++;
	}
	printf("\nMin = %0.1f", *min);
	
	return(0);
	
}