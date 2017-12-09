#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "analysis.h"
#include "widget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_btnFillChains_clicked();

    void on_btnFillWords_clicked();

    void on_btnFillWords_ds_clicked();

    void on_btnFillChains_ds_clicked();

    void on_btnWidgetShow_clicked();

private:
    Ui::MainWindow *ui;
    Widget *w;
};

#endif // MAINWINDOW_H
