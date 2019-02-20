#include "taskdialog.h"
#include "ui_taskdialog.h"

TaskDialog::TaskDialog(QWidget *parent, QVector<Task *> *tasksPointer) :
    QDialog(parent),
    ui(new Ui::TaskDialog)
{
    ui->setupUi(this);
    // set up the window so the user can't resize it and so that it adapts to the layout in case it gets resized programmatically
    window()->layout()->setSizeConstraint(QLayout::SetFixedSize);
    // enable the user to browse for files by clicking the tool buttons
    connect(ui->toolButton_openAFile, SIGNAL(clicked()), this, SLOT(browseFile()));
    connect(ui->toolButton_runAProgram, SIGNAL(clicked()), this, SLOT(browseFile()));
    // getting a pointer to the configuration manager
    configManager = ConfigurationManager::instance();
    // getting a pointer to the QVector<Task *> from the main window
    tasks = tasksPointer;
}

TaskDialog::~TaskDialog()
{
    delete ui;
}

void TaskDialog::retranslateUi()
{
    ui->groupBox_task->setTitle(tr("Task", "retranslateUi"));
    ui->label_name->setText(tr("Name:", "retranslateUi"));
    ui->label_action->setText(tr("Action:", "retranslateUi"));
    ui->comboBox_action->setItemText(0, tr("Remind me", "retranslateUi"));
    ui->comboBox_action->setItemText(1, tr("Visit a website", "retranslateUi"));
    ui->comboBox_action->setItemText(2, tr("Open a file", "retranslateUi"));
    ui->comboBox_action->setItemText(3, tr("Run a program", "retranslateUi"));
    ui->comboBox_action->setItemText(4, tr("Log me off", "retranslateUi"));
    ui->comboBox_action->setItemText(5, tr("Shut down the computer", "retranslateUi"));
    ui->comboBox_action->setItemText(6, tr("Restart the computer", "retranslateUi"));
    ui->label_remindMe->setText(tr("Message:", "retranslateUi"));
    ui->label_visitAWebsite->setText(tr("Website:", "retranslateUi"));
    ui->label_openAFile->setText(tr("File:", "retranslateUi"));
    ui->label_programToRun->setText(tr("Program:", "retranslateUi"));
    ui->label_arguments->setText(tr("Arguments (optional):", "retranslateUi"));
    ui->label_message_task->setText(tr("No additional information required.", "retranslateUi"));
    ui->groupBox_date->setTitle(tr("Date", "retranslateUi"));
    ui->comboBox_date->setItemText(0, tr("Specific", "retranslateUi"));
    ui->comboBox_date->setItemText(1, tr("Today", "retranslateUi"));
    ui->comboBox_date->setItemText(2, tr("Tomorrow", "retranslateUi"));
    ui->comboBox_date->setItemText(3, tr("Monthly", "retranslateUi"));
    ui->comboBox_date->setItemText(4, tr("Weekly", "retranslateUi"));
    ui->comboBox_date->setItemText(5, tr("Daily", "retranslateUi"));
    dateMessage_today = tr("The task will be performed the day it is added.", "retranslateUi");
    dateMessage_tomorrow = tr("The task will be performed the day after the day it is added.", "retranslateUi");
    dateMessage_daily = tr("The task will be performed every day.", "retranslateUi");
    dateMessage_irrelevant = tr("The date is irrelevant for the selected time option.", "retranslateUi");
    ui->checkBox_sunday->setText(tr("Sunday", "retranslateUi"));
    ui->checkBox_monday->setText(tr("Monday", "retranslateUi"));
    ui->checkBox_tuesday->setText(tr("Tuesday", "retranslateUi"));
    ui->checkBox_wednesday->setText(tr("Wednesday", "retranslateUi"));
    ui->checkBox_thursday->setText(tr("Thursday", "retranslateUi"));
    ui->checkBox_friday->setText(tr("Friday", "retranslateUi"));
    ui->checkBox_saturday->setText(tr("Saturday", "retranslateUi"));
    ui->groupBox_time->setTitle(tr("Time", "retranslateUi"));
    ui->comboBox_time->setItemText(0, tr("Specific", "retranslateUi"));
    ui->comboBox_time->setItemText(1, tr("Timer", "retranslateUi"));
    ui->comboBox_time->setItemText(2, tr("Repetitive", "retranslateUi"));
    ui->label_timer1->setText(tr("In", "retranslateUi"));
    ui->label_timer2->setText(tr("hours and", "retranslateUi"));
    ui->label_timer3->setText(tr("minutes from now", "retranslateUi"));
    ui->label_repetitive1->setText(tr("Run", "retranslateUi"));
    ui->label_repetitive2->setText(tr("times starting at", "retranslateUi"));
    ui->label_repetitive3->setText(tr("Every", "retranslateUi"));
    ui->label_repetitive4->setText(tr("hours and", "retranslateUi"));
    ui->label_repetitive5->setText(tr("minutes", "retranslateUi"));
    automaticComboBoxItem = tr("Automatic", "retranslateUi");
    ui->calendarWidget_specifiedDate->setLocale(QLocale());
}

