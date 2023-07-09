#include<stdio.h>
#include<string.h>
struct stud_details
{   char branch_name[30];
    char *name;
    int roll_no;
    float cgpa;
};


// int main(){
//     struct stud_details sd1;
//     sd1.name="paramveer";
//     sd1.roll_no=0731;
//     sd1.cgpa=9.84;
//     strcpy(sd1.branch_name,"mechanical"); /* if array is defined by [] then we cant change its addres normally as array once defined cant be redefined*/
//     struct stud_details sd2;
//     sd2.name="shruti";
//     sd2.roll_no=0751;
//     sd2.cgpa=9.83;
//     strcpy(sd2.branch_name,"mechanical");
//     struct stud_details sd3;
//     sd3.name="paramveer";
//     sd3.roll_no=0731;
//     sd3.cgpa=9.84;
//     strcpy(sd3.branch_name,"mechanical");
//     struct stud_details tut[10];
//     tut[0].name = "rishiraj";
//     tut[0].roll_no = 281;
//     tut[0].cgpa = 6;
//     strcpy(tut[0].branch_name,"mechanical");
//     tut[1].name = "tinu";
//     tut[1].roll_no = 354;
//     tut[1].cgpa = 7;
//     strcpy(tut[1].branch_name,"cs");
//     tut[2].name = "piyush";
//     tut[2].roll_no = 567;
//     tut[2].cgpa = 8;
//     strcpy(tut[2].branch_name,"elecronics");
//     for(int i=0;i<=2;i++){
//         puts(tut[i].name);
//         puts(tut[i].branch_name);
//         printf("%d \n",tut[i].roll_no);
//         printf("%f \n",tut[i].cgpa);
//         printf("*********\n");
//     }
    
//     return 0;
// }
// struct survey
//     {
//       char *name;
//       int age;
//       char *ocuupation;
//       float salary;
//     };
// int main()
// {
//     struct survey p1 = {"paramveer",24,"teacher",6000.0};
//     struct survey p2 = {"prateek",25,"it professional",20000.0};
//     struct survey *ptr = &p1;
//     printf("%s",(*ptr).ocuupation);
//     printf("%s",ptr->name);
//     return 0;
// }
typedef struct DetailsOfMechanicalStudents{
        char *name;
        int enroll_id;
        int curr_sem;
        float curr_sgpa;} dms;

typedef struct complex{
    int real;
    int img;
} c;
int main()
{
    dms s1 = {"Paramveer",834,6,9.5};
    dms *ptr = &s1;
    printf("%s",ptr->name);
    c c1 = {8,9};
    c c2 = {4,12};
    
    c *ptr1 = &c1;
    c *ptr2 = &c2;
    printf("this is real %d",ptr1->real);
    printf("this is imag %d",ptr1->img);
    return 0;
}



