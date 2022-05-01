#ifndef MYTEXTBROWSER_H
#define MYTEXTBROWSER_H
#include "mainwindow.h"
#include <QTextBrowser>

class MyTextBrowser : public QTextBrowser
{
    Q_OBJECT
public:
    MyTextBrowser(QWidget* parent = nullptr) : QTextBrowser(parent){};

    void appendGreen(const QString);
    void appendRed(const QString);
};

#endif // MYTEXTBROWSER_H
