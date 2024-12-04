#include "homewindow.h"
#include "ui_homewindow.h"
#include "notepad.h"
#include "clock_app.h"
#include "calculator.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_notepad_clicked()
{
    notepad *Notepad = new notepad(this);
    Notepad->show();
}

void Dialog::on_pushButton_clock_clicked()
{
    clock_app *Clock = new clock_app(this);
    Clock->show();
}

void Dialog::on_pushButton_logOut_clicked()
{
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();
}




void Dialog::on_pushButton_clicked()
{
    calculator *Calc = new calculator(this);
    Calc->show();
}

