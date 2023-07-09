#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<climits>
#include<algorithm>

int fact(int n){
    if(n==1){
        return 1;
    }
    return n*fact(n-1);
}

int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}
bool sorted(int a[],int n){
    if(n==1){
        return true;
    }
    int rest = sorted(a++,n-1);
    return (a[0]<a[1] && rest);
}
int arraysum(int arr[],int size){
    if(size==0){
        return 0;
    }
    if(size==1){
        return arr[0];
    }
    int sum = arr[0] + arraysum(arr++,size--);
    return sum;
}
bool linearSearch(int arr[],int size,int key){
    if(size==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    else{
        linearSearch(arr++,size--,key);
    }
}
bool binarySearch(int arr[],int size,int m,int key){
    if(m>size){
        return false;
    }
    int mid = (size+m)/2;
    if(arr[mid]>key){
        binarySearch(arr,mid-1,m,key);
    }
    else if(arr[mid]<key){
        binarySearch(arr,size,mid + 1 ,key);
    }
    else{
        return true;
    }
}
void decreasing_printer(int n){
    if(n==0){
        return;
    }
    cout<<n<<"\t";
    decreasing_printer(n-1);
}
 void increasing_printer(int n){
    if(n==0){
        return;
    }
    increasing_printer(n-1);
    cout<<n<<"\t";
 }   
int first_occur(int arr[],int n,int i,int key){
    if(arr[i]==key){
        return i;
    }
    if(i==n){
        return -1;
    }
    
    return first_occur(arr, n, i+1,key);;
}
int last_occur(int arr[],int n,int i,int key){
    if(i==n){     /*array is of size n-1 so when i will become n that means it crossed size of array and from there it will start returning and then function will get completed*/
        return -1;
    }
    int next = last_occur(arr,n,i+1,key);
    if(next != -1){
        return next; 
    }
    if(arr[i]==key){
        return i;
    }return -1;
}
void reversed(string s){
    if(s.length()==0){
        return;
    }
    string sub = s.substr(1);
    reversed(sub);
    cout<<s[0];
    return;
}
void replacepi(string main){
    if(main.length()==0){
        return;
    }
    if(main[0]=='p' && main[1]=='i'){
    cout<<"3.14";
    replacepi(main.substr(2));}
    else{
        cout<<main[0];
        replacepi(main.substr(1));
    }
    return;
}
void towerofhanoi(int n,char src,char dest,char helper){
    if(n==0){
        return;
    }
    towerofhanoi(n-1,src,helper,dest);
    cout<<"Move from"<<src<<"To"<<dest;
    towerofhanoi(n-1,helper,dest,src);
}
void removedup(string s){
    int st=0,e=1;
    while(e<s.size()){
        if(s[st]==s[e]){
           s.erase(e,1);
        }
        else{
            st++;
            e++;
        }
    }cout<<s;
}
string RemoveDupRecur(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    string ans = RemoveDupRecur(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }return ch+ans;
}
string shiftX(string s){
    if(s.length()==1){
        return s;
    }
    char ch = s[0];
    string ans = shiftX(s.substr(1));
    if(ch=='x'){
        return ans + 'x';
    }
    return ch+ans;
}
void PrintSub(char arr [],vector<char> &ch,int ind,int n){
    if(ind==n){
        for(int i=0;i<ch.size();i++){
            cout<<ch[i]<<" ";
        }cout<<endl;
        return;
        }
    ch.push_back(arr[ind]);
    PrintSub(arr,ch,ind+1,n);
    ch.pop_back();
    PrintSub(arr,ch,ind+1,n);
    }
void printsubac(string s,string ans ){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    printsubac(ros,ans);
    printsubac(ros,ans+ch);
    }

void sayDigits(int n){
    int i = n%10;
    n = n/10;
    if (n==0){
        return;
    }
    sayDigits(n);
    cout<<i;
}
int power(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans = power(a,b/2);
    if(b%2==0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}
void bubblesort(int *arr,int n){
    if(n==0 || n==1){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            int temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
        }
    }
    bubblesort(arr,n-1);
}
int mergeAndsort(int arr[],int low,int high){
    if(low>=high){
        return;
    }
    int mid = (low+high)/2;
    mergeAndsort(arr,low,mid);
    mergeAndsort(arr,mid+1,high);
    merge( arr ,low, mid, high);
}
void merge(int arr[],int low,int mid,int high){
    vector<int> temp;
    int right = mid+1;
    int left = low;
    while(left<=mid && right<=high){
    if(arr[left]<arr[right]){
        temp.push_back(arr[left]);
    }
    else{
        temp.push_back(arr[right]);
    }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
    }
    while(right<=high){
        temp.push_back(arr[right]);
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
int main()
{   int arr[] = {4,8,10,12,17,19};
    int size = 6;
    int key = 170;
    int m = 0;
    bool k = binarySearch(arr,size,m,key);
     if(k){
        cout<<"mil gya bhia";
     }
    return 0;
}
