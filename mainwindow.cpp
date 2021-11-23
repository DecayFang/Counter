#include "mainwindow.h"
#include "counters.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_counter(new Counters(this)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QHBoxLayout *cellLayout = new QHBoxLayout(ui->scrollAreaWidgetContents);
    m_counter->show();
    cellLayout->addWidget(m_counter);
    ui->scrollAreaWidgetContents->setLayout(cellLayout);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);

    connect(ui->AddButton, &QPushButton::clicked, [&]() {
        m_counter->addCell();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
