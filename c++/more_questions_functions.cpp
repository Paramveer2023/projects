#include<iostream>
using namespace std;
#include<math.h>
int sum_n(int a){
    int k = a*(a+1)/2;
    return k;
} 
void pythagoras_check(int p,int h,int b){
    if( pow(h,2)==pow(p,2)+pow(b,2)){
        cout<<"Its pythagorian triplet and hypotenus is "<<h;}
    else if( pow(b,2)==pow(h,2)+pow(p,2)){
        cout<<"Its pythagorian triplet and hypotenus is "<<b;}
    else if( pow(p,2)==pow(h,2)+pow(b,2)){
        cout<<"Its pythagorian triplet and hypotenus is "<<p;}
    else{
        cout<<"Its not a pythagorian triplet";
    }}

int binaryToDecimal(int a){
    int k,i=0;
    int ans=0;
    
    while(a>0){
        k = a%10;
        ans+=(k*pow(2,i));
        a = a/10;
        i++;
    }return ans;
}
int octalToDecimal(int a){
    int k,i=0;
    int ans=0;
    
    while(a>0){
        k = a%10;
        ans+=(k*pow(8,i));
        a = a/10;
        i++;
    }return ans;
}

void DecimalToBinary(int a){
    int k;
    while(a>0){
        k = a%2;
        a/=2;
        cout<<k;
    }
}

void DecimalToOctal(int a){
    int k;
    while(a>0){
        k = a%8;
        a/=8;
        cout<<k;}}

/ decimal to binary
// int main()
// {
//     int n,x=1,ans=0;
//     cin>>n;
//     while(x<=n){
//         x=x*2;
//     }
//     x=x/2;
//     while(x>0){
//         int bin = n/x;
//         n = n-bin*x;
//         x = x/2;
//         ans = (ans*10) + bin;
//     }
//     cout<<ans;
//     return 0;
// }

// decimal to octal
// int main()
// {
//     int n,x=1,ans=0;
//     cin>>n;
//     while(x<=n){
//         x = x*8;
//     }
//     x = x/8;
//     while(x>0){
//         int oct = n/x;
//         n = n - oct*x;
//         x = x/8;
//         ans = ans*10+oct;
//     }cout<<ans;
//     return 0;
// }

// decimal to hexadecimal

// int main()
// {   int n;
//     string ans;
//     int x=1;
//     cin>>n;
//     while(x<=n){
//         x=x*16;
//     }
//     x = x/16;
//     while(x>0){
//         int hex = n/16;
//         n = n - hex*16;
//         x = x/16;
//         if(hex <=9){
//             ans = ans + to_string(hex);
//         }
//         else if(hex>=10){
//             char c  = hex -10 + 'A';
//             ans.push_back(c); 
//         }
//     }cout<<ans;
//     return 0;
// }

// hexa to decimal
int main()
{   string n;
    cin>>n;
    int ans = 0,x=1;
    for(int i=n.size()-1;i>=0;i--){
        if(n[i]>='1' && n[i]<='9'){
         ans += int(n[i])*x;
        }
        else if(n[i]>='A' && n[i]<='F'){
            int c = (n[i] - 'A') +10;
            ans += c*x;
        }
        x*=16;
    }cout<<ans;
    
    return 0;
}

