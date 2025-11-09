#include<stdio.h>
struct student
{
        char name[100];
        int d,m,y;
};
void display(struct student,struct student);
int main()
{
	struct student stu1,stu2;
	printf("enter 1st student name and dob:\n");
	scanf("%s%d-%d-%d",stu1.name,&stu1.d,&stu1.m,&stu1.y);
        printf("enter 2nd student name and dob:\n");
        scanf("%s%d-%d-%d",stu2.name,&stu2.d,&stu2.m,&stu2.y);
	display(stu1,stu2);

	
}

void display(struct student stu1,struct student stu2)
{
	if(stu1.y > stu2.y)
		printf("%s is elder\n",stu2.name);
	else if(stu1.m > stu2.m)
		printf("%s is elder\n",stu2.name);
	else if(stu1.d > stu2.d)
		printf("%s is elder\n",stu2.name);
	else
	       printf("both are same age\n");	
}


	

