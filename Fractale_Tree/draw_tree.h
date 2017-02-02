#ifndef DRAW_TREE_H
#define DRAW_TREE_H
/*!
 * \file draw_tree.h
 * \brief lib affichage de l'arbre
 * \author Henry Renaud
 * \version 0.5
 */

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QFile>
#include <QTextStream>
#include <QProgressBar>

#include "frame.h"
#include "stock_prcent.h"
#include "qwidget_trees.h"
#include "qwidget_config.h"
#include "qwidget_ratio.h"
#include "qwidget_graphique.h"
  /*! \class Draw_Tree
   * \brief lib de l'affichage de l'arbre
   *
   *  La classe gere les fonctions d'affichage et de sauvegarde en SVG des arbres
   */
class Draw_Tree
{
public:
   Draw_Tree();
    /*!
     *  \brief Initialise la class
     *
     *  Methode qui initalise la class
     *
     *  \param *scene : Scene du QWidget_Graphique
     *  \param *ProgressBar_Plot : Barre de progression des calculs
     */
   void Init(QGraphicsScene *scene,QProgressBar *ProgressBar_Plot);
    /*!
     *  \brief Initialise la class
     *
     *  Methode qui initalise la class
     *
     *  \param *scene : Scene du QWidget_Graphique
     *  \param *ProgressBar_Plot : Barre de progression des calculs
     */
   void Clear();
   void Plot(QWidget_trees *Widget_trees,QWidget_Config *Widget_Config,QWidget_Ratio *Widget_Ratio,QWidget_Graphique *Widget_Graphique);
   void Save_file_svg(QString namefile);
private:
    void Draw_Graph();
    void Draw_Line();

    void Sub_Draw();

    Frame frame;

    int niveau;
    int niveau_max;
    double lenght;
    double sizePen;
    double prcent_lenght;
    bool etat_ratio;
    QColor color;
    bool color_auto;
    bool with_bout;

    bool IsSaveSVG;

    QGraphicsScene *scene;

    Stock_Prcent stock_prcent;

    QFile file;
    //QTextStream out;

    double X_max;
    double Y_max;
    double X_min;
    double Y_min;

    QProgressBar *ProgressBar;
};

#endif // DRAW_TREE_H
