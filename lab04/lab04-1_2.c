/*----------------------------------------------------------------------------
-		                 SE 185: Lab 04 - Debugging Code	    	         -
-	Name:		Jesus Horacio Soto Gonzalez 
- 	Section:	1															 -
-	NetID:		jhsoto														     -
-	Date:		9/23/2022															 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
void force(double mass, double acceleration); //Changed to double

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab04-1_2.c -o lab04-1_2
// Run with ./lab04-1_2
/* This program takes two inputs, acceleration and mass,
 * and outputs the force = mass * acceleration */

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    double mass;
	double acceleration; // Declare variable.

    printf("Enter an acceleration in m/s^2: ");
    scanf("%lf", &acceleration);

    printf("Enter the mass of the object in kg: ");
    scanf("%lf", &mass);

    printf("\nYou entered %lf m/s^2.\n", acceleration);
    printf("You entered %lf kg.\n\n", mass);

    force(mass, acceleration);

    return 0;
}

/**
 * Given mass and acceleration, calculates the force exerted.
 *
 * @param mass - The given mass of an object in kilograms.
 * @param acceleration - The acceleration of an object in m/s^2.
 */
void force(double mass, double acceleration)
{
    printf("The force is approximately %.2lf Newtons.\n", mass * acceleration);
	
}
