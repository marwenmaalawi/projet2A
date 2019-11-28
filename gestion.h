#ifndef GESTION_H
#define GESTION_H
#include "clients.h"
#include"promotions.h"
#include <QDialog>

namespace Ui {
class Gestion;
}

class Gestion : public QDialog
{
    Q_OBJECT

public:
    explicit Gestion(QWidget *parent = nullptr);
    ~Gestion();



private slots:


    void on_pushButton_18_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_ajouter_promotion_clicked();


    void on_comboBox_activated(const QString &arg1);

    void on_supprimer_promotion_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_lineEdit_chercher_client_cursorPositionChanged();

    void on_lineEdit_id_3_cursorPositionChanged();

    void on_pushButton_6_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_4_activated(const QString &arg1);


    void on_pushButton_3_clicked();

    void on_pushButton_consulter_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Gestion *ui;
    Clients tmpclient;
    Promotions tmppromo;
};

#endif // GESTION_H
