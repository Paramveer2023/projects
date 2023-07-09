#include<iostream>
using namespace std;
#include<math.h>

bool primecheck(int a){
    for(int i=2;i<a;i++){
        if(a%i==0){
            return false;}
    }
    return true;
    }

void fib(int a){
    int f0 = 0;
    int f1 = 1;
    int t;
    cout<<0<<"\t";
    for (int i = 1;i<=a;i++){
        t = f0+f1;
        f0 = f1;
        f1 = t;
        cout<<t<<"\t";}}

int fact(int a ){
    if(a==0){
        return 1;
    }
    int factn = 1;
    int fact1=1;
    for(int i=2;i<=a;i++){
        factn = factn*fact1*i;
    }return factn;}

int ncr(int n,int r){
    int factn = fact(n);
    int factr = fact(r);
    int factnr = fact((n-r));
    return factn/(factr*factnr);
}

void pascals_triangle(int a){
    for(int i=0;i<=a-1;i++){
        for(int j=0;j<=i;j++){
            cout<<ncr(i,j)<<"\t";
        }cout<<endl;
    }
}

int main()
{
    // int m,n;
    // cin>>m>>n;
    // for(int i=m;i<n;i++){
    //     if(primecheck(i)){
    //         cout<<i<<"\t";
    //     }}

    // fib(10);
    // int x = ncr(12,5);
    pascals_triangle(5);
    
    return 0;
}


