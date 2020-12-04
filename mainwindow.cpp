#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chantier.h"
#include <QMessageBox>
#include <QApplication>
#include <QSqlQuery>
#include <QDebug>
#include <QCoreApplication>
#include <QSqlQueryModel>
#include <QComboBox>
#include "intervenant.h"
#include "QMediaPlayer"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "mailing/SmtpMime"
#include <stdio.h>
#include <string.h>
#include "dialog.h"
#include <QtPrintSupport>
#include <QPrintDialog>
#include <QGraphicsView>
#include "parking.h"
#include <QVBoxLayout>
#include "stat.h"
#include <QtCharts>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QStandardItemModel>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    /*  **************sout*******************  */
    ui->pushButton_4->setIcon((QIcon(":/images/on.png")));
    ui->pushButton_4->setIconSize(ui->pushButton_4->size());
    ui->pushButton_4->setCheckable(true);
    /*  **************ajout*******************  */
    ui->pushButton_2->setIcon((QIcon(":/images/7.png")));
    ui->pushButton_2->setIconSize(ui->pushButton_2->size());
    ui->pushButton->setIcon((QIcon(":/images/9.png")));
    ui->pushButton->setIconSize(ui->pushButton->size());
    /*  **************modif*******************  */
    ui->modifierchantier->setIcon((QIcon(":/images/1.png")));
    ui->modifierchantier->setIconSize(ui->modifierchantier->size());
    ui->modifierchantier_3->setIcon((QIcon(":/images/1.png")));
    ui->modifierchantier_3->setIconSize(ui->modifierchantier_3->size());
    /*  **************tafsi5*******************  */
    ui->supprimerchantier_3->setIcon((QIcon(":/images/3.png")));
    ui->supprimerchantier_3->setIconSize(ui->supprimerchantier_3->size());
    ui->supprimerchantier->setIcon((QIcon(":/images/3.png")));
    ui->supprimerchantier->setIconSize(ui->supprimerchantier->size());
    /*  ******************tabs*******************  */
    ui->tabchantier->setModel(tmp_chantier.afficher());
    ui->tabcha->setModel(tmp_inter.afficher());
    ui->tabcha_2->setModel(tmp_parking.afficher());

    /*  ************************************************  */
    music1 =new QMediaPlaylist();
    music1->addMedia(QUrl("qrc:/images/backgmusic.mp3"));
    music1->setPlaybackMode(QMediaPlaylist::Loop);
    music = new QMediaPlayer();
    music->setPlaylist(music1);
    music->play();
    music->setVolume(10);
    /*  **************refresh*******************  */
    ui->pushButton_5->setIcon((QIcon(":/images/refresh1.png")));
    ui->pushButton_5->setIconSize(ui->pushButton_5->size());
    ui->pushButton_5->setCheckable(true);
    ui->pushButton_6->setIcon((QIcon(":/images/refresh1.png")));
    ui->pushButton_6->setIconSize(ui->pushButton_6->size());
    ui->pushButton_6->setCheckable(true);
    ui->pushButton_22->setIcon((QIcon(":/images/refresh1.png")));
    ui->pushButton_22->setIconSize(ui->pushButton_22->size());
    ui->pushButton_22->setCheckable(true);
    /*  **************recher*******************  */
    ui->pb_ok1->setIcon((QIcon(":/images/4.png")));
    ui->pb_ok1->setIconSize(ui->pb_ok1->size());
    ui->pb_ok1_2->setIcon((QIcon(":/images/4.png")));
    ui->pb_ok1_2->setIconSize(ui->pb_ok1_2->size());
    /*  **************anu*******************  */
    ui->pushButton_3->setIcon((QIcon(":/images/60578.png")));
    ui->pushButton_3->setIconSize(ui->pushButton_3->size());
    ui->pushButton_7->setIcon((QIcon(":/images/60578.png")));
    ui->pushButton_7->setIconSize(ui->pushButton_7->size());
    ui->pushButton_8->setIcon((QIcon(":/images/60578.png")));
    ui->pushButton_8->setIconSize(ui->pushButton_8->size());
    ui->pushButton_9->setIcon((QIcon(":/images/60578.png")));
    ui->pushButton_9->setIconSize(ui->pushButton_9->size());

    mainLayout=new QVBoxLayout ;
    mainLayout->addWidget(s.Preparechart());
    ui->widget->setLayout(mainLayout);







}

