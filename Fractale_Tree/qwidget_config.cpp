#include "qwidget_config.h"

QWidget_Config::QWidget_Config(QWidget *parent) : QWidget(parent)
{

    // Init :
        DoubleSpinBox_lenght= new QDoubleSpinBox();
            DoubleSpinBox_lenght->setMinimum(10);
            DoubleSpinBox_lenght->setMaximum(200);
            DoubleSpinBox_lenght->setValue(100);

        SpinBox_niveau= new QSpinBox();
            SpinBox_niveau->setMinimum(0);
            SpinBox_niveau->setMaximum(15);
            SpinBox_niveau->setValue(3);

        DoubleSpinBox_sizePen= new QDoubleSpinBox();
            DoubleSpinBox_sizePen->setMinimum(1);
            DoubleSpinBox_sizePen->setMaximum(200);
            DoubleSpinBox_sizePen->setValue(30);

        Label_lenght= new QLabel("Longeur");
            Label_lenght->setAlignment(Qt::AlignHCenter);
        Label_niveau= new QLabel("Niveau max");
            Label_niveau->setAlignment(Qt::AlignHCenter);
        Label_sizePen= new QLabel("Largeur");
            Label_sizePen->setAlignment(Qt::AlignHCenter);
    // GridLayou_config
        QGridLayout *GridLayou_config = new QGridLayout;
            GridLayou_config->addWidget(Label_niveau,1,1);
            GridLayou_config->addWidget(Label_lenght,1,2);
            GridLayou_config->addWidget(Label_sizePen,1,3);

            GridLayou_config->addWidget(SpinBox_niveau,2,1);
            GridLayou_config->addWidget(DoubleSpinBox_lenght,2,2);
            GridLayou_config->addWidget(DoubleSpinBox_sizePen,2,3);

    //QGroupBox_config
        QGroupBox *QGroupBox_config = new QGroupBox(tr("Configuration"));
            QGroupBox_config->setLayout(GridLayou_config);

    layout = new QGridLayout();
    layout->addWidget(QGroupBox_config);
    this->setLayout(layout);

    //Signale
        QObject::connect(SpinBox_niveau,SIGNAL(valueChanged(int)),this,SIGNAL(Value_changed()));
        QObject::connect(DoubleSpinBox_lenght,SIGNAL(valueChanged(double)),this,SIGNAL(Value_changed()));
        QObject::connect(DoubleSpinBox_sizePen,SIGNAL(valueChanged(double)),this,SIGNAL(Value_changed()));


}

double QWidget_Config::Get_Lenght()
{
    return DoubleSpinBox_lenght->value();
}

int QWidget_Config::Get_Niveau()
{
    return SpinBox_niveau->value();
}

double QWidget_Config::Get_SizePen()
{
    return DoubleSpinBox_sizePen->value();
}


void QWidget_Config::Set_Lenght(double lenght)
{
    DoubleSpinBox_lenght->setValue(lenght);
}

void QWidget_Config::Set_Niveau(int niveau)
{
    SpinBox_niveau->setValue(niveau);
}

void QWidget_Config::Set_SizePen(double sizePen)
{
    DoubleSpinBox_sizePen->setValue(sizePen);
}

