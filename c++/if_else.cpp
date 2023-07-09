#include<iostream>
using namespace std;
int main()
{
    int a=1;
    cout<<"enter value to check : ";
    cin>>a;
    
    if (a%2==0)
    {
        cout<<"its even";
    }
    else
    {
        cout<<"its odd";
    }
    // max no code 
    int d,b,c;
    cout<<"enter value of d,b,c : ";
    cin>>d>>b>>c;
    if (d>b & a>c){
        cout<<"d is greatest";
    }
    else if (b>d & b>c)
    {
        cout<<"b is greatest";

    }
    else{
        cout<<"c is greatest";
    }
    do
    {
        cout<<"is this true"<<endl;
        a++;
    } while (a<5);
    
    return 0;
}

