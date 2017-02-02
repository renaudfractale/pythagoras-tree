#include "draw_tree.h"

Draw_Tree::Draw_Tree()
{
    IsSaveSVG=false;
}

void Draw_Tree::Save_file_svg(QString namefile)
{
    IsSaveSVG=true;
    file.setFileName(namefile);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        //out.);
        QTextStream out(&file);
        out << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
        out << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"" << X_max-X_min+200 <<"\" height=\"" << Y_max-Y_min+200 << "\">\n";
        file.close();

            Draw_Graph();
        if(file.open(QIODevice::Append  | QIODevice::Text))
        {
            QTextStream out(&file);
            out << "</svg>";
            file.close();
        }


    }
    IsSaveSVG=false;
}


void Draw_Tree::Init(QGraphicsScene *scene, QProgressBar *ProgressBar_Plot)
{
    Draw_Tree::scene = scene;
    ProgressBar=ProgressBar_Plot;
}

void Draw_Tree::Clear()
{
    if(!IsSaveSVG)
    {
        X_max=0;
        X_min=0;
        Y_max=0;
        Y_min=0;
    }

    frame.Init(0,0,lenght,-90);

    scene->clear();
}

void Draw_Tree::Plot(QWidget_trees *Widget_trees,QWidget_Config *Widget_Config,QWidget_Ratio *Widget_Ratio,QWidget_Graphique *Widget_Graphique)
{
    //Init
    stock_prcent=Widget_trees->Get_Stock_Prcent();

    niveau=Widget_Config->Get_Niveau();
    niveau_max=Widget_Config->Get_Niveau();

    lenght=Widget_Config->Get_Lenght();
    sizePen=Widget_Config->Get_SizePen();

    prcent_lenght=Widget_Ratio->Get_Ratio()/100;
    etat_ratio=Widget_Ratio->isChecked();

    color=Widget_Graphique->Get_Color();
    color_auto=Widget_Graphique->Get_Color_Auto();

    with_bout=Widget_Graphique->Get_with_Bout();

    Draw_Graph();

    //Init
    stock_prcent=Widget_trees->Get_Stock_Prcent();

    niveau=Widget_Config->Get_Niveau();
    niveau_max=Widget_Config->Get_Niveau();

    lenght=Widget_Config->Get_Lenght();
    sizePen=Widget_Config->Get_SizePen();

    prcent_lenght=Widget_Ratio->Get_Ratio()/100;
    etat_ratio=Widget_Ratio->isChecked();

    color=Widget_Graphique->Get_Color();
    color_auto=Widget_Graphique->Get_Color_Auto();

    with_bout=Widget_Graphique->Get_with_Bout();
}
void Draw_Tree::Draw_Graph()
{
    // Clear();
    Clear();
    //base
    Draw_Line();
    frame.Move();
    //draw
    Frame frame_loc=frame;
    double lenght_loc=lenght;
    double sizePen_loc=sizePen;
    int nb_branche=0;

    for(int i=0;i<stock_prcent.Get_size();i++)
    {
        if(stock_prcent.Get_Prcent_By_Index(i)>0)
            nb_branche++;
    }
    int nb_max=0;
    for(int i=1;i<=niveau_max;i++)
    {
        nb_max=nb_max+(int)qPow(nb_branche,i);
    }
    ProgressBar->setMaximum(nb_max);
    ProgressBar->setValue(0);
    if(niveau_max==0)
    {
        ProgressBar->setMaximum(100);
        ProgressBar->setValue(ProgressBar->maximum());
    }
    if(color_auto)
    {
        for(int i=0;i<=niveau_max;i++)
        {
            frame=frame_loc;
            sizePen=sizePen_loc;
            lenght=lenght_loc;
            niveau=i;
            Sub_Draw();
        }
    }
    else
    {
        Sub_Draw();
    }
}

