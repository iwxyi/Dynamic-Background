#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dynamicbackgroundpure.h"
#include "dynamicbackgroundgradient.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event);

private:
    DynamicBackgroundInterface *dm_bg;
};

#endif // MAINWINDOW_H
