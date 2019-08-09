#include "simplecalculator.h"
#include "ui_simplecalculator.h"

SimpleCalculator::SimpleCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimpleCalculator)
{
    ui->setupUi(this);
}

SimpleCalculator::~SimpleCalculator()
{
    delete ui;
}
