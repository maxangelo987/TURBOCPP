#ifndef npreemp
#define npreemp

#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include "slist.h"
#include "graphin.h"
#include "gaunt.h"


class non_preemptive
{
public:
non_preemptive()
		{
		zero=0;
		ave_wait=0;
		ave_wait2=0;
		prev_atime=0;
	    	}

~non_preemptive(){}

void create_sched_nonpreemp();

long a,tot_process,my_bursttime,my_arrivetime,prev_atime,zero,ave_wait,ave_wait2;
char *sched_name;
int done;
};

char *schedname_inc1(long);
void init_graphics();
long create_gaunt(char, long);

void non_preemptive::create_sched_nonpreemp()
{
mylist<char*,long> npreempf;
long startrect=10,phase;
setbkcolor(GREEN);

   cout<<"Enter how many processes: ";
   cin>>tot_process;

   gotoxy(10,3);
   cout<<"Process";
   gotoxy(30,3);
   cout<<"Arrive Time";
   gotoxy(50,3);
   cout<<"Burst Time";

   sched_name="A";

   for(a=0; a<tot_process; a++)
	{
	gotoxy(12,a+4);
	cout<<sched_name;

	do
	{
	gotoxy(34,a+4);
	cin>>my_arrivetime;              // used in atime input when lesser than prev
	}
	while(my_arrivetime<prev_atime);

	prev_atime=my_arrivetime;

	gotoxy(54,a+4);
	cin>>my_bursttime;

	npreempf.insert_last(sched_name,my_arrivetime,my_bursttime,zero);
	sched_name=schedname_inc(a+1);
   	}

	npreempf.access_namelist();
	npreempf.access_btimelist();
	npreempf.access_atimelist();

	clrscr();
	init_graphics();
	setbkcolor(GREEN);

	gotoxy(10,1);
	cout<<"PROCESS";
	gotoxy(30,1);
	cout<<"ARRIVE TIME";
	gotoxy(50,1);
	cout<<"BURST TIME";

	int a;
	for(a=0; a<npreempf.accs_totnumlist(); a++)
		{
		gotoxy(13,a+2);
		cout<<npreempf.listname[a];
		gotoxy(34,a+2);
		cout<<npreempf.listatime[a];
		gotoxy(54,a+2);		  // display
		cout<<npreempf.listbtime[a];
		}

	npreempf.sortlist(2);

	npreempf.access_namelist();
	npreempf.access_btimelist();
	npreempf.access_atimelist();


	for(a=0; a<npreempf.accs_totnumlist(); a++)
		{
		if(a!=0)
			 {
			 startrect=create_gaunt(npreempf.listname[a],npreempf.listbtime[a],startrect,npreempf.listbtime[a-1]+ave_wait);
			 ave_wait+=npreempf.listbtime[a-1];
			 ave_wait2+=(ave_wait-npreempf.listatime[a]);
			 }
		else	
			 {
			 startrect=create_gaunt(npreempf.listname[a],npreempf.listbtime[a],startrect,0);
			 }
		}
	gotoxy(1,a+3);
	cout<<"Ave waiting time: ";
	gotoxy(21,a+3);
	cout<<(float)ave_wait2/npreempf.accs_totnumlist()<<" millisecond(s)";

	gotoxy((startrect*80/639)+1,23);     // for the last time display in the gannt chart
	cout<<npreempf.listbtime[a-1]+ave_wait;

	gotoxy((((startrect+10)/2)*80/639)-4,17);
	cout<<"GANNT CHART";
	gotoxy((((startrect+10)/2)*80/749)-4,18);
	cout<<"(SJF (N-Preemp))";


	
getch();
return;
}


#endif