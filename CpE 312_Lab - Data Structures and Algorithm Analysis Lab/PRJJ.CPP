#include<stdio.h>
#include<conio.h>

void enroll();
void inform();
void enrsub();
void enrsuba();
void enrsubb();
void enrsubc();
void enrsubd();
void enrsube();
void enrffs();
void enrfss();
void enrsfs();
void enrsss();
void enrtfs();
void enrtss();
void enrfofs();
void enrfoss();
void enrfos();
void enrfifs();
void enrfiss();
void tomain();
void second_page();

main()
{
 int m;
 clrscr();
 printf("Press 1. Enroll");
 printf("\nPress 2. View enrolled subjects");
 printf("\nPress 3. View statements");
 printf("\nPress 4. Delete enrolled subjects");
 printf("\nPress 5 Exit\n");
 scanf("\n%d", &m);
 if (m==1)
	{
	printf("Enroll");
	inform();
	}
 else if(m==2)
	{
	printf("View enrolled subjects");
	second_page();
	}
 else if(m==3)
	printf("View statement");
 else if(m==4)
	printf("Delete subjects enrolled");
 else if(m==5)
	printf("Exit");
 else
	printf("Error");
 getch();
 return(0);
}

void inform()
{
char a, b, c;
int d, e;
clrscr();
printf("First Name: ");
scanf("%s", &a);
printf("Last Name: ");
scanf("%s", &b);
printf("Course: ");
scanf("%s", &c);
printf("Year: ");
scanf("%d", &d);
printf("Id No.: ");
scanf("%d", &e);

int x;
	printf("\n\nPress 0 to continue ");
	printf("\nPress 1 to home\n ");
	scanf("%d",&x);
    if (x==0)
	{
	enrsub();
	}
 else if(x==1)
	{
	main();
	}
}

void enrsub()
{
 int y;
 clrscr();
 printf("Press 1. Enroll First Year");
 printf("\nPress 2. Enroll Second Year");
 printf("\nPress 3. Enroll Third Year");
 printf("\nPress 4. Enroll Fourth Year");
 printf("\nPress 5. Enroll Fifth Year\n");
 scanf("%d", &y);
 if (y==1)
	{
	printf("Enroll First Year");
	enrsuba();
	}
 else if (y==2)
	{
	printf("Enroll Second Year");
	enrsubb();
	}
 else if (y==3)
	{
	printf("Enroll Third Year");
	enrsubc();
	}
 else if (y==4)
	{
	printf("Enroll Fourth Year");
	enrsubd();
	}
 else if (y==5)
	{
	printf("Enroll Fifth Year");
	enrsube();
	}
 else
	printf("Error");
}

void enrsuba()
{
int z;
clrscr();
printf("\n1. 1st Year - First Semester Subjects");
printf("\n2. 1st Year - Second Semester Subjects\n");
scanf("%d", &z);
 if (z==1)
	{
	printf("1st Year - First Semester");
	enrffs();
	second_page();
	}
 else if (z==2)
	{
	printf("2nd Year - First Semester");
	enrfss();
	}
 else
	printf("Error");
}

void enrsubb()
{
int f;
clrscr();
printf("\n1. 2nd Year - First Semester Subjects");
printf("\n2. 2nd Year - Second Semester Subjects\n");
scanf("%d", &f);
 if (f==1)
	{
	printf("2nd Year - First Semester");
	enrsfs();
	}
 else if (f==2)
	{
	printf("2nd Year - Second Semester");
	enrsss();
	}
 else
	printf("Error");
}


void enrsubc()
{
int g;
clrscr();
printf("\n1. 3rd Year - First Semester Subjects");
printf("\n2. 3rd Year - Second Semester Subjects\n");
scanf("%d", &g);
 if (g==1)
	{
	printf("3rd Year - First Semester");
	enrtfs();
	}
 else if (g==2)
	{
	printf("3rd Year - Second Semester");
	enrtss();
	}
 else
	printf("Error");
}


void enrsubd()
{
int h;
clrscr();
printf("\n1. 4th Year - First Semester Subjects");
printf("\n2. 4th Year - Second Semester Subjects\n");
scanf("%d", &h);
 if (h==1)
	{
	printf("4th Year - First Semester");
	enrfofs();
	}
 else if (h==2)
	{
	printf("4th Year - Second Semester");
	enrfoss();
	}
 else if (h==3)
	{
	printf("4th Year - Summer");
	enrfos();
	}
 else
	printf("Error");
}


