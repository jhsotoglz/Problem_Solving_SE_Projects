/*----------------------------------------------------------------------------
-		    SE 185: Lab 03 - Introduction to the DS4 and Functions	    	 -
-	Name:				Jesus Horacio Soto Gonzalez													 -
- 	Section:			#1													 -
-	NetID:				jhsoto@iastate.edu												     -
-	Date:				9/16/2022													 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
double magnitude(double x, double y, double z);
int minutes(int ms);
int seconds(int ms);
int milliseconds(int ms);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab03-1.c -o lab03-1
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -a | ./lab03-1

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int t;
    double ax, ay, az;
	
    while (1)
    {
        scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);

        /* CODE SECTION 0 */
        printf("Echoing output: %08.3lf, %07.4lf, %07.4lf, %07.4lf\n", t / 1000.0, ax * 1000.0, ay * 1000.0, az * 1000.0);
		

        /* 	CODE SECTION 1 */
         
		 printf("At %d ms, the acceleration's magnitude was: %lf\n", t, magnitude(ax, ay, az));


        /* 	CODE SECTION 2 */
        
            printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n",
            minutes(t), seconds(t), milliseconds(t), magnitude(ax, ay, az));
       
    }

    return 0;
}

/* Put your functions here */
	
int minutes(int ms){
		int min = ms / 60000;
		return min;
}
int seconds (int ms){
		int sec = (ms / 1000) % 60;
		return sec;
}
int milliseconds (int ms){
		int mil = ms % 1000;
		return mil;
}		
/**
 * Calculates and returns the magnitude of three given values.
 *
 * @param x - The x-axis scanned values from the DS4 controller.
 * @param y - The y-axis scanned values from the DS4 controller.
 * @param z - The z-axis scanned values from the DS4 controller.
 * @return - The magnitude of the given values.
 */
double magnitude(double x, double y, double z)
{
    // Step 8, uncomment and modify the next line
     return sqrt((x * x) + (y * y) + (z * z));
}

