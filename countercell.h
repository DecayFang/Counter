#ifndef COUNTERCELL_H
#define COUNTERCELL_H

#include <QWidget>

namespace Ui {
class CounterCell;
}

class CounterCell : public QWidget
{
    Q_OBJECT

public:
    explicit CounterCell(QWidget *parent = 0);
    ~CounterCell();

private:
    Ui::CounterCell *ui;
};

#endif // COUNTERCELL_H
