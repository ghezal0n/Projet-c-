#include "fournisseur.h"
fournisseur::fournisseur(){
    id=0;
    nom_fourni="";
    type="";
    numero=0;
    adresse="";
}

fournisseur::fournisseur(int id, QString nom_fourni, QString type, int numero, QString adresse)
{
    this->id=id;
    this->nom_fourni=nom_fourni;
    this->type=type;
    this->numero=numero;
    this->adresse=adresse;
}

bool fournisseur::ajouter(){
    QSqlQuery query;
    QString res= QString::number(id);
    QString res2= QString::number(numero);
    query.prepare("INSERT INTO fournisseur (id, nom_fourni, type, numero, adresse) "
                        "VALUES (:id ,:nom_fourni ,:type ,:numero ,:adresse)");
    query.bindValue(":id", res);
    query.bindValue(":nom_fourni", nom_fourni);
    query.bindValue(":type", type);
    query.bindValue(":numero", res2);
    query.bindValue(":adresse", adresse);

    return query.exec();

}

bool fournisseur::modifier(){
    QSqlQuery query;
    QString res= QString::number(id);
    QString res1= QString::number(numero);

    query.prepare("UPDATE fournisseur SET id=:id, nom_fourni=:nom_fourni, type=:type, numero=:numero, adresse=:adresse WHERE (id =:id)");
    query.bindValue(":id", res);
    query.bindValue(":nom_fourni",nom_fourni);
    query.bindValue(":type",type);
    query.bindValue(":numero",res1);
    query.bindValue(":adresse",adresse);

    return query.exec();
}

QSqlQueryModel * fournisseur::combo_box(){
QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("Select id from fournisseur");
return model;
}

QSqlQueryModel*fournisseur::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("Select * from fournisseur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom fournisseur"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numero tel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse local"));
    return model;
}

bool fournisseur::supprimer(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("Delete from fournisseur where id = :id");
    query.bindValue(":id", res);
    return query.exec();
}

QSqlQueryModel * fournisseur::tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * From fournisseur ORDER BY id ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_fourni"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}

QSqlQueryModel * fournisseur::tri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * From fournisseur ORDER BY nom_fourni ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_fourni"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}

QSqlQueryModel * fournisseur::tri_type()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * From fournisseur ORDER BY type ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_fourni"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}

QSqlQueryModel * fournisseur::tri_numero()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * From fournisseur ORDER BY numero ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_fourni"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}

QSqlQueryModel * fournisseur::tri_adresse()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * From fournisseur ORDER BY adresse ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_fourni"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}


QSqlQueryModel * fournisseur::recherche_id(const QString &id){
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("Select * From fournisseur WHERE id like '" +id+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_fourni"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("categirie"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}

QSqlQueryModel * fournisseur::recherche_nom(QString nom){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * From fournisseur WHERE nom_fourni ='" +nom+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_fourni"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}

QSqlQueryModel * fournisseur::recherche_type(QString type){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * From fournisseur WHERE type ='" +type+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_fourni"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}

QSqlQueryModel * fournisseur::recherche_adresse(QString adresse){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("Select * From fournisseur WHERE adresse ='" +adresse+"'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_fourni"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}

