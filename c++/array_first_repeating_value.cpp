#include<iostream>
using namespace std;
#include<climits>

// int main()
// { int array[10]={12,45,65,41,52,67,43,79,99,33};
//     // max till i
//     int a[10];
//     int maxno = INT_MIN;
//     for(int i=0;i<=sizeof(array)/4;i++){
//         maxno = max(array[i],maxno);
//         a[i] = maxno;
//     }for(int i=0;i<=9;i++){
//         cout<<a[i]<<"\t";}
//     return 0;
// }

// int main()
// {int array[10]={12,45,65,41,52,67,43,79,99,33};
// // sum of all subarrays
// int sum = 0;
// for(int i=0;i<=9;i++){
//     int sum = 0;
//     for(int j=i;j<=9;j++){
//         sum+=array[j];
//         cout<<sum<<"\t";
//     }
// }    
//     return 0;
// }

// int main()
// {int array[10]={12,14,16,18,20,22,24,26,28,30};
//     // longest airthmatic subarray

//     int cdn=0,cdl=array[1]-array[0],ans=0,countern = 2;
//     for(int i = 1;i<=9;i++){
//         cdn = array[i+1] - array[i];
        
//         if(cdl==cdn){
//             countern+=1;
//         }
//         else{cdl=cdn;
//             ans = max(countern,ans);
//             countern = 2;
//         }
//     }
//     cout<<ans;
//     return 0;}

// int main()
// {int a[5]={12,7,56,45,20};
// // maximum visitors
//     int maxv = -1,ans = 0;
//     int size = 5;
//     a[size] = -1;
//     if(size==1){
//             cout<<'1';
//             return 0;
//         } 
    
//     for(int i=0;i<size;i++){
//         maxv = max(maxv,a[i]);
//         if(a[i]>maxv && a[i]>a[i+1] ){
//         cout<<a[i]<<"_"<<i<<"\t";
//         ans+=1;
//         }
//     }cout<<ans;
//     return 0;
// }


 int main()
//  first +ve
 {  int n;
    cin>>n;
    int a[n];
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }

    const int N = 1e6 +2;
    int check[N];
    for(int i=0;i<=N;i++){
        check[i]=0;
    }
    for(int i=0;i<=n;i++){
        if(a[i]>=0){
            check[a[i]]=1;
        }
    }for(int i;i<=N;i++){
        if(a[i]==1){
            cout<<i;
            break;
        }
    }
    return 0;
 }
 
//  int main()
// {
//     // repeating string counter
//     char check[26];
    
//     for(int i=0;i<26;i++){
//         check[i] = 0;
        
//     }
//     int n;
//     int a[n];
//     for(int i=0;i<n;i++){
//         int j = a[i] - 'a';
//         a[j] = a[j] + 1;
//     }
//     for(int i=0;i<26;i++){
//         cout<<a[i]<<"\n";
//     }
//     return 0;
// }
