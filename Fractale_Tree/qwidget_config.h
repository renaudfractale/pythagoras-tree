#ifndef QWIDGET_CONFIG_H
#define QWIDGET_CONFIG_H
/*!
 * \file qwidget_config.h
 * \brief Widget de configuration d'affichage de niveau des branches
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
#include <QGroupBox>
/*! \class QWidget_Config
 * \brief Widget de configuration d'affichage de niveau des branches
 *
 *  La classe gere les fonctions de deplacement des branches
 */
class QWidget_Config : public QWidget
{
    Q_OBJECT
public:
    explicit QWidget_Config(QWidget *parent = 0);

    int Get_Niveau();
    double Get_SizePen();
    double Get_Lenght();


    void Set_Niveau(int niveau);
    void Set_SizePen(double sizePen);
    void Set_Lenght(double lenght);



private :
    QGridLayout *layout;

    QSpinBox *SpinBox_niveau;
    QDoubleSpinBox *DoubleSpinBox_sizePen;
    QDoubleSpinBox *DoubleSpinBox_lenght;


    QLabel *Label_niveau;
    QLabel *Label_sizePen;
    QLabel *Label_lenght;


signals:
    void Value_changed();
public slots:
};

#endif // QWIDGET_CONFIG_H
