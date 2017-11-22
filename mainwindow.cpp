#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec> // подключение класса кодека текста

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnExit, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnFillChains_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    Analysis an;
    an.openfile();
    an.pushchains();
    an.sort();
    //QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    QStringList header;
    header << "Сиптомы" << "Частота повторения";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setRowCount(an.v.size());
    for (int i = 0 ; i < an.v.size(); i++)
    {
        //QString ds = QString::fromStdString(an.v[i].ds);
        QString word = QString::fromStdString(an.v[i].word);
        QString count = QString::number(an.v[i].count);
        //QString ds = codec->toUnicode(an.v[i].ds.c_str());
        //QString word = codec->toUnicode(an.v[i].word.c_str());
        //QString count = QString::number(an.v[i].count);
        //word = codec->toUnicode(an.v[i].word.c_str());
        //ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString(ds)));
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString(word)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString(count)));
    }
}

void MainWindow::on_btnFillWords_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(2);
    Analysis an;
    an.openfile();
    an.pushwords();
    an.sort();
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    QStringList header;
    header << "Сиптомы" << "Частота повторения";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setRowCount(an.v.size());
    for (int i = 0 ; i < an.v.size(); i++)
    {
        //QString ds = codec->toUnicode(an.v[i].ds.c_str());
        //QString word = codec->toUnicode(an.v[i].word.c_str());
        //QString count = QString::number(an.v[i].count);

        QString ds = QString::fromStdString(an.v[i].ds);
        QString word = QString::fromStdString(an.v[i].word);
        QString count = QString::number(an.v[i].count);

        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString(word)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString(count)));
    }
}

void MainWindow::on_btnFillWords_ds_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(3);
    Analysis an;
    an.openfile();
    an.pushwords_ds();
    an.sort_ds();
    //QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    QStringList header;
    header << "Диагноз" << "Сиптомы" << "Частота повторения";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setRowCount(an.v.size());
    for (int i = 0 ; i < an.v.size(); i++)
    {

        QString ds = QString::fromStdString(an.v[i].ds);
        QString word = QString::fromStdString(an.v[i].word);
        QString count = QString::number(an.v[i].count);
        //word = codec->toUnicode(an.v[i].word.c_str());
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString(ds)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString(word)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString(count)));
    }
}

void MainWindow::on_btnFillChains_ds_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(3);
    Analysis an;
    an.openfile();
    an.pushchains_ds();
    an.sort_ds();
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    QStringList header;
    header << "Диагноз" << "Сиптомы" << "Частота повторения";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setRowCount(an.v.size());
    for (int i = 0 ; i < an.v.size(); i++)
    {
        QString ds = codec->toUnicode(an.v[i].ds.c_str());
        QString word = codec->toUnicode(an.v[i].word.c_str());
        QString count = QString::number(an.v[i].count);
        //word = codec->toUnicode(an.v[i].word.c_str());
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString(ds)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString(word)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString(count)));
    }
}
