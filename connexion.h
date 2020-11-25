#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QApplication>

class Connection
{
private:
    QSqlDatabase db;
public:
    Connection();
    void fermerConnection();
    bool createconnect();
};

#endif // CONNEXTION_H



