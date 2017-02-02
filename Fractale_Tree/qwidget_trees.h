#ifndef QWIDGET_TREES_H
#define QWIDGET_TREES_H
/*!
 * \file qwidget_trees.h
 * \brief Widget trees, Gestion un nombre de branche et de leurs largeur
 * \author Henry Renaud
 * \version 0.5
 */
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QDebug>


#include "qwidget_tree.h"
#include "stock_prcent.h"


class QWidget_trees : public QWidget
{
    Q_OBJECT
public:
    explicit QWidget_trees();

    int Get_Nb_Widget_tree();

    int Get_Value_By_Index(int index);
    Stock_Prcent Get_Stock_Prcent();

    void Set_Value_By_Index(int index, int value);


private:
    int nb_Widget_tree;

    QWidget_tree *Tab_Widget_tree[10];

    QHBoxLayout *HBoxLayout;

    Stock_Prcent stock_prcent;


signals:
    void Value_changed();
public slots:
    void Update_Value();
};

#endif // QWIDGET_TREES_H
