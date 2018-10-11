#include "Road.h"

Road::Road()
{
    initwindow(ScreenWidth,ScreenHeight,"CAR GAMES");
}

Road::~Road()
{
    //dtor
}

void Road::makeroad()
{
        //lawns
    setfillstyle(SOLID_FILL,GREEN);
    bar(133,767,483,0);    //left lawn
    bar(883,767,1233,0);   //right lawn

    //white borders
    setfillstyle(SOLID_FILL,WHITE);
    bar(484,767,495,0);     //left border
    bar(871,767,882,0);     //right border

    //road
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(496,767,870,0);
}

void Road:: bars()
{
     if(_f==0)
        {
            setfillstyle(SOLID_FILL,WHITE);
            bar(673,767,693,667);
            bar(673,545,693,445);
            bar(673,322,693,222);
            bar(673,100,693,0);
            _f=1;
        }
        else
        {
            setfillstyle(SOLID_FILL,WHITE);
            bar(673,767+20,693,667+20);
            bar(673,545+20,693,445+20);
            bar(673,322+20,693,222+20);
            bar(673,100+20,693,0+20);
            _f=0;
        }
}

void Road::randomfuel()
{
    while(_i<=650 && flag==1)
    {
        setfillstyle(SOLID_FILL,RED);
        bar(500+rx,0+ry+_q,540+rx,60+ry+_q);
        _q=_i+10;
        break;
    }
    while(_q<=650 && flag==0)
        {
        setfillstyle(SOLID_FILL,DARKGRAY);
        bar(500+rx,0+ry+_q,540+rx,60+ry+_q);
        _q+=10;
        break;
        }
    if(_q>650)
    {
        rx=(rand()%330);
        _i=0;
        flag=1;
    }
}


void Road::obstacles()
{
    while(_i<=650)
    {
    if(r==0)
    {
        setfillstyle(SOLID_FILL,BLACK);
        bar(500+ox,0+oy+_i,540+ox,80+oy+_i);
        _i+=10;
        break;
    }
    else if(r==1)
    {
        setfillstyle(SOLID_FILL,BLACK);
        bar(500+ox,0+oy+_i,540+ox,80+oy+_i);
        bar(600+ox,20+oy+_i,640+ox,100+oy+_i);
        _i+=5;
        break;
    }
    else
    {
        setfillstyle(SOLID_FILL,BLACK);
        bar(500+ox,0+oy+_i,540+ox,80+oy+_i);
        bar(600+ox,20+oy+_i,640+ox,100+oy+_i);
        bar(700+ox,0+oy+_i,740+ox,80+oy+_i);
        _i+=5;
        break;
    }
    }
    if(_i>600)
    {
        ox=(rand()%80);
        r=(rand()%3);
        _i=0;
    }
}

void Road ::play()
{
      int page=0;
      makecar();
    while(_p)
    {
    setactivepage(page);
    setvisualpage(1-page);
    cleardevice();
    makeroad();
    bars();
    randomfuel();
    obstacles();
    movecar();
    delay(50);
     page=1-page;
    }
}




void Road::makecar()
{
    setfillstyle(SOLID_FILL,BLUE);
    bar(x+158,y,x+218,y-100);
    setfillstyle(SOLID_FILL,BLACK);
    bar(x+158,y-25,x+148,y-10);     //bar1
    bar(x+158,y-90,x+148,y-75);     //bar2
    bar(x+218,y-90,x+228,y-75);     //bar3
    bar(x+228,y-25,x+218,y-10);     //bar4

}
void Road::movecar()
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
     setfillstyle(SOLID_FILL,BLUE);
    bar(x+158,y,x+218,y-100);

    setfillstyle(SOLID_FILL,BLACK);
    bar(x+158,y-25,x+148,y-10);     //bar1
    bar(x+158,y-90,x+148,y-75);     //bar2
    bar(x+218,y-90,x+228,y-75);     //bar3
    bar(x+228,y-25,x+218,y-10);     //bar4

    if(getpixel(x+158,y)==4 || getpixel(x+218,y-100)==4)
    {
        flag=0;
        sf+=5;
    }


    if(getpixel(x+158,y)==0 || getpixel(x+218,y-100)==0)
    {
       setfillstyle(SOLID_FILL,BLACK);
        bar(0,0,ScreenWidth,ScreenHeight);
        setcolor(WHITE);
        settextstyle(9,HORIZ_DIR,8);
        outtextxy(400,300,"GAME OVER");
        delay(2000);
    }
    char b[10];
    sprintf(b,"SCORE:%d",sf);
    settextstyle(9,HORIZ_DIR,3);
    outtextxy(1000,100,b);
}

