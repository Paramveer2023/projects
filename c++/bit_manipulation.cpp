#include<iostream>
using namespace std;
#include<string>
#include<climits>
#include<algorithm>

int getbit(int n,int pos){
    return ((n &(1<<pos)) != 0);
}
int setbit(int n,int pos){
    return ((n | (1<<pos)) );
}
int clearbit(int n,int pos){
    int mask = ~(1<<pos); 
    return (n & mask);
}
int updatenbit(int n,int pos,int value){
    int mask = ~(1<<pos);
    n = (n & mask);
    mask = (value << pos);
    return (n | mask);
}

// void twice_no(int arr[],int n){
//      xor = 0;
//     for(int i=0;i<n;i++){
//         xor = xor ^ arr[i];
//         cout<<xor<<" ";
//     }
// }
int main()
{
    int arr[] = {1,2,2,4,8,5,4,5,8};
    int a = 100;
    int b = 101;
    cout<<b ^ a;
    return 0;
}



