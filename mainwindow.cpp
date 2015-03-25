#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>
#include <algorithm>
#include <array>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <windows.h>
#include <time.h>
#include <myo/myo.hpp>

#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_curve.h>

#include <QDebug>
#include <QTimer>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>

using namespace std;

bool runStatus;
bool myoStatus;

const double CntlFreq = 100.0;
double period = 1/CntlFreq;
double plotTime = 5;
int maxFr = CntlFreq * plotTime;

__int64 freq;
__int64 cnt;
int frameNum;
double last_frame = 0;
__int64 first_get = 0;
unsigned int cnt_get = 0;


bool saveFlag = false;
ofstream fid;
ifstream fid1;
QString fileComplete, fileCompileComplete;
QFile csvfile, csvcompilefile;


QString strOut;
std::array<double, 8> emgSamplesD;
std::array<double, 4> accSamplesD;
double emg1, emg2, emg3, emg4, emg5, emg6, emg7, emg8;
double accX, accY, accZ;
QVector<double> data_plotEmg1, data_plotEmg2, data_plotEmg3, data_plotEmg4;
QVector<double> data_plotEmg5, data_plotEmg6, data_plotEmg7, data_plotEmg8;
QVector<double> data_plotAccX, data_plotAccY, data_plotAccZ;

class DataCollector : public myo::DeviceListener
{
public:
    DataCollector()
    : emgSamples()
    {
    }

    // onUnpair() is called whenever the Myo is disconnected from Myo Connect by the user.
    void onUnpair(myo::Myo* myo, uint64_t timestamp)
    {
        // We've lost a Myo.        // Let's clean up some leftover state.
        emgSamples.fill(0);
    }

    // onEmgData() is called whenever a paired Myo has provided new EMG data, and EMG streaming is enabled.
    void onEmgData(myo::Myo* myo, uint64_t timestamp, const int8_t* emg)
    {
        for (int i = 0; i < 8; i++) {
            emgSamples[i] = emg[i];
            emgSamplesD[i] = (double) emg[i];
        }
    }

    // There are other virtual functions in DeviceListener that we could override here, like onAccelerometerData().
    // For this example, the functions overridden above are sufficient.
    void onAccelerometerData(myo::Myo* myo, uint64_t timestamp, const myo::Vector3<float> &accel)
    {
            accSamplesD[0] = (double) accel.x();
            accSamplesD[1] = (double) accel.y();
            accSamplesD[2] = (double) accel.z();
            accSamplesD[3] = (double) accel.magnitude();
    }

    void print()
    {
        //qDebug() << '\r';
        for (size_t i = 0; i < emgSamples.size(); i++)
        {
            ostringstream oss;
            oss << static_cast<int>(emgSamples[i]);
            string emgString = oss.str();
            QString qemgString = QString::fromStdString(emgString);
            QString qbuffStr =  QString::fromStdString(std::string(4 - emgString.size(), ' '));
            qDebug() << '[' << qemgString <<  qbuffStr << ']';
        }
    }

    std::array<double, 8> returnEMGDouble()
    {
        return  emgSamplesD;
    }

    std::array<double, 4> returnACCDouble()
    {
        return  accSamplesD;
    }
    void plot()
    {

    }

    std::array<int8_t, 8> emgSamples;               // The values of this array is set by onEmgData() above.
    std::array<double, 8> emgSamplesD;               // The values of this array is set by onEmgData() above.
    std::array<double, 4> accSamplesD;
};


DataCollector collector;
myo::Hub hub("com.example.emg-data-sample");
//myo::Hub hub;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //creation of tables of your data
    data_time = new QVector<double>;
    data_plotTime = new QVector<double>;       //only cntlfreq*10 samples for plotting
    data_emg1 = new QVector<double>; data_emg2 = new QVector<double>; data_emg3 = new QVector<double>;
    data_emg4 = new QVector<double>; data_emg5 = new QVector<double>; data_emg6 = new QVector<double>;
    data_emg7 = new QVector<double>; data_emg8 = new QVector<double>;
    data_accX = new QVector<double>; data_accY = new QVector<double>; data_accZ = new QVector<double>;

    data_plotTime->fill(0,maxFr);
    for(int i=1; i < maxFr; i++)
        data_plotTime->replace(i, data_plotTime->at(i-1) + (1/CntlFreq));

    //
    runStatus = false;
    myoStatus = false;

    //setup timer
        timer = new QTimer(this);
        timer->setInterval(1);     //originally 40

    ui->setupUi(this);

    //initialize the plot area
    init_qwtPlot();

    //setup timer
    timer = new QTimer(this);
    timer->setInterval(1);     //originally 40


    //get frequency of CPU
    frameNum = 0;
    QueryPerformanceFrequency((LARGE_INTEGER *) &freq);
        qDebug() << "CPU frequency: " << freq;
    QueryPerformanceCounter( (LARGE_INTEGER*) &first_get);

    connect(ui->openCloseButton, SIGNAL(clicked()), SLOT(onOpenCloseButtonClicked()));
    connect(ui->saveFileButton, SIGNAL(clicked()), SLOT(onSaveFileButtonClicked()));
    connect(ui->fileDirectoryButton, SIGNAL(clicked()), SLOT(onFileDirectoryButtonClicked() ));

    connect(timer, SIGNAL(timeout()), SLOT(onReadyRead()));


}

