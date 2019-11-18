#include "employe.h"

employe::employe(){

}
employe::employe(QString ID_EMPLOYE,QString ASSIDUITE,QString AVANTAGE,int SOLDE_DE_CONGE,int ABSENCE,int SALAIRE,int RANG,QString NOM,QString PRENOM)
{this->ID_EMPLOYE=ID_EMPLOYE;
 this->AVANTAGE=AVANTAGE;
 this->ASSIDUITE=ASSIDUITE  ;
 this->SOLDE_DE_CONGE=SOLDE_DE_CONGE;
 this->ABSENCE=ABSENCE;
 this->SALAIRE=SALAIRE;
 this->RANG=RANG;
 this->NOM=NOM;
 this->PRENOM=PRENOM;}

//get&set
void employe::set_ID_EMPLOYE(QString ID_EMPLOYE){
    this->ID_EMPLOYE=ID_EMPLOYE;
}
QString employe::get_ID_EMPLOYE(){return ID_EMPLOYE;}
QString employe::get_AVANTAGES(){return AVANTAGE;}
QString employe::get_ASSIDUITE(){return ASSIDUITE;}
int employe::get_SOLDE_DE_CONGE(){return SOLDE_DE_CONGE;}
int employe::get_ABSENCE(){return ABSENCE;}
int employe::get_SALAIRE(){return SALAIRE;}
int employe::get_RANG(){return RANG;}
QString employe::get_NOM(){return NOM;}
QString employe::get_PRENOM(){return PRENOM;}

//
bool employe::ajouter_employe()
{QSqlQuery query ;
 QString res= QString::number(SOLDE_DE_CONGE);
 QString res1= QString::number(ABSENCE);
 QString res2= QString::number(SALAIRE);
 QString res3= QString::number(RANG);
 query.prepare("INSERT INTO employes(ID_EMPLOYE,AVANTAGES,ASSIDUITE,SOLDE_DE_CONGE,ABSENCE,SALAIRE,RANG,NOM,PRENOM)VALUES(:ID_EMPLOYE,:AVANTAGES,:ASSIDUITE,:SOLDE_DE_CONGE,:ABSENCE,:SALAIRE,:RANG,:NOM,:PRENOM)");
 query.bindValue(":ID_EMPLOYE",ID_EMPLOYE);
 query.bindValue(":ASSIDUITE",ASSIDUITE);
 query.bindValue(":SOLDE_DE_CONGE",res);
 query.bindValue(":ABSENCE",res1);
 query.bindValue(":SALAIRE",res2);
 query.bindValue(":RANG",res3);
 query.bindValue(":NOM",NOM);
 query.bindValue(":PRENOM",PRENOM);
 query.bindValue(":AVANTAGES",AVANTAGE);
 return query.exec();
}
bool employe::modifier_employe()
{QSqlQuery query ;
 QString res= QString::number(SOLDE_DE_CONGE);
 QString res1= QString::number(ABSENCE);
 QString res2= QString::number(SALAIRE);
 QString res3= QString::number(RANG);
 query.prepare("UPDATE employes SET AVANTAGES=:AVANTAGES,ASSIDUITE=:ASSIDUITE,SOLDE_DE_CONGE=:SOLDE_DE_CONGE,ABSENCE=:ABSENCE,SALAIRE=:SALAIRE,RANG=:RANG,NOM=:NOM,PRENOM=:PRENOM where ID_EMPLOYE=:ID_EMPLOYE");
 query.bindValue(":ID_EMPLOYE",ID_EMPLOYE);
 query.bindValue(":ASSIDUITE",ASSIDUITE);
 query.bindValue(":SOLDE_DE_CONGE",res);
 query.bindValue(":ABSENCE",res1);
 query.bindValue(":SALAIRE",res2);
 query.bindValue(":RANG",res3);
 query.bindValue(":NOM",NOM);
 query.bindValue(":PRENOM",PRENOM);
 query.bindValue(":AVANTAGES",AVANTAGE);
 query.exec();
 if(query.numRowsAffected()==0){
     return false;
 } else{
     return true;
 }
}

QSqlQueryModel * employe::afficher_employe()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from employes");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ASSIDUITE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("AVANTAGE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("SOLDE_DE_CONGE"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("ABSENCE"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("SALAIRE"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("RANG"));
model->setHeaderData(7, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(8, Qt::Horizontal, QObject::tr("PRENOM"));
    return model;
}

bool employe::supprimer_employe(QString ID)
{
QSqlQuery query;
query.prepare("Delete from employes where ID_EMPLOYE = :ID");
query.bindValue(":ID",ID);
return   query.exec();
}


QSqlQueryModel * employe::afficher_list(){
QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select ID_EMPLOYE from employes");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
return  model;
}

void employe::chercher(){
    QSqlQuery query;
    query.prepare("select assiduite,avantages,solde_de_conge,absence,salaire,rang,nom,prenom from employes where id_employe=:id");
    query.bindValue(":id",ID_EMPLOYE);
    query.exec();
    while(query.next()){
    ASSIDUITE=query.value(0).toString();
    AVANTAGE=query.value(1).toString();
    SOLDE_DE_CONGE=query.value(2).toInt();
    ABSENCE=query.value(3).toInt();
    SALAIRE=query.value(4).toInt();
    RANG=query.value(5).toInt();
    NOM=query.value(6).toString();
    PRENOM=query.value(7).toString();
    }
 }
