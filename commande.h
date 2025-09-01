#ifndef COMMANDE_H
#define COMMANDE_H
#include <QDate>
#include <QSqlQueryModel>

class commande
{
    QString ID_COMMANDE;
    QString MONTANT;
    QString STATUT;
    QDate DATE_COMMANDE;
    QString ID_CLIENT;

public:
    commande();
    commande(QString MONTANT,QString STATUT,QDate DATE_COMMANDE,QString ID_CLIENT);
    commande(QString ID_COMMANDE,QString MONTANT,QString STATUT,QDate DATE_COMMANDE,QString ID_CLIENT);
    void Ajouter();
    QSqlQueryModel *afficher();
    void supprimer(QString ID_COMMANDE);
    void modifier();
};

#endif // COMMANDE_H
