#include "table.h"
#include <random>
#include <iostream>
#include <QTimer>
#include <QEventLoop>
#include <QLabel>
class Emplacement;

int Table::get_mode()
{
    return this->mode;    }

Emplacement *Table::getByPos(QPointF B)
{   Emplacement *emplacement=new Emplacement(0);
    emplacement->setPos(1000,1000);
    for(int unsigned i=0;i<Emplacements.size();i++){
        if(Emplacements[i]->pos()==B) return Emplacements[i];
    }
    return emplacement;
}

Table::Table(int mode,QGraphicsScene *scene)
{
    this->mode=mode;
    this->m_scene=scene;
    this->base_triangle=4;


    int itf=13;
    bool iter=true;
    double origin=225;
    double pas=30;
    int tmp_1= base_triangle;



    // 10 boules par joueur
    if (mode==1){
        std::vector<Emplacement *> temp1_0;
        std::vector<Emplacement *> temp2_0;


        for(int i=1;i<=17;i++)
        {



            if(i<=base_triangle)
            {
                origin=250-(i-1)*pas/2;

                for(int l=1;l<=i;l++)
                {
                    Emplacement *emplacement= new Emplacement(4);
                    temp1_0.push_back(emplacement);
                    emplacement->set_rempli(true);
                    Emplacements.push_back(emplacement);
                    emplacement->setPos(origin+=pas,i*pas);
                    scene->addItem(emplacement);
                }

            }


            else if(i>=base_triangle+1 && i<=13)
            {
                std::cout<< itf << std::endl;
                origin=250-(itf-1)*pas/2;
                for(int l=0;l<itf;l++)
                {


                    Emplacement *emplacement= new Emplacement(0);
                    Emplacements.push_back(emplacement);


                    if(iter)
                    {
                        if(l<tmp_1)
                            emplacement->set_emplacement_special(7);

                        else if(l>itf-1-(tmp_1))
                        {
                            emplacement->set_emplacement_special(7);
                            if(l==itf-1)tmp_1--;
                        }

                    }

                    else if(!iter && itf!=(2*(base_triangle+1)-1))
                    {
                        if(l<=tmp_1)
                        {
                            emplacement->set_emplacement_special(7);
                        }
                        else if(l>=itf-1-(tmp_1))
                        {
                            emplacement->set_emplacement_special(7);
                            if(l==itf-1) tmp_1++;
                        }

                    }
                    emplacement->setPos(origin+=pas,pas*i);
                    scene->addItem(emplacement);


                }
                (iter==true)?(itf--):(itf++);

                (itf==(2*(base_triangle+1)-1))?iter=false:NULL;


            }


            else if(i>(2*base_triangle+2*(base_triangle+1)-1)-base_triangle){
               origin=250-((2*base_triangle+2*(base_triangle+1)-1)-i)*pas/2;
                for(int l=i;l<=(2*base_triangle+2*(base_triangle+1)-1);l++)
                {
                    Emplacement *emplacement= new Emplacement(1);
                    temp2_0.push_back(emplacement);
                    emplacement->set_rempli(true);
                    Emplacements.push_back(emplacement);
                    emplacement->setPos(origin+=pas,pas*i);
                    scene->addItem(emplacement);



                }
            }

        }
        EmplacementdeJoueur1.push_back(temp1_0);
        EmplacementdeJoueur2.push_back(temp2_0);
    }// Sala l mode 1

    if (mode==3)
    {   std::vector<Emplacement *> temp1_0;
        std::vector<Emplacement *> temp1_1;
        std::vector<Emplacement *> temp1_2;
        std::vector<Emplacement *> temp2_0;
        std::vector<Emplacement *> temp2_1;
        std::vector<Emplacement *> temp2_2;
        for(int i=1;i<=17;i++)
        {


            if(i<=base_triangle)
            {
                origin=250-(i-1)*pas/2;

                for(int l=1;l<=i;l++)
                {
                    Emplacement *emplacement= new Emplacement(4); // Emplacement d'arrive des boules BLEU
                    temp1_0.push_back(emplacement); // Premiere 10 boules du joueur 1
                    emplacement->set_rempli(true);
                    Emplacements.push_back(emplacement);
                    emplacement->setPos(origin+=pas,i*pas);
                    scene->addItem(emplacement);
                }

            }


            else if(i>=base_triangle+1 && i<=13)
            {              std::cout<< itf << std::endl;
                origin=250-(itf-1)*pas/2;
                for(int l=0;l<itf;l++)
                {


                    Emplacement *emplacement= new Emplacement(0);
                    Emplacements.push_back(emplacement);


                    if(iter)
                    {
                        if(l<tmp_1)
                        {
                            emplacement->set_emplacement_special(6);
                            emplacement->set_rempli(true);
                            temp1_1.push_back(emplacement); // 2eme 10boules du joueur1



                        }
                        else if(l>itf-1-(tmp_1))
                        {
                            emplacement->set_emplacement_special(5); // MAGENTA
                            temp1_2.push_back(emplacement); // 3eme 10 boules du joueur 1
                            emplacement->set_rempli(true);


                            if(l==itf-1)
                            {
                                tmp_1--;
                            }
                        }

                    }

                    else if(!iter && itf!=(2*(base_triangle+1)-1))
                    {
                        if(l<=tmp_1)
                        {
                            emplacement->set_emplacement_special(2); // JAUNE
                            temp2_0.push_back(emplacement);
                            emplacement->set_rempli(true);



                        }
                        else if(l>=itf-1-(tmp_1))
                        {
                            emplacement->set_emplacement_special(3); // VERT
                            temp2_1.push_back(emplacement);
                            emplacement->set_rempli(true);


                            if(l==itf-1)
                            {
                                tmp_1++;
                            }
                        }

                    }
                    emplacement->setPos(origin+=pas,pas*i);
                    scene->addItem(emplacement);


                }
                (iter==true)?(itf--):(itf++);

                (itf==(2*(base_triangle+1)-1))?iter=false:NULL;


            }


            else if(i>(2*base_triangle+2*(base_triangle+1)-1)-base_triangle){
                origin=250-((2*base_triangle+2*(base_triangle+1)-1)-i)*pas/2;
                for(int l=i;l<=(2*base_triangle+2*(base_triangle+1)-1);l++)
                {
                    Emplacement *emplacement= new Emplacement(1); // ROUGE
                    temp2_2.push_back(emplacement);
                    emplacement->set_rempli(true);
                    Emplacements.push_back(emplacement);
                    emplacement->setPos(origin+=pas,pas*i);
                    scene->addItem(emplacement);



                }
            }


        }
        EmplacementdeJoueur1.push_back(temp1_0);
        EmplacementdeJoueur1.push_back(temp1_2);
        EmplacementdeJoueur1.push_back(temp1_1);
        EmplacementdeJoueur2.push_back(temp2_2);
        EmplacementdeJoueur2.push_back(temp2_0);
        EmplacementdeJoueur2.push_back(temp2_1);


    } // sala mode 3
    if (mode==2)
    {   std::vector<Emplacement *> temp1_0;
        std::vector<Emplacement *> temp1_1;

        std::vector<Emplacement *> temp2_0;
        std::vector<Emplacement *> temp2_1;

        for(int i=1;i<=17;i++)
        {



            if(i<=base_triangle)
            {
                origin=250-(i-1)*pas/2;

                for(int l=1;l<=i;l++)
                {
                    Emplacement *emplacement= new Emplacement(4);
                    Emplacements.push_back(emplacement);
                    temp1_0.push_back(emplacement);
                    emplacement->set_rempli(true);

                    emplacement->setPos(origin+=pas,i*pas);
                    scene->addItem(emplacement);
                }

            }


            else if(i>=base_triangle+1 && i<=13)
            {              std::cout<< itf << std::endl;
                origin=250-(itf-1)*pas/2;
                for(int l=0;l<itf;l++)
                {


                    Emplacement *emplacement= new Emplacement(0);
                    Emplacements.push_back(emplacement);


                    if(iter)
                    {
                        if(l<tmp_1)
                        {
                            emplacement->set_emplacement_special(7);




                        }
                        else if(l>itf-1-(tmp_1))
                        {
                            emplacement->set_emplacement_special(5);
                           temp1_1.push_back(emplacement);
                            emplacement->set_rempli(true);


                            if(l==itf-1)
                            {
                                tmp_1--;
                            }
                        }

                    }

                    else if(!iter && itf!=(2*(base_triangle+1)-1))
                    {
                        if(l<=tmp_1)
                        {
                            emplacement->set_emplacement_special(2);
                            temp2_0.push_back(emplacement);
                            emplacement->set_rempli(true);



                        }
                        else if(l>=itf-1-(tmp_1))
                        {
                            emplacement->set_emplacement_special(7);
                            if(l==itf-1)
                            {
                                tmp_1++;
                            }
                        }

                    }
                    emplacement->setPos(origin+=pas,pas*i);
                    scene->addItem(emplacement);


                }
                (iter==true)?(itf--):(itf++);

                (itf==(2*(base_triangle+1)-1))?iter=false:NULL;


            }


            else if(i>(2*base_triangle+2*(base_triangle+1)-1)-base_triangle){
                origin=250-((2*base_triangle+2*(base_triangle+1)-1)-i)*pas/2;
                for(int l=i;l<=(2*base_triangle+2*(base_triangle+1)-1);l++)
                {
                    Emplacement *emplacement= new Emplacement(1);
                    temp2_1.push_back(emplacement);
                    emplacement->set_rempli(true);
                    Emplacements.push_back(emplacement);
                    emplacement->setPos(origin+=pas,pas*i);
                    scene->addItem(emplacement);



                }
            }

        }
        EmplacementdeJoueur1.push_back(temp1_0);
        EmplacementdeJoueur1.push_back(temp1_1);
        EmplacementdeJoueur2.push_back(temp2_1);
        EmplacementdeJoueur2.push_back(temp2_0);


    }

}
Table::~Table()
{

}