void TaskDialog::add(QObject *parent)
{
    isEditing = false;
    m_wasAccepted = false;
    task = new Task(parent);
    setWindowTitle(tr("Add Task"));
    ui->lineEdit_name->setFocus();

    // setting up the task dialog with default values

    // Task
    ui->lineEdit_name->clear();
    ui->comboBox_action->setCurrentIndex(0);
    ui->plainTextEdit_messageToRemindWith->clear();
    ui->lineEdit_websiteToVisit->clear();
    ui->lineEdit_fileToOpen->clear();
    ui->lineEdit_programToRun->clear();
    ui->lineEdit_arguments->clear();

    // Date
    ui->comboBox_date->setCurrentIndex(0);
    lastDate = ui->comboBox_date->currentIndex();
    ui->calendarWidget_specifiedDate->setSelectedDate(QDate::currentDate());
    switch (ui->comboBox_date->currentIndex())
    {
    case 0:
        ui->stackedWidget_date->setCurrentIndex(0);
        break;
    case 1:
        ui->label_message_date->setText(dateMessage_today);
        ui->stackedWidget_date->setCurrentIndex(1);
        break;
    case 2:
        ui->label_message_date->setText(dateMessage_tomorrow);
        ui->stackedWidget_date->setCurrentIndex(1);
        break;
    case 3:
        ui->stackedWidget_date->setCurrentIndex(2);
        break;
    case 4:
        ui->stackedWidget_date->setCurrentIndex(3);
        break;
    case 5:
        break;
        ui->label_message_date->setText(dateMessage_daily);
        ui->stackedWidget_date->setCurrentIndex(1);
        break;
    }
    ui->checkBox_1->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_8->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_10->setChecked(false);
    ui->checkBox_11->setChecked(false);
    ui->checkBox_12->setChecked(false);
    ui->checkBox_13->setChecked(false);
    ui->checkBox_14->setChecked(false);
    ui->checkBox_15->setChecked(false);
    ui->checkBox_16->setChecked(false);
    ui->checkBox_17->setChecked(false);
    ui->checkBox_18->setChecked(false);
    ui->checkBox_19->setChecked(false);
    ui->checkBox_20->setChecked(false);
    ui->checkBox_21->setChecked(false);
    ui->checkBox_22->setChecked(false);
    ui->checkBox_23->setChecked(false);
    ui->checkBox_24->setChecked(false);
    ui->checkBox_25->setChecked(false);
    ui->checkBox_26->setChecked(false);
    ui->checkBox_27->setChecked(false);
    ui->checkBox_28->setChecked(false);
    ui->checkBox_29->setChecked(false);
    ui->checkBox_30->setChecked(false);
    ui->checkBox_31->setChecked(false);
    ui->checkBox_sunday->setChecked(false);
    ui->checkBox_monday->setChecked(false);
    ui->checkBox_tuesday->setChecked(false);
    ui->checkBox_wednesday->setChecked(false);
    ui->checkBox_thursday->setChecked(false);
    ui->checkBox_friday->setChecked(false);
    ui->checkBox_saturday->setChecked(false);

    // Time
    ui->comboBox_time->setCurrentIndex(0);
    ui->timeEdit_specifiedTime->setTime(QTime::currentTime());
    ui->spinBox_hoursFromNow->setValue(0);
    ui->spinBox_minutesFromNow->setValue(0);
    ui->comboBox_startingFrom->setVisible(false);
    ui->spinBox_runCount->setValue(0);
    ui->timeEdit_startingTime->setTime(QTime::currentTime());
    ui->spinBox_intervalHours->setValue(0);
    ui->spinBox_intervalMinutes->setValue(0);
    ui->stackedWidget_time->setCurrentIndex(ui->comboBox_time->currentIndex());

    // setting up the button box
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(tr("Add"));

    // ready to present the 'Add Task' dialog to the user
    exec();
}

