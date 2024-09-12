// Lab 09 DS4Talker Skeleton Code       

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses/ncurses.h>
#define WORDLENGTH 11
#define MAXWORDS 100
#define DEBUGM 0   // Set this to 0 to disable debug output

// Reads words from the file into WL and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int read_words(char* WL[MAXWORDS], char* file_name);

// modifies str to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* str);

// Draw_char Function
void draw_character(int x, int y, char use);

int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordcount; 
	wordcount = read_words(wordlist, argv[1]);

	if (DEBUGM) {
		printf("Read %d words from %s \n", wordcount, argv[1]);
		for (int i = 0; i < wordcount; i++) {
			printf("%s,", wordlist[i]);

		}
		printf("\n");
	}

	// most of your code goes here. Do not forget to include the ncurses library 
	
	initscr();
	refresh();
	
	// Create word list
	int xVal = 0, yVal = 0;
		for(int i = 0; i < wordcount; i++){
			mvprintw(yVal, xVal, " %s", wordlist);
			refresh();
			xVal += 15;
			if (xVal > 75){
				yVal++;
				xVal = 0;
			}

		}

		// Row count
		int rowCount = wordcount / 5;
		if(wordcount%rowCount != 0){
			rowCount++;
		}

	//Start loopty loop
	int time, joyDown, joyUp, joyLeft, joyRight, joy5, joy6;
	int b1, b2, b3, b4, b5, b6;
	int curX = 0, curY = 0;
	int prevX = 0, prevY = 0;
	int moveTime = 0;
	int lenghtOfLast = 0;
	int lenghtOfSentence = 0;
	int capitalizeNext = 0;
	
	do{
		
		//Inputs
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", 
		&time, &b1, &b2, &b3, &b4, &b5, &b6, &joyDown, &joyUp, &joyLeft, &joyRight, &joy5, &joy6);


			if (time - moveTime < 500)
			{
				continue;
			}
			
				// Delete previous cursor?

			draw_character(curX, curY, ' ');	
				
				//Assing curX and curY accordingly
			if (joyDown && curY < rowCount - 1){
				curY++;
			}

			else if (joyUp && curY > 0){
				curY--;
			}
			if (joyRight && curX < 60){
				curX+=15;
			}
			if (joyRight && curX > 0){
				curX-=15;
			}
				
				//New Cursor position
			moveTime = time; //Add the delay
			prevX = curX;
			prevY = curY;
			
			// Draw the new cursor
			draw_character(curX, curY, '-');
			
			if (b2){		// Add selection with space
				int indexToUse = curY * 5 + curX / 15;
				lenghtOfLast = strlen(wordlist[indexToUse]) + 1;

				char toAdd[12];
				strcpy(toAdd, wordlist[indexToUse]);
				
				if(capitalizeNext){
					toAdd -= 0X20 // 0X20 = space between words 
				}
			
			mvprintw(rowCount + 2, lenghtOfSentence, " %s", toAdd);
			lenghtOfSentence += lenghtOfLast;
			}

			if (b3){		//Add selection without space
				int indexToUse = curY * 5 + curX / 15;
				lenghtOfLast = strlen(wordlist[indexToUse]);

				char toAdd[12];
				strcpy(toAdd, wordlist[indexToUse]);
				
				if(capitalizeNext){
					toAdd -= 0X20 // 0X20 = space between words 
				}
			
			mvprintw(rowCount + 2, lenghtOfSentence, " %s", toAdd);
			lenghtOfSentence += lenghtOfLast;

			}

			else if (b4){		//Add selection with first letter capitalize
				if (capitalizeNext){
					capitalizeNext = 0;
					mvprintw(rowCount + 1, 0, "    ");
					}
				else {
					capitalizeNext = 1;
					mvprintw(rowCount + 1, 0, "CAP");
				}	
			}

			else if (b1){		//Delete last selection
				int indexToUse = curY * 5 + curX / 15;
				lenghtOfSentence -= lenghtOfLast;
				mvprintw(rowCount + 2, lenghtOfSentence, "      ");	//Debug

			}
			
			}
		while (1);
		endwin();

	}
	

//	return 0; 
//}

// DO NOT MODIFY THIS FUNCTION!

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


// DO NOT MODIFY THIS FUNCTION!
int read_words(char* WL[MAXWORDS], char* file_name)
{
	int numread = 0;
	char line[WORDLENGTH];
	char *p;
	FILE* fp = fopen(file_name, "r");
	while (!feof(fp)) {
		p = fgets(line, WORDLENGTH, fp);
		if (p != NULL) 
		{
			trimws(line);
			WL[numread] = (char *)malloc(strlen(line) + 1);
			strcpy(WL[numread], line);
			numread++;
		}
	}
	fclose(fp);
	return numread;
}

// Draw_char Function
void draw_character(int x, int y, char use)
{	
    mvaddch(y,x,use);
    refresh();
}
