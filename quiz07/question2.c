#include<stdio.h>

int main() {
    int a = 15;
    //int copy_a = a;
	int *ptr_a = &a;
    a /= 3;
    //copy_a = a;
	
	
    ++*ptr_a;
    a = *ptr_a;
    if(*ptr_a == a) {
        printf("Copy_a = %d\n" , *ptr_a);
        printf("a = %d\n" , a);
        printf("Therefore, Copy_a = a = %d\n" , *ptr_a);
    }
    return 0;
}