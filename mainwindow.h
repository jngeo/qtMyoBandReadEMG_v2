#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include <qwt_plot.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_curve.h>

namespace Ui {
class MainWindow;
}

class QTimer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onOpenCloseButtonClicked();
    void onSaveFileButtonClicked();
    void onFileDirectoryButtonClicked();
    void onReadyRead();

private:
    Ui::MainWindow *ui;
    void init_qwtPlot();
    void plotEMG();

    QTimer *timer;
    QwtPlotCurve *curveEMG1, *curveEMG2, *curveEMG3, *curveEMG4;
    QwtPlotCurve *curveEMG5, *curveEMG6, *curveEMG7, *curveEMG8;
    QwtPlotCurve *curveACCX, *curveACCY, *curveACCZ;
    QVector<double> *data_time, *data_plotTime;  //, *data_ploty;
    QVector<double> *data_emg1, *data_emg2, *data_emg3, *data_emg4;
    QVector<double> *data_emg5, *data_emg6, *data_emg7, *data_emg8;
    QVector<double> *data_accX, *data_accY, *data_accZ;
};

#endif // MAINWINDOW_H
