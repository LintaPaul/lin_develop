#include <stdio.h>
#include<string.h>
#include<stdlib.h>
struct bills
{
  int bill_no;
  char bill_name[200];
  struct date
  {
    int day;
    int month;
    int year;
  } dd_mm_yy;


};
typedef struct bills BILLS;
BILLS b[1000];
void
bill_add (int n)
{ 
  
  int i = 0;
  for (i = 0; i < n; i++)
    {
      printf ("Enter bill no \n");
      scanf ("%d", &b[i].bill_no);
      
      printf ("Enter bill_name \n");
      scanf ("%s", b[i].bill_name);
     
      printf ("Enter due-date in dd_mm_yy format \n");
      printf ("Day : ");
      scanf ("%d", &b[i].dd_mm_yy.day);
      
      printf ("Month : ");
      
      scanf ("%d", &b[i].dd_mm_yy.month);
      
      printf ("Year : ");
      scanf ("%d", &b[i].dd_mm_yy.year);
      
    }

}

void
due_check (int n)
{
  char bname[1000];
  int i = 0, tday = 0, tmonth = 0, tyear = 0, dmonth = 0, tleft = 0;
  printf ("enter the name of bill to check due date \n");
  scanf ("%s", bname);
  printf ("Enter today's date (day,month and year) \n");
  scanf ("%d%d%d", &tday, &tmonth, &tyear);
  for (i = 0; i < 100; i++)
    {

      if ((strcmp (bname, b[i].bill_name)) == 0)
	{
	  if ((b[i].dd_mm_yy.year < tyear) || (b[i].dd_mm_yy.month < tmonth)
	      || (b[i].dd_mm_yy.day < tday))
	    {
	      printf ("Time Expired!!! \n Due Date was:\n");
	      printf ("%d:%d:%d \n", b[i].dd_mm_yy.day, b[i].dd_mm_yy.month,
		      b[i].dd_mm_yy.year);
	    }
	  else
	    {
	      if (tyear < b[i].dd_mm_yy.year)
	    	{
		  printf ("Don't worry.Enough time for payment \n");
		  printf ("Due Date is:%d:%d:%d \n", b[i].dd_mm_yy.day,
			  b[i].dd_mm_yy.month, b[i].dd_mm_yy.year);
		    }
	      else if (tmonth < b[i].dd_mm_yy.month)
	    	{
		  dmonth = b[i].dd_mm_yy.month - tmonth;
		  tleft = (dmonth * 30) + b[i].dd_mm_yy.day - tday;
		  printf ("Due Date :%d:%d:%d \n", b[i].dd_mm_yy.day,
			  b[i].dd_mm_yy.month, b[i].dd_mm_yy.year);
		  printf ("Time left for payment is %d days: \n", tleft);
		    }
	        
	    }
	 return;  
	}
  }/*closing of for*/
  
  printf ("no such bill \n");
}

int
main ()
{
  int ch = 0, n = 0;
  printf("....Make your choice....\n 1.Check due date of bills \n 2.Add new bills\n 3.Exit \n");
  scanf ("%d", &ch);
  do
    {

      switch (ch)
	{
	case 1:
	  due_check (100);
	  break;
	case 2:
	  printf ("How many bills to add? \n");
	  scanf ("%d", &n);
	  bill_add (n);
	  break;

	default:
	  printf ("Thank You for coming \n");
	}
      printf
	("....Make your choice....\n 1.Check due date of bills \n 2.Add new bills \n 3.Exit \n");
      scanf ("%d", &ch);


    }
  while (ch != 3);


  return 0;
}
