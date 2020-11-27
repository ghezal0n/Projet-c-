#include "dialog.h"
#include "ui_dialog.h"
#include "mailing/SmtpMime"
#include <QMessageBox>
#include <QApplication>
#include "mainwindow.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->comboBox_5->setModel(w.gettmp().combo_box1());

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_envoyer_clicked()
{

    w.playaudio();
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

void Dialog::on_comboBox_5_activated(const QString &arg1)
{
    QString a=ui->comboBox_5->currentText();
      QSqlQuery query;
      query.prepare("select * from inter where email =:email");
      query.bindValue(":email", a);

      if (query.exec())
      {

          while (query.next()) {


              w.playaudio();
               ui->lineEdit_adresse->setText(query.value(4).toString());


          }
      }
}
