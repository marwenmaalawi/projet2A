#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{
num=0;
}

void notification::notification_ajout_constructeur(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/CNTE/Desktop/photos/ena.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Un nouveau constructeur a été ajouté !",QSystemTrayIcon::Information,15000);
//num++;
}

void notification::notification_ajout_avion(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/CNTE/Desktop/photos/ena.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Un nouveau avion a été ajoutée !",QSystemTrayIcon::Information,15000);
//num++;
}


void notification::notification_Ouverture(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/CNTE/Desktop/photos/ena.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("Gestion d'Airlines ","Nouvelle instance ouverte",QSystemTrayIcon::Information,15000);
//num++;
}
