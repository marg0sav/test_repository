#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTabBar>//чтобы скрыть вкладки
#include"stylehelper.h"
#include<QDebug>
#include<QFontDatabase>
#include<QMessageBox>
#include<QGridLayout>
#include<QString>
#include<QRegExp>
int col=6;
int row=6;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setCurrentIndex(0);
    setInterfaceStyle();
    addFont();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setInterfaceStyle()
{
this->setStyleSheet(styleHelper::getMainWindowStyle());
    ui->playButton->setStyleSheet(styleHelper::getStartButtonStyle());
    ui->aboutButton->setStyleSheet(styleHelper::getStartButtonStyle());
    ui->exitButton->setStyleSheet(styleHelper::getStartButtonStyle());
    //ui->levelOfDifficultyButton->setStyleSheet(styleHelper::getStartButtonStyle());
    ui->checkButton->setStyleSheet(styleHelper::getStartButtonStyle());
    ui->textLabel_1_1->setStyleSheet(styleHelper::getLabelStyle());
    ui->aboutTextLabel_1_1->setStyleSheet(styleHelper::getAboutTextStyle());
    buttonHide(true);


    ui->tabWidget->setStyleSheet(styleHelper::getTabWidgetStyle());
    ui->level_1->setStyleSheet(styleHelper::getTabStyle());
    //ui->level_2->setStyleSheet(styleHelper::getTabStyle());
 //игровое поле
  gameFieldInitialization();
  readOnlyFun(true);
 //кнопки отвечающие за верность/неверность
    ui->horizontalButton_1_1->setStyleSheet(styleHelper::getStatusButton());
    ui->horizontalButton_2_1->setStyleSheet(styleHelper::getStatusButton());
    ui->horizontalButton_3_1->setStyleSheet(styleHelper:: getStatusButton());
    ui->verticalButton_1_1->setStyleSheet(styleHelper::getStatusButton());
    ui->verticalButton_2_1->setStyleSheet(styleHelper::getStatusButton());
    ui->verticalButton_3_1->setStyleSheet(styleHelper::getStatusButton());
}

void MainWindow::addFont()
{
    int id = QFontDatabase::addApplicationFont(":/Fonts/Roboto-Medium.ttf");//добавили в базу данных шрифтов
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    qDebug()<<family;
}

void MainWindow::readOnlyFun(bool change)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        { if(i%2==0)
            {
                QGridLayout *grid= qobject_cast<QGridLayout*>(ui->level_1->layout());
                QLineEdit *line3 = qobject_cast<QLineEdit*>(grid->itemAtPosition(i,j)->widget());
                line3->setReadOnly(change);
            }
            else
            {
                if(j%2!=0)
                {
                    QGridLayout *grid= qobject_cast<QGridLayout*>(ui->level_1->layout());
                    QLineEdit *line4 = qobject_cast<QLineEdit*>(grid->itemAtPosition(i,j)->widget());
                    line4->setReadOnly(change);
                }

            }
        }
    }
}

void MainWindow::gameFieldInitialization()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        { if(i%2==0)
            {
                QGridLayout *grid= qobject_cast<QGridLayout*>(ui->level_1->layout());
                QLineEdit *line1 = qobject_cast<QLineEdit*>(grid->itemAtPosition(i,j)->widget());
                line1->setStyleSheet(styleHelper::getLineEditStyle());
            }
            else
            {
                if(j%2!=0)
                {
                QGridLayout *grid= qobject_cast<QGridLayout*>(ui->level_1->layout());
                QLineEdit *line2 = qobject_cast<QLineEdit*>(grid->itemAtPosition(i,j)->widget());
                line2->setStyleSheet(styleHelper::getLineEditStyle());
                }
                else
                {
                    QGridLayout *grid= qobject_cast<QGridLayout*>(ui->level_1->layout());
                    QPushButton *btn = qobject_cast<QPushButton*>(grid->itemAtPosition(i,j)->widget());
                    btn->setStyleSheet(styleHelper::getBlankButtonStyle());
                }
            }
        }
    }
}

void MainWindow::clear()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        { if(i%2==0)
            {
                QGridLayout *grid= qobject_cast<QGridLayout*>(ui->level_1->layout());
                QLineEdit *line = qobject_cast<QLineEdit*>(grid->itemAtPosition(i,j)->widget());
                line->setText("");
            }
            else
            {
                if(j%2!=0)
                {
                    QGridLayout *grid= qobject_cast<QGridLayout*>(ui->level_1->layout());
                    QLineEdit *line1 = qobject_cast<QLineEdit*>(grid->itemAtPosition(i,j)->widget());
                    line1->setText("");
                }

            }
        }
    }
}

void MainWindow::buttonHide(bool change)
{
    ui->horizontalButton_1_1->setHidden(change);
    ui->horizontalButton_2_1->setHidden(change);
    ui->horizontalButton_3_1->setHidden(change);
    ui->verticalButton_1_1->setHidden(change);
    ui->verticalButton_2_1->setHidden(change);
    ui->verticalButton_3_1->setHidden(change);
}

void MainWindow::on_exitButton_clicked()
{
   QMessageBox::StandardButton exit= QMessageBox::question(this,"","Вы точно хотите выйти?\nДанные не сохранятся!",QMessageBox::Yes|QMessageBox::No);
   if(exit==QMessageBox::Yes)
       QApplication::quit();
}

