#include "counters.h"
#include "countercell.h"
#include "datacenter.h"
#include "ui_counters.h"

Counters::Counters(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Counters)
{
    ui->setupUi(this);

    const QList<CellData> &data = m_dataCenter.data();
    for(const CellData &cd : data) {
        addCell(cd.name, cd.count, cd.timeStamps);
    }
}

Counters::~Counters()
{
    _saveViewData();

    delete ui;
}

void Counters::_saveViewData()
{
    QList<CellData> newData;
    for(const CounterCell *cell : m_cells) {
        newData.append({ cell->name(), cell->count(), cell->timeStamps() });
    }
    m_dataCenter.setData(newData);
    m_dataCenter.save();
}

void Counters::addCell(const QString &name, int count, const QStringList &timeStamps)
{
    CounterCell *cell = new CounterCell(name, count, timeStamps, this);
    cell->show();
    ui->horizontalLayout->addWidget(cell);
    m_cells.append(cell);
}

void Counters::addCell()
{
    CounterCell *cell = new CounterCell(this);
    cell->show();
    ui->horizontalLayout->addWidget(cell);
    m_cells.append(cell);
}

void Counters::removeCell(CounterCell *cell)
{
    m_cells.removeOne(cell);
}
