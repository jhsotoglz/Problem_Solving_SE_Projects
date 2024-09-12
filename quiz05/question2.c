#include <stdio.h>

double calculateAverage(double average[4]) //Function to calculate the averages
{
    return (average[0] + average[1] + average[2] + average[3])/4.0; //Returns the average of all grades
}

char letterGrade(double average)   //Function to find the letter grade
{
    if(average >= 85 && average <= 100)
        return 'A';
    else if(average >= 75 && average <= 84)
        return 'B';
    else if(average >= 60 && average <= 74)
        return 'C';
    else 
        return 'F';
}

int main()
{
   double grades[2][4];   //2d array
   
   printf("Please Enter assignment grades for student 1 and student 2\n");  
   for(int i = 0; i < 2; i++) // 2 students      
   {
       for(int j = 0; j < 4; j++)  // 4 assignment grades
       {
           printf("Student-%d Assignment-%d grade: ", i+1, j+1);   //Ask user to enter grades
           scanf(" %lf", &grades[i][j]);    //stores user inputs into grades[i][j]
       }
   }
   
    //Uses calculateAverage for student 1 grades array and stores in avg1
   double avg1 = calculateAverage(grades[0]);  
   
    //Uses calculateAverage for student 2 grades array and stores in avg2
   double avg2 = calculateAverage(grades[1]);
   
   printf("\nStudent 1 Avg = %.2lf\n", avg1);
   printf("Student 1 Grade = %c\n", letterGrade(avg1));
   printf("Student 2 Avg = %.2lf\n", avg2);
   printf("Student 2 Grade = %c\n", letterGrade(avg2));
   return 0;
}