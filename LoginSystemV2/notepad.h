#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QDialog>

namespace Ui {
class notepad;
}

class notepad : public QDialog
{
    Q_OBJECT

public:
    explicit notepad(QWidget *parent = nullptr);
    ~notepad();

private slots:

    void on_pushButton_notepadback_clicked();

    void on_pushButton_notepadNew_clicked();

    void on_pushButton_notepadOpen_clicked();

    void on_pushButton_notepadsave_clicked();

private:
    Ui::notepad *ui;
    QString file_name;
};

#endif // NOTEPAD_H
