// Lab 09 DS4Talker Skeleton Code       

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <ncurses/ncurses.h>
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
	int i;
	int currword = 0;
	int currcol = 0;
	int curX = 0;
	int curY = 0;
	int looper = 0;
	int time, joyLX, joyLY, joyLeft, joyRight;
	int b1, b2, b3, b4;
	wordcount = read_words(wordlist, argv[1]);

	if (DEBUGM) {
		printf("Read %d words from %s \n", wordcount, argv[1]);
		for (i = 0; i < wordcount; i++) {
		printf("%s,", wordlist[i]);
		
		}
		printf("\n");
	}

		initscr();

// most of your code goes here. Do not forget to include the ncurses library 
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 5; j++){
			mvprintw(i, currcol * 15, "%15s", wordlist[currword]);
			currword++;
			currcol++;
		}
		currcol = 0;
	}
	mvprintw(15, 0, "%15s", wordlist[currword]);
	refresh();

	while (looper = 0){
		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d", &time, &b1, &b2, &b3, &b4, /*&b5, &b6*/ &joyLX, &joyLY, &joyLeft, &joyRight /*&joy5, &joy6*/);
		draw_character(curX, curY, "-");
		refresh();

		if (joyLY > 0){
			curY++;
		}
		else if (joyLY < 0){
			curY--;
		}
		if (joyLX > 0){
			curX += 15;
		}
		else if (joyLX < 0){
			curX -= 15;
		}
		curY++;
		draw_character(curX, curY, "-");
		refresh();
	
	}
	return 0;
}


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
