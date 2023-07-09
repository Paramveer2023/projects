#include<iostream>
using namespace std;
#include<climits>

// int main()
// {   int n;
//     cin>>n;
//     char arr[n];
//     cin>>arr;
//     int s=0,e=n-1;
//     bool flag = true;
//     while(s<e){
//         if(arr[s]==arr[e]){
//             s++;
//             e--;
//         }
//         else{
//             flag = false;
//             break;
//         }
//     }if(flag){
//         cout<<"yes its a palindrome";
//     }
    
//     return 0;
// }

int main()
{
    // largest word in sentence
    int n;
    cin>>n;
    cin.ignore();
    char arr[n+1];
    cout<<"enter your sentence  ";
    cin.getline(arr,n);
    cin.ignore();
     int j=0,count=0,maxx = 0;
     while(arr[j] != '\0'){
        if(arr[j] == ' ' || arr[j] == '\0'){
            maxx = max(maxx,count); 
            count = 0;
        }
            
        else{
            count++; 
        }
        j++;
        maxx = max(maxx,count);
     }cout<<maxx;
    return 0;
}
