#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
int mark(int,int,int,int);
int num_fix=0,g=1;
int lev[501],ro[501];
void main()
{
	int d=DETECT,m;
	initgraph(&d,&m,"c:\\tc\\bgi");
	for(int q=0;q<500;q++)
	{lev[q]=0;ro[q]=0;}
	int x,y;
	x=getmaxx()/2;
	y=getmaxy()/2;
	int draw=1,del=0;
	union REGS ii,oo;
	int perm=1;
	rectangle(x-161,y-221,x+161,y+221);
	rectangle(x-163,y-223,x+163,y+223);
	int room1,room2,room3,room4,level1,level2,level3,level4;
	int andom,style,tabby=0;
	int time,clr;
	randomize();
	for(time=500;time>=100;time-=10)
	{
		if(time==100)
		time=110;
		andom=random(7);
		switch(andom)
		{
			case 0:
			style=1;room1=8;room2=9;room3=8;room4=9;level1=1;level2=1;level3=2;level4=2;clr=1;break;
			case 1:
			style=2;room1=8;room2=8;room3=8;room4=8;level1=1;level2=2;level3=3;level4=4;clr=2;break;
			case 2:
			style=3;room1=8;room2=9;room3=8;room4=9;level1=1;level2=2;level3=2;level4=3;clr=3;break;
			case 3:
			style=4;room1=8;room2=9;room3=8;room4=9;level1=2;level2=1;level3=3;level4=2;clr=4;break;
			case 4:
			style=5;room1=8;room2=9;room3=10;room4=9;level1=1;level2=1;level3=1;level4=2;clr=7;break;
			case 5:
			style=6;room1=8;room2=8;room3=8;room4=9;level1=1;level2=2;level3=3;level4=1;clr=6;break;
			case 6:
			style=7;room1=8;room2=8;room3=8;room4=7;level1=1;level2=2;level3=3;level4=1;clr=5;break;
		}
		int ret=0;
		int pet=0;
		tabby=0;
		for(int loop=0;loop<25;loop++)
		{
		loop--;
		ret=mark(level1,room1,draw,clr);
		if(ret==1)
		pet=1;
		ret=mark(level2,room2,draw,clr);
		if(ret==1)
		pet=1;
		ret=mark(level3,room3,draw,clr);
		if(ret==1)
		pet=1;
		ret=mark(level4,room4,draw,clr);
		if(ret==1)
		pet=1;
		if(pet==1)
		{loop=25;goto skip;}

		delay(time);

		if(level1<22&&level2<22&&level3<22&&level4<22)
		{
			ret=mark(level1,room1,del,clr);
			if(ret==1)
			pet=1;
			ret=mark(level2,room2,del,clr);
			if(ret==1)
			pet=1;
			ret=mark(level3,room3,del,clr);
			if(ret==1)
			pet=1;
			ret=mark(level4,room4,del,clr);
			if(ret==1)
			pet=1;
			if(pet==1)
			{loop=25;goto skip;}

			level1++;
			level2++;
			level3++;
			level4++;
		}
		else
		{
		loop=25;
		goto skip;
		}
			if(kbhit())
			{
				//interrupt issue to scan the ascii ans scan codes of the key hit
				ii.h.ah=0;
				int86(22,&ii,&oo);
				//if esc key has been pressed
				if(oo.h.ah==1)
				{
				closegraph();exit(0);
				}
				//if right key has been pressed
				if(oo.h.ah==77)
				{
				for(int num=500;num>=0;num--)
					{
						if(level1==lev[num]-1&&room1+1==ro[num]||level2==lev[num]-1&&room2+1==ro[num]||level3==lev[num]-1&&room3+1==ro[num]||level4==lev[num]-1&&room4+1==ro[num]||level1==lev[num]&&room1+1==ro[num]||level2==lev[num]&&room2+1==ro[num]||level3==lev[num]&&room3+1==ro[num]||level4==lev[num]&&room4+1==ro[num])
						perm=0;

					}

				if(room1<16&&room2<16&&room3<16&&room4<16&&perm==1)
				{room1++;room2++;room3++;room4++;}
				perm=1;
				}
				//if left key has been pressed
				if(oo.h.ah==75)
				{
					for(int num=500;num>=0;num--)
					{
						if(level1==lev[num]-1&&room1-1==ro[num]||level2==lev[num]-1&&room2-1==ro[num]||level3==lev[num]-1&&room3-1==ro[num]||level4==lev[num]-1&&room4-1==ro[num]||level1==lev[num]&&room1-1==ro[num]||level2==lev[num]&&room2-1==ro[num]||level3==lev[num]&&room3-1==ro[num]||level4==lev[num]&&room4-1==ro[num])
						perm=0;
					}

				if(room1>1&&room2>1&&room3>1&&room4>1&&perm==1)
				{room1--;room2--;room3--;room4--;}
				perm=1;
				}
				//if upper key has been pressed
				if(oo.h.ah==72)
				{
				if(room1<16&&room2<16&&room3<16&&room4<16&&room1>1&&room2>1&&room3>1&&room4>1)
				 {
				 if(tabby==0)
				 switch(style)
					{
					case 1:break;
					case 2:room1--;room3++;room4+=2;level1++;level3--;level4-=2;break;
					case 3:room1+=2;level1++;level3++;break;
					case 4:room2-=2;level2++;level4++;break;
					case 5:room1++;level1--;break;
					case 6:room2++;room3--;level3-=2;break;
					case 7:room2--;room3++;level3-=2;break;
					}
				else if(tabby==1)
				switch(style)
					{
					case 1:break;
					case 2:room1++;room3--;room4-=2;level1--;level3++;level4+=2;break;
					case 3:room1-=2;level1--;level3--;break;
					case 4:room2+=2;level2--;level4--;break;
					case 5:room4--;level4--;break;
					case 6:	room1++;room3++;level1++;level3++;level2--;level4--;break;
					case 7:	room3-=2;level1++;level3--;break;
					}
				else if(tabby==2)
				switch(style)
					{
					case 1:break;
					case 2:room1--;room3++;room4+=2;level1++;level3--;level4-=2;break;
					case 3:room1+=2;level1++;level3++;break;
					case 4:room2-=2;level2++;level4++;break;
					case 5:room3--;level3++;break;
					case 6:room2--;room4++;level4+=2;break;
					case 7:room4++;room3--;level3+=2;break;
					}
				else if(tabby==3)
				switch(style)
					{
					case 1:break;
					case 2:room1++;room3--;room4-=2;level1--;level3++;level4+=2;break;
					case 3:room1-=2;level1--;level3--;break;
					case 4:room2+=2;level2--;level4--;break;
					case 5:room1--;room3++;room4++;level1++;level3--;level4++;break;
					case 6:room1--;room4--;level1--;level2++;level3++;level4--;break;
					case 7:room2++;room3+=2;room4--;level1--;level3++;break;
					}
					tabby++;
					if(tabby==4)
					tabby=0;
				 }
				}
				//if lower key has been pressed
				if(oo.h.ah==80)
				{
				getch();
				}
			}//kbhit
		skip:
		if(loop==25)
			{
				mark(level1,room1,12,clr);
				mark(level2,room2,12,clr);
				mark(level3,room3,12,clr);
				mark(level4,room4,12,clr);

				mark(level1,room1,3,clr);
				mark(level2,room2,3,clr);
				mark(level3,room3,3,clr);
				mark(level4,room4,3,clr);
			}
		}
	}
}
int mark(int level,int room,int col,int b_clr)
{
	int x,y,num,toll[22],gon;
	x=getmaxx()/2;
	y=getmaxy()/2;
	g=1;
	for(int r=0;r<22;r++)
	toll[r]=0;

	if(col==12)
	{col=1;
	goto sk;}

	for(num=500;num>=0;num--)
	if(level==lev[num]-1&&room==ro[num])
	{
	if(level<=1)
	{cleardevice();setcolor(14);outtextxy(x-50,y,"lost in height");sleep(3);closegraph();exit(0);}
	col=3;
	}
	sk:
	if(col==1)
	{
		setfillstyle(SOLID_FILL,b_clr);
		bar(x-160+1+20*(room-1),y-220+1+20*(level-1),x-140-1+20*(room-1),y-200-1+20*(level-1));
	}
	else if(col==0)
	{
		setfillstyle(SOLID_FILL,0);
		bar(x-160+1+20*(room-1),y-220+1+20*(level-1),x-140-1+20*(room-1),y-200-1+20*(level-1));
	}
	else
	{
	lev[num_fix]=level;
	ro[num_fix]=room;
	gotoxy(3,3);
	cout<<lev[num_fix]<<" "<<ro[num_fix]<<" .\n";
	num_fix++;
	sound(300);
	delay(30);
	nosound();

	g=5;
	}
	//check
	for(num=500;num>=0;num--)
	{
		switch(lev[num])
		{
		 case 1:toll[0]++;break;   case 2:toll[1]++;break;   case 3:toll[2]++;break;   case 4:toll[3]++;break;
		 case 5:toll[4]++;break;   case 6:toll[5]++;break;   case 7:toll[6]++;break;   case 8:toll[7]++;break;
		 case 9:toll[8]++;break;   case 10:toll[9]++;break;  case 11:toll[10]++;break;  case 12:toll[11]++;break;
		 case 13:toll[12]++;break;  case 14:toll[13]++;break;  case 15:toll[14]++;break;  case 16:toll[15]++;break;
		 case 17:toll[16]++;break;  case 18:toll[17]++;break;  case 19:toll[18]++;break;  case 20:toll[19]++;break;
		 case 21:toll[20]++;break;  case 22:toll[21]++;break;
		}
	}
	gotoxy(1,1);
	for(gon=0;gon<22;gon++)
	{

		cout<<toll[gon]<<endl;
		if(toll[gon]==16)
		{
		 gotoxy(5,5);
		 cout<<gon+1;

		 for(num=500;num>=0;num--)
		 {
		  if(lev[num]==gon+1)
		  {
		   lev[num]=0;ro[num]=0;
		  }
		 }
		 for(num=500;num>=0;num--)
		 {

		  if(lev[num]<=gon&&lev[num]!=0)
		  {
		   lev[num]++;
		  }
		 }
		 cleardevice();
		 setcolor(WHITE);
		 rectangle(x-161,y-221,x+161,y+221);
		 rectangle(x-163,y-223,x+163,y+223);
		 setfillstyle(SOLID_FILL,RED);
		 for(num=500;num>=0;num--)
		 {
		 bar(x-160+1+20*(ro[num]-1),y-220+1+20*(lev[num]-1),x-140-1+20*(ro[num]-1),y-200-1+20*(lev[num]-1));
		 }
		}
	}
	for(r=0;r<22;r++)
	toll[r]=0;
	//
	if(g==5)
	return 1;

	return 0;
}
