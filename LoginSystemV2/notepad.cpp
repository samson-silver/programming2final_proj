#include "notepad.h"
#include "ui_notepad.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

notepad::notepad(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::notepad)
{
    ui->setupUi(this);
    setWindowTitle("Notepad");
}

notepad::~notepad()
{
    delete ui;
}

void notepad::on_pushButton_notepadback_clicked() //Closes notepad
{
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();
}


void notepad::on_pushButton_notepadNew_clicked()
{
    file_name = "";
    ui->textEdit->setText("");
}


void notepad::on_pushButton_notepadOpen_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Choose note to open");
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "..", "Unable to open file");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void notepad::on_pushButton_notepadsave_clicked()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Choose note to open");
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "..", "Unable to open file");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

