#ifndef MAIN_FENETRE_H
#define MAIN_FENETRE_H
/*!
 * \file main_fenetre.h
 * \brief Affichage principal
 * \author Henry Renaud
 * \version 0.5
 */
#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QDebug>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextBrowser>
#include <QProgressBar>

#include "qwidget_trees.h"
#include "draw_tree.h"
#include "qwidget_config.h"
#include "qwidget_ratio.h"
#include "qwidget_graphique.h"
  /*! \class Main_fenetre
   * \brief classe d'affichage de la fenetre principale du logiciel
   *
   *  La classe gere :
   *		Les Menus
   *		Les widget personalisés
   */
namespace Ui {
class Main_fenetre;
}

class Main_fenetre : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main_fenetre(QWidget *parent=0);

private:

    void createActions();
    void createMenus();

    void Save_file(QString fichier);
    void Open_file(QString fichier);


    QVBoxLayout *VBoxLayout;

    QWidget_trees *Widget_trees;

    QGraphicsView *GraphicsView;
    QGraphicsScene *scene;

    QHBoxLayout *Layout_Zoom;
    QPushButton *PushButton_Zoom_P;
    QPushButton *PushButton_Zoom_M;

    Draw_Tree draw_Tree;

    QHBoxLayout *HBoxLayout;

    QWidget_Config *Widget_Config;

    QWidget_Ratio *Widget_Ratio;

    QWidget_Graphique *Widget_Graphique;

    QMenu *fileMenu;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *saveAct_SVG;

    QMenu *exempleMenu;
    QAction *exemple_base_Act;
    QMenu *exemple_Recabre_Group;
        QMenu *exemple_Recabre_formecmplx_Group;
            QAction *exemple_Recabre_formecmplx_hypercube_Act;
            QAction *exemple_Recabre_formecmplx_logo_Act;
        QMenu *exemple_Recabre_Reel_Group;
            QAction *exemple_Recabre_Reel_symetrie_Act;
            QAction *exemple_Recabre_Reel_disymetrie_Act;
    QMenu *exemple_Pyabre_Group;
        QMenu *exemple_Pyabre_symetrie_Group;
            QAction *exemple_Pyabre_symetrie_Mono_SansB_Act;
            QAction *exemple_Pyabre_symetrie_Mono_AvecB_Act;
            QAction *exemple_Pyabre_symetrie_Auto_SansB_Act;
            QAction *exemple_Pyabre_symetrie_Auto_AvecB_Act;
        QMenu *exemple_Pyabre_disymetrielow_Group;
            QAction *exemple_Pyabre_disymetrielow_Mono_SansB_Act;
            QAction *exemple_Pyabre_disymetrielow_Mono_AvecB_Act;
        QMenu *exemple_Pyabre_disymetriemax_Group;
            QAction *exemple_Pyabre_disymetriemax_Auto_SansB_Act;
            QAction *exemple_Pyabre_disymetriemax_Auto_AvecB_Act;

    QMenu *aproposMenu;
    QAction *presentation_dev_Act;
    QAction *presentation_prog_Act;
    QAction *aide_Act;

    bool Current_Update;

    QTextBrowser *TextBrowser;
    QHBoxLayout *HBoxLayout_all;

    QProgressBar *ProgressBar_Plot;

private slots:
    void newFile();
    void open();
    void save();
    void save_svg();

    //Base
        void exemple_base();
    // Pyabre carré
        //Symetrie
            void exemple_Pyabre_symetrie_Mono_SansB();
            void exemple_Pyabre_symetrie_Mono_AvecB();
            void exemple_Pyabre_symetrie_Auto_SansB();
            void exemple_Pyabre_symetrie_Auto_AvecB();
        // DiSymetrie faible
            void exemple_Pyabre_disymetrielow_Mono_SansB();
            void exemple_Pyabre_disymetrielow_Mono_AvecB();
        // DiSymetrie forte
            void exemple_Pyabre_disymetriemax_Auto_SansB();
            void exemple_Pyabre_disymetriemax_Auto_AvecB();
    // Pyabre rectangle
        // Forme Complexe
            void exemple_Recabre_formecmplx_hypercube();
            void exemple_Recabre_formecmplx_logo();
        // Arbre Reel
            void exemple_Recabre_Reel_symetrie();
            void exemple_Recabre_Reel_disymetrie();


    void Presentation_dev_Box();
    void Presentation_prog_Box();

    void Aide_Box();

public slots:
    void Zoom_P();
    void Zoom_M();
    void Plot_tree();

};

#endif // MAIN_FENETRE_H
