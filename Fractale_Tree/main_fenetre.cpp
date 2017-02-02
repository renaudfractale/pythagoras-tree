#include "main_fenetre.h"


Main_fenetre::Main_fenetre(QWidget *parent) :
    QMainWindow(parent)
{
     Current_Update=true;
    qDebug() << "Etape 1.0";
    //Init widget
        QWidget *widget = new QWidget;
        setCentralWidget(widget);

        //setWindowIcon(QIcon("Icone.ico"));
        setWindowTitle("Fractale Tree");
    qDebug() << "Etape 2.0";
    // QWidget_trees
        Widget_trees = new QWidget_trees();
            Widget_trees->Set_Value_By_Index(0,30);
            Widget_trees->Set_Value_By_Index(1,30);
            Widget_trees->Set_Value_By_Index(2,30);
            QObject::connect(Widget_trees,SIGNAL(Value_changed()),this,SLOT(Plot_tree()));

    //  Widget_Config
        Widget_Config = new QWidget_Config();
            QObject::connect(Widget_Config,SIGNAL(Value_changed()),this,SLOT(Plot_tree()));

    // Widget_Ratio
        Widget_Ratio= new QWidget_Ratio();
            QObject::connect(Widget_Ratio,SIGNAL(Value_changed()),this,SLOT(Plot_tree()));

    // Widget_Graphique
        Widget_Graphique = new QWidget_Graphique();
            QObject::connect(Widget_Graphique,SIGNAL(Value_changed()),this,SLOT(Plot_tree()));

    // HBoxLayout
        HBoxLayout = new QHBoxLayout();
            HBoxLayout->addWidget(Widget_trees);
            HBoxLayout->addWidget(Widget_Config);
            HBoxLayout->addWidget(Widget_Ratio);
            HBoxLayout->addWidget(Widget_Graphique);
    qDebug() << "Etape 3.0";
    // Graphique
        //Init
        GraphicsView= new QGraphicsView();
        scene= new QGraphicsScene();
        GraphicsView->setScene(scene);

        PushButton_Zoom_P = new QPushButton("Zoom +");
        PushButton_Zoom_M = new QPushButton("Zoom -");
        //Layout_Zoom
        Layout_Zoom = new QHBoxLayout();
            Layout_Zoom->addWidget(PushButton_Zoom_P);
            Layout_Zoom->addWidget(PushButton_Zoom_M);
    qDebug() << "Etape 3.5";
    //Bar
    ProgressBar_Plot= new QProgressBar();
        ProgressBar_Plot->setMaximum(100);
        ProgressBar_Plot->setMinimum(0);
        ProgressBar_Plot->setValue(100);

    qDebug() << "Etape 4.0";
    //VBoxLayout
    VBoxLayout = new QVBoxLayout();
        VBoxLayout->addLayout(HBoxLayout);
        VBoxLayout->addWidget(GraphicsView,6);
        VBoxLayout->addLayout(Layout_Zoom);
        VBoxLayout->addWidget(ProgressBar_Plot);

     // TextBrowser
     TextBrowser= new QTextBrowser();
         TextBrowser->setSource(QUrl("Aide.html"));
         TextBrowser->hide();
     // HBoxLayout_all
    HBoxLayout_all = new QHBoxLayout();
        HBoxLayout_all->addLayout(VBoxLayout);
        HBoxLayout_all->addWidget(TextBrowser);

     // setLayout
      widget->setLayout(HBoxLayout_all);
    qDebug() << "Etape 5.0";
     //SLOT
         QObject::connect(PushButton_Zoom_M,SIGNAL(clicked(bool)),this,SLOT(Zoom_M()));
         QObject::connect(PushButton_Zoom_P,SIGNAL(clicked(bool)),this,SLOT(Zoom_P()));
     qDebug() << "Etape 6.0";
     // draw_Tree
         draw_Tree.Init(scene,ProgressBar_Plot);
     qDebug() << "Etape 7.0";
    //Plot_tree()
         Plot_tree();
     qDebug() << "Etape 8.0";
     createActions();
     createMenus();
}
void Main_fenetre::Zoom_M()
{
    GraphicsView->scale(0.75,0.75);
}

void Main_fenetre::Zoom_P()
{
    GraphicsView->scale(1.25,1.25);
}

