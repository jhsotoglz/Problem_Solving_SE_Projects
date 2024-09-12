#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	char str1[20] = "Fun";
	char str2[20] = "With";
	char str3[20] = "Strings";
	
	strcpy(str1, str3);
	strcpy(str3, str2);
	strcpy(str1, str2);
	if(strcmp(str2, str1) == 0)
	{
			printf("%s", str3);
	}
	else
	{
			printf("%s", str1);
	}
}