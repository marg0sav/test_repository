#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exitButton_clicked();


    void on_playButton_clicked();

    void on_checkButton_clicked();

    void on_aboutButton_clicked();


private:
    Ui::MainWindow *ui;
    void setInterfaceStyle();
    void addFont();
    void readOnlyFun(bool change);
    void gameFieldInitialization();
    void clear();
    void buttonHide(bool change);
    bool gameStart=false;
};
#endif // MAINWINDOW_H

