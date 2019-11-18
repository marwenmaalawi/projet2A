#include "QMessageBox"
#include "gestion.h"
#include "employe.h"
#include "ui_gestion.h"
#include <QDebug>

gestion::gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion)
{
    ui->setupUi(this);

    ui->tab_employe->setModel(tmpemploye.afficher_employe());
 ui->comboBox_ajoutID->setModel(tmpemploye.afficher_list());
 ui->tab_shift->setModel(tmpsh.afficher_shift());
 ui->comboBox_employe->setModel(tmpemploye.afficher_list());
 ui-> comboBox_modemploye->setModel(tmpemploye.afficher_list());
 ui->shift_sup->setModel(tmpsh.afficher_list());
 ui->shif_mod->setModel(tmpsh.afficher_list());
}
gestion::~gestion()
{
    delete ui;
}

void gestion::on_pushButton_clicked()
{ QString ID_EMPLOYE=ui->lineEdit_ID_EMPLOYE->text();
 QString NOM=ui->lineEdit_NOM->text();
 QString PRENOM=ui->lineEdit_PRENOM->text();
 QString ASSIDUITE=ui->lineEdit_ASSIDUITE->text();
 QString AVANTAGE=ui->lineEdit_AVANTAGE->text();
 int SOLDE_DE_CONGE=ui->lineEdit_SOLDE_DE_CONGE->text().toInt();
 int SALAIRE=ui->lineEdit_SALAIRE->text().toInt() ;
 int ABSENCE=ui->lineEdit_ABSENCE->text().toInt();
 int RANG=ui->lineEdit_RANG->text().toInt() ;
 employe  e(ID_EMPLOYE,ASSIDUITE,AVANTAGE,SOLDE_DE_CONGE, ABSENCE,SALAIRE,RANG,NOM,PRENOM);
bool test=e.ajouter_employe();
if (test)
{   ui->tab_employe->setModel(tmpemploye.afficher_employe());
 ui->comboBox_ajoutID->setModel(tmpemploye.afficher_list());
 ui->tab_shift->setModel(tmpsh.afficher_shift());
 ui->comboBox_employe->setModel(tmpemploye.afficher_list());
 ui-> comboBox_modemploye->setModel(tmpemploye.afficher_list());
 ui->shift_sup->setModel(tmpsh.afficher_list());
 ui->shif_mod->setModel(tmpsh.afficher_list());
 QMessageBox::information(nullptr,QObject::tr("ajouter employe"),
   QObject::tr("employe ajoute.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
else
QMessageBox::critical(nullptr, QObject::tr("Ajouter un employe"),
    QObject::tr("Erreur !.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}


void gestion::on_ok_clicked()
{
    if(selected!=-1){
    bool test=tmpemploye.supprimer_employe(tmpemploye.get_ID_EMPLOYE());
    if(test)
    {

        ui->tab_employe->setModel(tmpemploye.afficher_employe());
     ui->comboBox_ajoutID->setModel(tmpemploye.afficher_list());
     ui->tab_shift->setModel(tmpsh.afficher_shift());
     ui->comboBox_employe->setModel(tmpemploye.afficher_list());
     ui-> comboBox_modemploye->setModel(tmpemploye.afficher_list());
     ui->shift_sup->setModel(tmpsh.afficher_list());
     ui->shif_mod->setModel(tmpsh.afficher_list());
     QMessageBox::information(nullptr, QObject::tr("Supprimer un employe"),
                    QObject::tr("employe supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
 }else{
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employe"),
                            QObject::tr("merci de choisir un ID !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void gestion::on_pushButton_2_clicked()
  {
    QString NOM=ui->lineEdit_NOM_2->text();
    QString PRENOM=ui->lineEdit_PRENOM_2->text();
    QString ASSIDUITE=ui->lineEdit_ASSIDUITE_2->text();
    QString AVANTAGE=ui->lineEdit_AVANTAGE_2->text();
    int SOLDE_DE_CONGE=ui->lineEdit_SOLDE_DE_CONGE_2->text().toInt();
    int SALAIRE=ui->lineEdit_SALAIRE_2->text().toInt() ;
    int ABSENCE=ui->lineEdit_ABSENCE_2->text().toInt();
    int RANG=ui->lineEdit_RANG_2->text().toInt() ;
    employe  e(tmpemploye.get_ID_EMPLOYE(),ASSIDUITE,AVANTAGE,SOLDE_DE_CONGE, ABSENCE,SALAIRE,RANG,NOM,PRENOM);
   if((tmpemploye.get_ID_EMPLOYE()=="")||(NOM=="")||(PRENOM=="")||(ASSIDUITE=="")||(AVANTAGE=="")||(ui->lineEdit_SOLDE_DE_CONGE_2->text()=="")||(ui->lineEdit_SALAIRE_2->text()=="")||(ui->lineEdit_ABSENCE_2->text()=="")||(ui->lineEdit_RANG_2)->text()=="")
{QMessageBox::information(nullptr,QObject::tr("verifier champs"),
                          QObject::tr("merci de remplir tous les champs \n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
   }
    else{       bool test=e.modifier_employe();
   if (test)
   {

       ui->tab_employe->setModel(tmpemploye.afficher_employe());
    ui->comboBox_ajoutID->setModel(tmpemploye.afficher_list());
    ui->tab_shift->setModel(tmpsh.afficher_shift());
    ui->comboBox_employe->setModel(tmpemploye.afficher_list());
    ui-> comboBox_modemploye->setModel(tmpemploye.afficher_list());
    ui->shift_sup->setModel(tmpsh.afficher_list());
    ui->shif_mod->setModel(tmpsh.afficher_list());
    QMessageBox::information(nullptr,QObject::tr("modifier employe"),
      QObject::tr("employe modifier.\n"
                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else{
   QMessageBox::critical(nullptr, QObject::tr("modifier employe"),
       QObject::tr("merci de verifiez l'id !.\n"
                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
   }
}



void gestion::on_pushButton_3_clicked()
{
bool test=tmpsh.ajouter_shift();
if (test)
{

    ui->tab_employe->setModel(tmpemploye.afficher_employe());
 ui->comboBox_ajoutID->setModel(tmpemploye.afficher_list());
 ui->tab_shift->setModel(tmpsh.afficher_shift());
 ui->comboBox_employe->setModel(tmpemploye.afficher_list());
 ui-> comboBox_modemploye->setModel(tmpemploye.afficher_list());
 ui->shift_sup->setModel(tmpsh.afficher_list());
 ui->shif_mod->setModel(tmpsh.afficher_list());
 QMessageBox::information(nullptr,QObject::tr("ajouter employe"),
   QObject::tr("l'employe a ete bien affecte .\n"
                "Click Cancel to exit."), QMessageBox::Cancel);

}
else
{QMessageBox::critical(nullptr, QObject::tr("Ajouter employe"),
    QObject::tr("l'employe est deja affecter a ce shift  !.\n"
                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void gestion::on_comboBox_ajoutID_activated(const QString &arg1)
{
    tmpsh.set_ID_EMPLOYE(arg1);

}
void gestion::on_dateEdit_dateChanged(const QDate &date)
{
    tmpsh.set_DATEDUJOUR(date.toString());
}

void gestion::on_comboBox_ajoutshift_activated(const QString &arg1)
{tmpsh.set_SHIFFT(arg1);}



void gestion::on_ok_shift_clicked()
{

    bool test=tmpsh.supprimer_shift();
    if(test)
    {

        ui->tab_employe->setModel(tmpemploye.afficher_employe());
     ui->comboBox_ajoutID->setModel(tmpemploye.afficher_list());
     ui->tab_shift->setModel(tmpsh.afficher_shift());
     ui->comboBox_employe->setModel(tmpemploye.afficher_list());
     ui-> comboBox_modemploye->setModel(tmpemploye.afficher_list());
     ui->shift_sup->setModel(tmpsh.afficher_list());
     ui->shif_mod->setModel(tmpsh.afficher_list());
     QMessageBox::information(nullptr, QObject::tr("Supprimer shift"),
                    QObject::tr("shift supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer shift"),
                    QObject::tr("cette employe n'a pas encore ete affecter dans un shift  !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void gestion::on_comboBox_employe_activated(const QString &arg1)
{
     tmpemploye.set_ID_EMPLOYE(arg1);
}







void gestion::on_comboBox_modemploye_activated(const QString &arg1)
{
    tmpemploye.set_ID_EMPLOYE(arg1);
    tmpemploye.chercher();
    ui->lineEdit_NOM_2->setText(tmpemploye.get_NOM());
    ui->lineEdit_PRENOM_2->setText(tmpemploye.get_PRENOM());
    ui->lineEdit_ASSIDUITE_2->setText(tmpemploye.get_ASSIDUITE());
    ui->lineEdit_AVANTAGE_2->setText(tmpemploye.get_AVANTAGES());
    ui->lineEdit_SOLDE_DE_CONGE_2->setText(QString ::number(tmpemploye.get_SOLDE_DE_CONGE()));
    ui->lineEdit_SALAIRE_2->setText(QString::number(tmpemploye.get_SALAIRE()));
    ui->lineEdit_ABSENCE_2->setText(QString::number(tmpemploye.get_ABSENCE()));
    ui->lineEdit_RANG_2->setText(QString::number(tmpemploye.get_RANG())) ;

}

void gestion::on_comboBox_employe_activated(int index)
{
selected=index;
}

void gestion::on_shift_sup_activated(const QString &arg1)
{
    tmpsh.generate_data(arg1);
}

void gestion::on_shif_mod_activated(const QString &arg1)
{
    tmpsh.generate_data(arg1);
    ui->lineEdit_shift->setText(tmpsh.get_SHIFFT());
    ui->lineEdit_date->setText(tmpsh.get_DATEDUJOUR());
}

void gestion::on_comboBox_ajoutshift_2_activated(const QString &arg1)
{
    NEW_shifft=arg1;
}

void gestion::on_dateEdit_2_userDateChanged(const QDate &date)
{
    NEW_date=date.toString();
}

void gestion::on_pushButton_5_clicked()
{
    if(mod_selected!=-1){
    if(NEW_shifft==""){
        NEW_shifft=tmpsh.get_SHIFFT();
    }
    if(NEW_date==""){
        NEW_date=tmpsh.get_DATEDUJOUR();
    }
    if(tmpsh.modifier_shift(NEW_date,NEW_shifft)){
        ui->tab_employe->setModel(tmpemploye.afficher_employe());
     ui->comboBox_ajoutID->setModel(tmpemploye.afficher_list());
     ui->tab_shift->setModel(tmpsh.afficher_shift());
     ui->comboBox_employe->setModel(tmpemploye.afficher_list());
     ui-> comboBox_modemploye->setModel(tmpemploye.afficher_list());
     ui->shift_sup->setModel(tmpsh.afficher_list());
     ui->shif_mod->setModel(tmpsh.afficher_list());
     QMessageBox::information(nullptr, QObject::tr("MODIFIER shift"),
                    QObject::tr("shift modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }else{
        QMessageBox::information(nullptr, QObject::tr("MODIFIER shift"),
                       QObject::tr("shift déja existe.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

    }
    }else{
        QMessageBox::information(nullptr, QObject::tr("MODIFIER shift"),
                       QObject::tr("merci de choisir un ID .\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void gestion::on_shif_mod_activated(int index)
{
    mod_selected=index;
}
