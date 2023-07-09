#include<stdio.h>
#include<math.h>
int sum(int a ,int b);
void area(int radius,int side,int length,int breadth);
int sumup(int a);
int fact(int a);
int fib(int x);
int main() {
    // for(int i=0;i<=10;i=i+1){
    //     printf("%d \n",i);
    // }
    // int i=1,y;
    // printf("enter value :");
    // scanf("%d",&y);
    // int sum=0;
    // while(i<=y){
    //     sum+=i;
    //     i++;
    // }
    // printf("%d \n",sum);
    // for (char x='a';x<='m';x++)
    // {
    //     printf("%c ,",x);
    // }
    // int n;
    // printf("table of : ");
    // scanf("%d",&n);
    // int sum = 0;
    // for(int i=1;i<=10;i++){
    //     sum+=n;
    //     printf("%d ",sum);
    // }
    // int p;
    // printf("enter next value :");
    // scanf("%d",&p);
    // while (1)
    // {
    // if (p%2==0)
    // {
    // printf("enter next value :");
    // scanf("%d",&p); 
    // }
    // else{
    //     printf("its odd");
    //     break;
    // }

    // }
    // int i;
    // do
    // {
    //    printf("enter no : ");
    //    scanf("%d",&i);
    //    if (i%2!=0){
    //     printf("its odd");  
    //     break;
    //    } 
    // } while (1);
    
    // for(int i=5;i<=50;i++){
    //     if(i%2!=0){
    //         continue;
    //     }
    //     printf("%d ,",i);
    // }
    // int q;
    // printf("factorial of : ");
    // scanf("%d",&q);
    // int fact=1;
    // for(int i=q;i>=2;i--){
    //     fact*=i;
    // }
    // printf("%d",fact);
    // int s = sum(5,4);
    // printf("%d",s);
    // printf("%d",fib(8));
    int n;
    printf("enter value : ");
    scanf("%d",&n);
    int n1=1,n2=1,i,num;
    printf("%d \n",n1);
    printf("%d \n",n2);
    for(i=3;i<=n;i++){
        num = n1 + n2 ;
        printf("%d",num); 
        n1 = n2;
        n2 = num;

    }
    
    
    return 0;
}
int sum(int a ,int b){
    int sum;
    sum = (a*b)-(a+b);
    return sum;
}
void area(int radius,int side,int length,int breadth){
    int c = 3.14*pow(radius,2);
    int s = pow(side,2);
    int r = length*breadth;
    printf("%d",c);
    // printf("%d",s);
    // printf("%d",r);
}
int sumup(int a){
    int i = 0;
    if(a==1){
        return 1;
    }
    
    int add = sumup(a-1) + a;
    return add;
}
int fact(int a){
    if(a==0){
        return 1;
    }
    int factorial = fact(a-1)*a;
    return 
    factorial;
}
int fib(int x){
    if(x==0 || x==1){
        if(x==0){
            return 0;
        }
        else{
            return 1;
        }
    }
    int s = fib(x-1) + fib(x-2);
    // printf("fib series of %d is %d  \n ",x,s);
    return s;
}