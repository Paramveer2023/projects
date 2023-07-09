#include<iostream>
using namespace std;
int main(){
// // rectangle pattern

//     for(int i=1;i<=5;i++){
//         for(int i=1;i<=4;i++){
//             cout<<"*\t";
//         }cout<<endl;
//     }

// //  hollow rectangle
//     for(int i=1;i<=5;i++){
//         for(int j=1;j<=4;j++){
//             if((j==2 || j==3) && (i==2 || i==3 || i==4)){
//                 cout<<" ";
//                 continue;
//             }
//             cout<<"*";
//         }cout<<endl;
//     }

// // inverted half pyramid
// for(int i=5;i>=1;i--){
//     for(int j=1;j<=i;j++){
//         cout<<"*\t";
//     }cout<<endl;
// }

// // half pyramid after 180 rotation
// for(int i=4;i>=0;i--){
//     for(int j=1;j<=5;j++){
//         if(j<=i){
//             cout<<" \t";}
//         else{
//             cout<<"*\t";
//         }
        
//     }cout<<endl;
// }
// // half pyramid using no.s
// for(int i=1;i<=5;i++){
//     for(int j=1;j<=i;j++){
//         cout<<i<<"\t";
//     }cout<<endl;
// }
// // floyd's traingle
// int k=1;
// for(int i=1;i<=5;i++){
//     for(int j=1;j<=i;j++){
        
//         cout<<k<<"\t";
//         k++;
//     }cout<<endl;
// }

// // butterfly patterrn
// for(int i=1;i<=4;i++){
//     for(int j=1;j<=8;j++){
//         if(j<=i || j>8-i){
//             cout<<"*\t";
//         }
//         else{
//             cout<<" \t";
//         }}
//     cout<<endl;
// }cout<<endl;
// for(int i=4;i<=1;i--){
//     for(int j=8;j<=1;j--){
//         if(j>=i || j<8-i){
//             cout<<"*\t";
//         }
//         else{
//             cout<<" \t";
//         }
//     }cout<<endl;
// }

// //  no.pyramid  
//  for(int i=0;i<5;i++){
//     for(int j=1;j<=5-i;j++){
//         cout<<j<<"\t";
//     }cout<<endl;
//  }

// //  0,1 pattern
// for(int i=1;i<=5;i++){
//     for(int j=1;j<=i;j++){
//         if((i+j)%2==0){
//             cout<<1<<"\t";}
//         else{
//             cout<<0<<"\t";
//         }
        
//     }cout<<endl;
// }

// // rhombus pattern
//  for(int i=0;i<5;i++){
//     for(int j=4-i;j>=1;j--){
//         cout<<" ";
//     }
//     for(int k=1;k<=5;k++){
//         cout<<"*";
//     }
//     cout<<endl;
//  }

// // no.pyramid
// for(int i=1;i<=5;i++){
//     for(int j=5-i;j>=1;j--){
//         cout<<" ";
//     }
//     for(int j=1;j<=i;j++){
//         cout<<i;
//         cout<<" ";
//     }cout<<endl;
// }
// int n;
// cin>>n;
// for(int i=1;i<=n;i++){
//     for(int j=1;j<=2*n-(2*i);j++){
//         cout<<" ";
//     }
//     for(int k=i;k>0;k--){
//         cout<<k<<" ";
//     }
//     for(int k=2;k<=i;k++){
//         cout<<k<<" ";
//     }
//     cout<<endl;
// }

// // star pattern
// for(int i=1;i<=5;i++){
//     for(int j=5-i;j>=0;j--){
//         cout<<" ";
//     }
//     for(int k=1;k<=i;k++){
//         cout<<"*";
//     }
//     for(int l=1;l<=i-1;l++){
//         cout<<"*";
//     }
//     cout<<endl;
// }
// for(int i=4;i>=0;i--){
//     for(int j=0;j<=4-i;j++){
//         cout<<" ";
//     }
//     for(int k=i;k>=1;k--){
//         cout<<"*";
//     }
//     for(int l=i;l>=0;l--){
//         cout<<"*";
//     }cout<<endl;
// }
// zigzag pattern
for(int i=1;i<=3;i++){
    for(int j=1;j<=9;j++){
        if((i+j)%4==0 || (i=2 && j%4==0)){
            cout<<"*";
        }
        else{
            cout<<" ";
        }
    }cout<<endl;
}
    return 0;
} 
