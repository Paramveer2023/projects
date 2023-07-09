#include<stdio.h>

int main()
{
    FILE *fptr;
    fptr = fopen("test.txt","w");
    // char ch;
    // ch = fgetc(fptr);
    // while (ch!=EOF)
    // {
    //    printf("%c",ch);
    //    ch = fgetc(fptr); 
    // }
    // fclose(fptr);
    int n;
    printf("enter limit of odd no : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i+=2){
        fprintf(fptr,"%d \t",i);
    }

    FILE *fptr1;
    fptr1 = fopen("test.txt","r");
    int x;
    fscanf(fptr1,"%d",&x);
    int y;
    fscanf(fptr1,"%d",&y);
    fclose(fptr);

    FILE *fptr2;
    fptr2 = fopen("test.txt","w");
    int z = x+y;
    fprintf(fptr2,"%d",z);
    fclose(fptr);

    return 0;
}
