#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* this code asks the user for a date and based on that gives the latest date.
okamil2, 250982002.
*/
int main(){
        int mm, dd, yy, i;
        int mmm=0, mdd=0, myy=0;


        while(i=1){
                printf("Please enter the date (mm/dd/yy): ");
                scanf(" %d/%d/%d", &mm, &dd, &yy);

                if(mm==0 && dd==0 && yy==0){
                        printf("Error: At least one date must be input!\n");

                }

                else{
                        printf("%02d/%02d/%02d is the latest date \n", mmm, mdd, myy);
                }
                exit(0);



        }


        if ((mm < 1 || mm > 12) || (dd < 1 || dd > 31) || (yy < 1 || yy > 99)){
                printf("Error: Invalid date number! \n");
        }

        if(myy < yy){
                myy = yy;
                mmm = mm;
                mdd = dd;
        }

        else if((myy == yy) && (mmm < mm)){
                 mmm = mm;
                 mdd = dd;
        }
        else if (myy==yy && mmm==mm && mdd<dd){
                        mdd = dd;
                }
        }
}
