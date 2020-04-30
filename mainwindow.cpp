#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QImage image("C:/Resources/card.jpg");

    splitter = new QSplitter(this);

    imageLabel = new QLabel();
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setScaledContents(true);
    imageLabel->setPixmap(QPixmap::fromImage(image));

    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(imageLabel);
    setCentralWidget(splitter);

    buttons = new QGroupBox(this);
    layout = new QVBoxLayout();

    buttonOpen = new QPushButton("Open",buttons);
    buttonQuit = new QPushButton("QUIT",buttons);

    layout->addWidget(buttonOpen);
    layout->addWidget(buttonQuit);

    buttons->setLayout(layout);

    splitter->addWidget(scrollArea);
    splitter->addWidget(buttons);

    setWindowTitle(tr("Demo"));
    resize(800, 400);
}

MainWindow::~MainWindow()
{
    delete ui;
}

