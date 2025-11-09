#include<stdio.h>
struct student
{
	char ID[100];
        char name[100];
	int marks;
	char fname[100];
        int d,m,y;
};
void display(struct student);
int main()
{
       struct student stu1={"KM40B","hary",98,"poter",29,4,1999};
 	//scanf("%s%s%d-%d-%d%f\n%c",s.name,s.fname,&s.d,&s.m,&s.y,&s.per,&s.gender);
        display(stu1);
        printf("ID:%s\nname:%s\nmarks:%d\nfname:%s\nDob:%d-%d-%d\n",stu1.ID,stu1.name,stu1.marks,stu1.fname,stu1.d,stu1.m,stu1.y);

return 0;	
}

void display(struct student stu1)
{
	printf("ID:%s\nname:%s\nmarks:%d\nfname:%s\nDob:%d-%d-%d\n",stu1.ID,stu1.name,stu1.marks,stu1.fname,stu1.d,stu1.m,stu1.y);

}




