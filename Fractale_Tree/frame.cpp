#include "frame.h"


void Frame::Init(double x, double y, double d, double alpha)
{
    Frame::x=x;
    Frame::y=y;
    Frame::d=d;
    Frame::alpha=alpha;
}

void Frame::Add_alpha(double alpha)
{
    Frame::alpha=Frame::alpha+alpha;
}

void Frame::Set_d(double d)
{
    Frame::d=d;
}

void Frame::Move()
{
    double x2=Frame::Get_x2();
    double y2=Frame::Get_y2();
    Frame::x=x2;
    Frame::y=y2;

}

double Frame::Get_alpha()
{
    return Frame::alpha;
}

double Frame::Get_d()
{
    return Frame::d;
}

double Frame::Get_x1()
{
    return Frame::x;
}

double Frame::Get_y1()
{
    return Frame::y;
}

double Frame::Get_x2()
{
    return Frame::x+qCos(PI*Frame::alpha/180)*Frame::d;
}

double Frame::Get_y2()
{
    return Frame::y+qSin(PI*Frame::alpha/180)*Frame::d;
}