void Main_fenetre::Plot_tree()
{
    if(Current_Update)
    {
        //scene= new QGraphicsScene();
        draw_Tree.Plot(Widget_trees,Widget_Config,Widget_Ratio,Widget_Graphique);
    }
    //draw_Tree.Save_file_svg("temp.svg");
}
void Main_fenetre::createActions()
{
    // Fichier
        newAct = new QAction(tr("&Nouveau"), this);
            newAct->setShortcuts(QKeySequence::New);
            newAct->setStatusTip(tr("Créer un nouveau fichier"));
            connect(newAct, &QAction::triggered, this, &Main_fenetre::newFile);
        openAct=  new QAction(tr("&Ouvrir"), this);
            openAct->setShortcuts(QKeySequence::Open);
            openAct->setStatusTip(tr("Ouvrir un fichier"));
            connect(openAct, &QAction::triggered, this, &Main_fenetre::open);
        saveAct=  new QAction(tr("&Sauvegarder"), this);
            saveAct->setShortcuts(QKeySequence::Save);
            saveAct->setStatusTip(tr("Sauvegarder un fichier"));
            connect(saveAct, &QAction::triggered, this, &Main_fenetre::save);
        saveAct_SVG=  new QAction(tr("S&auvegarder en svg"), this);
            saveAct_SVG->setShortcuts(QKeySequence::SaveAs);
            saveAct_SVG->setStatusTip(tr("Saauvegarder le fichier en svg"));
            connect(saveAct_SVG, &QAction::triggered, this, &Main_fenetre::save_svg);
    //A Propos
        presentation_dev_Act= new QAction(tr("A propos du &developeur"),this);
            presentation_dev_Act->setStatusTip(tr("A propos du developeur"));
            connect(presentation_dev_Act, &QAction::triggered, this, &Main_fenetre::Presentation_dev_Box);
        presentation_prog_Act= new QAction(tr("A propos du &programme"),this);
            presentation_prog_Act->setStatusTip(tr("A propos du programme"));
            connect(presentation_prog_Act, &QAction::triggered, this, &Main_fenetre::Presentation_prog_Box);
        aide_Act= new QAction(tr("&Aide"),this);
            aide_Act->setStatusTip(tr("Aide du programme"));
            connect(aide_Act, &QAction::triggered, this, &Main_fenetre::Aide_Box);
    // Exemples
        exemple_base_Act=new QAction(tr("&Base"),this);
            exemple_base_Act->setStatusTip(tr("Exemple de base"));
            connect(exemple_base_Act, &QAction::triggered, this, &Main_fenetre::exemple_base);
    // Arbre de Pythagore rectanculaire
        //Forme complexe
            exemple_Recabre_formecmplx_hypercube_Act=new QAction(tr("&HyperCube"),this);
                connect(exemple_Recabre_formecmplx_hypercube_Act, &QAction::triggered, this, &Main_fenetre::exemple_Recabre_formecmplx_hypercube);
            exemple_Recabre_formecmplx_logo_Act=new QAction(tr("&Logo"),this);
                connect(exemple_Recabre_formecmplx_logo_Act, &QAction::triggered, this, &Main_fenetre::exemple_Recabre_formecmplx_logo);
        // Arbre reel
            exemple_Recabre_Reel_symetrie_Act=new QAction(tr("Arbre &Symetrique"),this);
                connect(exemple_Recabre_Reel_symetrie_Act, &QAction::triggered, this, &Main_fenetre::exemple_Recabre_Reel_symetrie);
            exemple_Recabre_Reel_disymetrie_Act=new QAction(tr("Arbre &Dissymétrique"),this);
                connect(exemple_Recabre_Reel_disymetrie_Act, &QAction::triggered, this, &Main_fenetre::exemple_Recabre_Reel_disymetrie);
    // Arbre de Pythagore Carre
        // Arbre Symetrique
            exemple_Pyabre_symetrie_Mono_SansB_Act=new QAction(tr("Arbre rouge sans arrondi"),this);
                connect(exemple_Pyabre_symetrie_Mono_SansB_Act, &QAction::triggered, this, &Main_fenetre::exemple_Pyabre_symetrie_Mono_SansB);
            exemple_Pyabre_symetrie_Mono_AvecB_Act=new QAction(tr("Arbre rouge avec arrondi"),this);
                connect(exemple_Pyabre_symetrie_Mono_AvecB_Act, &QAction::triggered, this, &Main_fenetre::exemple_Pyabre_symetrie_Mono_AvecB);
            exemple_Pyabre_symetrie_Auto_SansB_Act=new QAction(tr("Arbre multi-color sans arrondi"),this);
                connect(exemple_Pyabre_symetrie_Auto_SansB_Act, &QAction::triggered, this, &Main_fenetre::exemple_Pyabre_symetrie_Auto_SansB);
            exemple_Pyabre_symetrie_Auto_AvecB_Act=new QAction(tr("Arbre multi-color avec arrondi"),this);
                connect(exemple_Pyabre_symetrie_Auto_AvecB_Act, &QAction::triggered, this, &Main_fenetre::exemple_Pyabre_symetrie_Auto_AvecB);
        // Arbre Dissymetrique faible;
            exemple_Pyabre_disymetrielow_Mono_SansB_Act=new QAction(tr("Arbre rouge sans arrondi"),this);
                connect(exemple_Pyabre_disymetrielow_Mono_SansB_Act, &QAction::triggered, this, &Main_fenetre::exemple_Pyabre_disymetrielow_Mono_SansB);
            exemple_Pyabre_disymetrielow_Mono_AvecB_Act=new QAction(tr("Arbre rouge avec arrondi"),this);
                connect(exemple_Pyabre_disymetrielow_Mono_AvecB_Act, &QAction::triggered, this, &Main_fenetre::exemple_Pyabre_disymetrielow_Mono_AvecB);
        // Arbre Dissymetrique Forte;
            exemple_Pyabre_disymetriemax_Auto_SansB_Act=new QAction(tr("Arbre multi-color sans arrondi"),this);
                connect(exemple_Pyabre_disymetriemax_Auto_SansB_Act, &QAction::triggered, this, &Main_fenetre::exemple_Pyabre_disymetriemax_Auto_SansB);
            exemple_Pyabre_disymetriemax_Auto_AvecB_Act=new QAction(tr("Arbre multi-color avec arrondi"),this);
                connect(exemple_Pyabre_disymetriemax_Auto_AvecB_Act, &QAction::triggered, this, &Main_fenetre::exemple_Pyabre_disymetriemax_Auto_AvecB);


    }
