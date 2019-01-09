#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
struct student
{
 char name[20];
 int rollno;
 float marks;
}st;
void main()
{
    FILE *fp1,*fp2;
    char next='y';
    int roll_no;
    int resize,ch;
    clrscr();
    fp1 = fopen("STUDENT.DAT","rb+");
    if(fp1 == NULL)
    {
	fp1 = fopen("STUDENT.DAT","wb+");
	if(fp1 == NULL)
	{
	    printf("Connot open file");
	    exit(1);
	}
    }
    resize = sizeof(st);
    while(1)
    {
    printf("\n1:add record\n2:display record\n3:search\n4.modify\n5.delete\n6.exit\n");
    printf("enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:
	    fseek(fp1,0,SEEK_END);
	    next = 'y';
	    while(next == 'y')
	    {
	       printf("Enter rollno\n");
	       scanf("%d", &st.rollno);
	       printf("Enter name\n");
	       scanf("%s",st.name);
	       printf("Enter marks\n ");
	       scanf("%f", &st.marks);
	       fwrite(&st,resize,1,fp1);
	       printf("Add another record(y/n):");
	       fflush(stdin);
	       next=getche();
	    }
	    break;
       case 2:
	     rewind(fp1);
	     printf("Rollno\tMaks\tMarks\n");
	     printf("*************************\n");
	     while(fread(&st,resize,1,fp1)==1)
	    {
		printf("\n%d\t%s\t%f",st.rollno,st.name,st.marks);
	    }
	    break;
      case 3:next = 'y';
	    while(next == 'y')
	    {
		printf("Enter the rollno to be search: ");
		scanf("%d",&roll_no);
		rewind(fp1);
		while(fread(&st,resize,1,fp1)==1)
		{
		    if(roll_no==st.rollno)
		    {
			printf("student details\n");
			printf("Rollno\tName\tmarks\n");
			printf("%d\t%s\t%f\n",st.rollno,st.name,st.marks);
		       fseek(fp1,-resize,SEEK_CUR);
		       fwrite(&st,resize,1,fp1);
			break;
		    }
		}
		printf("Search the record(y/n)\n");
		fflush(stdin);
		next=getche();
	    }
	    break;
      case 4:next = 'y';
	    while(next == 'y')
	    {
		printf("Enter the rollno to be  modify\n");
		scanf("%d",&roll_no);
		rewind(fp1);
		while(fread(&st,resize,1,fp1)==1)
		{
		    if(st.rollno,roll_no)
		    {
			printf("\nEnter roll no,name,marks\n");
			scanf("%d%s%f",st.rollno,&st.name,&st.marks);
			fseek(fp1,-resize,SEEK_CUR);
			fwrite(&st,resize,1,fp1);
			break;
		    }
		}
		printf("\nModify the record(y/n)");
		fflush(stdin);
		next=getche();
	    }
	    break;
	case 5:
	    next = 'y';
	    while(next == 'y')
	    {
		printf("\nEnter rollno  to delete: ");
		scanf("%d",&roll_no);
		fp2 = fopen("TEMP.DAT","w");
		rewind(fp1);
		while(fread(&st,resize,1,fp1) == 1)
		{
		    if(roll_no==st.rollno)
		    {
			fwrite(&st,resize,1,fp2);
		    }
		}
		fclose(fp1);
		fclose(fp2);
		remove("STUDENT.DAT");
		rename("TEMP.DAT","STUDENT.DAT");
		fp1= fopen("STUDENT.DAT", "r");
		printf("Delete another record(y/n)");
		fflush(stdin);
		next = getche();
	    }
	    break;
       case 6:
		fclose(fp1);
		exit(0);

       default:printf("invalid choice\n");
		break;

	}
}
       //	getch();
   // return 0;
}