void enrsube()
{
int i;
clrscr();
printf("\n1. 5th Year - First Semester Subjects");
printf("\n2. 5th Year - Second Semester Subjects\n");
scanf("%d", &i);
 if (i==1)
	{
	printf("5th Year - First Semester");
	enrfifs();
	}
 else if (i==2)
	{
	printf("5th Year - Second Semester");
	enrfiss();
	}
 else
	printf("Error");
}


void enrffs()
{
int  i, subj;
clrscr();
printf("1. EM111       College Algebra E		      TTH 2:30 - 4:30	F307\n");
printf("\n2. EM112     Solid Menstruation      		      TTH 9:00 - 10:30  A306\n");
printf("\n3. EPS111Lec General Chemistry Lec		      MWF 1:30 - 2:30   F307\n");
printf("\n4. EPS111Lab General Chemistry Lab		      MWF 2:30 - 3:30   Lab B\n");
printf("5. \nES111     Engineering Drawing	              TTH 10:30 - 12:00 Drafting\n");
printf("6. \nEngl1     Study and Thinking Skills in English   MWF 7:30 - 8:30   F103\n");
printf("7. \nFil1      Komunikasyon sa Akademikong Filipino   MWF 5:30 - 6:30   F203\n");
printf("8. \nSocio1    Society & Culture w/ Family Planning   MWF 8:30 - 9:3    F310\n");
printf("9. \nPhys Ed   Physical Fitness			      MW  10:30 - 11:30  F306\n");
printf("10. \nNSTP1    National Service Training Program 1    TH  4:00 - 5:30    F304\n");
printf("11. \nGuid1    Ub Orientation			      TTh 1:30 - 2:30   F304\n");
for(i=0; i>=-1; i--)
	scanf("%d", &subj);

printf("\n\nPress 0 to View Enrolled Subject");
printf("\nPress 1 to return Home");
scanf("%d", &subj);
if(subj==0)
	second_page();
else if (subj==-1)
	main();
}

void enrfss()
{
int i, subj;
clrscr();
printf("1. EM123	Advanced Algebra 	                    TTH 4:00 - 5:30\n");
printf("2. \nEM124	Plane & Spherical Trigonometry              M-TH 3:00 - 4:00\n");
printf("3. \nES122Lec 	Comp. Funda. & Prog Lec                     TTH 10:00 - 11:00\n");
printf("4. \nES122Lab 	Comp. Funda. & Prog Lab                     MWF 8:30 - 9:30\n");
printf("5. \nES120	Engineering Accounting                      TTh 1:00 - 2:00\n");
printf("6. \nEngl2    	Writing in the Discipline                   MWF 9:30 - 10:30\n");
printf("7. \nFil2	Pagbasa at Pagsulat Patungo sa Pananaliksik MWF 1:30 - 2:30\n");
printf("8. Pyshc1       General Psychology                          MWF 10:30 - 11:30\n");
printf("9. P.E.2	Rhythmic Activities                         TTh 9:00 - 10:00\n");
printf("10. NSTP2	National Service Training Program 2	    MWF 4:30 - 5:30\n");
printf("11. Guid2 	Self Awareness 	                            TTH 8:00 - 9:00\n");
for(subj=0; subj<=10; subj++)
	scanf("%d", &subj);

printf("\n\nPress 0 to View Enrolled Subject");
printf("\nPress 1 to return Home");
scanf("%d", &subj);
 if(subj==0)
	{
	second_page();
	}
 else if(subj==1)
	{
	main();
	}
}

void enrsfs()
{
int i, subj;
clrscr();
printf("1. EM125       Analytic Geometry E			    TTH 2:30 - 4:00   A304\n");
printf("2. \nEPS212Lec College Physics 1E Lec 			    MWF 7:30 - 8:30   Phys A\n");
printf("3. \nEPS212Lab College Physics 1E Lab			    MWF 8:30 - 9:30   Phys A\n");
printf("4. \nES213     Cyberbetics/Internet  			    MW  3:00 - 4:30   Comp C\n");
printf("5. \nPhilo1    Introduction to Logic 			    MWF 9:30 - 10:30  F309\n");
printf("6. \nLit 2     World Literature  			    TTH 4:00 - 5:30   F310\n");
printf("7. \nPol Sci 1 Politics & Governance w/ Phil Constitution   MWF 1:30 - 2:30        \n");
printf("8. \nHistory 1 Philippine History   			    MWF 10:30 - 11:30 F309\n");
printf("9. \nP.E.3     Fundamentals of Games & Sports  		    TTH 8:00 - 9:00   ST215\n");
printf("10. \nGuid 3   Relationship Enhancement  		    TTH 10:30 - 11:30 F304\n");
for(i=0; i<=9; i++)
	scanf("%d", &subj);

printf("\n\nPress 0 to View Enrolled Subject");
printf("\nPress 1 to return Home");
scanf("%d", &subj);
 if(subj==0)
	{
	second_page();
	}
 else if(subj==1)
	{
	main();
	}
}