void TaskDialog::edit()
{
    isEditing = true;
    m_wasAccepted = false;
    initialName = task->name();
    setWindowTitle(tr("Edit Task"));
    ui->lineEdit_name->setFocus();

    // reading the task's specific details

    // Task
    ui->lineEdit_name->setText(task->name());
    ui->comboBox_action->setCurrentIndex((int)(task->taskAction()));
    ui->plainTextEdit_messageToRemindWith->clear();
    ui->lineEdit_websiteToVisit->clear();
    ui->lineEdit_fileToOpen->clear();
    ui->lineEdit_programToRun->clear();
    ui->lineEdit_arguments->clear();
    switch ((action)(ui->comboBox_action->currentIndex()))
    {
    case remindTheUser:
        ui->plainTextEdit_messageToRemindWith->setPlainText(task->message());
        break;
    case visitAWebsite:
        ui->lineEdit_websiteToVisit->setText(task->website());
        break;
    case openAFile:
        ui->lineEdit_fileToOpen->setText(task->file());
        break;
    case runAProgram:
        ui->lineEdit_programToRun->setText(task->program());
        ui->lineEdit_arguments->setText(task->arguments());
        break;
    }

    // Date
    ui->comboBox_date->setCurrentIndex((int)(task->taskDate()));
    ui->calendarWidget_specifiedDate->setSelectedDate(QDate::currentDate());
    ui->checkBox_1->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_8->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->checkBox_10->setChecked(false);
    ui->checkBox_11->setChecked(false);
    ui->checkBox_12->setChecked(false);
    ui->checkBox_13->setChecked(false);
    ui->checkBox_14->setChecked(false);
    ui->checkBox_15->setChecked(false);
    ui->checkBox_16->setChecked(false);
    ui->checkBox_17->setChecked(false);
    ui->checkBox_18->setChecked(false);
    ui->checkBox_19->setChecked(false);
    ui->checkBox_20->setChecked(false);
    ui->checkBox_21->setChecked(false);
    ui->checkBox_22->setChecked(false);
    ui->checkBox_23->setChecked(false);
    ui->checkBox_24->setChecked(false);
    ui->checkBox_25->setChecked(false);
    ui->checkBox_26->setChecked(false);
    ui->checkBox_27->setChecked(false);
    ui->checkBox_28->setChecked(false);
    ui->checkBox_29->setChecked(false);
    ui->checkBox_30->setChecked(false);
    ui->checkBox_31->setChecked(false);
    ui->checkBox_sunday->setChecked(false);
    ui->checkBox_monday->setChecked(false);
    ui->checkBox_tuesday->setChecked(false);
    ui->checkBox_wednesday->setChecked(false);
    ui->checkBox_thursday->setChecked(false);
    ui->checkBox_friday->setChecked(false);
    ui->checkBox_saturday->setChecked(false);
    lastDate = (task->taskTime() == timer ? 0 : ui->comboBox_date->currentIndex());
    QVector<bool> d;
    switch ((dateKind)(ui->comboBox_date->currentIndex()))
    {
    case specificDate:
        ui->calendarWidget_specifiedDate->setSelectedDate(task->specifiedDate());
        ui->stackedWidget_date->setCurrentIndex(0);
        break;
    case today:
        ui->label_message_date->setText(dateMessage_today);
        ui->stackedWidget_date->setCurrentIndex(1);
        break;
    case tomorrow:
        ui->label_message_date->setText(dateMessage_tomorrow);
        ui->stackedWidget_date->setCurrentIndex(1);
        break;
    case monthly:
        d = task->monthlyDays();
        ui->checkBox_1->setChecked(d[0]);
        ui->checkBox_2->setChecked(d[1]);
        ui->checkBox_3->setChecked(d[2]);
        ui->checkBox_4->setChecked(d[3]);
        ui->checkBox_5->setChecked(d[4]);
        ui->checkBox_6->setChecked(d[5]);
        ui->checkBox_7->setChecked(d[6]);
        ui->checkBox_8->setChecked(d[7]);
        ui->checkBox_9->setChecked(d[8]);
        ui->checkBox_10->setChecked(d[9]);
        ui->checkBox_11->setChecked(d[10]);
        ui->checkBox_12->setChecked(d[11]);
        ui->checkBox_13->setChecked(d[12]);
        ui->checkBox_14->setChecked(d[13]);
        ui->checkBox_15->setChecked(d[14]);
        ui->checkBox_16->setChecked(d[15]);
        ui->checkBox_17->setChecked(d[16]);
        ui->checkBox_18->setChecked(d[17]);
        ui->checkBox_19->setChecked(d[18]);
        ui->checkBox_20->setChecked(d[19]);
        ui->checkBox_21->setChecked(d[20]);
        ui->checkBox_22->setChecked(d[21]);
        ui->checkBox_23->setChecked(d[22]);
        ui->checkBox_24->setChecked(d[23]);
        ui->checkBox_25->setChecked(d[24]);
        ui->checkBox_26->setChecked(d[25]);
        ui->checkBox_27->setChecked(d[26]);
        ui->checkBox_28->setChecked(d[27]);
        ui->checkBox_29->setChecked(d[28]);
        ui->checkBox_30->setChecked(d[29]);
        ui->checkBox_31->setChecked(d[30]);
        ui->stackedWidget_date->setCurrentIndex(2);
        break;
    case weekly:
        d = task->weeklyDays();
        ui->checkBox_sunday->setChecked(d[0]);
        ui->checkBox_monday->setChecked(d[1]);
        ui->checkBox_tuesday->setChecked(d[2]);
        ui->checkBox_wednesday->setChecked(d[3]);
        ui->checkBox_thursday->setChecked(d[4]);
        ui->checkBox_friday->setChecked(d[5]);
        ui->checkBox_saturday->setChecked(d[6]);
        ui->stackedWidget_date->setCurrentIndex(3);
        break;
    case daily:
        break;
        ui->label_message_date->setText(dateMessage_daily);
        ui->stackedWidget_date->setCurrentIndex(1);
        break;
    }

    // Time
    ui->comboBox_time->setCurrentIndex(0);
    ui->comboBox_time->setCurrentIndex((int)(task->taskTime()));
    ui->timeEdit_specifiedTime->setTime(QTime::currentTime());
    ui->spinBox_hoursFromNow->setValue(0);
    ui->spinBox_minutesFromNow->setValue(0);
    if (task->taskTime() == timer)
    {
        ui->comboBox_startingFrom->setCurrentIndex(0);
        ui->comboBox_startingFrom->setVisible(true);
    }
    else
    {
        ui->comboBox_startingFrom->setCurrentIndex(1);
        ui->comboBox_startingFrom->setVisible(false);
    }
    ui->spinBox_runCount->setValue(0);
    ui->timeEdit_startingTime->setTime(QTime::currentTime());
    ui->spinBox_intervalHours->setValue(0);
    ui->spinBox_intervalMinutes->setValue(0);
    switch ((timeKind)(ui->comboBox_time->currentIndex()))
    {
    case specificTime:
        ui->timeEdit_specifiedTime->setTime(task->specifiedTime());
        break;
    case timer:
        ui->spinBox_hoursFromNow->setValue(task->hoursFromNow());
        ui->spinBox_minutesFromNow->setValue(task->minutesFromNow());
        break;
    case repetitive:
        ui->spinBox_runCount->setValue(task->runCount());
        ui->timeEdit_startingTime->setTime(task->startingTime());
        ui->spinBox_intervalHours->setValue(task->intervalHours());
        ui->spinBox_intervalMinutes->setValue(task->intervalMinutes());
        break;
    }

    // setting up the button box
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(tr("Save"));

    // ready to present the 'Edit Task' dialog to the user
    exec();
}

