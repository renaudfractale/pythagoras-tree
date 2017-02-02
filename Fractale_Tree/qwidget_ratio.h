#ifndef QWIDGET_RATIO_H
#define QWIDGET_RATIO_H
/*!
 * \file qwidget_ratio.h
 * \brief Widget ratio, gere le ratio de longueur entre le branche n-1 et la branche n
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
#include <QGroupBox>

class QWidget_Ratio : public QWidget
{
    Q_OBJECT
public:
    explicit QWidget_Ratio(QWidget *parent = 0);

    double Get_Ratio();
    void Set_Ratio(double ratio);

    bool isChecked();
    void Set_Checked(bool etat);
private :
    QGridLayout *layout;

    QDoubleSpinBox *DoubleSpinBox_ration;
    QLabel *Label_ration;

    QCheckBox *CheckBox;



signals:
    void Value_changed();
public slots:
    void CheckBox_Update();
};

#endif // QWIDGET_RATIO_H
