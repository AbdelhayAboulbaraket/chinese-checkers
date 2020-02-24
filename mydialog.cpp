#include "mydialog.h"
#include "ui_mydialog.h"
#include<QPixmap>
#include<QMessageBox>

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
    //pour ajouter une image
    QPixmap pic_help(":/img/img/help.png");
    int a = ui->help_label->width();
    int b = ui->help_label->height();
    ui->help_label->setPixmap(pic_help.scaled(a,b,Qt::KeepAspectRatio));
    ui->help_label_2->setPixmap(pic_help.scaled(a,b,Qt::KeepAspectRatio));

}


MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_pushButton_clicked()
{
    QMessageBox::information(this,"But du Jeu","<span style=\"color: white\">""Le <b>but du jeu</b> est très simple, le premier joueur qui arrive à faire passer la totalité de ses pions vers la zone d'adversaire sera le vainqueur, donc il doit être rapide et malin.""</span>");
}

void MyDialog::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"Niveaux du Jeu","<span style=\"color: white\">"" •	<b>Le niveau facile</b> : Une partie avec une couleur chacun.<br><br>"
                                                   "•	<b>Le niveau moyen</b> : Une partie avec 2 couleurs pour chaque joueur.<br><br>"
                                                   "•	<b>Le niveau difficile</b> :  Une partie avec 3 couleurs pour chaque joueur, comme ça il y'aura plusieurs stratégies et un maximum de variations de déplacements. ");


}






void MyDialog::on_pushButton_3_clicked()
{
    QMessageBox::information(this,"Régles du Jeu","<span style=\"color: white\">""<pre>Les joueurs sont répartis de façon symétrique autour du tablier de jeu.<br><br>Chacun joue tour à tour un seul pion.<br><br>Un mouvement se déroule selon deux modes, au choix et de façon exclusive :<br><br>   • Déplacement d'une case dans une des six directions du plateau.<br>   • Déplacement par sauts successifs<br><br>Un pion n'a le droit de séjourner que dans son triangle de départ, dans l'hexagone central ou son triangle d'arrivée.<br><br>Un pion doit obligatoirement quitter son triangle de départ quand le joueur situé vis-à-vis n'a plus.</pre>""</span>");

}
