#ifndef MOVE_H
#define MOVE_H
#include "emplacement.h"
#include "boule.h"


class Move
{
private:
    Boule *the_one_to_move;
    Emplacement *to;
    double how_good_it_is;
public:
    // constructeur :
    Move(Boule *A,Emplacement *B);
    // getters :
    Boule *get_one_to_move();
    Emplacement *get_to();
    // setters :
    void set_how_good(double score);

};

#endif // MOVE_H
