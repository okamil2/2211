#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
this code asks the user for input of a phone number and based on what the user wants
it returns the phone number in different formats.
okamil2, 250982002.
*/

int main(){
        int num1, num2, num3;

        printf("enter the phone number: ");
        scanf("%3d%3d%4d", &num1, &num2, &num3);

        if((num1 < 100 || num1 > 999) || (num2 < 100 || num2 > 999) || (num3 < 1000 || num3 > 9999)){
                printf("Error: Invalid Phone Number!");
                exit(1);

        }

        else{
        while(getchar() !='\n');
                printf("Format Options: ");
                printf("A) Local\n");
                printf("B) Domestic\n");
                printf("C) International\n");
                printf("D) Odd\n");

        char string; // initializing the variable s for the letter;
        scanf(" %c", &string);

                switch(string){
                        case 'A': case 'a': printf("Phone Number: %3d-%4d\n", num2, num3); break;
                        case 'B': case 'b': printf("Phone Number: (%3d) %3d-%4d\n", num1, num2, num3); break;
                        case 'C': case 'c': printf("Phone Number: +1-%3d-%3d-%4d\n", num1, num2, num3); break;
                        case 'D': case 'd': printf("Phone Number:  0%3d  0%3d  %4d\n", num1, num2, num3); break;

                                default: printf("invalid Option!\n");
                }
                exit(0);
        }
}

