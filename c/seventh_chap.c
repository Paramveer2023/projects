#include<stdio.h>
#include<string.h>
int slice(char array[],int m,int n);
int vowel_count(char array[]);
int main(){
    // char name[] = {'P','A','R','A','V','E','E','R','\0'};
    // for (int i=0;name[i]!='\0';i++){
    //     printf("%d",name[i]);
    // }
    
    char n[10];
    // scanf("%s",n);
    // printf("%s\n",n);
    // fgets(n,10,stdin);
    // puts(n);
    int dig[] = {1,2,3,4,7,9};
    char str1[] = "paramveer ";
    char str2[] = "singh";
    // printf("%d",strlen(str));
    // strcat(str1,str2);
    // printf("%d",strcmp(str2,str1));
    char ch;
    int i; 
    char str3[50];
    char salt[] = "abcd";
    // while(ch != '\n'){
    //     scanf("%c",&ch);
    //     str3[i]=ch;
    //     i++;
    // }str3[i] = '\0';
    // puts(str3);
    // printf("enter your password : ");
    // fgets(str3,10,stdin);
    // strcat(str3,salt);
    // puts(str3);
    slice(str1,2,6);
    vowel_count(str1);
    return 0;

}

int slice(char array[],int m,int n){
    char str4[100];
    for(int i=m,j=0;i<=n;i++,j++){
        
        str4[j] = array[i];
    }
    return puts(str4);
}
int vowel_count(char array[]){
    int counter =0;
    for(int i=0;i != '\0';i++){
        if(array[i]=="a"||array[i]=="e"||array[i]=="i"||array[i]=="o"||array[i]=="u"){
                counter++;
        }
    }
    return printf("%d",counter);
}