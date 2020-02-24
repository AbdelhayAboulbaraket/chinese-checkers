#include "emplacement.h"
#include "mainwindow.h"

extern MainWindow *w;

void Emplacement::set_possible(bool b)
{
    this->possible=b;
}

bool Emplacement::get_rempli()
{
    return this->rempli;
}

void Emplacement::set_rempli(bool est_rempli)
{
    this->rempli=est_rempli;
}

Emplacement::Emplacement(int emplacement_special)
{
    this->emplacement_special=emplacement_special;
}

Emplacement::Emplacement(const Emplacement &F)
{

    this->setPos(F.pos());
    this->set_emplacement_special(F.emplacement_special);
    this->set_rempli(F.rempli);
    this->set_possible(F.possible);

}
Emplacement::~Emplacement()
{
}

QRectF Emplacement::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -10 - adjust, -10 - adjust, 23 + adjust, 23 + adjust);
}

void Emplacement::set_emplacement_special(int ok)
{
    this->emplacement_special=ok;
}

int Emplacement::get_emplacement_special()
{
    return this->emplacement_special;
}

void Emplacement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void)option; (void)widget;
    QRectF rect = boundingRect();
//    if(this->rempli==true)
//    {
//        painter->setBrush(Qt::green);
//    }
    if(possible)
    {
        painter->setBrush(Qt::cyan);
    }
    switch(this->emplacement_special)
    {
     case 1:
    {
        QPen pen(Qt::red,2); // emplacement d'arrive red
        painter->setPen(pen);
        break;
    }
    case 2:
    {
        QPen pen(QColor(255,99,71), 2);
        painter->setPen(pen);
        break;
    }
    case 3:
    {
        QPen pen(QColor(255,140,0), 2);
        painter->setPen(pen);
        break;
    }
    case 4:
    {
        QPen pen(QColor(0,56,178), 2);
        painter->setPen(pen);
        break;
    }
    case 5:
    {
        QPen pen(QColor(158,14,64), 2);
        painter->setPen(pen);
        break;
    }
    case 6:
    {
        QPen pen(QColor(34,139,34), 2);
        painter->setPen(pen);
        break;
    }
    case 7:
    {
        QPen pen(Qt::cyan, 2);
        painter->setPen(pen);
        break;
    }
    case 0:
    {
        QPen pen(Qt::white, 2);
        painter->setPen(pen);
        break;
    }

    }

    // painter->setBrush(Qt::red); // for coloring the circle;
    painter->drawEllipse(rect);



}

void Emplacement::mousePressEvent(QGraphicsSceneMouseEvent *event)
{   Q_UNUSED(event);
    if (this->possible==true )
    {
        if(this->get_emplacement_special()==w->get_movable()->get_color() )
        {
            w->get_Joueur(w->get_turn())->change_score(1);
            qDebug()<<"score ++<<"<<w->get_Joueur(w->get_turn())->get_score();
        }
        if(w->get_movable()->get_current_pos()->get_emplacement_special()==w->get_movable()->get_color())
        {
            w->get_Joueur(w->get_turn())->change_score(-1);
            qDebug()<<"score --<<"<<w->get_Joueur(w->get_turn())->get_score();
        }

        w->get_movable()->setPos(this->pos());
        w->get_movable()->get_current_pos()->set_rempli(false);
        w->get_movable()->update();
        this->set_rempli(true);
        w->get_movable()->set_current_pos(this);
        for(int unsigned i=0;i<w->get_movable()->get_possible_moves().size();i++)
        {
            w->get_movable()->get_possible_moves()[i]->set_possible(false);
            w->get_movable()->get_possible_moves()[i]->update();
        }
        w->get_movable()->setScale(1);
        w->set_movable(NULL);
        if(w->get_turn()==1)
        {
          w->check_win();
        }
        w->swap_turn();


        if(w->get_computer()!=0)
        {
          if(w->get_computer()==1) w->make_ev_ai_move();
          if(w->get_computer()==2) w->make_random_ai_move();
        }

    }
}
