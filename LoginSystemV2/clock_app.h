#ifndef CLOCK_APP_H
#define CLOCK_APP_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class clock_app;
}

class clock_app : public QDialog
{
    Q_OBJECT

public:
    explicit clock_app(QWidget *parent = nullptr);
    ~clock_app();

public slots:
    void time_display();

private slots:
    void on_pushButton_back_clicked();

private:
    Ui::clock_app *ui;
    QTimer *timer;
};

#endif // CLOCK_APP_H
