#ifndef TRAINING_H
#define TRAINING_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class Training;
}

class Training : public QWidget
{
    Q_OBJECT

public:
    explicit Training(QWidget *parent = 0);
    ~Training();

private slots:
    void receiveshow();

private:
    Ui::Training *ui;

private:
    void closeEvent(QCloseEvent *event);
};

#endif // TRAINING_H
