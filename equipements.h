#ifndef EQUIPEMENTS_H
#define EQUIPEMENTS_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class equipements
{ private:
    int quantite;
    QString code,description;
    QDate date_acq;
    float prix;

public:
    equipements();
    equipements(QString,QString,int,QDate,float);

    QString Getcode() {return code;}
            void Setcode(QString val){code=val;}
    QString Getdescription() { return description; }
            void Setdescription(QString val) { description = val; }
    int Getquantite(){ return quantite; }
            void Setquantite (int val){quantite=val;}
    QDate Getdate_acq() { return date_acq; }
            void Setdate_acq(QDate val) { date_acq = val; }
    float Getprix() {return prix;}
            void Setprix(float val) { prix = val; }


//Les fonctions CRUD
            bool ajouter();
            QSqlQueryModel*afficher();
            bool supprimer(QString);
            bool modifier();
            QSqlQueryModel * combo_box();
//Les fonctions avancées
            QSqlQueryModel * tri_code();
            QSqlQueryModel * tri_description();
            QSqlQueryModel * tri_quantite();
            QSqlQueryModel * tri_date();
            QSqlQueryModel * tri_prix();
            QSqlQueryModel * recherche_code(QString);
            QSqlQueryModel * recherche_description(QString);
            QSqlQueryModel * recherche_quantite(int);

};
#endif // EQUIPEMENTS_H
