#ifndef fcfs
#define fcfs

#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include "slist.h"
#include "graphin.h"
#include "gaunt.h"


class first_come_first_serve
{
public:
first_come_first_serve()
	   {
		zero=0;
		ave_wait=0;
		ave_wait2=0;
	    }

~first_come_first_serve(){}

void create_sched_fcfs();
long a,tot_process,my_bursttime,zero,ave_wait,ave_wait2;
char *sched_name;
};

char *schedname_inc(long);
void init_graphics();
long create_gaunt(char, long);

void first_come_first_serve::create_sched_fcfs()
{
   mylist<char*,long> fcfsfcfs;
   long startrect=10;
   init_graphics();
   setbkcolor(RED);
   
   cout<<"Enter how many processes: ";
   cin>>tot_process;
   gotoxy(20,2);
   cout<<"Process";
   gotoxy(40,2);
   cout<<"Burst Time";
   sched_name="A";
   for(a=0; a<tot_process; a++)
	{
	gotoxy(22,a+3);
	cout<<sched_name;
	gotoxy(44,a+3);
	cin>>my_bursttime;

	fcfsfcfs.insert_last(sched_name,zero,my_bursttime,zero);
	sched_name=schedname_inc(a+1);
   	}
	
	fcfsfcfs.access_namelist();
	fcfsfcfs.access_btimelist();
	clrscr();
	init_graphics();
	setbkcolor(RED);
	gotoxy(20,1);
	cout<<"PROCESS";
	gotoxy(40,1);
	cout<<"BURST TIME";

	for(int a=0; a<fcfsfcfs.accs_totnumlist(); a++)
		{
		gotoxy(23,a+2);
		cout<<fcfsfcfs.listname[a];
		gotoxy(44,a+2);
		cout<<fcfsfcfs.listbtime[a];
		if(a!=0)
			{
			 startrect=create_gaunt(fcfsfcfs.listname[a],fcfsfcfs.listbtime[a],startrect,fcfsfcfs.listbtime[a-1]+ave_wait);
			 ave_wait+=fcfsfcfs.listbtime[a-1];
			 ave_wait2+=ave_wait;
			}
		else
			{
			startrect=create_gaunt(fcfsfcfs.listname[a],fcfsfcfs.listbtime[a],startrect,0);
			}
		}

	gotoxy(1,a+3);
	cout<<"Ave waiting time: ";
	gotoxy(21,a+3);
	cout<<(float)ave_wait2/fcfsfcfs.accs_totnumlist()<<" millisecond(s)";
	
	gotoxy((startrect*80/639)+1,23);     // for the last time display in the gannt chart
	cout<<fcfsfcfs.listbtime[a-1]+ave_wait;

	gotoxy((((startrect+10)/2)*80/639)-4,17);
	cout<<"GANNT CHART)";
        gotoxy((((startrect+10)/2)*80/719)-4,18);
	cout<<"(FCFS Scheduling)";

	
	getch();
	return;
}


#endif