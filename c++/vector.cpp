#include<iostream>
#include<vector>
using namespace std;

void take_display(vector<int> &v,int n){
     int ele;
    for(int i=0;i<n;i++){
        cout<<"enter element to the vector ";
        cin>>ele;
        v.push_back(ele);
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    
}
int main()
{
    vector<int> v1;
    vector<int> :: iterator iter = v1.begin();
    v1.insert(iter ,56);
    take_display(v1,5);
    return 0;
} 
