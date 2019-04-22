#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* shifte(char message[], int key);

int main() 
{
int choice;
char message[100];
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
        printf("Please enter the plain text you wish to encrypt: \n");
        scanf(" %s", message);
        int key;
        printf("Please enter the key: \n");
        scanf("%d", &key);
        printf("The encrypted text is: \n");
        printf(" %s", shifte(message, key));
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

char* shifte(char message[], int key)
{
	int ascii;
	char encrypted;
	int text_length = strlen(message);
	char *cipher_text=calloc(text_length,8);
	for (int i = 0; i < text_length; i++)
	{
		ascii = (int)message[i];
		if (ascii > 64 && ascii < 91)
		{
			ascii = ascii - 65;
			ascii = (ascii + key) % 26;
			ascii = ascii + 65;
			encrypted = (char)ascii;
			cipher_text[i] = encrypted;
		}
		else
		{
			cipher_text[i] = message[i];
		}
	}
	return cipher_text;
}









//Perhaps have a function to put each letter lower case and reuse
//You have done this all wrong. You should be using the mod 26 method!. This is not that bad of a change but basically means i made no progress