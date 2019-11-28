#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{
num=0;
}

void notification::notification_ajout_client(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/elyes/Desktop/Loux/2éme année/Dossier C++/elyescrud_versionfinale/background-smh-avion.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","DOMBE_Air_Line : un client a été ajouter!",QSystemTrayIcon::Information,15000);
//num++;
}

void notification::notification_supprimer_client(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/elyes/Desktop/Loux/2éme année/Dossier C++/elyescrud_versionfinale/background-smh-avion.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","DOMBE_Air_Line : un client a été supprimer!",QSystemTrayIcon::Information,15000);
//num++;
}


void notification::notification_Ouverture(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/elyes/Desktop/Loux/2éme année/Dossier C++/elyescrud_versionfinale/background-smh-avion.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("Gestion d'agence de voyage","Nouvelle instance ouverte",QSystemTrayIcon::Information,15000);
//num++;
}
void notification::notification_modifier_client(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/elyes/Desktop/Loux/2éme année/Dossier C++/elyescrud_versionfinale/background-smh-avion.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","DOMBE_Air_Line : un client a été modifier!",QSystemTrayIcon::Information,15000);
//num++;
}

void notification::notification_ajout_promo(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/elyes/Desktop/Loux/2éme année/Dossier C++/elyescrud_versionfinale/background-smh-avion.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","DOMBE_Air_Line : une promotion a été ajouter!",QSystemTrayIcon::Information,15000);
//num++;
}

void notification::notification_supprimer_promo(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/elyes/Desktop/Loux/2éme année/Dossier C++/elyescrud_versionfinale/background-smh-avion.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","DOMBE_Air_Line : une promotion a été supprimer!",QSystemTrayIcon::Information,15000);
//num++;
}
void notification::notification_modifier_promo(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/elyes/Desktop/Loux/2éme année/Dossier C++/elyescrud_versionfinale/background-smh-avion.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","DOMBE_Air_Line : une promotion a été modifier!",QSystemTrayIcon::Information,15000);
//num++;
}



