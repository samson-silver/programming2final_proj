#include "clock_app.h"
#include "ui_clock_app.h"
#include <QDateTime>


clock_app::clock_app(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::clock_app)
{
    ui->setupUi(this);
    setWindowTitle("Clock");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(time_display()));
    timer->start(0);
}

clock_app::~clock_app()
{
    delete ui;
}

void clock_app::time_display() {
    QTime timeEST = QTime::currentTime();
    QString timeEST_text = timeEST.toString("hh:mm:ss");
    ui->label_timeEST->setText(timeEST_text);
}

void clock_app::on_pushButton_back_clicked()
{
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();
}

