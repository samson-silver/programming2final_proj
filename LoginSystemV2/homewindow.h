#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_logOut_clicked();

    void on_pushButton_notepad_clicked();

    void on_pushButton_clock_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // HOMEWINDOW_H
