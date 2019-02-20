/********************************************************************************
** Form generated from reading UI file 'taskdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKDIALOG_H
#define UI_TASKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskDialog
{
public:
    QVBoxLayout *verticalLayout_taskDialog;
    QGroupBox *groupBox_task;
    QVBoxLayout *verticalLayout_task;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QLabel *label_action;
    QComboBox *comboBox_action;
    QStackedWidget *stackedWidget_task;
    QWidget *page_remindMe;
    QVBoxLayout *verticalLayout_remindMe;
    QLabel *label_remindMe;
    QPlainTextEdit *plainTextEdit_messageToRemindWith;
    QWidget *page_visitAWebsite;
    QVBoxLayout *verticalLayout_visitAWebsite;
    QLabel *label_visitAWebsite;
    QLineEdit *lineEdit_websiteToVisit;
    QSpacerItem *verticalSpacer_visitAWebsite;
    QWidget *page_openAFile;
    QVBoxLayout *verticalLayout_openAFile;
    QLabel *label_openAFile;
    QHBoxLayout *horizontalLayout_openAFile;
    QLineEdit *lineEdit_fileToOpen;
    QToolButton *toolButton_openAFile;
    QSpacerItem *verticalSpacer_openAFile;
    QWidget *page_runAProgram;
    QVBoxLayout *verticalLayout_runAProgram;
    QLabel *label_programToRun;
    QHBoxLayout *horizontalLayout_runAProgram;
    QLineEdit *lineEdit_programToRun;
    QToolButton *toolButton_runAProgram;
    QLabel *label_arguments;
    QLineEdit *lineEdit_arguments;
    QWidget *page_message_task;
    QHBoxLayout *horizontalLayout_message_task;
    QLabel *label_message_task;
    QGroupBox *groupBox_date;
    QVBoxLayout *verticalLayout_date;
    QComboBox *comboBox_date;
    QStackedWidget *stackedWidget_date;
    QWidget *page_specificDate;
    QHBoxLayout *horizontalLayout_specificDate;
    QCalendarWidget *calendarWidget_specifiedDate;
    QWidget *page_message_date;
    QHBoxLayout *horizontalLayout_message_date;
    QLabel *label_message_date;
    QWidget *page_monthlyDays;
    QGridLayout *gridLayout_monthlyDays;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_11;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_13;
    QCheckBox *checkBox_14;
    QCheckBox *checkBox_15;
    QCheckBox *checkBox_16;
    QCheckBox *checkBox_17;
    QCheckBox *checkBox_18;
    QCheckBox *checkBox_19;
    QCheckBox *checkBox_20;
    QCheckBox *checkBox_21;
    QCheckBox *checkBox_22;
    QCheckBox *checkBox_23;
    QCheckBox *checkBox_24;
    QCheckBox *checkBox_25;
    QCheckBox *checkBox_26;
    QCheckBox *checkBox_27;
    QCheckBox *checkBox_28;
    QCheckBox *checkBox_29;
    QCheckBox *checkBox_30;
    QCheckBox *checkBox_31;
    QWidget *page_weeklyDays;
    QVBoxLayout *verticalLayout_weeklyDays;
    QCheckBox *checkBox_sunday;
    QCheckBox *checkBox_monday;
    QCheckBox *checkBox_tuesday;
    QCheckBox *checkBox_wednesday;
    QCheckBox *checkBox_thursday;
    QCheckBox *checkBox_friday;
    QCheckBox *checkBox_saturday;
    QGroupBox *groupBox_time;
    QVBoxLayout *verticalLayout_time;
    QComboBox *comboBox_time;
    QStackedWidget *stackedWidget_time;
    QWidget *page_specificTime;
    QVBoxLayout *verticalLayout_specificTime;
    QHBoxLayout *horizontalLayout_specificTime;
    QTimeEdit *timeEdit_specifiedTime;
    QSpacerItem *horizontalSpacer_specificTime;
    QSpacerItem *verticalSpacer_specificTime;
    QWidget *page_timer;
    QVBoxLayout *verticalLayout_timer;
    QHBoxLayout *horizontalLayout_timer;
    QLabel *label_timer1;
    QSpinBox *spinBox_hoursFromNow;
    QLabel *label_timer2;
    QSpinBox *spinBox_minutesFromNow;
    QLabel *label_timer3;
    QSpacerItem *horizontalSpacer_timer;
    QComboBox *comboBox_startingFrom;
    QSpacerItem *verticalSpacer_timer;
    QWidget *page_repetitive;
    QVBoxLayout *verticalLayout_repetitive;
    QHBoxLayout *horizontalLayout_repetitive1;
    QLabel *label_repetitive1;
    QSpinBox *spinBox_runCount;
    QLabel *label_repetitive2;
    QTimeEdit *timeEdit_startingTime;
    QSpacerItem *horizontalSpacer_repetitive1;
    QHBoxLayout *horizontalLayout_repetitive2;
    QLabel *label_repetitive3;
    QSpinBox *spinBox_intervalHours;
    QLabel *label_repetitive4;
    QSpinBox *spinBox_intervalMinutes;
    QLabel *label_repetitive5;
    QSpacerItem *horizontalSpacer_repetitive2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TaskDialog)
    {
        if (TaskDialog->objectName().isEmpty())
            TaskDialog->setObjectName(QString::fromUtf8("TaskDialog"));
        TaskDialog->resize(319, 597);
        verticalLayout_taskDialog = new QVBoxLayout(TaskDialog);
        verticalLayout_taskDialog->setObjectName(QString::fromUtf8("verticalLayout_taskDialog"));
        groupBox_task = new QGroupBox(TaskDialog);
        groupBox_task->setObjectName(QString::fromUtf8("groupBox_task"));
        verticalLayout_task = new QVBoxLayout(groupBox_task);
        verticalLayout_task->setObjectName(QString::fromUtf8("verticalLayout_task"));
        label_name = new QLabel(groupBox_task);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        verticalLayout_task->addWidget(label_name);

        lineEdit_name = new QLineEdit(groupBox_task);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        verticalLayout_task->addWidget(lineEdit_name);

        label_action = new QLabel(groupBox_task);
        label_action->setObjectName(QString::fromUtf8("label_action"));

        verticalLayout_task->addWidget(label_action);

        comboBox_action = new QComboBox(groupBox_task);
        comboBox_action->addItem(QString());
        comboBox_action->addItem(QString());
        comboBox_action->addItem(QString());
        comboBox_action->addItem(QString());
        comboBox_action->addItem(QString());
        comboBox_action->addItem(QString());
        comboBox_action->addItem(QString());
        comboBox_action->setObjectName(QString::fromUtf8("comboBox_action"));

        verticalLayout_task->addWidget(comboBox_action);

        stackedWidget_task = new QStackedWidget(groupBox_task);
        stackedWidget_task->setObjectName(QString::fromUtf8("stackedWidget_task"));
        page_remindMe = new QWidget();
        page_remindMe->setObjectName(QString::fromUtf8("page_remindMe"));
        verticalLayout_remindMe = new QVBoxLayout(page_remindMe);
        verticalLayout_remindMe->setObjectName(QString::fromUtf8("verticalLayout_remindMe"));
        verticalLayout_remindMe->setContentsMargins(0, 0, 0, 0);
        label_remindMe = new QLabel(page_remindMe);
        label_remindMe->setObjectName(QString::fromUtf8("label_remindMe"));

        verticalLayout_remindMe->addWidget(label_remindMe);

        plainTextEdit_messageToRemindWith = new QPlainTextEdit(page_remindMe);
        plainTextEdit_messageToRemindWith->setObjectName(QString::fromUtf8("plainTextEdit_messageToRemindWith"));
        plainTextEdit_messageToRemindWith->setMaximumSize(QSize(16777215, 65));

        verticalLayout_remindMe->addWidget(plainTextEdit_messageToRemindWith);

        stackedWidget_task->addWidget(page_remindMe);
        page_visitAWebsite = new QWidget();
        page_visitAWebsite->setObjectName(QString::fromUtf8("page_visitAWebsite"));
        verticalLayout_visitAWebsite = new QVBoxLayout(page_visitAWebsite);
        verticalLayout_visitAWebsite->setObjectName(QString::fromUtf8("verticalLayout_visitAWebsite"));
        verticalLayout_visitAWebsite->setContentsMargins(0, 0, 0, 0);
        label_visitAWebsite = new QLabel(page_visitAWebsite);
        label_visitAWebsite->setObjectName(QString::fromUtf8("label_visitAWebsite"));

        verticalLayout_visitAWebsite->addWidget(label_visitAWebsite);

        lineEdit_websiteToVisit = new QLineEdit(page_visitAWebsite);
        lineEdit_websiteToVisit->setObjectName(QString::fromUtf8("lineEdit_websiteToVisit"));

        verticalLayout_visitAWebsite->addWidget(lineEdit_websiteToVisit);

        verticalSpacer_visitAWebsite = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_visitAWebsite->addItem(verticalSpacer_visitAWebsite);

        stackedWidget_task->addWidget(page_visitAWebsite);
        page_openAFile = new QWidget();
        page_openAFile->setObjectName(QString::fromUtf8("page_openAFile"));
        verticalLayout_openAFile = new QVBoxLayout(page_openAFile);
        verticalLayout_openAFile->setObjectName(QString::fromUtf8("verticalLayout_openAFile"));
        verticalLayout_openAFile->setContentsMargins(0, 0, 0, 0);
        label_openAFile = new QLabel(page_openAFile);
        label_openAFile->setObjectName(QString::fromUtf8("label_openAFile"));

        verticalLayout_openAFile->addWidget(label_openAFile);

        horizontalLayout_openAFile = new QHBoxLayout();
        horizontalLayout_openAFile->setObjectName(QString::fromUtf8("horizontalLayout_openAFile"));
        lineEdit_fileToOpen = new QLineEdit(page_openAFile);
        lineEdit_fileToOpen->setObjectName(QString::fromUtf8("lineEdit_fileToOpen"));
        lineEdit_fileToOpen->setReadOnly(true);

        horizontalLayout_openAFile->addWidget(lineEdit_fileToOpen);

        toolButton_openAFile = new QToolButton(page_openAFile);
        toolButton_openAFile->setObjectName(QString::fromUtf8("toolButton_openAFile"));

        horizontalLayout_openAFile->addWidget(toolButton_openAFile);


        verticalLayout_openAFile->addLayout(horizontalLayout_openAFile);

        verticalSpacer_openAFile = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_openAFile->addItem(verticalSpacer_openAFile);

        stackedWidget_task->addWidget(page_openAFile);
        page_runAProgram = new QWidget();
        page_runAProgram->setObjectName(QString::fromUtf8("page_runAProgram"));
        verticalLayout_runAProgram = new QVBoxLayout(page_runAProgram);
        verticalLayout_runAProgram->setObjectName(QString::fromUtf8("verticalLayout_runAProgram"));
        verticalLayout_runAProgram->setContentsMargins(0, 0, 0, 0);
        label_programToRun = new QLabel(page_runAProgram);
        label_programToRun->setObjectName(QString::fromUtf8("label_programToRun"));

        verticalLayout_runAProgram->addWidget(label_programToRun);

        horizontalLayout_runAProgram = new QHBoxLayout();
        horizontalLayout_runAProgram->setObjectName(QString::fromUtf8("horizontalLayout_runAProgram"));
        lineEdit_programToRun = new QLineEdit(page_runAProgram);
        lineEdit_programToRun->setObjectName(QString::fromUtf8("lineEdit_programToRun"));
        lineEdit_programToRun->setReadOnly(true);

        horizontalLayout_runAProgram->addWidget(lineEdit_programToRun);

        toolButton_runAProgram = new QToolButton(page_runAProgram);
        toolButton_runAProgram->setObjectName(QString::fromUtf8("toolButton_runAProgram"));

        horizontalLayout_runAProgram->addWidget(toolButton_runAProgram);


        verticalLayout_runAProgram->addLayout(horizontalLayout_runAProgram);

        label_arguments = new QLabel(page_runAProgram);
        label_arguments->setObjectName(QString::fromUtf8("label_arguments"));

        verticalLayout_runAProgram->addWidget(label_arguments);

        lineEdit_arguments = new QLineEdit(page_runAProgram);
        lineEdit_arguments->setObjectName(QString::fromUtf8("lineEdit_arguments"));

        verticalLayout_runAProgram->addWidget(lineEdit_arguments);

        stackedWidget_task->addWidget(page_runAProgram);
        page_message_task = new QWidget();
        page_message_task->setObjectName(QString::fromUtf8("page_message_task"));
        horizontalLayout_message_task = new QHBoxLayout(page_message_task);
        horizontalLayout_message_task->setObjectName(QString::fromUtf8("horizontalLayout_message_task"));
        horizontalLayout_message_task->setContentsMargins(0, 0, 0, 0);
        label_message_task = new QLabel(page_message_task);
        label_message_task->setObjectName(QString::fromUtf8("label_message_task"));
        label_message_task->setAlignment(Qt::AlignCenter);

        horizontalLayout_message_task->addWidget(label_message_task);

        stackedWidget_task->addWidget(page_message_task);

        verticalLayout_task->addWidget(stackedWidget_task);


        verticalLayout_taskDialog->addWidget(groupBox_task);

        groupBox_date = new QGroupBox(TaskDialog);
        groupBox_date->setObjectName(QString::fromUtf8("groupBox_date"));
        verticalLayout_date = new QVBoxLayout(groupBox_date);
        verticalLayout_date->setObjectName(QString::fromUtf8("verticalLayout_date"));
        comboBox_date = new QComboBox(groupBox_date);
        comboBox_date->addItem(QString());
        comboBox_date->addItem(QString());
        comboBox_date->addItem(QString());
        comboBox_date->addItem(QString());
        comboBox_date->addItem(QString());
        comboBox_date->addItem(QString());
        comboBox_date->setObjectName(QString::fromUtf8("comboBox_date"));

        verticalLayout_date->addWidget(comboBox_date);

        stackedWidget_date = new QStackedWidget(groupBox_date);
        stackedWidget_date->setObjectName(QString::fromUtf8("stackedWidget_date"));
        page_specificDate = new QWidget();
        page_specificDate->setObjectName(QString::fromUtf8("page_specificDate"));
        horizontalLayout_specificDate = new QHBoxLayout(page_specificDate);
        horizontalLayout_specificDate->setObjectName(QString::fromUtf8("horizontalLayout_specificDate"));
        horizontalLayout_specificDate->setContentsMargins(0, 0, 0, 0);
        calendarWidget_specifiedDate = new QCalendarWidget(page_specificDate);
        calendarWidget_specifiedDate->setObjectName(QString::fromUtf8("calendarWidget_specifiedDate"));
        calendarWidget_specifiedDate->setGridVisible(true);

        horizontalLayout_specificDate->addWidget(calendarWidget_specifiedDate);

        stackedWidget_date->addWidget(page_specificDate);
        page_message_date = new QWidget();
        page_message_date->setObjectName(QString::fromUtf8("page_message_date"));
        horizontalLayout_message_date = new QHBoxLayout(page_message_date);
        horizontalLayout_message_date->setObjectName(QString::fromUtf8("horizontalLayout_message_date"));
        horizontalLayout_message_date->setContentsMargins(0, 0, 0, 0);
        label_message_date = new QLabel(page_message_date);
        label_message_date->setObjectName(QString::fromUtf8("label_message_date"));
        label_message_date->setAlignment(Qt::AlignCenter);
        label_message_date->setWordWrap(true);

        horizontalLayout_message_date->addWidget(label_message_date);

        stackedWidget_date->addWidget(page_message_date);
        page_monthlyDays = new QWidget();
        page_monthlyDays->setObjectName(QString::fromUtf8("page_monthlyDays"));
        gridLayout_monthlyDays = new QGridLayout(page_monthlyDays);
        gridLayout_monthlyDays->setObjectName(QString::fromUtf8("gridLayout_monthlyDays"));
        gridLayout_monthlyDays->setContentsMargins(0, 0, 0, 0);
        checkBox_1 = new QCheckBox(page_monthlyDays);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));

        gridLayout_monthlyDays->addWidget(checkBox_1, 0, 0, 1, 1);

        checkBox_2 = new QCheckBox(page_monthlyDays);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_monthlyDays->addWidget(checkBox_2, 0, 1, 1, 1);

        checkBox_3 = new QCheckBox(page_monthlyDays);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout_monthlyDays->addWidget(checkBox_3, 0, 2, 1, 1);

        checkBox_4 = new QCheckBox(page_monthlyDays);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout_monthlyDays->addWidget(checkBox_4, 0, 3, 1, 1);

        checkBox_5 = new QCheckBox(page_monthlyDays);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));

        gridLayout_monthlyDays->addWidget(checkBox_5, 0, 4, 1, 1);

        checkBox_6 = new QCheckBox(page_monthlyDays);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));

        gridLayout_monthlyDays->addWidget(checkBox_6, 0, 5, 1, 1);

        checkBox_7 = new QCheckBox(page_monthlyDays);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));

        gridLayout_monthlyDays->addWidget(checkBox_7, 0, 6, 1, 1);

        checkBox_8 = new QCheckBox(page_monthlyDays);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));

        gridLayout_monthlyDays->addWidget(checkBox_8, 1, 0, 1, 1);

        checkBox_9 = new QCheckBox(page_monthlyDays);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));

        gridLayout_monthlyDays->addWidget(checkBox_9, 1, 1, 1, 1);

        checkBox_10 = new QCheckBox(page_monthlyDays);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));

        gridLayout_monthlyDays->addWidget(checkBox_10, 1, 2, 1, 1);

        checkBox_11 = new QCheckBox(page_monthlyDays);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));

        gridLayout_monthlyDays->addWidget(checkBox_11, 1, 3, 1, 1);

        checkBox_12 = new QCheckBox(page_monthlyDays);
        checkBox_12->setObjectName(QString::fromUtf8("checkBox_12"));

        gridLayout_monthlyDays->addWidget(checkBox_12, 1, 4, 1, 1);

        checkBox_13 = new QCheckBox(page_monthlyDays);
        checkBox_13->setObjectName(QString::fromUtf8("checkBox_13"));

        gridLayout_monthlyDays->addWidget(checkBox_13, 1, 5, 1, 1);

        checkBox_14 = new QCheckBox(page_monthlyDays);
        checkBox_14->setObjectName(QString::fromUtf8("checkBox_14"));

        gridLayout_monthlyDays->addWidget(checkBox_14, 1, 6, 1, 1);

        checkBox_15 = new QCheckBox(page_monthlyDays);
        checkBox_15->setObjectName(QString::fromUtf8("checkBox_15"));

        gridLayout_monthlyDays->addWidget(checkBox_15, 2, 0, 1, 1);

        checkBox_16 = new QCheckBox(page_monthlyDays);
        checkBox_16->setObjectName(QString::fromUtf8("checkBox_16"));

        gridLayout_monthlyDays->addWidget(checkBox_16, 2, 1, 1, 1);

        checkBox_17 = new QCheckBox(page_monthlyDays);
        checkBox_17->setObjectName(QString::fromUtf8("checkBox_17"));

        gridLayout_monthlyDays->addWidget(checkBox_17, 2, 2, 1, 1);

        checkBox_18 = new QCheckBox(page_monthlyDays);
        checkBox_18->setObjectName(QString::fromUtf8("checkBox_18"));

        gridLayout_monthlyDays->addWidget(checkBox_18, 2, 3, 1, 1);

        checkBox_19 = new QCheckBox(page_monthlyDays);
        checkBox_19->setObjectName(QString::fromUtf8("checkBox_19"));

        gridLayout_monthlyDays->addWidget(checkBox_19, 2, 4, 1, 1);

        checkBox_20 = new QCheckBox(page_monthlyDays);
        checkBox_20->setObjectName(QString::fromUtf8("checkBox_20"));

        gridLayout_monthlyDays->addWidget(checkBox_20, 2, 5, 1, 1);

        checkBox_21 = new QCheckBox(page_monthlyDays);
        checkBox_21->setObjectName(QString::fromUtf8("checkBox_21"));

        gridLayout_monthlyDays->addWidget(checkBox_21, 2, 6, 1, 1);

        checkBox_22 = new QCheckBox(page_monthlyDays);
        checkBox_22->setObjectName(QString::fromUtf8("checkBox_22"));

        gridLayout_monthlyDays->addWidget(checkBox_22, 3, 0, 1, 1);

        checkBox_23 = new QCheckBox(page_monthlyDays);
        checkBox_23->setObjectName(QString::fromUtf8("checkBox_23"));

        gridLayout_monthlyDays->addWidget(checkBox_23, 3, 1, 1, 1);

        checkBox_24 = new QCheckBox(page_monthlyDays);
        checkBox_24->setObjectName(QString::fromUtf8("checkBox_24"));

        gridLayout_monthlyDays->addWidget(checkBox_24, 3, 2, 1, 1);

        checkBox_25 = new QCheckBox(page_monthlyDays);
        checkBox_25->setObjectName(QString::fromUtf8("checkBox_25"));

        gridLayout_monthlyDays->addWidget(checkBox_25, 3, 3, 1, 1);

        checkBox_26 = new QCheckBox(page_monthlyDays);
        checkBox_26->setObjectName(QString::fromUtf8("checkBox_26"));

        gridLayout_monthlyDays->addWidget(checkBox_26, 3, 4, 1, 1);

        checkBox_27 = new QCheckBox(page_monthlyDays);
        checkBox_27->setObjectName(QString::fromUtf8("checkBox_27"));

        gridLayout_monthlyDays->addWidget(checkBox_27, 3, 5, 1, 1);

        checkBox_28 = new QCheckBox(page_monthlyDays);
        checkBox_28->setObjectName(QString::fromUtf8("checkBox_28"));

        gridLayout_monthlyDays->addWidget(checkBox_28, 3, 6, 1, 1);

        checkBox_29 = new QCheckBox(page_monthlyDays);
        checkBox_29->setObjectName(QString::fromUtf8("checkBox_29"));

        gridLayout_monthlyDays->addWidget(checkBox_29, 4, 0, 1, 1);

        checkBox_30 = new QCheckBox(page_monthlyDays);
        checkBox_30->setObjectName(QString::fromUtf8("checkBox_30"));

        gridLayout_monthlyDays->addWidget(checkBox_30, 4, 1, 1, 1);

        checkBox_31 = new QCheckBox(page_monthlyDays);
        checkBox_31->setObjectName(QString::fromUtf8("checkBox_31"));

        gridLayout_monthlyDays->addWidget(checkBox_31, 4, 2, 1, 1);

        stackedWidget_date->addWidget(page_monthlyDays);
        page_weeklyDays = new QWidget();
        page_weeklyDays->setObjectName(QString::fromUtf8("page_weeklyDays"));
        verticalLayout_weeklyDays = new QVBoxLayout(page_weeklyDays);
        verticalLayout_weeklyDays->setObjectName(QString::fromUtf8("verticalLayout_weeklyDays"));
        verticalLayout_weeklyDays->setContentsMargins(0, 0, 0, 0);
        checkBox_sunday = new QCheckBox(page_weeklyDays);
        checkBox_sunday->setObjectName(QString::fromUtf8("checkBox_sunday"));

        verticalLayout_weeklyDays->addWidget(checkBox_sunday);

        checkBox_monday = new QCheckBox(page_weeklyDays);
        checkBox_monday->setObjectName(QString::fromUtf8("checkBox_monday"));

        verticalLayout_weeklyDays->addWidget(checkBox_monday);

        checkBox_tuesday = new QCheckBox(page_weeklyDays);
        checkBox_tuesday->setObjectName(QString::fromUtf8("checkBox_tuesday"));

        verticalLayout_weeklyDays->addWidget(checkBox_tuesday);

        checkBox_wednesday = new QCheckBox(page_weeklyDays);
        checkBox_wednesday->setObjectName(QString::fromUtf8("checkBox_wednesday"));

        verticalLayout_weeklyDays->addWidget(checkBox_wednesday);

        checkBox_thursday = new QCheckBox(page_weeklyDays);
        checkBox_thursday->setObjectName(QString::fromUtf8("checkBox_thursday"));

        verticalLayout_weeklyDays->addWidget(checkBox_thursday);

        checkBox_friday = new QCheckBox(page_weeklyDays);
        checkBox_friday->setObjectName(QString::fromUtf8("checkBox_friday"));

        verticalLayout_weeklyDays->addWidget(checkBox_friday);

        checkBox_saturday = new QCheckBox(page_weeklyDays);
        checkBox_saturday->setObjectName(QString::fromUtf8("checkBox_saturday"));

        verticalLayout_weeklyDays->addWidget(checkBox_saturday);

        stackedWidget_date->addWidget(page_weeklyDays);

        verticalLayout_date->addWidget(stackedWidget_date);


        verticalLayout_taskDialog->addWidget(groupBox_date);

        groupBox_time = new QGroupBox(TaskDialog);
        groupBox_time->setObjectName(QString::fromUtf8("groupBox_time"));
        verticalLayout_time = new QVBoxLayout(groupBox_time);
        verticalLayout_time->setObjectName(QString::fromUtf8("verticalLayout_time"));
        comboBox_time = new QComboBox(groupBox_time);
        comboBox_time->addItem(QString());
        comboBox_time->addItem(QString());
        comboBox_time->addItem(QString());
        comboBox_time->setObjectName(QString::fromUtf8("comboBox_time"));

        verticalLayout_time->addWidget(comboBox_time);

        stackedWidget_time = new QStackedWidget(groupBox_time);
        stackedWidget_time->setObjectName(QString::fromUtf8("stackedWidget_time"));
        page_specificTime = new QWidget();
        page_specificTime->setObjectName(QString::fromUtf8("page_specificTime"));
        verticalLayout_specificTime = new QVBoxLayout(page_specificTime);
        verticalLayout_specificTime->setObjectName(QString::fromUtf8("verticalLayout_specificTime"));
        verticalLayout_specificTime->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_specificTime = new QHBoxLayout();
        horizontalLayout_specificTime->setObjectName(QString::fromUtf8("horizontalLayout_specificTime"));
        timeEdit_specifiedTime = new QTimeEdit(page_specificTime);
        timeEdit_specifiedTime->setObjectName(QString::fromUtf8("timeEdit_specifiedTime"));
        timeEdit_specifiedTime->setAlignment(Qt::AlignCenter);

        horizontalLayout_specificTime->addWidget(timeEdit_specifiedTime);

        horizontalSpacer_specificTime = new QSpacerItem(95, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_specificTime->addItem(horizontalSpacer_specificTime);


        verticalLayout_specificTime->addLayout(horizontalLayout_specificTime);

        verticalSpacer_specificTime = new QSpacerItem(20, 23, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_specificTime->addItem(verticalSpacer_specificTime);

        stackedWidget_time->addWidget(page_specificTime);
        page_timer = new QWidget();
        page_timer->setObjectName(QString::fromUtf8("page_timer"));
        verticalLayout_timer = new QVBoxLayout(page_timer);
        verticalLayout_timer->setObjectName(QString::fromUtf8("verticalLayout_timer"));
        verticalLayout_timer->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_timer = new QHBoxLayout();
        horizontalLayout_timer->setObjectName(QString::fromUtf8("horizontalLayout_timer"));
        label_timer1 = new QLabel(page_timer);
        label_timer1->setObjectName(QString::fromUtf8("label_timer1"));

        horizontalLayout_timer->addWidget(label_timer1);

        spinBox_hoursFromNow = new QSpinBox(page_timer);
        spinBox_hoursFromNow->setObjectName(QString::fromUtf8("spinBox_hoursFromNow"));

        horizontalLayout_timer->addWidget(spinBox_hoursFromNow);

        label_timer2 = new QLabel(page_timer);
        label_timer2->setObjectName(QString::fromUtf8("label_timer2"));

        horizontalLayout_timer->addWidget(label_timer2);

        spinBox_minutesFromNow = new QSpinBox(page_timer);
        spinBox_minutesFromNow->setObjectName(QString::fromUtf8("spinBox_minutesFromNow"));
        spinBox_minutesFromNow->setMaximum(59);

        horizontalLayout_timer->addWidget(spinBox_minutesFromNow);

        label_timer3 = new QLabel(page_timer);
        label_timer3->setObjectName(QString::fromUtf8("label_timer3"));

        horizontalLayout_timer->addWidget(label_timer3);

        horizontalSpacer_timer = new QSpacerItem(21, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_timer->addItem(horizontalSpacer_timer);


        verticalLayout_timer->addLayout(horizontalLayout_timer);

        comboBox_startingFrom = new QComboBox(page_timer);
        comboBox_startingFrom->addItem(QString());
        comboBox_startingFrom->addItem(QString());
        comboBox_startingFrom->setObjectName(QString::fromUtf8("comboBox_startingFrom"));

        verticalLayout_timer->addWidget(comboBox_startingFrom);

        verticalSpacer_timer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_timer->addItem(verticalSpacer_timer);

        stackedWidget_time->addWidget(page_timer);
        page_repetitive = new QWidget();
        page_repetitive->setObjectName(QString::fromUtf8("page_repetitive"));
        verticalLayout_repetitive = new QVBoxLayout(page_repetitive);
        verticalLayout_repetitive->setObjectName(QString::fromUtf8("verticalLayout_repetitive"));
        verticalLayout_repetitive->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_repetitive1 = new QHBoxLayout();
        horizontalLayout_repetitive1->setObjectName(QString::fromUtf8("horizontalLayout_repetitive1"));
        label_repetitive1 = new QLabel(page_repetitive);
        label_repetitive1->setObjectName(QString::fromUtf8("label_repetitive1"));

        horizontalLayout_repetitive1->addWidget(label_repetitive1);

        spinBox_runCount = new QSpinBox(page_repetitive);
        spinBox_runCount->setObjectName(QString::fromUtf8("spinBox_runCount"));

        horizontalLayout_repetitive1->addWidget(spinBox_runCount);

        label_repetitive2 = new QLabel(page_repetitive);
        label_repetitive2->setObjectName(QString::fromUtf8("label_repetitive2"));

        horizontalLayout_repetitive1->addWidget(label_repetitive2);

        timeEdit_startingTime = new QTimeEdit(page_repetitive);
        timeEdit_startingTime->setObjectName(QString::fromUtf8("timeEdit_startingTime"));

        horizontalLayout_repetitive1->addWidget(timeEdit_startingTime);

        horizontalSpacer_repetitive1 = new QSpacerItem(37, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_repetitive1->addItem(horizontalSpacer_repetitive1);


        verticalLayout_repetitive->addLayout(horizontalLayout_repetitive1);

        horizontalLayout_repetitive2 = new QHBoxLayout();
        horizontalLayout_repetitive2->setObjectName(QString::fromUtf8("horizontalLayout_repetitive2"));
        label_repetitive3 = new QLabel(page_repetitive);
        label_repetitive3->setObjectName(QString::fromUtf8("label_repetitive3"));

        horizontalLayout_repetitive2->addWidget(label_repetitive3);

        spinBox_intervalHours = new QSpinBox(page_repetitive);
        spinBox_intervalHours->setObjectName(QString::fromUtf8("spinBox_intervalHours"));

        horizontalLayout_repetitive2->addWidget(spinBox_intervalHours);

        label_repetitive4 = new QLabel(page_repetitive);
        label_repetitive4->setObjectName(QString::fromUtf8("label_repetitive4"));

        horizontalLayout_repetitive2->addWidget(label_repetitive4);

        spinBox_intervalMinutes = new QSpinBox(page_repetitive);
        spinBox_intervalMinutes->setObjectName(QString::fromUtf8("spinBox_intervalMinutes"));
        spinBox_intervalMinutes->setMaximum(59);

        horizontalLayout_repetitive2->addWidget(spinBox_intervalMinutes);

        label_repetitive5 = new QLabel(page_repetitive);
        label_repetitive5->setObjectName(QString::fromUtf8("label_repetitive5"));

        horizontalLayout_repetitive2->addWidget(label_repetitive5);

        horizontalSpacer_repetitive2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_repetitive2->addItem(horizontalSpacer_repetitive2);


        verticalLayout_repetitive->addLayout(horizontalLayout_repetitive2);

        stackedWidget_time->addWidget(page_repetitive);

        verticalLayout_time->addWidget(stackedWidget_time);


        verticalLayout_taskDialog->addWidget(groupBox_time);

        buttonBox = new QDialogButtonBox(TaskDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Help|QDialogButtonBox::Ok);

        verticalLayout_taskDialog->addWidget(buttonBox);


        retranslateUi(TaskDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), TaskDialog, SLOT(reject()));

        stackedWidget_task->setCurrentIndex(0);
        stackedWidget_date->setCurrentIndex(0);
        stackedWidget_time->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TaskDialog);
    } // setupUi

    void retranslateUi(QDialog *TaskDialog)
    {
        TaskDialog->setWindowTitle(QApplication::translate("TaskDialog", "Task Dialog", nullptr));
        groupBox_task->setTitle(QApplication::translate("TaskDialog", "Task", nullptr));
        label_name->setText(QApplication::translate("TaskDialog", "Name:", nullptr));
        label_action->setText(QApplication::translate("TaskDialog", "Action:", nullptr));
        comboBox_action->setItemText(0, QApplication::translate("TaskDialog", "Remind me", nullptr));
        comboBox_action->setItemText(1, QApplication::translate("TaskDialog", "Visit a website", nullptr));
        comboBox_action->setItemText(2, QApplication::translate("TaskDialog", "Open a file", nullptr));
        comboBox_action->setItemText(3, QApplication::translate("TaskDialog", "Run a program", nullptr));
        comboBox_action->setItemText(4, QApplication::translate("TaskDialog", "Log me off", nullptr));
        comboBox_action->setItemText(5, QApplication::translate("TaskDialog", "Shut down the computer", nullptr));
        comboBox_action->setItemText(6, QApplication::translate("TaskDialog", "Restart the computer", nullptr));

        label_remindMe->setText(QApplication::translate("TaskDialog", "Message:", nullptr));
        label_visitAWebsite->setText(QApplication::translate("TaskDialog", "Website:", nullptr));
        label_openAFile->setText(QApplication::translate("TaskDialog", "File:", nullptr));
        toolButton_openAFile->setText(QApplication::translate("TaskDialog", "...", nullptr));
        label_programToRun->setText(QApplication::translate("TaskDialog", "Program:", nullptr));
        toolButton_runAProgram->setText(QApplication::translate("TaskDialog", "...", nullptr));
        label_arguments->setText(QApplication::translate("TaskDialog", "Arguments (optional):", nullptr));
        label_message_task->setText(QApplication::translate("TaskDialog", "No additional information required.", nullptr));
        groupBox_date->setTitle(QApplication::translate("TaskDialog", "Date", nullptr));
        comboBox_date->setItemText(0, QApplication::translate("TaskDialog", "Specific", nullptr));
        comboBox_date->setItemText(1, QApplication::translate("TaskDialog", "Today", nullptr));
        comboBox_date->setItemText(2, QApplication::translate("TaskDialog", "Tomorrow", nullptr));
        comboBox_date->setItemText(3, QApplication::translate("TaskDialog", "Monthly", nullptr));
        comboBox_date->setItemText(4, QApplication::translate("TaskDialog", "Weekly", nullptr));
        comboBox_date->setItemText(5, QApplication::translate("TaskDialog", "Daily", nullptr));

        label_message_date->setText(QApplication::translate("TaskDialog", "<message>", nullptr));
        checkBox_1->setText(QApplication::translate("TaskDialog", "1", nullptr));
        checkBox_2->setText(QApplication::translate("TaskDialog", "2", nullptr));
        checkBox_3->setText(QApplication::translate("TaskDialog", "3", nullptr));
        checkBox_4->setText(QApplication::translate("TaskDialog", "4", nullptr));
        checkBox_5->setText(QApplication::translate("TaskDialog", "5", nullptr));
        checkBox_6->setText(QApplication::translate("TaskDialog", "6", nullptr));
        checkBox_7->setText(QApplication::translate("TaskDialog", "7", nullptr));
        checkBox_8->setText(QApplication::translate("TaskDialog", "8", nullptr));
        checkBox_9->setText(QApplication::translate("TaskDialog", "9", nullptr));
        checkBox_10->setText(QApplication::translate("TaskDialog", "10", nullptr));
        checkBox_11->setText(QApplication::translate("TaskDialog", "11", nullptr));
        checkBox_12->setText(QApplication::translate("TaskDialog", "12", nullptr));
        checkBox_13->setText(QApplication::translate("TaskDialog", "13", nullptr));
        checkBox_14->setText(QApplication::translate("TaskDialog", "14", nullptr));
        checkBox_15->setText(QApplication::translate("TaskDialog", "15", nullptr));
        checkBox_16->setText(QApplication::translate("TaskDialog", "16", nullptr));
        checkBox_17->setText(QApplication::translate("TaskDialog", "17", nullptr));
        checkBox_18->setText(QApplication::translate("TaskDialog", "18", nullptr));
        checkBox_19->setText(QApplication::translate("TaskDialog", "19", nullptr));
        checkBox_20->setText(QApplication::translate("TaskDialog", "20", nullptr));
        checkBox_21->setText(QApplication::translate("TaskDialog", "21", nullptr));
        checkBox_22->setText(QApplication::translate("TaskDialog", "22", nullptr));
        checkBox_23->setText(QApplication::translate("TaskDialog", "23", nullptr));
        checkBox_24->setText(QApplication::translate("TaskDialog", "24", nullptr));
        checkBox_25->setText(QApplication::translate("TaskDialog", "25", nullptr));
        checkBox_26->setText(QApplication::translate("TaskDialog", "26", nullptr));
        checkBox_27->setText(QApplication::translate("TaskDialog", "27", nullptr));
        checkBox_28->setText(QApplication::translate("TaskDialog", "28", nullptr));
        checkBox_29->setText(QApplication::translate("TaskDialog", "29", nullptr));
        checkBox_30->setText(QApplication::translate("TaskDialog", "30", nullptr));
        checkBox_31->setText(QApplication::translate("TaskDialog", "31", nullptr));
        checkBox_sunday->setText(QApplication::translate("TaskDialog", "Sunday", nullptr));
        checkBox_monday->setText(QApplication::translate("TaskDialog", "Monday", nullptr));
        checkBox_tuesday->setText(QApplication::translate("TaskDialog", "Tuesday", nullptr));
        checkBox_wednesday->setText(QApplication::translate("TaskDialog", "Wednesday", nullptr));
        checkBox_thursday->setText(QApplication::translate("TaskDialog", "Thursday", nullptr));
        checkBox_friday->setText(QApplication::translate("TaskDialog", "Friday", nullptr));
        checkBox_saturday->setText(QApplication::translate("TaskDialog", "Saturday", nullptr));
        groupBox_time->setTitle(QApplication::translate("TaskDialog", "Time", nullptr));
        comboBox_time->setItemText(0, QApplication::translate("TaskDialog", "Specific", nullptr));
        comboBox_time->setItemText(1, QApplication::translate("TaskDialog", "Timer", nullptr));
        comboBox_time->setItemText(2, QApplication::translate("TaskDialog", "Repetitive", nullptr));

        timeEdit_specifiedTime->setDisplayFormat(QApplication::translate("TaskDialog", "HH:mm:ss", nullptr));
        label_timer1->setText(QApplication::translate("TaskDialog", "In", nullptr));
        label_timer2->setText(QApplication::translate("TaskDialog", "hours and", nullptr));
        label_timer3->setText(QApplication::translate("TaskDialog", "minutes from now", nullptr));
        comboBox_startingFrom->setItemText(0, QApplication::translate("TaskDialog", "Starting from when the task was added", nullptr));
        comboBox_startingFrom->setItemText(1, QApplication::translate("TaskDialog", "Starting from now", nullptr));

        label_repetitive1->setText(QApplication::translate("TaskDialog", "Run", nullptr));
        label_repetitive2->setText(QApplication::translate("TaskDialog", "times starting at", nullptr));
        label_repetitive3->setText(QApplication::translate("TaskDialog", "Every", nullptr));
        label_repetitive4->setText(QApplication::translate("TaskDialog", "hours and", nullptr));
        label_repetitive5->setText(QApplication::translate("TaskDialog", "minutes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskDialog: public Ui_TaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKDIALOG_H
