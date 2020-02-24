#include "mainwindow.h"
#include "ui_mainwindow1.h"
#include "emplacement.h"
#include <iostream>
#include "table.h"
#include <joueur.h>
#include <QtDebug>
#include<QtCore>
#include<QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Dame Chinoise");
    setWindowIcon(QIcon(":/img/img/chinese checkers.png"));
    //set the size of the window to 60x85 % of the screen
    QDesktopWidget dw;
    int x=dw.width()*0.56;
    int y=dw.height()*0.82;
    this->setFixedSize(x,y);
    m_scene = new QGraphicsScene();
    ui->graphicsView->setScene(m_scene);


    this->mode=1;
    m_table = NULL;
    J1= NULL;
    J2= NULL;
    this->variante_rapide=false;
    this->game_in_progress=false;
    this->computer=0;
    movable=NULL;
    turn=2; // player1 plays first ( BLUE )




}

MainWindow::~MainWindow()
{
    delete ui;
}
QPointF MainWindow::jump(QPointF position,int direction)
{
    if(direction==1)
        return QPointF(position.rx()+30,position.ry()); // Droite
    if(direction==2)
        return QPointF(position.rx()+15,position.ry()+30); // Bas droite
    if(direction==3)
        return QPointF(position.rx()-15,position.ry()+30);// Bas gauche
    if(direction==4)
        return QPointF(position.rx()-30,position.ry());  // Gauche
    if(direction==5)
        return QPointF(position.rx()-15,position.ry()-30); // Haut gauche
    if(direction==6)
        return QPointF(position.rx()+15,position.ry()-30); // haut droite
}

int MainWindow::get_turn()
{
    return this->turn;
}

void MainWindow::swap_turn()
{ if(this->turn==1) turn=2;
    else if(this->turn ==2) turn=1;
}



int MainWindow::check_win()
{   if (this->J1->get_score()==this->J1->get_nbr_boule() && this->J2->get_score()==this->J2->get_nbr_boule())
    {    delete this->m_scene;
        m_scene = new QGraphicsScene();
        ui->graphicsView->setStyleSheet("background-image: url(:/img/img/draw.jpg);");
        ui->graphicsView->setScene(m_scene);
        qDebug()<<"DRAW";
        this->game_in_progress=false;
        return -1;
    }
    if(this->J1->get_score()==this->J1->get_nbr_boule())
    {
        delete this->m_scene;
        m_scene = new QGraphicsScene();
        if (computer==0)
            ui->graphicsView->setStyleSheet("background-image: url(:/img/img/win.jpg);");
        else {ui->graphicsView->setStyleSheet("background-image:url(:/img/img/computer won.jpg);");}
            ui->graphicsView->setScene(m_scene);
        qDebug()<<"RED WINS";
        this->game_in_progress=false;return 1;
    }
    else if(this->J2->get_score()==this->J2->get_nbr_boule())
    {       delete this->m_scene;
        m_scene = new QGraphicsScene();
        ui->graphicsView->setStyleSheet("background-image: url(:/img/img/bluewin.jpg);");
        ui->graphicsView->setScene(m_scene);
        qDebug()<<"BLUE WINS";
        this->game_in_progress=false;return 2;
    }
    else return 0;
}

Joueur *MainWindow::get_Joueur(int n)
{
    if (n==1) return this->J1;
    if(n==2) return this->J2;

}

bool MainWindow::get_game_in_progress()
{
    return this->game_in_progress;
}






bool MainWindow::deja_traite(Boule *Q,Emplacement *E)
{
    for(unsigned int i=0;i<Q->get_possible_moves().size();i++)
    {
        if(Q->get_possible_moves()[i]==E)
        {
            return true;
        }
    }
    for(unsigned int i=0;i<Q->get_restricted_moves().size();i++)
    {
        if(Q->get_restricted_moves()[i]==E)
        {
            return true;
        }
    }
    return false;
}
void MainWindow::all_allowed_moves()
{
    all_jump_moves();
    if (get_variante_rapide()==false)  all_hop_moves();
    if (get_variante_rapide()==true) all_fast_moves();
}

void MainWindow::set_movable(Boule *B)
{
    this->movable=B;


}

Boule *MainWindow::get_movable()
{
    Boule *copy=this->movable;
    return copy;
}

