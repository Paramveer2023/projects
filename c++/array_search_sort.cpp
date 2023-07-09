#include<iostream>
using namespace std;
#include<math.h>
#include<vector>
#include<climits>

int binary_search(int arr[],int size,int key){
    int max = size;
    int min = 0;
    while(min<=max){
        int c = (min + max)/2;
        if(arr[c]==key){
        cout<<"found at "<< c;
        return 1;
        }
        else if(arr[c]<key){
            min=c+1;
            }
        else {
            max=c-1;
            }}
         cout<<"NOT found";
            return -1;}

int selection_sort(int a[],int size){
    for(int i=0;i<=size-1;i++){
        for(int j=i+1;j<=size;j++){
            if(a[j]<a[i]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }for(int i=0;i<=size-1;i++){
        cout<<a[i]<<"\t";
    }
}

int bubble_sort(int a[],int n){
    int k=1;
    for(int i=0;i<n-2;i++){
        for(int j=0;j<=n-k;j++){
            if(a[j]>a[j+1]){
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }k++;
    }for(int i=0;i<=n-1;i++){
        cout<<a[i]<<"\t";
    }
}

int insertion_sort(int a[],int n){
    for(int i=1;i<=n;i++){
        int current = a[i];
        int j = i-1;
        while (a[j]>current && j>=0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=current;
        
    }for(int i=0;i<=n-1;i++){
        cout<<a[i]<<"\t";
    }
}


int main()
{
    // max and min of array
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    // int mino=INT_MAX;
    // int maxno=INT_MIN;
    // for(int i=0;i<n;i++){
    //     arr[i]>maxno ? maxno=arr[i]: maxno = maxno;
    //     arr[i]<mino ? mino=arr[i]: mino = mino;}
    // cout<<maxno<<" "<<mino;

    // binary search
    // int array[10]={12,24,45,56,78,89,94,105,112,114};
    // binary_search(array,10,112);

// sorting of array
int array[10]={12,45,65,41,52,67,43,79,99,33};

// selection_sort(array,10);
// bubble_sort(array,10);
// insertion_sort(array,10);
int arr1[] = {1,3,5,7,9};
int arr2[] = {2,4,6,8} ;
vector<int> v;
merge_sorted(arr1,5,arr2,4,v);
for(int i=0;i<=9-1;i++){
        cout<<v[i]<<"\t";
    }
    return 0;
}
