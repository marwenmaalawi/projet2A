
#include "gestionproduit.h"
#include "ui_gestionproduit.h"
#include "prodect.h"
#include "QMessageBox"
#include "fournisseur.h"
#include"smtp.h"
#include "statistique.h"
gestionproduit::gestionproduit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionproduit)
{
    ui->setupUi(this);
    ui->tab_produit->setModel(tmpproduit.afficher_produit());
    ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
     ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());
 ui->comboBox_modidfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
 ui->comboBox_modidproduit->setModel(tmpproduit.afficher_listprodect());
 ui->comboBoxmodidproduitfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());



 connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
       connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
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
    prodect p(id_produit,type,date_fabrication,date_expiration,tmpproduit.get_id());
    bool teste;
           teste =p.ajouter_produit();
    if (teste)
   {   ui->tab_produit->setModel(tmpproduit.afficher_produit());
        ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
         ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidproduit->setModel(tmpproduit.afficher_listprodect());
     ui->comboBoxmodidproduitfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
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
    {  ui->tab_produit->setModel(tmpproduit.afficher_produit());
        ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
         ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidproduit->setModel(tmpproduit.afficher_listprodect());
     ui->comboBoxmodidproduitfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
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
   {   ui->tab_produit->setModel(tmpproduit.afficher_produit());
        ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
         ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidproduit->setModel(tmpproduit.afficher_listprodect());
     ui->comboBoxmodidproduitfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
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
    {  ui->tab_produit->setModel(tmpproduit.afficher_produit());
        ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
         ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidproduit->setModel(tmpproduit.afficher_listprodect());
     ui->comboBoxmodidproduitfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
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
    tmpproduit.set_id(arg1);
}

void gestionproduit::on_comboBox_modidfournisseur_activated(const QString &arg1)
{
    tmpfournisseur.set_id(arg1) ;
}

void gestionproduit::on_modifierfournisseur_clicked()
{
    QString nom=ui->lineEdit_modnomfournisseur->text();
    QString mail=ui->lineEdit_modmailfournisseur->text();

    fournisseur f(tmpfournisseur.get_id(),nom,mail);
    bool teste;
           teste=f.modifier_fournisseur();
    if (teste)
   {  ui->tab_produit->setModel(tmpproduit.afficher_produit());
        ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
         ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
     ui->comboBox_modidproduit->setModel(tmpproduit.afficher_listprodect());
     ui->comboBoxmodidproduitfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
     QMessageBox::information(nullptr,QObject::tr("modifier fournisseur"),
       QObject::tr("fournisseur modifier") ,QMessageBox::Cancel);

    }else
{
        QMessageBox::critical(nullptr,QObject::tr("modifier fournisseur"),
          QObject::tr("merci de remplir tout les champs correctement") ,QMessageBox::Cancel) ;
}


}


void gestionproduit::on_comboBox_modidproduit_activated(const QString &arg1)
{
   tmpproduit.set_id(arg1);
}

void gestionproduit::on_comboBoxmodidproduitfournisseur_activated(const QString &arg1)
{
    tmpproduit.set_ID_FOURNISSEUR(arg1);
}

void gestionproduit::on_modifierproduit_clicked()
{     QString type=ui->lineEdit_modtypeproduit->text();
      QString date_fabrication=ui->lineEdit_modDFproduit->text();
      QString date_expiration=ui->lineEdit_modDEXproduit->text();
       prodect p(tmpproduit.get_id(),type,date_fabrication,date_expiration,tmpproduit.get_ID_FOURNISSEUR());
       bool teste;
              teste=p.modifier_produit();
       if (teste)
      {  ui->tab_produit->setModel(tmpproduit.afficher_produit());
           ui->tab_fournisseur->setModel(tmpfournisseur.afficher_fournisseur());
            ui->comboBox->setModel(tmpfournisseur.afficher_listfournisseur());
        ui->comboBox_modidfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
        ui->comboBox_modidproduit->setModel(tmpproduit.afficher_listprodect());
        ui->comboBoxmodidproduitfournisseur->setModel(tmpfournisseur.afficher_listfournisseur());
        QMessageBox::information(nullptr,QObject::tr("modifier produit"),
          QObject::tr("produit modifier") ,QMessageBox::Cancel);

       }else
   {
           QMessageBox::critical(nullptr,QObject::tr("modifier produit"),
             QObject::tr("merci de remplir tout les champs correctement") ,QMessageBox::Cancel) ;
   }


}

void gestionproduit::on_pushButton_clicked()
{
    QString id=ui->lineEdit->text();
ui->tableView->setModel(tmpfournisseur.rechercher(id));
}
void gestionproduit::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void gestionproduit::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void gestionproduit::on_consulter_stat_clicked()
{


        ui->tablestat->setModel(tmpfournisseur.stats());
        statistique*a=new statistique();
        a->show();

}
