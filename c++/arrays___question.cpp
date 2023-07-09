#include<iostream>
using namespace std;
#include<math.h>
#include<vector>
#include<climits>

void zero_at_end(int arr[],int n){
    int a[n];
    int s=0,i=0;
    int e=n-1;
    while(e>=s){
        if(arr[i]!=0){
            a[s] = arr[i];
            s++;
        }
        if(arr[i]==0){
            a[e] = arr[i];
            e--;
        }
        i++;
    }
    for(int i=0;i<n;i++){
        arr[i]=a[i];
    }
}
void rotate(vector<int> &arr,int k){
    vector<int> temp(arr.size());
    for(int i=0;i<arr.size();i++){
        temp[(i+k)%arr.size()] = arr[i];
    }
    arr = temp;
}
bool sorted_rotated_array(vector<int> a){
    int count=0;
    for(int i=1;i<a.size();i++){
        if(a[i-1]>a[i]){
            count++;
        }
    }
    if(a[0]<a[(a.size()-1)]){
            count++;
        }
   return count==1;
}
int array_sum(vector<int> a,int n,vector<int> b,int m){
    int carry = 0;
    vector<int> temp;
    int i = n-1,j=m-1;
    while(i>=0 && j>=0){
        int val1 = a[i];
        int val2 = b[j];
        int sum = val1 + val2 + carry;
        carry = sum/10;
        temp.push_back(sum%10);
        i--;
        j--;
    }
    while(i>=0){
        int sum = a[i] + carry;
        temp.push_back(sum%10);
        carry = sum/10;
        i--;
    }
    while(j>=0){
        int sum = b[j] + carry;
        temp.push_back(sum%10);
        carry = sum/10;
        j--;
    } 
}
void reverse_sentence_words(vector<char> &s){
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i] == ' ' || s[i] == ',' || s[i] == '\0' ){
            int c = i;
            while(j<=i-1){
                int temp = s[i-1];
                s[i-1] = s[j];
                s[j] = temp;
                j++;
                i--;
            }
            i = c;
            j = c+1;
        }
    }
    for(int i = 0;i<s.size();i++){
        cout<<s[i];
    }
}
bool check(int c1[],int c2[]){
    for(int i=0;i<26;i++){
        if(c1[i]==c2[i]){
            return true ;
        }
    }
}
bool check_permutaion(string s1,string s2){
    int check1[26] = {0};
    for(int i=0;i<s1.size();i++){
        check1[s1[i] - 'a']+=1;
    }
    int check2[26] = {0};
    int j = 0,k=0;
    while(j<s1.size() && j<s2.size()){
        check2[s1[j]-'a']+=2;
        j++;
    }
    if(check(check1,check2)){
        return true;
    }
    while(j<s2.size()){
        check2[s1[j]-'a']+=1;
        check2[s1[j] - 'a' - s1.size()] = 0;
        if(check(check1,check2)){
        return true;
    }

    }return false;
}
    
void print_like_wave(int arr[][4],int row,int col){
        int i = 0,j=0;
    while(j<col){
        while(i<row){
            cout<<arr[i][j]<<" ";
            i++;
        }
        cout<<endl;
        j++;
        i--;
        while(i>=0){
            cout<<arr[i][j]<<" ";
            i--;
        }
        cout<<endl;
        j++;
        i=0;
    }

}
void rotate_matrix(int arr[][3],int rows,int cols){
    int re = rows - 1;
    int cs = 0;
    int ce = cols;
    while(cs<ce){
        for(int i=re;i>=0;i--){
            cout<<arr[i][cs]<<" ";
        }
        cout<<endl;
        cs++;
    }
}
void prime_sieve(int n){
    int arr[n] = {0};
    for(int i=2;i<n;i++){
        if(arr[i]==0){
            for(int j=2*i;j<n;j+i){
                arr[j]=1;
            }
        }
    }
}   
int gcd(int n,int m){
    int a  = min(n,m);
    int b = max(n,m);
    while(b%a!=0){
        int c = b%a;
        b = a;
        a = c;
    }
    if(a==1){
        cout<<"coprime_pairs ";
    }
    return a;
}
int main()
{
    // int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // int cs = 0;
    // int ce = 3;
    // int re = 3;
    // while(cs<ce){
    //     for(int i=0;i<re;i++){
    //         cout<<arr[cs][i]<<" ";
            
    //     }
    //     cs++;
    //     cout<<endl;
    // }
    // print_like_wave(arr,3,4);
    // rotate_matrix(arr,3,3);
    cout<<gcd(13,19);
    
    return 0;
}
