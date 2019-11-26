#ifndef gaunt
#define gaunt

#include "graphin.h"
#include <graphics.h>
#include <iostream.h>

void init_graphics();
long create_gaunt(char *name, long time, long startg, long waittime){
//init_graphics();
long startx,starty,endx,endy;
int a;
startx=startg;
starty=300;
endy=350;
endx=startx;
for(a=0; a<time; a++){
       endx+=10;
}
rectangle(startx,starty,endx,endy);

outtextxy((endx+startx-4)/2,(endy+starty-8)/2,name);

gotoxy((startx*80/639)+1,23);
cout<<waittime;


return endx;

}

char *schedname_inc(long z){
   switch(z){
   case 1: return("B");
   case 2: return("C");
   case 3: return("D");
   case 4: return("E");
   case 5: return("F");
   case 6: return("G");
   case 7: return("H");
   case 8: return("I");
   case 9: return("J");
   case 10: return("K");
   case 11: return("L");
   case 12: return("M");
   case 13: return("N");
   case 14: return("O");
   case 15: return("P");
   case 16: return("Q");
   case 17: return("R");
   case 18: return("S");
   case 19: return("T");
   case 20: return("U");
   case 21: return("V");
   case 22: return("W");
   case 23: return("X");
   case 24: return("Y");
   case 25: return("Z");
   default: return("0");
   }
}

#endif