#include <stdio.h>

int main ()
{
	
	char firstName[40], lastName[40]; 
	char major[20]; 
	char collegeYear[20];
	int graduationYear;
	
	printf("Enter your first name: ");
	scanf("%s", firstName);
	
	printf("Enter the last name: ");
	scanf("%s", lastName);
	
	printf("Enter your major: ");
	scanf("%s", major);
	
	printf("Enter year in college (ex. Freshman, sophomore, etc): ");
	scanf("%s", collegeYear);
	
	printf("Enter your graduation year: ");
	scanf("%d", &graduationYear);
	
	printf("\n");
	
	printf("Name (last, first): Name (%s, %s)\n", lastName, firstName);
	printf("Major: %s\n", major);
	printf("Year: %s\n", collegeYear);
	printf("Graduation Year: %d", graduationYear);
	
	return 0;
	
	
}