void MainWindow::all_jump_moves()
{
    QPointF help(1000,1000);
    if(this->turn==1){
        this->J1->clear_boules_moves();
        for(unsigned int k=0;k<this->J1->get_boules().size();k++)
        {   for(int l=1;l<=6;l++){
                QPointF i=jump(this->J1->get_boules()[k]->pos(),l);
                Emplacement *temp1=this->m_table->getByPos(i);
                if(temp1->get_rempli()==false && temp1->pos()!=help)
                {
                    if(temp1->get_emplacement_special()==this->J1->get_boules()[k]->get_color()
                            || temp1->get_emplacement_special()==this->J1->get_boules()[k]->get_color()+3
                            || temp1->get_emplacement_special()==this->J1->get_boules()[k]->get_color()-3
                            || temp1->get_emplacement_special()==0)
                        this->J1->get_boules()[k]->push_to_moves(temp1); // si temp1 est un emplacement special vide.
                }
            }
        }
    }
    else if(this->turn==2)
    {
        this->J2->clear_boules_moves();
        for(unsigned int k=0;k<this->J2->get_boules().size();k++)
        {   for(int l=1;l<=6;l++){
                QPointF i=jump(this->J2->get_boules()[k]->pos(),l);
                Emplacement *temp1=this->m_table->getByPos(i);
                if(temp1->get_rempli()==false && temp1->pos()!=help) // si temp1 est vide et n'est pas hors plateau.
                {    int multiplier;
                    if(J2->get_id()==1) multiplier=1;
                    else {
                        multiplier=-1;
                    }
                    if(temp1->get_emplacement_special()==this->J2->get_boules()[k]->get_color()
                            || temp1->get_emplacement_special()==this->J2->get_boules()[k]->get_color()+3*multiplier
                            || temp1->get_emplacement_special()==0)
                        this->J2->get_boules()[k]->push_to_moves(temp1);
                }
            }
        }
    }
}

void MainWindow::all_hop_moves() // cette fonction parcours les boules d'un joueur et affectes les mouvements possibles
{   if(this->turn==1)   {                     // pour chaque boule , dans Possible_moves.
        for(unsigned int k=0;k<this->J1->get_boules().size();k++)
        {
            QPointF position(this->J1->get_boules()[k]->pos());
            hop_recu(this->J1->get_boules()[k],position);

        }
    }
    else if(this->turn==2){
        for(unsigned int k=0;k<this->J2->get_boules().size();k++)
        {
            QPointF position(this->J2->get_boules()[k]->pos());
            hop_recu(this->J2->get_boules()[k],position);
        }

    }
}

void MainWindow::hop_recu(Boule *Q,QPointF pos)
{
    QPointF help(1000,1000);
    QPointF i,j,position=pos;
    for(int l=1;l<=6;l++)
    {
        position=pos;
        i=jump(position,l);
        j=jump(i,l);
        Emplacement *temp1=this->m_table->getByPos(i);
        Emplacement *temp2=this->m_table->getByPos(j);
        if(temp1->get_rempli()==true && temp1->pos()!=Q->pos() && temp2->pos()!=help && temp2->get_rempli()==false && deja_traite(Q,temp2)==false)
        {
            int multiplier;
            if(Q->get_id()==1) multiplier=1;
            else {
                multiplier=-1;
            }
            if(temp2->get_emplacement_special()==Q->get_color()
                    || temp2->get_emplacement_special()==Q->get_color()+multiplier*3
                    || temp2->get_emplacement_special()==0)

            Q->push_to_moves(temp2);
            else {
                Q->push_to_restricted(temp2);
            }

            position=temp2->pos();
            hop_recu(Q,position);

        }

    }

}

void MainWindow::redraw_board()
{   if (m_table!=NULL && J1!=NULL && J2!=NULL) // si deja le jeu a été joué au moins une fois , on delete table , J1 et J2
    {delete this->m_table;
    delete this->J1;
    delete this->J2;
    }
    delete this->m_scene;
    m_scene = new QGraphicsScene();
    ui->graphicsView->setStyleSheet("background-image: url(:/img/img/flou.jpg);");
    ui->graphicsView->setScene(m_scene);
    ui->pushButton_2->setEnabled(true); // le boutton PLAY AGAIN s'active.
    m_table = new Table(this->mode,m_scene); // creation table
    J1= new Joueur(m_table); // creation joueur1
    J2= new Joueur(m_table); // creation joueur2
    this->game_in_progress=true; // jeu est maintenant en progres
    movable=NULL; // aucune boule n'est déplaçable.
    turn=2; // le joueur 2 joue toujours en premier (en bas )
}

