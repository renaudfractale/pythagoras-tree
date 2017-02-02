#ifndef QWIDGET_TREE_H
#define QWIDGET_TREE_H
/*!
 * \file qwidget_tree.h
 * \brief Widget tree : Elements de QWidget_trees
 * \author Henry Renaud
 * \version 0.5
 */
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSpinBox>
#include <QLabel>
#include <QtMath>
#include <QVBoxLayout>
class QWidget_tree : public QWidget
{
    Q_OBJECT
public:
    explicit QWidget_tree(QWidget *parent = 0);

    int Get_Value();
    void Set_Value(int value);

    double Get_Prcent();
    void Set_Prcent(double prcent);

    void Init();



private:
    double Prcent;

    QSpinBox *SpinBox_Value;
    QLabel *Label_Prcent;

    QVBoxLayout *VBoxLayout;


signals:
    void Value_changed();

public slots:
};

#endif // QWIDGET_TREE_H
