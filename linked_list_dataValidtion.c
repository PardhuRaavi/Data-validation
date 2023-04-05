#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct pn{
    char fname[10];
    char lname[10];
    char dob[10];//date of birth ddmmyyyy
    
}psn; // person structure

typedef struct sa{
    char doj[12];//date of joining ddmmyyyy
    int initial; //initial salary
    int increment; //salary increment % 
    int current; // current salary
}sal; //salary details structure

typedef struct e0{
    psn *p;
    sal *s;
    struct e0 *next;
}emp; // employee data structure


int get_psn(psn *new_psn); // asks user to fill person details 
int get_sal(sal *new_sal, psn *new_psn ); // asks user to fill person details 
int create(emp **new_emp); // creates new emplyee memory
int print(emp **new_emp); //prints the employee details
int validate_string(char * string);
int validate_date(char *date,char *month,char *year);
int validate_per(int per);
int validate_sal(char *sal);
int main() 
{
	emp *emp1=NULL,**new_emp; 
	new_emp = &emp1;
	create(new_emp);
	print(new_emp);
	return 0;
}

int get_psn(psn *new_psn) // asks user to fill person details 
{
    printf("\nPlease enter Employee details\n");
    printf("\nFirst name : ");
    while(1)
    {
    scanf("%s",new_psn->fname);
    if(validate_string(new_psn->fname)>0)
    break;
    else
    printf("Enter the name correctly : ");
    }
    printf("\nLast name : ");
    while(1)
    {
    scanf("%s",new_psn->lname);
    if(validate_string(new_psn->lname)>0)
    break;
    else
    printf("Enter the name correctly : ");
    }
    
    printf("\nDate of birth as dd mm yyyy : ");
    while(1)
    {
    scanf("%s",new_psn->dob);
    scanf("%s",(char *)(new_psn->dob)+3);
    scanf("%s",(char *)(new_psn->dob)+6);
    if(validate_date(new_psn->dob, (char *)(new_psn->dob)+3, (char *)(new_psn->dob)+6)>0)
    break;
    else
    printf("Enter the date correctly : ");
    }
return 0;   
}


int validate_string(char *string)
{
for(int i=0;i<strlen(string);i++)
{
if((string[i]>=65&&string[i]<=90)||(string[i]>=97&&string[i]<=122));
else
return -1;
}
return 1;
}

int validate_date(char *date,char *month,char *year)
{
int i;
if(strlen(date)==2 && ((date[0]>='0' && date[0]<='3') && (date[1]>='0' && date[1]<='9')))
{
if(date[0]=='3')
{
if(date[1]<='1');
else
return -1;
}
if(date[0]=='0')
{
if(date[1]>'0');
else
return -1;
}
if(strlen(month)==2 && ((month[0]>='0' && month[0]<='1') && (month[1]>='0' && month[1]<='9')))
{
if(month[0]=='1')
{
if(month[1]<='2');
else
return -1;
}
if(month[0]=='0')
{
if(month[1]>'0');
else
return -1;
}

if(year[0]>='1' && year[0]<='2')
{
for(i=1;i<strlen(year);i++)
{
if(year[i]>='0' && year[i]<='9');
else
break;
}
if(i==4)
return 1;
else
return -1;
}

}
}
return -1;
}
int validate_per(int per)
{
if(per>=0 && per<=100)
return 1;
else
return -1;
}

int validate_sal(char *sal)
{
int amt;
printf("%s\n",sal);
for(int i=0;i<strlen(sal);i++)
{
if(sal[i]>='0' && sal[i]<='9');
else
return -1;
}
sscanf(sal,"%d",&amt);
return amt;
}

int get_sal(sal *new_sal, psn *new_psn ) // asks user to fill person details 
{
    char sal[15];
    printf("\nPlease enter Salary details for %s %s\n", new_psn->fname, new_psn->lname);
    printf("\nInitial Salary : ");
    while(1)
    {
    scanf("%s",sal);
    if((new_sal->initial=validate_sal(sal))>=0)
    break;
    else
    printf("enter the correct salary : ");
    }
    printf("\nIncrement Salary %% : ");
    while(1)
    {
    scanf("%d",&(new_sal->increment));
    if(validate_per(new_sal->increment)>0)
    break;
    else 
    printf("Enter the percentage correctly : ");
    }
    
    printf("\nDate of Joining as dd mm yyyy : ");
    while(1)
    {
    scanf("%s",new_sal->doj);
    scanf("%s",(char *)(new_sal->doj)+3);
    scanf("%s",(char *)(new_sal->doj)+6);
    if(validate_date(new_sal->doj, (char *)(new_sal->doj)+3, (char *)(new_sal->doj)+6)>0)
    break;
    else
    printf("Enter the date correctlty : ");
    }
    return 0;
}

int create(emp **new_emp){
    *new_emp = (emp *)malloc(sizeof(emp));
    (*new_emp)->s = (sal *)malloc(sizeof(sal));
    (*new_emp)->p = (psn *)malloc(sizeof(psn)); 
    
  get_psn((*new_emp)->p); // get person details to from user
  get_sal((*new_emp)->s,(*new_emp)->p); // get person details to from user
  printf("\nEmployee Created  ::\n");
  return 0;
}


int print(emp **new_emp){
    
    printf("\nEmployee details of Mr. %s %s are ::\n",(*new_emp)->p->fname,(*new_emp)->p->lname);
    
    printf("\nDate of birth : %s %s %s",(*new_emp)->p->dob
                                        ,(char *)((*new_emp)->p->dob)+3
                                        ,(char *)((*new_emp)->p->dob)+6);
                                        
    printf("\nDate of Joining : %s %s %s",(*new_emp)->s->doj
                                        ,(char *)((*new_emp)->s->doj)+3
                                        ,(char *)((*new_emp)->s->doj)+6);

    printf("\nInitial salary  : %d",(*new_emp)->s->initial);
    printf("\nSalary increment : %d%%\n",(*new_emp)->s->increment);
  
    
    return 0;
}