int MainWindow::get_mode()
{
    return this->mode;
}

void MainWindow::set_mode(int n)
{
    this->mode=n;
}

void MainWindow::all_fast_moves()
{
    if(this->turn==1){
            for(unsigned int k=0;k<this->J1->get_boules().size();k++)
             {

                    QPointF position(this->J1->get_boules()[k]->pos());
                    fast_recu(this->J1->get_boules()[k],position);
            }
    }
            else if(this->turn==2){
                for(unsigned int k=0;k<this->J2->get_boules().size();k++)
                 {

                        QPointF position(this->J2->get_boules()[k]->pos());
                        fast_recu(this->J2->get_boules()[k],position);
                }
    }
}

void MainWindow::fast_recu(Boule *boule, QPointF position)
{
    QPointF help(1000,1000);
    int multiplier;
    if(boule->get_id()==1) multiplier=1;
    else {
        multiplier=-1;
    }
        int cmpt;
        for(int unsigned l=0;l<=6;l++)
        {
                cmpt=0;
                cmpt=compteur(boule->get_color(),position,cmpt,l);

                if(cmpt>=1)
                {	int x=0;
                        QPointF help2(position);
                        while(x<=cmpt){help2=jump(help2,l); x++; }
                        Emplacement *temp=this->m_table->getByPos(help2);
                        if(temp->get_rempli()==true && temp->pos()!= boule->pos())
                        {
                                int cmpt2=0;

                                while(cmpt2<=cmpt)
                                {
                                        help2=jump(help2,l);
                                        temp=this->m_table->getByPos(help2);
                                        if(temp->get_rempli()==true || temp->pos()==help ) break;
                                        if(temp->get_emplacement_special()==boule->get_color()+3*multiplier
                                                || temp->get_emplacement_special()==boule->get_color()
                                               || temp->get_emplacement_special()==0 )

                                        cmpt2++;

                                }
                                if(cmpt2==cmpt+1 && deja_traite(boule,temp)==false)
                                {

                                        boule->push_to_moves(temp);
                                        fast_recu(boule,help2);
                                }



                         }
         }

                else if(cmpt==0 )
                {

                    QPointF i,j,help2;

                        help2=position;
                        i=jump(help2,l);
                        j=jump(i,l);
                        Emplacement *temp1=this->m_table->getByPos(i);
                        Emplacement *temp2=this->m_table->getByPos(j);
                        if(temp1->get_rempli()==true && temp2->pos()!=help && temp2->get_rempli()==false && deja_traite(boule,temp2)==false)
                        {
                            if(temp2->get_emplacement_special()==0 || temp2->get_emplacement_special()== boule->get_color()
                                    || temp2->get_emplacement_special()== boule->get_color()+3*multiplier)
                                boule->push_to_moves(temp2);
                            else {
                                boule->push_to_restricted(temp2);
                            }
                            help2=temp2->pos();
                            fast_recu(boule,help2);

                        }



}
        }
}

int MainWindow::compteur(int color,QPointF position, int cmpt, int l)
{
    QPointF help(1000,1000);
    int multiplier;
    if(color<=3) multiplier=1;
    else
    {
        multiplier=-1;
    }
        QPointF i=jump(position,l);
            Emplacement *temp=this->m_table->getByPos(i);
            if(temp->get_rempli()==false && temp->pos()!=help
                    && (temp->get_emplacement_special()==color+3*multiplier  || temp->get_emplacement_special()==color || temp->get_emplacement_special()==0 ))
            {
                    cmpt++;
                    position=i;
                    cmpt=compteur(color,position,cmpt,l);
            }
    return cmpt;
}

bool MainWindow::get_variante_rapide()
{
    return this->variante_rapide;
}

void MainWindow::set_variante_rapide(bool ok)
{
    this->variante_rapide=ok;
}

void MainWindow::set_computer(int ok)
{
    this->computer=ok;
}

int MainWindow::get_computer()
{
    return this->computer;
}

