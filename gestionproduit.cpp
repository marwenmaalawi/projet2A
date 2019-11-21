
#include "gestionproduit.h"
#include "ui_gestionproduit.h"
#include "prodect.h"
#include "QMessageBox"
#include "fournisseur.h"
gestionproduit::gestionproduit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionproduit)
{
    ui->setupUi(this);
    ui->tab_produit->setModel(tmpproduit.afficher_produit());
    ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
     ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());

}

gestionproduit::~gestionproduit()
{
    delete ui;
}



void gestionproduit::on_Ajouter_produit_clicked()
{
    QString id_produit=ui->lineEdit_idproduit->text();
    QString type=ui->lineEdit_typeproduit->text();
    QString date_fabrication=ui->lineEdit_DFproduit->text();
    QString date_expiration=ui->lineEdit_DEXproduit->text();
    prodect p(id_produit,type,date_fabrication,date_expiration,tmpfournisseur.get_id());
    bool teste;
           teste =p.ajouter_produit();
    if (teste)
   { ui->tab_produit->setModel(tmpproduit.afficher_produit());
     ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());  //refresh
     QMessageBox::information(nullptr,QObject::tr("ajouter produit"),
       QObject::tr("produit ajoute") ,QMessageBox::Cancel);

    }else
{
        QMessageBox::critical(nullptr,QObject::tr("ajouter produit"),
          QObject::tr("produit existe deja ") ,QMessageBox::Cancel) ;
}
}


void gestionproduit::on_supprimer_produit_clicked()
{
    QString id=ui->lineEdit_suppproduit->text();
    bool test=tmpproduit.supprimer_produit(id);
    if(test)
    {ui->tab_produit->setModel(tmpproduit.afficher_produit());//refresh
     ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("produit  supprime.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("verfier l'id !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


void gestionproduit::on_ajouter_fournisseur_clicked()
{QString id=ui->lineEdit_idfournisseur->text();
    QString nom=ui->lineEdit_nomfournisseur->text();
    QString mail=ui->lineEdit_mail->text();

    fournisseur f(id,nom,mail);
    bool teste;
           teste=f.ajouter_fournisseur();
    if (teste)
   { ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
        ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());//refresh
     QMessageBox::information(nullptr,QObject::tr("ajouter fournisseur"),
       QObject::tr("fournisseur ajoute") ,QMessageBox::Cancel);

    }else
{
        QMessageBox::critical(nullptr,QObject::tr("ajouter fournisseur"),
          QObject::tr("fournisseur existe deja ") ,QMessageBox::Cancel) ;
}

}

void gestionproduit::on_supprimer_fournisseur_clicked()
{  QString id=ui->lineEdit_suppfournisseur->text();
    bool test=tmpfournisseur.supprimer_fournisseur(id);
    if(test)
    {ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
        ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer fournisseur"),
                    QObject::tr("fournisseur  supprime.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer fournisseur"),
                    QObject::tr("verfier l'id !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestionproduit::on_comboBox_activated(const QString &arg1)
{
    tmpfournisseur.set_id(arg1);
}
