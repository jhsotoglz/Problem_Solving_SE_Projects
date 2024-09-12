#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int quiz01()
{
    int score = 0;
    int answer;
    int answer1;
    int answer2;
    int answer3;

    printf("Quiz 01\n");
    printf("Question 1 (1 point)\n");
    printf("What is the capital of Canada?\n");
    printf("1) Toronto\n");
    printf("2) Ottawa\n");
    printf("3) Vancouver\n");
    scanf("%d", &answer);
    if (answer == 2)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("Question 2 (1 point)\n");
    printf("What is the capital of the United States?\n");
    printf("1) New York\n");
    printf("2) Los Angeles\n");
    printf("3) Washington, D.C.\n");
    scanf("%d", &answer1);
    if (answer1 == 3)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("Question 3 (1 point)\n");
    printf("What is the capital of France?\n");
    printf("1) Paris\n");
    printf("2) Marseille\n");
    printf("3) Lyon\n");
    scanf("%d", &answer2);
    if (answer2 == 1)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("Question 4 (1 point)\n");
    printf("What is the capital of Italy?\n");
    printf("1) Rome\n");
    printf("2) Milan\n");
    printf("3) Venice\n");
    scanf("%d", &answer3);
    if (answer3 == 1)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("Your total score for Quiz 01 is: %d/4\n", score);
    return score;
}

int quiz02()
{
    int score = 0;
    int answer;
    int answer1;
    int answer2;
    int answer3;

    printf("Quiz 02\n");
    printf("Question 1 (1 point)\n");
    printf("What is the capital of Australia?\n");
    printf("1) Sydney\n");
    printf("2) Melbourne\n");
    printf("3) Perth\n");
    scanf("%d", &answer);
    if (answer == 1)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("Question 2 (1 point)\n");
    printf("What is the capital of China?\n");
    printf("1) Shanghai\n");
    printf("2) Beijing\n");
    printf("3) Hong Kong\n");
    scanf("%d", &answer1);
    if (answer1 == 2)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("Question 3 (1 point)\n");
    printf("What is the capital of Japan?\n");
    printf("1) Osaka\n");
    printf("2) Tokyo\n");
    printf("3) Nagoya\n");
    scanf("%d", &answer2);
    if (answer2 == 2)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("Question 4 (1 point)\n");
    printf("What is the capital of Russia?\n");
    printf("1) Moscow\n");
    printf("2) St. Petersburg\n");
    printf("3) Novosibirsk\n");
    scanf("%d", &answer3);
    if (answer3 == 1)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("Your total score for Quiz 02 is: %d/4\n", score);
     return score;
}

int quiz03()
{
    int score = 0;
    int answer;
    int answer1;
    int answer2;
    int answer3;

    printf("Quiz 03\n");
    printf("Question 1 (1 point)\n");
    printf("What is the capital of Argentina?\n");
    printf("1) Buenos Aires\n");
    printf("2) Cordoba\n");
    printf("3) Rosario\n");
    scanf("%d", &answer);
    if (answer == 1)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("Question 2 (1 point)\n");
    printf("What is the capital of Brazil?\n");
    printf("1) Rio de Janeiro\n");
    printf("2) Sao Paulo\n");
    printf("3) Brasilia\n");
    scanf("%d", &answer1);
    if (answer1 == 3)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("Question 3 (1 point)\n");
    printf("What is the capital of Mexico?\n");
    printf("1) Monterrey\n");
    printf("2) Mexico City\n");
    printf("3) Guadalajara\n");
    scanf("%d", &answer2);
    if (answer2 == 2)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("Question 4 (1 point)\n");
    printf("What is the capital of Peru?\n");
    printf("1) Lima\n");
    printf("2) Arequipa\n");
    printf("3) Trujillo\n");
    scanf("%d", &answer3);
    if (answer3 == 1)
    {
        printf("Correct!\n");
        score++;
    }
    else
    {
        printf("Incorrect.\n");
    }

    printf("Your total score for Quiz 03 is: %d/4\n", score);
     return score;
}

// Generates and prints 'count' random
// numbers in range [lower, upper].
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

    printf("Welcome to the midterm project!\n");
    printf("There are three quizzes to choose from.\n");
    printf("Quiz 01\n");
    printf("Quiz 02\n");
    printf("Quiz 03\n");

    printf("Please enter a number between 1 and 9 to choose a quiz: ");
    scanf("%d", &choice);
    
    
    int lower = 1;
    int upper = 9;
 
    // Use current time as
    // seed for random generator
    srand(time(0));
    quiz = getRandomNumber(lower, upper, 1);

    if (choice >= 1 && choice <= 9)
    {
        do
        {
            switch (quiz)
            {
            case 1:
            case 4:
            case 7:
               score = quiz01();
                break;
            case 2:
            case 5:
            case 8:
               score = quiz02();
                break;
            case 3:
            case 6:
            case 9:
               score = quiz03();
                break;
            }
            total = total + score;
            count++;

        } while (score != 4);
        average = (float)total / count;
        printf("Your average score is: %.2f\n", average);
        printf("Your total score is: %d/12\n", total);
    }
    else
    {
        printf("Sorry, you did not choose the right number. Please try again.\n");
    }

    return 0;
}