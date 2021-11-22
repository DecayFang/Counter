#include "countercell.h"
#include "ui_countercell.h"

CounterCell::CounterCell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CounterCell)
{
    ui->setupUi(this);
}

CounterCell::~CounterCell()
{
    delete ui;
}
