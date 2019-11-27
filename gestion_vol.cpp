#include "gestion_vol.h"
#include "ui_gestion_vol.h"
#include <QString>
#include "QMessageBox"
#include "QSqlQuery"
gestion_vol::gestion_vol(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_vol)
{
    ui->setupUi(this);
    ui->tab_vols->setModel(tmpvols.afficher_vol());
    ui->comboBox_ID_DEST->setModel(tmpdest.afficher_destlist());
    ui->tab_dest->setModel(tmpdest.afficher_dest());
    ui->comboBox_ID_DEST_mod->setModel(tmpdest.afficher_destlist());
     ui->comboBox_N_VOL_mod->setModel(tmpvols.afficher_vollist());
     ui->comboBox_ID_DEST_mod_vol->setModel(tmpdest.afficher_destlist());

}

gestion_vol::~gestion_vol()
{
    delete ui;
}



void gestion_vol::on_AJOUTER_VOLS_clicked()
{
    int N_VOL = ui->lineEdit_N_vol->text().toInt();
    QString HEURE = ui->lineEdit_heure->text();
    QString ORIGINE = ui->lineEdit_origine->text();

  gerer_vols e(N_VOL ,HEURE,ORIGINE,tmpvols.get_STATUT(),tmpvols.get_ID_DEST());
  bool test=e.ajouter_vol();
  if(test)
{
      ui->tab_vols->setModel(tmpvols.afficher_vol());
      ui->comboBox_ID_DEST->setModel(tmpdest.afficher_destlist());
        ui->comboBox_ID_DEST_mod->setModel(tmpdest.afficher_destlist());
        ui->comboBox_N_VOL_mod->setModel(tmpvols.afficher_vollist());
        ui->comboBox_ID_DEST_mod_vol->setModel(tmpdest.afficher_destlist());

      ui->tab_dest->setModel(tmpdest.afficher_dest());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un vol"),
                  QObject::tr("vol ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un vol"),
                  QObject::tr("vol existe deja  !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestion_vol::on_comboBox_ID_DEST_activated(const QString &arg1)
{
    tmpvols.set_ID_DEST(arg1);
}

void gestion_vol::on_AJOUTER_DESTINATION_clicked()
{
    int duree = ui->lineEdit_DURREE->text().toInt();
    QString ville = ui->lineEdit_VILLE->text();
    QString id = ui->lineEdit_ID_DEST->text();
  destination v(id,ville,duree);
  bool test=v.ajouter_dest();
  if(test)
{
      ui->tab_vols->setModel(tmpvols.afficher_vol());
      ui->comboBox_ID_DEST->setModel(tmpdest.afficher_destlist());
        ui->comboBox_ID_DEST_mod->setModel(tmpdest.afficher_destlist());
        ui->comboBox_N_VOL_mod->setModel(tmpvols.afficher_vollist());
        ui->comboBox_ID_DEST_mod_vol->setModel(tmpdest.afficher_destlist());

      ui->tab_dest->setModel(tmpdest.afficher_dest());  //refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter destination"),
                  QObject::tr("dest ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter destination"),
                  QObject::tr("destination deja ajouter !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



}

void gestion_vol::on_supprimer_dest_clicked()
{
    QString id = ui->lineEdit_suppdest->text();
    bool test=tmpdest.supprimer_destination(id);
    if(test)
    {
        ui->tab_vols->setModel(tmpvols.afficher_vol());
        ui->comboBox_ID_DEST->setModel(tmpdest.afficher_destlist());
          ui->comboBox_ID_DEST_mod->setModel(tmpdest.afficher_destlist());
          ui->comboBox_N_VOL_mod->setModel(tmpvols.afficher_vollist());
          ui->comboBox_ID_DEST_mod_vol->setModel(tmpdest.afficher_destlist());

        ui->tab_dest->setModel(tmpdest.afficher_dest());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer destination"),
                    QObject::tr("destination supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer destination"),
                    QObject::tr("verfier l id !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}


void gestion_vol::on_supprimervols_clicked()
{int id = ui->lineEdit_suppvols->text().toInt();
    bool test=tmpvols.supprimer_vol(id);
    if(test)
    {
        ui->tab_vols->setModel(tmpvols.afficher_vol());
        ui->comboBox_ID_DEST->setModel(tmpdest.afficher_destlist());
          ui->comboBox_ID_DEST_mod->setModel(tmpdest.afficher_destlist());
        ui->tab_dest->setModel(tmpdest.afficher_dest());
         //refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer vol"),
                    QObject::tr("vol supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer vol"),
                    QObject::tr("verfier le numero du vol  !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void gestion_vol::on_comboBox_status_activated(const QString &arg1)
{
    tmpvols.set_STATUT(arg1);
}



void gestion_vol::on_comboBox_ID_DEST_mod_activated(const QString &arg1)
{
    tmpdest.set_id(arg1);
    tmpdest.chercher_dest();
    ui->lineEdit_VILLE_mod->setText(tmpdest.get_ville());
    ui->lineEdit_DURREE_mod->setText(QString::number(tmpdest.get_duree()));

}




void gestion_vol::on_comboBox_ID_DEST_mod_vol_activated(const QString &arg1)
{
    tmpvols.set_ID_DEST(arg1);
}

void gestion_vol::on_comboBox_status_mod_activated(const QString &arg1)
{
    tmpvols.set_STATUT(arg1);
}



void gestion_vol::on_comboBox_N_VOL_mod_activated(const QString &arg1)
{ int a=arg1.toInt();
    tmpvols.set_N_VOL(a);
    tmpvols.chercher_vol();
    ui->lineEdit_heure_mod->setText(tmpvols.get_HEURE());
    ui->lineEdit_origine_mod->setText(tmpvols.get_ORIGINE());
    ui->lineEdit_statut_mod->setText(tmpvols.get_STATUT());
     ui->lineEdit_ID_DEST_mod->setText(tmpvols.get_ID_DEST());

}

void gestion_vol::on_mod_dest_clicked()
{

        QString ville =ui->lineEdit_VILLE_mod->text();
       int duree =ui->lineEdit_DURREE_mod->text().toInt();
        destination  d(tmpdest.get_id(),ville,duree);
       if((tmpdest.get_id()=="")||(ville=="")||(duree==0))

    {QMessageBox::information(nullptr,QObject::tr("verifier champs"),
                              QObject::tr("merci de remplir tous les champs \n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

       }
        else{       bool test=d.modifier_destination();
       if (test==true)
       {
           ui->tab_vols->setModel(tmpvols.afficher_vol());
           ui->comboBox_ID_DEST->setModel(tmpdest.afficher_destlist());
           ui->tab_dest->setModel(tmpdest.afficher_dest());
           ui->comboBox_ID_DEST_mod->setModel(tmpdest.afficher_destlist());
            ui->comboBox_N_VOL_mod->setModel(tmpvols.afficher_vollist());
            ui->comboBox_ID_DEST_mod_vol->setModel(tmpdest.afficher_destlist());



        QMessageBox::information(nullptr,QObject::tr("modifier destination"),
          QObject::tr("destination modifier.\n"
                       "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else{
       QMessageBox::critical(nullptr, QObject::tr("modifier destination"),
           QObject::tr("ERREUR !.\n"
                       "Click Cancel to exit."), QMessageBox::Cancel);

       }
       }
    }


void gestion_vol::on_mod_vol_clicked()
{
    QString heure =ui->lineEdit_heure_mod->text();
   QString origine =ui->lineEdit_origine_mod->text();
    gerer_vols  v(tmpvols.get_N_VOL(),heure,origine,tmpvols.get_STATUT(),tmpvols.get_ID_DEST());



          bool test=v.modifier_vols();
   if (test==true)
   {
       ui->tab_vols->setModel(tmpvols.afficher_vol());
       ui->comboBox_ID_DEST->setModel(tmpdest.afficher_destlist());
       ui->tab_dest->setModel(tmpdest.afficher_dest());
       ui->comboBox_ID_DEST_mod->setModel(tmpdest.afficher_destlist());
        ui->comboBox_N_VOL_mod->setModel(tmpvols.afficher_vollist());
        ui->comboBox_ID_DEST_mod_vol->setModel(tmpdest.afficher_destlist());



    QMessageBox::information(nullptr,QObject::tr("modifier vols"),
      QObject::tr("vol modifier.\n"
                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else{
   QMessageBox::critical(nullptr, QObject::tr("modifier vols"),
       QObject::tr("ERREUR !.\n"
                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
}