int MainWindow::set_ev_ai_moves()
{
    // if computer mode is enabled
    this->ev_ai_moves.clear();
    if(1)
    {

        for(int unsigned i=0;i<10;i++)
        {
            for(int unsigned k=0;k<this->J1->get_boules()[i]->get_possible_moves().size();k++)
            {
                Move *temp=new Move(this->J1->get_boules()[i],this->J1->get_boules()[i]->get_possible_moves()[k]);
//                qDebug()<<i<<":"<<this->J1->get_boules()[i]->get_possible_moves().size();
//                qDebug()<<"ha mnin ja"<<temp->get_one_to_move()->pos();
//                qDebug()<<"ha fen ghadi"<<temp->get_to()->pos();
//                qDebug()<<"___________________";
                this->ev_ai_moves.push_back(temp);
            }
        }
    }

    // evaluation function. A refaire
    double w1=0.911;
    double w2=0.14;
    double w3=0;
    double w4=0;

    double max_score=-99999999;
    int ind_max_score=-1;

    for(int unsigned i=0;i<this->ev_ai_moves.size();i++)
    {
        double score=0;
        double a2=0;
        double a1=0;
        double b2=0;
        double b1=0;
        double c2=0;
        double c1=0;
        double d2=0;
        double d1=0;


        for(int k=0;k<10;k++)
        {  int max_adv_J2=-999999;
            int max_adv_J1=999999;
            if(ev_ai_moves[i]->get_one_to_move()->pos()!=this->J1->get_boules()[k]->pos())
            {
                a2+=(510-this->J2->get_boules()[k]->pos().ry())*(510-this->J2->get_boules()[k]->pos().ry());

                a1+=(30-this->J1->get_boules()[k]->pos().ry())*(30-this->J1->get_boules()[k]->pos().ry());

                b2+=(270-this->J2->get_boules()[k]->pos().ry())*(270-this->J2->get_boules()[k]->pos().ry());
                b1+=(270-this->J1->get_boules()[k]->pos().ry())*(270-this->J1->get_boules()[k]->pos().ry());

                c2+=(455-this->J2->get_boules()[k]->pos().ry());
                c1-=(75-this->J1->get_boules()[k]->pos().ry());

                d1+=(280-this->J1->get_boules()[k]->pos().rx())*(280-this->J1->get_boules()[k]->pos().rx());
                d2+=(280-this->J2->get_boules()[k]->pos().rx())*(280-this->J2->get_boules()[k]->pos().rx());

            }
            else
            {
                a2+=(510-this->J2->get_boules()[k]->pos().ry())*(510-this->J2->get_boules()[k]->pos().ry());
                a1+=(30-this->ev_ai_moves[i]->get_to()->pos().ry())*(30-this->ev_ai_moves[i]->get_to()->pos().ry());
                b2+=(270-this->J2->get_boules()[k]->pos().ry())*(270-this->J2->get_boules()[k]->pos().ry());
                b1+=(270-this->ev_ai_moves[i]->get_to()->pos().ry())*(270-this->ev_ai_moves[i]->get_to()->pos().ry());
                c2+=(455-this->J2->get_boules()[k]->pos().ry());
                c1-=(75-this->ev_ai_moves[i]->get_to()->pos().ry());
                d2+=(280-this->ev_ai_moves[i]->get_to()->pos().rx())*(280-this->ev_ai_moves[i]->get_to()->pos().rx());
                d1+=(280-this->J2->get_boules()[k]->pos().rx())*(280-this->J2->get_boules()[k]->pos().rx());
            }
        }
        score=w1*(a1-a2)+w2*(b1-b2)+w3*(c1-c2)+w4*(d1-d2);
        this->ev_ai_moves[i]->set_how_good(score);

        if(score>max_score)
        {
            max_score=score;
            ind_max_score=i;
        }

    }

    return ind_max_score;

}

