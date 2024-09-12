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
                int* l_joy_x, int* l_joy_y, int* r_joy_x, int* r_joy_y );

/*-----------------------------------------------------------------------------
    PRE: ~(-1.0) <= mag <= ~(1.0)
    This function scales the roll/pitch value to fit on the screen.
    Input should be capped at either -1.0 or 1.0 before the rest of your
    conversion.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleMagForScreen(double rad);//For roll x value goes from -1(Right) to 1(Left) sin of (PI/2) = 1 sin of (-PI/2) = -1
						 		 // To use the values of 1.0 and -1.0 and output rad we need inverse of sin = arcsin.
	
	
		
	

/*-----------------------------------------------------------------------------
    PRE: -128 <= mag <= 127
    This function scales the joystick value to fit on the screen.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleJoyForScreen(int rad);
	
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
void print_chars(int num, char use, char positive, char negative);
	
	
			


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
    int scaled_joy; 
	int button;	
                  /* Value of joystick adjusted to fit screen display */

    /* Put pre-loop preparation code here */
	
	double *g_x, *g_y, *g_z, *rad;
	
	int *b_Up, *b_Down, *b_Left, *b_Right, *t

    do
    {
        /* Scan a line of input */
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d", &t, &x, &y, &z, &b_Up, &b_Down, &b_Left, &b_Right, &j_LX, &j_LY, &j_RX, &j_RY); 
		
		
		
        /* Calculate and scale for pitch AND roll AND joystick */
			scaled_pitch 	= 	scaleMagForScreen(x);
			scaled_roll 	= 	scaleMagForScreen(z-0.21); //z-0.21 helps when controller is flat
			scaled_joy		=	scaleJoyForScreen(j_RX);

        /* Switch between roll, pitch, and joystick with the up, down, and right button, respectivly */
			if (b_Up == 1){
				button = 1;	//Scaled pitch
			}
			else if (b_Right == 1){
				button == 3;	//Scaled joy
			}
			else if (b_Down == 1){
				button == 2;	// Scalled roll
			}
			

        /* Output your graph line */
		if (button == 1){
			print_chars(scaled_pitch, 'R', 'L');
		}
		else if (button == 2){
			print_chars(scaled_roll, 'B', 'F');
		}
		else if (button == 3){
			print_chars(scaled_joy, 'R', 'L');
		}
        fflush(stdout);
			
			if (b_Left == 1){
				break;
			}

    } while (1 ); /* Modify to stop when left button is pressed */

    return 0;

}

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
					
					scanf("%d, %lf, %lf, &lf, %d, %d, %d, %d, %d, %d, %d, %d, %d", 
					&time, &g_x, &g_y, &g_z, &button_T, 
					&button_C, &button_X, &button_S,
					l_joy_x, l_joy_y, r_joy_x, r_joy_y);
					
					return *button_S;
				}
				
/*-----------------------------------------------------------------------------
    PRE: ~(-1.0) <= mag <= ~(1.0)
    This function scales the roll/pitch value to fit on the screen.
    Input should be capped at either -1.0 or 1.0 before the rest of your
    conversion.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleMagForScreen(double rad)//For roll x value goes from -1(Right) to 1(Left) sin of (PI/2) = 1 sin of (-PI/2) = -1
{						 		 // To use the values of 1.0 and -1.0 and output rad we need inverse of sin = arcsin.
	
	if 		(rad < -1.0){
			 rad = -1.0;		 
	}
	else if (rad > 1.0){
			 rad = 1.0;
	}	
		rad = rad * 39;
		return rad;
	
}
/*-----------------------------------------------------------------------------
    PRE: -128 <= mag <= 127
    This function scales the joystick value to fit on the screen.
    POST: -39 <= return value <= 39
-----------------------------------------------------------------------------*/
int scaleJoyForScreen(int rad){
	if (rad < -128){
		rad = -128;
	
	}
	else if (rad > 127){
		rad = 127;

	}
		rad = rad * 0.3046875;
		return rad;
}
	
/*----------------------------------------------------------------------------
    PRE: -39 <= number <= 39
    Uses print_chars to graph a number from -39 to 39 on the screen.
    You may assume that the screen is 80 characters wide.
----------------------------------------------------------------------------*/
void graph_line(int num){
	if (num < -39){
		num = -39;
	}
	else if (num > 39){
		num = 39;
	}
	
}

/*-----------------------------------------------------------------------------
    PRE: num >= 0
    This function prints the character "use" to the screen "num" times
    This function is the ONLY place printf is allowed to be used
    POST: nothing is returned, but "use" has been printed "num" times
-----------------------------------------------------------------------------*/
void print_chars(int num, char use, char positive, char negative){
	int i;
	
		if (num >= 0){
			for (i = 0; i < 39; i++){
				printf(" ");
			}
			printf("0");
			for (i = 0; i < num; i++){
				printf("%c", positive);
			}
			printf("\n");
		}
		if(num < 0){
			for(i = 0; i > -39 - num; i--){
				printf(" ");
			}
			for(i = num; i < 0; i++){
				printf("%c", negative);
			}
			printf("0\n");
		}
	}

	
				
				
	

