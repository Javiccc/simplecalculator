#include "simplecalculator.h"
#include "ui_simplecalculator.h"

SimpleCalculator::SimpleCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimpleCalculator)
{
    ui->setupUi(this);

    //connect functions for digits
    connect(ui->Button0, SIGNAL(clicked(bool)), this, SLOT(on_Button0_clicked()), Qt::UniqueConnection);
    connect(ui->Button1, SIGNAL(clicked(bool)), this, SLOT(on_Button1_clicked()), Qt::UniqueConnection);
    connect(ui->Button2, SIGNAL(clicked(bool)), this, SLOT(on_Button2_clicked()), Qt::UniqueConnection);
    connect(ui->Button3, SIGNAL(clicked(bool)), this, SLOT(on_Button3_clicked()), Qt::UniqueConnection);
    connect(ui->Button4, SIGNAL(clicked(bool)), this, SLOT(on_Button4_clicked()), Qt::UniqueConnection);
    connect(ui->Button5, SIGNAL(clicked(bool)), this, SLOT(on_Button5_clicked()), Qt::UniqueConnection);
    connect(ui->Button6, SIGNAL(clicked(bool)), this, SLOT(on_Button6_clicked()), Qt::UniqueConnection);
    connect(ui->Button7, SIGNAL(clicked(bool)), this, SLOT(on_Button7_clicked()), Qt::UniqueConnection);
    connect(ui->Button8, SIGNAL(clicked(bool)), this, SLOT(on_Button8_clicked()), Qt::UniqueConnection);
    connect(ui->Button9, SIGNAL(clicked(bool)), this, SLOT(on_Button9_clicked()), Qt::UniqueConnection);

    //connect functions for manipulate
    connect(ui->clear, SIGNAL(clicked(bool)), this, SLOT(on_clear_clicked()), Qt::UniqueConnection);
    connect(ui->add, SIGNAL(clicked(bool)), this, SLOT(on_add_clicked()), Qt::UniqueConnection);
    connect(ui->substract, SIGNAL(clicked(bool)), this, SLOT(on_substract_clicked()), Qt::UniqueConnection);
    connect(ui->product, SIGNAL(clicked(bool)), this, SLOT(on_product_clicked()), Qt::UniqueConnection);
    connect(ui->divide, SIGNAL(clicked(bool)), this, SLOT(on_divide_clicked()), Qt::UniqueConnection);
    connect(ui->delect, SIGNAL(clicked(bool)), this, SLOT(on_delect_clicked()), Qt::UniqueConnection);
    connect(ui->equal, SIGNAL(clicked(bool)), this, SLOT(on_equal_clicked()), Qt::UniqueConnection);
    connect(ui->dot, SIGNAL(clicked(bool)), this, SLOT(on_dot_clicked()), Qt::UniqueConnection);

}

SimpleCalculator::~SimpleCalculator()
{
    delete ui;
}



void SimpleCalculator::on_Button0_clicked()
{
    digit0 = ui->Button0->text();
    line += digit0;
    ui->lineEdit->setText(line);
}

void SimpleCalculator::on_Button1_clicked()
{
    digit1 = ui->Button1->text();
    line += digit1;
    ui->lineEdit->setText(line);
}

void SimpleCalculator::on_Button2_clicked()
{
    digit2 = ui->Button2->text();
    line += digit2;
    ui->lineEdit->setText(line);
}

void SimpleCalculator::on_Button3_clicked()
{
    digit3 = ui->Button3->text();
    line += digit3;
    ui->lineEdit->setText(line);
}

void SimpleCalculator::on_Button4_clicked()
{
    digit4 = ui->Button4->text();
    line += digit4;
    ui->lineEdit->setText(line);
}

void SimpleCalculator::on_Button5_clicked()
{
    digit5 = ui->Button5->text();
    line += digit5;
    ui->lineEdit->setText(line);
}

