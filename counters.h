#ifndef COUNTERS_H
#define COUNTERS_H

#include <QWidget>

namespace Ui {
class Counters;
}

class Counters : public QWidget
{
    Q_OBJECT

public:
    explicit Counters(QWidget *parent = 0);
    ~Counters();

    void addCell();

private:
    Ui::Counters *ui;
};

#endif // COUNTERS_H
