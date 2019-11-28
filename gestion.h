
#ifndef GESTION_H
#define GESTION_H

#include <QDialog>
#include "avions.h"
#include "constructeur.h"
#include "smtp.h"
#include "qcustomplot.h"


namespace Ui {
class gestion;
}

class gestion : public QDialog
{
    Q_OBJECT

public:
    explicit gestion(QWidget *parent = nullptr);
    ~gestion();
    void initialiser();
    void initialiser_modifier();

    void initialiser_supp();
    QSqlQueryModel * tri();
    void refresh();


private slots:
    void on_ajouter_constructeur_clicked();

    void on_supprimer_constructeur_clicked();

    void on_suppavions_clicked();

    void on_ajouter_av_clicked();

    void on_id_constructeur_activated(const QString &arg1);

    void on_id_constructeur_3_activated(const QString &arg1);

    void on_modifier_av_clicked();

    void on_modifier_constructeur_clicked();

    void on_chercher_constructeur_textChanged(const QString &arg1);

    void on_chercher_avion_textChanged(const QString &arg1);


    void on_trier_selon_id_clicked();
    void on_trier_selon_id_desc_clicked();

    void on_trier_selon_etat_clicked();
    void on_trier_selon_etat_desc_clicked();

    void on_trier_selon_id_constructeur_clicked();
    void on_trier_selon_id_constructeur_desc_clicked();


    void on_comboBox_id_mod_activated(const QString &arg1);

    void on_comboBox_id_const_mod_activated(const QString &arg1);

    void on_pushButton_tri_id_const_clicked();
    void on_pushButton_tri_id_const_desc_clicked();

    void on_pushButton_tri_nom_const_clicked();
    void on_pushButton_tri_nom_const_desc_clicked();

    void on_pushButton_tri_mail_const_clicked();
    void on_pushButton_tri_mail_const_desc_clicked();


    void sendMail();
    void mailSent(QString);

     void on_consulter_stat_clicked();

     void on_enpanne_clicked(bool checked);

     void on_fonctionnel_clicked(bool checked);

     void on_comboBox_id_mod_currentTextChanged(const QString &arg1);

     void on_comboBox_id_const_mod_currentTextChanged(const QString &arg1);

     void on_comboBox_supp_const_activated(const QString &arg1);

     void on_comboBox_id_supp_activated(const QString &arg1);

     void on_comboBox_id_supp_const_activated(const QString &arg1);

     void on_comboBox_id_supp_currentTextChanged(const QString &arg1);

     void on_checkBox_toggled(bool checked);
     void on_checkBox_2_toggled(bool checked);
     void on_checkBox_3_toggled(bool checked);


     void on_checkBox_id_avion_toggled(bool checked);
     void on_checkBox_etat_avion_toggled(bool checked);
     void on_checkBox_id_const_avion_toggled(bool checked);

     void on_sendBtn_clicked();

private:
    Ui::gestion *ui;
    avions tmpavions;
    constructeur tmpconstructeur;
    QString etat;
    int k=0;

};

#endif // GESTION_H
