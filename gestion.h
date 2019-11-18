#ifndef GESTION_H
#define GESTION_H
#include <QDialog>
#include <QSqlQueryModel>
#include <QAbstractItemView>
#include"employe.h"
#include "shift.h"
namespace Ui{
class gestion;
}

class gestion : public QDialog
{
    Q_OBJECT

public:
    explicit gestion(QWidget *parent = nullptr);
    ~gestion();

private slots:
    void on_pushButton_clicked();

    void on_ok_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_dateEdit_dateChanged(const QDate &date);

    void on_ok_shift_clicked();


    void on_comboBox_employe_activated(const QString &arg1);

    void on_comboBox_ajoutID_activated(const QString &arg1);

    void on_comboBox_ajoutshift_activated(const QString &arg1);

    void on_comboBox_modemploye_activated(const QString &arg1);

    void on_comboBox_employe_activated(int index);

    void on_shift_sup_activated(const QString &arg1);

    void on_shif_mod_activated(const QString &arg1);

    void on_comboBox_ajoutshift_2_activated(const QString &arg1);

    void on_dateEdit_2_userDateChanged(const QDate &date);

    void on_pushButton_5_clicked();

    void on_shif_mod_activated(int index);

private:
    Ui::gestion *ui;
    employe tmpemploye;
    shift tmpsh;
    int selected=-1;
    int mod_selected=-1;
    QString NEW_date,NEW_shifft;

};

#endif // GESTION_H
