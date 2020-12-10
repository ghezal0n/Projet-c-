#include "employe.h"
#include <QString>
#include <QSqlQuery>
#include <QDebug>

Employe::Employe()
{
    id="";
    nom="";
    prenom="";
    telephone="";
    poste="";
    ddn="";
}
Employe::Employe(QString id,QString nom ,QString prenom,QString poste,QString telephone ,QString ddn){//const
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->telephone=telephone;
    this->poste=poste;
    this->ddn=ddn;
}


bool Employe::ajouter(){
    QSqlQuery query;
    //QString
    query.prepare("insert into employe (ID, NOM, PRENOM, POSTE, TELEPHONE, DDE )" "values (:id, :nom, :prenom, :poste, :telephone, :ddn)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":poste",poste);
    query.bindValue(":telephone",telephone);
    query.bindValue(":ddn",ddn);

    return    query.exec();
}

QSqlQueryModel * Employe::afficher(){
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from employe");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("poste"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("ddn"));

     return model;
}

bool Employe::supprimer(QString idE)
{
    QSqlQuery query;
    query.prepare("Delete from employe where ID = :id");
    query.bindValue(":id", idE);
    return    query.exec();
}
bool Employe ::modifier(QString idp)
{    QSqlQuery query;


     query.prepare("UPDATE employe SET NOM=:nom ,PRENOM=:prenom ,POSTE=:poste ,TELEPHONE=:telephone, DDE=:dde  where ID = :idp");
      query.bindValue(":idp",idp);
      query.bindValue(":nom",nom);
      query.bindValue(":prenom",prenom);
      query.bindValue(":poste",poste);
      query.bindValue(":telephone",telephone);
       query.bindValue(":dde",ddn);


        return    query.exec();
}
QSqlQueryModel * Employe::afficherid(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select id  from employe");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    return model;
}


 QSqlQueryModel *   Employe::recherche_id(QString val)
 {
     QSqlQueryModel * model = new QSqlQueryModel();

     model->setQuery("select * from employe WHERE id||NOM||PRENOM||POSTE||TELEPHONE||DDE LIKE '%"+val+"%'");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("poste"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("ddn"));

     return model;
 }

QSqlQueryModel *  Employe::trier(QString critere ,QString mode)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from employe order by "+critere+" "+mode+"");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("poste"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ddn"));

  return model;
}

QSqlQuery * Employe::recherche_id2(QString id)
{
    QSqlQuery * model = new QSqlQuery();
    model->prepare("select * from employe WHERE id LIKE "+id+"");
    model->exec();
    qDebug()<<id;
    return model;
}

QVector <QString> Employe::getinforamation(QString id){
    QSqlQuery query,query2;
    QString  nom ,prenom,poste, salaire;
    QVector <QString> information;
    query.prepare("select * from employe WHERE id LIKE "+id+"");
    query.exec();

     while(query.next()){
        nom= query.value(1).toString();
        prenom =query.value(2).toString();
        poste = query.value(3).toString();
     }

     query2.prepare("select salaire from poste WHERE grade LIKE :id");
     query2.bindValue(":id",poste);
     query2.exec();
     while(query2.next()){
       salaire= query2.value(0).toString();
     }

     information.push_back(nom);
     information.push_back(prenom);
     information.push_back(poste);
     information.push_back(salaire);

     return  information;
}

QChartView * Employe::statistique(){

        QPieSeries *series = new QPieSeries();
        QSqlQuery query,query2;
        query.prepare("select grade from poste");
        query.exec();
        int nb=0;
        QVector <QString> grade;
        QVector <QPieSlice *> slicee ;
        qDebug()<<grade.length();
         while(query.next())
         {
             grade.push_back(query.value(0).toString());
         }
                for(int k=0;k<grade.length();k++){
                     query2.prepare("select poste from employe where poste like :val");
                     query2.bindValue(":val",grade.at(k));
                    query2.exec();
                    while(query2.next()){
                        nb++;
                 }
                series->append(grade.at(k),nb);
                nb=0;
                query2.clear();
                    slicee.push_back(series->slices().at(k));
                    slicee.at(k)->setLabelVisible();
                }
        // Add label to 1st slice
        // Create the chart widget
        QChart *chart = new QChart();

        // Add data to chart with title and hide legend
        chart->addSeries(series);
        chart->setTitle("poste/employe");
        chart->legend()->hide();

        // Used to display the chart
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

     return chartView;
}
QChartView * Employe::statistique2(){

           // Assign names to the set of bars used
            QBarSet *set0 = new QBarSet("grade");
            QSqlQuery query,query2;
            query.prepare("select grade from poste");
            query.exec();
               int nb=0;
               // Holds the category titles
            QStringList categories;

            while(query.next())
            {
               categories.push_back(query.value(0).toString());
            }
            for(int k=0;k<categories.length();k++){
                 query2.prepare("select poste from employe where poste like :val");
                 query2.bindValue(":val",categories.at(k));
                 query2.exec();
                 //il y a encore des donnes , next
                while(query2.next()){
                    nb++;
                }
            set0->insert(k,nb);
            nb=0;
            }


        // Assign values for each bar


       // Add all sets of data to the chart as a whole
       // 1. Bar Chart
       QBarSeries *series = new QBarSeries();

       // 2. Stacked bar chart
       // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
       series->append(set0);

       // Used to define the bar chart to display, title
       // legend,
       QChart *chart = new QChart();

       // Add the chart
       chart->addSeries(series);

       // Set title
       chart->setTitle("nombre d'employee par grade");

       // Define starting animation
       // NoAnimation, GridAxisAnimations, SeriesAnimations
       chart->setAnimationOptions(QChart::AllAnimations);



       // Adds categories to the axes
       QBarCategoryAxis *axis = new QBarCategoryAxis();
       axis->append(categories);
       chart->createDefaultAxes();

       // 1. Bar chart
       chart->setAxisX(axis, series);

       // 2. Stacked Bar chart
       // chart->setAxisY(axis, series);

       // Define where the legend is displayed
       chart->legend()->setVisible(true);
       chart->legend()->setAlignment(Qt::AlignBottom);

       // Used to display the chart
       QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);


       return chartView;


}