void enrsss()
{
int i, subj;
clrscr();
printf("1. EM226       Differential Calculus E  			 MW  1:30 - 3:00 \n");
printf("2. \nEPS223Lec College Physics 2E Lec				 MWF 8:30 - 9:30\n");
printf("3. \nEPS223Lab College Physics 2E Lab				 MWF 9:30 - 10:30\n");
printf("4. \nES224     Computer-Aided Drafting				 TTh 8:00 - 9:30\n");
printf("5. \nEcon 1    Principles of Economics w/ Taxation & Land Reform TTH 10:30 - 12:00\n");
printf("6. \nEngl 3    Speech Communication 				 TTh 1:00 - 2:30\n");
printf("7. \nRizal     Life & Works of Rizal 				 MWF 3:30 - 4:30\n");
printf("8. \nBis211    Alamsulat Bisaya 				 WF  4:30 - 6:00\n");
printf("9. \nP.E.4     Recreational Activities 				 TTh 3:00 - 4:00\n");
printf("10. \nGuid4    Career Preparation and Development  		 TTH 4:00 - 5:00\n");
for(i=0; i<=10; i++)
	scanf("%d", &subj);

printf("\n\nPress 0 to View Enrolles Subject");
printf("\nPress 1 to return Home");
scanf("%d", &subj);

 if(subj==0)
	{
	printf("Enrolled Subjects");
	clrscr();
	second_page();
	}
 else if(subj==10)
	printf("Error");
}

void enrtfs()
{
int i, subj;
clrscr();
printf("1. EM317	Integral Calculus E 		      		MW  1:30 - 3:30   A308	\n");
printf("2. EE 311Lec    Electrical Circuits(DC Circuits) Lec  		TTh 2:30 - 4:00   A307\n");
printf("3. EE 311Lab    Electrical Circuits(DC Circuits) Lab  		TTH 4:00 - 5:30   Elec Lab\n");
printf("4. EE 312       Electromagnentics                     		WF  10:30 - 12:00 A306\n");
printf("5. ECE 311Lec	Electronics 1(Electronic Devices & Circuits)Lec MWF 8:30 - 9:30   A304 \n");
printf("6. ECE 311Lab	Electronics 1(Electronic Devices & Circuits)Lab MWF 9:30 - 10:30  Elec Lab\n");
printf("7. Cpe 311 	Computer Hardware Fundamentals	  		TTh 10:30 - 12:00 EE Lab \n");
printf("8. Cpe 312Lec	Data Structures & Algorithm Analysis Lec  	TTh 5:30 - 7:00   A306\n");
printf("9. Cpe 312Lab	Data Structures & Algorithm Analysis Lab  	M   4:30 - 7:30   Comp C\n");
printf("10. Engl 4E	Technical Comminication	 		        MWF 7:30 - 8:30   F309	\n");
for(i=0; i<=9; i++)
	scanf("%d", &subj);

printf("\n\nPress 0 to View Enrolles Subject");
printf("\nPress 1 to return Home");
scanf("%d", &subj);

 if(subj==0)
	{
	printf("Enrolled Subjects");
	clrscr();
	second_page();
	}
 else if(subj==9)
	printf("Error");
}

