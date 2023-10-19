#ifndef STYLEHELPER_H
#define STYLEHELPER_H
#include<QString>

class styleHelper
{
public:
    static QString getMainWindowStyle();
    static QString getStartButtonStyle();
    static QString getTabWidgetStyle();
    static QString getTabStyle();//отвечает за содержимое виджета

    static QString getBlankButtonStyle();
    static QString getRightButtonStyle();
    static QString getWrongButtonStyle();
    static QString getLineEditStyle();
    static QString getStatusButton();
    static QString getLabelStyle();
    static QString getAboutTextStyle();
};

#endif // STYLEHELPER_H
