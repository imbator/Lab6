#include "csvwriter.h"
#include <iostream>

CSVWriter::CSVWriter(const QString& filename)
{
    fout.open(filename.toLatin1().data());
}

CSVWriter::~CSVWriter()
{
    fout.close();
}


void CSVWriter::WriteAll(std::vector<Lesson> vec)
{
    std::ofstream fout("schedule_database_output.csv");
    if(!fout.is_open())
       {
           std::cout << "Error" << std::endl;
       }
       else
       {
           for (int i = 0; i < int(vec.size()); i++)
           {
               fout << vec[i].number << ";" << (vec[i].title).toStdString() << ";" << vec[i].type  << ";" << vec[i].auditory << std::endl;

           }

        }
}
