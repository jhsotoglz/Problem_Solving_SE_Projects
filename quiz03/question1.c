#include <stdio.h>



void main()
{
    int gradePercentage;
	
    printf("Please enter your grading percentage: \n");
    scanf("%d",&gradePercentage);
	
    if(gradePercentage<0 || gradePercentage>100)
    {
        printf("Your grade must be between 0 and 100 percent inclusively.");
    }
    else if(gradePercentage<60)
    {
        printf("Your letter grade is F");
    }
    else if(gradePercentage>=60 && gradePercentage<63)
    {
        printf("Your letter grade is D-");
    }
    else if(gradePercentage>=63 && gradePercentage<67)
    {
        printf("Your letter grade is D");
    }
    else if(gradePercentage>=67 && gradePercentage<70)
    {
        printf("Your letter grade is D+");
    }
    else if(gradePercentage>=70 && gradePercentage<73)
    {
        printf("Your letter grade is C-");
    }
	 else if(gradePercentage>=73 && gradePercentage<77)
    {
        printf("Your letter grade is C");
    }
	 else if(gradePercentage>=77 && gradePercentage<80)
    {
        printf("Your letter grade is C+");
    }
	 else if(gradePercentage>=80 && gradePercentage<83)
    {
        printf("Your letter grade is B-");
    }
	 else if(gradePercentage>=83 && gradePercentage<87)
    {
        printf("Your letter grade is B");
    }
	 else if(gradePercentage>=87 && gradePercentage<90)
    {
        printf("Your letter grade is B+");
    }
	 else if(gradePercentage>=90 && gradePercentage<93)
    {
        printf("Your letter grade is A-");
    }
    else
    {
        printf("Grade A+");
    }
}