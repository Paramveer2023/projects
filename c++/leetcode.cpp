#include<bits/stdc++.h>
using namespace std;
int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int sum = A[0];
        int i = 0;
        int j = 0;
        int maxx=0;
        while(j<N-1){
            
            if(sum==K){
                maxx = max(maxx,(j-i+1));
                i++;
                j=i;
            }
            if(sum<K){
                j++;
                sum+=A[j];
                cout<<sum<<" ";
            }
            if(sum>K){
                if(A[i]<0){
                   sum = sum + A[i]; 
                }
                else{
                sum-=A[i];
                }
                i++;
            }
        }
        return maxx;
    } 
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        vector<pair<int,int>> ans;
        int i = 0;
        int j = 0;
        int sum = A[i];
        while(i<N){
            sum+=B[j];
            if(sum==X && j<M){
                ans.emplace_back(A[i],B[j]);
                sum = A[i+1];
                j=0;
            }
            if(sum!=X && j<M){
                j++;
                sum = A[i];
            }
            if(j==(M-1)){
                sum = A[i+1];
                j=0;
                
            }
        }
        return ans;
    }

int main()
{int A[] = {-1, -2, 4, -6, 5, 7};
int B[] = {6, 3, 4, 0} ;
int X = 8 ;
int N = 6;
int M = 4;
int *ptr = &X;
(*ptr)++;
cout<<*ptr; 

 
    return 0;
}
