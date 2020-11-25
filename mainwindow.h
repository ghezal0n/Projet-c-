#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "chantier.h"
#include "intervenant.h"
#include <QMainWindow>
#include "QMediaPlayer"
#include "QMediaPlaylist"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void display_listes();
    void playaudio();


private slots:
    void on_pushButton_clicked();

    void on_modifierchantier_clicked();

    void on_id_chmo_activated(const QString &arg1);


    void on_tabchantier_activated(const QModelIndex &index);

    void on_supprimerchantier_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_modifierchantier_3_clicked();

    void on_pushButton_4_toggled(bool checked);

    void on_pushButton_4_clicked();

    void on_supprimerchantier_3_clicked();

    void on_tabcha_activated(const QModelIndex &index);

    void on_pb_ok1_clicked();

    void on_pushButton_5_toggled(bool checked);

    void on_pb_ok1_2_clicked();

    void on_pushButton_6_toggled(bool checked);

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_4_activated(const QString &arg1);


    void on_pushButton_envoyer_clicked();

    void on_comboBox_5_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    chantier tmp_chantier;
    intervenat tmp_inter;
    QMediaPlaylist* music1;
    QMediaPlayer* music;
};
#endif // MAINWINDOW_H



