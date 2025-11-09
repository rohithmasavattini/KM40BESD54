#include<stdio.h>
#include<string.h>
#define n 3
struct date
{
	int d,m,y;
};
struct student
{
        char ID[50];
        char name[50];
        int marks[6];
        char fname[100];
        struct date dob;
	struct date doj;
	struct date dop;
	int total;

};
void sort(struct student stu[]);
int datecmp(struct date,struct date);
int main()
{
       struct student stu[n];
       int i,j;
       for(i=0;i<n;i++)
       {
	       printf("enter data for student %d:\n",i+1);
	       printf("enter ID: ");
	       scanf("%s",stu[i].ID);
	       printf("enter name: ");
	       scanf("%s",stu[i].name);
	       printf("eneter fname: ");
	       scanf("%s",stu[i].fname);
	       printf("enter dob: ");
       	       scanf("%d-%d-%d",&stu[i].dob.d,&stu[i].dob.m,&stu[i].dob.y);
	       printf("enter doj: ");   
               scanf("%d-%d-%d",&stu[i].doj.d,&stu[i].doj.m,&stu[i].doj.y);             	      		//printf("enter dop: ");   
              	//scanf("%d-%d-%d",&stu[i].dop.d,&stu[i].dop.m,&stu[i].dop.y);        
	       printf("eneter marks of 6 subjects of student %d:",i+1);
	       for(j=0;j<6;j++)	
	       {
		       scanf("%d",&stu[j].marks[j]);
	       }       
           }

       		int d;
       		for(i=0;i<n-1;i++)
		{
		for(j=i+1;j<n;j++)		
       		d=datecmp(stu[i].dob,stu[j].dob);
		if(d==1)	
		{
			printf("eldest student is:%s\n",stu[i].name);
		}
		}
		
		for(i=0;i<n;i++)
                {
                for(j=0;j<6;j++)
                stu[i].total += stu[j].marks[j];
		}

		int big=0,c=0;
		big=stu[0].total;

		for(i=1;i<n;i++)
                {
			if(stu[i].total>big)
			{
				big=stu[i].total;
				c++;
			}
       
                }
	       printf("\ntopper of the student is: %s",stu[c].name);
               printf("\nfname: %s",stu[c].fname);
	       printf("\nmarks:\n");
	       for(i=0;i<6;i++)
	       {
		       printf("%d ",stu[c].marks[i]);
	       }
	       printf("\ntotal marks: %d",big);
	       int p=0,f=0,fs=0; 	
	       for(i=0;i<n;i++)
	       {
		       if(stu[i].total/6 >= 30)
			       p++;
		       if(stu[i].total/6 <= 30)
			       f++;
		       if(stu[i].total/6 >= 60)
			       fs++;

	       }
	       printf("\n%d students are passed",p);
	       printf("\n%d students are failed",p);
	 	printf("\n%d students got first class",fs);

		sort(stu);

 
}



int datecmp(struct date stu,struct date stu1)
{
        if(stu.y < stu1.y)
		return 1;
        if(stu.y > stu1.y)
   		return -1;
        if(stu.m < stu1.m)
                return 1;
        if(stu.m > stu1.m)
                return -1;
        if(stu.d < stu1.d)
                return 1;
        if(stu.d > stu1.d)
                return -1;
	return 0;
}

void sort(struct student stu[])
{
	int i,j;
	struct student temp;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		if(strcmp(stu[i].name,stu[j].name)>0)
		{
			temp=stu[i];
			stu[i]=stu[j];
			stu[j]=temp;
		}
	printf("after sorting\n");
	for(i=0;i<n;i++)
	{
		printf("name:%s\n",stu[i].name);
	}

}


