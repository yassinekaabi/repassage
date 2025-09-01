#include "client.h"
#include <QSqlQuery>
client::client() {}

client::client(QString ID_CLIENT,QString NOM,QString PRENOM,QString MAIL,QString SEXE)
{
    this->ID_CLIENT=ID_CLIENT;
    this->NOM=NOM;
    this->PRENOM=PRENOM;
    this->MAIL=MAIL;
    this->SEXE=SEXE;
}
client::client(QString NOM,QString PRENOM,QString MAIL,QString SEXE)
{
    this->NOM=NOM;
    this->PRENOM=PRENOM;
    this->MAIL=MAIL;
    this->SEXE=SEXE;
}
void client::Ajouter()
{
    QSqlQuery query;
    query.prepare("insert into CLIENT(NOM,PRENOM,MAIL,SEXE) values (:NOM,:PRENOM,:MAIL,:SEXE)");
    query.bindValue(":NOM",NOM);
    query.bindValue(":PRENOM",PRENOM);
    query.bindValue(":MAIL",MAIL);
    query.bindValue(":SEXE",SEXE);
    query.exec();
}
QSqlQueryModel* client::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from CLIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("SEXE"));
    return model;
}
void client::supprimer(QString ID_CLIENT)
{
    QSqlQuery query;
    query.prepare("delete from CLIENT where ID_CLIENT = :ID_CLIENT");
    query.bindValue(":ID_CLIENT", ID_CLIENT);
    query.exec();
}
void client::modifier()
{
    QSqlQuery query;
    query.prepare("update CLIENT set  NOM=:NOM, PRENOM=:PRENOM,MAIL=:MAIL,SEXE=:SEXE where(ID_CLIENT=:ID_CLIENT)");
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":MAIL", MAIL);
    query.bindValue(":SEXE", SEXE);
    query.bindValue(":ID_CLIENT", ID_CLIENT);
    query.exec();

}


