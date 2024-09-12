#include <stdio.h>


void TOH(int n, char a, char c, char b){
	//base case move disj=k n-1 from A -> C
	if (n==1){
		printf("\nMove disk 1 from rod %c to rod %c", a, c);
		return;
	}
	//recursive case
	// move n-1 disk, A -> B
	TOH(n-1, a, b, c);
	printf("\nMove disk 1 from rod %c to rod %c", a, c);
	//Move n-1 disk, B -> c
	TOH (n-1, b, c, a);
}
	

void main(){
	int N = 5; //Number of disk
	TOH(N, 'A', 'C', 'B');
	
}