void MainWindow::on_playButton_clicked()
{
    buttonHide(false);
    ui->tabWidget->setCurrentIndex(1);
    if(gameStart)
    {
        QMessageBox::StandardButton play= QMessageBox::question(this,"","Вы точно хотите сдаться?\nДанные не сохранятся!",QMessageBox::Yes|QMessageBox::No);
        if(play==QMessageBox::Yes)
        {
        readOnlyFun(true);
        clear();
        ui->playButton->setText("Играть");
        ui->aboutButton->setDisabled(false);
        //ui->levelOfDifficultyButton->setDisabled(false);
        gameStart=false;
        ui->horizontalButton_1_1->setStyleSheet(styleHelper::getStatusButton());
        ui->horizontalButton_2_1->setStyleSheet(styleHelper::getStatusButton());
        ui->horizontalButton_3_1->setStyleSheet(styleHelper:: getStatusButton());
        ui->verticalButton_1_1->setStyleSheet(styleHelper::getStatusButton());
        ui->verticalButton_2_1->setStyleSheet(styleHelper::getStatusButton());
        ui->verticalButton_3_1->setStyleSheet(styleHelper::getStatusButton());
        }
        else
        gameStart=true;
    }
    else
    {
        ui->playButton->setText("Сдаться");
        clear();
        readOnlyFun(false);
        ui->aboutButton->setDisabled(true);
        //ui->levelOfDifficultyButton->setDisabled(true);
        gameStart=true;

    }
}



void MainWindow::on_checkButton_clicked()
{
    int count=0;
    QString word_1=0;
    QString word_2=0;
    QString word_3=0;
    QString word_4=0;
    QString word_5=0;
    QString word_6=0;
    word_1=ui->lineEdit_1_1->text()+ui->lineEdit_2_1->text()+ui->lineEdit_3_1->text()+ui->lineEdit_4_1->text()+ui->lineEdit_5_1->text()+ui->lineEdit_6_1->text();
    QRegExp word1("[^л-я][лнп]а.[нкп].");
    if(word1.exactMatch(word_1))
    {
        ui->horizontalButton_1_1->setStyleSheet(styleHelper::getRightButtonStyle());
        count++;}
    else
       ui->horizontalButton_1_1->setStyleSheet(styleHelper::getWrongButtonStyle());



    word_2=ui->lineEdit_13_1->text()+ui->lineEdit_14_1->text()+ui->lineEdit_15_1->text()+ui->lineEdit_16_1->text()+ui->lineEdit_17_1->text()+ui->lineEdit_18_1->text();
    QRegExp word2("[п-х][а-к]..з[а-ж]");
    if(word2.exactMatch(word_2))
    {
        ui->horizontalButton_2_1->setStyleSheet(styleHelper::getRightButtonStyle());
        count++;}
    else
       ui->horizontalButton_2_1->setStyleSheet(styleHelper::getWrongButtonStyle());



    word_3=ui->lineEdit_25_1->text()+ui->lineEdit_26_1->text()+ui->lineEdit_27_1->text()+ui->lineEdit_28_1->text()+ui->lineEdit_29_1->text()+ui->lineEdit_30_1->text();
    QRegExp word3("[^л-ш]н.[жпр]н[ауе]");
    if(word3.exactMatch(word_3))
    {
        ui->horizontalButton_3_1->setStyleSheet(styleHelper::getRightButtonStyle());
        count++;}
    else
       ui->horizontalButton_3_1->setStyleSheet(styleHelper::getWrongButtonStyle());




    word_4=ui->lineEdit_2_1->text()+ui->lineEdit_8_1->text()+ui->lineEdit_14_1->text()+ui->lineEdit_20_1->text()+ui->lineEdit_26_1->text()+ui->lineEdit_32_1->text();
    QRegExp word4("[лгб][тан].[т-ч]н[^д-я]");
    if(word4.exactMatch(word_4))
    {
        ui->verticalButton_1_1->setStyleSheet(styleHelper::getRightButtonStyle());
        count++;}
    else
         ui->verticalButton_1_1->setStyleSheet(styleHelper::getWrongButtonStyle());




    word_5=ui->lineEdit_4_1->text()+ui->lineEdit_10_1->text()+ui->lineEdit_16_1->text()+ui->lineEdit_22_1->text()+ui->lineEdit_28_1->text()+ui->lineEdit_34_1->text();
    QRegExp word5("д[рнб]о.ж[з-л]");
    if(word5.exactMatch(word_5))
    {
        ui->verticalButton_2_1->setStyleSheet(styleHelper::getRightButtonStyle());
        count++;}
    else
       ui->verticalButton_2_1->setStyleSheet(styleHelper::getWrongButtonStyle());





    word_6=ui->lineEdit_6_1->text()+ui->lineEdit_12_1->text()+ui->lineEdit_18_1->text()+ui->lineEdit_24_1->text()+ui->lineEdit_30_1->text()+ui->lineEdit_36_1->text();
    QRegExp word6("а.а.а.");
    if(word6.exactMatch(word_6))
    {
        ui->verticalButton_3_1->setStyleSheet(styleHelper::getRightButtonStyle());
        count++;}
    else
       ui->verticalButton_3_1->setStyleSheet(styleHelper::getWrongButtonStyle());
    if(count==6)
    {
        QMessageBox::information(this,"","ВЫ ПОБЕДИЛИ!");
        ui->playButton->setText("Начать заново!");
    }
}


void MainWindow::on_aboutButton_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
    buttonHide(true);
}

