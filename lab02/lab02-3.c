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

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int integer_result;
    double decimal_result;

    integer_result = 77 / 5;
    printf("The value of 77/5 is %lf, using integer math.\n", integer_result); // Wrong format specifier for int, the correct format specifier is %d.
	
	printf("The value of 77/5 is %d, using integer math. \n", integer_result); // Correct program


    integer_result = 2 + 3;
    printf("The value of 2+3 is %d.\n"); // There is no int_result assing so the answer can not be provided.
	
	printf("The value of 2+3 is %d.\n", integer_result); // Correct program
   
   
	decimal_result = 1.0 / 22.0;
	printf("The value 1.0/22.0 is %d.\n", decimal_result); // Wrong format specifier for double, the correct one is %lf.
	
	printf("The value 1.0/22.0 is %lf.\n", decimal_result); // Correct program

    return 0;
}
