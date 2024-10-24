#include <stdio.h>

int main (){

    int numbers [10];
    int sum =0;
    float average;


    printf("enter ten numbers:\n");

 for (int i=0; i<10; i++){

    printf("number%d", i+1);
    scanf("%d", &numbers [i]);
    sum += numbers [i];
}
   average = sum / 10.0;

   printf("sum: %d\n", sum);
   printf("average = %.2f\n", average);
}