MainWindow::~MainWindow()
{
    delete ui;
    delete music;
    delete mainLayout;
}
void MainWindow::display_listes()
{
    ui->tabchantier->setModel(tmp_chantier.afficher());
    ui->id_chmo->setModel(tmp_chantier.combo_box());
    ui->tabcha->setModel(tmp_inter.afficher());
    ui->comboBox_2->setModel(tmp_inter.combo_box());
    ui->tabcha_2->setModel(tmp_parking.afficher());
    ui->comboBox_6->setModel(tmp_parking.combo_box());
    ui->widget->setLayout(mainLayout);
    refresh_stat();
}
void MainWindow::refresh_stat()
{
    if ( ui->widget->layout() != NULL )
    {
    QLayoutItem* item;
    while ( ( item = ui->widget->layout()->takeAt( 0 ) ) != NULL )
    {
    delete item->widget();
    delete item;
    }
    delete ui->widget->layout();
    }
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(s.Preparechart());
    ui->widget->setLayout(mainLayout);
}
void MainWindow::playaudio()
{

    QMediaPlayer * music =new QMediaPlayer();
    music->setMedia(QUrl("qrc:/images/Click2.mp3"));
    music->play();
}




void MainWindow::on_pushButton_clicked()
{
    int i=ui->lineeditid->text().toInt();
    QString p=ui->lineEditadres->text();
    int k=ui->lineEditsurface->text().toInt();
    int l=ui->lineEditbudget->text().toInt();
    QDate d= ui->dateEdit->date();
    chantier c(i,p,k,l,d);


    if ((i!='\0')&&(p!='\0')&&(k!='\0')&&(l!='\0'))
    {

    bool test = c.ajouter();
    if(test)

    {
        display_listes();
        playaudio();
        QMessageBox::information(nullptr,("Ajout chantier"),("chantier ajouté"));}
else
     {QMessageBox::warning(nullptr,("Ajout chantier"),("chantier non ajouté"));}
    }

    else QMessageBox::warning(nullptr,("Ajout chantier"),("pas de données"));


 }

void MainWindow::on_modifierchantier_clicked()
{

    int i=ui->id_chmo->currentText().toInt();
    QString b=ui->ad_chmo->text();
    int e=ui->sur_chmo->text().toInt();
    int f=ui->bud_chmo->text().toInt();
    QDate d= ui->date_chmo->date();
    chantier c(i,b,e,f,d);
    bool test=c.modifier();
    if(test)
    {
         display_listes();
         playaudio();
        QMessageBox::information(nullptr, QObject::tr("Modifier un chantier"),
                    QObject::tr("chantier modifier modifié.\n"
                                "Cliquez sur Ok pour continuer."), QMessageBox::Ok);
    }
    else

       QMessageBox::critical(nullptr, QObject::tr("Modifier un chantier"),
                   QObject::tr("Erreur!\n"
                               "Erreur de modification de le chantier.\n Veuillez réessayer."), QMessageBox::Ok);


}

void MainWindow::on_id_chmo_activated(const QString & )
{
    QString a=ui->id_chmo->currentText();
      QSqlQuery query;
      query.prepare("select * from chantier where ID_CHANTIER =:id_chantier");
      query.bindValue(":id_chantier", a);

      if (query.exec())
      {

          while (query.next()) {


               playaudio();
               ui->id_chmo->setCurrentText(query.value(0).toString());
               ui->ad_chmo->setText(query.value(1).toString());
               ui->sur_chmo->setText(query.value(2).toString());
               ui->bud_chmo->setText(query.value(3).toString());
                ui->date_chmo->setDate(query.value(4).toDate());

          }
      }
}



