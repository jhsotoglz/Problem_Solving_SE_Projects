#include <stdio.h>
#include <stdlib.h>
#define pi 3.1416


struct cylinder{
	double radius;
	double height;
};

	double cylinderProperties(struct cylinder d2, double x[2]);
	double cylinderProperties(struct cylinder d2,double x[2]){
		x[0]=(2 * pi*(d2.radius)*(d2.radius)+2*pi*(d2.radius)*(d2.height));
		x[1]=(pi*(d2.radius)*(d2.radius)*(d2.height));
	}

void main(){
	
	struct cylinder d2;
	double x[2];
	
	printf("Radius: ");
	scanf("%lf", &d2.radius);
	printf("Height: ");
	scanf("%lf", &d2.height);
	
	double cylinderProperties(struct cylinder d2, double x[2]);
	
	printf("volume = %0.2lf\nSurface area = %0.2lf\n", x[0], x[1]);
	
}