void Main_fenetre::createMenus()
{
    QMenuBar *menuBar_rh=new QMenuBar(0);
    fileMenu=menuBar_rh->addMenu(tr("&Fichier"));
        fileMenu->addAction(newAct);
        fileMenu->addAction(openAct);
        fileMenu->addAction(saveAct);
        fileMenu->addAction(saveAct_SVG);
    // Menu Exemples
    exempleMenu=menuBar_rh->addMenu(tr("&Exemples"));
        exempleMenu->addAction(exemple_base_Act);
            // Sub-menu Arbre carre
            exemple_Pyabre_symetrie_Group=exempleMenu->addMenu(tr("Arbres Carres &Symetrique"));
                exemple_Pyabre_symetrie_Group->addAction(exemple_Pyabre_symetrie_Mono_SansB_Act);
                exemple_Pyabre_symetrie_Group->addAction(exemple_Pyabre_symetrie_Mono_AvecB_Act);
                exemple_Pyabre_symetrie_Group->addAction(exemple_Pyabre_symetrie_Auto_SansB_Act);
                exemple_Pyabre_symetrie_Group->addAction(exemple_Pyabre_symetrie_Auto_AvecB_Act);
            // Sub-sub-menu Arbre dissymetrique faible
            exemple_Pyabre_disymetrielow_Group=exempleMenu->addMenu(tr("Arbres Carrés Dissymetriques F&aibles"));
                exemple_Pyabre_disymetrielow_Group->addAction(exemple_Pyabre_disymetrielow_Mono_SansB_Act);
                exemple_Pyabre_disymetrielow_Group->addAction(exemple_Pyabre_disymetrielow_Mono_AvecB_Act);
            // Sub-sub-menu Arbre dissymetrique forte
            exemple_Pyabre_disymetriemax_Group=exempleMenu->addMenu(tr("Arbres Carrés Dissymetriques F&ortes"));
                exemple_Pyabre_disymetriemax_Group->addAction(exemple_Pyabre_disymetriemax_Auto_SansB_Act);
                exemple_Pyabre_disymetriemax_Group->addAction(exemple_Pyabre_disymetriemax_Auto_AvecB_Act);
            // Sub-sub-menu Arbre naturel
            exemple_Recabre_Reel_Group=exempleMenu->addMenu(tr("Arbres Rectangulaire &Naturels"));
                exemple_Recabre_Reel_Group->addAction(exemple_Recabre_Reel_symetrie_Act);
                exemple_Recabre_Reel_Group->addAction(exemple_Recabre_Reel_disymetrie_Act);
            // Sub-sub-menu formes complexes
            exemple_Recabre_formecmplx_Group=exempleMenu->addMenu(tr("Formes Rectangulaire &Complexes"));
                exemple_Recabre_formecmplx_Group->addAction(exemple_Recabre_formecmplx_hypercube_Act);
                exemple_Recabre_formecmplx_Group->addAction(exemple_Recabre_formecmplx_logo_Act);


    aproposMenu=menuBar_rh->addMenu(tr("&?"));
        aproposMenu->addAction(aide_Act);
        aproposMenu->addAction(presentation_dev_Act);
        aproposMenu->addAction(presentation_prog_Act);

   setMenuBar(menuBar_rh);
}
void Main_fenetre::newFile()
{
    Open_file("new.datatree");
}

