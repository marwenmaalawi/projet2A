#include "statistiques.h"
#include "connexion.h"
#include <QMap>
#include <QVector>
#include <QString>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QGridLayout>
#include "ui_statistiques.h"
#include <QSqlQuery>
#include <QDebug>
#include <QDialog>
QT_CHARTS_USE_NAMESPACE
statistiques::statistiques(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::statistiques)
{
    ui->setupUi(this);
    QVector <QPieSlice *> tab;
        QPieSeries *series = new QPieSeries();
        QSqlQuery qry;
        int tous=0;
        int etrangere=0;
        int tunisienne=0;

        qry.prepare("select * from clients ");
        if (qry.exec())
        {

            while (qry.next())
            {

    tous++;

    if(qry.value(3)=="tunisienne")
    {
        tunisienne++;
    }
    else if(qry.value(3)!="tunisienne")
    {
        etrangere++;
    }


            }
        }


        qDebug () << " " << etrangere;
            qDebug () << " " << tunisienne;


float testing1 =(etrangere*100)/tous;
float testing2 =100-testing1;
QString pleasework = QString::number(testing1);
QString pleaseworks= QString::number(testing2);
    series ->append("etrangere "+pleasework+"%",(etrangere));
        series ->append("tunisienne "+pleaseworks+"%",(tunisienne));


QPieSlice * slice0= series->slices().at(0);
slice0->setLabelVisible();
QPieSlice * slice1= series->slices().at(1);
slice1->setLabelVisible();

    if (etrangere>tunisienne)
    {

       slice0->setExploded();
        slice0->setPen(QPen(Qt::darkGreen,2));
       slice0->setBrush(Qt::red);

    }
    else
    {

 slice1->setExploded();
  slice1->setPen(QPen(Qt::darkGreen,2));
 slice1->setBrush(Qt::red);
    }





    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("etat produit  : ");
    chart->legend()->hide();



                QChartView *chartview = new QChartView (chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        QGridLayout *mainLayout = new QGridLayout;
            mainLayout->addWidget(chartview, 1, 1);
            setLayout(mainLayout);


}

statistiques::~statistiques()
{
    delete ui;
}