void MainWindow::make_ev_ai_move()
{
    this->all_allowed_moves();
    //          qDebug()<<"1"<<this->get_ev_moves()[this->set_ev_ai_moves()]->get_to()->pos();
    //          qDebug()<<"2"<<this->get_ev_moves()[this->set_ev_ai_moves()]->get_one_to_move()->pos();
    int id=this->set_ev_ai_moves();
//    qDebug()<<id;
    this->get_ev_moves()[id]->get_one_to_move()->setPos(this->get_ev_moves()[id]->get_to()->pos());
    this->get_ev_moves()[id]->get_one_to_move()->get_current_pos()->set_rempli(false);
    this->get_ev_moves()[id]->get_one_to_move()->get_current_pos()->update();
    this->get_ev_moves()[id]->get_to()->set_rempli(true);
    this->get_ev_moves()[id]->get_to()->update();
    if(this->get_ev_moves()[id]->get_to()->get_emplacement_special()==this->get_ev_moves()[id]->get_one_to_move()->get_color() )
    {
        this->get_Joueur(this->get_turn())->change_score(1);
        qDebug()<<"score ++ "<<this->get_Joueur(this->get_turn())->get_score();
    }
    if(this->get_ev_moves()[id]->get_one_to_move()->get_current_pos()->get_emplacement_special()==this->get_ev_moves()[id]->get_one_to_move()->get_color())
    {
        this->get_Joueur(this->get_turn())->change_score(-1);
        qDebug()<<"score -- "<<this->get_Joueur(this->get_turn())->get_score();
    }
    this->get_ev_moves()[id]->get_one_to_move()->set_current_pos(this->get_ev_moves()[id]->get_to());
    this->check_win();
    this->swap_turn();
}

void MainWindow::set_random_ai_moves()
{
    // if computer mode is enabled
    if(1)
    {
        this->random_ai_moves.clear();
        this->all_allowed_moves();
        std::vector<Move*> backward_moves;
        std::vector<Move*> side_moves;
        for(int unsigned i=0;i<this->J1->get_boules().size();i++)
        {
            for(int unsigned k=0;k<this->J1->get_boules()[i]->get_possible_moves().size();k++)
            {
                Move *temp=new Move(this->J1->get_boules()[i],this->J1->get_boules()[i]->get_possible_moves()[k]);
                if (this->J1->get_boules()[i]->get_possible_moves()[k]->pos().ry()-this->J1->get_boules()[i]->pos().ry() >0)
                    this->random_ai_moves.push_back(temp);
                else if(this->J1->get_boules()[i]->get_possible_moves()[k]->pos().ry()-this->J1->get_boules()[i]->pos().ry()==0) side_moves.push_back(temp);
                else {
                    backward_moves.push_back(temp);
                }
            }
        }
        if(this->random_ai_moves.size()==0) this->random_ai_moves=side_moves;
        if(this->random_ai_moves.size()==0) this->random_ai_moves=backward_moves;
    }

}

void MainWindow::make_random_ai_move()
{     set_random_ai_moves();

      //khsni nzid l conditions t win

      int i=rand()%this->random_ai_moves.size();
        this->random_ai_moves[i]->get_one_to_move()->setPos(this->random_ai_moves[i]->get_to()->pos());
        this->random_ai_moves[i]->get_one_to_move()->get_current_pos()->set_rempli(false);
        this->random_ai_moves[i]->get_one_to_move()->get_current_pos()->update();
        if(this->random_ai_moves[i]->get_to()->get_emplacement_special()==this->random_ai_moves[i]->get_one_to_move()->get_color() )
        {
            this->get_Joueur(this->get_turn())->change_score(1);
            qDebug()<<"zidni<<"<<this->get_Joueur(this->get_turn())->get_score();
        }
        if(this->random_ai_moves[i]->get_one_to_move()->get_current_pos()->get_emplacement_special()==this->random_ai_moves[i]->get_one_to_move()->get_color())
        {
            this->get_Joueur(this->get_turn())->change_score(-1);
            qDebug()<<"n9sni<<"<<this->get_Joueur(this->get_turn())->get_score();
        }
        this->random_ai_moves[i]->get_to()->set_rempli(true);
          this->random_ai_moves[i]->get_one_to_move()->set_current_pos(this->random_ai_moves[i]->get_to());
          check_win();
            swap_turn();
}

std::vector<Move *> MainWindow::get_ev_moves()
{
    return this->ev_ai_moves;
}

void MainWindow::on_pushButton_3_clicked()
{
    MyDialog mDialog;
    mDialog.setModal(true);
    mDialog.exec();
}


void MainWindow::on_pushButton_clicked()
{
    MyConfig mConfig;
    mConfig.setModal(true);
    mConfig.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    redraw_board();
}