void Main_fenetre::open()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "data (*.datatree)");
    QMessageBox::about(this,"Namefile",fichier);
    if(!fichier.isEmpty())
        Open_file(fichier);
    //Open_file(fichier);
}
void Main_fenetre::save_svg()
{
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier sous le format SVG", QString(), "svg (*.svg)");
    QMessageBox::about(this,"Namefile",fichier);
    if(!fichier.isEmpty())
    {
        Plot_tree();
        draw_Tree.Save_file_svg("fichier");
    }

    //Widget_Plot->Save_As_SVG(fichier);
}

void Main_fenetre::save()
{
    QString fichier = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "data (*.datatree)");
    QMessageBox::about(this,"Namefile",fichier);
    if(!fichier.isEmpty())
        Save_file(fichier);
}

void Main_fenetre::Presentation_dev_Box()
{
   QMessageBox::about(this, "A propos du développeur",
                      "Développeur en C++, python, PHP et JavaScript, je suis passionné par la programmation et les mathématiques, notamment les fractales. Mes autres passions sont la photo et les panoramas à 360°.:\n" \
                      "Mes sites internet sont :\n" \
                      "> CV Mécatronique : http://www.renaud-henry.fr \n" \
                      "> Galerie photo : http://piwigo.rhenry.fr \n" \
                      "> Portfolio Photo : http://photo.rhenry.fr \n" \
                      "> Panoramas : http://pano.rhenry.fr \n" \
                      "> Visite virtuelle :  http://visite-virtuel.rhenry.fr");
}
void Main_fenetre::Presentation_prog_Box()
{
   QMessageBox::about(this, "A propos du programme",
                      "Nom du programme : Fractale Tree \n" \
                      "Version : 0.5 \n" \
                      "Date : 30 juin 2016 \n" \
                      "Développeur : Renaud HENRY \n" \
                      "Site web : http://fratale.rhenry.fr (en cours de construction) \n" \
                      "Email : fratale@rhenry.fr");
}
void Main_fenetre::Aide_Box()
{
    if(TextBrowser->isHidden())
    {
        TextBrowser->show();
    }
    else
    {
        TextBrowser->hide();
    }
}


