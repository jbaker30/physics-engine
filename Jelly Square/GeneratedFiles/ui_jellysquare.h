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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *JellySquareClass)
    {
        if (JellySquareClass->objectName().isEmpty())
            JellySquareClass->setObjectName(QStringLiteral("JellySquareClass"));
        JellySquareClass->resize(840, 572);
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
        JellySquareClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(JellySquareClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 840, 21));
        JellySquareClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(JellySquareClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        JellySquareClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(JellySquareClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        JellySquareClass->setStatusBar(statusBar);

        retranslateUi(JellySquareClass);

        QMetaObject::connectSlotsByName(JellySquareClass);
    } // setupUi

    void retranslateUi(QMainWindow *JellySquareClass)
    {
        JellySquareClass->setWindowTitle(QApplication::translate("JellySquareClass", "JellySquare", 0));
    } // retranslateUi

};

namespace Ui {
    class JellySquareClass: public Ui_JellySquareClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JELLYSQUARE_H
