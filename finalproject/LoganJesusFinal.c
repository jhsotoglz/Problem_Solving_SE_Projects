//SE 185: Final Project Template//
/////////////////////////
/* 
Team xx (please insert your team number instead of xx)
Team member 1 Logan Pfantz | 50%
Team member 2 Jesus Soto | 50%
*/

////////////////////
#include<stdio.h>//
//add more here////
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXWORDS 2000						// max num of words in wordlist
#define WORDLENGTH 25						// max word length
#define NUMROWS 18							// height of the game screen
#define NUMCOLUMNS 50						// width of the game screen


//////////////////////
//Struct Definition//
////////////////////
typedef struct rowInformation{
	char word[WORDLENGTH];
	int wordPosition;
}rowInformation;


/////////////////////////////////////
//User Defined Functions Prototype//
//List prototypes here and define//
//tehm below the main function////
/////////////////////////////////

// Takes in a word, a row, and a position of the word in that row then builds the row with the word in stated position
void build_currentRow(char word[WORDLENGTH], char currentRow[NUMCOLUMNS], int wordPosition);

// Reads in all the words from the file
int read_words(char* wordlist[MAXWORDS]);

// trims whitespace off the end of words
void trimws(char* str);

// Asks the user to enter p to play or w to add word, returns user input
char play_or_add(int numWords);


void main(){
	int numWords;														// Stores the number of words in wordlist
	int wordsToAdd = 1;													// Stores number of words to add based on how much time has passed
	int wordMultiplier = 1;												// Multiplied to wordsToAdd to increase difficulty as the game goes on
	int rowBottomWord = 0;												// Stores the current position of the lowest word on screen
	int minWordLength;													// Stores user input for minimum word length
	int lastTime;														// Holds value of time from previous loop, used for timer
	int startTime;														// Stores the current time when the user starts playing
	int timeBuffer = 2;													// Stores how many seconds pass before adding a new word
	int gameOver = 0;													// Stores the state of the game (whether player has lost)
	int score = 0;														// Stores the users current score
	int wordsOnScreen = 0;												// Stores how many words are currently on screen

	char* wordlist[MAXWORDS];											// Stores an array of all words in text file
	char currentRow[NUMCOLUMNS];										// Stores a string of the current row to be printed
	char userWord[WORDLENGTH];											// Stores the user's entered word
	char userChar;														// Stores the user's input for the introduction
	char addedWord[WORDLENGTH];											// Stores the word the user wants to add to text file
	
	srand(time(NULL));													// Seed
	
	//----------------------------------------------------------------------------------------------------------------- //
	// Introduction
	printf("Hello, this is a typing game. You will need to type the words as they appear.\n"
		   "Would you like to play or add a word?\n");

	// Read in all the words from the file
	numWords = read_words(wordlist);	

	// Ask the user if they want to enter a word or play
	userChar = play_or_add(numWords);

	// The user wants to enter a word
	while(userChar == 'w'){
		printf("What word would you like to add?\n");	// Ask Question
		fflush(stdin);          						// To clear extra white space characters in stdin
		scanf(" %s", addedWord);							// Get input
		if(strlen(addedWord) > 0){
			FILE* fp = fopen("wordList.txt", "a");
			fprintf(fp, "\n%s", addedWord);
			fclose(fp);
			numWords++;									// Update value of numwords
		}
		else {
			printf("Adding word failed. Try Again.\n");
		}
		userChar = play_or_add(numWords);				// Get user input again
	}

	
	
	// Update wordslist with any added words
	numWords = read_words(wordlist);
	
	// Get user input on word length
	
	// -------------------------------------------------------------------------------------------------------------------- //
	// Create all rows with empty words
	rowInformation allRows[NUMROWS];									// Holds the word and its position in each row
	for(int i = 0; i < NUMCOLUMNS; i++){
		strcpy(allRows[i].word, "");									// All rows are empty at the start
	}
	
	lastTime = time(NULL);												// Set timer for first round
	startTime = lastTime;												// Set starting time of game
	// start game
	do {
		// Print the game screen
		system("clear");													// Clear the terminal screen
		for(int i = 0; i < NUMCOLUMNS; i++){
			printf("_");													// Print top line
		}
		printf("\n");
		
		for(int i = 0; i < wordsToAdd; i++){								// Repeat adding words until the correct number is added
		
			// Move all words down one line
			for(int i = NUMROWS - 1; i > 0; i--){
				strcpy(allRows[i].word, allRows[i-1].word);					// Copy previous row's word into current row
				allRows[i].wordPosition = allRows[i-1].wordPosition;		// Copy position of previous word into the current row
			}
			
			// Add new word to first row
			strcpy(allRows[0].word, wordlist[rand() % numWords]);			// Get a random word from wordlist, put it in first row
			// Get position of word
			allRows[i].wordPosition = rand() % (NUMCOLUMNS - 2 - strlen(allRows[i].word));	// Subtract length of word from length of row to ensure a word won't go past the right wall
		}
		
		// Print all the rows
		for(int i = 0; i < NUMROWS; i++){
			build_currentRow(allRows[i].word, currentRow, allRows[i].wordPosition);
			printf("%s", currentRow);
		}
		
		for(int j = 0; j < 2; j++){											// Print bottom 2 lines
			for(int i = 0; i < NUMCOLUMNS; i++){
				printf("_");
			}
			printf("\n");
		}
		
		// Get user input
		printf("Type here: ");
		scanf(" %s", userWord);
		// End of game screen

		// Check user input for a match in each row
		for(int i = 0; i < NUMROWS; i++){
			if(strcmp(allRows[i].word, userWord) == 0){						// If userWord matches the word in the row
				strcpy(allRows[i].word, "");									// Clear the row
				score++;														// Add a point to the score
			}
		}
		
		// Update rowBottomWord and wordsOnScreen
		for(int i = 0; i < NUMROWS; i++){									// Check each row for a word
			if(strlen(allRows[i].word) > 0){								// If row has a word
				rowBottomWord = i;												// Save row as bottom row
				wordsOnScreen++;												// Increment wordsOnScreen
			}
		}
		// Find how many words needed to add for next time
		wordsToAdd = (time(NULL) - lastTime) / timeBuffer;					// Add a word for each timeBuffer amount of time that has passed since the last word was entered
		if(wordsToAdd == 0 & wordsOnScreen == 0){
			wordsToAdd = 1;													// Add a word each time, even if enough time hasn't passed
		}
		
		// Increase words to add as the game goes on
		if(score % 4 == 0){													// Every forth word increases the amount of words to spawn
			wordMultiplier++;
		}
		wordsToAdd *= wordMultiplier;
		
		lastTime = time(NULL);												// Reset timer for next round
		wordsOnScreen = 0;													// Reset wordsOnScreen for the next round
		
		// Check if player has lost
		if(rowBottomWord + wordsToAdd > NUMROWS - 1){						// If a word goes below bottom row
			gameOver = 1;
		}
		
	} while(!gameOver);
	
	// Display game over screen
	printf("\n\nA word touched the bottom!\n");
	printf("You lasted %d seconds!\n", time(NULL) - startTime);
	printf("Words correctly entered: %d\n", score);
	
}

