#include "move.h"

Move::Move(Boule *A, Emplacement *B)
{
    this->the_one_to_move=A;
    this->to=B;
}

Boule *Move::get_one_to_move()
{
    return this->the_one_to_move;
}

Emplacement *Move::get_to()
{
    return this->to;
}

void Move::set_how_good(double score)
{
    this->how_good_it_is=score;
}
