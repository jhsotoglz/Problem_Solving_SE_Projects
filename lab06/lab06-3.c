/*----------------------------------------------------------------------------
-		                    SE 185: Lab 06 - Bop-It!	    	             -
-	Name:																	 -
- 	Section:																 -
-	NetID:																     -
-	Date:																	 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
void buttonsPressed (int b1);
int randomNum();
int roundTime = 2500;

/*----------------------------------------------------------------------------
-	                            Notes                                        -
-----------------------------------------------------------------------------*/
// Compile with gcc lab06.c -o lab06
// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -b | ./lab06

/*----------------------------------------------------------------------------
-								Implementation								 -
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
   
int	b1, b2, b3, b4, t, user;
int count = 0;
int bopIt = 0;
int start;


   srand(time(NULL)); /* This will ensure a random game each time. */
	
	printf("Welcome to BopIt!!!\n");
	printf("Press O to start the game!\n");
	
		while(TRUE){
			scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
				if(b2 == 1 && b1 == 0 && b3 == 0 && b4 ==0){
					bopIt = 1;
				}
				else if (bopIt == 1 && b2 == 0 && b1 == 0 && b3 == 0 && b4 == 0){
							break;
				}
		}
		while (bopIt == 1){
			scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
			if (b2 == 0 && b1 == 0 && b3 == 0 && b4 == 0){
				int button = randomNum();
				start = t;
				if (button == 1){
					while(1){
						scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
						if (b1 == 1){
							count ++;
							break;
						}
						else if (b2 == 1 || b3 == 1 || b4 == 1){
							printf("\nWrong answer!!!\n");
							bopIt = 0;
							break;
						}
						else if (t - start > roundTime){
							printf("\nOut of time!!!\n");
							bopIt = 0;
							break;
						}
						else{ 
							if (roundTime == 0){
								printf("\nOut of time!!!\n");
								bopIt = 0;
								break;
								
						}
						}
					}
					}
					else if (button == 2){
						while (1){
							scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
						if (b2 == 1){
							count ++;
							break;
						}
						else if (b1 == 1 || b3 == 1 || b4 == 1){
							printf("\nWrong answer!!!\n");
							bopIt = 0;
							break;
						}
						else if (t - start > roundTime){
							printf("\nOut of time\n");
							bopIt = 0;
							break;
						}
						else{ 
							if (roundTime == 0){
								printf("\nOut of time!!!\n");
								bopIt = 0;
								break;
								
						}
						}
					}
					}
					else if (button == 3){
						while (1){
							scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
						if (b3 == 1){
							count ++;
							break;
						}
						else if (b2 == 1 || b1 == 1 || b4 == 1){
							printf("\nWrong answer!!!\n");
							bopIt = 0;
							break;
						}
						else if (t - start > roundTime){
							printf("\nOut of time!!!\n");
							bopIt = 0;
							break;
						}
						else{ 
							if (roundTime == 0){
								printf("\nOut of time!!!\n");
								bopIt = 0;
								break;
								
						}
						}
					}
					}
					else if (button == 4){
						while(1){
							scanf("%d, %d, %d, %d, %d", &t, &b1, &b2, &b3, &b4);
						if (b4 == 1){
							count ++;
							break;
						}
						else if (b2 == 1 || b3 == 1 || b1 == 1){
							printf("\nWrong answer!!!\n");
							bopIt = 0;
							break;
						}
						else if (t - start > roundTime){
							printf("\nOut of time!!!\n");
							bopIt = 0;
							break;
						}
						else{ 
							if (roundTime == 0){
								printf("\nOut of time!!!\n");
								bopIt = 0;
								break;
								
						}
						}
					}
					}
					else{ 
							if (roundTime == 0){
								printf("\nOut of time!!!\n");
								bopIt = 0;
								break;
							}
					}
			}
		}
			printf("\nThank you for playing\n");
			printf("\nYou made it through %d rounds!\n");
			
    return 0;
}

void buttonsPressed (int b2){
		if (b2 == 1){
				exit(1);
		}
}

int randomNum(){
	switch(rand () % 4 + 1){
		case 1:
		roundTime = roundTime - 100;
		printf("\nPress the TRIANGLE button!\n");
		printf("\nYou have %d milliseconds to respond!\n", roundTime);
		return 1;
		break;
		case 2:
		roundTime = roundTime - 100;
		printf("\nPress the O button!\n");
		printf("\nYou have %d milliseconds to respond!\n", roundTime);
		return 2;
		break;
		case 3:
		roundTime = roundTime - 100;
		printf("\nPress the X button!\n");
		printf("\nYou have %d milliseconds to respond!\n", roundTime);
		return 3;
		break;
		case 4:
		roundTime = roundTime - 100;
		printf("\nPress the SQUARE button!\n");
		printf("\nYou have %d milliseconds to respond!\n", roundTime);
		return 4;
		break;
	}
}

/* Put your functions here, and be sure to put prototypes above. */

