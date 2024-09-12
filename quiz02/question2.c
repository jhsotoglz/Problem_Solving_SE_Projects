#include<stdio.h>
#include<math.h>

double DrivingCost(double drivenMiles, double milesPerGallon, double dollarsPerGallon);
int main ()
{
	double drivenMiles, milesPerGallon, dollarsPerGallon;
	printf("Enter driven Miles: ");
	scanf("%lf", &drivenMiles);
		
	printf("Enter Miles per Gallon: ");
	scanf("%lf", &milesPerGallon);
		
	printf("Enter dollars per Gallon: ");
	scanf("%lf", &dollarsPerGallon);
	
	printf("Driving Cost = %.2lf", DrivingCost(drivenMiles, milesPerGallon, dollarsPerGallon));
	printf("\n");
	
	return 0;
	
	
}
double DrivingCost(double drivenMiles, double milesPerGallon, double dollarsPerGallon){
	

	double drivingCost;
	drivingCost = ((drivenMiles * dollarsPerGallon) / milesPerGallon);
	
	return drivingCost;
}