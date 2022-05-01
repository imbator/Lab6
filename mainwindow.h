#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <lesson.h>
#include <QMainWindow>
#include "abstractreader.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void read_file(AbstractReader &rd);

public slots:
    void findAuditory();
    void addToVector();
    void absRead(AbstractReader& reader);
    void newReadAll(AbstractReader& reader);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    std::vector<Lesson> lessons;

};
#endif // MAINWINDOW_H
