#include<stdio.h>
#include<math.h>

int main ()
{
	float mikeX, mikeY, maryX, maryY, garyX, garyY, loganX, loganY, distance1, distance2, distance3, distance4;
	
	mikeX = 22.05;
	mikeY = 85.10;
	
	maryX = 43.25;
	maryY = 09.80;
	
	garyX = 02.55;
	garyY = 72.86;
	
	loganX = 15.15;
	loganY = 40.40;
	
	
	distance1 = sqrt ( (15.55 - mikeX) * (15.55 - mikeX) + (55.15 - mikeY) * (55.15 - mikeY) );
	distance2 = sqrt ( (15.55 - maryX) * (15.55 - maryX) + (55.15 - maryY) * (55.15 - maryY) );
	distance3 = sqrt ( (15.55 - garyX) * (15.55 - garyX) + (55.15 - garyY) * (55.15 - garyY) );
	distance4 = sqrt ( (15.55 - loganX) * (15.55 - loganX) + (55.15 - loganY) * (55.15 - loganY) );
	
	printf(" The E distance for Mike is: %f\n", distance1);
	printf(" The E distance for Mary is: %f\n", distance2);
	printf(" The E distance for Gary is: %f\n", distance3);
	printf(" The E distance for Logan is: %f\n", distance4);
	

	
	return 0;



}