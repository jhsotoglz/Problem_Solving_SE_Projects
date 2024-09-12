/*----------------------------------------------------------------------------
-		                    SE 185: quiz 06				    	             -
-	Name:				  Jesus Soto Gonzalez								 -
- 	Section:				1												 -
-	NetID:				  jhsoto										     -
-	Date:				  10/21/2022										 -
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

char first_name[50], last_name[50];
char *full_name = NULL;
int num_letters = 0;
									//scanning first and last name
		printf("Please enter your first name:\n");
		scanf("%s", &first_name);
		
		printf("Please enter your last name:\n");
		scanf("%s", &last_name);
		
									// This allocates the full name in memory
	full_name = (char*)malloc(sizeof(char)*(strlen(first_name) + strlen(last_name)+1));
		
		strcpy(full_name, first_name);
		strcat(full_name, " ");
		strcat(full_name, last_name);
		
									// Need to count num of letters
	for(int i = 0; full_name[i] != '\0'; i++)
	{
		if(((*full_name + i) >= 'A' && *(full_name + i) <= 'Z')||(*(full_name + i) >= 'a' && (*full_name + i) <= 'z')){
			num_letters++;
	}
	}

		printf("First name: %s\n", first_name);
		printf("Last name: %s\n", last_name);
		printf("Full name: %s\n", full_name);
		printf("Number of letters: %d\n", num_letters);
	
									//Free allocated memory
	free(full_name);
	return 0;
}
	