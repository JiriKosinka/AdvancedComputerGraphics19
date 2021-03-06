#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "objfile.h"
#include <QFileDialog>
#include "mesh.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QVector<Mesh> Meshes;
    void importOBJ();

private slots:
    void on_ImportOBJ_clicked();
    void on_RotationDial_valueChanged(int value);
    void on_SubdivSteps_valueChanged(int value);
    void on_wireframeCheckbox_stateChanged(int state);
    void on_limitPositionCheckbox_stateChanged(int state);
    void on_tessellationEnabled_stateChanged(int value);
    void on_tessallationLevelOuter_valueChanged(int value);
    void on_tessallationLevelInner_valueChanged(int value);

    void on_patchVertices4_toggled(bool checked);
    void on_patchVertices16_toggled(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
