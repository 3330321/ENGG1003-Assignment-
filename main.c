#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* shifte(char text[], int key); //Function for shift encryption
char* shiftd(char cipher_text[], int key); //Function for shift decryption
char* sube(char text[], char subkey[]); //Function for substitutiton encryption
char* subd(char keysub[], char cipher_text[]); //Function for substitution decryption

/*
"%[^\n]*c has been used throughout the program. This scans for all text the user 
enters untill a new line is encountered. This allows text with spaces to be entered.
*/

int main() 
{
int choice=-1;
int key=0;//This is the key in the shift cipher
char keysub[30]; //This is the key in the substitution cipher
char text[300]; //This is the text the user enters
printf("\nPress 1 for a substitution encrpytion\nPress 2 for a substitution decryption\nPress 3 for a shift encrpytion\nPress 4 for a shift decrpytion\nPress 5 to bruteforce shift decryption\n");
scanf("%d", &choice); //Scans for users choice
while ((getchar()) != '\n'); //White the char entered is not a space
switch(choice) { //Switch case to determine what encryption or decryption the user wants
    case 1: 
    {
        printf("You have chosen substitution encryption\n");
        printf("Please enter the plain text you wish to encrypt:\n");
        scanf("%[^\n]%*c", text); 
        printf("Please enter a key including all letters A-Z:\n");
        scanf("%[^\n]%*c", keysub); //Scans for the substitution alphabet
        for(int i=0; i<26; i++)
        {
            printf("%c - %c\n", i+65, keysub[i]); //Used to show how the letters change
        }
        printf("Your encrypted code is: %s", sube(keysub, text)); //Prints the encrypted cipher_text
        break;
    }
    case 2:
    {
        printf("You have chosen substitution decrpytion\n");
        printf("Please enter the cipher text you wish to decrypt:\n");
        scanf("%[^\n]%*c", text); //Scans for cipher text
        printf("Please enter a key including all letters A-Z:\n");
        scanf("%[^\n]%*c", keysub); //Scans for substitution alphabet
        for(int i=0; i<26; i++)
        {
            printf("%c - %c\n", keysub[i], i+65); //Used to show how letters chhange
        }
        printf("Your decrypted code is: %s", subd(keysub, text)); //Prints the decrypted plain text
        break;
    }
    case 3: 
    {
        printf("You have chosen shift encrpytion\n");
        printf("Please enter the plain text you wish to encrypt: \n");
        scanf ("%[^\n]%*c", text); //Scans for plain text
        printf("Please enter the key: \n");
        scanf("%d", &key); //Scans for shift value
        printf("The encrypted text is: \n");
        printf("Your encrypted code is: %s", shifte(text, key));  //Prints the encrpyted cipher text  
        break;
    }
    case 4:
    {
        printf("You have chosen shift decrpytion\n");
        printf("Please enter the cipher text you wish to decrypt:\n");
        scanf ("%[^\n]%*c", text); //Scans for cipher text
        printf("Please enter the shift:\n");
        scanf("%d", &key); //Scans for shift value
        
        printf("Your decrypted code is: %s", shiftd(text, key)); //Prints the decrypted cipher text
        break;
    }
    case 5:
    {
        int number=0; //Used to print line numbers
        int correct; //Used to print the correct answer
        printf("You have chosen shift decryption with no given key\n");
        printf("Please enter the cipher text you wish to decrypt\n");
        scanf ("%[^\n]%*c", text); //Scans for input text
        printf("All potential solutions are:\n");
        for(int key=0; key<27; key++) //Runs through all possible shift values
        {
            printf("%d: %s\n", number, shiftd(text,key)); //Prints in the form "1: TEXT"
            number++;
        }
        printf("\nPlease select which number is the correct:\n");
        scanf("%d", &correct); //Allows the user to select the correct shift
        printf("The decrypted cipher is: %s \nand the shift is %d\n", shiftd(text, correct), correct);
        break;
    }
    
    default: printf("\nPlease select a correct option"); //If the user enters a number that is not an option it will prompt them.
    }
return 0;
}