void enrtss()
{
int i, subj;
printf("[1] EM 328 Differential Equation 	MWF 8:30 - 9:30\n");
printf("[2] EM 329 Engineering Probability & Statistics	       MWF 10:30 - 11:30\n");
printf("[3] ES 326 Statics of Rigid Bodies	TTh 1:30 - 3:00\n");
printf("[4] ES 315 Environmental Engineering     TTH 3:00 - 4:30\n");
printf("[5] EE 322Lec Electrical Circuits 2(AC Circuits) Lec	MWF 1:30 - 2:30\n");
printf("[6] EE 322Lab Electrical Circuits 2(AC Circuits) Lab     MWF 2:30 - 3:30\n");
printf("[7] ECE 322Lec Electronics 2(Electronic Circuits Analysis & Design)Lec	TTH 7:30 - 9:00\n");
printf("[8] ECE 322Lab Electronics 2(Electronic Circuits Analysis & Design)Lab  TTH 9:00 - 10:30\n");
printf("[9] Computer 3 Computer Programming Design & Implementation	MWF 5:30 - 6:30\n");
for(i=0; i<=8; i++)
	scanf("%d", &subj);

printf("\n\nPress 0 to View Enrolles Subject");
printf("\nPress 1 to return Home");
scanf("%d", &subj);

 if(subj==0)
	{
	printf("Enrolled Subjects");
	clrscr();
	second_page();
	}
 else if(subj==8)
	printf("Error");
}

void enrfofs()
{
int i, subj;
printf("[1] ES 327  Safety Management F 10:30 - 11:30 A304\n");
printf("[2] ES 420  Engineering Economics MWF 9:30 - 10:30 A304\n");
printf("[3] ECE 412A Principles of Communication TTh 10:30 - 12:00 A304\n");
printf("[4] CpE 411Lec Computer System Organization w/ Assembly Language Lec TTh 9:00 - 10:30 A304\n");
printf("[5] CpE 411Lab Computer System Organization w/ Assembly Language Lab Wed 10:30 - 1:30 Comp C\n");
printf("[6] CpE 412Lec Control Systems Lec MWF 1:30 - 2:30 A306 \n");
printf("[7] CpE 412Lab Control Systems Lab TTh 2:30 - 4:00 Elec Lab\n");
printf("[8] CpE 413Lec Logic Circuits & Switching Theory Lec TTh 4:00 - 5:30 A306 \n");
printf("[9] CpE 413Lab Logic Circuits & Switching Theory Lab MWF 3:30 - 4:30 Elec Lab\n");
printf("[10] CpE 414 Advanced Engineering Mathematics w/ Numerical Methods MWf 2:30 - 4:30 A309\n");
for(i=0; i<=9; i++)
	scanf("%d", &subj);

printf("\n\nPress 0 to View Enrolles Subject");
printf("\nPress 1 to return Home");
scanf("%d", &subj);

 if(subj==0)
	{
	printf("Enrolled Subjects");
	clrscr();
	second_page();
	}
 else if(subj==9)
	printf("Error");
}

void enrfoss()
{
int i, subj;
clrscr();
printf("[1] ES 418 Dynamics of Rigid Bodies MWF 8:30 - 9:30\n");
printf("[2] ES 419 Mechanics of Deformable Bodies M-F  7:30 - 8:30");
printf("[3] ME 420 Safety Engineering TTh 2:00 - 4:00\n");
printf("[4] CpE 421Lec Advanced Logic Circuits Lec TTh 4:00 - 5:30\n");
printf("[5] CpE 421Lab Advanced Logic Circuits Lab TTh 5:30 - 7:00\n");
printf("[6] CpE 422Lec Microprocessors System Lec MWF 2:30 - 4:30\n");
printf("[7] CpE 422Lab Microprocessors System Lab MWF 3:30 - 4:30\n");
printf("[8] CpE 423Lec Operating Systems Lec TTh 8:00 - 9:30\n");
printf("[9] CpE 423Lab Operating Systems Lab TTh 9:30 - 11:00\n");
printf("[10] CpE 424 Data Communications MWF 10:30 - 11:30\n");
for(i=0; i<=9; i++)
	scanf("%d", &subj);

printf("\n\nPress 0 to View Enrolles Subject");
printf("\nPress 1 to return Home");
scanf("%d", &subj);

 if(subj==0)
	{
	printf("Enrolled Subjects");
	clrscr();
	second_page();
	}
 else if(subj==9)
	printf("Error");
}

void enrfos()
{
int i, subj;
clrscr();
printf("[1] CpE 510 Society and Cultural Immersion (OJT)320 hrs \n");
for(i=0; i<=1; subj++)
	scanf("%d", &subj);

printf("\n\nPress 0 to View Enrolles Subject");
printf("\nPress 1 to return Home");
scanf("%d", &subj);

 if(subj==0)
	{
	printf("Enrolled Subjects");
	clrscr();
	second_page();
	}
 else if(subj==1)
	printf("Error");
}