void Draw_Tree::Sub_Draw()
{

    Frame frame_loc = frame;
    double lenght_loc=lenght;
    double sizePen_loc=sizePen;

    frame_loc.Add_alpha(90);
    Frame frame_temp = frame_loc;
    niveau--;
    if(niveau>-1)
    {
        double angle=0;
        double angle_temp=0;
        for(int i=0;i<stock_prcent.Get_size();i++)
        {
            angle_temp=stock_prcent.Get_Angle_By_Index(i);
            if(angle_temp>0)
            {
                frame_temp=frame_loc;

                double l=qCos(angle_temp/2*PI/180)*sizePen_loc/2;
                double d=qSin(angle_temp/2*PI/180)*sizePen_loc/2;

                frame_temp.Add_alpha(-angle-angle_temp/2);
                frame_temp.Set_d(l);
                frame_temp.Move();

                sizePen=d*2;
                if(etat_ratio)
                    lenght=lenght_loc*prcent_lenght;
                else
                    lenght=sizePen;
                frame=frame_temp;
                frame.Set_d(lenght);

                if(niveau==0 || !color_auto)
                {
                    Draw_Line();
                    ProgressBar->setValue(ProgressBar->value()+1);
                }


                frame.Move();
                Sub_Draw();

                angle=angle+angle_temp;

            }
        }

    }
   niveau++;
}
void Draw_Tree::Draw_Line()
{
    //qDebug() << "1 sizePen="<< sizePen;
    double x1,x2,y1,y2;
    x1=frame.Get_x1();
    x2=frame.Get_x2();
    y1=frame.Get_y1();
    y2=frame.Get_y2();
    //X_max
    if(x1>X_max)
    {
        X_max=x1;
    }
    if(x2>X_max)
    {
        X_max=x2;
    }
    //X_min
    if(x1<X_min)
    {
        X_min=x1;
    }
    if(x2<X_min)
    {
        X_min=x2;
    }
    //Y_max
    if(y1>Y_max)
    {
        Y_max=y1;
    }
    if(y2>Y_max)
    {
        Y_max=y2;
    }
    //Y_min
    if(y1<Y_min)
    {
        Y_min=y1;
    }
    if(y2<Y_min)
    {
        Y_min=y2;
    }


    Frame frame_temp;
    QVector<QPointF> VectorQPointF;

    //P1
    frame_temp=frame;
    frame_temp.Add_alpha(90);
    frame_temp.Set_d(sizePen/2);
    VectorQPointF.append(QPointF(frame_temp.Get_x2(),frame_temp.Get_y2()));

    //P2
    frame_temp=frame;
    frame_temp.Move();
    frame_temp.Add_alpha(90);
    frame_temp.Set_d(sizePen/2);
    VectorQPointF.append(QPointF(frame_temp.Get_x2(),frame_temp.Get_y2()));

    //P3
    frame_temp=frame;
    frame_temp.Move();
    frame_temp.Add_alpha(-90);
    frame_temp.Set_d(sizePen/2);
    VectorQPointF.append(QPointF(frame_temp.Get_x2(),frame_temp.Get_y2()));

    //P4
    frame_temp=frame;
    frame_temp.Add_alpha(-90);
    frame_temp.Set_d(sizePen/2);
    VectorQPointF.append(QPointF(frame_temp.Get_x2(),frame_temp.Get_y2()));
    //QVector<QPointF>
    //QPolygonF()
    QPolygonF PolygonF=QPolygonF(VectorQPointF);
    //qDebug() << "2 sizePen="<< sizePen;
    QColor Color ;
    Color=color;
    if(color_auto)
    {
        Color.setRed(qrand()%255);
        Color.setGreen(qrand()%255);
        Color.setBlue(qrand()%255);
    }

    QPen Pen(Color);
    //Pen.setWidth((int)sizePen);
    Pen.setWidth(0);

    QBrush Brush(Color);

    scene->addPolygon(PolygonF,Pen,Brush);

    if(with_bout)
    {
        double X1,X2,Y1,Y2;
        X1=x2-(sizePen/2);
        Y1=y2-(sizePen/2);
        X2=x2+(sizePen/2);
        Y2=y2+(sizePen/2);
        double dX,dY;
        dX=X2-X1;
        dY=Y2-Y1;
        scene->addEllipse(X1,Y1,dX,dY,Pen,Brush);
    }
    //qDebug() << "3 sizePen="<< sizePen;
    //SVG
    //double x1,x2,y1,y2;
    x1=frame.Get_x1()-X_min+100;
    x2=frame.Get_x2()-X_min+100;
    y1=frame.Get_y1()-Y_min+100;
    y2=frame.Get_y2()-Y_min+100;

    if(IsSaveSVG)
    {
        if(file.open(QIODevice::Append  | QIODevice::Text))
        {
            QTextStream out(&file);
            out << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" stroke=\"rgb(" << Color.red() <<"," << Color.green() << "," << Color.blue() << ")\" stroke-width=\"" << (int)sizePen << "\"/>\n";
            if(with_bout)
            {
                out << "<circle cx=\"" << x2 <<"\" cy=\"" << y2 << "\" r=\"" << sizePen/2 << "\" fill=\"rgb(" << Color.red() <<"," << Color.green() << "," << Color.blue() << ")\"/> \n";
            }
            file.close();
        }
        //qDebug() << "4 sizePen="<< sizePen;
    }

}
