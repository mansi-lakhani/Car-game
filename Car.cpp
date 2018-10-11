#include "Car.h"
Car::Car()
{

}

Car::~Car()
{
    //dtor
}

void Car::makecar()
{
    setfillstyle(SOLID_FILL,BLUE);
    bar(x+158,y,x+218,y-100);
    setfillstyle(SOLID_FILL,BLACK);
    bar(x+158,y-25,x+148,y-10);     //bar1
    bar(x+158,y-90,x+148,y-75);     //bar2
    bar(x+218,y-90,x+228,y-75);     //bar3
    bar(x+228,y-25,x+218,y-10);     //bar4

}
void Car::movecar()
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

    if((y-100)==480)
    {
        setfillstyle(SOLID_FILL,DARKGRAY);
        bar(500,480,540,420);
    }
}
