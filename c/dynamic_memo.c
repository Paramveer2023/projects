#include<stdio.h>
#include<stdlib.h>
int main()
{   int *ptr;
//     ptr =(int *) malloc(5*sizeof(int)); /*typecasted into integer */
//     ptr[0] = 870;
//     ptr[1] =45;
//     ptr[2] = 543;

//     int *ptr1;
//     ptr1 = (float * )malloc(5*sizeof(float));
//     ptr[0] = 45.23;

    int *ptr2;
    ptr2 =(int*) calloc(5,sizeof(int));
    ptr2 = realloc(ptr2,3);
    for(int i=1;i<=5;i++){
        ptr2[i]=2*i;}
    ptr2 = realloc(ptr2,6);
    for(int i=1,j=0;i<=13;i=i+2,j++){
        ptr2[j]=i;
    }
    for(int i=0;i<=5;i++){
        printf("%d\t",ptr2[i]);}
    return 0;

}