#include"layer.h"

void student(STU stu)
{
	printf("enter ID,name,percentage:\n");
	scanf("%d\n%s\n%f",&stu.ID,stu.name,&stu.per); 
}

void student_1(STU *stu)
{
	printf("enter ID,name,percentage:\n");
	scanf("%d%s%f",&stu->ID,stu->name,&(*stu).per);
}



		
