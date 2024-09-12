#include <stdio.h>
#include <string.h>

int main ()
{
	
	char username[20];
	char password[10];

	
	printf("Enter username: \n");
	
	scanf("%s", username);

	
	printf("Enter password: \n");
	
	scanf("%s", password);
	
	if (strcmp(username, "se185@iastate.edu") == 0 && strcmp(password, "ds4rd") == 0) {
		
		printf("Success!");
	}
	else { 
		printf("Username or Password is incorrect.");
	}
	
	return 0;
}
	
	