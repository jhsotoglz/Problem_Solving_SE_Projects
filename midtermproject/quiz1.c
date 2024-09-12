
/*----------------------------------------------------------------------------
-	                            Functions Prototypes                         -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/

// Compile with gcc midtermproject.c -o midtermproject

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/

	int score;
	int totalScore;
	int averageScore;
	int count;
	int total;

int main()
{

	srand(time(0));
	
	int luckyNum;
	int quizNum;
	int attempts;
	char answer1;
	char answer2;
	char answer3;
	char answer4;
	char answer5;
	char answer6;
	char answer7;
	char answer8;
	char answer9;
	
		printf("\nWelcome to the Quiz Game!\n");
		printf("\nThis game will give you the opportunity to answer three different quizes. Quiz 01, Quiz 02, Quiz 03.\n");
		printf("\nTo start the game, please select a number from 1 to 9 to start the game:\n");
		scanf("%d", &luckyNum);
		printf("\n");
	
	score = 0;
	totalScore = 0;
	count = 0;
	total = 0;
	
	quizNum = (rand() % 3) + 1;
		printf("You will be taking quiz number %d\n", quizNum);
	
	  if (score != 15){
        average = (float)total / count;
        printf("Your average score is: %.2f\n", average);
        printf("Your total score is: %d/9\n", total);
    }
    else
    {
        printf("Sorry, you did not choose the right number. Please try again.\n");
    }

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
	/* Quiz # 1 */
	
	void quiz01()
	{
	if (quizNum == 1)
	{
		printf("\nQuiz # 1\n\n");
	
		printf("\nQuestion 1: \nAn array is a special variable that has one name,but stores a list of data items,"
								"with each item being directly accessible.\n"
										"A. True 		B.False\n");
										
		printf("\nSelect A for True and B for False: ");
		scanf("%s", &answer1);
		
			if (answer1 == 'A')
			{
			printf("\nCorrect!\n");
			printf("\n");
			score = score + 5;
			}
			else 
			{
			printf("\nIncorrect!\n");
			printf("\n");
			}
		
		printf("\nQuestion 2: \nWhat is the correct format specifier for a double type variable?\n"
					"A.%%d		B.%%lf	 C.%%u	 D.%%f \n");
		
		printf("Enter your answer: ");
		scanf("%s", &answer2);
			if ((answer2 == 'B') || (answer2 == 'b'))
			{
			printf("\nCorrect!\n");
			printf("\n");
			score = score + 5;
			}
			else
			{
			printf("\nIncorrect!\n");
			printf("\n");
			}
		

		printf("\nQuestion 3: \nWhat is the Hexadecimal equivalent to this decimal digit: 14?\n"
								"Please enter your answer: ");
		scanf("%s", &answer3);
			
			if (answer3 == 'E')
			{
				printf("\nCorrect!\n");
				printf("\n");
				score = score + 5;
			}
			else
			{
				printf("Incorrect!\n");
				printf("\n");
			}
		
		
	
	}
}
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	
	/* Quiz # 2 */
	
	void quiz02()
	{
		if (quizNum == 2)
		{
		printf("\nQuiz # 2\n\n");
		
		printf("\nQuestion 1: \nA function has to return one item, not two or more.\n"
										"A. True		B. False\n");
		printf("\nSelect A for True and B for False: ");
		
		scanf("%s", &answer4);
		
			if ((answer4 == 'B') || (answer4 == 'b'))
			{
				printf("\nCorrect!\n");
				printf("\n");
				score = score + 5;
			}
			else
			{
				printf("\nIncorrect!\n");
				printf("\n");
			}
		
		printf("Question 2: \nSelect the correct variable identifier.\n"
			"A.	Avg_Value		B.  _numPeople		D. #Apples	D. !height\n");
		printf("\nEnter your answer: ");
		scanf("%s", &answer5);
	
			if ((answer5 == 'B') || (answer5 == 'b'))
			{
				printf("\nCorrect!\n");
				printf("\n");
				score = score + 5;
			}
			else
			{
				printf("\nIncorrect!\n");
				printf("\n");
			}
			
			printf("\nQuestion 3: \nType the value of y.\n"
									"x = -9.0\n"
									"y = sqrt(fabs(x))\n");
			printf("\nEnter your answer: ");
			scanf("%s", &answer6);
			
				if (answer6 == '3')
				{
					printf("\nCorrect!\n");
					printf("\n");
					score = score + 5;
				}
				else
				{
					printf("\nIncorrect!\n");
					printf("\n");
				}
		
		
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
		
	/* Quiz # 3 */
	
	void quiz03()
	{
	if (quizNum == 3)
	{
		printf("\nQuiz # 3\n\n");
		
		printf("Question 1: \nA branch is a sequence of statements only executed under a certain condition.\n"
												"A. True		B. False\n");
												
		printf("Select A for True and B for False: ");
		
		scanf("%s", &answer7);
		
		if ((answer7 == 'A') || (answer7 == 'a'))
		{
			printf("\nCorrect!\n");
			printf("\n");
			score = score + 5;
		}
		else
		{
			printf("Incorrect!\n");
			printf("\n");
		}
		
		
		printf("\nQuestion 2: \nA function is a named list of ______ . \n"
								"A.	Variables	B. Data types		C. Statements		D. Arguments\n");
				
				printf("\nEnter your answer: ");
				scanf("%s", &answer8);
			
		if ((answer8 == 'C') || (answer8 == 'c'))
		{
			printf("\nCorrect!\n");
			printf("\n");
				score = score + 5;
		}
		else
		{
			printf("\nIncorrect!\n");
			printf("\n");
		}
		
		
		printf("\nQuestion 3: \nWhat will be the output of the following code?\n"
								"(If infinite write letter I)\n"
									"\nz = 0;\n"
									"c = 'y';\n"
									"\n"
									"while (c = 'y') {\n"
									"printf(%c, &c);  (Ignore the missing quotation marks)\n"
									"z = z + 1;\n");
									
		printf("\nEnter your answer: ");
		scanf("%s", &answer9);
		
		if ((answer9 == 'I') || (answer9 == 'i'))
		{
			printf("\nCorrect!\n");
			printf("\n");
			score = score + 5;
		}
		else
		{
			printf("\nIncorrect!\n");
			printf("\n");
		}
		
		
	}
}

/* Put your functions here, and be sure to put prototypes above. */


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	