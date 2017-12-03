#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec> // подключение класса кодека текста
#include <QDebug>
#include "widget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    w = NULL;
    connect(ui->btnExit, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    if(w != NULL) delete w;
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
    an.push_ds();
    an.sort_ds();
    QStringList header;
    header << "Диагноз" << "Сиптомы" << "Частота повторения";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setRowCount(1000);
    //qDebug() << an.v_s.size() << "\n";
    int sum = 0;
    for (int j=0; j<an.v_ds.size(); ++j)
    {
        Analysis::Words_ds wds = an.v_ds[j];
        for (int i = 0 ; i < (wds.v.size()); i++)
        {
            QString ds = QString::fromStdString(wds.diagID);
            QString word = QString::fromStdString(wds.v[i].word);
            QString count = QString::number(wds.v[i].count);
            //word = codec->toUnicode(an.v[i].word.c_str());
            ui->tableWidget->setItem(sum,0,new QTableWidgetItem(QString(ds)));
            ui->tableWidget->setItem(sum,1,new QTableWidgetItem(QString(word)));
            ui->tableWidget->setItem(sum,2,new QTableWidgetItem(QString(count)));
            sum ++;
            //qDebug() << QString::fromStdString(wds.diagID) << QString::fromStdString(wds.v[i].word) << wds.v[i].count;
        }
    }
    /*
    for (int i = 0; i < wds.v.size(); ++i)
    {

        QString ds = QString::fromStdString(wds.diagID);
        QString word = QString::fromStdString(wds.v[i].word);
        if (word != "")
        {
            qDebug() << QString::fromStdString(wds.diagID) << " " << word;
        }
   }*/

}

void MainWindow::on_btnFillChains_ds_clicked()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(3);
    Analysis an;
    an.openfile();
    an.pushchains_ds();
    //an.sort_ds();
    QStringList header;
    header << "Диагноз" << "Сиптомы" << "Частота повторения";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    //qDebug() << an.v_s.size() << "\n";
    foreach(Analysis::Words_ds wds, an.v_ds)
    {
        QString ds = QString::fromStdString(wds.diagID);
        ui->tableWidget->setHorizontalHeaderLabels(header);
        ui->tableWidget->setRowCount(wds.v.size());
        for (int i = 0 ; i < wds.v.size(); i++)
        {

            QString ds = QString::fromStdString(an.v[i].ds);
            QString word = QString::fromStdString(wds.v[i].word);
            QString count = QString::number(wds.v[i].count);
            //word = codec->toUnicode(an.v[i].word.c_str());
            if (word != "")
            {
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString(ds)));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString(word)));
                ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString(count)));
            }
        }
    }
}

void MainWindow::on_btnWidgetShow_clicked()
{
    if(w != NULL) delete w;
    w = new Widget();
    Analysis an;
    an.openfile();
    an.pushwords_ds();
    an.push_ds();
    //qDebug() << ui->tableWidget->currentRow();
    QString text;
    for (int i = 0 ; i < ui->tableWidget->rowCount(); i++)
    {
        int row = ui->tableWidget->currentRow();
        if (row == ui->tableWidget->row(ui->tableWidget->currentItem()))
        {
            //qDebug() << ui->tableWidget->item(row,1)->text();
            text = ui->tableWidget->item(row,1)->text();
        }
    }
    an.get_ds(text.toStdString());
    for (int  i = 0; i < an.v_curr.size(); ++i)
    {
        qDebug() << QString::fromStdString(an.v_curr[i].diagID) << an.v_curr[i].count;
    }

//  Формирование нового вектора (диагноз, кол-во повторений)
//  w->setPlotParams(slovo,siagnozList)
    //w->show();
}
