// Lab 09 DS4Talker Skeleton Code       

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses/ncurses.h>
#define WORDLENGTH 11
#define MAXWORDS 100
#define DEBUGM 0   // Set this to 0 to disable debug output
#define BUFFER 500

// Reads words from the file into WL and trims the whitespace off of the end
// DO NOT MODIFY THIS FUNCTION
int read_words(char* WL[MAXWORDS], char* file_name);

// modifies str to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* str);

// Draw_char Function
void draw_character(int x, int y, char use);

void clearAr(char *array, int num);


int main(int argc, char* argv[]) {
	char* wordlist[MAXWORDS];
	int wordcount;
	int i, t, t_last = 0, b[6], j[10], x=0, y = 0, px = 16, py = 0, currentWordLoc = 0, h;
    char sentence[80], currWord[15], temp[15], history[100][80];
	wordcount = read_words(wordlist, argv[1]);

	if (DEBUGM) {
		printf("Read %d words from %s \n", wordcount, argv[1]);
		for (i = 0; i < wordcount; i++) {
		printf("%s,", wordlist[i]);
		
		}
		printf("\n");
	}

	

// most of your code goes here. Do not forget to include the ncurses library 
	do{

        initscr(0);

        while (!b[5]){ //!joystick click

		scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &t, &b[0], &b[1], &b[2], &b[3], &b[4], &b[5], &j[0], &j[1], &j[2], &j[3], &j[4], &j[5], &j[6], &j[7], &j[8], &j[9]);
        // b[0-5], tri, cir, x, sq, click rstick, click lstick
        // j[0-9], options, share, R2, L2, R1, L1, ljx, ljy, rjx, rjy

        if (t_last == 0)
            t_last = t;

        x = 0;
        y = 0;

        for (i = 0; i < wordcount; i++){ //display list
            mvprintw(y, x, "%15s", wordlist[i]);
            x = x + 15;
            if (x % 75 == 0){
                y++;
                x = 0;
            }
        }    

        draw_character(px, py, ' '); //delete pointer

        if ((j[6] > 120) && (t-t_last >=BUFFER)){ //move right
                t_last = t;
                if(px < 75)
                px = px + 15;
        }

        if ((j[6] < -120) && (t-t_last >= BUFFER)){ //move left
                t_last = t;
                if (px != 16)
                px = px - 15;
        }

        if((j[7] > 120) && (t - t_last >= BUFFER)){//move down 
                t_last = t; 
                if(py <= wordcount / 5) 
                py = py + 1; 
        }

        if((j[7] < -120) && (t - t_last >= BUFFER)){//move up 
                t_last = t; 
                if(py != 0) 
                py = py - 1; 
        }
            draw_character(px, py, '-'); // print pointer 
            currentWordLoc = (px / 15) + (py * 5) - 1; //find word pointer is pointing at 
            strcpy(currWord, wordlist[currentWordLoc]);

        if(b[0] && (t - t_last >= BUFFER)){//triangle; append a space followed by word 
                t_last = t; 
                h++; 
                clearAr(temp, 15); 
                strcpy(temp, " "); 
                strcat(temp, currWord); 
                strcat(sentence, temp); 
        }
        
        if(b[1] && (t - t_last >= BUFFER)){//circle; bonus do later 
            t_last = t; 
        }

        if(b[2] && (t - t_last >= BUFFER)){//X; remove last item 
            if(h > 0){ 
                t_last = t; 
                clearAr(temp, 15); 
                strcpy(temp, " "); 
                strcpy(sentence, history[h - 1]); 
                clearAr(history[h], 80); 
                h--;
            }
        }

        if(b[3] && (t - t_last >= BUFFER)){//Sq; add word, no space 
            t_last = t; 
            h++; 
            clearAr(temp, 15); 
            strcat(temp, currWord); 
            strcat(sentence, temp); 
        } 

            strcpy(history[h], sentence); 
            mvprintw((wordcount / 5) + 5, 0, " "); 

            mvprintw((wordcount / 5) + 5, 0, "%s", history[h]); refresh(); 
    } 
            
            clearAr(sentence, 80); 
}

while(1); 
    
        refresh(); 
        endwin(); 
        
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


void clearAr(char *array, int num){ 
    int i; for(i = 0; i < num; i++){ 
        array[i] = 0; 
        } 
        
        array[0] = '\0';
}

// Draw_char Function
void draw_character(int x, int y, char use)
{	
    mvaddch(y,x,use);
    refresh();
}
