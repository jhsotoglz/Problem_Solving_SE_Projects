#include <stdio.h>

int main()
{
   double homework[5], exams[3];   //This arrays will store % inputs of Homework and Exams
   double average[3];   //Array to store average calculations
   
   for(int i = 0; i < 5; i++)   
   {
       printf("Enter your grade (%%) for HW #0%d: ", i+1);   //Aks user to enter Homework grade
       scanf(" %lf", &homework[i]);   //Stores inputs into hw[i]
   }
   for(int i = 0; i < 3; i++) 
   {
       printf("Enter your grade (%%) for Exm #0%d: ", i+1);  //Ask user to enter the Exam grade
       scanf(" %lf", &exams[i]); //Stores inputs into exm[i]
   }
   //The Homework average is calculated and stored in avg[0]
   average[0] = (homework[0] + homework[1] + homework[2] + homework[3] + homework[4])/5.0;
   
   //The Exam average is calculated and stored in avg[1]
   average[1] = (exams[0] + exams[1] + exams[2])/3.0;
   
   //The weighted average is calculated and stored in avg[2]
   average[2] = (0.40 * average[0]) + (0.6 * average[1]);
   
   printf("\nFinal grade = %.2lf%%\n", average[2]);   //This displays the weighted average
   return 0;
}