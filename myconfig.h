#ifndef MYCONFIG_H
#define MYCONFIG_H

#include <QDialog>

namespace Ui {
class MyConfig;
}

class MyConfig : public QDialog
{
    Q_OBJECT

public:
    explicit MyConfig(QWidget *parent = nullptr);
    ~MyConfig();

private slots:


    void on_pushButton_clicked();


    void on_radioButton_3_clicked(bool checked);

    void on_radioButton_4_clicked(bool checked);

    void on_radioButton_5_clicked(bool checked);

    void on_radioButton_7_clicked(bool checked);

    void on_radioButton_6_clicked(bool checked);

    void on_radioButton_2_clicked(bool checked);

    void on_radioButton_clicked(bool checked);

    void on_radioButton_2_clicked();

    void on_radioButton_8_clicked(bool checked);

private:
    Ui::MyConfig *ui;
};

#endif // MYCONFIG_H
