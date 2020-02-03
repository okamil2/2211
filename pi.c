#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
We will make this code here to generate random numbers in a predefind range which we will use to perform some mathematical calculations
to generate pi, mean and the standard deviation. okamil2, 250982002.
*/



double estimate_pi(long long n) {
        //initiating variables
        long long int i, in = 0;
        double rat;
        //for loop to generate random numbers and store them
        for (i = 1; i <= n; i++) {
                double x = (double)rand()/(double)RAND_MAX;
                double y = (double)rand()/(double)RAND_MAX;

        if (((x*x)+(y*y)) <= 1)
                in++;
        } //the code below to calculate ratio
        rat = ((double)in/(double)n);
        return 4*rat;
}
int main() {
        srand(time(0));
        long long int N;
        printf("Enter N Value: ");
        //read the number that the user enters
        scanf("%lld", &N);
        int i;
        double pval[10], tot=0;

        //estimate pi value
        printf("Estimated pi value:\n");
        for (i=0; i<10; i++) {
                pval[i] = estimate_pi(N);
                printf("%d\t\t\t%.10f\n", (i+1), pval[i]);
                tot = tot + pval[i];
        }
        // code to calculate the mean
        double mu = tot/10;
        double sum = 0;
        for (i=0; i<10; i++) {
                sum = sum + pow((pval[i] - mu),2);
        }
        //code to calculate standard deviation
        sum = sum /10;
        double sd = sqrt(sum);
        printf("Estimated mu = %.10f\n", mu);
        printf("Standard Deviation = %.10f\n", sd);
}


