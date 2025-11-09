int a2i(char*);
void i2a(int num);
int strlength(char []);
void strreverse(char []);
void istrcpy(char str3[],char str4[]);
int stringcmp (char str5[],char str6[]);
void stringcat(char str7[],char str8[]);
int stringchr(char buff[],char c);

int strstr_2(char s1[],char s2[]);
int cmp1(char s1[],char s2[],int i);


void replacechar(char str9[],char c1,char c2);


int main()
{
		int i1,i2,l,c,sum;
    char string[5]="1234";
		int num=1234;
	
	  char str[10]="kernel";
	
		char str1[10]="Master";
	
	  char str3[20]="Master";
    char str4[20]="Kernel";
	
    char str5[10]="kernel";
		char str6[10]="kernel";
		
			
    char str7[20]="kernel";
    char str8[20]="master";
	
		char buff[10]="kernel",c3='e';
	
		char s1[100]="kernel master",s2[100]="mast";
        
		char str9[20]="kernel",c1='e',c2='l';

     sum=a2i(string);
		 
		 i2a(num);
		   
      l=strlength(str);
			
        strreverse(str1);
					
        istrcpy(str3,str4);
			
			
        c=(stringcmp(str5,str6));
				
				stringcat(str7,str8);
				
				i1=stringchr(buff,c3);
				
        
        i2=strstr_2(s1,s2);
				
				
        replacechar(str9,c1,c2);
				
        return 0;

}




int a2i(char* a)
{   
    int sum,digit,i;
    sum=0;
    for(i=0; i < a[i]!=0; i++)
    {
        digit=a[i]-0x30;
        sum=(sum*10)+digit;
    }
    return sum;
	}

	
	
void i2a(int num)
{
int i,j;
char a[10],temp;
for(i=0;num>0;i++)
{
	a[i]= num%10 + 0x30;
	num=num/10;
}
a[i]='\0';
i=i-1;
for(j=0;j<i;i--,j++)
{
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;;
}
		
	}
	
	
int strlength(char str[])
{
        int i=0;
        while(str[i]!='\0')
        {
        i++;
        }
        return i;
			}
		

void strreverse(char str1[])
{
        int i,j,r;
				char temp;
				//j=strlen(str1)-1;
        for(j=0;str1[j]!=0;j++);
        j=j-1;
        for(i=0;i<j;i++,j--)
        {
                temp=str1[i];
                str1[i]=str1[j];
                str1[j]=temp;
        }
}
			

void istrcpy(char str3[],char str4[])
{
        int i;
        for(i=0;str4[i]!='\0';i++)
        {
                str3[i]=str4[i];
        }
        str3[i]='\0';

}


int stringcmp(char str5[],char str6[])
{
        int i=0;
        while(str5[i]!='\0' || str6[i]!='\0')
        {
                if(str5[i]!=str6[i])
                        return (str5[i]-str6[i]);
                i++;
        }
        return 0;
}


void stringcat(char str7[],char str8[])
{
        int i,j;
        for(i=0; str7[i]!='\0';i++);
        for(j=0; str8[j]!='\0';i++,j++)
        {
                str7[i]=str8[j];
        }
        str7[i]='\0';
    
}



int stringchr(char buff[],char c3)
{
	int i;
	for(i=0;buff[i]!=0;i++)
	{
		if(buff[i]==c3)
			return i;
	}
			return 0;
}


		
		
		
int strstr_2(char s1[],char s2[])
{
        int i;
        for(i=0;s1[i]!='\0';i++)
        {
                if(s1[i]==s2[0])
                        if (cmp1(s1,s2,i)==1)
                                return i;
        }
        return -1;
}

int cmp1(char s1[],char s2[],int i)
{
        
        int k;
				i++;
        for(k=1;s2[k]!='\0';k++,i++)
        {
					       if(s1[i]!=s2[k])
                        return 0;
        }
        return 1;
}



void replacechar(char str9[],char c1,char c2)
{
        int i;
        for(i=0;str9[i]!='\0';i++)
        {
                if(str9[i]==c1)
                {
                        str9[i]=c2;
                }
        }
			}
