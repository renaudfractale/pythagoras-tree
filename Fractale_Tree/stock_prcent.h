#ifndef STOCK_PRCENT_H
#define STOCK_PRCENT_H
/*!
 * \file stock_Prcent.h
 * \brief Class de gestion du pourcenatage : Elements de QWidget_trees
 * \author Henry Renaud
 * \version 0.5
 */

class Stock_Prcent
{
public:
    Stock_Prcent();

    void Set_Size(int size);
    int Get_size();

    double Get_Prcent_By_Index(int index);
    void Set_Prcent_By_Index(int index,double prcent);

    double Get_Angle_By_Index(int index);

private:
    int Size;
    double Tab_Prcent[10];
    double Tab_Angle[10];
};

#endif // STOCK_PRCENT_H
