#include "menu_principal.h"
#include "ui_menu_principal.h"
#include "gestion_vol.h"
menu_principal::menu_principal(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::menu_principal)
{
    ui->setupUi(this);
}

menu_principal::~menu_principal()
{
    delete ui;
}

void menu_principal::on_pushButton_clicked()
{
    gestion_vol c;
    c.exec();
}
