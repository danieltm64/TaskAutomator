#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QFile>
#include "configurationmanager.h"
#include "task.h"

namespace Ui {
class TaskDialog;
}

class TaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDialog(QWidget *parent = 0, QVector<Task *> *tasksPointer = 0);
    ~TaskDialog();
    void retranslateUi();
    void add(QObject *parent);
    void edit();
    bool wasAccepted() const;
    Task *retrieveTask() const;
    void setTask(Task *t);

private slots:
    void browseFile();
    void on_comboBox_action_currentIndexChanged(int index);
    void on_comboBox_date_currentIndexChanged(int index);
    void on_comboBox_time_currentIndexChanged(int index);
    void on_buttonBox_accepted();
    void on_buttonBox_helpRequested();

private:
    Ui::TaskDialog *ui;
    QString dateMessage_today;
    QString dateMessage_tomorrow;
    QString dateMessage_daily;
    QString dateMessage_irrelevant;
    QString automaticComboBoxItem;
    int lastDate;
    ConfigurationManager *configManager;
    Task *task;
    QVector<Task *> *tasks;
    bool isEditing;
    bool m_wasAccepted;
    QString initialName;
    bool isTaskNameTaken(const QString &taskName) const;
};

#endif // TASKDIALOG_H
