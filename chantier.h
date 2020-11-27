#ifndef CHANTIER_H
#define CHANTIER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDebug>
#include <QDateEdit>



class chantier {

    QString adresse;
    QDate date_limite;
    int id_chantier,surface_de_terrain,budget;

public :
    chantier();
    chantier(int,QString,int,int,QDate);

    int getID(){return id_chantier;}
    int getSUR(){return surface_de_terrain;}
    int getBUDGET(){return budget;}
    QString getAD(){return adresse;}
    QDate getdate(){return date_limite;}

     void setID(int a){id_chantier=a;}
     void setSUR(int b){surface_de_terrain=b;}
     void setBUDGET(int c){budget=c;}
     void setAD(QString d){adresse=d;}
     void setdate(QDate e){date_limite=e;}

    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier();
    QSqlQueryModel * combo_box();

    bool supprimer(int);
    QSqlQueryModel * chercher(const QString &);
    QSqlQueryModel * chercherbug(const QString &);
    QSqlQueryModel * cherchersur(const QString &);
    QSqlQueryModel * trier_id();
    QSqlQueryModel * trier_id1();
    QSqlQueryModel * trier_id2();
    QSqlQueryModel * trier_id3();
    QSqlQueryModel * trier_id4();
    QSqlQueryModel * trier_id5();
    QSqlQueryModel * trier_id6();
    QSqlQueryModel * trier_id7();
};


















#endif // CHANTIER_H
