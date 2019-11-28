#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QDialog>
#include <QMap>
#include <QVector>
namespace Ui {
class statistiques;
}

class statistiques : public QDialog
{
    Q_OBJECT

public:
    explicit statistiques(QDialog *parent = nullptr);
    ~statistiques();

private:
    Ui::statistiques *ui;
};


#endif // STATISTIQUES_H
