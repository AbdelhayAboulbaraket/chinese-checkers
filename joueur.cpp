#include "joueur.h"
class Boule;
std::vector<Boule *> Joueur::get_boules()
{
    std::vector<Boule *> copy=this->Boules;
    return copy;
}

void Joueur::push_to_boules(int i, Emplacement *Q)
{
    this->Boules[i]->push_to_moves(Q);
}

void Joueur::clear_boules_moves()
{
    for (unsigned int i=0;i<this->get_boules().size();i++)
    {
        this->Boules[i]->clear_moves();
    } // supprimer tous les mouvements précédents.
}

int Joueur::get_score()
{
    return this->score;
}

int Joueur::get_nbr_boule()
{
    return this->nbr_boule;
}

void Joueur::change_score(int ok)
{
    this->score+=ok;
}

int Joueur::get_id()
{
    return this->id;
}


Joueur::Joueur(Table *table)
{
    this->id=++c;
    this->nbr_boule=table->get_mode()*10;

    for(int i=0;i<nbr_boule;i++)
    {
         Boule *boule= new Boule();
         boule->set_id(this->id);
         boule->setcolor((id-1)*3+(i/10)+1);
         Boules.push_back(boule);
        switch(id) {
            case 1 :
                      boule->setPos(table->EmplacementdeJoueur1[i/10][i%10]->pos());
                      boule->set_current_pos(table->EmplacementdeJoueur1[i/10][i%10]);

                     break;       // and exits the switch
            case 2 :
            boule->setPos(table->EmplacementdeJoueur2[i/10][i%10]->pos());
            boule->set_current_pos(table->EmplacementdeJoueur2[i/10][i%10]);
                     break;

        }
        table->m_scene->addItem(boule);


    }

}

Joueur::~Joueur()
{
this->c--;
}
 int Joueur::c=0;
