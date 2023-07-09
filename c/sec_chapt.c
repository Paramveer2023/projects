#include<stdio.h>
#include<math.h>

int main() {
    float a=25.5,b=5;
    printf("%d \n",a/b);
    float c = 1.9678;
    printf("%f",c);

    return 0;
}


relational operators

int main() {
    printf("%d \n", 4 > 5);
    printf("%d \n",17>8 && 5>13);
    printf("%d \n",17!=45 || 18>53);
    printf("%d \n", !((89<56) && (78<56)));
    return 0;
}
int main() {
    int a;
    printf("enter value");
    // scanf(" %d",&a);
    // printf("%d",a%2==0);
    scanf("%d \n", &a);
    printf("%d \n",a>9 && a<100);
    return 0;
}