#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QScrollArea>
#include <QPushButton>
#include <QSplitter>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QSplitter>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QPushButton *buttonNext;
    ~MainWindow();

public slots:
    void onUpdate();

private:
    Ui::MainWindow *ui;
    QSplitter *splitter;
    QScrollArea *scrollArea;
    QLabel *imageLabel;
    QGroupBox *buttons;
    QVBoxLayout *layout;
    QPushButton *buttonQuit;
    QVector<QImage> images;
    int currentImage = 0;

};
#endif // MAINWINDOW_H
