#include<stdio.h>
void arr(int*a,int s);
int count_odd(int arr[],int n);
int reverse(int arr[],int n);
int fib(int a);
int main(){ 
    // int n=1;
    // int num[10];
    // for(int i=0;i<=2;i++){
    //     printf("enter next value in array : ");
    //     scanf("%d",&num[i]);
    // }
    // printf("%d \n",(num[0]+(0.8*num[0])));
    // printf("%u",&num[0]);
    // int par[] = {45,95,15,65};
    // int a = 45;
    // printf("add of a %u \n",&a);
    // int b = 78;
    // printf("add of b %u \n",&b);
    // int*p = &a;
    // printf("add of point at a %u \n",p);
    // p = p-1;
    // printf("incremented add %u \n",*p);

    // arrayy is a pointer
    // int array[]={1,2,3,4,5};
    // int*l=array;
    // l++;
    // printf("%d",l);
    // printf("%d",&array[1]);
    // for(int i=1;i<=5;i++){
    //     printf("%d \n",*l);
    //     l++;
    // }
    // int array[]={1,34,56,78,16,15} ;
    // int* p= &array[0];
    // arr(p,6);
    // int arr[2][4] = {{1,2,3,4},{7,8,9,10}};
    // printf("%d \n",arr[1][4]);
    // int arr[]={12,5,78,42,96,26,28,34};
    // reverse(arr,8);
    // for(int i=0;i<8;i++){
    //     printf("%d \n",arr[i]);
// }
    int array[2][10];
    for(int i=1;i<=10;i++){
        array[0][i-1] = 2*i;
        
        array[1][i-1] = 3*i;
        
    }
    for(int i=0;i<10;i++){
        printf("%d \t",array[0][i]);}
    for(int i=0;i<10;i++){
        printf("%d \t",array[1][i]);}
    return 0;
}
void arr(int*a,int s){
    for(int i;i<=s;i++){
        printf("%d \n",*a);
        a++;
    }
    }
int count_odd(int arr[],int n){
    int counter = 0;
    for(int i=0;i<=n;i++){
        if (arr[i]%2!=0){
            printf("its odd %d \n",arr[i]);
            counter++;
        }
    }return printf("%d",counter);
}
int reverse(int arr[],int n){
    for(int i=0;i!=n || i<n;i++,n--){
        int temp = arr[i];
        arr[i]=arr[n-1];
        arr[n]=temp;
    }
    
}
int fib(int a){
    int n1=1,n2=1,c;
    int array[a];
    for(int i=0 ;i<=a;i++){
        if(i==0){
            c=0;
        }
        else if(i==1){
            c=n1;
        }
        else if(i==2){
            c=n2;
        }else{ 
        c = n1 + n2;
        n1 = n2;
        n2 = c;
        }
        printf("%d \t",c);
        array[i]=c;
    }
}
