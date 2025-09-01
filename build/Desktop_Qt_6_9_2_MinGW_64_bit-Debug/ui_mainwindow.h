/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *page;
    QTableView *tableView;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *ID_CLIENT;
    QLineEdit *NOM;
    QLineEdit *PRENOM;
    QLineEdit *MAIL;
    QLabel *label_6;
    QLineEdit *SEXE;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_7;
    QWidget *page_2;
    QTableView *tableView_2;
    QLabel *label_7;
    QLineEdit *ID_COMMANDE;
    QLineEdit *MONTANT;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *pushButton_4;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QDateEdit *DATE_COMMANDE;
    QPushButton *pushButton_8;
    QComboBox *comboBox;
    QComboBox *STATUT;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 776);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(2, 29, 1161, 681));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 10, 1151, 701));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        pushButton_5 = new QPushButton(page_3);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(382, 150, 381, 81));
        pushButton_6 = new QPushButton(page_3);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(382, 290, 381, 71));
        stackedWidget->addWidget(page_3);
        page = new QWidget();
        page->setObjectName("page");
        tableView = new QTableView(page);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(30, 440, 1071, 241));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 100, 121, 20));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 170, 121, 20));
        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 220, 121, 20));
        label_5 = new QLabel(page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(70, 270, 131, 20));
        ID_CLIENT = new QLineEdit(page);
        ID_CLIENT->setObjectName("ID_CLIENT");
        ID_CLIENT->setGeometry(QRect(210, 100, 113, 26));
        NOM = new QLineEdit(page);
        NOM->setObjectName("NOM");
        NOM->setGeometry(QRect(210, 160, 113, 26));
        PRENOM = new QLineEdit(page);
        PRENOM->setObjectName("PRENOM");
        PRENOM->setGeometry(QRect(210, 210, 113, 26));
        MAIL = new QLineEdit(page);
        MAIL->setObjectName("MAIL");
        MAIL->setGeometry(QRect(210, 270, 113, 26));
        label_6 = new QLabel(page);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(70, 340, 121, 20));
        SEXE = new QLineEdit(page);
        SEXE->setObjectName("SEXE");
        SEXE->setGeometry(QRect(210, 330, 113, 26));
        pushButton = new QPushButton(page);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 390, 93, 29));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(480, 100, 93, 29));
        pushButton_3 = new QPushButton(page);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(360, 100, 93, 29));
        pushButton_7 = new QPushButton(page);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(1010, 30, 93, 29));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        tableView_2 = new QTableView(page_2);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(30, 350, 1111, 341));
        label_7 = new QLabel(page_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(80, 40, 121, 20));
        ID_COMMANDE = new QLineEdit(page_2);
        ID_COMMANDE->setObjectName("ID_COMMANDE");
        ID_COMMANDE->setGeometry(QRect(220, 40, 113, 26));
        MONTANT = new QLineEdit(page_2);
        MONTANT->setObjectName("MONTANT");
        MONTANT->setGeometry(QRect(220, 90, 113, 26));
        label_8 = new QLabel(page_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(80, 90, 121, 20));
        label_9 = new QLabel(page_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(80, 150, 121, 20));
        label_10 = new QLabel(page_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(80, 200, 131, 20));
        label_11 = new QLabel(page_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(80, 250, 121, 20));
        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(170, 310, 93, 29));
        pushButton_13 = new QPushButton(page_2);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setGeometry(QRect(460, 40, 93, 29));
        pushButton_14 = new QPushButton(page_2);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(350, 40, 93, 29));
        DATE_COMMANDE = new QDateEdit(page_2);
        DATE_COMMANDE->setObjectName("DATE_COMMANDE");
        DATE_COMMANDE->setGeometry(QRect(220, 200, 111, 26));
        pushButton_8 = new QPushButton(page_2);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(1020, 20, 93, 29));
        comboBox = new QComboBox(page_2);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(220, 250, 111, 26));
        STATUT = new QComboBox(page_2);
        STATUT->addItem(QString());
        STATUT->addItem(QString());
        STATUT->addItem(QString());
        STATUT->setObjectName("STATUT");
        STATUT->setGeometry(QRect(220, 150, 111, 26));
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Gestion client", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Gestion commande", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ID_CLIENT", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "NOM", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "PRENOM", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "MAIL", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "SEXE", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "retour", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "ID_COMMANDE", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "MONTANT", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "STATUT", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "DATE_COMMANDE", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "nom_client", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "ajouter", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "retour", nullptr));
        STATUT->setItemText(0, QCoreApplication::translate("MainWindow", "livree", nullptr));
        STATUT->setItemText(1, QCoreApplication::translate("MainWindow", "en cours", nullptr));
        STATUT->setItemText(2, QCoreApplication::translate("MainWindow", "annulee", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
