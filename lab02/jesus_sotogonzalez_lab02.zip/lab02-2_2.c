/*----------------------------------------------------------------------------
-		        SE 185: Lab 02 - Solving Simple Problems in C	    	 	 -
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
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int x, y, z;
	printf("Enter a lenght:  ");
	scanf("%d", &x);
	
	printf("Enter a height: ");
	scanf("%d", &y);
	
	printf("Enter a width:  ");
	scanf("%d", &z);
	
	printf(" A %d by %d by %d rectangular cube area is %d\n", x, y, z, x*y*z);
	



    return 0;
}
