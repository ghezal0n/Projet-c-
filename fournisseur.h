#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseur
{ private:
    int id,numero;
    QString nom_fourni,type,adresse;


public:
    fournisseur();
    fournisseur(int,QString,QString,int,QString);


    int Getid() {return id;}
            void Setid(int val){id=val;}
    QString Getnom_fourni() { return nom_fourni; }
            void Setnom_fourni(QString val) { nom_fourni = val; }
    QString Gettype() { return type; }
            void Settype(QString val) { type = val; }
    int Getnumero(){ return numero; }
            void Setnumero (int val){numero=val;}

    QString Getadresse() { return adresse; }
            void Setadresse(QString val) { adresse = val; }

//Les fonctions CRUD
            bool ajouter();
            QSqlQueryModel*afficher();
            bool supprimer(int);
            bool modifier();
            QSqlQueryModel *combo_box();

//Les fonctions avancées
            QSqlQueryModel * tri_id();
            QSqlQueryModel * tri_nom();
            QSqlQueryModel * tri_type();
            QSqlQueryModel * tri_numero();
            QSqlQueryModel * tri_adresse();
            QSqlQueryModel * recherche_id(const QString &);
            QSqlQueryModel * recherche_nom(QString);
            QSqlQueryModel * recherche_type(QString);
            QSqlQueryModel * recherche_adresse(QString);
};

#endif // FOURNISSEUR_H
