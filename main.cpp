  #include "mainwindow.h"

#include <QApplication>
#include "connexion.h"
#include <QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connexion c ;
    try { c.ouvrirConnexion() ;
      w.show();}catch (QString s)
    {qDebug()<<s;}
    w.show();
    return a.exec();
}
