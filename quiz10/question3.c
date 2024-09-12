#include <stdio.h>
#include <string.h>

//Funtion declaration
int calc_length(char str[], int count);
 
int main ()
{
	char str[100];
	int len = 0;
    printf ("Enter the string: ");
	scanf ("%s", str);
    len = calc_length (str, 0);
    printf ("The length of %s = %d\n", str, len);
	return 0;
}
 
 //Function definition
int calc_length (char str[], int count)
{
	static int l = 0;
    if (str[count] == '\0')
		return l;
	else
		l++;
 calc_length (str, count + 1); // Recursion
}