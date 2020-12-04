#include "stat.h"
#include <QDebug>
#include <algorithm>
using namespace  std;
Stat::Stat()
{



}
QChartView * Stat::Preparechart()
{
    QSqlQuery query;
       int count1=0;
       int count2=0;
       int count3=0;

       if(query.exec("select type from parking"))
       {
           while(query.next())
             {
                if(query.value(0).toString()=="public"){
                    count1++; }
                else if(query.value(0).toString()=="privé"){
                    count2++;}
                else if(query.value(0).toString()=="privé à usage public"){
                    count3++;}
              }
        }
       QPieSeries *Series;
       Series = new QPieSeries();
       Series->append("public", count1);
       Series->append("privé", count2);
       Series->append("privé à usage public", count3);
       Series->setLabelsVisible();
       Series->setLabelsPosition(QPieSlice::LabelOutside);
       for(auto slice : Series->slices())
           slice->setLabel(QString("%1 %2%").arg(slice->label()).arg(100*slice->percentage(), 0, 'f', 1));
       QChart *chart = new QChart();
       chart->addSeries(Series);
       chart->setTitle("Les types de parking");
       QChartView *chartView = new QChartView(chart);
       //chartView->setRenderHint(QPainter::TextAntialiasing);
       chartView->setRenderHint(QPainter::Antialiasing);
       QChart::ChartTheme theme = QChart::ChartThemeBlueIcy ;
       chartView->chart()->setTheme(theme);


       return chartView;
    }






