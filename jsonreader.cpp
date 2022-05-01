#include "jsonreader.h"
#include <iostream>
#include "json.hpp"



JSONReader::JSONReader(const QString &filename)
{
    fin.open(filename.toLatin1().data());
    fin >> json;
    j_start = json.begin();
}


JSONReader::~JSONReader()
{
    fin.close();
}

std::vector<Lesson> JSONReader::readAll()
{
    nlohmann::json objJson;
    std::vector<Lesson> lesson;
    // std::fstream fileinput;
    // fileinput.open(filename.toStdString());
    fin >> objJson;
    std::cout << objJson.size() << std::endl;

    for (auto &e: objJson)
    {
        Lesson temp;
        temp.number = (e["number"]);
        std::cout << e["number"] << std::endl;
        temp.title = QString::fromStdString(e["title"]);
        std::cout << e["title"] << std::endl;
        temp.type = e["type"];
        std::cout << e["type"] << std::endl;
        temp.auditory = e["auditory"];
        std::cout << e["auditory"] << std::endl;
        lesson.push_back(temp);
        std::cout << "Added, next" << std::endl;
    }
    std::sort(lesson.begin(), lesson.end());
    std::cout << "Is sorted?:" << std::endl;
    std::cout << lesson[1].auditory << std::endl;
    std::cout << "Let's check overloaded operator:" << std::endl;
    for (auto &e: lesson) {std::cout << e;}
    return lesson;
}

