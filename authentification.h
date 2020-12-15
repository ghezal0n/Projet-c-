#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H
#include "mainwindow.h"
#include <QDialog>
#include <QApplication>
namespace Ui {
class authentification;
}

class authentification : public QDialog
{
    Q_OBJECT

public:
    explicit authentification(QWidget *parent = nullptr);
    ~authentification();

private slots:
    void on_connexion_clicked();

private:
    Ui::authentification *ui;
    MainWindow w;
};

#endif // AUTHENTIFICATION_H
