/*-----------------------------------------------------------------------------
-					  		SE 185 Lab 08
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name:		Jesus Soto
- Section:			1
-	NetID:		jhsoto
-	Date:		10/28/2022
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <ncurses/ncurses.h>
#include <unistd.h>
#include <time.h> //Add time
#include <stdlib.h>


/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
/* Mathmatical constants */
#define PI 3.14159

/* 	Screen geometry
    Use ROWS and COLUMNS for the screen height and width (set by system)
    MAXIMUMS */
#define COLUMNS 100
#define ROWS 80
#define MAXPOINTS 10000

/* 	Character definitions taken from the ASCII table */
#define AVATAR 'A'
#define WALL '*'
#define EMPTY_SPACE ' '

/*	Number of samples taken to form an moving average for the gyroscope data
    Feel free to tweak this. */
#define NUM_SAMPLES 10


/*-----------------------------------------------------------------------------
-								Static Data
-----------------------------------------------------------------------------*/
/* 2D character array which the maze is mapped into */
char MAZE[COLUMNS][ROWS];


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*	POST: Generates a random maze structure into MAZE[][]
    You will want to use the rand() function and maybe use the output %100.
    You will have to use the argument to the command line to determine how
    difficult the maze is (how many maze characters are on the screen). */
void generate_maze(int difficulty);

/*	PRE: MAZE[][] has been initialized by generate_maze()
    POST: Draws the maze to the screen */
void draw_maze(void);

/*	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y */
void draw_character(int x, int y, char use);

/*	PRE: -1.0 < mag < 1.0
    POST: Returns tilt magnitude scaled to -1.0 -> 1.0
    You may want to reuse the roll function written in previous labs. */
double calc_roll(double mag);

/* 	Updates the buffer with the new_item and returns the computed
    moving average of the updated buffer */
double m_avg(double buffer[], int avg_size, double new_item);


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
/*	Main - Run with './ds4rd.exe -t -g -b' piped into STDIN */
void main(int argc, char* argv[])
{

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
    double new_x, new_y, new_z;
    double avg_x, avg_y, avg_z;
    int lengthofavg = 0;
	int time;
	int counter
	int a = 39;
	int b = 0;
	int difficulty = 0;

  if (argc != 2 )
  {
      printw("You must enter the difficulty level on the command line.");
      refresh();
      return;
  }
  else
  {
    /* 	Setup screen for Ncurses
        The initscr functionis used to setup the Ncurses environment
        The refreash function needs to be called to refresh the outputs
        to the screen */
    initscr();
    refresh();

    /* WEEK 2 Generate the Maze */

    /* Read gyroscope data and fill the buffer before continuing */
	

    /* Event loop */
	
    do
    {
		 

        /* Read data, update average */
		scanf("%d, %lf, %lf, %lf", &time, &new_x, &new_y, &new_z);

        avg_x = m_avg(x, lengthofavg, new_x);
        avg_y = m_avg(y, lengthofavg, new_y);
        avg_z = m_avg(z, lengthofavg, new_z);

        printf("RAW, %lf, %lf, %lf, AVG ,%lf, %lf, %lf\n", new_x, new_y, new_z, avg_x, avg_y, avg_z);
        fflush(stdout);

        /* Is it time to move?  if so, then move avatar */
		++counter;
		if(counter ???? == 0){ //if(time - t2 > 200){ (%15 == 0???)
			if ((MAZE[a][b + 1])== ''){
				draw_character(a, b, ' ');
				b = b + 1;
				draw_character(a, b, 'A');
			}
			if((new_x > 1 ) && ((MAZE[a - 1][b] == '' ))){  //1?
				draw_character(a, b, '');
				a = a - 1;
				draw_character(a, b, 'A');
			}
			if((new_x < - 1 ) && ((MAZE[a + 1][b] == '' ))){  //1? 
				draw_character(a, b, '');
				a = a + 1;
				draw_character(a, b, 'A');
			}
				++counter;
		}
		

    } while(1); // Change this to end game at right time

    /* Print the win message */


    /* This function is used to cleanup the Ncurses environment.
    Without it, the characters printed to the screen will persist
    even after the progam terminates */
    endwin();

  }

    printf("YOU WIN!\n");

  

double m_avg(double buffer[], int avg_size, double new_item)
{
double sum = 0;
	
	for (int i = 0; i < avg_size; i++){
		if (i == avg_size - 1){
			buffer[i] = new_item;
		}
		else{ 
			buffer[i]= buffer[1 + i];
		}
	}
	for (int i = 0; i < avg_size; i++){
		sum = buffer[i] + sum;
	}

	return sum / avg_size;

}


/* 	PRE: 0 < x < COLUMNS, 0 < y < ROWS, 0 < use < 255
    POST: Draws character use to the screen and position x,y
    THIS CODE FUNCTIONS FOR PLACING THE AVATAR AS PROVIDED.
    DO NOT NEED TO CHANGE THIS FUNCTION. */
void draw_character(int x, int y, char use)
{	
    mvaddch(y,x,use);
    refresh();
}







double calc_roll(double mag){
	if (mag > 1.0){
		
		mag = 1.0;
		}
		
	else if (mag < -1.0){
		
		mag = -1.0;
		}
	return mag;
	}


void generate_maze(int difficulty){
	int i, j;
	srand((int)time(0));
		for(i = 0; i < ROWS; i++){
			for(j = 0; j < COLUMNS; j++){
				if (( rand() % 101) < difficulty){
					MAZE[i][j] = '*';
				}
				else{
					MAZE[i][j] = '';
				}
			}
		}
}