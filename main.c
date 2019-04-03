#include <stdio.h>
/* This is my first commit for the beginning of my week 6 workshop*/
int main() {
    int choice //The two choice ints are used to decide the required function.
    int choice_two
    printf("Press 1 for encryption or 2 for decryption\n"); //Choice for use to encrypt or decrypt
    scanf("%d", &choice);
    if(choice=1){
        printf("Press 1 to encrypt a shift or 2 to encrypt a substitution");
        scanf("%d", &choice_two);
        if(choice_two=1) { //The use has chosen to encrypt a shift
            printf("Please enter the text you with to encrypt");
            scanf();
            printf("")
        else //The user has chosen to encrypt a substitution
            printf("Please enter the text you wish to encrpyt");
        }
    else //The user has chose to decrypt
        printf("Press 1 to decrypt a shift or 2 to decrypt a substition");
   `    scanf("%d", &choice_two);
        if(choice_two=1){ //The use has chosen to decrypt a shift
            printf("Please enter the text you wish to decrypt");
            else //The user has chosen to decrypt a substitution
            printf("Please enter the text you wish to decrypt");
        }
    }

   
   
   
   
   
return 0;
}
