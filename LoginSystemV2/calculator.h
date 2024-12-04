#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>

namespace Ui {
class calculator;
}

class calculator : public QDialog
{
    Q_OBJECT

public:
    explicit calculator(QWidget *parent = nullptr);
    ~calculator();

private:
    Ui::calculator *ui;

public slots:
    void numberPressed();
    void operationPressed();
    void equalPressed();
    void changeSignPressed();

private slots:
    void on_pushButton_quit_clicked();
    void on_pushButton_clear_clicked();
};

#endif // CALCULATOR_H
