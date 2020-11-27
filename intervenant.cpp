#include "intervenant.h"

intervenat::intervenat(){
    email="";
    nom="";
    prnom="";
   idd=0;
   gsm=0;

}
intervenat::intervenat(int a ,QString b ,QString c ,int d ,QString f )
{

     email=f;
     nom=b;
     prnom=c;
    idd=a;
    gsm=d;

 }
bool intervenat::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(idd);
    QString res1= QString::number(gsm);
    query.prepare("INSERT INTO inter (ID,NOM,PRENOM,GSM,EMAIL) VALUES (:idd,:nom,:prnom,:gsm,:email)");
    query.bindValue(":idd",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prnom",prnom);
    query.bindValue(":gsm",res1);
    query.bindValue(":email",email);

    return    query.exec();
}
QSqlQueryModel * intervenat::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from inter ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));

    return model;
}
QSqlQueryModel * intervenat::combo_box(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select ID from inter");
    return model;
}
bool intervenat::modifier()
{


    QSqlQuery query;
    QString res= QString::number(idd);
    QString res1= QString::number(gsm);
    query.prepare("UPDATE inter SET nom=:nom, prenom=:prnom , gsm=:gsm , email=:email where id =:idd") ;
    query.bindValue(":idd",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prnom",prnom);
    query.bindValue(":gsm",res1);
    query.bindValue(":email",email);

    return    query.exec();
}
bool intervenat::supprimer(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from inter where ID =:idd");
    query.bindValue(":idd", res);
    return query.exec();
}
QSqlQueryModel * intervenat::cherchernom(const QString &type)
{
     QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from inter where NOM like '" + type + "%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));

    return model;
}
QSqlQueryModel * intervenat::chercherprenom(const QString &type)
{
     QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from inter where prenom like '" + type + "%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));

    return model;
}
QSqlQueryModel * intervenat::cherchergsm(const QString &type)
{
     QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from inter where gsm like '" + type + "%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));

    return model;
}
QSqlQueryModel * intervenat::trier1()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM inter\
                        ORDER BY NOM ");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
      return  model;
}
QSqlQueryModel * intervenat::trier2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM inter\
                        ORDER BY NOM DESC");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
      return  model;
}
QSqlQueryModel * intervenat::trier3()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM inter\
                        ORDER BY prenom ");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
      return  model;
}
QSqlQueryModel * intervenat::trier4()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM inter\
                        ORDER BY prenom DESC");

                      model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
                      model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
                      model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
                      model->setHeaderData(3, Qt::Horizontal, QObject::tr("GSM"));
                      model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
      return  model;
}
QSqlQueryModel * intervenat::combo_box1(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select email from inter");
    return model;
}