void MainWindow::onOpenCloseButtonClicked()
{
    if(myoStatus == false)
    {
        try
        {
            //myo::Hub hub("com.example.emg-data-sample");
            //hub("com.example.emg-data-sample");
            qDebug() << "Attempting to find a Myo...";

            myo::Myo* myo = hub.waitForMyo(1000);
            // If waitForMyo() returned a null pointer, we failed to find a Myo, so exit with an error message.
            if (!myo)
            {
                qDebug() << "Unable to find a Myo!";
            }
            qDebug() << "Connected to a Myo armband!";

            // Next we enable EMG streaming on the found Myo.
            myo->setStreamEmg(myo::Myo::streamEmgEnabled);

            // Next we construct an instance of our DeviceListener, so that we can register it with the Hub.
            //DataCollector collector;
                //qDebug() << "jim1!";
            hub.addListener(&collector);
                //qDebug() << "jim2";

            // Finally we enter our main loop.
            /*
            while (1)
            {
                // In each iteration of our main loop, we run the Myo event loop for a set number of milliseconds.
                // In this case, we wish to update our display 50 times a second, so we run for 1000/20 milliseconds.
                hub.run(50);
                collector.print();
                //collector.plot();
                //emgSamplesD = collector.returnEMGDouble();
                //plotEMG();
            }
            */
        }
        catch (const std::exception& e)
        {
            qDebug() << "Error: " << e.what() ;
        }
        myoStatus = true;
    }

    //If using polling mode, we need a QTimer
    if (runStatus == false)
    {
        qDebug("Program has started!");
        runStatus = true;

        frameNum = 0;
        cnt_get = 0;
        QueryPerformanceCounter( (LARGE_INTEGER*) &first_get);
        last_frame = first_get;

        timer->start();

        ui->openCloseButton->setText("Stop Myo");
        ui->openCloseButton->setStyleSheet("* { background-color: rgb(255,0,0) }");
    }
    else
    {
        runStatus = false;
        timer->stop();
        qDebug("Program has stopped!");
        ui->openCloseButton->setText(tr("&Start Myo"));
        ui->openCloseButton->setStyleSheet("* { background-color: rgb(240,240,240) }");
    }


}

void MainWindow::onReadyRead()
{
    QueryPerformanceCounter((LARGE_INTEGER *) &cnt);
    hub.run(5);        //hub.run(10) : 100 Hz   //hub.run(50) : 50 Hz
    if( ((double)(cnt - first_get) / freq) >= period*(cnt_get+1) )
    {
        emgSamplesD = collector.returnEMGDouble();
        accSamplesD = collector.returnACCDouble();

        if (saveFlag)
        {
            QTextStream outCom(&csvfile);
            outCom << frameNum << ", " << ((double)(cnt - last_frame) / freq) << ", "
                   << emgSamplesD[0] << ", "  << emgSamplesD[1] << ", "
                   << emgSamplesD[2] << ", "  << emgSamplesD[3] << ", "
                   << accSamplesD[0] << ", " << accSamplesD[1] << ", " << accSamplesD[2] << endl;
        }

        plotEMG();

        last_frame = cnt;
        cnt_get++;
        frameNum++;
    }
}



