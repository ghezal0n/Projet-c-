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
    /*  **************recher*******************  */
    ui->pb_ok1->setIcon((QIcon(":/images/4.png")));
    ui->pb_ok1->setIconSize(ui->pb_ok1->size());
    ui->pb_ok1_2->setIcon((QIcon(":/images/4.png")));
    ui->pb_ok1_2->setIconSize(ui->pb_ok1_2->size());




}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::display_listes()
{
    ui->tabchantier->setModel(tmp_chantier.afficher());
    ui->id_chmo->setModel(tmp_chantier.combo_box());
    ui->tabcha->setModel(tmp_inter.afficher());
    ui->comboBox_2->setModel(tmp_inter.combo_box());
    ui->comboBox_5->setModel(tmp_chantier.combo_box1());



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
            QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                        QObject::tr("Client supprimé.\n"
                                    "Click Ok to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
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
            QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                        QObject::tr("Client supprimé.\n"
                                    "Click Ok to exit."), QMessageBox::Cancel);

        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
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
        playaudio();

    }
   else  {
        ui->pushButton_5->setIcon((QIcon(":/images/refresh1.png")));
        ui->pushButton_5->setIconSize(ui->pushButton_5->size());
        display_listes();
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
        playaudio();

    }
   else  {
        ui->pushButton_6->setIcon((QIcon(":/images/refresh1.png")));
        ui->pushButton_6->setIconSize(ui->pushButton_6->size());
        display_listes();
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



void MainWindow::on_pushButton_envoyer_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);




                smtp.setUser("smartmunicipality40@gmail.com");
                smtp.setPassword("municipality");



        MimeMessage message;

        message.setSender(new EmailAddress("smartmunicipality40@gmail.com", "Mohamed aouadi"));
        message.addRecipient(new EmailAddress(ui->lineEdit_adresse->text(), "Recipient's name"));
        message.setSubject(ui->lineEdit_objet->text());



        MimeText text;

        text.setText(ui->textEdit_texte->toPlainText());



        message.addPart(&text);


        smtp.connectToHost();
        smtp.login();
        if (smtp.sendMail(message)){
           QMessageBox::information(this, "OK", "email envoyé");
        }
        else{
           QMessageBox::critical(this, "Erreur","email non envoyé");
        }
        smtp.quit();
}

void MainWindow::on_comboBox_5_activated(const QString &)
{

playaudio();

}
