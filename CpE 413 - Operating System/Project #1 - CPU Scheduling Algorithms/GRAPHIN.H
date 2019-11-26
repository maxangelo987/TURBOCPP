#ifndef graphin
#define graphin

#include<graphics.h>
#include<stdio.h>
#include<conio.h>

void init_graphics(){

int gdriver = DETECT, gmode, errorcode;

initgraph(&gdriver, &gmode, "C:\\turboc3\\bgi");

errorcode = graphresult();

if (errorcode != grOk)
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();

   exit(1);    /* terminate with an error code */
  }
  settextstyle(SMALL_FONT, HORIZ_DIR, 4);
}
  #endif
