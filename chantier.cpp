#include "chantier.h"
#include <QComboBox>
chantier::chantier()
{
    id_chantier=0;
    adresse="***";
    surface_de_terrain=0;
    budget=0;
}

chantier::chantier(int id_chantier,QString adresse,int surface_de_terrain,int budget,QDate date_limite)
{
    this->id_chantier=id_chantier;
    this->adresse=adresse;
    this->surface_de_terrain=surface_de_terrain;
    this->budget=budget;
    this->date_limite=date_limite;
}

bool chantier::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id_chantier);
    QString res1= QString::number(surface_de_terrain);
    QString res2= QString::number(budget);

    query.prepare("INSERT INTO chantier (ID_CHANTIER,adresse,surface_de_terrain,budget,date_limite) VALUES (:id_chantier,:adresse,:surface_de_terrain,:budget,:date_limite)");
    query.bindValue(":id_chantier",res);
    query.bindValue(":adresse",adresse);
    query.bindValue(":surface_de_terrain",res1);
    query.bindValue(":budget",res2);
    query.bindValue(":date_limite",date_limite);

    return    query.exec();
}

QSqlQueryModel * chantier::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from chantier ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface de terrain"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("budget"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date limite"));

    return model;
}
bool chantier::modifier()
{

    QSqlQuery query;
    QString res= QString::number(this->id_chantier);
    QString res1= QString::number(this->surface_de_terrain);
    QString res2= QString::number(this->budget);
    query.prepare("UPDATE chantier SET adresse=:adresse,surface_de_terrain=:surface_de_terrain,budget=:budget,date_limite=:date_limite WHERE id_chantier=:id_chantier") ;
    query.bindValue(":id_chantier",res);
    query.bindValue(":adresse",adresse);
    query.bindValue(":surface_de_terrain",res1);
    query.bindValue(":budget",res2);
    query.bindValue(":date_limite",date_limite);

    return    query.exec();
}
QSqlQueryModel * chantier::combo_box(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select ID_CHANTIER from chantier");
    return model;
}
bool chantier::supprimer(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from chantier where ID_CHANTIER =:id_chantier");
    query.bindValue(":id_chantier", res);
    return query.exec();
}
QSqlQueryModel * chantier::chercher(const QString &type)
{
     QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from chantier where adresse like '" + type + "%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface de terrain"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("budget"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date limite"));

    return model;
}
QSqlQueryModel * chantier::chercherbug(const QString &type)
{
     QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from chantier where budget like '" + type + "%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface de terrain"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("budget"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date limite"));

    return model;
}
QSqlQueryModel * chantier::cherchersur(const QString &type)
{
     QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from chantier where surface_de_terrain like '" + type + "%' ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface de terrain"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("budget"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date limite"));

    return model;
}
QSqlQueryModel * chantier::trier_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM chantier\
                        ORDER BY id_chantier ");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface de terrain"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("budget"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date limite"));
      return  model;
}
QSqlQueryModel * chantier::trier_id1()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM chantier\
                        ORDER BY id_chantier DESC");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface de terrain"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("budget"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date limite"));
      return  model;
}
QSqlQueryModel * chantier::trier_id2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM chantier\
                        ORDER BY surface_de_terrain ");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface de terrain"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("budget"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date limite"));
      return  model;
}
QSqlQueryModel * chantier::trier_id3()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM chantier\
                        ORDER BY surface_de_terrain DESC");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface de terrain"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("budget"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date limite"));
      return  model;
}
QSqlQueryModel * chantier::trier_id4()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM chantier\
                        ORDER BY budget ");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface de terrain"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("budget"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date limite"));
      return  model;
}
QSqlQueryModel * chantier::trier_id5()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM chantier\
                        ORDER BY budget DESC");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface de terrain"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("budget"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date limite"));
      return  model;
}
QSqlQueryModel * chantier::trier_id6()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM chantier\
                        ORDER BY date_limite ");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface de terrain"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("budget"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date limite"));
      return  model;
}
QSqlQueryModel * chantier::trier_id7()
{
    QSqlQueryModel * model= new QSqlQueryModel();

      model->setQuery("SELECT * FROM chantier\
                        ORDER BY date_limite DESC");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("surface de terrain"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("budget"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date limite"));
      return  model;
}

