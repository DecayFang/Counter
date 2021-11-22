#include "counters.h"
#include "countercell.h"
#include <QPushButton>
#include <QDebug>
#include "ui_counters.h"

Counters::Counters(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Counters)
{
    ui->setupUi(this);
}

Counters::~Counters()
{
    delete ui;
}

void Counters::addCell()
{
    qDebug() << this;
//    QPushButton *cell = new QPushButton("123", this);
//    cell->show();
//    ui->horizontalLayout->addWidget(cell);
}
