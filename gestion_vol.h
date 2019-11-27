#ifndef GESTION_VOL_H
#define GESTION_VOL_H
#include"gerer_vols.h"
#include "destination.h"
#include <QDialog>

namespace Ui {
class gestion_vol;
}

class gestion_vol : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_vol(QWidget *parent = nullptr);
    ~gestion_vol();

private slots:


    void on_AJOUTER_VOLS_clicked();

    void on_comboBox_ID_DEST_activated(const QString &arg1);

    void on_AJOUTER_DESTINATION_clicked();

    void on_supprimer_dest_clicked();


    void on_supprimervols_clicked();

    void on_comboBox_status_activated(const QString &arg1);


    void on_comboBox_ID_DEST_mod_activated(const QString &arg1);



    void on_comboBox_ID_DEST_mod_vol_activated(const QString &arg1);

    void on_comboBox_status_mod_activated(const QString &arg1);


    void on_comboBox_N_VOL_mod_activated(const QString &arg1);

    void on_mod_dest_clicked();

    void on_mod_vol_clicked();

private:
    Ui::gestion_vol *ui;
    gerer_vols tmpvols;
    destination tmpdest;
};

#endif // GESTION_VOL_H