bool TaskDialog::wasAccepted() const
{
    return m_wasAccepted;
}

Task *TaskDialog::retrieveTask() const
{
    return task;
}

void TaskDialog::setTask(Task *t)
{
    task = t;
}

void TaskDialog::browseFile()
{
    QFileDialog fileDialog(this);
    fileDialog.setOption(QFileDialog::DontUseNativeDialog);
    if (ui->comboBox_action->currentIndex() == 2)
    {
        fileDialog.setWindowTitle(tr("Select a file to open"));
        if (ui->lineEdit_fileToOpen->text().isEmpty())
            fileDialog.setDirectory(QDir::root());
        else
            fileDialog.selectFile(ui->lineEdit_fileToOpen->text());
        fileDialog.setNameFilters(QStringList() << tr("All files (*.*)"));
        if (fileDialog.exec() == QDialog::Accepted)
            ui->lineEdit_fileToOpen->setText(QDir::toNativeSeparators(fileDialog.selectedFiles().first()));
    }
    else if (ui->comboBox_action->currentIndex() == 3)
    {
        fileDialog.setWindowTitle(tr("Select a program to run"));
        if (ui->lineEdit_programToRun->text().isEmpty())
            fileDialog.setDirectory(QDir::root());
        else
            fileDialog.selectFile(ui->lineEdit_programToRun->text());
        fileDialog.setNameFilters(QStringList() << tr("Programs (*.exe)") << tr("All files (*.*)"));
        if (fileDialog.exec() == QDialog::Accepted)
            ui->lineEdit_programToRun->setText(QDir::toNativeSeparators(fileDialog.selectedFiles().first()));
    }
}

