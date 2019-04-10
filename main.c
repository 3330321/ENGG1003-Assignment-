#include <stdio.h>
/* This is my commit at end of workshop*/
int main() {
    int choice;
    printf("Press 1 for a substitution encrpytion, 2 for a substitution decryption, 3 for a shift encrpytion or 4 for a substitution decrpytion\n");
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
        printf("Please enter the plain text you wish to encrypt\n");
        printf("Please enter the shift\n");
        break;
    }
    case 4:
    {
        printf("You have chosen shift decrpytion/n");
        printf("Please enter the cipher text you wish to decrypt\n");
        printf("Please enter the shift\n");
        break;
    }
}

return 0;
}
