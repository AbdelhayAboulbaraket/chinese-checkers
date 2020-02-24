#ifndef BOULE_H
#define BOULE_H
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsObject>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QtDebug>
#include <emplacement.h>

class Boule: public QGraphicsObject
{  Q_OBJECT
    private:
    int id;
    int color;
    Emplacement *current_pos; // l'emplacement sur lequel reside cette boule.
    std::vector<Emplacement*> possible_moves; // l'ensemble des emplacements ou pourra se déplacer cette boule.
    std::vector<Emplacement*> restricted_moves; // L'ensemble des emplacements ou pourra se déplacer cette mais n'a pas le droit ( Triangle different du triangle d'arrivée et de départ)

 public:
    // Constructeurs:
       Boule();
       Boule (const Boule & F);
       // setters :
       void set_id(int id);
       void set_current_pos(Emplacement *a);
       void setcolor(int a);
       // getters
       std::vector<Emplacement*> get_restricted_moves();
       std::vector<Emplacement*> get_possible_moves();
       Emplacement *get_current_pos();
       int get_id();
       int get_color();
       // Painting :
       QRectF boundingRect() const;
       void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
       // Autre :
       void push_to_restricted(Emplacement*E);
       void push_to_moves(Emplacement *E); // possible_moves.pushback(E);
       void clear_moves(); // possible_moves.clear();
       // Destructeur:
       virtual ~Boule();


signals:


protected:

             void mousePressEvent (QGraphicsSceneMouseEvent *event);


};



#endif // BOULE_H
