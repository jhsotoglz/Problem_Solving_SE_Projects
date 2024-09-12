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

int roundTime;
int tB, sB, xB, oB, t;
int button;

int main(int argc, char *argv[])

{
int outofTime;
int lessT;


	roundTime = 2500;
	oB = 0;
	
		printf("Welcome to the BOP-It GAME!\n");
		
		
		while (TRUE){
			printf("\nPress O to start the game!!!\n");
				while (oB == 0)
								{
					scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);  
								}
				while (oB == 1)
								{
					scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);  
					
								}
									    srand(time(NULL)); /* This will ensure a random game each time.*/
									while(TRUE){
										button = rand()%4 + 1; 
											if(button = 1)
											{
												printf("\nPRESS THE TRIANGLE BUTTON!!!\n"); 
												scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);
												
												int outofTime = t;
												int lessT = 0;
												
													while(lessT < roundTime && tB == !1)
													{
														scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);
														if(sB == 1 || xB == 1 || oB == 1)
														{
															printf("\nWrong button\n");
															return 0;
														}
														lessT = (t - outofTime);
													}
											}
											
											if(button = 2)
											{
												printf("\nPRESS THE SQUARE BUTTON!!!\n");
												scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);
												
												int outofTime = t;
												int lessT = 0;
												
													while(lessT < roundTime && sB == !1)
													{
														scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);
														if(tB == 1 || xB == 1 || oB == 1)
														{
															printf("\nWrong button\n");
															return 0;
														}
														lessT = (t - outofTime);
													}
											}
											if(button = 3)
											{
												printf("\nPRESS THE X BUTTON!!!\n");
												scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);
												
												int outofTime = t;
												int lessT = 0;
												
													while(lessT < roundTime && xB == !1)
													{
														scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);
														if(tB == 1 || sB == 1 || oB == 1)
														{
															printf("\nWrong button\n");
															return 0;
														}
														lessT = (t - outofTime);
													}
											}
											if(button = 4)
											{
												printf("\nPRESS THE O BUTTON!!!\n");
												scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);
												
												int outofTime = t;
												int lessT = 0;
												
													while(lessT < roundTime && oB == !1)
													{
														scanf("%d, %d, %d, %d, %d", &tB, &sB, &xB, &oB, &t);
														if(tB == 1 || sB == 1 || xB == 1)
														{
															printf("\nWrong button\n");
															return 0;
														}
														lessT = (t - outofTime);
										}
									}
								}
									
		}

}

/* Put your functions here, and be sure to put prototypes above. */

