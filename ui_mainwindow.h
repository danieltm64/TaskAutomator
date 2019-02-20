/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "tasklist.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd;
    QAction *actionEdit;
    QAction *actionRemove;
    QAction *actionSelectAll;
    QAction *actionSelectNone;
    QAction *actionConfiguration;
    QAction *actionUserManual;
    QAction *actionAbout;
    QAction *actionRestore;
    QAction *actionExit;
    QWidget *centralWidget;
    TaskList *treeWidget_taskList;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(550, 300);
        MainWindow->setMinimumSize(QSize(550, 300));
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QString::fromUtf8("actionAdd"));
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        actionRemove = new QAction(MainWindow);
        actionRemove->setObjectName(QString::fromUtf8("actionRemove"));
        actionSelectAll = new QAction(MainWindow);
        actionSelectAll->setObjectName(QString::fromUtf8("actionSelectAll"));
        actionSelectNone = new QAction(MainWindow);
        actionSelectNone->setObjectName(QString::fromUtf8("actionSelectNone"));
        actionConfiguration = new QAction(MainWindow);
        actionConfiguration->setObjectName(QString::fromUtf8("actionConfiguration"));
        actionUserManual = new QAction(MainWindow);
        actionUserManual->setObjectName(QString::fromUtf8("actionUserManual"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionRestore = new QAction(MainWindow);
        actionRestore->setObjectName(QString::fromUtf8("actionRestore"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        treeWidget_taskList = new TaskList(centralWidget);
        treeWidget_taskList->setObjectName(QString::fromUtf8("treeWidget_taskList"));
        treeWidget_taskList->setGeometry(QRect(0, 0, 551, 268));
        treeWidget_taskList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeWidget_taskList->setAlternatingRowColors(true);
        treeWidget_taskList->setSelectionMode(QAbstractItemView::ExtendedSelection);
        treeWidget_taskList->setRootIsDecorated(false);
        treeWidget_taskList->setColumnCount(2);
        treeWidget_taskList->header()->setDefaultSectionSize(130);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Task Automator", nullptr));
        actionAdd->setText(QApplication::translate("MainWindow", "Add", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAdd->setToolTip(QApplication::translate("MainWindow", "Adds a new task", nullptr));
#endif // QT_NO_TOOLTIP
        actionEdit->setText(QApplication::translate("MainWindow", "Edit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionEdit->setToolTip(QApplication::translate("MainWindow", "Edits the selected task", nullptr));
#endif // QT_NO_TOOLTIP
        actionRemove->setText(QApplication::translate("MainWindow", "Remove", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRemove->setToolTip(QApplication::translate("MainWindow", "Removes the selected tasks", nullptr));
#endif // QT_NO_TOOLTIP
        actionSelectAll->setText(QApplication::translate("MainWindow", "Select All", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSelectAll->setToolTip(QApplication::translate("MainWindow", "Selects all tasks in the list", nullptr));
#endif // QT_NO_TOOLTIP
        actionSelectNone->setText(QApplication::translate("MainWindow", "Select None", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSelectNone->setToolTip(QApplication::translate("MainWindow", "Clears the selection", nullptr));
#endif // QT_NO_TOOLTIP
        actionConfiguration->setText(QApplication::translate("MainWindow", "Configuration", nullptr));
#ifndef QT_NO_TOOLTIP
        actionConfiguration->setToolTip(QApplication::translate("MainWindow", "Shows the configuration dialog", nullptr));
#endif // QT_NO_TOOLTIP
        actionUserManual->setText(QApplication::translate("MainWindow", "User Manual", nullptr));
#ifndef QT_NO_TOOLTIP
        actionUserManual->setToolTip(QApplication::translate("MainWindow", "Shows the user manual", nullptr));
#endif // QT_NO_TOOLTIP
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAbout->setToolTip(QApplication::translate("MainWindow", "Shows authorship information", nullptr));
#endif // QT_NO_TOOLTIP
        actionRestore->setText(QApplication::translate("MainWindow", "Restore", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRestore->setToolTip(QApplication::translate("MainWindow", "Show Task Automator", nullptr));
#endif // QT_NO_TOOLTIP
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "Close Task Automator", nullptr));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_taskList->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Task", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Next Occurrence", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
