/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
-	Name:		Jesus Horacio Soto Gonzalez															 -
- 	Section:	1															 -
-	NetID:		jhsoto@iastate.edu														     -
-	Date:		9/9/2022															 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
	int integerResult;
	double decimalResult;
	
	integerResult = 6427 + 1725;
	printf("The result value of this calculation is: %d.\n", integerResult); // a
	
	integerResult = (6971 * 3925) - 95;
	printf("The result value of this calculation is: %d.\n", integerResult); // b
	
	decimalResult = 79 + 12 / 5;
	printf("The result value of this calculation is: %.2lf.\n", decimalResult); // c    
	
	decimalResult = 3640.0 / 107.9;
	printf("The result value of this calculation is: %.2lf.\n", decimalResult); // d

	integerResult = (22 / 3) * 3;
	printf("The result value of this calculation is: %d.\n", integerResult); // e
	
	integerResult = 22 / (3 * 3);
	printf("The result value of this calculation is: %d.\n", integerResult); // f
	
	decimalResult = 22 / (3 * 3);
	printf("The result value of this calculation is: %.2lf.\n", decimalResult); // g
	
	decimalResult = 22 / 3 * 3;
	printf("The result value of this calculation is: %.2lf.\n", decimalResult); // h
	
	decimalResult = (22.0 / 3) * 3.0;
	printf("The result value of this calculation is: %.2lf.\n", decimalResult); // i
	
	integerResult = 22.0 / (3 * 3.0);
	printf("The result value of this calculation is: %d.\n", integerResult); // j
	
	decimalResult = 22.0 / 3.0 * 3.0;
	printf("The result value of this calculation is: %.2lf.\n", decimalResult); // k
	
	//-----------------------------------------------------------------------------------------
	
	double areaCircle;
	
	areaCircle = ((23.567 * 23.67) / (4 * M_PI));
	printf("The area of the cirlce is: %.2lf\n", areaCircle);	
	
	//-----------------------------------------------------------------------------------------
	
	double meters;
	
	meters = (14 * 0.3048);
	printf("14 feet is equal to %.2lf meters.\n", meters);
	
	//-----------------------------------------------------------------------------------------
	
	double degreesCelsius;
	
	degreesCelsius = ((76 - 32) / 1.8);
	printf("76 defrees Fahrenheit equals %.2lf Degrees Celsius.\n", degreesCelsius);
	
	
	
	
	
	return 0;
}