#ifndef JOUEUR_H
#define JOUEUR_H
#include "table.h"
#include "boule.h"
#include <QGraphicsScene>
class Table;
class Joueur
{
private :
    std::vector<Boule *> Boules;
    static int c;
    int id;
    int nbr_boule;
    int score=0;

public:
    // getters :
    std::vector<Boule *> get_boules();
    int get_score();
    int get_nbr_boule();
    int get_id();
    // autre:
    void push_to_boules(int i,Emplacement *Q);
    void clear_boules_moves();
    void change_score(int ok);
    // constructeur :
    Joueur(Table *table);
    // destructeur :
    ~Joueur();
};

#endif // JOUEUR_H
