#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion.h"
#include "notification.h"

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
{Gestion g ;
    g.setWindowTitle("Gestion des Clients");
    QString okd="";
         notification ok;
         ok.notification_Ouverture(okd);

 g.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
   close();
}
