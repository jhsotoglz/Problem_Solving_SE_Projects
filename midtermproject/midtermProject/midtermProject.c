/*----------------------------------------------------------------------------
-		         SE 185: Midterm Project   	               -
- List the names of all team members, their roles, and their participation
1- Student 1 - Role: Quiz Creator	and debugger - Participation: x%
(Use this line to describe your contribution to the project)
2- Student 2 - Role: Quiz Creator and debugger - Participation: y%
(Use this line to describe your contribution to the project)
3- 
4-  Jesus Soto Gonzalez Program creator - Participation: 100%
5-																                                     -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									                                   -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

/*----------------------------------------------------------------------------
-	                            Functions Prototypes                                   -
-----------------------------------------------------------------------------*/

int quiz01();

int quiz02();

int quiz03();

int getRandomNumber(int lower, int upper, int count);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/

// Compile with gcc midtermProject.c -o proj

/*----------------------------------------------------------------------------
-								Implementation								                               -
-----------------------------------------------------------------------------*/
int quiz01()
	{
		int score = 0;
		char answer1;
		char answer2;
		char answer3;
		
		 printf("\n Quiz # 1\n\n");
	
		printf("\nQuestion 1: \nAn array is a special variable that has one name, but stores a list of data items,"
								" with each item being directly accessible.\n"
										" A. True 		B.False\n");
		printf("\n Select A for True and B for False: ");
		scanf("%s", &answer1);
		if (answer1 == 'A' || answer1 == 'a')
		{
			printf("\n Correct!\n");
			score = score + 5;
		}
		else
		{
			printf("\n Incorrect!\n");
		}
		
		printf("\nQuestion 2: \n What is the correct format specifier for a double type variable?\n"
					" A.%%d		B.%%lf	 C.%%u	 D.%%f \n");
		printf("\n Enter your answer: ");
		scanf("%s", &answer2);
		if ((answer2 == 'B') || (answer2 == 'b'))
			{   
			printf("\n Correct!\n");
			score = score + 5;
		}
		else
		{
			printf("\n Incorrect!\n");
		}
		
		printf("\n Question 3: \n What is the Hexadecimal equivalent to this decimal digit: 14?\n"
								" Please enter your answer: ");
		scanf("%s", &answer3);
		if (answer3 == 'E')
		{
			 printf("\n Correct!\n");
			score = score + 5;
		}
		else
		{
			printf("\n Incorrect!\n");
		}
		
		printf("\n Your total score for Quiz 01 is: %d/15\n", score);
		
		 return score;
}

int quiz02()
{
    int score = 0;
    char answer1;
    char answer2;
    char answer3;
	
	printf("\n Quiz # 2\n\n");
		
		printf("\n Question 1: \n A function has to return one item, not two or more.\n"
										" A. True		B. False\n");
		printf("\n Select A for True and B for False: ");
		
		scanf("%s", &answer1);
		if ((answer1 == 'B') || (answer1 == 'b'))
		{
			printf("\n Correct!\n");
			score = score + 5;
		}
		else
		{
			printf("\n Incorrect!\n");
		}
	
	printf(" Question 2: \n Select the correct variable identifier.\n"
			" A.	Avg_Value		B.  _numPeople		D. #Apples	D. !height\n");
		printf("\n Enter your answer: ");
		scanf("%s", &answer2);
		if ((answer2 == 'B') || (answer2 == 'b'))
		{
			printf("\n Correct!\n");
			score = score + 5;
		}
		else
		{
			printf("\n Incorrect.\n");
		}
		
	printf("\n Question 3: \n Type the value of y.\n"
							" x = -9.0\n"
							" y = sqrt(fabs(x))\n");
		printf("\n Enter your answer: ");
		scanf("%s", &answer3);
		if (answer3 == '3')
		{
			printf("\n Correct!\n");
			score = score + 5;
		}
		else
		{
			printf("\n Incorrect!\n");
		}
		 
		 printf("\n Your total score for Quiz 02 is: %d/15\n", score);
		 
		 return score;
}
		
int quiz03()
{
	int score = 0;
    char answer1;
    char answer2;
    char answer3;
	
	printf("\n Quiz # 3\n\n");
		
		printf(" Question 1: \nA branch is a sequence of statements only executed under a certain condition.\n"
												" A. True		B. False\n");
												
		printf(" Select A for True and B for False: ");
		
		scanf("%s", &answer1);
		
		if ((answer1 == 'A') || (answer1 == 'a'))
		{
			printf("\n Correct!\n");
			score = score + 5;
		}
		else
		{
			printf("\n Incorrect!\n");
		}
		
		
		printf("\n Question 2: \n A function is a named list of ______ . \n"
								" A.	Variables	B. Data types		C. Statements		D. Arguments\n");
				
				printf("\n Enter your answer: ");
				scanf("%s", &answer2);
			
		if ((answer2 == 'C') || (answer2 == 'c'))
		{
			printf("\n Correct!\n");
				score = score + 5;
		}
		else
		{
			printf("\n Incorrect!\n");
		}
		
		
		printf("\n Question 3: \n What will be the output of the following code?\n"
								" (If infinite write letter I)\n"
									" \nz = 0;\n"
									" c = 'y';\n"
									" \n"
									" while (c = 'y') {\n"
									" printf(%c, &c);  (Ignore the missing quotation marks)\n"
									" z = z + 1;\n");
									
		printf("\n Enter your answer: ");
		scanf("%s", &answer3);
		
		if ((answer3 == 'I') || (answer3 == 'i'))
		{
			printf("\n Correct!\n");
			score = score + 5;
		}
		else
		{
			printf("\n Incorrect!\n");
		}
		 
		 printf("\n Your total score for Quiz 02 is: %d/15\n", score);
		 
		 return score;
		
	}
	
	

int getRandomNumber(int lower, int upper, int count)
{
    int i;
    int result;
    for (i = 0; i < count; i++) {
        int num = (rand() %
        (upper - lower + 1)) + lower;
        result = num;
    }
    
    return result;
}

int main()
{
    int choice;
    int score = 0;
    int total = 0;
    int count = 0;
    int quiz;
    float average;

    printf("\n Welcome to the Quiz Game!\n");
	printf("\n This game will give you the opportunity to answer three different quizes.\n"); 
	printf(" Quiz 01\n"); 
	printf(" Quiz 02\n"); 
	printf(" Quiz 03\n");
		

    printf(" Please enter a number between 1 and 9 to choose a quiz: ");
    scanf("%d", &choice);
    
    
    int lower = 1;
    int upper = 9;
 
    srand(time(0));
    quiz = getRandomNumber(lower, upper, 1);

    if (choice >= 1 && choice <= 9)
    {
        do
        {
            switch (quiz)
            {
            case 1:
            case 5:
            case 6:
               score = quiz01();
                break;
            case 2:
            case 4:
            case 9:
               score = quiz02();
                break;
            case 3:
            case 7:
            case 8:
               score = quiz03();
                break;
            }
            total = total + score;
            count++;

        } while (score != 15);
        average = (float)total / count;
        printf(" Your average score is: %.2f\n", average);
        printf(" Your total score is: %d/45\n", total);
		
    }
    else
    {
        printf("\n Sorry, please try to enter a number from 1 to 9.\n");
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */

int quiz01();

int quiz02();

int quiz03();

int getRandomNumber(int lower, int upper, int count);