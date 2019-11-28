#include "mainwindow.h"

#include <QApplication>
#include "connexion.h"
#include <QMessageBox>
#include <QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Connexion de l'Admin");
    connexion c;
    try {
        c.ouvrirConnexion();
        w.show();

    } catch (QString s) {
        qDebug()<<s;

    }
    w.show();
    return a.exec();
}
