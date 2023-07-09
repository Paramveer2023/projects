#include<iostream>
using namespace std;
#include<climits>

int merge_sorted(int a1[],int m,int a2[],int n,vector<int> &v){
    
    int c1=0;
    int c2=0;
    while(c1<m && c2<n){
        if(a1[c1]<a2[c2]){
            v.push_back(a1[c1]);
            c1++;
        }
        else{
            v.push_back(a2[c2]);
            c2++;
        }
    }
    while(c1<m){
        v.push_back(a1[c1]);
            c1++;
    }
    while(c2<n){
        v.push_back(a2[c2]);
            c2++;
    }
    
}

// int main()
// {
//     //  max sum of subarray
//     int n;
//     cin>>n;
//     int a[n]; 
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     int currsum[n+1];
//     currsum[0]=0;
//     for(int i=1;i<=n;i++){
//         currsum[i] = a[i-1] + currsum[i-1];
//     }
//     int maxsum = INT_MIN;
//     for(int i=1;i<=n;i++){
//         int sum = 0;
//         for(int j=0;j<i;j++){
//             sum = currsum[i] - currsum[j];
//             maxsum = max(sum,maxsum);
//         }
//     }cout<<maxsum;
//     return 0;
// }

// int main()
// {
//     // kaden's algorithm
//     int n;
//     cin>>n;
//     int a[n]; 
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     int currentsum=0;
//     int maxsum;
//     for(int i=0;i<=n;i++){
//         currentsum = currentsum + a[i];
//         if(currentsum<0){
//             currentsum = 0;
//         }maxsum = max(maxsum,currentsum);
//     }cout<<maxsum;
//     return 0;
// }

// int main()
// {
//     // max subarray sum of circular array
//     int n;
//     cin>>n;
//     int a[n]; 
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     int currentsum2 = 0;
//     int maxsum2 = INT_MIN;
//     for(int i=0;i<n;i++){
//         currentsum2 = currentsum2 + a[i];
//         if(currentsum2<0){
//             currentsum2 =0;
//         }
//         maxsum2 = max(maxsum2,currentsum2);
//     }
// int newa[n];
//     for(int i=0;i<n;i++){
//         newa[i] = -a[i];
//     }
//     int currentsum1 = 0;
//     int maxsum1 = INT_MIN;
//     for(int i=0;i<n;i++){
//         currentsum1 = currentsum1 + newa[i];
//         if(currentsum1<0){
//             currentsum1 =0;
//         }
//         maxsum1 = max(maxsum1,currentsum1);
//     }
    
//     int maxsum = maxsum2 - maxsum1;
//     return 0;
// }

int main()
{
    // pair of numbers having sum equal to k
    int n,k;
    cin>>n>>k;
    int a[n]; 
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // for(int i;i<n-1;i++){
    //     int curr = a[i];
    //     for(int j=i+1;j<n;j++){
    //         int sum = a[i] + a[j];
    //         if(sum==k){
    //             cout<<i<<" "<<j;
    //         }
    //     }
    // }/*bruteforce aprroch*/
    int low = 0;
    int high = n-1;
    while(low<high){
        int sum = a[low] + a[high];
        if (sum<k){
            low+=1;
        }
        else if(sum>k){
            high-=1;
        }
        else{
            cout<<low<<" "<<high;
            break;
        }
    }
    
    return 0;
}
