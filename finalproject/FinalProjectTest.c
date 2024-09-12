//SE 185: Final Project Template//
/////////////////////////
/* 
Team xx (please insert your team number instead of xx)
Team member 1 "Logan Pfantz" | 50%
Team member 2 "Jose Soto" | 50%

*/

////////////////////
#include<stdio.h>//
//add more here////
#include <stdlib.h>
#include <string.h>
#include <ncurses/ncurses.h>
#include <time.h>
#include <ctype.h>
#define MAXWORDS 2000
#define WORDLENGTH 20
#define MAXONSCREEN 20											// The maximum number of words that can be on screen at once

//////////////////////
//Struct Definition//
////////////////////


/////////////////////////////////////
//User Defined Functions Prototype//
//List prototypes here and define//
//tehm below the main function////
/////////////////////////////////

// Asks the user to enter p to play or w to add a word: Returns user input
char User_selection(int numWords);

// Puts all the words in the text file into an array
int read_words(char* wordslist[MAXWORDS], char* file_name);

void trim_word(char word[WORDLENGTH]);

// Adds a random word to the top of the screen, returns the word's column position
int add_word(char word[]);

int main(){
	char userChar;												// Stores the variable entered by the user
	int wordcount;												// Stores the current number of words in the file
	int randNum;												// Stores a random number
	srand(time(NULL));											// Start with a random seed everytime
	int wordPositions[1000][1];									// 2D Array used to store each word's column and row
	int wordRows[1000];											// Stores the current row of each word
	char userWord[WORDLENGTH];									// Stores the word typed in from the user
	int colPosition;											// temporarily stores the column position of an incoming word
	int previous_time = time(NULL);								// Stores the time value of the previous word selection
	int currWord = 0;											// Stores the number of words that have been printed
	
	// Read words from input file
	char* wordslist[MAXWORDS] = {"apple", "whatever", "which", "total", "enough", "smurf", "country", "specific"};
	wordcount = sizeof(wordslist);

	// Introduction
	printf("Hello, this is a typing game. You will need to type the words as they appear.\n"
		   "Enter p to play.\n");
	scanf(" %c", &userChar);

	// Start the game
	initscr();
    refresh();

	// Print the game screen
	mvprintw(0, 0, "__________________________________________________");

	for (int i = 1; i < 18; i++){
		mvprintw(i, 0, "|                                                |");
	}
	for (int i = 18; i < 20; i++){
		mvprintw(i, 0, "__________________________________________________");
	}
	mvprintw(22, 0, "Type here: ");
	refresh();


	do {
		randNum = random() % wordcount;
		scanf(" %s", userWord);
		mvprintw(22, 13, userWord);
		colPosition = add_word(wordslist[random() % wordcount]);			// Add a word to the screen
		wordPositions[currWord][0] = colPosition;

		currWord++;
	} while(1);
	
	endwin();
	
	
	return 0;
}

///////////////////////////////////////
//User Defined Functions' Definition//
/////////////////////////////////////
char User_selection(int numWords){
	char userChar;
	int validChar = 1;
	while (validChar){
		printf("You currently have %d words that can be used. (p/w)\n", numWords);
		scanf(" %c", &userChar);
		if (userChar == 'p' | userChar == 'w')
			validChar = 0;
		else
			printf("Invalid response, try again.\n");
	}
	
	return userChar;
}

int add_word(char word[]){
	int i;
	for(i = 0; word[i] != '\0'; i++);
	int colPosition = random() % (49 - i);
	mvprintw(1, colPosition, word);
	return colPosition;
}