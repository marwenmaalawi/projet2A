#include "fournisseur.h"
#include "QtSql"
#include "QSqlQuery"
fournisseur::fournisseur()
{

}


fournisseur::fournisseur(QString id,QString nom,QString mail)
{this->id=id;
 this->nom=nom;
 this->mail=mail;

}
QString fournisseur::get_id(){return id;}
QString fournisseur:: get_nom(){return nom;}
QString fournisseur::get_mail(){return mail;}
void fournisseur:: set_id(QString id){this->id=id;}
void fournisseur::set_nom(QString nom){this->nom=nom;}
void fournisseur::set_mail(QString mail){this->mail=mail;}

bool fournisseur::ajouter_fournisseur()
{
QSqlQuery query;

query.prepare("INSERT INTO fournisseurs (ID_FOURNISSEUR,NOM_FOURNISSEUR,ADRESSE_MAIL) VALUES (:ID_FOURNISSEUR,:NOM_FOURNISSEUR,:ADRESSE_MAIL)");
query.bindValue(":ID_FOURNISSEUR",id);
query.bindValue(":NOM_FOURNISSEUR", nom);
query.bindValue(":ADRESSE_MAIL", mail);


return    query.exec();
}

QSqlQueryModel * fournisseur::afficher_fournisseur()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select ID_FOURNISSEUR, NOM_FOURNISSEUR, ADRESSE_MAIL from fournisseurs");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_FOURNISSEUR "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE_MAIL"));

    return model;
}



bool fournisseur::supprimer_fournisseur(QString id)
{
QSqlQuery query;
query.prepare("Delete from fournisseurs where ID_FOURNISSEUR=:ID_FOURNISSEUR ");
query.bindValue(":ID_FOURNISSEUR", id);
  query.exec();
return (query.numRowsAffected()>0) ;
}
QSqlQueryModel * fournisseur::afficher_listfournisseur()
{QSqlQueryModel* model =new QSqlQueryModel();
model->setQuery("select ID_FOURNISSEUR from FOURNISSEURS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNISSEUR"));
return model ;}


