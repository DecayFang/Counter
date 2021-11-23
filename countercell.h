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
    explicit CounterCell(const QString &name, int count, const QStringList &timeStamps, QWidget *parent = 0);
    ~CounterCell();

    QString name() const;
    int count() const;
    QStringList timeStamps() const;

private slots:
    void _autoStretch();

private:
    Ui::CounterCell *ui;
};

#endif // COUNTERCELL_H
