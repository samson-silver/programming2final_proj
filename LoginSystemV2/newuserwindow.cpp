#include "newuserwindow.h"
#include "ui_newuserwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

newuserwindow::newuserwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::newuserwindow)
{
    ui->setupUi(this);
}

newuserwindow::~newuserwindow()
{
    delete ui;
}

void newuserwindow::on_pushButton_createnew_clicked()
{
    QString firstname = ui->lineEdit_firstname->text();
    QString lastname = ui->lineEdit_lastname->text();
    QString newUsername = ui->lineEdit_newusername->text();
    QString newPassword = ui->lineEdit_newpassword->text();
    QString passConfirm = ui->lineEdit_passconfirm->text();
    if (firstname == "" || lastname == "" || newUsername == "" || newPassword == "" || passConfirm == "") {
        QMessageBox::warning(this, "..", "All fields must be filled out");
        return;
    }
    if (newPassword != passConfirm) {
        QMessageBox::warning(this, "..", "Passwords do not match");
        return;
    }
    QFile file(newUsername + ".txt");
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&file);
    out << newUsername << '\n' << newPassword << '\n';
    out << firstname << '\n' << lastname;
    file.flush();
    file.close();
    QMessageBox::about(this, "Success", "User successfully added");
    close();
}


void newuserwindow::on_pushButton_cancelnew_clicked()
{
    close();
}

