#include "qwidget_trees.h"

QWidget_trees::QWidget_trees() : QWidget()
{
    qDebug() << "Etape 2.1";
    //Init
    nb_Widget_tree=10;
    stock_prcent.Set_Size(nb_Widget_tree);

    // HBoxLayou_tree
    QHBoxLayout *HBoxLayou_tree = new QHBoxLayout;
    //Boucle Tab_Widget_tree
    for(int i=0;i<nb_Widget_tree;i++)
    {
        Tab_Widget_tree[i] = new QWidget_tree();
        HBoxLayou_tree->addWidget(Tab_Widget_tree[i]);
        QObject::connect(Tab_Widget_tree[i],SIGNAL(Value_changed()),this,SIGNAL(Value_changed()));
    }
    //QGroupBox_tree
        QGroupBox *QGroupBox_tree = new QGroupBox(tr("Tree"));
        QGroupBox_tree->setLayout(HBoxLayou_tree);

        // HBoxLayout
    HBoxLayout = new QHBoxLayout();
        HBoxLayout->addWidget(QGroupBox_tree);

    //setLayout
    this->setLayout(HBoxLayout);

    //Upadate
    Update_Value();

    //
    QObject::connect(this,SIGNAL(Value_changed()),this,SLOT(Update_Value()));
}

void QWidget_trees::Update_Value()
{
    int total=0;
    for(int i=0;i<nb_Widget_tree;i++)
    {
        total=total+Tab_Widget_tree[i]->Get_Value();
    }
    double prcent=100/((double)total);
    for(int i=0;i<nb_Widget_tree;i++)
    {
        int value=Tab_Widget_tree[i]->Get_Value();
        Tab_Widget_tree[i]->Set_Prcent(value*prcent);
        stock_prcent.Set_Prcent_By_Index(i,value*prcent);
    }
}


Stock_Prcent QWidget_trees::Get_Stock_Prcent()
{
    return stock_prcent;
}


int QWidget_trees::Get_Value_By_Index(int index)
{
    if(index>=0 && index<nb_Widget_tree)
    {
        return Tab_Widget_tree[index]->Get_Value();
    }
    return 0;
}

int QWidget_trees::Get_Nb_Widget_tree()
{
    return nb_Widget_tree;
}


void QWidget_trees::Set_Value_By_Index(int index, int value)
{
    if(index>=0 && index<nb_Widget_tree)
    {
        Tab_Widget_tree[index]->Set_Value(value);
    }
}

