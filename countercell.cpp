#include "countercell.h"
#include "counters.h"
#include "ui_countercell.h"
#include <QDebug>
#include <QTimer>
#include <QIntValidator>
#include <QDateTime>
#include <climits>

CounterCell::CounterCell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CounterCell)
{
    ui->setupUi(this);

    ui->CountLine->setValidator(new QIntValidator(0, INT_MAX));

    // there is a delay for the true metrics to be calced
    QTimer::singleShot(1, [&]() { _autoStretch(); });

    connect(ui->NameLine, SIGNAL(textChanged(QString)), this, SLOT(_autoStretch()));

    connect(ui->CloseButton, &QPushButton::clicked, [&]() {
        Counters *p = dynamic_cast<Counters*>(parentWidget());
        Q_ASSERT(p);
        p->removeCell(this);
        close();
    });

    connect(ui->CountButton, &QPushButton::clicked, [&]() {
        int count = ui->CountLine->text().toInt();
        ui->CountLine->setText(QString::number(count + 1));

        QString time = QDateTime::currentDateTime().toString("hh:mm");
        ui->DateBox->insertItem(0, time);
        ui->DateBox->setCurrentIndex(0);
    });
}

CounterCell::CounterCell(const QString &name, int count, const QStringList &timeStamps, QWidget *parent)
    : CounterCell(parent)
{
    ui->NameLine->setText(name);
    ui->CountLine->setText(QString::number(count));
    for(const QString &ts : timeStamps) {
        ui->DateBox->insertItem(0, ts);
    }
    ui->DateBox->setCurrentIndex(0);
}

CounterCell::~CounterCell()
{
    delete ui;
}

QString CounterCell::name() const
{
    return ui->NameLine->text();
}

int CounterCell::count() const
{
    return ui->CountLine->text().toInt();
}

QStringList CounterCell::timeStamps() const
{
    QStringList result;
    for(int i = ui->DateBox->count() - 1; i >= 0; --i)
        result.append(ui->DateBox->itemText(i));
    return result;
}

void CounterCell::_autoStretch()
{
    QFontMetrics metric = ui->NameLine->fontMetrics();
    int width = std::max(ui->CountLine->rect().width(), metric.boundingRect(ui->NameLine->text()).width() + 6);
    ui->NameLine->setFixedWidth(width);
}
