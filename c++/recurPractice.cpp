#include<iostream>
#include<bits/stdc++.h> 
#include <vector>
using namespace std;


void printsub(int ind,vector<int> &ds,int arr[],int n){
    if(ind == n){
        for(auto it : ds){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    ds.push_back(arr[ind]);
    printsub(ind++,ds,arr,n);
    ds.pop_back();
    printsub(ind++,ds,arr,n);
}
int main()
{
    int arr[] = {3,1,2};
    vector<int> ds;
    
    printsub(0,ds,arr,3);

    return 0;
}
