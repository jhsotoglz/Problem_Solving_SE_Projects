#include <stdio.h>
#include <stdlib.h>

typedef struct point {
		double x;
		double y;
}point_type;

double calc_y_int(point_type *point, double m){
	double b = (point->y) - m * (point->x);
	return b;
}

int main(){
	point_type *p1, *p2;
	double slope, y_int;
	
	p1 = (point_type*)malloc(sizeof(point_type));
	p2 = (point_type*)malloc(sizeof(point_type));		
	
	p1->x=1;
	p2->y=1;
	
	printf("p1 = (%lf,%lf)\n", p1->x, p1->y);
	
	(*p2).x = 2;
	(*p2).y = 3;
	
	slope = (p2->y - (*p1).y) / (p2->x - (*p1).x);
	y_int = calc_y_int(p1, slope);
	
	printf("y = %lfx + %lf\n", slope, y_int);
	
	return 0;
}
