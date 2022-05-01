#include "mytextbrowser.h"

void MyTextBrowser::appendGreen(const QString str)
{
    auto color = textColor();
    setTextColor(Qt::green);
    append(str);
    setTextColor(color);
}

void MyTextBrowser::appendRed(const QString str)
{
    auto color = textColor();
    setTextColor(Qt::red);
    append(str);
    setTextColor(color);
}
