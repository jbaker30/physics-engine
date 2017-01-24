/********************************************************************************
** Form generated from reading UI file 'jellysquare.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JELLYSQUARE_H
#define UI_JELLYSQUARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "customrender.h"

QT_BEGIN_NAMESPACE

class Ui_JellySquareClass
{
public:
    QWidget *centralWidget;
    CustomRender *graphicsView;
    QSlider *massSlider;
    QLabel *label;
    QLabel *label_2;
    QSlider *springSlider;
    QLabel *label_3;
    QSlider *dampingSlider;
    QSlider *resistanceSlider;
    QLabel *label_4;
    QLabel *massLabel;
    QLabel *springLabel;
    QLabel *dampingLabel;
    QLabel *resistanceLabel;
    QLabel *intLabel;
    QSlider *intSlider;
    QLabel *label_5;
    QPushButton *resetButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *JellySquareClass)
    {
        if (JellySquareClass->objectName().isEmpty())
            JellySquareClass->setObjectName(QStringLiteral("JellySquareClass"));
        JellySquareClass->resize(841, 690);
        centralWidget = new QWidget(JellySquareClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new CustomRender(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 10, 800, 500));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setSceneRect(QRectF(0, 0, 0, 0));
        graphicsView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        massSlider = new QSlider(centralWidget);
        massSlider->setObjectName(QStringLiteral("massSlider"));
        massSlider->setGeometry(QRect(20, 520, 160, 22));
        massSlider->setMaximum(20);
        massSlider->setValue(10);
        massSlider->setSliderPosition(10);
        massSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 550, 71, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(290, 550, 101, 16));
        springSlider = new QSlider(centralWidget);
        springSlider->setObjectName(QStringLiteral("springSlider"));
        springSlider->setGeometry(QRect(290, 520, 160, 22));
        springSlider->setMaximum(100);
        springSlider->setSingleStep(1);
        springSlider->setSliderPosition(20);
        springSlider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(550, 550, 121, 16));
        dampingSlider = new QSlider(centralWidget);
        dampingSlider->setObjectName(QStringLiteral("dampingSlider"));
        dampingSlider->setGeometry(QRect(550, 520, 160, 22));
        dampingSlider->setMaximum(30);
        dampingSlider->setSliderPosition(5);
        dampingSlider->setOrientation(Qt::Horizontal);
        resistanceSlider = new QSlider(centralWidget);
        resistanceSlider->setObjectName(QStringLiteral("resistanceSlider"));
        resistanceSlider->setGeometry(QRect(20, 580, 160, 22));
        resistanceSlider->setMaximum(100);
        resistanceSlider->setValue(0);
        resistanceSlider->setSliderPosition(0);
        resistanceSlider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 610, 121, 16));
        massLabel = new QLabel(centralWidget);
        massLabel->setObjectName(QStringLiteral("massLabel"));
        massLabel->setGeometry(QRect(190, 520, 41, 16));
        springLabel = new QLabel(centralWidget);
        springLabel->setObjectName(QStringLiteral("springLabel"));
        springLabel->setGeometry(QRect(460, 520, 41, 16));
        dampingLabel = new QLabel(centralWidget);
        dampingLabel->setObjectName(QStringLiteral("dampingLabel"));
        dampingLabel->setGeometry(QRect(730, 520, 41, 16));
        resistanceLabel = new QLabel(centralWidget);
        resistanceLabel->setObjectName(QStringLiteral("resistanceLabel"));
        resistanceLabel->setGeometry(QRect(190, 580, 41, 16));
        intLabel = new QLabel(centralWidget);
        intLabel->setObjectName(QStringLiteral("intLabel"));
        intLabel->setGeometry(QRect(460, 580, 41, 16));
        intSlider = new QSlider(centralWidget);
        intSlider->setObjectName(QStringLiteral("intSlider"));
        intSlider->setGeometry(QRect(290, 580, 160, 22));
        intSlider->setMaximum(50);
        intSlider->setSingleStep(1);
        intSlider->setSliderPosition(20);
        intSlider->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(290, 610, 101, 16));
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setGeometry(QRect(670, 570, 75, 23));
        JellySquareClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(JellySquareClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 841, 21));
        JellySquareClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(JellySquareClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        JellySquareClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(JellySquareClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        JellySquareClass->setStatusBar(statusBar);

        retranslateUi(JellySquareClass);
        QObject::connect(massSlider, SIGNAL(valueChanged(int)), massLabel, SLOT(setNum(int)));
        QObject::connect(springSlider, SIGNAL(valueChanged(int)), springLabel, SLOT(setNum(int)));
        QObject::connect(dampingSlider, SIGNAL(valueChanged(int)), dampingLabel, SLOT(setNum(int)));
        QObject::connect(resistanceSlider, SIGNAL(valueChanged(int)), resistanceLabel, SLOT(setNum(int)));
        QObject::connect(massSlider, SIGNAL(valueChanged(int)), graphicsView, SLOT(ChangeMass(int)));
        QObject::connect(springSlider, SIGNAL(valueChanged(int)), graphicsView, SLOT(ChangeSpring(int)));
        QObject::connect(dampingSlider, SIGNAL(valueChanged(int)), graphicsView, SLOT(ChangeDamper(int)));
        QObject::connect(resistanceSlider, SIGNAL(valueChanged(int)), graphicsView, SLOT(ChangeResistance(int)));
        QObject::connect(intSlider, SIGNAL(valueChanged(int)), intLabel, SLOT(setNum(int)));
        QObject::connect(intSlider, SIGNAL(valueChanged(int)), graphicsView, SLOT(ChangePressure(int)));
        QObject::connect(graphicsView, SIGNAL(ResetMass(int)), massSlider, SLOT(setValue(int)));
        QObject::connect(graphicsView, SIGNAL(ResetResistance(int)), resistanceSlider, SLOT(setValue(int)));
        QObject::connect(graphicsView, SIGNAL(ResetSpring(int)), springSlider, SLOT(setValue(int)));
        QObject::connect(graphicsView, SIGNAL(ResetPressure(int)), intSlider, SLOT(setValue(int)));
        QObject::connect(graphicsView, SIGNAL(ResetDamper(int)), dampingSlider, SLOT(setValue(int)));
        QObject::connect(resetButton, SIGNAL(clicked()), graphicsView, SLOT(ResetSimulation()));

        QMetaObject::connectSlotsByName(JellySquareClass);
    } // setupUi

    void retranslateUi(QMainWindow *JellySquareClass)
    {
        JellySquareClass->setWindowTitle(QApplication::translate("JellySquareClass", "JellySquare", 0));
        label->setText(QApplication::translate("JellySquareClass", "Mass", 0));
        label_2->setText(QApplication::translate("JellySquareClass", "Spring Coefficient", 0));
        label_3->setText(QApplication::translate("JellySquareClass", "Damping Coefficient", 0));
        label_4->setText(QApplication::translate("JellySquareClass", "Resistance", 0));
        massLabel->setText(QApplication::translate("JellySquareClass", "10", 0));
        springLabel->setText(QApplication::translate("JellySquareClass", "20", 0));
        dampingLabel->setText(QApplication::translate("JellySquareClass", "5", 0));
        resistanceLabel->setText(QApplication::translate("JellySquareClass", "98", 0));
        intLabel->setText(QApplication::translate("JellySquareClass", "20", 0));
        label_5->setText(QApplication::translate("JellySquareClass", "Internal Pressure", 0));
        resetButton->setText(QApplication::translate("JellySquareClass", "Reset", 0));
    } // retranslateUi

};

namespace Ui {
    class JellySquareClass: public Ui_JellySquareClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JELLYSQUARE_H