void TaskDialog::on_comboBox_action_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:
        ui->stackedWidget_task->setCurrentIndex(0);
        break;
    case 1:
        ui->stackedWidget_task->setCurrentIndex(1);
        break;
    case 2:
        ui->stackedWidget_task->setCurrentIndex(2);
        break;
    case 3:
        ui->stackedWidget_task->setCurrentIndex(3);
        break;
    case 4:
    case 5:
    case 6:
        ui->stackedWidget_task->setCurrentIndex(4);
        break;
    }
}

void TaskDialog::on_comboBox_date_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:
        ui->stackedWidget_date->setCurrentIndex(0);
        break;
    case 1:
        ui->label_message_date->setText(dateMessage_today);
        ui->stackedWidget_date->setCurrentIndex(1);
        break;
    case 2:
        ui->label_message_date->setText(dateMessage_tomorrow);
        ui->stackedWidget_date->setCurrentIndex(1);
        break;
    case 3:
        ui->stackedWidget_date->setCurrentIndex(2);
        break;
    case 4:
        ui->stackedWidget_date->setCurrentIndex(3);
        break;
    case 5:
        ui->label_message_date->setText(dateMessage_daily);
        ui->stackedWidget_date->setCurrentIndex(1);
        break;
    }
}

void TaskDialog::on_comboBox_time_currentIndexChanged(int index)
{
    switch (index)
    {
    case 0:
    case 2:
        if (!ui->groupBox_date->isEnabled())
        {
            ui->comboBox_date->setCurrentIndex(-1);
            ui->comboBox_date->removeItem(ui->comboBox_date->count() - 1);
            ui->comboBox_date->setCurrentIndex(lastDate);
            ui->groupBox_date->setEnabled(true);
        }
        break;
    case 1:
        if (ui->groupBox_date->isEnabled())
        {
            ui->groupBox_date->setEnabled(false);
            lastDate = ui->comboBox_date->currentIndex();
            ui->label_message_date->setText(dateMessage_irrelevant);
            ui->stackedWidget_date->setCurrentIndex(1);
            ui->comboBox_date->addItem(automaticComboBoxItem);
            ui->comboBox_date->setCurrentIndex(ui->comboBox_date->count() - 1);
        }
        break;
    }
    ui->stackedWidget_time->setCurrentIndex(index);
}

