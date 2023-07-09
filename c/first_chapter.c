# include <stdio.h>
#include <math.h>


int main() {
    int a = 25, b = 8;
    int sum = a+b;
    int mul = a/b;
    int c = 12, d = 10;
    printf("%d",sum);
    printf("%d",mul);

    int x,y;
    printf("enter value of x");
    scanf("%d",&x);

    printf("enter value of y");
    scanf("%d",&y); 

    int z = x/y;
    printf("the value of z is %f",z);

    printf("%d",x*y);

    return 0;

}