char* shifte(char text[], int key)
{
	int ascii; 
	char encrypted;
	int text_length = strlen(text); //
	char *cipher_text=calloc(text_length,8); //Allocates memory for cipher text and returns pointer to it
	for (int i = 0; i < text_length; i++) //Program will run till all entered text is processed
	{
	    int islowercase = 0;
		ascii = (int)text[i];
		if(ascii > 96 && ascii< 123) //Convert lower case to upper case
		{
		    ascii -= 32;
		    islowercase++;
	    }

		if (ascii > 64 && ascii < 91)// if the entered text is between A-Z
		{
			ascii = ascii - 65; //A=0, B=1....Z=26
			ascii = (ascii + key) % 26;
			ascii = ascii + 65;
			
			if(islowercase == 1) //If we did detect a lower case this loop it will be returned
			{
			ascii += 32;
		    }

			encrypted = (char)ascii; //The encrypted value is the character at the resultant ascii decimal
			cipher_text[i] = encrypted; //The cipher_text array is filled with the characters
		}
		else
		{
			cipher_text[i] = text[i]; //This avoids all text that isnt A-Z
		}
	}
	return cipher_text;
}

char* shiftd(char cipher_text[], int key)//This is the same as shift encryption except we minus the ascii first
{
    {
	int ascii;
	char encrypted;
	int text_length = strlen(cipher_text); 
	char *text=calloc(text_length,8);
	for (int i = 0; i < text_length; i++)
	{
	    int islowercase = 0;
		ascii = (int)cipher_text[i];
		
		if(ascii > 96 && ascii< 123) //Convert lower case to upper case
		{
		    ascii -= 32;
		    islowercase = 1;
	    }  
		if (ascii > 64 && ascii < 91)
		{
			ascii = ascii + 65;
			ascii = (ascii - key) % 26;
			ascii = ascii + 65;
			
			if(islowercase==1)
			ascii += 32;
			
			encrypted = (char)ascii;
			text[i] = encrypted;
		}
		else
		{
			text[i] = cipher_text[i];
		}
	}
	return text;
}
}

char* sube(char keysub[], char text[]){
    int ascii;
    int text_length = strlen(text);
    char *cipher_text = calloc(text_length, 8);
    for(int i=0; i<text_length; i++) //Runs untill all characters have been processed
    {
        ascii=(int)text[i];
        if (ascii>64 && ascii<91) //If the text is A-Z
        {
        ascii -= 65; //Eg. A=0, B=1...
        cipher_text[i]=keysub[ascii]; //Eg. If the first char of the plaintext was A, its ascii value   
                                      //is 0. If the key was QWERTY, keysub[ascii]=keysub[0]=Q. This means
                                      //A would be encrpyted to Q
        } else {
            cipher_text[i]=text[i]; //Non A-Z characters stay the same
        }
    }
    return cipher_text;
}

char* subd(char keysub[], char cipher_text[]){
    char alphabet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M',  //An array for all letters
                       'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; //of the alphabet
    int ascii;
    int text_length = strlen(cipher_text);
    char *text = calloc(text_length, 8);
    for(int i=0; i<text_length; i++)
    {
        ascii=(int)cipher_text[i];
        if(ascii>64 && ascii<91)
        {
            for(int j=0; j<26; j++)
            {
                if(cipher_text[i]==keysub[j]) //As the for loop runs, it compares the cipher text and 
                                              //key text till theyre equal. At this point 'j', it means
                                              //the letters are the same and thus, this letter is in the
                                              //cipher text.
                {
                    text[i]=alphabet[j];//Since keysub[j]=alphabet[j] we can fill the plaintext.
                    break;
                } else {
                    continue;
                }
            }
        } else {
            text[i]=cipher_text[i]; //Avoids characters outside of A-Z
        }
    }
    return text;
}
