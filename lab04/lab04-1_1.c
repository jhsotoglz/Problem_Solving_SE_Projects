/*----------------------------------------------------------------------------
-		                 SE 185: Lab 04 - Debugging Code	    	         -
-	Name:			Jesus Horacio Soto Gonzalez														 -
- 	Section:		1														 -
-	NetID:			jhsoto													     -
-	Date:			9/23/2022														 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-1_1.c -o lab04-1_1
// Run with ./lab04-1_1
/* This program outputs if a integer will divide into another integer with no remainder. */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int i, j;

    printf("Enter an integer: "); // Missing semicolon
    scanf("%d", &i);

    printf("Enter another integer: "); // Missing quotation mark before the last parentesis. 
    scanf("%d", &j); // Missing semicolon after scanf function.

    if (j % i == 0)
    {
        printf("%d divides %d\n", i, j);

    } else{  // need to add open brace to start else.

        printf("%d does not divide %d\n", i, j); // Missing letter n for printf function.
        printf("%d %% %d is %d\n", j, i, (j % i));
    }

    return 0;
}
