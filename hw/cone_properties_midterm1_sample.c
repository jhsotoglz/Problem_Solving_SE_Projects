#include<stdio.h>
#include<math.h>
//==========================//
#define PI 3.14
//==========================//
//declaring functions
void coneProperties(float h, float r, float result[]);
	
	
//==========================//	
void main(){
	//variable declaration
	float height, radius;

	
	//ask the user to enter the height and the radius
	printf("Please enter the height:\n");
	scanf("%f",&height);
	printf("Please enter the radius:\n");
	scanf("%f", &radius);
	int result [3];
	//function call
	coneProperties (height, radius, result);
	
	//Generate the output by calling the functions
	printf("The area of the cone is: %f\n",coneArea(height,radius));
	printf("The area of the base is: %f\n",baseArea(radius));
	printf("The volume of the cone is:%f\n",coneVol(height,radius));
	
}

//defining the functions
void coneProperties(float h, float r, float result[]){
	return[0] = PI*r*sqrt(h*h+r*r);
	return[1] = PI*r**r;
	return[2] = (1.0/3.0)
//================================//
//coneArea function//
double coneArea(float h, float r){
	return PI*r*sqrt(h*h+r*r);
}//===============================//
//baseArea function//
double baseArea(float r){
	return PI*r*r;
}//==============================//
//coneVolume function//
double coneVol(float h, float r){
	return (1.0/3)*PI*r*r*h;
}//==============================//