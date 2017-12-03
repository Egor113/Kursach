#ifndef WIDGET_H
#define WIDGET_H
#include <QVBoxLayout>
#include <QPushButton>
#include "qcustomplot.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

private:
    QCustomPlot *customPlot;
    QVBoxLayout *vbox;
    QPushButton *res;
    QCPBars *fossil;

private slots:
    void rndres();
};

#endif // WIDGET_H
