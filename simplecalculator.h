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

private:
    Ui::SimpleCalculator *ui;
};

#endif // SIMPLECALCULATOR_H
