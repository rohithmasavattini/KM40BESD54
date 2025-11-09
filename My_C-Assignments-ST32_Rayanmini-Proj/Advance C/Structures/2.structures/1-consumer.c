#include"layer.h"
void student(STU );
void student_1(STU *);
void print(STU *);
int main()
{
	STU s= {54,"name",88.5};
	student(s);
	printf("ID:%d\nname:%s\nper:%f\n",s.ID,s.name,s.per);
	student_1(&s);	
	printf("ID:%d\nname:%s\nper:%.2f\n",s.ID,s.name,s.per);
	//print(&s);

}
void print(STU *s)
{

	printf("ID:%d\nname:%s\nper:%.2f\n",s->ID,s->name,s->per);
	
}
	
