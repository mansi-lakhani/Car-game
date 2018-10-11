#include "car.h"

void car::move_car()
{
    int t_l;
    if(GetAsyncKeyState(VK_LEFT))
       {
        if(t_l>=495 && t_l<=871)
       t_l=(x+158)-speed;
       }
    else if(GetAsyncKeyState(VK_RIGHT));
        {
            if(t_l>=495 && t_l<=871)
            t_l=(x+218)+speed;
    }
}
void car :: make_car()
{
            setcolor(BLUE);
            setfillstyle(SOLID_FILL,BLUE);
            bar(x+158,y,x+218,y-100);       //CAR

            //tyres
            setcolor(BLACK);
            bar(x+158,y-25,x+148,y-10);     //tyre1
            bar(x+158,y-90,x+148,y-75);     //tyre2
            bar(x+218,y-90,x+228,y-75);     //tyre3
            bar(x+238,y-25,x+228,y-10);     //tyre4
}

