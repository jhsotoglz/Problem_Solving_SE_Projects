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
	int counter;
	int r = 0;
	int c = COLUMNS / 2;
	int buffer = 1000;
	

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
	for (int i = 0; i < NUM_SAMPLES; i++){
		scanf("%d, %lf, %lf, %lf", &time, &new_x, &new_y, &new_z);
			x[i]=new_x;
			y[i]=new_y;
			z[i]=new_z;
		}

    /* Event loop */
	counter = 0;
    do
    {
        /* Read data, update average */
		scanf("%d, %lf, %lf, %lf", &time, &new_x, &new_y, &new_z);

        avg_x = m_avg(x, lengthofavg, new_x);
        avg_y = m_avg(y, lengthofavg, new_y);
        avg_z = m_avg(z, lengthofavg, new_z);
		

        /* Is it time to move?  if so, then move avatar */
		if (time > counter + buffer){
			c = find_c(avg_x, c);
			r = r + 1;
			counter = time;
			if ((calc_roll == 1.0) && ((MAZE[c - 1][r] == ' '))){	//Left  calc_roll or avg_x???????
				draw_character(c, r, ' ');
				c = c -1;
				draw_character(c, r, 'A');
			}
		if ((calc_roll == - 1.0) && ((MAZE[c + 1][r] == ' '))){		//Right
				draw_character(c, r ' ');
				c = c + 1;
				draw_character(c, r, 'A');
			
			clear();
		}
		draw_character(c, r, 'A');
		

    } while(1); // Change this to end game at right time

    /* Print the win message */


    /* This function is used to cleanup the Ncurses environment.
    Without it, the characters printed to the screen will persist
    even after the progam terminates */
    endwin();

  }

    printf("YOU WIN!\n");
}


}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/* 	Updates the buffer with the new_item and returns the computed
    moving average of the updated buffer */
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


/*	PRE: -1.0 < mag < 1.0
    POST: Returns tilt magnitude scaled to -1.0 -> 1.0
    You may want to reuse the roll function written in previous labs. */
double calc_roll(double mag){
	if (mag > 1.0){
		mag = 1.0;
	}
	else if (mag < -1.0){
		mag = -1.0;
	}
	return mag;
}


/*	POST: Generates a random maze structure into MAZE[][]
    You will want to use the rand() function and maybe use the output %100.
    You will have to use the argument to the command line to determine how
    difficult the maze is (how many maze characters are on the screen). */
void generate_maze(int difficulty){
	int i;
	int j;
	int r;
	
		srand ((int)time(0));
		for (i = 0; i < ROWS; ++i){
			for (j = 0; j < COLUMNS; ++j){
				if (( rand() % 101) < difficulty ){
					MAZE[i][j] = '*';
				}
				else {
					MAZE[i][j] = ' ';
				}
			}
		}
}


/*	PRE: MAZE[][] has been initialized by generate_maze()
    POST: Draws the maze to the screen */
void draw_maze(void){
	int i;
	int j;
	
	for ( i = 0; i < ROWS; ++i){
		for(j = 0; j < COLUMNS; ++j){
			draw_character(i, j, MAZE[i][j]);
		}
	}
}



int find_c( double avg_x, int c){
	if (-0.05 >= avg_x & avg_x <= 0.05);
	else if (avg_x > 0){
		c = c - (avg_x * 10);
	}
	else if (avg_x < 0){
		c = c - (avg_x * 10);
	}
	if (c < 0){
		c = 0;
	}
	if (c > COLUMNS){
		c = COLUMNS;
	}
	return c;
	
}
