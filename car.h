#ifndef CAR_H
#define CAR_H

#include <iostream>
#include<graphics.h>
#include<windows.h>


class car
{
    public:
        float x=495,y=760,speed=10,f=0;

        void move_car();
        void make_car();

    protected:

    private:
};


#endif // CAR_H
