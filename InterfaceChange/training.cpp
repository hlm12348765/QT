#include <QtGui>
#include "training.h"
#include "ui_training.h"

Training::Training(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Training)
{
    ui->setupUi(this);
    setWindowTitle(tr("SLAT2000"));
}

Training::~Training()
{
    delete ui;
}

void Training::receiveshow()
{
    this ->show();
}
