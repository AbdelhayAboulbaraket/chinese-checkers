#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QMainWindow>
#include "table.h"
#include"mydialog.h"
#include"myconfig.h"
#include "move.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // contructeur :
    explicit MainWindow(QWidget *parent = 0);
    // getters :
    Boule *get_movable();
    int get_mode();
    int get_turn();
    Joueur * get_Joueur(int n);
    bool get_game_in_progress();
    bool get_variante_rapide();
    void set_variante_rapide(bool ok);
    int get_computer();
    std::vector<Move*> get_ev_moves();


    // generation de mouvements :

    // variante normale :
    QPointF jump(QPointF position,int direction);
    bool deja_traite(Boule *Q,Emplacement *E);
    void hop_recu(Boule *Q,QPointF pos);
    void all_hop_moves();
    void all_jump_moves();
    void all_allowed_moves();

    // variante rapide :
    void all_fast_moves();
    void fast_recu(Boule *boule, QPointF position);
    int compteur(int color,QPointF position, int cmpt,int l);


    // setters :
    void set_movable(Boule *B);
    void set_mode(int n);
    void set_computer(int ok);

    // autre:
    void swap_turn();
    int check_win();
    void redraw_board();

    // AI
    int set_ev_ai_moves();
    void make_ev_ai_move();
    void set_random_ai_moves();
    void make_random_ai_move();

    // destructeur :
    ~MainWindow();

private slots:


    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    MyDialog *mDialog;
    MyConfig *mConfig;
    QGraphicsScene *m_scene;
    Table *m_table;
    Joueur *J1;
    Joueur *J2;
    Boule *movable;
    int turn;
    bool game_in_progress;
    bool variante_rapide;
    int mode;
    int computer=1;
    std::vector<Move*> ev_ai_moves;
    std::vector<Move*> random_ai_moves;




};

#endif // MAINWINDOW_H
