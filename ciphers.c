#include <stdlib.h>
#include <string.h>
#include "ciphers.h"
#include <stdio.h>
#include <ctype.h>




/*
* c99 to compile, gcc, option: -f
* functions for caesar and vigen ciphers
* contains frequency analysis
* Obaida Kamil; 250982002
*/



int stringTst( const char s[] )
{
    unsigned char c;

    while ( ( c = *s ) && ( isalpha( c ) ) ) ++s;

    return *s == '\0';
}

char * caesar_encrypt(char *plaintext, int key){

    // finding the correct key, removes the negative ones
    key = key % 26;
     //setting memory to store cipher txts
    char *cipherText = (char *)malloc(260*sizeof(char));

    //checks to see if we have enough memory
    if ( cipherText == NULL){
        printf("Not enough memory!\n");
        exit(EXIT_FAILURE);
    }
    //duplicating the string to keep the original one
    strcpy(cipherText, plaintext);
    //checks the case of the character, then makes them all uppercase
    for (int i = 0; cipherText[i] != '\0';i++){
        cipherText[i] = toupper((char) cipherText[i]);
        if(cipherText[i] >= 'A' && cipherText[i] <= 'Z'){
            int x = ((cipherText[i]- 65) + key) %26;
            x += 'A';
            cipherText[i] = (char) x;
        }

    }

    return cipherText;
}

//decrypting the txt
char * caesar_decrypt(char *ciphertext, int key){
    key = key % 26;
    //setting the memory
    char *out = (char *)malloc(260*sizeof(char));

    //checks to see if we have enough memory
    if ( out == NULL){
        printf("Not enough memory!\n");
        exit(EXIT_FAILURE);
    }
    // duplicating the string to keep the original on
    strcpy(out, ciphertext);

    for(int i=0; out[i] != '\0'; i++){
        if((out[i]>='A'&&out[i] <='Z')){
            int y = ((out[i]- 90) - key) %26;

            y += 'Z';
            out[i] = (char) y;
        }
    }
    return out;
}

char * vigen_encrypt(char *plaintext, char *key){
    char *cipherText;
    char *key_text;
    int j;
    //setting the memory
    cipherText = (char *)malloc(260*sizeof(char));
    key_text = (char *)malloc(260*sizeof(char));

    //checks to see if we have enough memory
    if ( cipherText == NULL){
        printf("Not enough memory!\n");
        exit(EXIT_FAILURE);
    }
    if ( key_text == NULL){
        printf("Not enough memory!\n");
        exit(EXIT_FAILURE);
    }
    // duplicating the string to keep the original on
    strcpy(cipherText, plaintext);
    strcpy(key_text, key);

    for (int i = 0, j=0;cipherText[i] != '\0'; i++, j++){
        if (key_text[j] == '\0')
            j=0;

        cipherText[i] = toupper((char) cipherText[i]);
        key_text[j] = toupper((char) key_text[j]);

        if(cipherText[i] >= 'A' && cipherText[i] <= 'Z'){
            cipherText[i] = ((cipherText[i] + key_text[j]) % 26) + 'A';
        }

    }

return cipherText;
}


char * vigen_decrypt(char *ciphertext, char *key){
    char *plainText;
    char *key_text;
    int j;
    //setting the memory
    plainText = (char *)malloc(260*sizeof(char));
    key_text = (char *)malloc(260*sizeof(char));


    if ( plainText == NULL){
        printf("Not enough memory!\n");
        exit(EXIT_FAILURE);
    }
    if ( key_text == NULL){
        printf("Not enough memory!\n");
        exit(EXIT_FAILURE);
    }
    // duplicating the string to keep the original on
    strcpy(plainText, ciphertext);
    strcpy(key_text, key);

    for (int i = 0,j=0;plainText[i] != '\0'; i++,j++){
        if (key_text[j] == '\0')
            j=0;

        plainText[i] = toupper((char) plainText[i]);
        key_text[j] = toupper((char) key_text[j]);

        if(plainText[i] >= 'A' && plainText[i] <= 'Z'){

            plainText[i] = (((plainText[i] - key_text[j])) % 26);

            if(plainText[i] < 0)
                plainText[i] += 26;
            plainText[i] += 'A';
        }

    }

    return plainText;

}


//gets the percentage of each letter's presence
void freq_analysis(char *ciphertext, double letters[26]){
    for(int i=0 ; i<26; ++i)
        letters[i] = 0.0;
    int total = 0.0;
    for(int i=0; i<strlen(ciphertext) ; ++i){

        ciphertext[i] = tolower((char) ciphertext[i]);

        if(ciphertext[i] >='a' && ciphertext[i] <='z'){
            ++letters[ciphertext[i]-'a'];
            ++total;
        }
    }

    for(int i=0; i < 26 ; ++i){

        letters[i] = letters[i]*100/total;


    }

}




