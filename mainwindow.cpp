#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowModality(Qt::WindowModal);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   QString identifiant;
   QString mot_de_passe;
   identifiant = ui->lineEdit->text();
   mot_de_passe = ui->lineEdit_2->text();

   if(identifiant=="please" && mot_de_passe == "work")
   { gestion g;
    g.exec() ;}


}

void MainWindow::on_checkBox_clicked(bool checked)
{
    if(checked)
    {

        ui->lineEdit_2->setEchoMode(QLineEdit::EchoMode(0));
    }
    else
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::EchoMode(2));
    }

}
