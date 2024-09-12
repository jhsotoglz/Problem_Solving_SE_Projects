#include<stdio.h>
#include<string.h>

/*Simulate piggybank that stores coins
pennies, nickles, dime, quarter*/

typedef struct PiggyBank_struct{
	int pennies;
	int nickles;
	int dimes;
	int quarters;
	double total;
}PiggyBank;

PiggyBank initPiggy(int initBal);
void addCoins(char coins, PiggyBank* p);

void main(void){
	PiggyBank p;
	char userInput;
	int initialBalance;
	
	printf("Initial balance: ");
	scanf("%d", &initialBalance);
	
	p=initPiggy(initialBalance);
	
		printf("Add coins\n p=penny..etc\n");
	printf("Type s to smash\n");
	printf("Insert coin: ");
	scanf(" %c", &userInput);
	while(userInput!='S'){
		addCoins(userInput, &p);
		printf("Insert Coin");
		scanf(" %c", &userInput);
	}
	printf("\nYou have %d p, %d n, %d d, %d q\n Total %0.2lf\n", p.pennies, p.nickles, p.dimes, p.quarters, p.total);
}
	


PiggyBank initPiggy(int initBal){
	PiggyBank newPig;
	int remainder;
	
	newPig.total = initBal/100.0;
	
	newPig.quarters = initBal/25;
	remainder=initBal%25;
	
	newPig.dimes=remainder/10;
	remainder=remainder%10;
	
	newPig.nickles=remainder/5;
	newPig.pennies = remainder%5;
	return newPig;
	
}
	
void addCoins(char coins, PiggyBank* p){
	switch(coins){
		case 'P':
			p->pennies +=1;
			p->total+=0.01;
			break;
		case 'N':
			p->nickles +=1;
			p->total+=0.05;
			break;
		case 'D':
			p->dimes +=1;
			p->total+=0.10;
			break;
		case 'Q':
			p->quarters +=1;
			p->total+=0.25;
			break;
		default:
			printf("Error");
			break;
	}
}