void MainWindow::on_tabchantier_activated(const QModelIndex &index)
{
    QString a=ui->tabchantier->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from chantier where ID_CHANTIER=:id_chantier");
    query.bindValue(":id_chantier", a);

    if (query.exec())
    {

        while (query.next()) {

            ui->lineEdit_7->setText(query.value(0).toString());
            ui->sup_id->setText(query.value(0).toString());
            ui->id_chmo->setCurrentText(query.value(0).toString());
            ui->ad_chmo->setText(query.value(1).toString());
            ui->sur_chmo->setText(query.value(2).toString());
            ui->bud_chmo->setText(query.value(3).toString());
            ui->date_chmo->setDate(query.value(4).toDate());


        }
    }
}

void MainWindow::on_supprimerchantier_clicked()
{

    int a=ui->sup_id->text().toInt();
    bool test=tmp_chantier.supprimer(a);

    if (a!='\0'){
    QMessageBox::StandardButton reponse = QMessageBox::question(this,"suppression","confirmer la suppression",QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {

        if(test)
        {
            playaudio();
            display_listes();
            QMessageBox::information(nullptr, QObject::tr("Supprimer un chantier"),
                        QObject::tr("Client supprimé.\n"
                                    "Click Ok to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un chantier"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else  return;}






}

void MainWindow::on_pushButton_2_clicked()
{
    int i=ui->lineEdit->text().toInt();
    QString p=ui->lineEdit_2->text();
    QString k=ui->lineEdit_3->text();
    int l=ui->lineEdit_4->text().toInt();
    QString d= ui->lineEdit_5->text();
    intervenat c(i,p,k,l,d);
    if ((i!='\0')&&(p!='\0')&&(k!='\0')&&(l!='\0')&&(d!='\0'))
    {
    bool test = c.ajouter();
    if(test)

    {   playaudio();
        display_listes();
        QMessageBox::information(nullptr,("Ajout intervenant"),("intervenant ajouté"));}
else
     {QMessageBox::warning(nullptr,("Ajout intervenant"),("intervenant non ajouté"));}}
    else QMessageBox::warning(nullptr,("Ajout intervenant"),("pas de données"));

}

void MainWindow::on_comboBox_2_activated(const QString &)
{
     QString a=ui->comboBox_2->currentText();
      QSqlQuery query;
      query.prepare("select * from inter where ID =:idd");
      query.bindValue(":idd", a);

      if (query.exec())
      {

          while (query.next()) {


               playaudio();
               ui->comboBox_2->setCurrentText(query.value(0).toString());
               ui->lineEditadres_4->setText(query.value(1).toString());
               ui->lineEditsurface_4->setText(query.value(2).toString());
               ui->lineEditbudget_4->setText(query.value(3).toString());
               ui->lineEdit_6->setText(query.value(4).toString());

          }
      }
}

void MainWindow::on_modifierchantier_3_clicked()
{
    int i=ui->comboBox_2->currentText().toInt();
    QString p=ui->lineEditadres_4->text();
    QString k=ui->lineEditsurface_4->text();
    int l=ui->lineEditbudget_4->text().toInt();
    QString d= ui->lineEdit_6->text();
    intervenat c(i,p,k,l,d);
    bool test=c.modifier();
    if(test)
    {    playaudio();
         display_listes();
        QMessageBox::information(nullptr, QObject::tr("Modifier un intervenat"),
                    QObject::tr("un intervenat a été modifier.\n"
                                "Cliquez sur Ok pour continuer."), QMessageBox::Ok);
    }
    else

       QMessageBox::critical(nullptr, QObject::tr("Modifier un chantier"),
                   QObject::tr("Erreur!\n"
                               "Erreur de modification .\n Veuillez réessayer."), QMessageBox::Ok);



}






void MainWindow::on_pushButton_4_toggled(bool checked)
{


    if (checked){
        ui->pushButton_4->setIcon((QIcon(":/images/off.png")));
        ui->pushButton_4->setIconSize(ui->pushButton_4->size());
        playaudio();
        music->pause();

    }
   else  {
        ui->pushButton_4->setIcon((QIcon(":/images/on.png")));
        ui->pushButton_4->setIconSize(ui->pushButton_4->size());
        playaudio();
        music->play();
    }

}

void MainWindow::on_pushButton_4_clicked()
{

}


void MainWindow::on_supprimerchantier_3_clicked()
{



        int a=ui->lineEdit_23->text().toInt();
       bool test=tmp_inter.supprimer(a);
       if (a!='\0'){
    QMessageBox::StandardButton reponse = QMessageBox::question(this,"suppression","confirmer la suppression",QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {

        if(test)
        {
            playaudio();
            display_listes();
            QMessageBox::information(nullptr, QObject::tr("Supprimer un intervenant"),
                        QObject::tr("intervenant supprimé.\n"
                                    "Click Ok to exit."), QMessageBox::Cancel);

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un intervenant"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        playaudio();}

    }
    else  return;}


}



void MainWindow::on_tabcha_activated(const QModelIndex &index)
{
    QString a=ui->tabcha->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from inter where ID=:idd");
    query.bindValue(":idd", a);

    if (query.exec())
    {

        while (query.next()) {
            playaudio();
            ui->lineEdit_23->setText(query.value(0).toString());
            ui->comboBox_2->setCurrentText(query.value(0).toString());
            ui->lineEditadres_4->setText(query.value(1).toString());
            ui->lineEditsurface_4->setText(query.value(2).toString());
            ui->lineEditbudget_4->setText(query.value(3).toString());
            ui->lineEdit_6->setText(query.value(4).toString());


        }
    }
}

void MainWindow::on_pb_ok1_clicked()
{


    if (ui->radioButton_3->isChecked())
    {
        QString type= ui->lineEdit_18->text() ;
        ui->tabchantier->setModel(tmp_chantier.chercher(type));
        playaudio();
    }

    if (ui->radioButton_2->isChecked())
    {
        QString type= ui->lineEdit_18->text() ;
        ui->tabchantier->setModel(tmp_chantier.chercherbug(type));
        playaudio();
    }

    if (ui->radioButton->isChecked())
    {
        QString type= ui->lineEdit_18->text() ;
        ui->tabchantier->setModel(tmp_chantier.cherchersur(type));
        playaudio();
    }
    if (!(ui->radioButton_3->isChecked())&&!(ui->radioButton_2->isChecked())&&!(ui->radioButton->isChecked()))
           { playaudio();
        QMessageBox::critical(nullptr, QObject::tr("cherche échoué"),
                               QObject::tr("aaaaa\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }



}

void MainWindow::on_pushButton_5_toggled(bool checked)
{

    if (checked){
        ui->pushButton_5->setIcon((QIcon(":/images/refresh2.png")));
        ui->pushButton_5->setIconSize(ui->pushButton_5->size());
        display_listes();
        ui->lineEdit_18->clear();
        ui->sup_id->clear();
        playaudio();

    }
   else  {
        ui->pushButton_5->setIcon((QIcon(":/images/refresh1.png")));
        ui->pushButton_5->setIconSize(ui->pushButton_5->size());
        display_listes();
        ui->lineEdit_18->clear();
        ui->sup_id->clear();
        playaudio();
    }



}

void MainWindow::on_pb_ok1_2_clicked()
{
    if (ui->radioButton_4->isChecked())
    {
        QString type= ui->lineEdit_19->text() ;
        ui->tabcha->setModel(tmp_inter.cherchernom(type));
        playaudio();
    }

    if (ui->radioButton_5->isChecked())
    {
        QString type= ui->lineEdit_19->text() ;
        ui->tabcha->setModel(tmp_inter.chercherprenom(type));
        playaudio();
    }

    if (ui->radioButton_6->isChecked())
    {
        QString type= ui->lineEdit_19->text() ;
        ui->tabcha->setModel(tmp_inter.cherchergsm(type));
        playaudio();
    }
    if (!(ui->radioButton_4->isChecked())&&!(ui->radioButton_5->isChecked())&&!(ui->radioButton_6->isChecked()))
           { playaudio();
        QMessageBox::critical(nullptr, QObject::tr("cherche échoué"),
                               QObject::tr("aaaaa\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_6_toggled(bool checked)
{
    if (checked){
        ui->pushButton_6->setIcon((QIcon(":/images/refresh2.png")));
        ui->pushButton_6->setIconSize(ui->pushButton_6->size());
        display_listes();
        ui->lineEdit_19->clear();
        ui->lineEdit_23->clear();
        playaudio();

    }
   else  {
        ui->pushButton_6->setIcon((QIcon(":/images/refresh1.png")));
        ui->pushButton_6->setIconSize(ui->pushButton_6->size());
        display_listes();
        ui->lineEdit_19->clear();
        ui->lineEdit_23->clear();
        playaudio();
    }


}

void MainWindow::on_comboBox_activated(const QString &arg1)
{

 if(arg1=="ID")
    {
     if (ui->radioButton_7->isChecked())
     {
         ui->tabchantier->setModel(tmp_chantier.trier_id());
         playaudio();
     }
     if (ui->radioButton_8->isChecked())
     {
         ui->tabchantier->setModel(tmp_chantier.trier_id1());
         playaudio();
     }
    }
 if(arg1=="Surface")
    {
     if (ui->radioButton_7->isChecked())
     {
         ui->tabchantier->setModel(tmp_chantier.trier_id2());
         playaudio();
     }
     if (ui->radioButton_8->isChecked())
     {
         ui->tabchantier->setModel(tmp_chantier.trier_id3());
         playaudio();
     }
    }
 if(arg1=="Budget")
    {
     if (ui->radioButton_7->isChecked())
     {
         ui->tabchantier->setModel(tmp_chantier.trier_id4());
         playaudio();
     }
     if (ui->radioButton_8->isChecked())
     {
         ui->tabchantier->setModel(tmp_chantier.trier_id5());
         playaudio();
     }
    }
 if(arg1=="Date limite")
    {
     if (ui->radioButton_7->isChecked())
     {
         ui->tabchantier->setModel(tmp_chantier.trier_id6());
         playaudio();
     }
     if (ui->radioButton_8->isChecked())
     {
         ui->tabchantier->setModel(tmp_chantier.trier_id7());
         playaudio();
     }
    }
}

void MainWindow::on_comboBox_4_activated(const QString &arg1)
{
    if(arg1=="Nom")
       {
        if (ui->radioButton_13->isChecked())
        {
            ui->tabcha->setModel(tmp_inter.trier1());
            playaudio();
        }
        if (ui->radioButton_12->isChecked())
        {
            ui->tabcha->setModel(tmp_inter.trier2());
            playaudio();
        }
       }
    if(arg1=="Prénom")
       {
        if (ui->radioButton_13->isChecked())
        {
            ui->tabcha->setModel(tmp_inter.trier3());
            playaudio();
        }
        if (ui->radioButton_12->isChecked())
        {
            ui->tabcha->setModel(tmp_inter.trier4());
            playaudio();
        }
       }
}



void MainWindow::on_comboBox_5_activated(const QString &)
{

playaudio();

}

void MainWindow::on_pushButton_3_clicked()
{

playaudio();
    ui->lineEditadres_4->clear();
        ui->lineEditsurface_4->clear();
         ui->lineEditbudget_4->clear();
         ui->lineEdit_6->clear();

}





void MainWindow::on_pushButton_7_clicked()
{
    playaudio();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
     ui->lineEdit_5->clear();
}

void MainWindow::on_pushButton_8_clicked()
{
    playaudio();
    ui->lineeditid->clear();
    ui->lineEditadres->clear();
    ui->lineEditsurface->clear();
    ui->lineEditbudget->clear();
    ui->dateEdit->clear();
}

void MainWindow::on_pushButton_9_clicked()
{
    playaudio();
    ui->ad_chmo->clear();
    ui->sur_chmo->clear();
    ui->bud_chmo->clear();
    ui->date_chmo->clear();
}

void MainWindow::on_pushButton_10_clicked()
{
    playaudio();
    Dialog d;
    d.exec();

}


void MainWindow::on_pushButton_11_clicked()
{



QMediaPlayer * music =new QMediaPlayer();
music->setMedia(QUrl("qrc:/images/Flash instant, printer, printing sound effect (128 kbps).mp3"));







        QString num1 = ui->lineEdit_7->text();
        int num = ui->lineEdit_7->text().toInt();

        QSqlQuery query;

        QString id;
        QString adr;
        QString surfa;
        QString bdget,datemil1;
        QDate datemil;

        if(num1!=""){playaudio();

        query.prepare("select * from chantier where ID_CHANTIER =:id_chantier");
        query.bindValue(":id_chantier", num);
        if (query.exec())
        {

            while (query.next()) {

                 id= query.value(0).toString();
                 adr= query.value(1).toString();
                 surfa=query.value(2).toString();
                 bdget=query.value(3).toString();
                 datemil = query.value(4).toDate();
                 datemil1=datemil.toString("dd-MM-yyyy");


             }
        }
              QPrinter printer(QPrinter::HighResolution);
                  printer.setPageSize(QPrinter::A4);
QGraphicsView a;

                 QPrintDialog *dialog = new QPrintDialog(&printer);
                  if (dialog->exec() == QDialog::Accepted)
                  {               QPainter painter(&printer);
                                  painter.begin(&printer);
                                  int iYPos = 0;
                                  int iWidth = printer.width();
                                  int iHeight = printer.height();
                                  QPixmap pxPic;
                                  pxPic.load(":/images/background.jpg","JPG");
                                 QSize s(iWidth/1, iHeight/1);
                                  QPixmap pxScaledPic = pxPic.scaled(s, Qt::IgnoreAspectRatio, Qt::FastTransformation);
                                  painter.drawPixmap(0, iYPos, pxScaledPic.width(), pxScaledPic.height(), pxScaledPic);
                                  iYPos += pxScaledPic.height() + 250;
                                  QFont f;
                                      f.setPointSize(20);
                                      f.setBold(true);
                                      painter.setFont(f);
                                   painter.drawText(1800, 500, "CHANTIER");
                                   f.setPointSize(15);
                                   f.setBold(true);
                                   painter.setFont(f);
                                   painter.drawText(100, 1000, "ID de chantier :");
                                   painter.drawText(1900, 1000,id);
                                   painter.drawText(100, 1300, "Aderesse :");
                                   painter.drawText(1900, 1300,adr);
                                   painter.drawText(100, 1600, "Surface de terrain en m² :");
                                   painter.drawText(1900, 1600,surfa);
                                   painter.drawText(100, 1900, "Budget en dt :");
                                   painter.drawText(1900, 1900,bdget);
                                   painter.drawText(100, 2200, "Date limite :");
                                   painter.drawText(1900, 2200,datemil1);




                                  painter.end();
                                  music->play();


                  }
        }
        else
        {playaudio();
            QMessageBox::critical(nullptr, QObject::tr("Imprimer chantier"),
                        QObject::tr("Erreur !.\n"
                                    "Veuillez selectionner un id d'un chantier à imprimer .\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pushButton_12_clicked()
{
    int i=ui->lineeditid_2->text().toInt();
    QString p=ui->lineEditadres_2->text();
    int k=ui->lineEditsurface_2->text().toInt();
    QString s=ui->comboBox_3->currentText();

    parking c(i,p,k,s);


    if ((i!='\0')&&(p!='\0')&&(k!='\0'))
    {

    bool test = c.ajouter();
    if(test)

    {
        display_listes();
        playaudio();
        QMessageBox::information(nullptr,("Ajout parking"),("parking ajouté"));}
else
     {QMessageBox::warning(nullptr,("Ajout parking"),("parking non ajouté"));}
    }

    else QMessageBox::warning(nullptr,("Ajout parking"),("pas de données"));
}

void MainWindow::on_pushButton_13_clicked()
{
    playaudio();
   ui->lineeditid_2->clear();
   ui->lineEditadres_2->clear();
   ui->lineEditsurface_2->clear();
}

void MainWindow::on_modifierchantier_6_clicked()
{
    int i=ui->comboBox_6->currentText().toInt();
    QString p=ui->lineEditadres_5->text();
    int l=ui->lineEditsurface_5->text().toInt();
    QString s=ui->comboBox_5->currentText();

    parking c(i,p,l,s);
    bool test=c.modifier();
    if(test)
    {    playaudio();
         display_listes();
        QMessageBox::information(nullptr, QObject::tr("Modifier un parking"),
                    QObject::tr("un parking a été modifier.\n"
                                "Cliquez sur Ok pour continuer."), QMessageBox::Ok);
    }
    else

       QMessageBox::critical(nullptr, QObject::tr("Modifier un parking"),
                   QObject::tr("Erreur!\n"
                               "Erreur de modification .\n Veuillez réessayer."), QMessageBox::Ok);
}

void MainWindow::on_pushButton_21_clicked()
{
    playaudio();
    ui->comboBox_6->clear();
    ui->lineEditadres_5->clear();
    ui->lineEditsurface_5->clear();
}

void MainWindow::on_supprimerchantier_5_clicked()
{
    int a=ui->lineEdit_24->text().toInt();
   bool test=tmp_parking.supprimer(a);
   if (a!='\0'){
QMessageBox::StandardButton reponse = QMessageBox::question(this,"suppression","confirmer la suppression",QMessageBox::Yes | QMessageBox::No);
if (reponse == QMessageBox::Yes)
{

    if(test)
    {
        playaudio();
        display_listes();
        QMessageBox::information(nullptr, QObject::tr("Supprimer un parking"),
                    QObject::tr("parking supprimé.\n"
                                "Click Ok to exit."), QMessageBox::Cancel);

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un parking"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    playaudio();}

}
else  return;}

}

void MainWindow::on_pb_ok1_5_clicked()
{
    if (ui->radioButton_21->isChecked())
    {
        QString type= ui->lineEdit_22->text() ;
        ui->tabcha_2->setModel(tmp_parking.chercheradresse(type));
        playaudio();
    }

    if (ui->radioButton_22->isChecked())
    {
        QString type= ui->lineEdit_22->text() ;
        ui->tabcha_2->setModel(tmp_parking.chercherid(type));
        playaudio();
    }


    if (!(ui->radioButton_21->isChecked())&&!(ui->radioButton_22->isChecked()))
           { playaudio();
        QMessageBox::critical(nullptr, QObject::tr("cherche échoué"),
                               QObject::tr("aaaaa\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_comboBox_7_activated(const QString &arg1)
{
    if(arg1=="ID")
       {
        if (ui->radioButton_24->isChecked())
        {
            ui->tabcha_2->setModel(tmp_parking.trier_3());
            playaudio();
        }
        if (ui->radioButton_25->isChecked())
        {
            ui->tabcha_2->setModel(tmp_parking.trier_4());
            playaudio();
        }
       }
    if(arg1=="Nombre de places de parking")
       {
        if (ui->radioButton_24->isChecked())
        {
            ui->tabcha_2->setModel(tmp_parking.trier_1());
            playaudio();
        }
        if (ui->radioButton_25->isChecked())
        {
            ui->tabcha_2->setModel(tmp_parking.trier_2());
            playaudio();
        }
       }
}

void MainWindow::on_pushButton_22_toggled(bool checked)
{
    if (checked){
        ui->pushButton_22->setIcon((QIcon(":/images/refresh2.png")));
        ui->pushButton_22->setIconSize(ui->pushButton_22->size());
        display_listes();
        ui->lineEdit_24->clear();
        ui->lineEdit_22->clear();
        playaudio();

    }
   else  {
        ui->pushButton_22->setIcon((QIcon(":/images/refresh1.png")));
        ui->pushButton_22->setIconSize(ui->pushButton_22->size());
        display_listes();
        ui->lineEdit_24->clear();
        ui->lineEdit_22->clear();
        playaudio();
}
}

void MainWindow::on_tabcha_2_activated(const QModelIndex &index)
{

    QString a=ui->tabcha_2->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from parking where ID=:id");
    query.bindValue(":id", a);

    if (query.exec())
    {

        while (query.next()) {
            playaudio();
            ui->lineEdit_24->setText(query.value(0).toString());
            ui->comboBox_6->setCurrentText(query.value(0).toString());
            ui->lineEditadres_5->setText(query.value(1).toString());
            ui->lineEditsurface_5->setText(query.value(2).toString());



        }
    }
}







void MainWindow::on_comboBox_stat_type_currentTextChanged()
{

      /*  mainLayout=new QVBoxLayout ;
        mainLayout->addWidget(s.Preparechart(ui->comboBox12->currentText()));
        ui->widget->setLayout(mainLayout);*/
}
