#include "gestion.h"
#include "ui_gestion.h"
#include "smtp.h"
#include "QMessageBox"
#include"statistiques.h"
#include "qcustomplot.h"
#include <QString>
#include "notification.h"
gestion::gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion)
{
    ui->setupUi(this);
    setWindowModality(Qt::WindowModal);
    ui->tab_avions->setModel(tmpavions.afficher_avions());
    ui->tab_constructeur->setModel(tmpconstructeur.afficher_constructeur());
    ui->id_constructeur->setModel(tmpconstructeur.afficher_constructeurlist());
    ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());
    ui->comboBox_id_mod->setModel(tmpavions.afficher_avionslist());
    ui->comboBox_id_const_mod->setModel(tmpconstructeur.afficher_constructeurlist());

    ui->comboBox_id_supp->setModel(tmpavions.getIdModel());
    ui->comboBox_id_supp_const->setModel(tmpconstructeur.getIdModel());

    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
}

gestion::~gestion()
{
    delete ui;
}

void gestion::initialiser()
{
    ui->lineEdit_idavion->clear();
    //ui->lineEdit_etat->clear();

    ui->lineEdit_idconstructeur->clear();
    ui->lineEdit_nomconstructeur->clear();
    ui->lineEdit_mailcostructeur->clear();
}

void gestion::initialiser_modifier()
{
    ui->lineEdit_etat_3->clear();
    ui->lineEdit_nom_const_mod->clear();
    ui->lineEdit_mail_const_mod->clear();
}

void gestion::initialiser_supp()
{
    ui->comboBox_id_supp->clear();
    ui->comboBox_id_supp_const->clear();
}

void gestion::refresh()
{
    ui->tab_avions->setModel(tmpavions.afficher_avions());
    ui->tab_constructeur->setModel(tmpconstructeur.afficher_constructeur());
    ui->id_constructeur->setModel(tmpavions.afficher_avions());
    ui->id_constructeur_3->setModel(tmpavions.afficher_avions());
    ui->comboBox_id_mod->setModel(tmpavions.afficher_avions());
    ui->comboBox_id_const_mod->setModel(tmpconstructeur.afficher_constructeurlist());
}


