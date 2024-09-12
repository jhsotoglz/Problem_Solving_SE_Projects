#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>	
#include <stdio.h>
#include <string.h>
#include <math.h>

void main (){

FILE *fp;  
int nums[8] = {12, 7, 3, 0, 28, 74, 37, 299};
int evenNums[8];
int curr;
int count = 0;
int i = 0;
   
    
    fp = fopen("numbers.txt" , "w");

    if (fp == NULL){
        printf("Unable to open file\n");
        exit(0);
    }
    
    while (i < 8){

        fprintf(fp, "%d ", nums[i]);
        i++;
    }
    fclose(fp);

    fp = fopen("numbers.txt", "r");
        if (fp == NULL){
            printf("Unable to open file\n");
            exit(0);
        }

        while (!feof(fp)) {  
            fscanf(fp, "%d ", &evenNums[i]);
                if (evenNums[i] % 2 == 0){
                    printf("%d ", evenNums[i]);
                    i++; 
                }
            }
        
        fclose(fp);
}