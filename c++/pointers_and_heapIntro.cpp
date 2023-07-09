#include<iostream>
using namespace std;
#include<climits>


int main()
{/*pointers logic*/
    int x=12;
    int y=57;
    int z=29;
    int *ptr = &x;
    cout<<&x<<"\n";
    cout<<ptr<<"\n";
    cout<<*ptr<<"\n";
    cout<<&ptr<<"\n";

/*pointers arithmatics*/
    cout<<*(ptr + 1)<<"\n";
    cout<<*(ptr + 2)<<"\n";

/*pointer as array*/
int arr[]={12,23,45,34};
cout<<*(arr + 1)<<"\n";

/*heap intro*/
int a=15;
int*p = new int();
*p = 4;
delete(p);
cout<<*p;
    return 0;
}