void gestion::on_ajouter_constructeur_clicked()
{
    QString id = ui->lineEdit_idconstructeur->text();
    QString nom= ui->lineEdit_nomconstructeur->text();
    QString mail= ui->lineEdit_mailcostructeur->text();
  constructeur e(id,nom,mail);

  bool test=e.ajouter_constructeur();
  if(test)
{QString okd="";
      notification ok;
      ok.notification_ajout_constructeur(okd);
      ui->tab_constructeur->setModel(tmpconstructeur.afficher_constructeur());
      refresh();
      initialiser();

      //refresh
      ui->id_constructeur->setModel(tmpconstructeur.afficher_constructeurlist());
      ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());
      ui->comboBox_id_const_mod->setModel(tmpconstructeur.afficher_constructeurlist());

      QMessageBox::information(nullptr, QObject::tr("Ajouter un constructeur"),
                  QObject::tr("constructeur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un constructeur"),
                  QObject::tr("constructeur existe deja  !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void gestion::on_supprimer_constructeur_clicked()
{

    QString id = ui->comboBox_id_supp_const->currentText();
    bool test=tmpconstructeur.supprimer_constructeur(id);
    if(test)
    {ui->tab_constructeur->setModel(tmpconstructeur.afficher_constructeur());
        refresh();
        initialiser_supp();
        //refresh
        ui->id_constructeur->setModel(tmpconstructeur.afficher_constructeurlist());
        ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());
        ui->comboBox_id_const_mod->setModel(tmpconstructeur.afficher_constructeurlist());
        ui->comboBox_id_supp_const->setModel(tmpconstructeur.getIdModel());


        QMessageBox::information(nullptr, QObject::tr("Supprimer constructeur"),
                    QObject::tr("constructeur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer constructeur"),
                    QObject::tr("verifier l'id  !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void gestion::on_suppavions_clicked()
{
    QString id = ui->comboBox_id_supp->currentText();
    bool test=tmpavions.supprimer_avions(id);
    if(test)
    {
        ui->tab_avions->setModel(tmpavions.afficher_avions());
        ui->id_constructeur->setModel(tmpconstructeur.afficher_constructeurlist());
        ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());
        ui->comboBox_id_mod->setModel(tmpavions.afficher_avionslist());
        ui->comboBox_id_supp->setModel(tmpavions.getIdModel());
        refresh();

 initialiser_supp();
        //refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer avions"),
                    QObject::tr("avion supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer avions"),
                    QObject::tr("verifier l'id  !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion::on_ajouter_av_clicked()
{
    QString okd="";
          notification ok;
          ok.notification_ajout_avion(okd);
    QString id = ui->lineEdit_idavion->text();
    QString etat1= etat;
    avions a(id,etat1,tmpavions.get_ID_CONSTRUCTEUR());

    bool test=a.ajouter_avions();
    if(test)
    {
      ui->tab_avions->setModel(tmpavions.afficher_avions());//refresh
      refresh();
      initialiser();
      ui->comboBox_id_mod->setModel(tmpavions.afficher_avionslist());
      ui->id_constructeur->setModel(tmpconstructeur.afficher_constructeurlist());
      ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());

      ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());
      ui->comboBox_id_mod->setModel(tmpavions.afficher_avionslist());

      QMessageBox::information(nullptr, QObject::tr("Ajouter un avions"),
                  QObject::tr("avion ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un avions"),
                  QObject::tr("avion existe deja  !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void gestion::on_id_constructeur_activated(const QString &arg1)
{
    tmpavions.set_ID_CONSTRUCTEUR(arg1);

}

void gestion::on_id_constructeur_3_activated(const QString &arg1)
{
    tmpavions.set_ID_CONSTRUCTEUR(arg1);
}

void gestion::on_modifier_av_clicked()
{
    tmpavions.set_etat(ui->lineEdit_etat_3->text());
    bool test=tmpavions.modifier();
if(test)
{
   ui->tab_avions->setModel(tmpavions.afficher_avions());//refresh

   ui->comboBox_id_mod->setModel(tmpavions.afficher_avionslist());
   ui->id_constructeur->setModel(tmpconstructeur.afficher_constructeurlist());
   ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());

   ui->comboBox_id_mod->setModel(tmpavions.afficher_avionslist());
   ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());
   refresh();
   initialiser();
   initialiser_modifier();

    QMessageBox::information(nullptr, QObject::tr("modifer un avions"),
                QObject::tr("avion modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("modifier un avions"),
                QObject::tr("avion non valide  !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void gestion::on_modifier_constructeur_clicked()
{
    tmpconstructeur.set_nom(ui->lineEdit_nom_const_mod->text());
    tmpconstructeur.set_mail(ui->lineEdit_mail_const_mod->text());
bool test=tmpconstructeur.modifier_constructeur();
if(test)
{
    ui->tab_constructeur->setModel(tmpconstructeur.afficher_constructeur());
    refresh();
    initialiser_modifier();
    //refresh
    ui->id_constructeur->setModel(tmpconstructeur.afficher_constructeurlist());
    ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());
    ui->comboBox_id_const_mod->setModel(tmpconstructeur.afficher_constructeurlist());

    ui->id_constructeur_3->setModel(tmpconstructeur.afficher_constructeurlist());

    QMessageBox::information(nullptr, QObject::tr("modifer un constructeur"),
                QObject::tr("constructeur modifié.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("modifier un constructeur"),
                QObject::tr("constructeur non valide  !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}


void gestion::on_chercher_constructeur_textChanged(const QString &arg1)
{
    if(k==0)
        ui->tab_constructeur2->setModel(tmpconstructeur.chercher_constructeur_id(arg1));
    if(k==1)
        ui->tab_constructeur2->setModel(tmpconstructeur.chercher_constructeur_nom(arg1));
    if(k==2)
        ui->tab_constructeur2->setModel(tmpconstructeur.chercher_constructeur_mail(arg1));
}


void gestion::on_chercher_avion_textChanged(const QString &arg1)
{
     if(k==0)
     ui->tab_avions2->setModel(tmpavions.chercher_avions_id(arg1));
     if(k==1)
     ui->tab_avions2->setModel(tmpavions.chercher_avions_etat(arg1));
     if(k==2)
     ui->tab_avions2->setModel(tmpavions.chercher_avions_ID_CONSTRUCTEUR(arg1));
}


void gestion::on_trier_selon_id_clicked()
{
     ui->tab_avions->setModel(tmpavions.afficher_tri_id());
}
void gestion::on_trier_selon_id_desc_clicked()
{
    ui->tab_avions->setModel(tmpavions.afficher_tri_id_desc());
}


void gestion::on_trier_selon_etat_clicked()
{
     ui->tab_avions->setModel(tmpavions.afficher_tri_etat());
}
void gestion::on_trier_selon_etat_desc_clicked()
{
    ui->tab_avions->setModel(tmpavions.afficher_tri_etat_desc());
}


void gestion::on_trier_selon_id_constructeur_clicked()
{
    ui->tab_avions->setModel(tmpavions.afficher_tri_ID_CONSTRUCTEUR());
}
void gestion::on_trier_selon_id_constructeur_desc_clicked()
{
    ui->tab_avions->setModel(tmpavions.afficher_tri_ID_CONSTRUCTEUR_desc());
}



void gestion::on_comboBox_id_mod_activated(const QString &arg1)
{
    tmpavions.set_id(arg1);
}

void gestion::on_comboBox_id_const_mod_activated(const QString &arg1)
{
    tmpconstructeur.set_id(arg1);
}

void gestion::on_pushButton_tri_id_const_clicked()
{
    ui->tab_constructeur->setModel(tmpconstructeur.afficher_tri_id());
}
void gestion::on_pushButton_tri_id_const_desc_clicked()
{
     ui->tab_constructeur->setModel(tmpconstructeur.afficher_tri_id_desc());
}


void gestion::on_pushButton_tri_nom_const_clicked()
{
     ui->tab_constructeur->setModel(tmpconstructeur.afficher_tri_nom());
}
void gestion::on_pushButton_tri_nom_const_desc_clicked()
{
     ui->tab_constructeur->setModel(tmpconstructeur.afficher_tri_nom_desc());
}


void gestion::on_pushButton_tri_mail_const_clicked()
{
     ui->tab_constructeur->setModel(tmpconstructeur.afficher_tri_mail());
}
void gestion::on_pushButton_tri_mail_const_desc_clicked()
{
     ui->tab_constructeur->setModel(tmpconstructeur.afficher_tri_mail_desc());
}


void gestion::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void gestion::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void gestion::on_consulter_stat_clicked()
{
statistiques *s = new statistiques();
setWindowModality(Qt::WindowModal);
s->show();
}

void gestion::on_enpanne_clicked(bool checked)
{
    if(checked)
        etat="en panne";
}

void gestion::on_fonctionnel_clicked(bool checked)
{
    if(checked)
        etat="fonctionnel";
}


void gestion::on_comboBox_id_mod_currentTextChanged(const QString &arg1)
{
    QString id = arg1;
    QSqlQuery query;
    QString ide;
    query.exec("select * from avion where id_avion ='"+id+"'");
    while(query.next())
    {
    ui->lineEdit_etat_3->setText(query.value(1).toString());
    ui->id_constructeur_3->setCurrentText(query.value(2).toString());
    }
}

void gestion::on_comboBox_id_const_mod_currentTextChanged(const QString &arg1)
{
    QString id = arg1;
    QSqlQuery query;
    QString ide;
    query.exec("select * from constructeur where id_constructeur ='"+id+"'");
    while(query.next())
    {
    ui->lineEdit_nom_const_mod->setText(query.value(1).toString());
    ui->lineEdit_mail_const_mod->setText(query.value(2).toString());
    }
}


void gestion::on_checkBox_toggled(bool checked)
{
    k=0;
    ui->checkBox_2->setCheckState(Qt::CheckState(0));
    ui->checkBox_3->setCheckState(Qt::CheckState(0));
}

void gestion::on_checkBox_2_toggled(bool checked)
{
    k=1;
    ui->checkBox->setCheckState(Qt::CheckState(0));
    ui->checkBox_3->setCheckState(Qt::CheckState(0));
}

void gestion::on_checkBox_3_toggled(bool checked)
{
    k=2;
    ui->checkBox->setCheckState(Qt::CheckState(0));
    ui->checkBox_2->setCheckState(Qt::CheckState(0));
}


void gestion::on_checkBox_id_avion_toggled(bool checked)
{
    k=0;
    ui->checkBox_etat_avion->setCheckState(Qt::CheckState(0));
    ui->checkBox_id_const_avion->setCheckState(Qt::CheckState(0));
}

void gestion::on_checkBox_etat_avion_toggled(bool checked)
{
    k=1;
    ui->checkBox_id_avion->setCheckState(Qt::CheckState(0));
    ui->checkBox_id_const_avion->setCheckState(Qt::CheckState(0));
}

void gestion::on_checkBox_id_const_avion_toggled(bool checked)
{
    k=2;
    ui->checkBox_id_avion->setCheckState(Qt::CheckState(0));
    ui->checkBox_etat_avion->setCheckState(Qt::CheckState(0));
}




