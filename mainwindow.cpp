#include "mainwindow.h"
#include "counters.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QHBoxLayout *cellLayout = new QHBoxLayout(ui->scrollAreaWidgetContents);
    Counters *counter = new Counters(this);
    counter->show();
    cellLayout->addWidget(counter);
    ui->scrollAreaWidgetContents->setLayout(cellLayout);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);

    connect(ui->AddButton, &QPushButton::clicked, [&]() {
        counter->addCell();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
