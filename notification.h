#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <QSystemTrayIcon>
#include<QString>
class notification
{
private:
    int num;
public:
    notification();
    void notification_Ouverture(QString id);

    void notification_ajout_client(QString id);
    void notification_supprimer_client(QString id);
    void notification_modifier_client(QString id);

    void notification_ajout_promo(QString id);
    void notification_modifier_promo(QString id);
    void notification_supprimer_promo(QString id);

};

#endif // NOTIFICATION_H
