/********************************************************************************
** Form generated from reading UI file 'reminddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMINDDIALOG_H
#define UI_REMINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RemindDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *RemindDialog)
    {
        if (RemindDialog->objectName().isEmpty())
            RemindDialog->setObjectName(QString::fromUtf8("RemindDialog"));
        RemindDialog->resize(374, 163);
        verticalLayout = new QVBoxLayout(RemindDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(RemindDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setTextFormat(Qt::RichText);

        verticalLayout->addWidget(label);

        plainTextEdit = new QPlainTextEdit(RemindDialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(plainTextEdit);

        buttonBox = new QDialogButtonBox(RemindDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(RemindDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), RemindDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RemindDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(RemindDialog);
    } // setupUi

    void retranslateUi(QDialog *RemindDialog)
    {
        RemindDialog->setWindowTitle(QApplication::translate("RemindDialog", "Task Automator", nullptr));
        label->setText(QApplication::translate("RemindDialog", "Task Automator was configured to remind you with the following message.\n"
"<br />\n"
"<br />", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RemindDialog: public Ui_RemindDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMINDDIALOG_H
