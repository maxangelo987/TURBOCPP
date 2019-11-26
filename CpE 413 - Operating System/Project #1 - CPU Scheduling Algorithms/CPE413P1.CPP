#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<string.h>
#include<process.h>
#include<conio.h>
#include"fcfs.h"
#include"npreemp.h"
#include"preemp.h"
#include"prior.h"
#include"roundr.h"

char access,access2[20];
int gd=DETECT, gm,c;


main()
{


clrscr();
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
setbkcolor(WHITE);
setcolor(RED);
settextstyle(TRIPLEX_FONT, HORIZ_DIR,9);
outtextxy(50,75,"CPU");

setcolor(GREEN);
settextstyle(TRIPLEX_FONT, HORIZ_DIR,9);
outtextxy(50,175,"Scheduling");

setcolor(BLUE);
settextstyle(TRIPLEX_FONT, HORIZ_DIR,9);
outtextxy(50,275,"Algorithms");

getch();

initgraph(&gd,&gm,"C:\\turboc3\\bgi");
setbkcolor(BLACK);
setcolor(6);
settextstyle(SANS_SERIF_FONT, HORIZ_DIR,4);

outtextxy(62,40,"    CPU Scheduling Algorithms   ");
settextstyle(TRIPLEX_FONT, HORIZ_DIR,2);
setcolor(RED);
outtextxy(62,100,"[A] First Come, First Served Scheduling");
setcolor(GREEN);
outtextxy(62,120,"[B] Shortest Job First Scheduling");
setcolor(BLUE);
outtextxy(62,140,"[C] Priority Scheduling");
setcolor(YELLOW);
outtextxy(62,160,"[D] Round Robin Scheduling");
setcolor(9);
settextstyle(TRIPLEX_FONT, HORIZ_DIR,1);
outtextxy(62,218,"\t\tEnter option here: ");
gotoxy(32,15);
cin>>access;

     switch(access)
     {
     case 'A':// clrscr();
	       first_come_first_serve ffff;
	       ffff.create_sched_fcfs();
	       closegraph();
	       c=RED;
	       break;

    case 'B': //clrscr();
	       initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	       setbkcolor(BLACK);
	       setcolor(6);
	       settextstyle(SANS_SERIF_FONT, HORIZ_DIR,4);

	       outtextxy(62,40,"    CPU Scheduling Algorithms   ");
	       settextstyle(TRIPLEX_FONT, HORIZ_DIR,2);
	       setcolor(GREEN);
	       outtextxy(62,120,"[B1] Shortest Job First (Non-Preemtive)");
	       outtextxy(62,140,"[B2] Shortest Job First (Preemptive)");
	       setcolor(9);
	       settextstyle(TRIPLEX_FONT, HORIZ_DIR,1);
	       outtextxy(62,218,"\t\tEnter option here: ");
	       gotoxy(32,15);
	       gets(access2);
	       initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	       c=GREEN;

	       if(strcmp("B1",access2)==0)
			{
		//	clrscr();
			non_preemptive nnpp;
			nnpp.create_sched_nonpreemp();
			closegraph();
			break;
			}

	       else if(strcmp("B2",access2)==0)
			{
		  //	clrscr();
			preemptive pprr;
			pprr.create_sched_preemp();
			closegraph();
			break;
			}
	       else
			{
			return 1;
			}
     case 'C':// clrscr();
	       priority pr;
	       pr.create_sched_priority();
	       closegraph();
	       c=BLUE;
	       break;
     case 'D': //clrscr();
	       roundrobin rr;
	       rr.create_sched_roundrobin();
	       closegraph();
	       c=YELLOW;
	       break;
     default:  return 1;
     }

	       clrscr();
	       initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	       setbkcolor(c);
	       settextstyle(TRIPLEX_FONT, HORIZ_DIR,2);
	       setcolor(WHITE);
	       outtextxy(62,100,"           CpE 413 - Operating System               ");
	       outtextxy(62,140,"                  PROJECT NO. 1                     ");
	       outtextxy(62,170,"           CPU Scheduling Algorithms                ");
	       outtextxy(70,320," Perin, Max Angelo                                  ");
	       outtextxy(70,340,"      BSCpE 4                                       ");
	       outtextxy(70,360,"                              Engr. Edgar Uy II     ");
	       outtextxy(70,380,"                                  Instructor        ");

getchar();
//clrscr();
return 0;
}


