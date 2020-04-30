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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSplitter *splitter;
    QScrollArea *scrollArea;
    QLabel *imageLabel;
    QGroupBox *buttons;
    QVBoxLayout *layout;
    QPushButton *buttonOpen;
    QPushButton *buttonQuit;

};
#endif // MAINWINDOW_H
