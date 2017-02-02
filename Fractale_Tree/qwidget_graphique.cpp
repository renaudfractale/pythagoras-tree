#include "qwidget_graphique.h"

QWidget_Graphique::QWidget_Graphique(QWidget *parent) : QWidget(parent)
{


    // Init
        CheckBox_Color= new QCheckBox("Couleur automatique");
        PushButton_Color = new QPushButton("COLOR");
        RadioButton_Bout_with = new QRadioButton("Avec bout rond");
            RadioButton_Bout_with->setChecked(true);
        RadioButton_Bout_without = new QRadioButton("Sans bout rond");

    //HBoxLayou_graphique
        QGridLayout *HBoxLayou_graphique = new QGridLayout;
            HBoxLayou_graphique->addWidget(CheckBox_Color,1,1);
            HBoxLayou_graphique->addWidget(PushButton_Color,2,1);

            HBoxLayou_graphique->addWidget(RadioButton_Bout_with,1,2);
            HBoxLayou_graphique->addWidget(RadioButton_Bout_without,2,2);

    //  QGroupBox_graphique
    QGroupBox *QGroupBox_graphique = new QGroupBox(tr("Graphique"));
        QGroupBox_graphique->setLayout(HBoxLayou_graphique);

    layout = new QGridLayout();
        layout->addWidget(QGroupBox_graphique,1,1);
    this->setLayout(layout);

    QObject::connect(RadioButton_Bout_with,SIGNAL(clicked(bool)),this,SIGNAL(Value_changed()));
    QObject::connect(RadioButton_Bout_without,SIGNAL(clicked(bool)),this,SIGNAL(Value_changed()));

    QObject::connect(CheckBox_Color,SIGNAL(stateChanged(int)),this,SIGNAL(Value_changed()));

    QObject::connect(PushButton_Color,SIGNAL(clicked(bool)),this,SIGNAL(Value_changed()));
    QObject::connect(PushButton_Color,SIGNAL(clicked(bool)),this,SLOT(Button_color_clicked()));

    QObject::connect(this,SIGNAL(Value_changed()),this,SLOT(Update_Etat()));

    Color.setRgb(254,0,0);
    Set_Color(Color);
}

void QWidget_Graphique::Button_color_clicked()
{
    Color = QColorDialog::getColor(Color, this);
    Set_Color(Color);
}

void QWidget_Graphique::Update_Etat()
{
    PushButton_Color->setEnabled(!CheckBox_Color->isChecked());
}



QColor QWidget_Graphique::Get_Color()
{
    return Color;
}

void QWidget_Graphique::Set_Color(QColor color)
{
    Color=color;

    QPalette palette;
    palette.setColor(QPalette::ButtonText, Color);
    PushButton_Color->setPalette(palette);
}

bool QWidget_Graphique::Get_with_Bout()
{
    return RadioButton_Bout_with->isChecked();
}

void QWidget_Graphique::Set_with_Bout(bool etat)
{
    RadioButton_Bout_with->setChecked(etat);
}

bool QWidget_Graphique::Get_Color_Auto()
{
    return CheckBox_Color->isChecked();
}

void QWidget_Graphique::Set_Color_Auto(bool etat)
{
    CheckBox_Color->setChecked(etat);
}
