#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QOpenGLFunctions_4_1_Core>
#include <QOpenGLWidget>
#include <QOpenGLDebugLogger>
#include <QOpenGLShaderProgram>

#include <QVector2D>
#include <QMouseEvent>

class MainView : public QOpenGLWidget, protected QOpenGLFunctions_4_1_Core {

    Q_OBJECT

public:
    MainView(QWidget *parent = 0);
    ~MainView();

    void clearArrays();
    void presetNet(int preset);
    void updateBuffers();

    bool showNet, showCurvePts;
    int selectedPt;
    int findClosest(float x, float y);

    void setMask(QString stringMask);

protected:
    void initializeGL();
    void paintGL();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    QOpenGLDebugLogger* debugLogger;

    QVector<QVector2D> netCoords, interpolatedCoords;

    QOpenGLShaderProgram* mainShaderProg;
    GLuint netVAO, netCoordsBO, interpolatedCoordsBO;

    void createShaderPrograms();
    void createBuffers();
    QVector<QVector2D> generateCurvePoints(QVector<QVector2D> ctrlpoints);
    QVector<QVector2D> interpolateUsingMask(QVector<QVector2D> ctrlpoints, QVector<int> mask);

    bool updateUniformsRequired;
    //GLint uni...

    void updateUniforms();

    QVector<int> subdivMask, firstStencil, secondStencil;
    float normalizeValue;

private slots:
    void onMessageLogged( QOpenGLDebugMessage Message );

};

#endif // MAINVIEW_H
