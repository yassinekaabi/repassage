#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "commande.h"

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QVBoxLayout>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/htc/OneDrive/Documents/test/11878958_Online_Shoping_29.png");

    // Assign the pixmap to the QLabel
    ui->label->setPixmap(pix);
    ui->label_15->setPixmap(pix);
    ui->label_14->setPixmap(pix);
    // Scale the image to fit the QLabel automatically

    ui->label->setScaledContents(true);
    ui->label_15->setScaledContents(true);
    ui->label_14->setScaledContents(true);
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
    QString SEXE = ui->SEXE->currentText();
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
    QString SEXE = ui->SEXE->currentText();
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

void MainWindow::on_statbtnC_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT statut, COUNT(*) FROM commande GROUP BY statut");

    if (!query.exec()) {
        qDebug() << "Erreur requête stats:" << query.lastError().text();
        return;
    }

    // Créer une série
    QPieSeries *series = new QPieSeries();

    while (query.next()) {
        QString statut = query.value(0).toString();
        int count = query.value(1).toInt();
        series->append(statut, count);
    }

    // Créer le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des commandes par statut");
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Créer la vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // ⚡ Insérer dans le widget stats_commande
    QVBoxLayout *layout = new QVBoxLayout(ui->stats_commande);
    layout->addWidget(chartView);
    ui->stats_commande->setLayout(layout);
}



void MainWindow::on_statbtnC_2_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT sexe, COUNT(*) FROM client GROUP BY sexe");

    if (!query.exec()) {
        qDebug() << "Erreur requête stats:" << query.lastError().text();
        return;
    }

    // Créer une série
    QPieSeries *series = new QPieSeries();
    while (query.next()) {
        QString sexe = query.value(0).toString();
        int count = query.value(1).toInt();
        series->append(sexe, count);
    }

    // Créer le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des clients par sexe");
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // 🔥 Supprimer l'ancien contenu du widget statsCl
    QLayout *oldLayout = ui->statsCl->layout();
    if (oldLayout != nullptr) {
        QLayoutItem *item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();  // supprimer anciens charts
            delete item;
        }
        delete oldLayout;
    }

    // Ajouter un nouveau layout avec le chart
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);
    ui->statsCl->setLayout(layout);
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QSqlQueryModel *model = new QSqlQueryModel();

    // Préparer la requête de recherche
    QSqlQuery query;
    query.prepare("SELECT id_client, nom, prenom, sexe, mail "
                  "FROM client "
                  "WHERE id_client LIKE :rech "
                  "   OR nom LIKE :rech "
                  "   OR prenom LIKE :rech");

    // Ajouter les wildcards %
    query.bindValue(":rech", "%" + arg1 + "%");

    query.exec();
    model->setQuery(query);

    // Afficher dans le TableView
    ui->tableView->setModel(model);
}


void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    QSqlQueryModel *model = new QSqlQueryModel();

    // Préparer la requête de recherche
    QSqlQuery query;
    query.prepare("SELECT id_commande,montant,statut,date_commande,id_client "
                  "FROM commande "
                  "WHERE id_commande LIKE :rech ");

    // Ajouter les wildcards %
    query.bindValue(":rech", "%" + arg1 + "%");

    query.exec();
    model->setQuery(query);

    // Afficher dans le TableView
    ui->tableView_2->setModel(model);
}


void MainWindow::on_triCLB_clicked()
{
    QString tri = ui->triCL->currentText(); // "ASC" ou "DESC"

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Exemple : trier par nom
    QString req = "SELECT id_client, nom, prenom, mail, sexe "
                  "FROM client ORDER BY id_client " + tri;

    query.prepare(req);
    query.exec();
    model->setQuery(query);

    ui->tableView->setModel(model);
}


void MainWindow::on_triCB_clicked()
{
    QString triC = ui->triC->currentText(); // "ASC" ou "DESC"

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    QString req = "SELECT id_commande, montant, statut, date_commande, id_client "
                  "FROM commande ORDER BY id_commande " + triC;

    query.prepare(req);
    query.exec();
    model->setQuery(query);

    ui->tableView_2 ->setModel(model);
}

