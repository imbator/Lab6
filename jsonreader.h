#ifndef JSONREADER_H
#define JSONREADER_H
#include <vector>
#include "lesson.h"
#include "abstractreader.h"
#include <QString>
#include <fstream>
#include <iostream>
#include <json.hpp>
class JSONReader: public AbstractReader
{
private:
    nlohmann::json json;
    nlohmann::json::iterator j_start;

public:
    // std::ifstream fin;
    JSONReader(const QString& filename);
    ~JSONReader();
    std::vector<Lesson> readAll() override;
    bool is_open() override
    {
       return fin.is_open();
    }
    JSONReader& operator>>(Lesson &lesson_obj) override
    {
        std::string temp_lesson;
        if(j_start < json.end())
        {
            lesson_obj.number = j_start.value()["number"];
            temp_lesson = j_start.value()["title"];
            lesson_obj.type = j_start.value()["type"];
            lesson_obj.auditory = j_start.value()["auditory"];
            lesson_obj.title = QString::fromStdString(temp_lesson);

        }
        j_start++;
        return *this;
    }

    virtual operator bool() const override
        {
            return j_start - 1 != json.end();
        }
};

#endif // JSONREADER_H
