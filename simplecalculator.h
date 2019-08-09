#ifndef SIMPLECALCULATOR_H
#define SIMPLECALCULATOR_H

#include <QMainWindow>

namespace Ui {
class SimpleCalculator;
}

class SimpleCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimpleCalculator(QWidget *parent = 0);
    ~SimpleCalculator();

private slots:
    void on_Button0_clicked();

    void on_Button1_clicked();

    void on_Button2_clicked();

    void on_Button3_clicked();

    void on_Button4_clicked();

    void on_Button5_clicked();

    void on_Button6_clicked();

    void on_Button7_clicked();

    void on_Button8_clicked();

    void on_Button9_clicked();

    void on_dot_clicked();

    void on_delect_clicked();

    void on_clear_clicked();

    void on_add_clicked();

    void on_substract_clicked();

    void on_product_clicked();

    void on_divide_clicked();

    void on_equal_clicked();

private:
    Ui::SimpleCalculator *ui;

    //text to be display
    QString line;
    //digit 0
    QString digit0;
    //digit 1
    QString digit1;
    //digit 2
    QString digit2;
    //digit 3
    QString digit3;
    //digit 4
    QString digit4;
    //digit 5
    QString digit5;
    //digit 6
    QString digit6;
    //digit 7
    QString digit7;
    //digit 8
    QString digit8;
    //digit 9
    QString digit9;
    //temporary number
    QString temp1;
    QString temp2;

    //result
    double result;

    //flag to record the type of manipulate
    int flagEqual = 0;  //record equal
    int flagAdd = 0;    //record add
    int flagSub = 0;
    int flagProduct = 0;
    int flagDivide = 0;

};

#endif // SIMPLECALCULATOR_H