void Main_fenetre::Save_file(QString fichier)
{
    QColor color;
    QFile file(fichier);
    if (file.open(QIODevice::WriteOnly))
    {
        QDataStream out(&file);
        //Version
        out << 1;
        //Trees :
        out << Widget_trees->Get_Nb_Widget_tree();
        for(int i=0;i<Widget_trees->Get_Nb_Widget_tree();i++)
        {
            out << Widget_trees->Get_Value_By_Index(i);
        }

        //Config
        out << Widget_Config->Get_Lenght();
        out << Widget_Config->Get_Niveau();
        out << Widget_Config->Get_SizePen();

        // Ration
        out << Widget_Ratio->Get_Ratio();
        out << Widget_Ratio->isChecked();

        //Graphique
        color=Widget_Graphique->Get_Color();
        out << color.red();
        out << color.green();
        out << color.blue();
        out << Widget_Graphique->Get_Color_Auto();
        out << Widget_Graphique->Get_with_Bout();

        file.close();
    }
}
void Main_fenetre::Open_file(QString fichier)
{
    Current_Update=false;
    int r,g,b,nb_ligne,Version;
    double d;
    bool bo;
    QColor color;

    QFile file(fichier);

    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);

        //Widget_trees
        in >> Version;
        if(Version==10)
        {
            nb_ligne=Version;
            for(int i=0;i<nb_ligne;i++)
            {
                in >> r;
                 Widget_trees->Set_Value_By_Index(i,r);
            }

            //Config
            in >> d;
            Widget_Config->Set_Lenght(d);
            in >> r;
            Widget_Config->Set_Niveau(r);
            in >> d;
            Widget_Config->Set_SizePen(d);

            //Ration
            Widget_Ratio->Set_Checked(true);
            in >> d;
            Widget_Ratio->Set_Ratio(d);
            in >> bo;
            Widget_Ratio->Set_Checked(bo);

            //Graphique
            in >> r;
            in >> g;
            in >> b;
            color.setRgb(r,g,b);
            Widget_Graphique->Set_Color(color);
            in >> bo;
            Widget_Graphique->Set_Color_Auto(bo);
            in >> bo;
            Widget_Graphique->Set_with_Bout(bo);
        }
        else if (Version==1)
        {
            in >> nb_ligne;
            for(int i=0;i<nb_ligne;i++)
            {
                in >> r;
                 Widget_trees->Set_Value_By_Index(i,r);
            }

            //Config
            in >> d;
            Widget_Config->Set_Lenght(d);
            in >> r;
            Widget_Config->Set_Niveau(r);
            in >> d;
            Widget_Config->Set_SizePen(d);

            //Ration
            Widget_Ratio->Set_Checked(true);
            in >> d;
            Widget_Ratio->Set_Ratio(d);
            in >> bo;
            Widget_Ratio->Set_Checked(bo);

            //Graphique
            in >> r;
            in >> g;
            in >> b;
            color.setRgb(r,g,b);
            Widget_Graphique->Set_Color(color);
            in >> bo;
            Widget_Graphique->Set_Color_Auto(bo);
            in >> bo;
            Widget_Graphique->Set_with_Bout(bo);
        }

        file.close();

    }
    Current_Update=true;
    Plot_tree();
    Zoom_M();
    Zoom_P();
}

void Main_fenetre::exemple_base()
{
    Open_file("exemples/000_exemple_base_Act.datatree");
}

void Main_fenetre::exemple_Pyabre_disymetrielow_Mono_AvecB()
{
    Open_file("exemples/022_exemple_Pyabre_disymetrielow_Mono_AvecB_Act.datatree");

}

void Main_fenetre::exemple_Pyabre_disymetrielow_Mono_SansB()
{
    Open_file("exemples/021_exemple_Pyabre_disymetrielow_Mono_SansB_Act.datatree");


}
void Main_fenetre::exemple_Pyabre_disymetriemax_Auto_AvecB()
{
    Open_file("exemples/032_exemple_Pyabre_disymetriemax_Auto_AvecB_Act.datatree");


}
void Main_fenetre::exemple_Pyabre_disymetriemax_Auto_SansB()
{
    Open_file("exemples/031_exemple_Pyabre_disymetriemax_Auto_SansB_Act.datatree");


}
void Main_fenetre::exemple_Pyabre_symetrie_Auto_AvecB()
{
    Open_file("exemples/014_exemple_Pyabre_symetrie_Auto_AvecB_Act.datatree");


}
void Main_fenetre::exemple_Pyabre_symetrie_Auto_SansB()
{
    Open_file("exemples/013_exemple_Pyabre_symetrie_Auto_SansB_Act.datatree");

}
void Main_fenetre::exemple_Pyabre_symetrie_Mono_AvecB()
{
    Open_file("exemples/012_exemple_Pyabre_symetrie_Mono_AvecB_Act.datatree");

}
void Main_fenetre::exemple_Pyabre_symetrie_Mono_SansB()
{
    Open_file("exemples/011_exemple_Pyabre_symetrie_Mono_SansB_Act.datatree");

}

void Main_fenetre::exemple_Recabre_formecmplx_hypercube()
{
    Open_file("exemples/051_exemple_Recabre_formecmplx_hypercube_Act.datatree");

}
void Main_fenetre::exemple_Recabre_formecmplx_logo()
{
    Open_file("exemples/052_exemple_Recabre_formecmplx_logo_Act.datatree");

}
void Main_fenetre::exemple_Recabre_Reel_disymetrie()
{
    Open_file("exemples/042_exemple_Recabre_Reel_disymetrie_Act.datatree");

}
void Main_fenetre::exemple_Recabre_Reel_symetrie()
{
    Open_file("exemples/041_exemple_Recabre_Reel_symetrie_Act.datatree");

}
