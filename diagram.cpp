#include "diagram.h"
#include "ui_diagram.h"

Diagram::Diagram(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Diagram)
{
    ui->setupUi(this);
}

Diagram::~Diagram()
{
    delete ui;
}
