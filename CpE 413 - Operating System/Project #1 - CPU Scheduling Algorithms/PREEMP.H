#ifndef preemp
#define preemp

#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include "slist.h"
#include "graphin.h"
#include "gaunt.h"


class preemptive
{
public:
preemptive()
		{
		zero=0;
		ave_wait=0;
		ave_wait2=0;
		prev_atime=0;
	    	count=1;
		}

~preemptive(){}

void create_sched_preemp();
int mycheck_btime();
long analyze_timequant(int,char *);

long z,b,tot_process,my_bursttime,my_arrivetime,prev_atime,timequant,zero,ave_wait,ave_wait2;
char *sched_name,*name[20];
int done,count;
long arrivet[20],burstt[20];
};

char *schedname_inc1(long);
void init_graphics();
long create_gaunt(char, long, long, long);
void preemptive::create_sched_preemp(){
   mylist<char*,long> preempf;

   long a,startrect=10;
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

	preempf.insert_last(sched_name,my_arrivetime,my_bursttime,zero);
	sched_name=schedname_inc(a+1);
   	}

	preempf.access_namelist();
	preempf.access_btimelist();
	preempf.access_atimelist();

	clrscr();
	init_graphics();
	setbkcolor(GREEN);
	gotoxy(10,1);
	cout<<"PROCESS";
	gotoxy(30,1);
	cout<<"ARRIVE TIME";
	gotoxy(50,1);
	cout<<"BURST TIME";


	for(a=0; a<preempf.accs_totnumlist(); a++)
		{
		gotoxy(13,a+2);
		cout<<preempf.listname[a];
		name[a]=preempf.listname[a];
		gotoxy(34,a+2);
		cout<<preempf.listatime[a];
		arrivet[a]=preempf.listatime[a];
		gotoxy(54,a+2);		            // display
		cout<<preempf.listbtime[a];
		burstt[a]=preempf.listbtime[a];
		}
	
	int mycount=0,phase=0;
	z=0;
	
	while(mycheck_btime()==1 && phase==0)
		{		
		preempf.access_namelist();
		preempf.access_btimelist();
		preempf.access_atimelist();
		timequant=analyze_timequant(phase,name[z-1]);		
	//	timequant=4;
		
		if(burstt[z]>=timequant)
			{		
			if(z!=0)
				{
		    		startrect=create_gaunt(name[z],timequant,startrect,ave_wait);
				ave_wait2+=(ave_wait-arrivet[z]);
				ave_wait+=timequant;				
				}
			else	
				{
				startrect=create_gaunt(name[z],timequant,startrect,ave_wait);
				ave_wait2+=(ave_wait-arrivet[z]);
				ave_wait+=timequant;
				}
		
			preempf.update_node(ave_wait,preempf.listbtime[z]-timequant,z+1);
			burstt[z]=burstt[z]-timequant;
			arrivet[z]=ave_wait;
					
			mycount++;
			}

		else if (burstt[z]>0 && burstt[z]<timequant)
			{
			if(z!=0)
				{
		     		startrect=create_gaunt(name[z],burstt[z],startrect,ave_wait);
				ave_wait2+=(ave_wait-arrivet[z]);
			 	ave_wait+=burstt[z];
				}
			else
				{
				startrect=create_gaunt(name[z],burstt[z],startrect,ave_wait);
				ave_wait2+=(ave_wait-arrivet[z]);
				ave_wait+=burstt[z];		
				}
			
			preempf.update_node(ave_wait,zero,z+1);
			burstt[z]=0;
			arrivet[z]=ave_wait;
			mycount++;
		  	}		
	z++;

		if(ave_wait>=arrivet[tot_process-1])
			{
			phase++;
			}
	
	}
	
	
	preempf.sortlist(3);
	preempf.access_namelist();
	preempf.access_btimelist();
	preempf.access_atimelist();
		

	for(a=0; a<preempf.accs_totnumlist(); a++)
		{
	  	if(preempf.listbtime[a]!=0)
			{
			if(a!=0)
				{
				startrect=create_gaunt(preempf.listname[a],preempf.listbtime[a],startrect,preempf.listbtime[a-1]+ave_wait);
				ave_wait+=preempf.listbtime[a-1];			
				ave_wait2+=(ave_wait-preempf.listatime[a]);			
				mycount++;			
				}
			else
				{
				startrect=create_gaunt(preempf.listname[a],preempf.listbtime[a],startrect,ave_wait);
				ave_wait2+=(ave_wait-preempf.listatime[a]);
				mycount++;
				}
			}
		}

	
	gotoxy(1,tot_process+3);
	cout<<"Ave waiting time: ";
	gotoxy(21,tot_process+3);
	cout<<(float)ave_wait2/mycount<<" millisecond(s)";

	gotoxy((startrect*80/639)+1,23);     // for the last time display in the gannt chart
	cout<<ave_wait+preempf.listbtime[a-1];

	gotoxy((((startrect+10)/2)*80/639)-4,17);
	cout<<"GANNT CHART";
	gotoxy((((startrect+10)/2)*80/719)-4,18);
	cout<<"(SJF (Preemp))";

getch();		
return;
}

int preemptive::mycheck_btime()
{
for(b=0; b<tot_process; b++)
	{
	if(burstt[b]!=0)
	return 1;
	else{}  // just do nothing
	}
	return 0;
}

long preemptive::analyze_timequant(int phase, char *myname)
{
int c,d,tq;
long min=100;

	if(phase==0)
		{
		if(z==0)
			{
			z=0;
			return arrivet[1];
			}
	
		for(b=0; b<tot_process; b++)
			{
			if(burstt[b]<min && burstt[b]!=0 && arrivet[b]<=ave_wait)
				{
				min=burstt[b];
			   	z=b;
			   	}
			}
		
		if(name[z]==myname)
			{
			count++;	
			return arrivet[z+count]-arrivet[z];
			}
		else
			{
			count=1;
			return arrivet[z+1]-arrivet[z];
			}
		}	
}

#endif