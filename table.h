#ifndef TABLE_H
#define TABLE_H
#include <vector>
#include "emplacement.h"
#include <QGraphicsScene>
#include "joueur.h"
class Table
{
private:


    QGraphicsScene *m_scene;
    int base_triangle;
    int mode;
    std::vector<std::vector<Emplacement*>> EmplacementdeJoueur1; // EmplacementdeJoueur1[i] contient 10 emplacements qui appartiennent au meme triangle
    std::vector<std::vector<Emplacement*>> EmplacementdeJoueur2;
    std::vector<Emplacement*> Emplacements; // contient tous les emplacements du jeu (121 ) .

public:
    int get_mode();
    Emplacement * getByPos(QPointF B);
    Table(int mode,QGraphicsScene *scene);
    virtual ~Table();
    friend class Joueur;

};

#endif // TABLE_H
