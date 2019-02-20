/********************************************************************************
** Form generated from reading UI file 'configurationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATIONDIALOG_H
#define UI_CONFIGURATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfigurationDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_defaultSettings;
    QLabel *label_language;
    QComboBox *comboBox_language;
    QLabel *label_style;
    QComboBox *comboBox_style;
    QCheckBox *checkBox_displayToolbar;
    QCheckBox *checkBox_alternateBackgroundColor;
    QCheckBox *checkBox_confirmToRemoveTasks;
    QCheckBox *checkBox_confirmToExitProgram;
    QCheckBox *checkBox_minimizeToSystemTray;
    QCheckBox *checkBox_closeToSystemTray;
    QCheckBox *checkBox_startAutomatically;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfigurationDialog)
    {
        if (ConfigurationDialog->objectName().isEmpty())
            ConfigurationDialog->setObjectName(QString::fromUtf8("ConfigurationDialog"));
        ConfigurationDialog->resize(227, 310);
        horizontalLayout = new QHBoxLayout(ConfigurationDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_defaultSettings = new QVBoxLayout();
        verticalLayout_defaultSettings->setObjectName(QString::fromUtf8("verticalLayout_defaultSettings"));
        label_language = new QLabel(ConfigurationDialog);
        label_language->setObjectName(QString::fromUtf8("label_language"));

        verticalLayout_defaultSettings->addWidget(label_language);

        comboBox_language = new QComboBox(ConfigurationDialog);
        comboBox_language->addItem(QString());
        comboBox_language->addItem(QString());
        comboBox_language->setObjectName(QString::fromUtf8("comboBox_language"));

        verticalLayout_defaultSettings->addWidget(comboBox_language);

        label_style = new QLabel(ConfigurationDialog);
        label_style->setObjectName(QString::fromUtf8("label_style"));

        verticalLayout_defaultSettings->addWidget(label_style);

        comboBox_style = new QComboBox(ConfigurationDialog);
        comboBox_style->addItem(QString());
        comboBox_style->addItem(QString());
        comboBox_style->addItem(QString());
        comboBox_style->addItem(QString());
        comboBox_style->addItem(QString());
        comboBox_style->addItem(QString());
        comboBox_style->setObjectName(QString::fromUtf8("comboBox_style"));

        verticalLayout_defaultSettings->addWidget(comboBox_style);

        checkBox_displayToolbar = new QCheckBox(ConfigurationDialog);
        checkBox_displayToolbar->setObjectName(QString::fromUtf8("checkBox_displayToolbar"));
        checkBox_displayToolbar->setChecked(true);

        verticalLayout_defaultSettings->addWidget(checkBox_displayToolbar);

        checkBox_alternateBackgroundColor = new QCheckBox(ConfigurationDialog);
        checkBox_alternateBackgroundColor->setObjectName(QString::fromUtf8("checkBox_alternateBackgroundColor"));
        checkBox_alternateBackgroundColor->setChecked(true);

        verticalLayout_defaultSettings->addWidget(checkBox_alternateBackgroundColor);

        checkBox_confirmToRemoveTasks = new QCheckBox(ConfigurationDialog);
        checkBox_confirmToRemoveTasks->setObjectName(QString::fromUtf8("checkBox_confirmToRemoveTasks"));
        checkBox_confirmToRemoveTasks->setChecked(true);

        verticalLayout_defaultSettings->addWidget(checkBox_confirmToRemoveTasks);

        checkBox_confirmToExitProgram = new QCheckBox(ConfigurationDialog);
        checkBox_confirmToExitProgram->setObjectName(QString::fromUtf8("checkBox_confirmToExitProgram"));
        checkBox_confirmToExitProgram->setChecked(true);

        verticalLayout_defaultSettings->addWidget(checkBox_confirmToExitProgram);

        checkBox_minimizeToSystemTray = new QCheckBox(ConfigurationDialog);
        checkBox_minimizeToSystemTray->setObjectName(QString::fromUtf8("checkBox_minimizeToSystemTray"));
        checkBox_minimizeToSystemTray->setChecked(true);

        verticalLayout_defaultSettings->addWidget(checkBox_minimizeToSystemTray);

        checkBox_closeToSystemTray = new QCheckBox(ConfigurationDialog);
        checkBox_closeToSystemTray->setObjectName(QString::fromUtf8("checkBox_closeToSystemTray"));

        verticalLayout_defaultSettings->addWidget(checkBox_closeToSystemTray);

        checkBox_startAutomatically = new QCheckBox(ConfigurationDialog);
        checkBox_startAutomatically->setObjectName(QString::fromUtf8("checkBox_startAutomatically"));

        verticalLayout_defaultSettings->addWidget(checkBox_startAutomatically);

        buttonBox = new QDialogButtonBox(ConfigurationDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_defaultSettings->addWidget(buttonBox);


        horizontalLayout->addLayout(verticalLayout_defaultSettings);


        retranslateUi(ConfigurationDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigurationDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigurationDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigurationDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigurationDialog)
    {
        ConfigurationDialog->setWindowTitle(QApplication::translate("ConfigurationDialog", "Configuration", nullptr));
        label_language->setText(QApplication::translate("ConfigurationDialog", "Language:", nullptr));
        comboBox_language->setItemText(0, QApplication::translate("ConfigurationDialog", "English (US)", nullptr));
        comboBox_language->setItemText(1, QApplication::translate("ConfigurationDialog", "Portugu\303\252s (Brasil)", nullptr));

        label_style->setText(QApplication::translate("ConfigurationDialog", "Style:", nullptr));
        comboBox_style->setItemText(0, QApplication::translate("ConfigurationDialog", "Standard", nullptr));
        comboBox_style->setItemText(1, QApplication::translate("ConfigurationDialog", "Fusion", nullptr));
        comboBox_style->setItemText(2, QApplication::translate("ConfigurationDialog", "Fusion (dark with green)", nullptr));
        comboBox_style->setItemText(3, QApplication::translate("ConfigurationDialog", "Fusion (dark with yellow)", nullptr));
        comboBox_style->setItemText(4, QApplication::translate("ConfigurationDialog", "Fusion (dark with blue)", nullptr));
        comboBox_style->setItemText(5, QApplication::translate("ConfigurationDialog", "Fusion (dark with orange)", nullptr));

        checkBox_displayToolbar->setText(QApplication::translate("ConfigurationDialog", "Display toolbar (Alt to toggle)", nullptr));
        checkBox_alternateBackgroundColor->setText(QApplication::translate("ConfigurationDialog", "Alternate background color of task list", nullptr));
        checkBox_confirmToRemoveTasks->setText(QApplication::translate("ConfigurationDialog", "Confirm to remove tasks", nullptr));
        checkBox_confirmToExitProgram->setText(QApplication::translate("ConfigurationDialog", "Confirm to exit the program", nullptr));
        checkBox_minimizeToSystemTray->setText(QApplication::translate("ConfigurationDialog", "Minimize to system tray", nullptr));
        checkBox_closeToSystemTray->setText(QApplication::translate("ConfigurationDialog", "Close to system tray", nullptr));
        checkBox_startAutomatically->setText(QApplication::translate("ConfigurationDialog", "Start automatically when I log in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigurationDialog: public Ui_ConfigurationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATIONDIALOG_H
