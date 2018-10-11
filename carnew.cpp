#include <iostream>
#include<graphics.h>
#include<windows.h>

int f,x=495,y=760;

//bar
int bar(int f)
    {
        if (f==1)
            f=0;
        else
            f=1;

    }



//car

int car(int f)
    {
        //move_car();
        {
            setcolor(BLUE);
            setfillstyle(SOLID_FILL,BLUE);
            bar(x+158,y,x+218,y-100);       //CAR

        }
    }


int main()
{
    DWORD ScreenWidth=GetSystemMetrics(SM_CXSCREEN);
    DWORD ScreenHeight=GetSystemMetrics(SM_CYSCREEN);
    std::cout<<ScreenWidth<<std::endl;
    std::cout<<ScreenHeight<<std::endl;
    initwindow(ScreenWidth,ScreenHeight,"CAR GAMES");
int page=0;
    //car

    while(1)
    {

        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        if(f==0)
            f=1;
        else
            f=0;
        car(f);
        bar(f);
        delay(20);
        getch();
    }
}