void SimpleCalculator::on_Button6_clicked()
{
    digit6 = ui->Button6->text();
    line += digit6;
    ui->lineEdit->setText(line);
}

void SimpleCalculator::on_Button7_clicked()
{
    digit7 = ui->Button7->text();
    line += digit7;
    ui->lineEdit->setText(line);
}

void SimpleCalculator::on_Button8_clicked()
{
    digit8 = ui->Button8->text();
    line += digit8;
    ui->lineEdit->setText(line);
}

void SimpleCalculator::on_Button9_clicked()
{
    digit9 = ui->Button9->text();
    line += digit9;
    ui->lineEdit->setText(line);
}



void SimpleCalculator::on_dot_clicked()
{
    if(flagEqual == 0)
    {
        line += ".";
        ui->lineEdit->setText(line);
    }
    if(flagEqual == 1)
    {
        line = ui->lineEdit->text();
        line += ".";
        ui->lineEdit->setText(line);
        flagEqual = 0;
    }
}

void SimpleCalculator::on_delect_clicked()
{
    line = ui->lineEdit->text();    //reserve present text
    line.chop(1);   //delect the last digit
    ui->lineEdit->setText(line);
}

void SimpleCalculator::on_clear_clicked()
{//restart
    line.clear();
    temp1.clear();
    temp2.clear();
    result = 0;
    flagEqual = 0;
    flagAdd = 0;
    flagDivide = 0;
    flagSub = 0;
    flagProduct = 0;
    //output zero
    ui->lineEdit->setText(line);
}


void SimpleCalculator::on_add_clicked()
{
    flagAdd = 1;
    //get and reserve previous number
    temp1 = ui->lineEdit->text();
    line.clear();
    //clear the screen
    ui->lineEdit->setText(line);
}



void SimpleCalculator::on_substract_clicked()
{
    flagSub = 1;
    //get and reserve previous number
    temp1 = ui->lineEdit->text();
    line.clear();
    //clear the screen
    ui->lineEdit->setText(line);
}



void SimpleCalculator::on_product_clicked()
{
    flagProduct = 1;
    //get and reserve previous number
    temp1 = ui->lineEdit->text();
    line.clear();
    //clear the screen
    ui->lineEdit->setText(line);
}


void SimpleCalculator::on_divide_clicked()
{
    flagDivide = 1;
    //get and reserve previous number
    temp1 = ui->lineEdit->text();
    line.clear();
    //clear the screen
    ui->lineEdit->setText(line);
}

void SimpleCalculator::on_equal_clicked()
{
    flagEqual = 1;  //set equal tag to be true
    if(flagAdd == 1)
    {
        temp2 = ui->lineEdit->text();
        line.clear();
        result = temp1.toDouble() + temp2.toDouble();
        ui->lineEdit->setText(QString::number(result));
        //set add tag to be false
        flagAdd = 0;
    }

    else if(flagSub == 1)
    {
        temp2 = ui->lineEdit->text();
        line.clear();
        result = temp1.toDouble() - temp2.toDouble();

        if(result == 0)
        {
            ui->lineEdit->setText("0");
        }
        ui->lineEdit->setText(QString::number(result));
        //set substract tag to be false
        flagSub = 0;
    }
    else if(flagProduct == 1)
    {
        temp2 = ui->lineEdit->text();
        line.clear();
        result = temp1.toDouble() * temp2.toDouble();
        ui->lineEdit->setText(QString::number(result));
        //set product tag to be false
        flagProduct = 0;
    }
    else if(flagDivide == 1)
    {
        temp2 = ui->lineEdit->text();
        line.clear();
        result = temp1.toDouble() / temp2.toDouble();
        if(temp2 == "0")
        {//分子等于零
            ui->lineEdit->setText("0");
        }
        ui->lineEdit->setText(QString::number(result));
        //set product tag to be false
        flagProduct = 0;
    }
}
