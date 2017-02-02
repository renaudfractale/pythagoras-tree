#include "qwidget_tree.h"

QWidget_tree::QWidget_tree(QWidget *parent) : QWidget(parent)
{
    //Init
        // SpinBox_Value
            SpinBox_Value = new QSpinBox();
                SpinBox_Value->setMinimum(0);
                SpinBox_Value->setMaximum(100);
                SpinBox_Value->setValue(0);
        //  Label_Prcent
            Label_Prcent= new QLabel("0.00%");
                Label_Prcent->setAlignment(Qt::AlignHCenter);
        Init();
        // layout
            VBoxLayout = new QVBoxLayout();
                VBoxLayout->addWidget(SpinBox_Value);
                VBoxLayout->addWidget(Label_Prcent);

    //Signale
        QObject::connect(SpinBox_Value,SIGNAL(valueChanged(int)),this,SIGNAL(Value_changed()));

    // setLayout
        this->setLayout(VBoxLayout);

}

void QWidget_tree::Init()
{
    Set_Prcent(0);
    Set_Value(0);
}

void QWidget_tree::Set_Prcent(double prcent)
{
    Prcent=prcent;

    int no=qRound(prcent*100);
    QString txt=QString::number((double)no/100)+"%";
    Label_Prcent->setText(txt);
}

void QWidget_tree::Set_Value(int value)
{
    SpinBox_Value->setValue(value);
}


int QWidget_tree::Get_Value()
{
    return SpinBox_Value->value();
}

double QWidget_tree::Get_Prcent()
{
    return Prcent;
}
