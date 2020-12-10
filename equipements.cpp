#include "equipements.h"

equipements::equipements(){
    code="";
    description="";
    quantite=0;
    date_acq=date_acq.currentDate();
    prix=0;
}

equipements::equipements(QString code,QString description, int quantite, QDate date_acq, float prix)
{
    this->code=code;
    this->description=description;
    this->quantite=quantite;
    this->date_acq=date_acq;
    this->prix=prix;
}

bool equipements::ajouter(){
    QSqlQuery query;
    QString res= QString::number(quantite);
    QString res1= QString::number(prix);

    query.prepare("INSERT INTO equipements(code, description, quantite, date_acq, prix) "
                  "VALUES(:code ,:description ,:quantite ,:date_acq ,:prix)");
    query.bindValue(":code", code);
    query.bindValue(":description", description);
    query.bindValue(":quantite", res);
    query.bindValue(":date_acq", date_acq);
    query.bindValue(":prix",res1);

    return query.exec();
}

bool equipements::modifier(){
    QSqlQuery query;
    QString res= QString::number(quantite);
    QString res1= QString::number(prix);

    query.prepare("UPDATE equipements SET code=:code, description=:description, quantite=:quantite, date_acq=:date_acq, prix=:prix WHERE (code =:code)");
    query.bindValue(":code",code);
    query.bindValue(":description",description);
    query.bindValue(":quantite", res);
    query.bindValue(":date_acq",date_acq);
    query.bindValue(":prix", res1);

    return query.exec();
}
   QSqlQueryModel * equipements::combo_box(){
   QSqlQueryModel * model = new QSqlQueryModel();
   model->setQuery("Select code from equipements");
   return model;
}

QSqlQueryModel*equipements::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("Select * from equipements");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_acq"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
    return model;
}

bool equipements::supprimer(QString code)
{
    QSqlQuery query;
    QString res= QString(code);
    query.prepare("Delete from equipements where code = :code");
    query.bindValue(":code", res);
    return query.exec();
}

QSqlQueryModel * equipements::recherche_code(QString code){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * From equipements WHERE code ='" +code+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

    return model;
}

QSqlQueryModel * equipements::tri_code()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from equipements Order by code ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_acq"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

    return model;
}

QSqlQueryModel * equipements::tri_description()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from equipements Order by description ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_acq"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

    return model;
}

QSqlQueryModel * equipements::tri_quantite()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from equipements Order by quantite ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_acq"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

    return model;
}

QSqlQueryModel * equipements::tri_date()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from equipements Order by date_acq ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_acq"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

    return model;
}

QSqlQueryModel * equipements::tri_prix()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from equipements Order by prix ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_acq"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

    return model;
}

QSqlQueryModel * equipements::recherche_description(QString nom){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * From equipements WHERE description ='" +nom+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

    return model;
}

QSqlQueryModel * equipements::recherche_quantite(int quantite){
    QSqlQueryModel * model = new QSqlQueryModel();
    QString res = QString::number(quantite);
    model->setQuery("Select * From equipements WHERE quantite = " + res);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));

    return model;
}
