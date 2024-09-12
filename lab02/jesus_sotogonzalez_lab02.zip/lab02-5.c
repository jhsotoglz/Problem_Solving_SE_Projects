/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name:		Jesus Horacio Soto Gonzalez																 -
- 	Section:	1															 -
-	NetID:		jhsoto@iastate.edu														     -
-	Date:		9/9/2022															 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>   // Google this header file to learn more! :)

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double a, b, csquare;
    double filler;

    /* Put your code after this line */
	
	
	printf("Enter the value for a: \n");
	scanf("%lf", &a);
	printf("Enter the value for b: \n");
	scanf("%lf", &b);
	csquare = ((a * a) + (b * b)); 

    /* This next line will calculate the square root of whatever value is
     * inside the parenthesis and assigns it to the variable filler. */
    filler = sqrt(csquare);
	printf("The result value is: %lf\n", filler);
    return 0;
}
