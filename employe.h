#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
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
QT_CHARTS_USE_NAMESPACE
class Employe
{
private:

    QString id,nom,prenom,poste,telephone,ddn;
 public:
    Employe();
    Employe(QString,QString,QString,QString,QString,QString);

    QString getid(){return id;}
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getpost(){return poste;}
    QString gettelephone(){return telephone;}
    QString getddn(){return ddn;}

    void setid(QString id){this->id=id;}
    void setnom(QString nom){this->nom=nom;}
    void setprenom(QString prenom){this->prenom=prenom;}
    void setposte(QString poste){this->poste=poste;}
    void settelephone(QString telephone){this->telephone=telephone;}
    void setddn(QString ddn){this->ddn=ddn;}

    bool ajouter();
    bool supprimer(QString);
    bool modifier (QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherid();
    QSqlQueryModel * recherche_id (QString);
    QSqlQueryModel * trier(QString,QString);
    QSqlQuery * recherche_id2(QString);
    QChartView * statistique();
    QChartView * statistique2();

    QVector <QString> getinforamation(QString);
};

#endif // EMPLOYE_H
