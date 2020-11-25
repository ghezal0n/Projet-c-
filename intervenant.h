#ifndef INTERVENANT_H
#define INTERVENANT_H


#include <QMainWindow>
#include <QObject>
#include <QSharedDataPointer>
#include <QWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QDebug>
#include <QDateEdit>



class intervenat {

    QString email,nom,prnom;
    int idd,gsm;

public :
    intervenat();
    intervenat(int,QString,QString,int,QString);

    int getID(){return idd;}
    QString getNOM(){return nom;}
    QString getPRNOM(){return prnom;}
    int getGSM(){return gsm;}
    QString getMAIL(){return email;}

     /*void setID(int a){idd=a;}
     void setnom(QString b){nom=b;}
     void setprnom(QString c){prnom=c;}
     void setgsm(int d){gsm=d;}
     void setmail(QString e){email=e;}*/

    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier();
    QSqlQueryModel * combo_box();
    bool supprimer(int);
    QSqlQueryModel * cherchernom(const QString &);
    QSqlQueryModel * chercherprenom(const QString &type);
    QSqlQueryModel * cherchergsm(const QString &type);
    QSqlQueryModel * trier1();
    QSqlQueryModel * trier2();
    QSqlQueryModel * trier3();
    QSqlQueryModel * trier4();




};














#endif // INTERVENANT_H
