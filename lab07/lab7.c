/*-----------------------------------------------------------------------------
-					          SE 185 Lab 07 - The DS4 Equalizer
-             Developed for 185-Rursch by T.Tran and K.Wang
-	Name:		Jesus Soto Gonzalez
- 	Section:	1
-	NetID:		jhsoto	
-	Date:		10/21/2022
-
-   This file provides the outline for your program
-   Please implement the functions given by the prototypes below and
-   complete the main function to make the program complete.
-   You must implement the functions which are prototyped below exactly
-   as they are requested.
-----------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
-								Includes
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>


/*-----------------------------------------------------------------------------
-								Defines
-----------------------------------------------------------------------------*/
#define PI 3.141592653589

/* NO GLOBAL VARIABLES ALLOWED */


/*-----------------------------------------------------------------------------
-								Prototypes
-----------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------
    PRE: Arguments must point to double variables or int variables as appropriate
    This function scans a line of DS4 data, and returns
    True when left button is pressed
    False Otherwise
    POST: it modifies its arguments to return values read from the input line.
------------------------------------------------------------------------------------*/
int read_input( int* time,
                double* g_x, double* g_y, double* g_z,
                int* button_T, int* button_C, int* button_X, int* button_S,
                int* l_joy_x, int* l_joy_y, int* r_joy_x, int* r_joy_y ){
					
					int buttonsPressed;
					
					scanf("%d, %lf, %lf, &lf, %d, %d, %d, %d, %d, %d, %d, %d, %d", 
					&time, &g_x, &g_y, &g_z, &button_T, 
					&button_C, &button_X, &button_S,
					l_joy_x, l_joy_y, r_joy_x, r_joy_y);
					
					if ( *button_S == 1){
						
						buttonsPressed = 1;
					}
					else{
						buttonsPressed = 0;
					}
					return buttonsPressed;
	}

/*-----------------------------------------------------------------------------
    PRE: ~(-1.0) <= mag <= ~(1.0)
    This function scales the roll/pitch value to fit on the screen.
    Input should be capped at either -1.0 or 1.0 before the rest of your
    conversion.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleMagForScreen(double rP);//For roll x value goes from -1(Right) to 1(Left) sin of (PI/2) = 1 sin of (-PI/2) = -1
{						 		 // To use the values of 1.0 and -1.0 and output rad we need inverse of sin = arcsin.
	
	if 		(rP < -1.0){
			 rP = -1.0;
		return rP * 39;
	}
	else if (rP > 1.0){
			 rP = 1.0;
		return rP * 39;
	}
	else{
		return rP * 39);
	}
}
		
	

/*-----------------------------------------------------------------------------
    PRE: -128 <= mag <= 127
    This function scales the joystick value to fit on the screen.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleJoyForScreen(int joy){
	if (joy < -128){
		joy = -128;
		return joy / PI;
	}
	else if (joy > 127){
		joy = 127;
		return joy / PI;
	}
	else{
		return joy / PI;
	}
}
	
/*----------------------------------------------------------------------------
    PRE: -39 <= number <= 39
    Uses print_chars to graph a number from -39 to 39 on the screen.
    You may assume that the screen is 80 characters wide.
----------------------------------------------------------------------------*/
void graph_line(int number);

	
/*-----------------------------------------------------------------------------
    PRE: num >= 0
    This function prints the character "use" to the screen "num" times
    This function is the ONLY place printf is allowed to be used
    POST: nothing is returned, but "use" has been printed "num" times
-----------------------------------------------------------------------------*/
void print_chars(int num, char use){
	
	
			


/*-----------------------------------------------------------------------------
-								Implementation
-----------------------------------------------------------------------------*/
int main()
{
    double x, y, z;                     /* Values of x, y, and z axis*/
    int t;                              /* Variable to hold the time value */
    int b_Up, b_Down, b_Left, b_Right;  /* Variables to hold the button statuses */
    int j_LX, j_LY, j_RX, j_RY;         /* Variables to hold the joystick statuses */
    int scaled_pitch, scaled_roll; 	    /* Value of the roll/pitch adjusted to fit screen display */
    int scaled_joy;                     /* Value of joystick adjusted to fit screen display */

    /* Put pre-loop preparation code here */
	
	double *g_x, *g_y, *g_z, *rad;
	
	int *b_Up, *b_Down, *b_Left, *b_Right, *t

    do
    {
        /* Scan a line of input */
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", &t, &x, &y, &z, &b_Up, &b_Down, &b_Left, &b_Right); 
		
		
		
        /* Calculate and scale for pitch AND roll AND joystick */



        /* Switch between roll, pitch, and joystick with the up, down, and right button, respectivly */



        /* Output your graph line */


        fflush(stdout);

    } while (1 ); /* Modify to stop when left button is pressed */

    return 0;

}
