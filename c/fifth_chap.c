#include<stdio.h>
void swap(int*a,int*b);
int main() {
// int age = 56;
// int p = 894;
// int *x ;
// x = &age;
// *x = 560;
// x = &p;
// printf("%d \n",&x);
// printf("%d",x);    
float **pptr;
float *ptr;
float x=100.00;
ptr = &x;
pptr = &ptr;
// printf("%f \n",x);
// printf("%f \n",*ptr);
// printf("%f",**pptr);
int a=25,b=52;
swap(&a,&b);
printf("%d and %d",a,b);

return 0;
}
void swap(int*a,int*b){
    int x = *a;
    *a = *b;
    *b = x;
    printf("now a is %d and b is %d \n",*a,*b);
}