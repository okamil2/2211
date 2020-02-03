#include <stdio.h>
/* this code asks the user to input an amount of money and returns to the user how much is that in several different bills.
okamil2, 250982002.
*/

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *toonies, int *loonies);

int main() {
	int dollar, twenties, tens, fives, toonies, loonies;
	printf("Enter a dollar amount:\n");

	if (scanf("%d", &dollar) == 0) {// checking to see if there are any errors
		while(getchar() != '\n')
		printf("Enter an integer:\n");
		return 1;
	}
	if (dollar < 0) {
		printf("negative dollar!");
		return 1;
	}
	pay_amount(dollar, &twenties, &tens, &fives, &toonies, &loonies);
	
	printf("You get %d 20s, %d 10s , %d 5s , %d , toonies, %d loonies\n", twenties, tens, fives, toonies, loonies);	
	return 0;
}
//setting up what each bill is worth to return number of possible bills up^^
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *toonies, int *loonies) {
	*twenties = dollars/20;
	dollars = dollars - (*twenties * 20);

	*tens = dollars/10;
	dollars = dollars - (*tens * 10);

	*fives = dollars/5;
	dollars = dollars - (*fives * 5);

	*toonies = dollars/2;
	dollars = dollars - (*toonies * 2);

	*loonies = dollars/1;
}
