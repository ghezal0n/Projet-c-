#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>
#include "fournisseur.h"
#include "equipements.h"
#include <QMessageBox>
#include <QApplication>
#include <QComboBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton->setIcon((QIcon(":/images/2.png")));
    ui->pushButton->setIconSize(ui->pushButton->size());

    ui->pushButton_2->setIcon((QIcon(":/images/2.png")));
    ui->pushButton_2->setIconSize(ui->pushButton_2->size());

    ui->pushButton_3->setIcon((QIcon(":/images/pngtree-cartoon-arrow-icon-download-image_1256957.png")));
    ui->pushButton_3->setIconSize(ui->pushButton_3->size());

    ui->pb_ok1->setIcon((QIcon(":/images/4.png")));
    ui->pb_ok1->setIconSize(ui->pb_ok1->size());

    ui->chercher_equi->setIcon((QIcon(":/images/4.png")));
    ui->chercher_equi->setIconSize(ui->chercher_equi->size());

    ui->modifier_equi->setIcon((QIcon(":/images/1.png")));
    ui->modifier_equi->setIconSize(ui->modifier_equi->size());

    ui->supprimer_equi->setIcon((QIcon(":/images/3.png")));
    ui->supprimer_equi->setIconSize(ui->supprimer_equi->size());

    ui->modifier->setIcon((QIcon(":/images/1.png")));
    ui->modifier->setIconSize(ui->modifier->size());

    ui->supprimer->setIcon((QIcon(":/images/3.png")));
    ui->supprimer->setIconSize(ui->supprimer->size());

    ui->actualiser->setIcon((QIcon(":/images/pngtree-cartoon-arrow-icon-download-image_1256957.png")));
    ui->actualiser->setIconSize(ui->actualiser->size());

    ui->tableView->setModel(f.afficher());
    ui->tableView_2->setModel(e1.afficher());
    ui->comboBox_3->setModel(f.combo_box());
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refresh(){

    ui->tableView->setModel(f.afficher());
    ui->tableView_2->setModel(e1.afficher());
    ui->comboBox_3->setModel(f.combo_box());
    ui->comboBox_4->setModel(e1.combo_box());
}

void MainWindow::on_pushButton_2_clicked()
{
    QString a1=ui->lineEdit_e1->text();
    QString b2=ui->lineEdit_e2->text();
    int c3=ui->lineEdit_e3->text().toInt();
    QDate d3=ui->dateEdit_3->date();
    float e4=ui->lineEdit_e4->text().toFloat();

    equipements e1(a1,b2,c3,d3,e4);

       if ((a1!='\0')&&(b2!='\0')&&(c3!='\0')&&(e4!='\0'))
       {

       bool test = e1.ajouter();
       if(test)

       {
           QMessageBox::information(nullptr,("Ajout equipement"),("equipement ajouté"));
           ui->tableView_2->setModel(e1.afficher());
       }
   else
       {QMessageBox::warning(nullptr,("Ajout equipement"),("equipement non ajouter"));
       }
       }
        else QMessageBox::warning(nullptr,("Ajout equipement"),("pas de données"));
}


void MainWindow::on_pushButton_clicked()
{
    int a=ui->lineEdit1->text().toInt();
    QString b=ui->lineEdit2->text();
    QString c=ui->lineEdit3->text();
    int d=ui->lineEdit4->text().toInt();
    QString e=ui->lineEdit5->text();

    fournisseur f(a,b,c,d,e);

       if ((a!='\0')&&(b!='\0')&&(c!='\0')&&(d!='\0')&&(e!='\0'))
       {

       bool test = f.ajouter();
       if(test)

       {
           QMessageBox::information(nullptr,("Ajout fournisseur"),("fournisseur ajouté"));
           ui->tableView->setModel(f.afficher());
       }
   else
       {QMessageBox::warning(nullptr,("Ajout fournisseur"),("fournisseur non ajouter"));
       }
       }
       else QMessageBox::warning(nullptr,("Ajout fournisseur"),("pas de données"));
}


void MainWindow::on_modifier_clicked()
{
    int a=ui->comboBox_3->currentText().toInt();
    QString b=ui->lineEdit_22->text();
    QString c=ui->lineEdit_33->text();
    int d=ui->lineEdit_44->text().toInt();
    QString e=ui->lineEdit_55->text();

    fournisseur f(a,b,c,d,e);

    //   if ((a!='\0')&&(b!='\0')&&(c!='\0')&&(d!='\0')&&(e!='\0'))
       {

       bool test = f.modifier();
       if(test)

       {
           QMessageBox::information(nullptr,("modifier fournisseur"),("fournisseur modifié"));
           ui->tableView->setModel(f.afficher());
       }
   else
       {QMessageBox::warning(nullptr,("modifier fournisseur"),("fournisseur non modifier"));
       }
       }
//       else QMessageBox::warning(nullptr,("modifier fournisseur"),("pas de données"));
}

 void MainWindow::on_modifier_equi_clicked()
{
    QString a1=ui->comboBox_4->currentText();
    QString b2=ui->lineEdit_e22->text();
    int c3=ui->lineEdit_e33->text().toInt();
    QDate d3=ui->dateEdit_e2->date();
    float e4=ui->lineEdit_e44->text().toFloat();

  equipements e1(a1,b2,c3,d3,e4);
       {
       bool test = e1.modifier();
       if(test)

       {
           QMessageBox::information(nullptr,("modifier equipement"),("equipement modifié"));
           ui->tableView_2->setModel(e1.afficher());
       }
   else
       {QMessageBox::warning(nullptr,("Amodifier equipement"),("equipement non modifié"));
       }
       }
}


