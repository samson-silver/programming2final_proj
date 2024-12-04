#ifndef NEWUSERWINDOW_H
#define NEWUSERWINDOW_H

#include <QDialog>
#include <QVector>

namespace Ui {
class newuserwindow;
}

class newuserwindow : public QDialog
{
    Q_OBJECT

public:
    explicit newuserwindow(QWidget *parent = nullptr);
    ~newuserwindow();

private slots:
    void on_pushButton_createnew_clicked();

    void on_pushButton_cancelnew_clicked();

private:
    Ui::newuserwindow *ui;
};

#endif // NEWUSERWINDOW_H
