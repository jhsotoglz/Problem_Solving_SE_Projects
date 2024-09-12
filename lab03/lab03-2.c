/*----------------------------------------------------------------------------
-		    SE 185: Lab 03 - Introduction to the DS4 and Functions	    	 -
-	Name:		Jesus Horacio Soto Gonzalez															 -
- 	Section:	#1															 -
-	NetID:		jhsoto@iastate.edu														     -
-	Date:		9/16/2022															 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-2.c -o lab03-2
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -b | ./lab03-2

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/

int buttonsPressed(int triangle, int circle, int x, int square);

int main(int argc, char *argv[])
{
	int triangle, circle, x, square;
    while (1)
    {
	scanf("%d, %d, %d, %d", &triangle, &circle, &x, &square);
	printf("Buttons pressed = %d\n", buttonsPressed(triangle, circle, x, square));
	
		
	
    }

    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */
	int buttonsPressed(int triangle, int circle, int x, int square)
	{
		int buttonspressed;
	buttonspressed = triangle + circle + x + square;
	return buttonspressed;
	}