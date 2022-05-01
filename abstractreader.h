#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H
#include <vector>
#include "lesson.h"
#include <fstream>

class AbstractReader
{
public:
    std::ifstream fin;
    virtual ~AbstractReader();
    virtual std::vector<Lesson> readAll() = 0;
    virtual bool is_open() = 0;
    virtual AbstractReader& operator>>(Lesson& lesson_obj) = 0;
    virtual operator bool() const = 0;
};

#endif // ABSTRACTREADER_H
