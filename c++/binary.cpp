#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    // prime number
    int a;
    cout<<"enter value of a";
    cin>>a;
    int i;
    for(i=2;i<a;i++){  
        if(a%i==0){
            cout<<"its not prime";
            break;
        }}
        if(i==a){
            cout<<"its prime";
    }

   // reversing a number
   int n,k,a=0;
   cout<<"enter no to be reversed : ";
   cin>>n;
   while(n>0){
        k = n%10;
        n = n/10;
        a = 10*a + k;
   }
   cout<<a;

// check for amstrong no
int same,num,last,sum = 0;
cout<<"enter no to be checked : ";
   cin>>num;
    same = num;
   while(num>0){
    last = num%10;
    cout<<pow(last,3)<<"\t";
    sum+=pow(last,3);
    cout<<sum<<"\t";
    num = num/10;
   }
    if(sum == same){
        cout<<"its armstrong no.";
    }
    else{
        cout<<"its not an armstrong no.";   
    }

// factorial of a number
int fact,factn = 1;
cout<<"enter no. : ";
cin>>fact;
int fact1=1;
for(int i=2;i<=fact;i++){
    factn = factn*fact1*i;
}
cout<<factn;
    return 0;
}
