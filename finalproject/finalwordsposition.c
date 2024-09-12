///////////////////////////////////////////////////////////////////////////////////////////////////
	
	/*We can try something like this:
	Get the array of words and select a random word. I'm assuming the random word to be 'randomWord'.
	Then get the random word position by using the rand() function, as shown in the code below. */


char randomWord[20]; //This is temporary
int wordLen = strlen(randomWord); //This is temporary
srand(time(0));
//Generates the random position of the word
//Subtract '2' because of the borders of the box and the word length so it can fit in the box
int wordPos = rand() % (boxWidth-wordLen-2);

for(int g = 0; g < boxLength; g++){
    for(int h = 0; h < boxWidth; h++){
        if(g == 1 && h == wordPos){ //Inserts the word at the top and at the random position
            for(int i = 0; i < wordLen; i++){
                box[g][h] = randomWord[i];
                h++;
            }
            box[g][h] = ' ';
        }
        if(g == 0 || g == boxLength - 1)
            box[g][h] = '-';
        else if(h == 0 || h == boxWidth - 1)
            box[g][h] = '|';
        else
            box[g][h] = ' ';
    }
}