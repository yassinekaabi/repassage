#include "commande.h"
#include <QSqlQuery>

commande::commande(){

}

commande::commande(QString MONTANT,QString STATUT,QDate DATE_COMMANDE,QString ID_CLIENT){
    this->MONTANT=MONTANT;
    this->STATUT=STATUT;
    this->DATE_COMMANDE=DATE_COMMANDE;
    this->ID_CLIENT=ID_CLIENT;
}

commande::commande(QString ID_COMMANDE,QString MONTANT,QString STATUT,QDate DATE_COMMANDE,QString ID_CLIENT){
    this->ID_COMMANDE=ID_COMMANDE;
    this->MONTANT=MONTANT;
    this->STATUT=STATUT;
    this->DATE_COMMANDE=DATE_COMMANDE;
    this->ID_CLIENT=ID_CLIENT;
}


void commande::Ajouter()
{
    QSqlQuery query;
    query.prepare("insert into COMMANDE(MONTANT,STATUT,DATE_COMMANDE,ID_CLIENT) values (:MONTANT,:STATUT,:DATE_COMMANDE,:ID_CLIENT)");
    query.bindValue(":MONTANT",MONTANT);
    query.bindValue(":STATUT",STATUT);
    query.bindValue(":DATE_COMMANDE",DATE_COMMANDE);
    query.bindValue(":ID_CLIENT",ID_CLIENT);
    query.exec();
}
QSqlQueryModel* commande::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from COMMANDE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_COMMANDE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("MONTANT"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATUT"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_COMMANDE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ID_CLIENT"));
    return model;
}
void commande::supprimer(QString ID_COMMANDE)
{
    QSqlQuery query;
    query.prepare("delete from COMMANDE where ID_COMMANDE = :ID_COMMANDE");
    query.bindValue(":ID_COMMANDE", ID_COMMANDE);
    query.exec();
}
void commande::modifier()
{
    QSqlQuery query;
    query.prepare("update COMMANDE set  MONTANT=:MONTANT, STATUT=:STATUT,DATE_COMMANDE=:DATE_COMMANDE,ID_CLIENT=:ID_CLIENT where(ID_COMMANDE=:ID_COMMANDE)");
    query.bindValue(":MONTANT", MONTANT);
    query.bindValue(":STATUT", STATUT);
    query.bindValue(":DATE_COMMANDE", DATE_COMMANDE);
    query.bindValue(":ID_CLIENT", ID_CLIENT);
    query.bindValue(":ID_COMMANDE", ID_COMMANDE);
    query.exec();
}




