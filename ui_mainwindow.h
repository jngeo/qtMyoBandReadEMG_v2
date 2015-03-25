/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QwtPlot *emg1Plot;
    QLabel *label_emg1;
    QLabel *blackBG;
    QLabel *label_emg5;
    QwtPlot *emg5Plot;
    QLabel *label_emg2;
    QwtPlot *emg2Plot;
    QLabel *label_emg6;
    QwtPlot *emg6Plot;
    QPushButton *openCloseButton;
    QLabel *directoryLabel;
    QSpinBox *fileNameSpinBox;
    QToolButton *fileDirectoryButton;
    QLineEdit *receiveEditText;
    QLineEdit *fileLocationTextEdit;
    QLabel *filenameLabel;
    QPushButton *saveFileButton;
    QLabel *saveBackground;
    QLineEdit *fileNameTextEdit;
    QLabel *label_emg5_2;
    QwtPlot *accelXPlot;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1150, 773);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        emg1Plot = new QwtPlot(centralWidget);
        emg1Plot->setObjectName(QStringLiteral("emg1Plot"));
        emg1Plot->setGeometry(QRect(40, 60, 331, 161));
        label_emg1 = new QLabel(centralWidget);
        label_emg1->setObjectName(QStringLiteral("label_emg1"));
        label_emg1->setGeometry(QRect(40, 30, 121, 21));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_emg1->setPalette(palette);
        QFont font;
        font.setPointSize(12);
        label_emg1->setFont(font);
        label_emg1->setWordWrap(true);
        blackBG = new QLabel(centralWidget);
        blackBG->setObjectName(QStringLiteral("blackBG"));
        blackBG->setGeometry(QRect(20, 20, 791, 681));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        QBrush brush3(QColor(255, 255, 220, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush3);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        blackBG->setPalette(palette1);
        blackBG->setAutoFillBackground(true);
        label_emg5 = new QLabel(centralWidget);
        label_emg5->setObjectName(QStringLiteral("label_emg5"));
        label_emg5->setGeometry(QRect(440, 30, 121, 21));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_emg5->setPalette(palette2);
        label_emg5->setFont(font);
        label_emg5->setWordWrap(true);
        emg5Plot = new QwtPlot(centralWidget);
        emg5Plot->setObjectName(QStringLiteral("emg5Plot"));
        emg5Plot->setGeometry(QRect(440, 60, 331, 161));
        label_emg2 = new QLabel(centralWidget);
        label_emg2->setObjectName(QStringLiteral("label_emg2"));
        label_emg2->setGeometry(QRect(40, 220, 121, 21));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_emg2->setPalette(palette3);
        label_emg2->setFont(font);
        label_emg2->setWordWrap(true);
        emg2Plot = new QwtPlot(centralWidget);
        emg2Plot->setObjectName(QStringLiteral("emg2Plot"));
        emg2Plot->setGeometry(QRect(40, 250, 331, 161));
        label_emg6 = new QLabel(centralWidget);
        label_emg6->setObjectName(QStringLiteral("label_emg6"));
        label_emg6->setGeometry(QRect(440, 220, 121, 21));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_emg6->setPalette(palette4);
        label_emg6->setFont(font);
        label_emg6->setWordWrap(true);
        emg6Plot = new QwtPlot(centralWidget);
        emg6Plot->setObjectName(QStringLiteral("emg6Plot"));
        emg6Plot->setGeometry(QRect(440, 250, 331, 161));
        openCloseButton = new QPushButton(centralWidget);
        openCloseButton->setObjectName(QStringLiteral("openCloseButton"));
        openCloseButton->setGeometry(QRect(910, 20, 81, 31));
        directoryLabel = new QLabel(centralWidget);
        directoryLabel->setObjectName(QStringLiteral("directoryLabel"));
        directoryLabel->setGeometry(QRect(830, 90, 71, 21));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush4(QColor(127, 127, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(170, 170, 170, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush3);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        directoryLabel->setPalette(palette5);
        directoryLabel->setFont(font);
        directoryLabel->setWordWrap(true);
        fileNameSpinBox = new QSpinBox(centralWidget);
        fileNameSpinBox->setObjectName(QStringLiteral("fileNameSpinBox"));
        fileNameSpinBox->setGeometry(QRect(1030, 120, 31, 22));
        fileNameSpinBox->setValue(1);
        fileDirectoryButton = new QToolButton(centralWidget);
        fileDirectoryButton->setObjectName(QStringLiteral("fileDirectoryButton"));
        fileDirectoryButton->setGeometry(QRect(1030, 90, 20, 21));
        receiveEditText = new QLineEdit(centralWidget);
        receiveEditText->setObjectName(QStringLiteral("receiveEditText"));
        receiveEditText->setGeometry(QRect(820, 200, 321, 21));
        fileLocationTextEdit = new QLineEdit(centralWidget);
        fileLocationTextEdit->setObjectName(QStringLiteral("fileLocationTextEdit"));
        fileLocationTextEdit->setGeometry(QRect(910, 90, 113, 20));
        filenameLabel = new QLabel(centralWidget);
        filenameLabel->setObjectName(QStringLiteral("filenameLabel"));
        filenameLabel->setGeometry(QRect(830, 120, 71, 21));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush3);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        filenameLabel->setPalette(palette6);
        filenameLabel->setFont(font);
        filenameLabel->setWordWrap(true);
        saveFileButton = new QPushButton(centralWidget);
        saveFileButton->setObjectName(QStringLiteral("saveFileButton"));
        saveFileButton->setGeometry(QRect(910, 150, 71, 31));
        saveBackground = new QLabel(centralWidget);
        saveBackground->setObjectName(QStringLiteral("saveBackground"));
        saveBackground->setEnabled(true);
        saveBackground->setGeometry(QRect(820, 80, 321, 111));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush2);
        QBrush brush6(QColor(127, 170, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush6);
        QBrush brush7(QColor(63, 127, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush7);
        QBrush brush8(QColor(0, 42, 127, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush8);
        QBrush brush9(QColor(0, 56, 170, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush9);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush10(QColor(0, 85, 255, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush10);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush3);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush10);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        saveBackground->setPalette(palette7);
        saveBackground->setAutoFillBackground(true);
        saveBackground->setFrameShape(QFrame::Box);
        saveBackground->setScaledContents(true);
        saveBackground->setWordWrap(true);
        fileNameTextEdit = new QLineEdit(centralWidget);
        fileNameTextEdit->setObjectName(QStringLiteral("fileNameTextEdit"));
        fileNameTextEdit->setGeometry(QRect(910, 120, 113, 21));
        label_emg5_2 = new QLabel(centralWidget);
        label_emg5_2->setObjectName(QStringLiteral("label_emg5_2"));
        label_emg5_2->setGeometry(QRect(40, 420, 391, 21));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_emg5_2->setPalette(palette8);
        label_emg5_2->setFont(font);
        label_emg5_2->setWordWrap(true);
        accelXPlot = new QwtPlot(centralWidget);
        accelXPlot->setObjectName(QStringLiteral("accelXPlot"));
        accelXPlot->setGeometry(QRect(40, 450, 331, 161));
        MainWindow->setCentralWidget(centralWidget);
        blackBG->raise();
        saveBackground->raise();
        emg1Plot->raise();
        label_emg1->raise();
        label_emg5->raise();
        emg5Plot->raise();
        label_emg2->raise();
        emg2Plot->raise();
        label_emg6->raise();
        emg6Plot->raise();
        openCloseButton->raise();
        directoryLabel->raise();
        fileNameSpinBox->raise();
        fileDirectoryButton->raise();
        receiveEditText->raise();
        fileLocationTextEdit->raise();
        filenameLabel->raise();
        saveFileButton->raise();
        fileNameTextEdit->raise();
        label_emg5_2->raise();
        accelXPlot->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1150, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_emg1->setText(QApplication::translate("MainWindow", "EMG 1", 0));
        blackBG->setText(QString());
        label_emg5->setText(QApplication::translate("MainWindow", "EMG 5", 0));
        label_emg2->setText(QApplication::translate("MainWindow", "EMG 2", 0));
        label_emg6->setText(QApplication::translate("MainWindow", "EMG 6", 0));
        openCloseButton->setText(QApplication::translate("MainWindow", "Open/Close", 0));
        directoryLabel->setText(QApplication::translate("MainWindow", "Directory:", 0));
        fileDirectoryButton->setText(QApplication::translate("MainWindow", "...", 0));
        receiveEditText->setText(QString());
        fileLocationTextEdit->setText(QString());
        filenameLabel->setText(QApplication::translate("MainWindow", "Filename:", 0));
        saveFileButton->setText(QApplication::translate("MainWindow", "Save...", 0));
        saveBackground->setText(QString());
        fileNameTextEdit->setText(QApplication::translate("MainWindow", "testFile", 0));
        label_emg5_2->setText(QApplication::translate("MainWindow", "Accel X - red ; Accel Y- Blue ; AccelZ - Green", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
