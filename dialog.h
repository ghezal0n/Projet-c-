#ifndef DIALOG_H
#define DIALOG_H
#include "intervenant.h"
#include <QDialog>
#include "mainwindow.h"
#include "QCompleter"
#include "QDirModel"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    MainWindow w;


private slots:
    void on_pushButton_envoyer_clicked();

    void on_comboBox_5_activated(const QString &arg1);

private:
    Ui::Dialog *ui;
    QCompleter *Stringcompleter;
    QCompleter *Modelcompletere;
};

#endif // DIALOG_H
