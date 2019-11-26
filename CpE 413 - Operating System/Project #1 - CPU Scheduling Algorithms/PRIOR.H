#ifndef prior
#define prior

#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include "slist.h"
#include "graphin.h"
#include "gaunt.h"

class priority
{
public:
priority(){
		zero=0;
		ave_wait=0;
		ave_wait2=0;
	   }

~priority(){}

void create_sched_priority();

long a,tot_process,my_bursttime,mypriority,zero,ave_wait,ave_wait2;
char *sched_name;
};
char *schedname_inc1(long);
void init_graphics();
long create_gaunt(char, long);

void priority::create_sched_priority()
   {
   mylist<char*,long> priorityf;
   long startrect=10;
   clrscr();
   init_graphics();
   setbkcolor(BLUE);
   cout<<"Enter how many processes: ";
   cin>>tot_process;
   gotoxy(10,2);
   cout<<"Process";
   gotoxy(30,2);
   cout<<"Burst Time";
   gotoxy(50,2);
   cout<<"Priority";

   sched_name="A";

   for(a=0; a<tot_process; a++)
	{
	gotoxy(12,a+3);
	cout<<sched_name;
	gotoxy(34,a+3);
	cin>>my_bursttime;
	gotoxy(54,a+3);
	cin>>mypriority;

	priorityf.insert_last(sched_name,zero,my_bursttime,mypriority);
	sched_name=schedname_inc(a+1);
   	}

	priorityf.access_namelist();
	priorityf.access_btimelist();
	priorityf.access_prioritylist();

	clrscr();
	init_graphics();
	setbkcolor(BLUE);
	gotoxy(10,1);
	cout<<"PROCESS";
	gotoxy(30,1);
	cout<<"BURST TIME";
	gotoxy(50,1);
	cout<<"PRIORITY";

	int a;
	for(a=0; a<priorityf.accs_totnumlist(); a++)
		{
		gotoxy(13,a+2);
		cout<<priorityf.listname[a];
		gotoxy(34,a+2);
		cout<<priorityf.listbtime[a];
		gotoxy(54,a+2);
		cout<<priorityf.listpriority[a];
		}

	priorityf.sortlist(1);
	priorityf.access_namelist();
	priorityf.access_btimelist();
	priorityf.access_prioritylist();


	for(a=0; a<priorityf.accs_totnumlist(); a++)
		{
		if(a!=0)
			{
			 startrect=create_gaunt(priorityf.listname[a],priorityf.listbtime[a],startrect,priorityf.listbtime[a-1]+ave_wait);
			 ave_wait+=priorityf.listbtime[a-1];
			 ave_wait2+=ave_wait;
			}
		
		else
			{
			startrect=create_gaunt(priorityf.listname[a],priorityf.listbtime[a],startrect,0);
			}
		}


	gotoxy(1,a+3);
	cout<<"Ave waiting time: ";
	gotoxy(21,a+3);
	cout<<(float)ave_wait2/priorityf.accs_totnumlist()<<" millisecond(s)";
	
	gotoxy((startrect*80/639)+1,23);     // for the last time display in the gannt chart
	cout<<priorityf.listbtime[a-1]+ave_wait;

	gotoxy((((startrect+10)/2)*80/639)-4,17);
	cout<<"GANNT CHART";
	gotoxy((((startrect+10)/2)*80/789)-4,18);
	cout<<"(PRIORITY SCHEDULING)";


		
        
	getch();
	closegraph();
}


#endif