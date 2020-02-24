#include <QApplication>
#include<QDebug>
#include "main.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w=new MainWindow();







    w->show();

    return a.exec();
}