void MainWindow::on_supprimer_clicked()
{
   int a=ui->lineEdit_sup->text().toInt();
    bool test=f.supprimer(a);
    if (a!='\0'){
   QMessageBox::StandardButton supprimer = QMessageBox::question(this,"suppression","confirmer la suppression !!!",QMessageBox::Yes|QMessageBox::No);
    if (supprimer == QMessageBox::Yes)  {
        if(test){

                QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                             QObject::tr("fournisseur supprimé.\n"
                                         "Click OK to exit."), QMessageBox::Cancel);
           }
           else
               QMessageBox::critical(nullptr, QObject::tr("supprimer un fournisseur"),
                           QObject::tr("Erreur !.\n"
                                       "Veuillez saisir un idCon pour supprimer un fournisseur .\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}
  else return;
}
}

void MainWindow::on_supprimer_equi_clicked()
{
    QString a1=ui->lineEdit_supp->text();
       bool test=e1.supprimer(a1);
       if (a1!='\0'){
      QMessageBox::StandardButton supprimer_equi = QMessageBox::question(this,"suppression","confirmer la suppression !!!",QMessageBox::Yes|QMessageBox::No);
       if (supprimer_equi == QMessageBox::Yes)  {
           if(test)

                    QMessageBox::information(nullptr, QObject::tr("Supprimer un equipement"),
                                QObject::tr("equipement supprimé.\n"
                                            "Click OK to exit."), QMessageBox::Cancel);
              }
              else
                  QMessageBox::critical(nullptr, QObject::tr("supprimer un equipement"),
                              QObject::tr("Erreur !.\n"
                                          "Veuillez saisir un idCon pour supprimer un equipement .\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

   }
}

void MainWindow::on_comboBox_3_activated(const QString &)
{

    QString a=ui->comboBox_3->currentText();
          QSqlQuery query;
          query.prepare("select * from fournisseur where id =:id");
          query.bindValue(":id", a);

          if (query.exec())
          {

              while (query.next()) {

                   ui->comboBox_3->setCurrentText(query.value(0).toString());
                   ui->lineEdit_22->setText(query.value(1).toString());
                   ui->lineEdit_33->setText(query.value(2).toString());
                   ui->lineEdit_44->setText(query.value(3).toString());
                   ui->lineEdit_55->setText(query.value(4).toString());

              }
          }
}

void MainWindow::on_comboBox_4_activated(const QString &)
{
    QString a1=ui->comboBox_4->currentText();
          QSqlQuery query;
          query.prepare("select * from equipements where code =:code");
          query.bindValue(":code", a1);

          if (query.exec())
          {

              while (query.next()) {

                   ui->comboBox_4->setCurrentText(query.value(0).toString());
                   ui->lineEdit_e22->setText(query.value(1).toString());
                   ui->lineEdit_e33->setText(query.value(2).toString());
                   ui->dateEdit_e2->setDate(query.value(3).toDate());
                   ui->lineEdit_e44->setText(query.value(4).toString());

              }
          }
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
   // ui->tableView->setModel(f.tri_nom());
    //qDebug()<<arg1;
        if(arg1=="ID")
           {
                ui->tableView->setModel(f.tri_id());
           }

        if(arg1=="Nom")
           {
                ui->tableView->setModel(f.tri_nom());
           }

        if(arg1=="type")
           {
                ui->tableView->setModel(f.tri_type());
           }
        if(arg1=="numero")
                   {
                        ui->tableView->setModel(f.tri_numero());
                   }
        if(arg1=="adresse")
           {
                ui->tableView->setModel(f.tri_adresse());
           }

}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{

   // qDebug()<<arg1;
    if(arg1=="Code")
       {
            ui->tableView_2->setModel(e1.tri_code());
       }

    if(arg1=="Quantite")
       {
            ui->tableView_2->setModel(e1.tri_quantite());
       }

    if(arg1=="Description")
       {
            ui->tableView_2->setModel(e1.tri_description());
       }

    if(arg1=="Date")
       {
            ui->tableView_2->setModel(e1.tri_date());
       }

    if(arg1=="Prix")
       {
            ui->tableView_2->setModel(e1.tri_prix());
       }
}





void MainWindow::on_chercher_equi_clicked()
{
    QString a1= ui->lineEdit_21->text() ;
    ui->tableView_2->setModel(e1.recherche_code(a1));
}



void MainWindow::on_pushButton_3_clicked()
{
    refresh();
}

void MainWindow::on_actualiser_clicked()
{
    refresh();
}


void MainWindow::on_pb_ok1_clicked()
{
    QString a= ui->lineEdit_18->text();
    ui->tableView->setModel(f.recherche_id(a));
}


void MainWindow::on_tabWidget_3_tabBarClicked(int index)
{
    QPieSeries *series= new QPieSeries();
      QSqlQuery query;
      query.prepare("select description, quantite from equipements;");
      QVector<int> q;
      QVector<QString> vectdesc;
      if(query.exec()){
          while(query.next()){
          vectdesc.push_back(query.value(0).toString());
          q.push_back(query.value(1).toInt());
            }

       int s=0;
       for (int i=0;i<q.size();i++) s+=q[i];

       for (int i=0;i<vectdesc.size();i++){
      series->append(vectdesc[i], (qreal)((qreal)q[i]/(qreal)s)*100.0);

         }
      QChart *ch= new QChart();
      ch->addSeries(series);
      ch->setTitle(QString("statistique des quantitées de la table equipements par rapport au description"));
      ch->legend()->show();
      ch->setAnimationOptions(QChart::AllAnimations);
      QChartView *chart=new QChartView(ch);
      chart->setRenderHint(QPainter::Antialiasing);//graphique
      chart->setGeometry(ui->graphicsView_7->geometry());//taille de la page
      QGridLayout q;
      q.addWidget(chart);
      ui->graphicsView_7->setLayout(&q);
        }
}
