#include <stdio.h>

int examStat(int midterm1Score[], int result[], int r , int n );//examStat function declaration


int main()
{
    int midterm1Score[30];
	int result[5];
	int r = 5; 
	int n = 30;
    

    printf("Enter student's midterm scores one by one with a space between each input\n");
	for (int i = 0; i < n; i++)    
        scanf("%d", &midterm1Score[i]); //loop to input midterm scores
    
    examStat(midterm1Score, result, r , n); //examStat function call
    
    return 0;
}

//examStat function definition
int examStat(int midterm1Score[], int result[], int r , int n )
{
    int avg;
	int max;
	int min;
	int A = 0;
	int fail = 0;
	int sum = 0; 
	int c = 97; 
	// A,fail,sum,c are initialized as zero and c = 7 because ascii value of a = 97
    
 
    for(int i=0; i< n; i++)
    {
     sum = sum + midterm1Score[i];
    }
    avg = sum/n; //Average calculation
    
    
    min = midterm1Score[0];
	max = midterm1Score[0];

    for(int i = 0; i < n; i++)
    {
        if(midterm1Score[i] < min)
        {
            min = midterm1Score[i]; //calculate min
        }

        if(midterm1Score[i] > max)
        {
            max = midterm1Score[i]; //calculate max
        }
    }  
    
 
    for(int i = 0; i<n; i++) // calculates amount of students that failed, pass, got A
    {
        if(midterm1Score[i]<60)
        {
            fail++; 
        }
        else if(midterm1Score[i]>93)
        {
            A++;
        }
        else
        {
            
        }
    }
    
    result[0]=avg; 
    result[1]=max; 
    result[2]=min; 
    result[3]=fail; 
    result[4]=A;    
    
    for(int i = 0; i<r; i++)
    {
        printf("(%c) %d \n", c ,  result[i]); 
        c++;
    }
    
}