void MainWindow::onSaveFileButtonClicked()
{
    //frameNum = 0;   cnt =  0;
    //QueryPerformanceCounter( (LARGE_INTEGER *)&first_get );
    //     last_frame = first_get;

    if(!saveFlag && runStatus)
    {
        saveFlag = true;
        ui->saveFileButton->setText("Stop Saving");
        ui->saveFileButton->setStyleSheet("* { background-color: rgb(255,0,0) }");

        int fileNameValue = ui->fileNameSpinBox->value();
        QString fileDirectory = ui->fileLocationTextEdit->displayText();
        QString fileName = ui->fileNameTextEdit->displayText();
            fileComplete = fileDirectory.append("/");
            fileComplete = fileComplete.append(fileName);
            fileComplete = fileComplete.append(QString::number(fileNameValue));
            fileComplete = fileComplete.append(".csv");

        if (fileComplete.isEmpty() || fileDirectory.isEmpty() || fileName.isEmpty())
        {
            qDebug() << "No valid filename or file directory is detected!";
            return;
        }
        else
        {
            csvfile.setFileName(fileComplete);
            if (!csvfile.open(QIODevice::WriteOnly))
            {
                QMessageBox::information(this, tr("Unable to open file"),
                    csvfile.errorString());
                return;
            }
            csvfile.open(QIODevice::Append | QIODevice::Text);
            QTextStream outcsvfile(&csvfile);
            outcsvfile << "Frame, " << "Time_def, " << "Emg1, " << "Emg2, " << "Emg3, " << "Emg4, "
                                                    << "AccX, " << "AccY, "
                                                    << "AccZ" << endl;
        }
    }

    else if(saveFlag )
    {
        csvfile.close();
        saveFlag = false;
        int fileNameValue = ui->fileNameSpinBox->value();

        fileNameValue = fileNameValue + 1;
        ui->fileNameSpinBox->setValue(fileNameValue);
        ui->receiveEditText->setText(fileComplete);

        ui->saveFileButton->setText(tr("&Save..."));
        ui->saveFileButton->setToolTip(tr("Save contacts to a file"));      //ui->saveButton->setEnabled(false);
        ui->saveFileButton->setStyleSheet("* { background-color: rgb(240,240,240) }");
    }
    else
    {
    }
}

void MainWindow::onFileDirectoryButtonClicked()
{
    QString fileDirectory = QFileDialog::getExistingDirectory(this,"Caption",QString(),QFileDialog::ShowDirsOnly);
    qDebug()<<fileDirectory;
    ui->fileLocationTextEdit->setText(fileDirectory);
}


void MainWindow::plotEMG()
{
    //
    data_plotEmg1.clear();
    data_plotEmg2.clear();
    data_plotEmg5.clear();
    data_plotEmg6.clear();

    data_plotAccX.clear();
    data_plotAccY.clear();
    data_plotAccZ.clear();

    //Plot
    data_time->push_back(((double)(cnt - first_get) / freq));
    data_emg1->push_back(emgSamplesD[0]);   data_emg2->push_back(emgSamplesD[1]);
    data_emg5->push_back(emgSamplesD[4]);   data_emg6->push_back(emgSamplesD[5]);
    data_accX->push_back(accSamplesD[0]);
    data_accY->push_back(accSamplesD[1]);
    data_accZ->push_back(accSamplesD[2]);

    if(data_time->size() < maxFr)
    {
        curveEMG1->setSamples(*data_time,*data_emg1);// we set the data to the curve
        curveEMG2->setSamples(*data_time,*data_emg2);
        curveEMG5->setSamples(*data_time,*data_emg5);
        curveEMG6->setSamples(*data_time,*data_emg6);
        curveACCX->setSamples(*data_time,*data_accX);
        curveACCY->setSamples(*data_time,*data_accY);
        curveACCZ->setSamples(*data_time,*data_accZ);

    }
    else
    {
        data_plotEmg1 = data_emg1->mid(data_emg1->size()-(maxFr - 1), maxFr);
        data_plotEmg2 = data_emg2->mid(data_emg2->size()-(maxFr - 1), maxFr);
        data_plotEmg5 = data_emg5->mid(data_emg5->size()-(maxFr - 1), maxFr);
        data_plotEmg6 = data_emg6->mid(data_emg6->size()-(maxFr - 1), maxFr);

        data_plotAccX = data_accX->mid(data_accX->size()-(maxFr - 1), maxFr);
        data_plotAccY = data_accY->mid(data_accY->size()-(maxFr - 1), maxFr);
        data_plotAccZ = data_accZ->mid(data_accZ->size()-(maxFr - 1), maxFr);

        curveEMG1->setSamples(*data_plotTime, data_plotEmg1);
        curveEMG2->setSamples(*data_plotTime, data_plotEmg2);
        curveEMG5->setSamples(*data_plotTime, data_plotEmg5);
        curveEMG6->setSamples(*data_plotTime, data_plotEmg6);
        curveACCX->setSamples(*data_plotTime, data_plotAccX);
        curveACCY->setSamples(*data_plotTime, data_plotAccY);
        curveACCZ->setSamples(*data_plotTime, data_plotAccZ);
        //curve->setSamples(*data_plotx, *((QVector) data_y->mid( data_y->size()-(CntlFreq - 1), CntlFreq)) );
    }

    ui->emg1Plot->replot(); // we redraw the graphe
    ui->emg2Plot->replot(); // we redraw the graphe
    ui->emg5Plot->replot(); // we redraw the graphe
    ui->emg6Plot->replot(); // we redraw the graphe
    ui->accelXPlot->replot();


}

