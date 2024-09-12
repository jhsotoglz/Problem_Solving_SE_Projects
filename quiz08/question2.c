#include <stdio.h>
#include <stdlib.h>	/*add header file*/

typedef struct time {
int hr;
int min;
int sec;
} time;

/*declare functions*/
void convTime(int seconds, time *mileTime);
void printTime(int seconds, time *mileTime);

void main() {
time *mileTime = (struct time*)malloc(sizeof(struct time));  /*allocate memory*/
int seconds;

printf("Total Seconds: ");
scanf("%d", &seconds);

convTime(seconds, mileTime);
printTime(seconds, mileTime);

}

void convTime(int seconds, time *mileTime) {
mileTime->hr = seconds / 3600;
seconds = seconds % 3600;

mileTime->min = seconds / 60;
seconds = seconds % 60;

mileTime->sec = seconds;
}


void printTime(int seconds, time *mileTime) {
printf("%d seconds = %d hr %d min %d sec", seconds, mileTime->hr, mileTime->min, mileTime->sec);
}
