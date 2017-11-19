#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <conio.h>
#include <locale>
#include <string>
#include <iostream>
#include <QVector>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
#include <QString>
#include <QTextCodec>
#include <QtAlgorithms>
#include <algorithm>

class Analysis
{
public:
    struct Words { // Структрура для хранения
        std::string word; //слова(выражения)
        int         count; //частоты его повторения в тексте
        std::string ds; //и диагоноза
    };
    std::vector<Words> v; //Массив слов(выражений)
    std::ifstream fileReader; //Файловая переменная
    void pushwords_ds(); //Процедура добавления слов в массив
    void pushchains_ds();//Процедура добавления выражений в массив
    void pushwords(); //Процедура добавления слов в массив
    void pushchains();//Процедура добавления выражений в массив
    void sort_ds();
    void sort();
    void openfile();
    //void print();
    Analysis();

private:
    bool static sortCondition(Words w1, Words w2);
    bool static sortCondition_ds(Words w1, Words w2);
};

#endif // ANALYSIS_H
