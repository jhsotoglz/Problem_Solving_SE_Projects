#include <stdio.h>


typedef struct record{
    char name[20];
}srecord;

void main(){

srecord studentA[4];
srecord studentB[4];
float mid1A[4];
float mid2A[4];
float finalA[4];
float mid1B[4];
float mid2B[4];
float finalB[4];
float averages[4];
FILE* fp = fopen("student_data", "w");

    for(int i = 0; i < 4; i++){
        printf("Enter student %d name and three exam scores: ", i + 1);
        scanf("%s %f %f %f", studentA[i].name, &mid1A[i], &mid2A[i], &finalA[i]);
        fprintf(fp, "%s %.2f %.2f %.2f\n", studentA[i].name, mid1A[i], mid2A[i], finalA[i]);
    }

    fclose(fp);

fp = fopen("student_data", "r");
    for(int i = 0; i < 4; i++){
        fscanf(fp, "%s %f %f %f\n", studentB[i].name, &mid1B[i], &mid2B[i], &finalB[i] );
        printf("%s exam scores = %.2f, %.2f, %.2f\n", studentB[i].name, mid1B[i], mid2B[i], finalB[i]);
        }
        
    for(int i = 0; i < 4; i++){

        averages[i] = ((mid1B[i] + mid2B[i] + finalB[i]) / 3);  
        printf("%s exam average = %.2f\n", studentB[i].name, averages[i]);
    }
}
