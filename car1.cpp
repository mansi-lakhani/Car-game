#include "car1.h"

car1::car1()
{
     //initwindow(ScreenWidth,ScreenHeight,"CAR GAMES");
}

car1::~car1()
{
    //dtor
}
void car1::floodfill4(int x,int y,int fill,int old)
{
	int current;
	current=getpixel(x,y);
	if(current==old)
	{
		setcolor(fill);
		putpixel(x,y,fill);
		floodfill4(x+1,y,fill,old);
		floodfill4(x-1,y,fill,old);
		floodfill4(x,y+1,fill,old);
		floodfill4(x,y-1,fill,old);
	}
}

void car1::makecar()
{
    //rectangle(x+158,y,x+218,y-100);
	//floodfill4(x+158,y,2,8);
    setfillstyle(SOLID_FILL,BLUE);
    bar(x+158,y,x+218,y-100);
    setfillstyle(SOLID_FILL,BLACK);
    bar(x+158,y-25,x+148,y-10);     //bar1
    bar(x+158,y-90,x+148,y-75);     //bar2
    bar(x+218,y-90,x+228,y-75);     //bar3
    bar(x+228,y-25,x+218,y-10);     //bar4

}
void car1::movecar()
{
    if(GetAsyncKeyState(VK_LEFT))
    {
        if(x>=352)
            x=x-speed;
    }
    else if(GetAsyncKeyState(VK_RIGHT))
    {
        if(x<=635)
            x=x+speed;
    }
    else if(GetAsyncKeyState(VK_UP))
    {
        if(y<=740)
            y=y-speed;
    }
    else if(GetAsyncKeyState(VK_DOWN))
    {
        if(y>=100)
            y=y+speed;
    }
    //rectangle(x+158,y,x+218,y-100);
	//floodfill4(x+158,y,2,8);
     setfillstyle(SOLID_FILL,BLUE);
    bar(x+158,y,x+218,y-100);

    setfillstyle(SOLID_FILL,BLACK);
    bar(x+158,y-25,x+148,y-10);     //bar1
    bar(x+158,y-90,x+148,y-75);     //bar2
    bar(x+218,y-90,x+228,y-75);     //bar3
    bar(x+228,y-25,x+218,y-10);     //bar4


    if(getpixel(x+158,y)==0 || getpixel(x+218,y-100)==0)
    {
       setfillstyle(SOLID_FILL,BLACK);
        bar(0,0,ScreenWidth,ScreenHeight);
        setcolor(WHITE);
        settextstyle(9,HORIZ_DIR,8);
        outtextxy(400,300,"GAME OVER");
        delay(2000);
    }
}

