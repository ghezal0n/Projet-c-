#include "poste.h"
#include <QString>
#include <QSqlQuery>
#include <QDebug>


poste::poste()
{
     id="";
     grade="";
     avantage="";
     horaire="";
     salaire="";

}
poste::poste(QString id,QString grade,QString avantage,QString horaire,QString salaire )
{
    this->id=id;
    this->grade=grade;
    this->avantage=avantage;
    this->horaire=horaire;
    this->salaire=salaire;
  }
 bool poste::ajouter(){
    QSqlQuery query;
    //QString
    query.prepare("insert into poste (ID,GRADE,AVANTAGE,HORAIRE,SALAIRE )" "values (:id, :grade, :avantage, :horaire, :salaire)");
    query.bindValue(":id",id);
    query.bindValue(":grade",grade);
    query.bindValue(":avantage",avantage);
    query.bindValue(":horaire",horaire);
    query.bindValue(":salaire",salaire);


    return    query.exec();
}

QSqlQueryModel * poste::afficher(){
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from poste");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("grade"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("avantage"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("horaire"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));

     return model;
}

bool poste::supprimer(QString idp)
{
    QSqlQuery query;
    query.prepare("Delete from poste where ID = :id");
    query.bindValue(":id", idp);
    return    query.exec();
}
bool poste::modifier(QString idp)
{    QSqlQuery query;
     qDebug()<<idp;

     query.prepare("UPDATE poste SET GRADE=:grade ,AVANTAGE=:avantage ,HORAIRE=:horaire ,SALAIRE=:salaire where ID = :idp");
     query.bindValue(":idp",idp);
     query.bindValue(":grade",grade);
     query.bindValue(":avantage",avantage);
     query.bindValue(":horaire",horaire);
     query.bindValue(":salaire",salaire);
     return    query.exec();
}
QSqlQueryModel * poste::afficherid(){
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select id  from poste");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     return model;
 }
QSqlQueryModel * poste::affichergrade(){
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select grade from poste");

    model->setHeaderData(1, Qt::Horizontal, QObject::tr("grade"));

    return model;
}

QSqlQueryModel *   poste::recherche(QString value)
{
    QSqlQueryModel * model = new QSqlQueryModel();


    model->setQuery("select * from POSTE WHERE id||GRADE||AVANTAGE||HORAIRE||SALAIRE LIKE '%"+value+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("grade"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("avantage"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("horaire"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));

    return model;
}

QSqlQueryModel *  poste::trier(QString critere,QString mode )
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from poste order by "+critere+" "+mode+"" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("grade"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("avantage"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("horaire"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));

  return model;
}

QSqlQuery * poste::recherche_id(QString id)
{
    QSqlQuery * model = new QSqlQuery();
    model->prepare("select * from poste WHERE id LIKE "+id+"");
    model->exec();
    qDebug()<<id;
    return model;
}

