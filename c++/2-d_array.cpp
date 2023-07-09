#include<iostream>
using namespace std;
#include<climits>

int main()
{
    //making of 2-D array
    int m,n;
    cout<<"for a";
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }cout<<"\n";
    }
    // spiral order print
    int row_strt=0,row_end=m-1,col_strt=0,col_end=n-1;
    while(row_strt < row_end && col_strt < col_end){

        // for first row
        for(int col=col_strt;col<=col_end;col++){
            cout<<a[row_strt][col]<<" ";
        }cout<<"\n";
        row_strt++;

        // for last col
        for(int row=row_strt;row<=row_end;row++){
            cout<<a[row][col_end];
        }cout<<"\n";
        col_end--;

        // for last row
        for(int col=col_end;col>=col_strt;col--){
            cout<<a[row_end][col];
        }cout<<"\n";
        row_end--;

        // for first col
        for(int row=row_end;row>=row_strt;row--){
            cout<<a[row][col_strt];
        }cout<<"\n";
        col_strt++;
    }

    // transposing matrix
    int at[n][m];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int temp = a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    }

    // matrix multiplication
    int a[m][n];
    int x,y;
    cout<<"for b"; 
    cin>>y;
    int b[n][y];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin>>b[i][j];
        }
    }/*we are finding a*b */
    if (n==x){
    for(int i=0;i<n;i++){
        for(int j=n;j<n;j++){
            
        }
    }
    }

    // search in a sorted matrix
    int r=0,c=3,target;
    bool flag = false;
    while(r<3 && c>0){
        int value = a[r][c];
        if(value=target){
            flag = true;
        }
        else if(value<target){
            r++;
        }
        else if(value>target){
            c--;
        }
    }if(flag){
        cout<<"found";
    }else{cout<<"does not exist";}
    return 0;
}
