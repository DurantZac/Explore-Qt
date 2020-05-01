#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "imagelabel.h"
#include <QMouseEvent>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    splitter = new QSplitter(this);

    imageLabel = new ImageLabel();

    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(imageLabel);
    setCentralWidget(splitter);

    buttons = new QGroupBox(this);
    layout = new QVBoxLayout();

    buttonNext = new QPushButton("Next",buttons);
    buttonReset = new QPushButton("Reset", buttons);
    buttonQuit = new QPushButton("Quit",buttons);

    layout->addWidget(buttonNext);
    layout->addWidget(buttonReset);
    layout->addWidget(buttonQuit);

    buttons->setLayout(layout);

    splitter->addWidget(scrollArea);
    splitter->addWidget(buttons);

    setWindowTitle(tr("Demo"));
    resize(800, 400);

    QObject::connect(buttonNext, SIGNAL (clicked()),imageLabel , SLOT (slotOnNext()));
    QObject::connect(buttonReset, SIGNAL (clicked()),imageLabel, SLOT(slotOnReset()));
    QObject::connect(buttonQuit, SIGNAL (clicked()),QApplication::instance(),SLOT(quit()));
}



MainWindow::~MainWindow()
{
    delete ui;
}

