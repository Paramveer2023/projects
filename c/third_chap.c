#include<stdio.h>

// int main(){
//     int age;
//     printf("enter value of age : ");
//     scanf("%d", &age);
//     if (age>10 && age<18)
//     {
//         printf("not adult and has no rights");
//     }
//     else if (age>18 && age <30)
//     {
//         printf("adult and can vote \n");
//         printf("adult and can drive \n");
//         printf("adult and can use gun");
//     }
//     else {
//         printf("out of our survey");
//     }


//     return 0;
// }

// TERNARY OPERATOR

// int main() {
//     int age;
//     printf("enter value of age : ");
//     scanf("%d",&age);
//     age>=18 ? printf("adult....can vote as well drive and use guns ") : printf("non adult");
//     return 0;
// }

// SWITCH 
// int main() {
//     int day;
//     printf("enter the day_number : ");
//     scanf("%d",&day);
//     switch (day)
//     {
//     case 1:
//         printf("it's Monday");
//         break;
//     case 2:
//         printf("it's tuesay");
//         break;
//     case 3:
//         printf("it's thursday");
//         break;
//     case 4:
//         printf("it's wednesday");
//         break;
//     case 5:
//         printf("it's friday");
//         break;
//     case 6:
//         printf("it's saturday");
//         break;
//     case 7:
//         printf("it's Sunday");
//         break;
//     default:
//         printf("out of week range");
//     }
// }

// NESTED IF ELSE
// int main(){
    // int m;
    // printf("enter number : ");
    // scanf("%d",&m);
    // if (m>0){
    //     if (m%2 == 0)
    //     {
    //         printf("its even");
    //     }
    //     else{
    //         printf("its odd");
    //     }
    // }
    // else {
    //     printf("its whole no");
    // } 
//     return 0;
// }
       
    

int main() {
    char x;
    printf("Enter value of x ");
    scanf("%c", &x);
    if (x>='a' && x<='z')
    {
       printf("its a lower case");
    }
    else if (x>='A' && x<='Z')
    {
        printf("its upper case");
    }
    else
    {
    printf("Characters not allowed");
    }
    return 0;
}