void enrfifs()
{
int i, subj;
clrscr();
printf("[1] CpE 511Lec Digital Signal Processing Lec MW 9:30 - 10:30\n");
printf("[2] CpE 511Lab Digital Signal Processing Lab MW 10:30 - 11:30\n");
printf("[3] CpE 512    Computer System Architecture   WF 2:30 - 3:30 \n");
printf("[4] CpE 513    Project Management TTh 8:00 - 9:00\n");
printf("[5] CpE 514    Design Project 1(Methods of Research) TTh 9:00 - 10:00\n");
printf("[6] CpE 515Lec    Computer Networks Lec MWF 3:30 - 4:30\n");
printf("[7] CpE 515Lab    Computer Networks Lab MWF 4:30 - 5:30\n");
printf("[8] CpE 516Lec    Input/Output & Memory Systems Lec TTh 1:30 - 3:00\n");
printf("[9] CpE 516Lab    Input/Output & Memory Systems Lab  TTh 3:00 - 4:30\n");
printf("[10] ES 320        Engineering Management WF 8:30 - 9:30\n");
for(i=0; i<=9; i++)
	scanf("%d", &subj);

printf("\n\nPress 0 to View Enrolles Subject");
printf("\nPress 1 to return Home");
scanf("%d", &subj);

 if(subj==0)
	{
	printf("Enrolled Subjects");
	clrscr();
	second_page();
	}
 else if(subj==10)
	printf("Error");
}

void enrfiss()
{
int i, subj;
clrscr();
printf("[1] CpE 521 Software Engineering MWF 8:30 - 9:30\n");
printf("[2] CpE 522 CpE Elective 1(Emerging Technology)  MWF 1:30 - 2:30\n");
printf("[3] CpE 523 CpE Elective 2 (embedded Systems) TTh 2:00 - 3:30\n");
printf("[4] CpE 524 Engineering Ethics and Computer Laws TTh 9:00 - 10:30\n");
printf("[5] CpE 525 Design Project 2(Project Implementation) MF 2:30 - 5:30 \n");
printf("[6] CpE 526 Test and Quality Assurance TTh 8:00 - 9:00\n");
printf("[7] CpE 527 Technoprenuership TTh 4:00 - 5:00\n");
printf("[8] CpE 528 Seminars & Field Trips MWF 10:30 - 11:30\n");
for(i=0; i<=9; i++)
	scanf("%d", &subj);

printf("\n\nPress 0 to View Enrolles Subject");
printf("\nPress 1 to return Home");
scanf("%d", &subj);

 if(subj==0)
	{
	printf("Enrolled Subjects");
	clrscr();
	second_page();
	}
 else if(subj==9)
	printf("Error");
}
void tomain()
{
int q;
printf("Press 1 to go back to main");
printf("Opppsss, Error");
scanf("%d", &q);
if (q==1)
	second_page();
else if(q==2)
	main();
}

void second_page()
{
int l;
clrscr();
printf("View Enroll Subjects: ");
scanf("%d", &l);
if (l==11)
	{
	printf("Enrolled Subjects");
	enrffs();
	}
else if (l==12)
	{
	printf("Enroll Subjects");
	enrfss();
	tomain();
	}
else if (l==21)
	{
	printf("Enroll Subjects");
	enrsfs();
	tomain();
	}
else if (l==22)
	{
	printf("Enroll Subjects");
	enrsss();
	tomain();
	}
else if (l==31)
	{
	printf("Enroll Subjects");
	enrtfs();
	tomain();
	}
else if (l==32)
	{
	printf("Enroll Subjects");
	enrtss();
	tomain();
	}
else if (l==41)
	{
	printf("Enroll Subjects");
	enrfofs();
	tomain();
	}
else if (l==42)
	{
	printf("Enroll Subjects");
	enrfoss();
	tomain();
	}
else if (l==43)
	{
	printf("Enroll Subjects");
	enrfos();
	tomain();
	}
else if (l==51)
	{
	printf("Enroll Subjects");
	enrfifs();
	tomain();
	}
else if (l==52)
	{
	printf("Enroll Subjects");
	enrfiss();
	tomain();
	}
else if (l==00)
	{
	printf("Exit");
	main();
	tomain();
	}
return;
}

