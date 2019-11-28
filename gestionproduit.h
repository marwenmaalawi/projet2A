#ifndef GESTIONPRODUIT_H
#define GESTIONPRODUIT_H

#include <QDialog>
#include <prodect.h>
#include <QSqlQueryModel>
#include <QAbstractItemView>
#include "fournisseur.h"
namespace Ui {
class gestionproduit;
}

class gestionproduit : public QDialog
{
    Q_OBJECT

public:
    explicit gestionproduit(QWidget *parent = nullptr);
    ~gestionproduit();

private slots:


    void on_Ajouter_produit_clicked();

    void on_supprimer_produit_clicked();

    void on_ajouter_fournisseur_clicked();

    void on_supprimer_fournisseur_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_modidfournisseur_activated(const QString &arg1);

    void on_modifierfournisseur_clicked();


    void on_comboBox_modidproduit_activated(const QString &arg1);

    void on_comboBoxmodidproduitfournisseur_activated(const QString &arg1);

    void on_modifierproduit_clicked();

    void on_pushButton_clicked();
    void sendMail();
       void mailSent(QString);

       void on_consulter_stat_clicked();

private:
    Ui::gestionproduit *ui;
    prodect tmpproduit ;
    fournisseur tmpfournisseur;
};  

#endif // GESTIONPRODUIT_H
