/*----------------------------------------------------------------------------
-		                    SE 185: Lab 06 - Bop-It!	    	             -
-	Name:		Jesus Soto Gonzalez																 -
- 	Section:	1															 -
-	NetID:		jhsoto														     -
-	Date:		10/14/2022															 -
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
-								Includes									 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*----------------------------------------------------------------------------
-	                            Prototypes                                   -
-----------------------------------------------------------------------------*/
#define TRUE 1
#define FALSE 0


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
int roundTime;
int tB, sB, xB, oB, t;
int rounds;


	roundTime = 2500;
		
		
		while (1){
			printf("Let's Play Bop-It!\n");
			printf("\nPress O to start the game!!!\n");
				while (oB == 0)
								{
					scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);  
								}
				while (oB == 1)
								{
					scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);  
					
								}
								while(1){
									int button;
									button = rand() % 4 + 1;
										if(button = 1)
										{
											printf("\nPRESS THE TRIANGLE BUTTON!!!\n"); 
											printf("\nYou have %d milliseconds to respond!\n", roundTime);
											scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);
												while(roundTime > 0)
												{
													scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);
													if(sB == 1 || xB == 1 || oB == 1)
													{
														printf("\nWrong button\n");
														return 0;
													}
												}
										}
											
										if(button = 2)
										{
											printf("\nPRESS THE SQUARE BUTTON!!!\n");
											printf("\nYou have %d milliseconds to respond!\n", roundTime);
											scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);
												
												while(roundTime > 0 && oB == !1)
												{
													scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);
													if(tB == 1 || xB == 1 || oB == 1)
													{
														printf("\nWrong button\n");
														return 0;
													}
												}
										}
										if(button = 3)
										{
											printf("\nPRESS THE X BUTTON!!!\n");
											printf("\nYou have %d milliseconds to respond!\n", roundTime);
											scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);
												
												while(roundTime > 0 && oB == !1)
												{
													scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);
													if(tB == 1 || sB == 1 || oB == 1)
													{
														printf("\nWrong button\n");
														return 0;
													}
												}
										}
										if(button = 4)
										{
											printf("\nPRESS THE O BUTTON!!!\n");
											printf("\nYou have %d milliseconds to respond!\n", roundTime);
											scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);

												while(roundTime > 0 && oB == !1)
												{
													scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);
													if(tB == 1 || sB == 1 || xB == 1)
													{
														printf("\nWrong button\n");
														return 0;
													}
													
									}
								}
							}
							roundTime = roundTime - 100;
							printf("You completed %d rounds!!!, rounds");
	}

}

/* Put your functions here, and be sure to put prototypes above. */

