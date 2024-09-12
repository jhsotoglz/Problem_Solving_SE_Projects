// Lab 9 DS4Talker Skeleton Code

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
//#include <ncurses/ncurses.h>

#define MAXWORDS 100
#define WORDLEN 11
#define PI 3.14159265359
#define DEBUG 0 // set to 0 to disable debug output


//gcc lab9-3.c -o lab9-3 -lncurses
//./ds4rd.exe -d 054c:05c4 -D DS4_BT -t -j -b -bt| ./lab9-3.exe wordslist.txt
//./ds4rd.exe -d 054c:09CC -D DS4_BT -t -j -b -bt| ./lab9-3.exe "wordslist.txt"
// reads words from the file
// into wl and trims the whitespace off of the end

// DO NOT MODIFY THIS FUNCTION
int read_words(char* WL[MAXWORDS], char* file_name);

//modifies s to trim white space off the right side
// DO NOT MODIFY THIS FUNCTION
void trimws(char* str);

int Quadrent(int x,int y);

double Magnitude(int x, int y);

int IsCharAbleToBeCapitalized(char in);

char Capitalize(char in);

enum Direction{Right,Left,Up,Down};

int main(int argc, char* argv[]) {
    char* wordlist[MAXWORDS];
    int wordcount = 0;
    int i;
    char sentence[11000];
    char spaceArray[] = " ";
    wordCount = readWords(wordlist, argv[1]);

    initscr();

    if (DEBUG) {
        printf("Read %d words from %s \n",wordcount, argv[1]);
        for (i = 0; i< wordcount; i++) {
        printf("%s,", wordlist[i]);
        }

        printf("\n");
    }

// most of your code goes here. Don't forget to include the ncurses library
    int numberOfColumns = 5;
    int numberOfRows = wordCount / numberOfColumns;
    int numOfCharsInWordInSentence[MAXWORDS];
    int cursorX = 0; //must be between 0 & numberOfColumns -1
    int cursorY = 0; //must be between 0 & numberOfRows - 1
    int time, b1,b2,b3,b4;
    int RJoyX, RJoyY, LJoyX, LJoyY;//these range from -128 - 127. They're an

    unsigned byte
    double radiusOfDeadZone = 25.0;
    int isMoving = 0;//bool
    int SecondsToWaitBeforeMoving = 350;
    int WaitTimeHolder;
    int b1Off, b2Off, b3Off, b4Off, JoyButtonOff; //all booleans telling
    
    b1Off = 0;
    b2Off = 0;
    b3Off = 0;
    b4Off = 0;
    
    int a,LJoyButton,c,d,e,f,g,h;
    LJoyButton = 0;
    int wordIndex = 0;

//there is no char index. To find the char index use the array
// numOfCharsInWordInSentence

    int capitolizeFirstLetterOfNextWord = 0;//boolean

//you have an array of words. We need to print the words
//with a space. Try printing only one column

/* How this code works:
to find the direction of the joystick it uses arctan of the
xpos/ypos
then every time interval the cursor moves in the direction held if
the magnitude
is greater than a threashold.
The array wordlist is ran through and printed out to curses by a
nested for loop.
Bounds are put on how far the cursor can move and how many words in
the sentence there
can be.
The sentence is just a gigantic array consisting of 11001
characters.
We use an array of ints to keep track of the amount of characters in
one word.
We also have an index value.
When word is added its length is stored in an array and the index
value increases.
When a word is backspaced the characters on curses are filled with
spaces,
then a \0 is added. Lastly the index decreases.
Deleting the full sentence is repeated use of the prior instruction.
*/
while(1){
    scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d,
            %d, %d,", &time, &b1, &b2, &b3, &b4, &a,&LJoyButton,&c,&d,&e,&f,&g,&h, &RJoyX,
                &RJoyY, &LJoyX, & LJoyY);
//the joystick values are flipped
    RJoyY *= -1; //note the y bounds are now -127 - 128
    LJoyY *= -1;
    int wordItteraror = 0;
        for(int x = 1; x < numberOfColumns + 1; x++){
        //y then x
        for(int y = 0; y < numberOfRows; y++){

            mvprintw(y * 2, x * 8,"%s", wordlist[wordItteraror]);
                wordItteraror++;
            }
        }
    int quadrant = Quadrent(RJoyX,RJoyY);
    isMoving = (radiusOfDeadZone < Magnitude(RJoyX,RJoyY));
        
        if(isMoving == 1){ //if the cursor should be moving
        if(isMoving == 1){//the magnitude is still high enough
        
        if(time > WaitTimeHolder){
        mvaddch(cursorY * 2,((cursorX + 1) * 8) - 1, ' ');
    //move and set a new time
        if(quadrant == 1 && cursorX + 1 < numberOfColumns)
            cursorX++;
        else if(quadrant == 2 && cursorY > 0)
            cursorY--;
        else if(quadrant == 3 && cursorX > 0)
            cursorX--;
        else if(quadrant == 4 && cursorY + 1 < numberOfRows)
            cursorY++;
                WaitTimeHolder = time + SecondsToWaitBeforeMoving;
                }
        }
    else{//the magnitude is not high enough
        isMoving = 0;
        WaitTimeHolder = time;
        }
    }
    if(b1 && !b1Off){// assuming it is triangle
        if(wordIndex < MAXWORDS + 1){
        strcat(sentence, spaceArray);
        if(!capitolizeFirstLetterOfNextWord){//if we don't need to capitolizeFirstLetterOfNextWord
        strcat(sentence, wordlist[(cursorX * numberOfRows + cursorY)]);
    }
    else{//if we do need to capitolizeFirstLetterOfNextWord
        char stringWithCapitol[WORDLEN];
        strcpy(stringWithCapitol,wordlist[(cursorX *
        numberOfRows + cursorY)]);
        if(IsCharAbleToBeCapitolized(stringWithCapitol[0]))
        stringWithCapitol[0] = Capitolize(stringWithCapitol[0]);
        strcat(sentence,stringWithCapitol);
        capitolizeFirstLetterOfNextWord = 0;
    }
numOfCharsInWordInSentence[wordIndex] =
strlen(wordlist[(cursorX * numberOfRows + cursorY)]) + 1;
wordIndex++;
b1Off = 1;
}
}
else if(b2 && !b2Off){// assuming it is circle
if(wordIndex < MAXWORDS + 1){
if(!capitolizeFirstLetterOfNextWord){
strcat(sentence, wordlist[(cursorX * numberOfRows
+ cursorY)]);
}
else{

char stringWithCapitol[WORDLEN];
strcpy(stringWithCapitol,wordlist[(cursorX *
numberOfRows + cursorY)]);
if(IsCharAbleToBeCapitolized(stringWithCapitol[0]))
stringWithCapitol[0] =
Capitolize(stringWithCapitol[0]);
strcat(sentence,stringWithCapitol);
capitolizeFirstLetterOfNextWord = 0;
}
numOfCharsInWordInSentence[wordIndex] =
strlen(wordlist[(cursorX * numberOfRows + cursorY)]);
wordIndex++;
b2Off = 1;
}
}
else if(b3 && !b3Off){// assuming it is X
if(wordIndex > 0){
//the for loop bellow removes the characters from the
curses table
wordIndex--;
for(int i = strlen(sentence) -
numOfCharsInWordInSentence[wordIndex]; i < strlen(sentence); i++){
mvaddch(numberOfRows * 2, i, ' ');
}
//appends a null termiator
sentence[strlen(sentence) -
numOfCharsInWordInSentence[wordIndex]] = '\0';
b3Off = 1;
}
}
else if(b4 && !b4Off){// assuming it is square
capitolizeFirstLetterOfNextWord = 1;
b4Off = 1;
}
else if(LJoyButton && !JoyButtonOff){
if(wordIndex > 0){
//the for loop bellow removes the characters from the
curses table
while(wordIndex > 0){
wordIndex--;
for(int i = strlen(sentence) -
numOfCharsInWordInSentence[wordIndex]; i < strlen(sentence); i++){
mvaddch(numberOfRows * 2, i, ' ');
}
//appends a null termiator
sentence[strlen(sentence) -
numOfCharsInWordInSentence[wordIndex]] = '\0';
}
JoyButtonOff = 1;
}
}
if(!b1){
b1Off = 0;
}
if(!b2){
b2Off = 0;
}
if(!b3){
b3Off = 0;
}
if(!b4){

b4Off = 0;
}
if(!LJoyButton){
JoyButtonOff = 0;
}
//draws cursorX
//first parameter is y
mvaddch(cursorY * 2,((cursorX + 1) * 8) - 1, '>');
mvprintw(numberOfRows * 2, 0, sentence);
refresh();
fflush(stdout);
}
 return 0;
}
int IsCharAbleToBeCapitolized(char in){
return (in >= 97 && in <=122);
}
char Capitolize(char in){
return (char)(in - 32);
}
int Quadrent(int x,int y){
int quad = 1;
double angle = atan((double)y/(double)x);
if(x < 0){
angle = PI + angle;
}
if(angle <= PI/4 &&angle >= -PI/4){
//right quadrant
quad = 1;
}
else if(angle <-PI/4 || angle >= 5 * PI/4){
//bottom quadrant
quad = 4;
}
else if(angle > PI/4 && angle <= 3 * PI/4){
//upper quadrant
quad = 2;
}
else{
//angle > 3*PI/4 && angle <= 5* PI/4
//left quadrant
quad = 3;
}
return quad;
}
double Magnitude(int x, int y){
return pow(pow(x,2) +pow(y,2),0.5);
}
// DO NOT MODIFY THIS FUNCTION
void trimws(char* s) {

 int len = strlen(s) ;
 int x;
 if (len ==0) return;
 x = len-1;
 while (isspace(s[x]) && (x>=0)) {
 s[x] = '\0';
 x--;
 }
 }

// DO NOT MODIFY THIS FUNCTION
int readWords(char* wl[MAXWORDS], char* filename) {
    int numread =0;
    char line[WORDLEN];
    char *p;
    FILE* fp = fopen(filename,"r");
while (!feof(fp)) {
    p =fgets(line, WORDLEN, fp);
        if (!feof(fp) && p !=NULL) {
            trimws(line);
    wl[numread] = (char *) malloc(strlen(line)+1);
    strcpy(wl[numread], line);
    numread++;
        }
    } 
    fclose(fp);
    return numread;
}