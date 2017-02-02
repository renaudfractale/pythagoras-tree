#include "stock_prcent.h"

Stock_Prcent::Stock_Prcent()
{
    ;
}

 void Stock_Prcent::Set_Size(int size)
 {
     Size=size;
 }

 void Stock_Prcent::Set_Prcent_By_Index(int index, double prcent)
 {
     if(index>=0 && index<Size)
     {
         Tab_Prcent[index]=prcent;
         Tab_Angle[index]=prcent/100*180;
     }
 }

 int Stock_Prcent::Get_size()
 {
     return Size;
 }

 double Stock_Prcent::Get_Prcent_By_Index(int index)
 {
     if(index>=0 && index<Size)
     {
         return Tab_Prcent[index];
     }
     return 0;
 }
 double Stock_Prcent::Get_Angle_By_Index(int index)
 {
     if(index>=0 && index<Size)
     {
         return Tab_Angle[index];
     }
     return 0;
 }
