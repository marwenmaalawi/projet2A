#include "menu.h"
#include "ui_menu.h"
#include "gestion_employes.h"
menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{gestion_employes p;
    p.exec();

}