void TaskDialog::on_buttonBox_accepted()
{
    bool canAccept = true;
    QString errorMessage = "";
    QVector<bool> monthlyDays = QVector<bool>(31);
    monthlyDays[0] = ui->checkBox_1->isChecked();
    monthlyDays[1] = ui->checkBox_2->isChecked();
    monthlyDays[2] = ui->checkBox_3->isChecked();
    monthlyDays[3] = ui->checkBox_4->isChecked();
    monthlyDays[4] = ui->checkBox_5->isChecked();
    monthlyDays[5] = ui->checkBox_6->isChecked();
    monthlyDays[6] = ui->checkBox_7->isChecked();
    monthlyDays[7] = ui->checkBox_8->isChecked();
    monthlyDays[8] = ui->checkBox_9->isChecked();
    monthlyDays[9] = ui->checkBox_10->isChecked();
    monthlyDays[10] = ui->checkBox_11->isChecked();
    monthlyDays[11] = ui->checkBox_12->isChecked();
    monthlyDays[12] = ui->checkBox_13->isChecked();
    monthlyDays[13] = ui->checkBox_14->isChecked();
    monthlyDays[14] = ui->checkBox_15->isChecked();
    monthlyDays[15] = ui->checkBox_16->isChecked();
    monthlyDays[16] = ui->checkBox_17->isChecked();
    monthlyDays[17] = ui->checkBox_18->isChecked();
    monthlyDays[18] = ui->checkBox_19->isChecked();
    monthlyDays[19] = ui->checkBox_20->isChecked();
    monthlyDays[20] = ui->checkBox_21->isChecked();
    monthlyDays[21] = ui->checkBox_22->isChecked();
    monthlyDays[22] = ui->checkBox_23->isChecked();
    monthlyDays[23] = ui->checkBox_24->isChecked();
    monthlyDays[24] = ui->checkBox_25->isChecked();
    monthlyDays[25] = ui->checkBox_26->isChecked();
    monthlyDays[26] = ui->checkBox_27->isChecked();
    monthlyDays[27] = ui->checkBox_28->isChecked();
    monthlyDays[28] = ui->checkBox_29->isChecked();
    monthlyDays[29] = ui->checkBox_30->isChecked();
    monthlyDays[30] = ui->checkBox_31->isChecked();
    QVector<bool> weeklyDays = QVector<bool>(7);
    weeklyDays[0] = ui->checkBox_sunday->isChecked();
    weeklyDays[1] = ui->checkBox_monday->isChecked();
    weeklyDays[2] = ui->checkBox_tuesday->isChecked();
    weeklyDays[3] = ui->checkBox_wednesday->isChecked();
    weeklyDays[4] = ui->checkBox_thursday->isChecked();
    weeklyDays[5] = ui->checkBox_friday->isChecked();
    weeklyDays[6] = ui->checkBox_saturday->isChecked();
    if (ui->lineEdit_name->text().isEmpty())
    {
        canAccept = false;
        errorMessage = tr("You must give the task a name.");
    }
    else if (isTaskNameTaken(ui->lineEdit_name->text()) && (!isEditing || (isEditing && ui->lineEdit_name->text() != initialName)))
    {
        canAccept = false;
        errorMessage = tr("There already is a task with that name.");
    }
    QString advanceTheDateTime = tr("The given date/time is in the past. Please advance the task's date/time.");
    if (ui->comboBox_time->currentIndex() == 0)
    {
        if (ui->comboBox_date->currentIndex() == 0)
        {
            if (QDateTime(ui->calendarWidget_specifiedDate->selectedDate(), ui->timeEdit_specifiedTime->time()) < QDateTime::currentDateTime())
            {
                canAccept = false;
                if (!errorMessage.isEmpty())
                    errorMessage.append('\n');
                errorMessage.append(advanceTheDateTime);
            }
        }
        else if (ui->comboBox_date->currentIndex() == 1)
        {
            if (QDateTime(QDate::currentDate(), ui->timeEdit_specifiedTime->time()) < QDateTime::currentDateTime())
            {
                canAccept = false;
                if (!errorMessage.isEmpty())
                    errorMessage.append('\n');
                errorMessage.append(advanceTheDateTime);
            }
        }
        else if (ui->comboBox_date->currentIndex() == 2)
        {
            if (QDateTime(QDate::currentDate().addDays(1), ui->timeEdit_specifiedTime->time()) < QDateTime::currentDateTime())
            {
                canAccept = false;
                if (!errorMessage.isEmpty())
                    errorMessage.append('\n');
                errorMessage.append(advanceTheDateTime);
            }
        }
        else if (ui->comboBox_date->currentIndex() == 3)
        {
            int i;
            for (i = 0; i < 31; ++i)
                if (monthlyDays[i])
                    break;
            if (i == 31)
            {
                canAccept = false;
                if (!errorMessage.isEmpty())
                    errorMessage.append('\n');
                errorMessage.append(tr("You must specify at least one day of the month."));
            }
        }
        else if (ui->comboBox_date->currentIndex() == 4)
        {
            int i;
            for (i = 0; i < 7; ++i)
                if (weeklyDays[i])
                    break;
            if (i == 7)
            {
                canAccept = false;
                if (!errorMessage.isEmpty())
                    errorMessage.append('\n');
                errorMessage.append(tr("You must specify at least one day of the week."));
            }
        }
    }
    else if (ui->comboBox_time->currentIndex() == 1)
    {
        if (ui->spinBox_hoursFromNow->value() == 0 && ui->spinBox_minutesFromNow->value() == 0)
        {
            canAccept = false;
            if (!errorMessage.isEmpty())
                errorMessage.append('\n');
            errorMessage.append(tr("You must specify how much time from now you want the task to be performed."));
        }
        else if (isEditing && ui->comboBox_startingFrom->currentIndex() == 0 && task->creationDateTime().addSecs(60 * ui->spinBox_minutesFromNow->value() + 3600 * ui->spinBox_hoursFromNow->value()) < QDateTime::currentDateTime())
        {
            canAccept = false;
            if (!errorMessage.isEmpty())
                errorMessage.append('\n');
            errorMessage.append(advanceTheDateTime);
        }
    }
    else if (ui->comboBox_time->currentIndex() == 2)
    {
        if (ui->spinBox_runCount->value() == 0)
        {
            canAccept = false;
            if (!errorMessage.isEmpty())
                errorMessage.append('\n');
            errorMessage.append(tr("You must specify the number of times you want the task to be performed."));
        }
        if (ui->spinBox_runCount->value() > 1 && ui->spinBox_intervalHours->value() == 0 && ui->spinBox_intervalMinutes->value() == 0)
        {
            canAccept = false;
            if (!errorMessage.isEmpty())
                errorMessage.append('\n');
            errorMessage.append(tr("You must specify the length of the task's time interval."));
        }
        if (ui->comboBox_date->currentIndex() == 0)
        {
            if (QDateTime(ui->calendarWidget_specifiedDate->selectedDate(), ui->timeEdit_startingTime->time()) < QDateTime::currentDateTime())
            {
                canAccept = false;
                if (!errorMessage.isEmpty())
                    errorMessage.append('\n');
                errorMessage.append(advanceTheDateTime);
            }
        }
        else if (ui->comboBox_date->currentIndex() == 1)
        {
            if (QDateTime(QDate::currentDate(), ui->timeEdit_startingTime->time()) < QDateTime::currentDateTime())
            {
                canAccept = false;
                if (!errorMessage.isEmpty())
                    errorMessage.append('\n');
                errorMessage.append(advanceTheDateTime);
            }
        }
        else if (ui->comboBox_date->currentIndex() == 2)
        {
            if (QDateTime(QDate::currentDate().addDays(1), ui->timeEdit_startingTime->time()) < QDateTime::currentDateTime())
            {
                canAccept = false;
                if (!errorMessage.isEmpty())
                    errorMessage.append('\n');
                errorMessage.append(advanceTheDateTime);
            }
        }
        else if (ui->comboBox_date->currentIndex() == 3)
        {
            int i;
            for (i = 0; i < 31; ++i)
                if (monthlyDays[i])
                    break;
            if (i == 31)
            {
                canAccept = false;
                if (!errorMessage.isEmpty())
                    errorMessage.append('\n');
                errorMessage.append(tr("You must specify at least one day of the month."));
            }
        }
        else if (ui->comboBox_date->currentIndex() == 4)
        {
            int i;
            for (i = 0; i < 7; ++i)
                if (weeklyDays[i])
                    break;
            if (i == 7)
            {
                canAccept = false;
                if (!errorMessage.isEmpty())
                    errorMessage.append('\n');
                errorMessage.append(tr("You must specify at least one day of the week."));
            }
        }
    }
    if (ui->comboBox_action->currentIndex() == 1 && ui->lineEdit_websiteToVisit->text().isEmpty())
    {
        canAccept = false;
        if (!errorMessage.isEmpty())
            errorMessage.append('\n');
        errorMessage.append(tr("You must specify a website to visit."));
    }
    else if (ui->comboBox_action->currentIndex() == 2 && ui->lineEdit_fileToOpen->text().isEmpty())
    {
        canAccept = false;
        if (!errorMessage.isEmpty())
            errorMessage.append('\n');
        errorMessage.append(tr("You must specify a file to open."));
    }
    else if (ui->comboBox_action->currentIndex() == 3 && ui->lineEdit_programToRun->text().isEmpty())
    {
        canAccept = false;
        if (!errorMessage.isEmpty())
            errorMessage.append('\n');
        errorMessage.append(tr("You must specify a program to run."));
    }
    if (!canAccept)
    {
        QMessageBox messageBoxError(this);
        messageBoxError.setWindowTitle("Task Automator");
        messageBoxError.setText(errorMessage);
        messageBoxError.setStandardButtons(QMessageBox::Ok);
        messageBoxError.exec();
    }
    else
    {
        task->setName(ui->lineEdit_name->text());
        task->setTaskAction((action)(ui->comboBox_action->currentIndex()));
        switch ((action)(ui->comboBox_action->currentIndex()))
        {
        case remindTheUser:
            task->setMessage(ui->plainTextEdit_messageToRemindWith->toPlainText());
            break;
        case visitAWebsite:
            task->setWebsite(ui->lineEdit_websiteToVisit->text());
            break;
        case openAFile:
            task->setFile(ui->lineEdit_fileToOpen->text());
            break;
        case runAProgram:
            task->setProgram(ui->lineEdit_programToRun->text());
            task->setArguments(ui->lineEdit_arguments->text());
            break;
        }
        task->setTaskDate((dateKind)(ui->comboBox_date->currentIndex()));
        switch ((dateKind)(ui->comboBox_date->currentIndex()))
        {
        case specificDate:
            task->setSpecifiedDate(ui->calendarWidget_specifiedDate->selectedDate());
            break;
        case monthly:
            task->setMonthlyDays(monthlyDays);
            break;
        case weekly:
            task->setWeeklyDays(weeklyDays);
            break;
        }
        task->setTaskTime((timeKind)(ui->comboBox_time->currentIndex()));
        switch ((timeKind)(ui->comboBox_time->currentIndex()))
        {
        case specificTime:
            task->setSpecifiedTime(ui->timeEdit_specifiedTime->time());
            break;
        case timer:
            task->setHoursFromNow(ui->spinBox_hoursFromNow->value());
            task->setMinutesFromNow(ui->spinBox_minutesFromNow->value());
            break;
        case repetitive:
            task->setRunCount(ui->spinBox_runCount->value());
            task->setStartingTime(ui->timeEdit_startingTime->time());
            task->setIntervalHours(ui->spinBox_intervalHours->value());
            task->setIntervalMinutes(ui->spinBox_intervalMinutes->value());
            break;
        }
        if (!(isEditing && ui->comboBox_time->currentIndex() == 1 && ui->comboBox_startingFrom->currentIndex() == 0))
        {
            task->setCreationDateTime(QDateTime::currentDateTime());
            task->setLastPerformance(task->creationDateTime());
        }
        task->updateNextOccurrence();
        if (isEditing && initialName != task->name())
        {
            QFile f("tasks/" + Task::encodeNameToSave(initialName) + ".task");
            f.remove();
            f.close();
        }
        task->saveTaskFile();
        m_wasAccepted = true;
        accept();
    }
}

