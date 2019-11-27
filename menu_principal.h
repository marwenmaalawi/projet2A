#ifndef MENU_PRINCIPAL_H
#define MENU_PRINCIPAL_H


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class menu_principal; }
QT_END_NAMESPACE

class menu_principal : public QMainWindow
{
    Q_OBJECT

public:
    menu_principal(QWidget *parent = nullptr);
    ~menu_principal();

private slots:
    void on_pushButton_clicked();

private:
    Ui::menu_principal *ui;
};
#endif // MENU_PRINCIPAL_H
