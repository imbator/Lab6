#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include "csvreader.h"
#include <iostream>
#include "csvwriter.h"
#include "json.hpp"
#include <QFileDialog>
#include <QMessageBox>
#include "jsonreader.h"
#include "abstractreader.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    CSVWriter csv("schedule_database_output.csv");
    csv.WriteAll(lessons);
    std::cout << "Database has been succesfuly updated." << std::endl;
    delete ui;
}
void MainWindow::read_file(AbstractReader &rd)
{
    if (rd.is_open())
    {
        lessons = rd.readAll();
    }
}



void MainWindow::findAuditory()
{
    // ui->textBrowser->append(ui->editSearch->text());
    int researched_size = 0;
    int showUp_par = -1;
    for (auto &e: lessons)
    {
        if ((e.title).right((e.title).size() - 1) == ui->editSearch->text() or e.title == ui->editSearch->text())
        {
            ui->textBrowser->appendGreen(e.title + "," + QString::number(e.auditory) + "," + e.enum_def(e.type));
            showUp_par = 1;
        }
        researched_size += 1;
        if (researched_size == int (lessons.size()) && showUp_par == -1)
        {
            ui->textBrowser->appendRed("Искомая позиция не найдена.");
            researched_size = 0;
        }
    }
    showUp_par = -1;
}

void MainWindow::absRead(AbstractReader& reader)
{
    if(reader.is_open())
    {
        newReadAll(reader);
    }
}


void MainWindow::addToVector()
{
    Lesson c;
    c.number = (ui->editID->text()).toInt();
    c.title = ui->editTitle->text();
    c.auditory = (ui->editAuditory->text()).toInt();
    QString tempo;
    tempo = (ui->comboType->currentText());
    if (tempo == "lecture")
    {
        c.type =  static_cast<lesson_type>(0);
    }
    if (tempo=="practice")
    {
      c.type = static_cast<lesson_type>(1);
    }
    if (tempo == "laboratoty")
    {
        c.type = static_cast<lesson_type>(2);
    }
    else c.type = static_cast<lesson_type>(3);
    lessons.push_back(c);
    std::cout<<"Added"<<std::endl;
    std::cout<<"Database now have " << lessons.size() << " slots" << std::endl;

}


// здесь будем считывать файл сразу после нажатия кнопки

void MainWindow::on_pushButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open a file");
    QMessageBox::information(this,"..",file_name);
    if (ui->typeSelect->currentText() == "CSV")
    {
        CSVReader csv(file_name);
        absRead(csv);

    }
    if (ui->typeSelect->currentText() == "JSON")
    {
        JSONReader json(file_name);
        absRead(json);
    }
}


void MainWindow::newReadAll(AbstractReader& reader)
{
    Lesson less_obj;
    lessons.clear();
    while(reader >> less_obj)
    {       
        std::cout << less_obj;
        lessons.push_back(less_obj);
    }
}





