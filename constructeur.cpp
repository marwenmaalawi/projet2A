#include "constructeur.h"
#include <QDebug>

constructeur::constructeur()
{

}

constructeur::constructeur(QString id,QString nom,QString mail)
{
  this->id=id;
  this->nom=nom;
  this->mail=mail;
}
QString constructeur::get_nom(){return  nom;}
QString constructeur::get_mail(){return mail;}
QString constructeur::get_id(){return  id;}
void constructeur::set_id(QString id){this->id=id;};
void constructeur::set_nom(QString nom ){this->nom=nom;};
void constructeur::set_mail(QString mail ){this->mail=mail;};

bool constructeur::ajouter_constructeur()
{
QSqlQuery query;

query.prepare("INSERT INTO constructeur (ID_CONSTRUCTEUR, NOM, MAIL) "
                    "VALUES (:id, :nom, :mail)");
query.bindValue(":id", id);
query.bindValue(":nom", nom);
query.bindValue(":mail", mail);

return    query.exec();
}

QSqlQueryModel * constructeur::afficher_constructeur()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from constructeur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}

QSqlQueryModel * constructeur::afficher_tri_id()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from constructeur order by id_constructeur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}
QSqlQueryModel * constructeur::afficher_tri_id_desc()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from constructeur order by id_constructeur desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}

QSqlQueryModel * constructeur::afficher_tri_nom
()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from constructeur order by nom");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}
QSqlQueryModel * constructeur::afficher_tri_nom_desc()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from constructeur order by nom desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}

QSqlQueryModel * constructeur::afficher_tri_mail()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from constructeur order by mail");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}
QSqlQueryModel * constructeur::afficher_tri_mail_desc()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from constructeur order by mail desc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}


bool constructeur::supprimer_constructeur(QString idd)
{
QSqlQuery query;

query.prepare("Delete from constructeur where ID_CONSTRUCTEUR = :idd ");
query.bindValue(":idd", idd);
return    query.exec();
}
QSqlQueryModel * constructeur::afficher_constructeurlist()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select id_constructeur from constructeur");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
    return model;
}

bool constructeur::modifier_constructeur()
{
    QSqlQuery query;
    query.prepare("UPDATE constructeur set nom=:nom, mail=:mail where id_constructeur =:idd ");
    query.bindValue(":idd",id);
    query.bindValue(":nom",nom);
    query.bindValue(":mail",mail);
    return    query.exec();

}
QSqlQueryModel * constructeur::chercher_constructeur_id(QString nom)
{QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
nom='%'+nom+'%';
query.prepare(" select * from constructeur where id_constructeur like :nom order by nom ");
query.bindValue(":nom",nom);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}

QSqlQueryModel * constructeur::chercher_constructeur_nom(QString nom)
{QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
nom='%'+nom+'%';
query.prepare(" select * from constructeur where nom like :nom  order by nom ");
query.bindValue(":nom",nom);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}

QSqlQueryModel * constructeur::chercher_constructeur_mail(QString nom)
{QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
nom='%'+nom+'%';
query.prepare(" select * from constructeur where mail like :nom order by nom ");
query.bindValue(":nom",nom);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CONS"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
    return model;
}


QSqlQueryModel * constructeur::getIdModel()
{
    QSqlQuery *query = new QSqlQuery();
    QSqlQueryModel *model = new QSqlQueryModel();
    query->prepare("select id_constructeur from constructeur");
    query->exec();
    model->setQuery(*query);
    return model;
}
