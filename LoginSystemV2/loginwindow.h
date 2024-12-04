#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "homewindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_signUp_clicked();

    void on_pushButton_quitlogin_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *homeWindow;
};
#endif // LOGINWINDOW_H
