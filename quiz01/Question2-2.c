#include<stdio.h>
#include<math.h>

int main ()
{
	
	float x21, y21, x22, y22, distance;
	
	
	printf("Enter points for Mike: (x21, y21)\n");
	scanf("%f%f", &x21, &y21);
	
	printf("Enter points for School: (x22, y22)\n");
	scanf("%f%f", &x22, &y22);
	
	distance = sqrt( ( x22 - x21) * ( x22 - x21) + ( y22 - y21) * (y22 - y21) ); 
	
	printf("The E distance for Mike is: %f\n", distance );  
	printf("\n");
	
	
	printf("Enter points for Mary: (x21, y21)\n");
	scanf("%f%f", &x21, &y21);
	
	printf("Enter points for School: (x22, y22)\n");
	scanf("%f%f", &x22, &y22);
	
	distance = sqrt( ( x22 - x21) * ( x22 - x21) + ( y22 - y21) * (y22 - y21) ); 
	
	printf("The E distance for Mary is: %f\n", distance );  
	printf("\n");
	
	
	printf("Enter points for Gary: (x21, y21)\n");
	scanf("%f%f", &x21, &y21);
	
	printf("Enter points for School: (x22, y22)\n");
	scanf("%f%f", &x22, &y22);
	
	distance = sqrt( ( x22 - x21) * ( x22 - x21) + ( y22 - y21) * (y22 - y21) ); 
	
	printf("The E distance for Gary is: %f\n", distance );  
	printf("\n");
	
	
	printf("Enter points for Logan: (x21, y21)\n");
	scanf("%f%f", &x21, &y21);
	
	printf("Enter points for School: (x22, y22)\n");
	scanf("%f%f", &x22, &y22);
	
	distance = sqrt( ( x22 - x21) * ( x22 - x21) + ( y22 - y21) * (y22 - y21) ); 
	
	printf("The E distance for Logan is: %f\n", distance );  
	printf("\n");

	
	
	

	
}