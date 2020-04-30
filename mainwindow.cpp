#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    images.append(QImage("C:/Resources/image1.jpg"));
    images.append(QImage("C:/Resources/image2.jpg"));
    images.append(QImage("C:/Resources/image3.jpg"));

    splitter = new QSplitter(this);

    imageLabel = new QLabel();
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setScaledContents(true);
    imageLabel->setPixmap(QPixmap::fromImage(images.at(currentImage)));

    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(imageLabel);
    setCentralWidget(splitter);

    buttons = new QGroupBox(this);
    layout = new QVBoxLayout();

    buttonNext = new QPushButton("Next",buttons);
    buttonQuit = new QPushButton("Quit",buttons);

    layout->addWidget(buttonNext);
    layout->addWidget(buttonQuit);

    buttons->setLayout(layout);

    splitter->addWidget(scrollArea);
    splitter->addWidget(buttons);

    setWindowTitle(tr("Demo"));
    resize(800, 400);

    QObject::connect(buttonNext, SIGNAL (clicked()),this , SLOT (onUpdate()));
    QObject::connect(buttonQuit, SIGNAL (clicked()),QApplication::instance(),SLOT(quit()));
}

void MainWindow::onUpdate(){
    currentImage = currentImage < images.size()-1 ? currentImage +1 : 0;
    QImage newImage = images.at(currentImage);
    imageLabel->setPixmap(QPixmap::fromImage(newImage));
}

MainWindow::~MainWindow()
{
    delete ui;
}

