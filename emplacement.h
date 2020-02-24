#ifndef EMPLACEMENT_H
#define EMPLACEMENT_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsObject>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>



class Emplacement: public QGraphicsObject
{  Q_OBJECT
    private:

    int emplacement_special;
    bool rempli=false;
    bool possible=false;

 public:
        // Setters :
        void set_possible(bool b);
        void set_emplacement_special(int ok);
        void set_rempli(bool est_rempli=false);
        // getters :
        int get_emplacement_special();
        bool get_rempli();
        // constructeurs :
        Emplacement(int emplacement_special=0);
        Emplacement (const Emplacement &F);
        // destructeur :
        virtual ~Emplacement();
        // painting :
        QRectF boundingRect() const;
        void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

signals:


protected:

        void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

#endif // EMPLACEMENT_H
