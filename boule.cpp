#include "boule.h"
#include "mainwindow.h"
extern MainWindow *w;
Boule::Boule()
{

}

void Boule::set_id(int id)
{
    this->id=id;
}

Boule::Boule(const Boule &F)
{
    this->setPos(F.pos());
    this->setcolor(color);
    this->set_current_pos(F.current_pos);

}

std::vector<Emplacement *> Boule::get_restricted_moves()
{
    return this->restricted_moves;
}

void Boule::push_to_restricted(Emplacement *E)
{
    this->restricted_moves.push_back(E);
}

void Boule::push_to_moves(Emplacement *E)
{
    this->possible_moves.push_back(E);
}

void Boule::clear_moves()
{
    this->possible_moves.clear();
    this->restricted_moves.clear();
}

std::vector<Emplacement*> Boule::get_possible_moves()
{
    std::vector<Emplacement*> copy=this->possible_moves;
    return copy;
}

Boule::~Boule()
{

}

void Boule::set_current_pos(Emplacement *a)
{
    this->current_pos=a;
}

Emplacement *Boule::get_current_pos()
{
    Emplacement* copy=this->current_pos;
    return copy;
}

void Boule::setcolor(int a)
{
    this->color=a;
}

QRectF Boule::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -10 - 2, -10 - 2, 23 + 2, 23 + 2);
}

void Boule::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    (void)option; (void)widget;

    QRectF rect = boundingRect();
    QPen pen(Qt::black, 2);



    switch(color) {
    case 1 : painter->setBrush(Qt::red); // for coloring the circle;
        break;
    case 2 : painter->setBrush(QColor(255,99,71)); // for coloring the circle;
        break;
    case 3 : painter->setBrush(QColor(255,140,0)); // for coloring the circle;
        break;
    case 4 : painter->setBrush(QColor(0,56,178)); // for coloring the circle;
        break;
    case 5 : painter->setBrush(QColor(158,14,64)); // for coloring the circle;
        break;
    case 6 : painter->setBrush(QColor(34,139,34)); // for coloring the circle;
        break;
    }
    painter->setPen(pen);
    painter->drawEllipse(rect);
    QPen pen1(Qt::white,2);
    painter->setPen(pen1);
    QRectF recto=boundingRect();
    recto.adjust(7.5,7.5,7.5,7.5);
    QString s = QString::number(this->get_id());
    painter->drawText(recto,s);

    //setMouseTracking(true);

}

int Boule::get_id()
{
    return this->id;
}

int Boule::get_color()
{
    return this->color;
}

void Boule::mousePressEvent(QGraphicsSceneMouseEvent *event)
{   Q_UNUSED(event);
    if (w->get_movable()==NULL && w->get_turn()==this->id && w->get_game_in_progress()==true)
    {   w->all_allowed_moves();
        this->setScale(1.3);
        w->set_movable(this);
        for(int unsigned i=0;i<w->get_movable()->get_possible_moves().size();i++)
        {
            w->get_movable()->get_possible_moves()[i]->set_possible(true);
            w->get_movable()->get_possible_moves()[i]->update();
        }
    }
    else if(w->get_movable()!=NULL && w->get_turn()==this->id && w->get_game_in_progress()==true )
    {   w->get_movable()->setScale(1);
        this->setScale(1.3);
        for(int unsigned i=0;i<w->get_movable()->get_possible_moves().size();i++)
        {
            w->get_movable()->get_possible_moves()[i]->set_possible(false);
            w->get_movable()->get_possible_moves()[i]->update();
        }
        w->set_movable(this);
        for(int unsigned i=0;i<w->get_movable()->get_possible_moves().size();i++)
        {
            w->get_movable()->get_possible_moves()[i]->set_possible(true);
            w->get_movable()->get_possible_moves()[i]->update();
        }

    }


}
