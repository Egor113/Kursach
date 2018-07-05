#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <QDialog>
#include "qcustomplot.h"

namespace Ui {
class Diagram;
}

class Diagram : public QDialog
{
    Q_OBJECT

public:
    explicit Diagram(QWidget *parent = 0);
    ~Diagram();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Diagram *ui;
};

#endif // DIAGRAM_H
