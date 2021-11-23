#ifndef COUNTERS_H
#define COUNTERS_H

#include <QWidget>
#include "datacenter.h"

namespace Ui {
class Counters;
}

class CounterCell;

class Counters : public QWidget
{
    Q_OBJECT

public:
    explicit Counters(QWidget *parent = 0);
    ~Counters();

    void addCell(const QString &name, int count, const QStringList &timeStamps);
    void addCell();

    void removeCell(CounterCell *cell);

private:
    Ui::Counters *ui;

    QList<CounterCell*> m_cells;
    DataCenter m_dataCenter;
    void _saveViewData();
};

#endif // COUNTERS_H
