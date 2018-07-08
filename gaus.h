#ifndef GAUS_H
#define GAUS_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QVector>
#include <QDebug>
#include "qcustomplot.h"
#include "analysis.h"

struct CurrWordGaus// Структура для хранения диагноза
               // и частоты
{
    QString diagID;
    int count;
};

class Gaus : public QWidget
{
    Q_OBJECT

public:
    explicit Gaus(QWidget *parent = nullptr);
    QString word; //Строка для храения слова (выражения)
    QVector<CurrWordGaus> v; //Вектор для хранения диагноза и частоты
    void setPlotParams(QString str, QVector<CurrWordGaus> vect);// Процедура инициализации
private:
    QCustomPlot *customPlot;
    QVBoxLayout *vbox;
    QPushButton *res;
    QCPBars *fossil;
signals:

private slots:
    void rndres();
};

#endif // GAUS_H
