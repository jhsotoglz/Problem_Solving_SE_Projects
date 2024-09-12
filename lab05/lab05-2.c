/*----------------------------------------------------------------------------
-		         SE 185: Lab 05 - Conditionals (What's up?)	    	         -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
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
	void controller_direction(double gx, double gy, double gz, double ax, double ay, double az);
	int close_to (double tolerance, double point, double value);

/*----------------------------------------------------------------------------
-	                                Notes                                    -
-----------------------------------------------------------------------------*/
// Compile with gcc lab05.c -o lab05
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -a -g -b | ./lab05

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int triangle, circle, x_button, square;
    double ax, ay, az, gx, gy, gz;


    while (1)
    {
        scanf("%lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d",
              &ax, &ay, &az, &gx, &gy, &gz, &triangle, &circle, &x_button, &square);

        /* printf for observing values scanned in from ds4rd.exe,
         * be sure to comment or remove in final program */
        //printf("Echoing output: %lf, %lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d \n",
              // ax, ay, az, gx, gy, gz, triangle, circle, x_button, square);
		
        /* It would be wise (mainly save time) if you copy your code to calculate
         * the magnitude from lab03-1.c. You will also need to copy your
         * prototypes and functions to the appropriate sections in this program. */

	   // printf("The acceleration's current magnitude is: %lf\n", magnitude(ax, ay, az)); 
		controller_direction(gx, gy, gz, ax, ay, az);
		
	
	}
		
    return 0;
}

/* Put your functions here, and be sure to put prototypes above. */

	double magnitude(double x, double y, double z)
{
    
     return sqrt((x * x) + (y * y) + (z * z));

}
 
 void controller_direction(double gx, double gy, double gz, double ax, double ay, double az)
 {
	int change = 0;
	int current;
	
		if((close_to(.1, 0, magnitude(ax, ay, az)))){
			
		if (change != current){
			
			if ((close_to (0.3,0,gx)) & (close_to(0.3, 1, gy)) & (close_to (0.3, 0.2, gz))){
				printf("\nTOP\n");
					change = 0;
					
			}if ((close_to (0.3,0,gx)) & (close_to(0.3, -1, gy)) & (close_to (0.3, 0.2, gz))){
				printf("\nBOTTOM\n");
					change = 1;
					
			}if ((close_to (0.3,0,gx)) & (close_to(0.3, 0.3, gy)) & (close_to (0.3, -1, gz))){
				printf("\nFRONT\n");
					change = 2;
					
			}if ((close_to (0.3,0,gx)) & (close_to(0.3, -0.25, gy)) & (close_to (0.3, 1, gz))){
				printf("\nBACK\n");
					change = 3;
					
			}if ((close_to (0.3,1,gx)) & (close_to(0.3, 0, gy)) & (close_to (0.3, 0, gz))){
				printf("\nLEFT\n");
					change = 4;
					
			}if ((close_to (0.3,-1,gx)) & (close_to(0.3, 0, gy)) & (close_to (0.3, 0, gz))){
				printf("\nRIGHT\n");
					change = 5;
	} 	
		current = change;
	}
	}
 }
 int close_to (double tolerance, double point, double value)
 {
	 if((point - tolerance <= value) && (point + tolerance >= value)){
		 return 1;
	 }
	 else{
		 return 0;
	 }
 }
	 