#ifndef POSTE_H
#define POSTE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class poste
{
private:
    QString id,grade,horaire,avantage,salaire;
public:
    poste();
    poste(QString,QString,QString,QString,QString);

    QString getid(){return id;}
    QString getgrade(){return grade;}
    QString gethoraire(){return horaire;}
    QString getavantage(){return avantage;}
    QString getsalaire(){return salaire;}



    void setid(QString id){this->id=id;}
    void setnom(QString grade){this->grade=grade;}
    void setprenom(QString horaire ){this->horaire=horaire;}
    void setposte(QString aventage ){this->avantage=aventage;}
    void settelephone(QString salaire){this->salaire=salaire;}


    bool ajouter();
    bool supprimer(QString);
    bool modifier (QString);
    QSqlQueryModel * recherche(QString);
    QSqlQueryModel * afficherid();
    QSqlQueryModel * afficher();
    QSqlQueryModel * affichergrade();
    QSqlQueryModel * trier(QString,QString);
    QSqlQuery * recherche_id(QString);



};

#endif // POSTE_H

