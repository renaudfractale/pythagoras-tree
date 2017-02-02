#ifndef FRAME_H
#define FRAME_H
#include <QString>
#include <QtMath>
#define PI 3.14159265358979323846
/*!
 * \file frame.h
 * \brief lib gestion de repère 2D
 * \author Henry Renaud
 * \version 0.5
 */
/*! \class Frame
 * \brief lib gestion de repère 2D
 *
 *  La classe gere les fonctions de deplacement des branches
 */
class Frame
{
public:
    void Init(double x,double y,double d,double alpha);
    double Get_x1();
    double Get_y1();
    double Get_x2();
    double Get_y2();
    double Get_d();
    double Get_alpha();
    void Set_d(double d);
    void Add_alpha(double alpha);
    void Move();
   /* Qstring print_x1();
    Qstring print_y1();
    Qstring print_s();
    Qstring print_angle();*/
private:
    double x;
    double y;
    double d;
    double alpha;

};

#endif // FRAME_H
