#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MAXWORDS 2000
#define WORDLENGTH 25

// Reads in all the words from the file
int read_words(char* wordlist[MAXWORDS]);

// Trims whitespace from the end of words
void trimws(char* str);

// Asks the user to enter p to play or w to add word, returns user input
char play_or_add(int numWords);

int main(){
	char* wordlist[MAXWORDS];							// Stores list of words to be used in the game
	int numWords;										// Stores the total amount of words in wordslist
	char userChar;										// Stores the user's input for the introduction
	char userWord[WORDLENGTH];							// Stores the word the user wants to add

	// Introduction
	printf("Hello, this is a tpying game. You will need to type the words as they appear.\n"
		   "Would you like to play or add a word?\n");

	// Read in all the words from the file
	numWords = read_words(wordlist);	

	// Ask the user if they want to enter a word or play
	userChar = play_or_add(numWords);

	// The user wants to enter a word
	while(userChar == 'w'){
		printf("What word would you like to add?\n");	// Ask Question
		fflush(stdin);          						// To clear extra white space characters in stdin
		scanf(" %s", userWord);							// Get input
		if(strlen(userWord) > 0){
			FILE* fp = fopen("wordList2.txt", "a");
			fprintf(fp, "\n%s", userWord);
			fclose(fp);
			numWords++;									// Update value of numwords
		}
		else{
			printf("Adding word failed. Try Again.\n");
		}
		userChar = play_or_add(numWords);				// Update userChar at end of loop
	}

	// Update wordslist with any added words
	numWords = read_words(wordlist);
	for (int i = 10; i > 0; i--){
		printf("%s\n", wordlist[numWords - i]);
	}
}





int read_words(char* wordlist[MAXWORDS]){
	// Scan in words from "wordList.txt"
	int numWords = 0;
	char line[WORDLENGTH];
	char *p;
	FILE* fp = fopen("wordList2.txt", "r");
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

///////////////////////////////////////////////////////////////////////////////////////////////////
	
	/*We can try something like this:
	Get the array of words and select a random word. I'm assuming the random word to be 'randomWord'.
	Then get the random word position by using the rand() function, as shown in the code below. */


char randomWord[20]; //This is temporary
int wordLen = strlen(randomWord); //This is temporary
srand(time(0));
//Generates the random position of the word
//Subtract '2' because of the borders of the box and the word length so it can fit in the box
int wordPos = rand() % (boxWidth-wordLen-2);

for(int g = 0; g < boxLength; g++){
    for(int h = 0; h < boxWidth; h++){
        if(g == 1 && h == wordPos){ //Inserts the word at the top and at the random position
            for(int i = 0; i < wordLen; i++){
                box[g][h] = randomWord[i];
                h++;
            }
            box[g][h] = ' ';
        }
        if(g == 0 || g == boxLength - 1)
            box[g][h] = '-';
        else if(h == 0 || h == boxWidth - 1)
            box[g][h] = '|';
        else
            box[g][h] = ' ';
    }
}