void MainWindow::init_qwtPlot()
{
    ui->emg1Plot->setCanvasBackground( Qt::black );
        ui->emg1Plot->setAxisScale( QwtPlot::yLeft, -100.0, 100.0 );
        ui->emg1Plot->setAxisScale( QwtPlot::xBottom, 0.0, plotTime );
        QwtPlotGrid *grid1 = new QwtPlotGrid();
        grid1->setMajorPen( Qt::gray, 0, Qt::DashLine);
        grid1->enableX(0);  grid1->attach(ui->emg1Plot);
    ui->emg2Plot->setCanvasBackground( Qt::black );
        ui->emg2Plot->setAxisScale( QwtPlot::yLeft, -100.0, 100.0 );
        ui->emg2Plot->setAxisScale( QwtPlot::xBottom, 0.0, plotTime );
        QwtPlotGrid *grid2 = new QwtPlotGrid();
        grid2->setMajorPen( Qt::gray, 0, Qt::DashLine);
        grid2->enableX(0);  grid2->attach(ui->emg2Plot);
    //ui emg3
    //ui emg4
    ui->emg5Plot->setCanvasBackground( Qt::black );
        ui->emg5Plot->setAxisScale( QwtPlot::yLeft, -100.0, 100.0 );
        ui->emg5Plot->setAxisScale( QwtPlot::xBottom, 0.0, plotTime );
        QwtPlotGrid *grid5 = new QwtPlotGrid();
        grid5->setMajorPen( Qt::gray, 0, Qt::DashLine);
        grid5->enableX(0);  grid5->attach(ui->emg5Plot);
    ui->emg6Plot->setCanvasBackground( Qt::black );
        ui->emg6Plot->setAxisScale( QwtPlot::yLeft, -100.0, 100.0 );
        ui->emg6Plot->setAxisScale( QwtPlot::xBottom, 0.0, plotTime );
        QwtPlotGrid *grid6 = new QwtPlotGrid();
        grid6->setMajorPen( Qt::gray, 0, Qt::DashLine);
        grid6->enableX(0);  grid6->attach(ui->emg6Plot);
    //ui emg7
    //ui emg8

    ui->accelXPlot->setCanvasBackground( Qt::black );
        ui->accelXPlot->setAxisScale( QwtPlot::yLeft, -2.5, 2.5 );
        ui->accelXPlot->setAxisScale( QwtPlot::xBottom, 0.0, plotTime );
        QwtPlotGrid *grid9 = new QwtPlotGrid();
        grid9->setMajorPen( Qt::gray, 0, Qt::DashLine);
        grid9->enableX(0);  grid9->attach(ui->accelXPlot);

    // creation of the curve (you can add more curve to a graphe)
    curveEMG1 = new QwtPlotCurve;      curveEMG2 = new QwtPlotCurve;      curveACCX = new QwtPlotCurve;
    curveEMG1->setPen(Qt::white, 2);   curveEMG2->setPen(Qt::white, 2);   curveACCX->setPen(Qt::red, 2);
    curveEMG1->attach(ui->emg1Plot);   curveEMG2->attach(ui->emg2Plot);   curveACCX->attach(ui->accelXPlot);

    curveEMG5 = new QwtPlotCurve;      curveEMG6 = new QwtPlotCurve;      curveACCY = new QwtPlotCurve;
    curveEMG5->setPen(Qt::white, 2);   curveEMG6->setPen(Qt::white, 2);   curveACCY->setPen(Qt::green, 2);
    curveEMG5->attach(ui->emg5Plot);   curveEMG6->attach(ui->emg6Plot);   curveACCY->attach(ui->accelXPlot);

    curveACCZ = new QwtPlotCurve;
    curveACCZ->setPen(Qt::blue, 2);
    curveACCZ->attach(ui->accelXPlot);
}


MainWindow::~MainWindow()
{
    delete ui;
}
