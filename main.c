#include <stdio.h>

void shiftd(); //shift decrypt
void shifte(); //shift encrypt

char text[100], ch;
int i, key;

void getmessage()
{
    printf("Enter the plain text you wish to encrypt/decrypt\n");
    scanf("%[^\n]s", text);
}

void getkey()
{
    printf("Enter a key\n");
    scanf("%d", &key);
    
}






int main() 
{
int choice;
getmessage();
getkey();
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
        shifte();
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










void shifte()
{
    for(int i=0; text[i] != '\0'; i++) //As i increases it goes through each character in the array untill the condition '\0' is met (void)
    {
     if(ch >= 'a' && ch <= 'z') //Check if the character is within the boundary. If it is you can simply add the shift
     {
         ch = ch + key; //adding the shift
         if(ch > 'z'){ //Check if the character is outside the boundary. 
             ch = ch - 'z' + 'a' - 1; //The character is outside the boundary. Due to ascii values we can return it to the begging of the alphabet
         }
         text[i]=ch;
     }
     else if(ch >= 'A' && ch <= 'Z')
     {
         ch = ch + key;
         if(ch > 'Z')
         {
             ch = ch - 'Z' + 'A' - 1;
         }
         text[i] = ch;
     }
    }
    printf("Your encrypted message is: %s", text);
}




//Perhaps have a function to put each letter lower case and reuse
//You have done this all wrong. You should be using the mod 26 method!. This is not that bad of a change but basically means i made no progress