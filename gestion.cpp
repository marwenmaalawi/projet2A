#include "gestion.h"
#include "ui_gestion.h"
#include "QMessageBox"
#include "mainwindow.h"
#include "mail.h"
#include"notification.h"
#include<QDebug>
#include "statistiques.h"
Gestion::Gestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion)
{
    ui->setupUi(this);
    ui->tableView_3->setModel(tmpclient.afficher());
    ui->tab_promotions->setModel(tmppromo.afficher());
 ui->comboBox->setModel(tmpclient.afficher_listclient());
 ui->comboBox_2->setModel(tmpclient.afficher_listclient());
 ui->comboBox_3->setModel(tmppromo.afficher_listpromo());
 ui->comboBox_4->setModel(tmppromo.afficher_listpromo());


}


Gestion::~Gestion()
{
    delete ui;
}


void Gestion::on_pushButton_15_clicked()
{
 //  MainWindow m;
    close();
    //m.exec();
}

void Gestion::on_pushButton_17_clicked()
{
    close();
}

void Gestion::on_pushButton_19_clicked()
{
    close();
}

void Gestion::on_pushButton_21_clicked()
{
    close();
}

void Gestion::on_pushButton_18_clicked()
{
    QString okd="";
         notification ok;
    QString num_passeport= ui->lineEdit_20->text();
    bool test=tmpclient.supprimer_clients(num_passeport);
    if(test)
    {ui->tableView_3->setModel(tmpclient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
ok.notification_supprimer_client(okd);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gestion::on_pushButton_16_clicked()
{
    QString okd="";
         notification ok;


    QString nom = ui->lineEdit_15->text();
        QString prenom = ui->lineEdit_16->text();
       QString num_passeport  = ui->lineEdit_18->text();
     QString nationnalite  = ui->lineEdit_19->text();
     QString email=ui->lineEdit_email->text();
     QString num_telephone=ui->lineEdit_num_telephone->text();
     int nb_voyages=ui->lineEdit_nb_voyages->text().toInt();
     Clients c(nom,prenom,num_passeport,nationnalite,email,num_telephone,nb_voyages);
     bool test=c.ajouter_client();
     if(test)
   {ui->tableView_3->setModel(tmpclient.afficher());//refresh
   QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                     QObject::tr("client ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
   ok.notification_ajout_client(okd);

   }
     else
       {  QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}
}

//Modifier!!!









void Gestion::on_ajouter_promotion_clicked()
{
    QString okd="";
         notification ok;

    QString id = ui->lineEdit_id->text();
    QString pourcentage  = ui->lineEdit_pourcentage->text();
        QString evenement = ui->lineEdit_evenement->text();

     Promotions p(pourcentage,evenement,id,tmppromo.getnum_passeport());

     bool test=p.ajouter_promotions();
     if(test)
   {ui->tableView_3->setModel(tmppromo.afficher());//refresh
   QMessageBox::information(nullptr, QObject::tr("Ajouter une prmotion"),
                     QObject::tr("PROMOTION ajoutée.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
   ok.notification_ajout_promo(okd);

   }
     else
       {  QMessageBox::critical(nullptr, QObject::tr("Ajouter une promotion"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}
}






void Gestion::on_comboBox_activated(const QString &arg1)
{
    tmppromo.set_num_passeport(arg1);
}

void Gestion::on_supprimer_promotion_clicked()
{    QString okd="";
     notification ok;

    QString id= ui->lineEdit_supprimer_promotion->text();
    bool test=tmppromo.supprimer_promotions(id);
    if(test)
    {ui->tab_promotions->setModel(tmpclient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une promotion"),
                    QObject::tr("Promotion supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
ok.notification_supprimer_promo(okd);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une promotion"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gestion::on_pushButton_27_clicked()
{
    QString okd="";
         notification ok;
    QString id = ui->lineEdit_id->text();
    QString pourcentage  = ui->lineEdit_pourcentage->text();
        QString evenement = ui->lineEdit_evenement->text();

    Promotions p;
    if(p.rech(id)){
        bool test = p.modifier(pourcentage,evenement,tmppromo.getnum_passeport(),id);
        if(test){
            ui->tab_promotions->setModel(tmppromo.afficher());
            QMessageBox::information(nullptr,QObject::tr("Promotion modifée"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
      ok.notification_modifier_promo(okd);
        }

        else
          {  QMessageBox::critical(nullptr, QObject::tr("Modifier une promotion"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
    }
}

void Gestion::on_pushButton_20_clicked()
{
    QString okd="";
         notification ok;

    QString nom = ui->lineEdit_24->text();
    QString prenom = ui->lineEdit_17->text();
    QString num_passeport = ui->lineEdit_21->text();
    QString nationnalite = ui->lineEdit_22->text();
    QString email = ui->lineEdit_email_2->text();
    QString num_telephone = ui->lineEdit_num_telephone_2->text();
    int nb_voyages = ui->lineEdit_nb_voyages_2->text().toInt();


    Clients c;
    if(c.rech(num_passeport)){
        bool test = c.modifier(nom,prenom,num_passeport,nationnalite,email,num_telephone,nb_voyages);
        if(test){
            ui->tableView_3->setModel(tmpclient.afficher());
            QMessageBox::information(nullptr,QObject::tr("Clients modifié"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
       ok.notification_modifier_client(okd);
        }

        else
          {  QMessageBox::critical(nullptr, QObject::tr("Modifier un client"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
    }
}

void Gestion::on_pushButton_23_clicked()
{
    close();
}

void Gestion::on_pushButton_24_clicked()
{
     close();
}

void Gestion::on_pushButton_22_clicked()
{
     close();
}

void Gestion::on_pushButton_25_clicked()
{
     close();
}

void Gestion::on_pushButton_clicked()
{
    ui->tableView_3->setModel(tmpclient.afficher_tri());
}

void Gestion::on_pushButton_2_clicked()
{
  ui->tab_promotions->setModel(tmppromo.afficher_tri());
}

void Gestion::on_pushButton_5_clicked()
{
    QString num_passeport;

     num_passeport=ui->lineEdit_chercher_client->text();
     QSqlQueryModel *model=new QSqlQueryModel();
     QSqlQuery* query=new QSqlQuery();
     query->prepare("Select * from CLIENTS where num_passeport=:num_passeport ");
     query->bindValue(":num_passeport",num_passeport);
     query->exec();
     model->setQuery(*query);

    qDebug()<<(model->rowCount());
    if( (model->rowCount()==0))
     QMessageBox::information(nullptr, QObject::tr("Rechercher un client "),
                 QObject::tr(" Ce client n'existe pas .\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);


   else
     QMessageBox::information(nullptr, QObject::tr("Rechercher un client "),
                 QObject::tr(" Le client existe \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

}

void Gestion::on_lineEdit_chercher_client_cursorPositionChanged()
{
Clients c;
    QString num_passeport=ui->lineEdit_chercher_client->text();
     c.rechercher_client(ui->tableView_rechercheC,num_passeport);
}


void Gestion::on_lineEdit_id_3_cursorPositionChanged()
{
    Promotions p;
    QString ID_PROMO=ui->lineEdit_id_3->text();
    p.rechercher_promotion(ui->tableView_rechercheC_2,ID_PROMO);
}


void Gestion::on_pushButton_6_clicked()
{
    QString ID_PROMO;

     ID_PROMO=ui->lineEdit_id_3->text();
     QSqlQueryModel *model=new QSqlQueryModel();
     QSqlQuery* query=new QSqlQuery();
     query->prepare("Select * from PROMOTIONS where ID_PROMO=:ID_PROMO");
     query->bindValue(":ID_PROMO",ID_PROMO);
     query->exec();
     model->setQuery(*query);

    qDebug()<<(model->rowCount());
    if( (model->rowCount()==0))
     QMessageBox::information(nullptr, QObject::tr("Rechercher une promotion"),
                 QObject::tr(" Cette promotion n'existe pas .\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);


   else
     QMessageBox::information(nullptr, QObject::tr("Rechercher une promotion "),
                 QObject::tr(" La promotion existe \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

}

void Gestion::on_comboBox_3_activated(const QString &arg1)
{
   tmppromo.set_num_passeport(arg1);
}

void Gestion::on_comboBox_4_activated(const QString &arg1)
{
    tmppromo.set_num_passeport(arg1);
}



void Gestion::on_pushButton_3_clicked()
{
    mail m ;
   m.setWindowTitle("Envoyer un mail");
    m.exec();
}

void Gestion::on_pushButton_consulter_clicked()
{
    statistiques *s = new statistiques();
    setWindowModality(Qt::WindowModal);
    s->show();
}



void Gestion::on_pushButton_7_clicked()
{
    close();
}
