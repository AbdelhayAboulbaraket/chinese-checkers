#include "myconfig.h"
#include "ui_myconfig.h"
#include<QPixmap>
#include <QtDebug>
#include "mainwindow.h"
extern MainWindow *w;

MyConfig::MyConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyConfig)
{
    ui->setupUi(this);
    //pour ajouter une image
    QPixmap pic_config(":/img/img/configuration-png-8.png");
    int a = ui->config_label->width();
    int b = ui->config_label->height();
    ui->config_label->setPixmap(pic_config.scaled(a,b,Qt::KeepAspectRatio));
    if(w->get_mode()==1) ui->radioButton_3->setChecked(true);
    else if(w->get_mode()==2) ui->radioButton_4->setChecked(true);
    else if(w->get_mode()==3) {
        ui->radioButton_5->setChecked(true);}
    if(w->get_variante_rapide()==false) ui->radioButton_6->setChecked(true);
    else if(w->get_variante_rapide()==true) ui->radioButton_7->setChecked(true);

    if(w->get_computer()==0) ui->radioButton->setChecked(true);
    if(w->get_computer()==1)
    {
        ui->radioButton_2->setChecked(true);
        ui->radioButton_4->setEnabled(false);
        ui->radioButton_5->setEnabled(false);
    }
    if(w->get_computer()==2)
    {
        ui->radioButton_8->setChecked(true);
        ui->radioButton_4->setEnabled(false);
        ui->radioButton_5->setEnabled(false);
    }





}


MyConfig::~MyConfig()
{
    delete ui;
}



void MyConfig::on_radioButton_3_clicked(bool checked)
{
    w->set_mode(1);

}

void MyConfig::on_radioButton_4_clicked(bool checked)
{
    w->set_mode(2);

}

void MyConfig::on_radioButton_5_clicked(bool checked)
{
    w->set_mode(3);

}

void MyConfig::on_pushButton_clicked()
{
    this->hide();
    w->redraw_board();
}

void MyConfig::on_radioButton_7_clicked(bool checked)
{
    w->set_variante_rapide(true);
}

void MyConfig::on_radioButton_6_clicked(bool checked)
{
      w->set_variante_rapide(false);
}

void MyConfig::on_radioButton_2_clicked(bool checked)
{
    w->set_computer(1);
    w->set_mode(1);
    ui->radioButton_3->setChecked(true);
    ui->radioButton_4->setEnabled(false);
    ui->radioButton_5->setEnabled(false);


}



void MyConfig::on_radioButton_clicked(bool checked)
{
     w->set_computer(0);
     ui->radioButton_4->setEnabled(true);
     ui->radioButton_5->setEnabled(true);
}

void MyConfig::on_radioButton_8_clicked(bool checked)
{
    w->set_computer(2);
    w->set_mode(1);
    ui->radioButton_3->setChecked(true);
    ui->radioButton_4->setEnabled(false);
    ui->radioButton_5->setEnabled(false);
}
