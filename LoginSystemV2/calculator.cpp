#include "calculator.h"
#include "ui_calculator.h"

double value = 0.0;
bool addCondition = false;
bool subCondition = false;
bool multCondition = false;
bool divCondition = false;

calculator::calculator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::calculator)
{
    ui->setupUi(this);
    setWindowTitle("Calculator");
    ui->display->setText(QString::number(value));
    QPushButton *numbers[10];
    for (int i = 0; i < 10; i++) {

        QString buttonName = "pushButton_" + QString::number(i);
        numbers[i] = calculator::findChild<QPushButton *>(buttonName);
        connect(numbers[i], SIGNAL(released()), this, SLOT(numberPressed()));
    }

    connect(ui->pushButton_plus, SIGNAL(released()), this, SLOT(operationPressed()));
    connect(ui->pushButton_subtract, SIGNAL(released()), this, SLOT(operationPressed()));
    connect(ui->pushButton_multiply, SIGNAL(released()), this, SLOT(operationPressed()));
    connect(ui->pushButton_divide, SIGNAL(released()), this, SLOT(operationPressed()));

    connect(ui->pushButton_equals, SIGNAL(released()), this, SLOT(equalPressed()));
    connect(ui->pushButton_sign, SIGNAL(released()), this, SLOT(changeSignPressed()));

}

calculator::~calculator()
{

    delete ui;
}

void calculator::numberPressed() {
    QPushButton *button = (QPushButton *)sender();
    QString buttonVal = button->text();
    QString displayVal = ui->display->text();

    if (displayVal.toDouble() == 0 || displayVal.toDouble() == 0.0) {
        ui->display->setText(buttonVal);
    } else {
        QString newValue = displayVal + buttonVal;
        double newValueDouble = newValue.toDouble();
        ui->display->setText(QString::number(newValueDouble, 'g', 16));
    }
}

void calculator::operationPressed() {

    addCondition = false;
    subCondition = false;
    multCondition = false;
    divCondition = false;

    QString displayVal = ui->display->text();
    value = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString buttonVal = button->text();

    if (QString::compare(buttonVal, "+") == 0)
        addCondition = true;
    else if (QString::compare(buttonVal, "-") == 0)
        subCondition = true;
    else if (QString::compare(buttonVal, "*") == 0)
        multCondition = true;
    else if (QString::compare(buttonVal, "/") == 0)
        divCondition = true;

        ui->display->setText("");

}

void calculator::equalPressed() {

    double answer = 0.0;
    QString displayVal = ui->display->text();
    double displayValDouble = displayVal.toDouble();

    if (addCondition || subCondition || multCondition || divCondition) {
        if (addCondition)
            answer = value + displayValDouble;
        if (subCondition)
            answer = value - displayValDouble;
        if (multCondition)
            answer = value * displayValDouble;
        if (divCondition)
            answer = value / displayValDouble;
    }

    ui->display->setText(QString::number(answer));

}

void calculator::changeSignPressed() {

    QString displayVal = ui->display->text();
    double displayValDouble = displayVal.toDouble();
    displayValDouble *= -1;
    ui->display->setText(QString::number(displayValDouble));

};

void calculator::on_pushButton_quit_clicked()
{
    value = 0.0;
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();
}


void calculator::on_pushButton_clear_clicked()
{
    value = 0.0;
    ui->display->setText(QString::number(value));
}

