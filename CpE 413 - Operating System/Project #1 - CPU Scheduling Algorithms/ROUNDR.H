#ifndef roundr
#define roundr

#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include "slist.h"
#include "graphin.h"
#include "gaunt.h"


class roundrobin
{
public:
roundrobin()
	        {
		zero=0;
		ave_wait=0;
		ave_wait2=0;
		prev_atime=0;
	    	}

~roundrobin(){}

void create_sched_roundrobin();

long a,b,tot_process,my_bursttime,my_arrivetime,prev_atime,timequant,zero,ave_wait,ave_wait2;
char *sched_name;
int done;
};

char *schedname_inc1(long);
void init_graphics();
long create_gaunt(char, long, long, long);
void roundrobin::create_sched_roundrobin()
{
   mylist<char*,long> roundrobinf;

   long startrect=10;
   init_graphics();
   setbkcolor(YELLOW);

   cout<<"Enter RR Time Quantum: ";
   cin>>timequant;

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

	roundrobinf.insert_last(sched_name,my_arrivetime,my_bursttime,zero);
	sched_name=schedname_inc(a+1);
  	}

	roundrobinf.access_namelist();
	roundrobinf.access_btimelist();
	roundrobinf.access_atimelist();

	clrscr();
	init_graphics();
	setbkcolor(YELLOW);
	gotoxy(10,1);
	cout<<"PROCESS";
	gotoxy(30,1);
	cout<<"ARRIVE TIME";
	gotoxy(50,1);
	cout<<"BURST TIME";

	int a;
	for(a=0; a<roundrobinf.accs_totnumlist(); a++)
		{
		gotoxy(13,a+2);
		cout<<roundrobinf.listname[a];
		gotoxy(34,a+2);
		cout<<roundrobinf.listatime[a];
		gotoxy(54,a+2);		  // display
		cout<<roundrobinf.listbtime[a];
		}
	
	int mycount=0;
	a=0;
	while(roundrobinf.check_btime()==1)
		{
		roundrobinf.access_namelist();
		roundrobinf.access_btimelist();
		roundrobinf.access_atimelist();

	if(roundrobinf.listatime[a]>ave_wait )
		{
		a=-1;
		ave_wait++;
		}
	else
		{
		if(roundrobinf.listbtime[a]>=timequant)
			{		
			if(a!=0)
				{
		     		startrect=create_gaunt(roundrobinf.listname[a],timequant,startrect,ave_wait);
			 	ave_wait2+=(ave_wait-roundrobinf.listatime[a]);
				ave_wait+=timequant;				
				}
			else
				{
				startrect=create_gaunt(roundrobinf.listname[a],timequant,startrect,ave_wait);
				ave_wait2+=(ave_wait-roundrobinf.listatime[a]);
				ave_wait+=timequant;		
				}
	
		roundrobinf.update_node(ave_wait,roundrobinf.listbtime[a]-timequant,a+1);					
		mycount++;
		}

		else if (roundrobinf.listbtime[a]>0 && roundrobinf.listbtime[a]<timequant)
			{
			if(a!=0)
				{
		     		startrect=create_gaunt(roundrobinf.listname[a],roundrobinf.listbtime[a],startrect,ave_wait);
			 	ave_wait2+=(ave_wait-roundrobinf.listatime[a]);
			 	ave_wait+=roundrobinf.listbtime[a];	
				}
			else
				{
				startrect=create_gaunt(roundrobinf.listname[a],roundrobinf.listbtime[a],startrect,ave_wait);
				ave_wait2+=(ave_wait-roundrobinf.listatime[a]);
				ave_wait+=roundrobinf.listbtime[a];		
				}
			
		roundrobinf.update_node(ave_wait,zero,a+1);
		mycount++;
		  	}
		}
		
	a++;
		
		if(a==roundrobinf.accs_totnumlist())
			{
			a=0;
			}	
		}

 	gotoxy(1,roundrobinf.accs_totnumlist()+3);
	cout<<"Ave waiting time: ";
	gotoxy(21,roundrobinf.accs_totnumlist()+3);
	cout<<(float)ave_wait2/mycount<<" millisecond(s)";

	gotoxy((startrect*80/639)+1,23);     // for the last time display in the gannt chart
	cout<<ave_wait;

	gotoxy((((startrect+10)/2)*80/639)-4,17);
	cout<<"GANNT CHART";

	gotoxy((((startrect+10)/2)*80/819)-4,18);
	cout<<"(ROUND ROBIN SCHEDULING)";

		
getch();
return;
}



#endif