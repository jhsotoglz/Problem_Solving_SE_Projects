#include<stdio.h>

int main ()
{
	
	int areaCode, exchangeCode, userNumber;
	
	long long int phoneNuumber;

	printf("Enter Phone Number\n");
	scanf("%lld", &phoneNuumber);

	userNumber   = phoneNuumber % 10000;
	areaCode     = phoneNuumber / 10000000;
	exchangeCode = (phoneNuumber / 10000) % 1000;
	
	printf("Area Code is : %d  \n", areaCode);
	printf("Exchange Code is : %d \n", exchangeCode);
	printf("User Number is : %d \n", userNumber);
	
	return 0;

	
	
	
	
	
	
	
	
	
	
	
	
	
}