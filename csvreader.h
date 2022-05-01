#ifndef CSVREADER_H
#define CSVREADER_H
#include <QString>
#include <fstream>
#include <iostream>
#include <vector>
#include "lesson.h"
#include "abstractreader.h"

class CSVReader: public AbstractReader
{
    std::ifstream fin;
public:
    QString file_path;
    CSVReader(const QString& filename);
    ~CSVReader();
    //int flag;
    bool flag;
    bool is_open() override {return fin.is_open(); };
    operator bool() const override
        {
         return flag;
        }
    std::vector<std::string> split(const std::string &str, char delim);
    std::vector<Lesson> readAll() override;
    CSVReader (const CSVReader&) = delete;
    CSVReader operator = (const CSVReader&) = delete;
    CSVReader (CSVReader&&c): fin(std::move(c.fin)) {};
    CSVReader operator = (CSVReader &&c) {return std::move(c);};
    CSVReader& operator>>(Lesson &lesson_object) override
    {
        if (fin.eof()) {flag = false;}
        else {flag = true;};
        std::string line;
        std::getline(fin, line);
        std::vector<std::string> v = split(line, ';');
        lesson_object.number = std::stoi(v[0]);
        lesson_object.title = QString::fromStdString(v[1]);
        lesson_object.type = static_cast<lesson_type>(stoi(v[2]));
        lesson_object.auditory = stoi(v[3]);
        return *this;
    };
};

#endif // CSVREADER_H
