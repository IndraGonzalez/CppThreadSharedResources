/********************************************************************************
** Form generated from reading UI file 'BinaryFileReader.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BINARYFILEREADER_H
#define UI_BINARYFILEREADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BinaryFileReaderClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BinaryFileReaderClass)
    {
        if (BinaryFileReaderClass->objectName().isEmpty())
            BinaryFileReaderClass->setObjectName(QStringLiteral("BinaryFileReaderClass"));
        BinaryFileReaderClass->resize(600, 400);
        centralWidget = new QWidget(BinaryFileReaderClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        verticalLayout->addWidget(startButton);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        verticalLayout->addWidget(stopButton);

        BinaryFileReaderClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BinaryFileReaderClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        BinaryFileReaderClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BinaryFileReaderClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        BinaryFileReaderClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BinaryFileReaderClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        BinaryFileReaderClass->setStatusBar(statusBar);

        retranslateUi(BinaryFileReaderClass);

        QMetaObject::connectSlotsByName(BinaryFileReaderClass);
    } // setupUi

    void retranslateUi(QMainWindow *BinaryFileReaderClass)
    {
        BinaryFileReaderClass->setWindowTitle(QApplication::translate("BinaryFileReaderClass", "BinaryFileReader", 0));
        startButton->setText(QApplication::translate("BinaryFileReaderClass", "Empezar a leer", 0));
        stopButton->setText(QApplication::translate("BinaryFileReaderClass", "Para de leer", 0));
    } // retranslateUi

};

namespace Ui {
    class BinaryFileReaderClass: public Ui_BinaryFileReaderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BINARYFILEREADER_H
