#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 		Name:     Jesus Horacio Soto Gonzalez
		Section:  #1
		Course:   SE185 
*/ 

int main()
{

int player1Toss1, player1Toss2, player2Toss1, player2Toss2;
int player1Sum = 0, player2Sum = 0;
srand ( time(NULL) );

//Dice toss Player1
player1Toss1 = rand() % 6 + 1;
player1Toss2 = rand() % 6 + 1;

//Player1 dice toss sum
player1Sum = player1Toss1 + player1Toss2;

//Player1 results

printf("Player 1 Dice: %d - %d\n\n", player1Toss1, player1Toss2);
printf("Player 1 sum: %d\n\n", player1Sum);


//Dice toss Player2
player2Toss1 = rand() % 6 + 1;
player2Toss2 = rand() % 6 + 1;

//Player2 dice toss sum
player2Sum = player2Toss1 + player2Toss2;

//Player2 results

printf("Player 2 Dice: %d - %d\n\n", player2Toss1, player2Toss2);
printf("Player 2 sum: %d\n\n", player2Sum);

//Final results 
if(player1Sum > player2Sum)
printf("Player 1 is the winner");
else if(player2Sum > player1Sum)
printf("Player 2 is the winner");
else
printf("No one is lucky today. It is a tie.");

return 0;

}