///////////////////////////////////////
//User Defined Functions' Definition//
/////////////////////////////////////

void build_currentRow(char word[WORDLENGTH], char currentRow[NUMCOLUMNS], int wordPosition){
	// left wall
	strcpy(currentRow, "|");
	
	// number of spaces before word
	for(int i = 1; i < wordPosition + 1; i++){
		strcat(currentRow, " ");
	}
	
	// word
	strcat(currentRow, word);
	
	// spaces after word
	for(int i = wordPosition + strlen(word); i < NUMCOLUMNS - 2;i++){
		strcat(currentRow, " ");
	}
	
	// left wall
	strcat(currentRow, "|\n");
}

int read_words(char* wordlist[MAXWORDS]){
	// Scan in words from "wordList.txt"
	int numWords = 0;
	char line[WORDLENGTH];
	char *p;
	FILE* fp = fopen("wordList.txt", "r");
	while (!feof(fp)) {
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL) 
		{
			trimws(line);
			wordlist[numWords] = (char *)malloc(strlen(line) + 1);
			strcpy(wordlist[numWords], line);
			numWords++;
		}
	}
	fclose(fp);
	return numWords;
}

void trimws(char* str) {
	int length = strlen(str);
	int x;
	if (length == 0) return;
	x = length - 1;
	while (isspace(str[x]) && (x >= 0)) {
		str[x] = '\0';
		x -= 1;
	}
}

char play_or_add(int numWords){
	char userChar = 'a';										// Stores user input

	while(1){
		printf("You currently have %d words that can be used. (p/w)\n", numWords);
		scanf(" %c", &userChar);
		if (userChar == 'p' | userChar == 'w'){					// Ensure user can only enter p or w
			break;
		}
		printf("You must enter either p or w. Try Again.\n");
	}
	return userChar;
}