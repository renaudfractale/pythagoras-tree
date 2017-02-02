#ifndef QWIDGET_GRAPHIQUE_H
#define QWIDGET_GRAPHIQUE_H
/*!
 * \file qwidget_graphique.h
 * \brief Widget Couleur et Bout de l'abre
 * \author Henry Renaud
 * \version 0.5
 */

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QRadioButton>
#include <QColorDialog>
#include <QDebug>
#include <QGroupBox>
class QWidget_Graphique : public QWidget
{
    Q_OBJECT
public:
    explicit QWidget_Graphique(QWidget *parent = 0);

    QColor Get_Color();
    void Set_Color(QColor color);

    bool Get_with_Bout();
    void Set_with_Bout(bool etat);

    bool Get_Color_Auto();
    void Set_Color_Auto(bool etat);



private:


    QGridLayout *layout;

    QLabel *Label_bout;
    QPushButton *PushButton_Color;

    QCheckBox *CheckBox_Color;
    QRadioButton *RadioButton_Bout_with;
    QRadioButton *RadioButton_Bout_without;
    QColor Color;

signals:
    void Value_changed();
public slots:
    void Button_color_clicked();
    void Update_Etat();
};

#endif // QWIDGET_GRAPHIQUE_H
