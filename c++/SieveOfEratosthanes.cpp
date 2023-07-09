#include<iostream>
using namespace std;
#include<string>
#include<climits>
#include<algorithm>

int smallest_prime_factor(int n){
    int array[n];
    for(int i=2;i<=n;i++){
        array[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(array[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(array[j]==j){
                    array[j]=i;
                }
            }
        }
    } while(n!=1){
        cout<<array[n]<<" x ";
        n = n/array[n];
        }}


int sieve_of_eratosthanes(int n)
{
    int prime[n] = {0};
    for(int i=2;i<=n;i++){
        if (prime[i]==0){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=1;
            }
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]==0){
            cout<<i<<"\t";
        }
    }
}

int main()
{
    smallest_prime_factor(88);
    return 0;
}
