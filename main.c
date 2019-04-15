#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* shifte(char message[], int key);

int main() 
{
int choice;
printf("\nPress 1 for a substitution encrpytion\nPress 2 for a substitution decryption\nPress 3 for a shift encrpytion\nPress 4 for a shift decrpytion\n");
scanf("%d", &choice);
switch(choice) { 
    case 1: 
    {
        printf("You have chosen substitution encryption\n");
        printf("Please enter the plain text you wish to encrypt\n");
        break;
    }
    case 2:
    {
        printf("You have chosen substitution decrpytion\n");
        printf("Please enter the cipher text you wish to decrypt\n");
        printf("Please enter "); //How to do the substitution
        break;
    }
    case 3: 
    {
        printf("You have chosen shift encrpytion\n");
        char message[100] = "abcedfghijklmnopqrstuvwxyz"; //alphabet is test text
        char* result = shifte(message, -3); //where -3 is the test key
        printf("result = %s\n", result);
        break;
    }
    case 4:
    {
        printf("You have chosen shift decrpytion/n");
        printf("Please enter the cipher text you wish to decrypt\n");
        printf("Please enter the shift\n");
        break;
    }
    default: printf("\nPlease select a correct option");
    }
return 0;
}

char* shifte(char message[], int key) { //Function for shift encryption
    int i=0;
    while(message[i] != '\0') { //While it is not void
      char letter = message[i];
      letter -= 'a';
      letter += key;
        
      while (letter < 0) {  // if letter is negative, make it positive
        letter += 26;
      }
        
      letter %= 26;
      letter += 'a';
        
      message[i] = letter;  // write new letter back to char array
      
      i++; 
    }
    return message;
}












//Perhaps have a function to put each letter lower case and reuse
//You have done this all wrong. You should be using the mod 26 method!. This is not that bad of a change but basically means i made no progress