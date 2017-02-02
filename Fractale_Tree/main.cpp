#include "main_fenetre.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Main_fenetre w;
    w.show();

    return a.exec();
}
