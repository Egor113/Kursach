#ifndef WIDGET_H
#define WIDGET_H
#include <QVBoxLayout>
#include <QPushButton>
#include <QVector>
#include <QDebug>
#include "qcustomplot.h"
#include "analysis.h"

struct CurrWord
{
    QString diagID;
    int count;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    //QVecor
    explicit Widget(QWidget *parent = 0);
    QString word;
    QVector<CurrWord> v;
    void setPlotParams(QString str, QVector<CurrWord> vect);

private:
    QCustomPlot *customPlot;
    QVBoxLayout *vbox;
    QPushButton *res;
    QCPBars *fossil;

private slots:
    void rndres();
};

#endif // WIDGET_H
