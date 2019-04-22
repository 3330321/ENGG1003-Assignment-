#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* shifte(char text[], int key);
char* shiftd(char cipher_text[], int key);

int main() 
{
int choice;
int key;
char text[300];
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
        scanf("%s", text);
        printf("Please enter the key: \n");
        scanf("%d", &key);
        printf("The encrypted text is: \n");
        printf("%s", shifte(text, key));    
        break;
    }
    case 4:
    {
        printf("You have chosen shift decrpytion/n");
        printf("Please enter the cipher text you wish to decrypt\n");
        scanf("%s", text);
        printf("Please enter the shift\n");
        scanf("%d", &key);
        printf("%s", shiftd(text, key));
        break;
    }
    default: printf("\nPlease select a correct option");
    }
return 0;
}

char* shifte(char text[], int key)
{
	int ascii;
	char encrypted;
	int text_length = strlen(text);
	char *cipher_text=calloc(text_length,8);
	for (int i = 0; i < text_length; i++)
	{
		ascii = (int)text[i];
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
			cipher_text[i] = text[i];
		}
	}
	return cipher_text;
}

char* shiftd(char cipher_text[], int key)
{
    {
	int ascii;
	char encrypted;
	int text_length = strlen(cipher_text);
	char *text=calloc(text_length,8);
	for (int i = 0; i < text_length; i++)
	{
		ascii = (int)cipher_text[i];
		if (ascii > 64 && ascii < 91)
		{
			ascii = ascii + 65;
			ascii = (ascii - key) % 26;
			ascii = ascii + 65;
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

