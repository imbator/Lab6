#ifndef LESSON_H
#define LESSON_H

#include <QString>
#include <string>
#include <iostream>
enum lesson_type {LECTURE, PRACTICE, LABORATORY, EXAM};
class Lesson
{
public:
    int number;
    QString title;
    lesson_type type;
    int auditory;
    QString enum_def(int value)
    {
       switch(value)
       {
           case 0: return("Lecture");
           case 1: return("Practice");
           case 2: return("Laboratory");
           case 3: return("Exam");
       }   
    }
    bool operator <(const Lesson &other)
    {
        return this->auditory < other.auditory;
    }

    friend std::ostream& operator<<(std::ostream& os, const Lesson &c)
    {
        os << (c.title).toStdString() << " " << c.type << " " << c.auditory << std::endl;
        return os;
    };



};
#endif // LESSON_H
