#include<iostream>
using namespace std;
#include<string>
#include<climits>
#include<algorithm>

int main()
{
//     string str1 ;
//     string str2;
//     getline(cin,str1);
// // lower to upper
// for(int i=0;i<str1.size();i++){
//    if(str1[i]>='a' && str1[i]<='z') {str1[i] = int(str1[i])-32;}
// }cout<<str1<<"\nbnm";

// // to lower case
// for(int i=0;i<str1.size();i++){
//    if(str1[i]>='A' && str1[i]<='Z') {str1[i] = int(str1[i])+32;}
// }cout<<str1;

// // biggest no. from numeric string
//     string str2;
//     getline(cin,str2);
//     sort(str2.begin(),str2.end(),greater<int>());
//     cout<<str2;

// max time occuring string
string str;
getline(cin,str);
char ans;
int check[26];
for(int i=0;i<26;i++){
    check[i]=0;
}
for(int i=0;i<str.size();i++){
    check[(str[i]-97)]+=1;
}
int maxx=INT_MIN;
int st=0;
for(int i=0;i<26;i++){
    if(maxx<check[i]){
    maxx = max(maxx,check[i]);
    st = i;
    }
}
ans = st + 97;
cout<<ans<<" "<<maxx<<" times";
    return 0;
}
