#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "commande.h"
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString NOM = ui->NOM->text();
    QString PRENOM = ui->PRENOM->text();
    QString MAIL = ui->MAIL->text();
    QString SEXE = ui->SEXE->text();
    client C(NOM,PRENOM,MAIL,SEXE);
    C.Ajouter();
    ui->tableView->setModel(C.afficher());
}


void MainWindow::on_pushButton_3_clicked()
{
    QString ID_CLIENT= ui->ID_CLIENT->text();
    client C;
    C.supprimer(ID_CLIENT);
    ui->tableView->setModel(C.afficher());
}

void MainWindow::on_pushButton_2_clicked()
{
    QString ID_CLIENT= ui->ID_CLIENT->text();
    QString NOM = ui->NOM->text();
    QString PRENOM = ui->PRENOM->text();
    QString MAIL = ui->MAIL->text();
    QString SEXE = ui->SEXE->text();
    client C(ID_CLIENT,NOM,PRENOM,MAIL,SEXE);
    C.modifier();
    ui->tableView->setModel(C.afficher());
}
void MainWindow::afficher()
{
    client C;
    commande c;
    ui->tableView->setModel(C.afficher());
    ui->tableView_2->setModel(c.afficher());
}


void MainWindow::on_pushButton_4_clicked()
{
    QString MONTANT = ui->MONTANT->text();
    QString STATUT = ui->STATUT->currentText();
    QDate DATE_COMMANDE = ui->DATE_COMMANDE->date();
    QString ID_CLIENT = ui->comboBox->currentData().toString();
    commande c(MONTANT,STATUT,DATE_COMMANDE,ID_CLIENT);
    c.Ajouter();
    ui->tableView_2->setModel(c.afficher());
}


void MainWindow::on_pushButton_13_clicked()
{
    QString ID_COMMANDE = ui->ID_COMMANDE->text();
    commande c;
    c.supprimer(ID_COMMANDE);
    ui->tableView_2->setModel(c.afficher());
}


void MainWindow::on_pushButton_14_clicked()
{
    QString ID_COMMANDE = ui->ID_COMMANDE->text();
    QString MONTANT = ui->MONTANT->text();
    QString STATUT = ui->STATUT->currentText();
    QDate DATE_COMMANDE = ui->DATE_COMMANDE->date();
    QString ID_CLIENT = ui->comboBox->currentData().toString();
    commande c(ID_COMMANDE,MONTANT,STATUT,DATE_COMMANDE,ID_CLIENT);
    c.modifier();
    ui->tableView_2->setModel(c.afficher());
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::displayCombo()
{
    QSqlQuery query;
    query.prepare("SELECT id_client, nom FROM client");

    if (query.exec()) {
        while (query.next()) {
            QString id = query.value(0).toString();
            QString name = query.value(1).toString();
            ui->comboBox->addItem(name, id);
        }
    }
}
