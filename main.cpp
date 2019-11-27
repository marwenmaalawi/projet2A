#include "menu_principal.h"

#include <QApplication>
#include "connection.h"
#include <QMessageBox>
#include <QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu_principal w;
    Connection c;
    try {
        c.createconnect();
        w.show();
    } catch (QString s) {
        qDebug()<<s;

    }
    w.show();
    return a.exec();
}

