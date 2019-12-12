#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestionproduit.h"
#include"QMessageBox"
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
{ QString k,t;
    k=ui->pass->text();
    t=ui->user->text();
    if(k==login && t==lo)
    {gestionproduit gp;
        gp.exec();
    }else { QMessageBox::information(this,"title","mot de passe ou adresse incorect");

}


}
