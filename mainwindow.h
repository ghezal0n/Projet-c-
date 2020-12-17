#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtSql/QSqlDatabase>
#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include "fournisseur.h"
#include "equipements.h"
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>

QT_BEGIN_NAMESPACE
QT_CHARTS_USE_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void refresh();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_modifier_clicked();

    void on_modifier_equi_clicked();

    void on_supprimer_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_supprimer_equi_clicked();

    void on_comboBox_4_activated(const QString &arg1);

    void on_chercher_equi_clicked();

    void on_pushButton_3_clicked();

    void on_pb_ok1_clicked();

    void on_actualiser_clicked();

   // void on_tabWidget_3_tabBarClicked(int index);

    void on_tabWidget_3_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
    fournisseur f;
    equipements e1;
};
#endif // MAINWINDOW_H
