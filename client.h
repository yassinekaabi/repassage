#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQueryModel>

class client
{
    QString ID_CLIENT;
    QString NOM;
    QString PRENOM;
    QString MAIL;
    QString SEXE;

public:
    client();
    client(QString ID_CLIENT,QString NOM,QString PRENOM,QString MAIL,QString SEXE);
    client(QString NOM,QString PRENOM,QString MAIL,QString SEXE);
    void Ajouter();
    QSqlQueryModel *afficher();
    void supprimer(QString ID_CLIENT);
    void modifier();
};

#endif // CLIENT_H
