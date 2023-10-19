#include "stylehelper.h"



QString styleHelper::getMainWindowStyle()
{
    return "QWidget{"
            "background-image: url(:/Image/bg.png);"
            "}";
}

QString styleHelper::getStartButtonStyle()
{
    return "QPushButton{"
            "color:#fff;"
            "background: none;"//означает что фона не будет вообще, сначала отменили, а потом назначили новое значение
            "border:none;"//убираем границу
            "border-radius:19px;"
            "background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(89, 156, 208, 255), stop:1 rgba(65, 118, 184, 255));"
            "font-family: 'Roboto Medium';"
            "font-size:18px;"
            "}"
            "QPushButton::hover{"
            "background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(103, 162, 208, 255), stop:1 rgba(123, 150, 184, 255));"
            "}"
            "QPushButton::pressed{"
            "background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(89, 156, 208, 255), stop:1 rgba(65, 118, 184, 255));"
            "}";

}

QString styleHelper::getTabWidgetStyle()
{
    return "QTabWidget {"//изменяет игровое поле
           "border:none;"
           "}"
           "QTabWidget::pane {"
           "border:1px solid #222;"
           "border-radius:3px;"
           "}";
}

QString styleHelper::getTabStyle()
{
    return "QWidget#level_1 {"
           "background: rgb(33,40,50);"
           "}";
}

QString styleHelper::getBlankButtonStyle()
{
    return  "QPushButton{"
            "border:none;"
            "background: #070D19;"
            "}";
}


QString styleHelper::getRightButtonStyle()
{
    return "QPushButton{"
           "color:#fff;"
           "font-family: 'Roboto Medium';"
           "font-size:30px;"
           "border-radius:25px;"
           "border:none;"
           "background:none;"
           "background-color: #20401B;"
           "}";
}

QString styleHelper::getWrongButtonStyle()
{
    return "QPushButton{"
            "color:#fff;"
           "font-family: 'Roboto Medium';"
           "font-size:30px;"
           "border-radius:25px;"
           "border:none;"
           "background:none;"
           "background-color:rgb(120, 3, 9);"
           "}";
}


QString styleHelper::getLineEditStyle()
{
    return "QLineEdit{"
            "color:#fff;"
            "background-position: center center;"
            "border:none;"//убираем границу
            "font-family: 'Roboto Medium';"
            "font-size:40px;"
            "}"
            "QLineEdit::hover{"
            "background:#373D49;"
            "}";
}

QString styleHelper::getStatusButton()
{
    return  "QPushButton{"
            "color:#000;"
            "border:none;"//убираем границу
            "font-family: 'Roboto Medium';"
            "font-size:30px;"
            "}";
}

QString styleHelper::getLabelStyle()
{
    return  "QLabel{"
            "color:#fff;"
            "font-family: 'Roboto Medium';"
            "font-size:12px;"
            "}";
}

QString styleHelper::getAboutTextStyle()
{
    return "QLabel{"
            "color:#fff;"
            "font-family: 'Roboto Medium';"
            "font-size:14px;"
            "}";
}
