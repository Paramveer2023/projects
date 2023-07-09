#include<bits/stdc++.h>
int binary_search(int arr[],int s,int n,int key){
    int e = n-1;
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        else if(arr[mid]>key){
            e = mid-1;
        }
    }
}
int pivot(int arr[],int n){
    int st=0;
    int end=n-1;
    while(st<end){
    int mid = (st + end)/2;
    if(arr[0]<=arr[mid]){
       st=mid+1; 
    }
    else{
        end=mid;
    }
    }return st;
}
int search_rotated(int arr[],int n,int k){
    int pivotindex = pivot(arr,n);
    if(k>=arr[pivotindex] && k<=arr[0]){
        return binary_search(arr,0,pivotindex,k);
    }
    else{
        return binary_search(arr,pivotindex+1,n-1,k);
    }
}
int First_pos(int arr[],int n,int k){
    int value = binary_search(arr,0,n,k);
    while(value>=0){
        if(arr[value-1] == k){
            value =  binary_search(arr,0,value-1,k);
        }
        else{
            return value;
            }
        }
    }
int Last_pos(int arr[],int n,int k){
    int value = binary_search(arr,0,n,k);
    while(value<=n-1){
        if(arr[value+1] == k){
            value =  binary_search(arr,value+1,n-1,k);
        }
        else{
            return value;
            }
        }
    }
bool ispossible(int arr[],int size,int parts,int mid){
    int p = 1;
    int partssum = 0;
    for(int i=0;i<size;i++){
        if(partssum+arr[i]<=mid){
            partssum+=arr[i];
        }
        else{
            if(p>parts || arr[i]>mid){
                return false;
            }
            partssum = arr[i];
        }
    }
}
int min_max_distributions(int arr[],int size,int parts){
    int s=0;
    int sum=0;
    int ans=-1 ;/*if soln doesnot exist then -1 will be returned*/
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    int e=sum;
    int mid = (s + e)/2;  
    while(s<=e){
        if(ispossible(arr,size,parts,mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = (s+e)/2;
    }return ans;
}
int main()
{
    
    return 0;
}