void TaskDialog::on_buttonBox_helpRequested()
{
    QMessageBox messageBoxTask(this);
    messageBoxTask.setWindowTitle(tr("Task Automator Tip 1/3"));
    messageBoxTask.setText(tr("<b>Task</b><br /><br /><i>Name:</i> The name of the task as displayed in the task list.<br /><br /><i>Action:</i> What to do.<br /><br /><i>Message:</i> Visible when the selected action is \"Remind me\".<br />Determines the message to display when the task is performed.<br /><br /><i>Website:</i> Visible when the selected action is \"Visit a website\".<br />Determines the website to visit when the task is performed.<br /><br /><i>File:</i> Visible when the selected action is \"Open a file\".<br />Determines the file to open when the task is performed.<br /><br /><i>Program:</i> Visible when the selected action is \"Run a program\".<br />Determines the program to run when the task is performed.<br /><br /><i>Arguments (optional):</i> Visible when the selected action is \"Run a program\".<br />Determines the arguments to pass to the program that will be run when the task is performed."));
    QPushButton *nextTopicButtonTask = messageBoxTask.addButton(tr("Next Topic"), QMessageBox::AcceptRole);
    messageBoxTask.addButton(QMessageBox::Close);
    messageBoxTask.exec();
    if (messageBoxTask.clickedButton() == nextTopicButtonTask)
    {
        QMessageBox messageBoxDate(this);
        messageBoxDate.setWindowTitle(tr("Task Automator Tip 2/3"));
        messageBoxDate.setText(tr("<b>Date</b><br /><br /><i>Specific:</i> The task will be performed on the specified date.<br /><br /><i>Today:</i> The task will be performed the day it is added.<br /><br /><i>Tomorrow:</i> The task will be performed the day after the day it is added.<br /><br /><i>Monthly:</i> The task will be performed every specified days of the month.<br /><br /><i>Weekly:</i> The task will be performed every specified days of the week.<br /><br /><i>Daily:</i> The task will be performed every day."));
        QPushButton *nextTopicButtonDate = messageBoxDate.addButton(tr("Next Topic"), QMessageBox::AcceptRole);
        messageBoxDate.addButton(QMessageBox::Close);
        messageBoxDate.exec();
        if (messageBoxDate.clickedButton() == nextTopicButtonDate)
        {
            QMessageBox messageBoxTime(this);
            messageBoxTime.setWindowTitle(tr("Task Automator Tip 3/3"));
            messageBoxTime.setText(tr("<b>Time</b><br /><br /><i>Specific:</i> The task will be performed at the specified time.<br /><br /><i>Timer:</i> The task will be performed some time after it is added.<br /><br /><i>Repetitive:</i> The task will be performed at regular intervals."));
            messageBoxTime.addButton(QMessageBox::Close);
            messageBoxTime.exec();
        }
    }
}

bool TaskDialog::isTaskNameTaken(const QString &taskName) const
{
    for (QVector<Task *>::iterator i = tasks->begin(); i != tasks->end(); ++i)
        if ((*i)->name() == taskName)
            return true;
    return false;
}
