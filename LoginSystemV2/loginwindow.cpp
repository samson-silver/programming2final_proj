#include "loginwindow.h"
#include "./ui_loginwindow.h"
#include "newuserwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked() //Login button
{
    QString username = ui->lineEdit_username->text(); //Converts text in textbox to QString
    QString password = ui->lineEdit_password->text(); //Converts text in textbox to QString
    QFile file(username + ".txt");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&file);
    QString user = in.readLine();
    QString pass = in.readLine();
    if (user == username && pass == password && user != "" && pass != "") {
        hide();
        ui->lineEdit_username->setText("");
        ui->lineEdit_password->setText("");
        homeWindow = new Dialog(this);
        homeWindow->show();
        QMessageBox::about(this, "Success", "Login successful");
    }
    else {
        QMessageBox::warning(this, "Login", "Username or Password is incorrect");
    }
}


void MainWindow::on_pushButton_signUp_clicked()
{
    newuserwindow *newUserWindow = new newuserwindow(this);
    newUserWindow->setModal(true);
    newUserWindow->exec();
}



void MainWindow::on_pushButton_quitlogin_clicked()
{
    this->close();
}
