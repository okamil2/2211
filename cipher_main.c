#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "ciphers.h"
#include <stdio.h>
#include <ctype.h>


// 
/*
 * c99 to compile, gcc, options -f
 * Main file for using ciphers
 * Displays the plaintext before encrypting.
 * Displays the ciphertext after encrypting.
 * Displays the plaintext after decrypting.
 * Prints a table of letters and their frequency in the ciphertext.
 * Obaida Kamil 250982002
 */


int main(){
        //plain text storage variable
        char plaintext[250];
        int choice;

        //Getting the user's message to be ciphered for later
        printf("Input plaintext: ");
        fgets (plaintext, 250, stdin);

        //getting the user's choice
        printf("Available Ciphers\n  1) Ceasar\n  2) Vignere\n");
        scanf("%d", &choice);

        //cipher choice
        switch(choice) {
            case 1:{
                //in this case we are applying the ceaser cipher and we are showing the user what is happening
                int num_key;
                printf("Input Key: ");
                //get they key plus we check if we were successful in getting the key
                int check = scanf("%d",&num_key);
                if (check != 1){
                    printf("Input key can only be a number!\n");
                    exit(EXIT_FAILURE);
                }
                //printing the original text
                printf("Text before encryption:\n%s", plaintext);

                //the text after encryption
                char *cipherText = caesar_encrypt(plaintext,num_key);
                printf("Test after encryption: \n");
                printf("%s",cipherText);
                printf("\n");

                //return to orig text
                printf("Text after decryption: \n");
                char *origText = caesar_decrypt(cipherText,num_key);
                printf("%s",origText);
                double letters[26];
                // run frequency analysis and print
                freq_analysis(plaintext,letters);
                for(int i=0; i<26 ; ++i){

                    if ((i % 4) == 0){
                        printf("\n");
                    }
                    printf("%c --> %lf %%\t",i+'a', letters[i]);
                }
                printf("\n");
                // freeing memeory up
                free(origText);
                origText = NULL;
                free(cipherText);
                cipherText = NULL;
                break;
            }
                
            case 2:{
                //applying the vigenere and showing the user what is happening
                char key;
                printf("Input Key: ");
                scanf("%s",&key);
                if (!checkString(&key)){
                    printf("Input key can only be letters!\n");
                    exit(EXIT_FAILURE);
                }
                double letters[26];
                printf("\n");
                //printing the original text
                printf("Text before encryption:\n%s", plaintext);
                printf("\n");
                //the text after encryption
                char *cipherText = vigen_encrypt(plaintext,&key);
                printf("Text after encryption: \n");
                printf("%s",cipherText);
                printf("\n");
                //returning orig text
                printf("Text after decryption: \n");
                char * origText = vigen_decrypt(cipherText,&key);
                printf("%s",origText);
                break;
            }
                
            default: printf("Bad input!\n");
        }
                // run frequency analysis and display in nicely formatted table
                freq_analysis(plaintext, letters);
                for(int i = 0 ; i < 26 ; ++i){
                    if ((i % 4) == 0){
                        printf("\n");
                    }
                    printf("%c: %lf %%\t",i+'A', letters[i]);
                }
                printf("\n");
                // freeing memory up
                free(origText);
                free(cipherText);
    return 0;

}
