#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {

  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void on_ngonSlider_valueChanged(int value);

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
