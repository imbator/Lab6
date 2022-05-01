#ifndef CSVWRITER_H
#define CSVWRITER_H
#include <QString>
#include <fstream>
#include <iostream>
#include <vector>
#include "lesson.h"
#include "mainwindow.h"
#include <vector>

class CSVWriter
{
    std::ofstream fout;
public:
    CSVWriter(const QString& filename);
    ~CSVWriter();

    bool is_open() const { return fout.is_open(); }
    void WriteAll(std::vector<Lesson> vec);
    CSVWriter (const CSVWriter&) = delete;
    CSVWriter operator = (const CSVWriter&) = delete;
    CSVWriter (CSVWriter&&c): fout(std::move(c.fout)) {};
    CSVWriter operator = (CSVWriter &&c) {return std::move(c);}
};

#endif // CSVWRITER_H
