#include "qwidget_ratio.h"

QWidget_Ratio::QWidget_Ratio(QWidget *parent) : QWidget(parent)
{
    // Init
        DoubleSpinBox_ration = new QDoubleSpinBox();
            DoubleSpinBox_ration->setMinimum(0);
            DoubleSpinBox_ration->setMaximum(200);
            DoubleSpinBox_ration->setValue(80);

        Label_ration= new QLabel("Ratio en %");
            Label_ration->setAlignment(Qt::AlignHCenter);
        CheckBox = new QCheckBox("");
            CheckBox->setChecked(true);
    // QGridLayout_ratio
       QGridLayout *QGridLayout_ratio = new QGridLayout;
            QGridLayout_ratio->addWidget(Label_ration,1,1,1,2);
            QGridLayout_ratio->addWidget(CheckBox,2,1);
            QGridLayout_ratio->addWidget(DoubleSpinBox_ration,2,2);
    //QGroupBox_ratio
        QGroupBox *QGroupBox_ratio = new QGroupBox(tr("Ratio"));
            QGroupBox_ratio->setLayout(QGridLayout_ratio);

    layout = new QGridLayout();
    layout->addWidget(QGroupBox_ratio);
    this->setLayout(layout);

    QObject::connect(DoubleSpinBox_ration,SIGNAL(valueChanged(double)),this,SIGNAL(Value_changed()));
    QObject::connect(CheckBox,SIGNAL(stateChanged(int)),this,SIGNAL(Value_changed()));
    QObject::connect(CheckBox,SIGNAL(stateChanged(int)),this,SLOT(CheckBox_Update()));
}


void QWidget_Ratio::Set_Ratio(double ratio)
{
    DoubleSpinBox_ration->setValue(ratio);
}

double QWidget_Ratio::Get_Ratio()
{
    return DoubleSpinBox_ration->value();
}

void QWidget_Ratio::CheckBox_Update()
{
    DoubleSpinBox_ration->setEnabled(CheckBox->isChecked());
}

bool QWidget_Ratio::isChecked()
{
    return CheckBox->isChecked();
}

void QWidget_Ratio::Set_Checked(bool etat)
{
    CheckBox->setChecked(etat);
}
