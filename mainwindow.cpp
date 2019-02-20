#include "mainwindow.h"
#include "ui_mainwindow.h"

// TODO Maybe remove isEvaluating

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timerID(0)
{
    ui->setupUi(this);
    // setting the central widget to the task list widget
    setCentralWidget(ui->treeWidget_taskList);
    // setting the sort column and sort order
    ui->treeWidget_taskList->sortItems(0, Qt::AscendingOrder);
    // populating the main toolbar with actions
    ui->mainToolBar->setContextMenuPolicy(Qt::PreventContextMenu);
    ui->mainToolBar->addAction(ui->actionAdd);
    ui->mainToolBar->addAction(ui->actionEdit);
    ui->mainToolBar->addAction(ui->actionRemove);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actionSelectAll);
    ui->mainToolBar->addAction(ui->actionSelectNone);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actionConfiguration);
    // populating the help menu with actions before adding it to the main toolbar
    QMenu *helpMenu = new QMenu(this);
    helpMenu->addAction(ui->actionUserManual);
    helpMenu->addAction(ui->actionAbout);
    // setting up the toolbutton that will contain the help menu before adding it to the main toolbar
    helpToolButton = new QToolButton(this);
    helpToolButton->setPopupMode(QToolButton::InstantPopup);
    helpToolButton->setMenu(helpMenu);
    ui->mainToolBar->addWidget(helpToolButton);
    // populating the window's context menu with actions
    setContextMenuPolicy(Qt::ActionsContextMenu);
    addAction(ui->actionAdd);
    addAction(ui->actionEdit);
    addAction(ui->actionRemove);
    QAction *separator1 = new QAction(this);
    separator1->setSeparator(true);
    addAction(separator1);
    addAction(ui->actionSelectAll);
    addAction(ui->actionSelectNone);
    QAction *separator2 = new QAction(this);
    separator2->setSeparator(true);
    addAction(separator2);
    addAction(ui->actionConfiguration);
    helpContextMenuAction = new QAction(this);
    helpContextMenuAction->setMenu(helpMenu);
    addAction(helpContextMenuAction);
    // setting the initial enabled state of the add, edit and remove actions
    on_treeWidget_taskList_itemSelectionChanged();
    // constructing the task dialog
    taskDialog = new TaskDialog(this, &tasks);
    // constructing the about dialog
    aboutDialog = new AboutDialog(this);
    // constructing the configuration dialog
    configDialog = new ConfigurationDialog(this);
    // getting a pointer to the configuration manager
    configManager = ConfigurationManager::instance();
    // setting the style of the application
    currentAppStyle = standardStyle;
    setApplicationStyle(configManager->applicationStyle());
    // setting things up for the main window according to user preferences
    ui->mainToolBar->setVisible(configManager->displayToolbar());
    ui->treeWidget_taskList->setAlternatingRowColors(configManager->alternateBackgroundColor());
    // listening for changes in the configuration manager in order to update the main window according to the new preferences
    connect(configManager, SIGNAL(configurationChanged(QString)), this, SLOT(updateConfigurationChanges(QString)));
    // turning double clicks on the blank area of the task list into a way of adding a new task
    connect(ui->treeWidget_taskList, SIGNAL(doubleClickedOnBlankArea()), ui->actionAdd, SLOT(trigger()));
    // turning double clicks on an existing task in the task list into a way of editing the selected task
    connect(ui->treeWidget_taskList, SIGNAL(doubleClickedOnOneTask()), ui->actionEdit, SLOT(trigger()));
    // populating the context menu of the system tray icon
    QMenu *systemTrayMenu = new QMenu(this);
    systemTrayMenu->addAction(ui->actionAbout);
    systemTrayMenu->addAction(ui->actionRestore);
    systemTrayMenu->addAction(ui->actionExit);
    // setting up the system tray icon
    systemTrayIcon = new QSystemTrayIcon(this);
    systemTrayIcon->setIcon(qApp->windowIcon());
    systemTrayIcon->setContextMenu(systemTrayMenu);
    connect(systemTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(restoreFromSystemTray(QSystemTrayIcon::ActivationReason)));
    systemTrayIcon->show();
    ui->treeWidget_taskList->setVisible(false);
    currentAppLanguage = "";
    setApplicationLanguage(configManager->language());
    bool thereAreExpiredTasks = false;
    QDir dir("tasks");
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setNameFilters(QStringList() << "*.task");
    QFileInfoList files = dir.entryInfoList();
    if (files.size() > 0)
    {
        for (QFileInfoList::const_iterator i = files.constBegin(); i != files.constEnd(); ++i)
        {
            QFileInfo fileInfo = *i;
            Task *task = new Task;
            task->loadTaskFile(fileInfo.fileName());
            task->updateNextOccurrence();
            if (task->isValid())
            {
                QTreeWidgetItem *taskListEntry = new QTreeWidgetItem;
                task->setTaskListEntry(taskListEntry);
                task->updateNextOccurrence();
                taskListEntry->setData(0, Qt::UserRole, QVariant::fromValue<Task *>(task));
                task->setBeingEdited(false);
                ui->treeWidget_taskList->addTopLevelItem(taskListEntry);
                tasks.push_back(task);
                std::push_heap(tasks.begin(), tasks.end(), taskCompare());
            }
            else
            {
                expiredTasksMessage.append('\n' + task->name());
                thereAreExpiredTasks = true;
                task->deleteTaskFile();
            }
        }
        if (tasks.count() > 0)
        {
            timerID = startTimer(900);
            ui->treeWidget_taskList->setSortingEnabled(true);
            ui->treeWidget_taskList->setVisible(true);
        }
    }
    if (thereAreExpiredTasks)
    {
        QMessageBox expiredTasksDialog;
        expiredTasksDialog.setWindowTitle("Task Automator");
        expiredTasksDialog.setStandardButtons(QMessageBox::Ok);
        expiredTasksDialog.setText(expiredTasksMessage);
        expiredTasksDialog.exec();
    }
    messageBoxConfirmation = new QMessageBox(this);
    messageBoxConfirmation->setWindowTitle("Task Automator");
    messageBoxConfirmation->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    switch (ev->key())
    {
    case Qt::Key_Insert:
        ui->actionAdd->trigger();
        break;
    case Qt::Key_Return:
        if (ui->actionEdit->isEnabled())
            ui->actionEdit->trigger();
        break;
    case Qt::Key_Delete:
        if (ui->actionRemove->isEnabled())
            ui->actionRemove->trigger();
        break;
    case Qt::Key_F1:
        helpToolButton->click();
        break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    bool v;
    switch (ev->key())
    {
    case Qt::Key_Alt:
    case Qt::Key_AltGr:
        if (!ev->modifiers().testFlag(Qt::ShiftModifier) && !ev->modifiers().testFlag(Qt::ControlModifier))
        {
            v = !ui->mainToolBar->isVisible();
            ui->mainToolBar->setVisible(v);
            configManager->setDisplayToolbar(v);
            configManager->saveConfiguration();
            configDialog->setDisplayToolbarChecked(v);
        }
        break;
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *)
{
    ui->actionAdd->trigger();
}

void MainWindow::closeEvent(QCloseEvent *ev)
{
    ev->accept();
    if (configManager->closeToSystemTray() && isVisible())
    {
        minimizeToSystemTray();
        ev->ignore();
    }
    else
    {
        messageBoxConfirmation->setDefaultButton(QMessageBox::Yes);
        messageBoxConfirmation->setText(closeConfirmationMessage);
        if (configManager->confirmToExitProgram() && messageBoxConfirmation->exec() == QMessageBox::No)
            ev->ignore();
    }
    if (ev->isAccepted())
        qApp->quit();
}

void MainWindow::changeEvent(QEvent *ev)
{
    QMainWindow::changeEvent(ev);
    if (ev->type() == QEvent::WindowStateChange && configManager->minimizeToSystemTray() && isMinimized())
        minimizeToSystemTray();
}

void MainWindow::timerEvent(QTimerEvent *)
{
    if (tasks.front()->nextOccurrence() <= QDateTime::currentDateTime() && !tasks.front()->isBeingEdited())
    {
        ui->treeWidget_taskList->setSortingEnabled(false);
        tasks.front()->updateNextOccurrence();
        if (!tasks.front()->isValid())
        {
            connect(tasks.front(), SIGNAL(finished()), tasks.front(), SLOT(deleteLater()));
            tasks.front()->performNow();
            for (int i = 0; i < ui->treeWidget_taskList->topLevelItemCount(); ++i)
                if (tasks.front() == ui->treeWidget_taskList->topLevelItem(i)->data(0, Qt::UserRole).value<Task *>())
                {
                    ui->treeWidget_taskList->takeTopLevelItem(i);
                    break;
                }
            tasks.front()->deleteTaskFile();
            tasks.erase(tasks.begin());
            if (tasks.isEmpty())
            {
                killTimer(timerID);
                ui->treeWidget_taskList->setVisible(false);
                return;
            }
        }
        else
            tasks.front()->performNow();
        std::make_heap(tasks.begin(), tasks.end(), taskCompare());
        ui->treeWidget_taskList->setSortingEnabled(true);
    }
}

void MainWindow::paintEvent(QPaintEvent *ev)
{
    QMainWindow::paintEvent(ev);
    QPainter painter(this);
/*
    // originally left out
    QLinearGradient grad = QLinearGradient(0, 0, 0, height());
    //QLinearGradient grad = QLinearGradient(0, 0, width(), height());

    QColor gradColor1 = Qt::white;
    QColor gradColor2 = QColor::fromRgb(220, 220, 220);
    QColor textColor = Qt::black;

    grad.setColorAt(0, gradColor1);
    grad.setColorAt(1, gradColor2);
    QBrush brush(grad);
    brush.setStyle(Qt::LinearGradientPattern);
    painter.setBrush(brush);
    painter.fillRect(0, 0, width(), height(), brush);
    QString msg = tr("The task list is empty.");
    QString msg2 = tr("Click on Add or double click this area to begin.");
    QFontMetrics fm(font());
    painter.setPen(textColor);
    painter.drawText(width() / 2 - fm.width(msg) / 2, height() / 2 - fm.height() / 2, msg);
    painter.drawText(width() / 2 - fm.width(msg2) / 2, height() / 2 + fm.height(), msg2);
    // originally left out
// */
// /*
    QFontMetrics fm(font());
    painter.drawText(width() / 2 - fm.width(welcomeLine1) / 2, height() / 2 - fm.height() / 2, welcomeLine1);
    painter.drawText(width() / 2 - fm.width(welcomeLine2) / 2, height() / 2 + fm.height(), welcomeLine2);
    painter.drawText(width() / 2 - fm.width(welcomeLine3) / 2, height() / 2 + fm.height() * 2.5, welcomeLine3);
// */
}

void MainWindow::retranslateUi()
{
    ui->actionAdd->setText(tr("Add", "retranslateUi"));
    ui->actionEdit->setText(tr("Edit", "retranslateUi"));
    ui->actionRemove->setText(tr("Remove", "retranslateUi"));
    ui->actionSelectAll->setText(tr("Select All", "retranslateUi"));
    ui->actionSelectNone->setText(tr("Select None", "retranslateUi"));
    ui->actionConfiguration->setText(tr("Configuration", "retranslateUi"));
    helpToolButton->setText(tr("Help", "retranslateUi"));
    helpContextMenuAction->setText(tr("Help", "retranslateUi"));
    ui->actionUserManual->setText(tr("User Manual", "retranslateUi"));
    ui->actionAbout->setText(tr("About", "retranslateUi"));
    ui->actionRestore->setText(tr("Restore", "retranslateUi"));
    ui->actionExit->setText(tr("Exit", "retranslateUi"));
    ui->treeWidget_taskList->headerItem()->setText(0, tr("Next Occurence", "retranslateUi"));
    ui->treeWidget_taskList->headerItem()->setText(1, tr("Task", "retranslateUi"));
    expiredTasksMessage = tr("The following tasks have been removed because they\nexpired before they had a chance to be carried out.", "retranslateUi") + '\n';
    welcomeLine1 = tr("The task list is empty.", "retranslateUi");
    welcomeLine2 = tr("Click on Add or press the Insert key to begin.", "retranslateUi");
    welcomeLine3 = tr("For a complete tutorial, open the user manual from the Help menu.", "retranslateUi");
    closeConfirmationMessage = tr("Are you sure you want to close Task Automator?", "retranslateUi");
}

void MainWindow::updateConfigurationChanges(const QString &setting)
{
    // update the main window according to new preferences if necessary
    if (setting == "<group>")
    {
        ui->mainToolBar->setVisible(configManager->displayToolbar());
        ui->treeWidget_taskList->setAlternatingRowColors(configManager->alternateBackgroundColor());
        setApplicationStyle(configManager->applicationStyle());
        setApplicationLanguage(configManager->language());
    }
}

void MainWindow::minimizeToSystemTray()
{
    hide();
}

void MainWindow::restoreFromSystemTray(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::DoubleClick)
        ui->actionRestore->trigger();
}

void MainWindow::setApplicationLanguage(const QString &appLanguage)
{
    if (currentAppLanguage == appLanguage)
        return;
    QLocale locale;
    if (appLanguage == "Português (Brasil)")
    {
        translator.load(":/resources/taskautomator_pt.qm");
        translatorQt.load(":/resources/qt_pt.qm");
        qApp->installTranslator(&translator);
        qApp->installTranslator(&translatorQt);
        locale = QLocale(QLocale::Portuguese, QLocale::Brazil);
    }
    else
    {
        qApp->removeTranslator(&translatorQt);
        qApp->removeTranslator(&translator);
        locale = QLocale(QLocale::English, QLocale::UnitedStates);
    }
    QLocale::setDefault(locale);
    retranslateUi();
    taskDialog->retranslateUi();
    //aboutDialog->retranslateUi();
    //configDialog->retranslateUi();
    currentAppLanguage = appLanguage;
}

void setPaletteColor(QPalette &palette, QPalette::ColorRole colorRole, const QColor &color)
{
    palette.setColor(QPalette::Disabled, colorRole, color);
    palette.setColor(QPalette::Active, colorRole, color);
    palette.setColor(QPalette::Inactive, colorRole, color);
}

void MainWindow::setApplicationStyle(styleName appStyle)
{
    if (currentAppStyle == appStyle)
        return;
    QString color;
    QString styleName;
    switch (appStyle)
    {
    case standardStyle:
        switch (QSysInfo::WindowsVersion)
        {
        case QSysInfo::WV_XP:
            styleName = "windowsxp";
            break;
        case QSysInfo::WV_VISTA:
        case QSysInfo::WV_WINDOWS7:
        case QSysInfo::WV_WINDOWS8:
        case QSysInfo::WV_WINDOWS8_1:
        case QSysInfo::WV_WINDOWS10:
            styleName = "windowsvista";
            break;
        default:
            styleName = "windows";
        }
        qApp->setStyle(QStyleFactory::create(styleName));
        qApp->setPalette(qApp->style()->standardPalette());
        delete taskDialog;
        taskDialog = new TaskDialog(this, &tasks);
        delete aboutDialog;
        aboutDialog = new AboutDialog(this);
        delete configDialog;
        configDialog = new ConfigurationDialog(this);
        currentAppStyle = appStyle;
        return;
    case fusionStyle:
        color = "";
        break;
    case fusionStyleDarkWithGreen:
        color = "lime";
        break;
    case fusionStyleDarkWithYellow:
        color = "yellow";
        break;
    case fusionStyleDarkWithBlue:
        color = "cyan";
        break;
    case fusionStyleDarkWithOrange:
        color = "orange";
        break;
    }
    qApp->setStyle(QStyleFactory::create("fusion"));
    if (color.isEmpty())
    {
        /*
        QPalette palette(qApp->style()->standardPalette());
        qApp->setPalette(palette);
        // */
        color = "black";
        QPalette palette;//(qApp->palette());
        setPaletteColor(palette, QPalette::Window, QColor(255 - 23, 255 - 23, 255 - 23));
        setPaletteColor(palette, QPalette::WindowText, QColor(color));
        setPaletteColor(palette, QPalette::Base, QColor(255 - 23, 255 - 23, 255 - 23));
        setPaletteColor(palette, QPalette::AlternateBase, QColor(255 - 33, 255 - 33, 255 - 33));
        //setPaletteColor(palette, QPalette::ToolTipBase, QColor(128, 128, 128));
        //setPaletteColor(palette, QPalette::ToolTipText, QColor(128, 128, 128));
        setPaletteColor(palette, QPalette::Text, QColor(color));
        setPaletteColor(palette, QPalette::Button, QColor(255 - 23, 255 - 23, 255 - 23));
        setPaletteColor(palette, QPalette::ButtonText, QColor(color));
        //setPaletteColor(palette, QPalette::BrightText, QColor(128, 128, 128));
        setPaletteColor(palette, QPalette::Highlight, QColor("black"));
        setPaletteColor(palette, QPalette::HighlightedText, QColor("white"));
        setPaletteColor(palette, QPalette::Link, QColor("teal"));
        setPaletteColor(palette, QPalette::LinkVisited, QColor("teal"));
        qApp->setPalette(palette);
    }
    else
    {
        QPalette palette;//(qApp->palette());
        setPaletteColor(palette, QPalette::Window, QColor(53, 53, 53));
        setPaletteColor(palette, QPalette::WindowText, QColor(color));
        setPaletteColor(palette, QPalette::Base, QColor(53, 53, 53));
        setPaletteColor(palette, QPalette::AlternateBase, QColor(63, 63, 63));
        //setPaletteColor(palette, QPalette::ToolTipBase, QColor(128, 128, 128));
        //setPaletteColor(palette, QPalette::ToolTipText, QColor(128, 128, 128));
        setPaletteColor(palette, QPalette::Text, QColor(color));
        setPaletteColor(palette, QPalette::Button, QColor(53, 53, 53));
        setPaletteColor(palette, QPalette::ButtonText, QColor(color));
        //setPaletteColor(palette, QPalette::BrightText, QColor(128, 128, 128));
        setPaletteColor(palette, QPalette::Highlight, QColor("black"));
        setPaletteColor(palette, QPalette::HighlightedText, QColor("white"));
        setPaletteColor(palette, QPalette::Link, QColor("teal"));
        setPaletteColor(palette, QPalette::LinkVisited, QColor("teal"));
        qApp->setPalette(palette);
    }
    delete taskDialog;
    taskDialog = new TaskDialog(this, &tasks);
    delete aboutDialog;
    aboutDialog = new AboutDialog(this);
    delete configDialog;
    configDialog = new ConfigurationDialog(this);
    currentAppStyle = appStyle;
}

void MainWindow::on_actionAdd_triggered()
{
    taskDialog->add(this);
    if (taskDialog->wasAccepted())
    {
        ui->treeWidget_taskList->setSortingEnabled(false);
        Task *task = taskDialog->retrieveTask();
        QTreeWidgetItem *taskListEntry = new QTreeWidgetItem;
        task->setTaskListEntry(taskListEntry);
        task->updateNextOccurrence();
        taskListEntry->setData(0, Qt::UserRole, QVariant::fromValue<Task *>(task));
        task->setBeingEdited(false);
        /*
        if (task->isSingleShot())
            connect(task, SIGNAL(finished()), task, SLOT(deleteLater()));
        */
        ui->treeWidget_taskList->addTopLevelItem(taskListEntry);
        tasks.push_back(task);
        std::push_heap(tasks.begin(), tasks.end(), taskCompare());
        ui->treeWidget_taskList->setVisible(true);
        if (ui->treeWidget_taskList->topLevelItemCount() == 1)
            timerID = startTimer(900);
        ui->treeWidget_taskList->setSortingEnabled(true);
    }
}

void MainWindow::on_actionEdit_triggered()
{
    Task *task = ui->treeWidget_taskList->selectedItems().front()->data(0, Qt::UserRole).value<Task *>();
    task->setBeingEdited(true);
    taskDialog->setTask(task);
    taskDialog->edit();
    if (taskDialog->wasAccepted())
    {
        ui->treeWidget_taskList->setSortingEnabled(false);
        task->updateNextOccurrence();
        std::make_heap(tasks.begin(), tasks.end(), taskCompare());
        ui->treeWidget_taskList->setSortingEnabled(true);
    }
    task->setBeingEdited(false);
}

void MainWindow::on_actionRemove_triggered()
{
    QList<QTreeWidgetItem *> selectedItems = ui->treeWidget_taskList->selectedItems();
    messageBoxConfirmation->setDefaultButton(QMessageBox::Yes);
    messageBoxConfirmation->setText(tr("Are you sure you want to remove the selected tasks?", "relevant"));
    if (selectedItems.count() && (!configManager->confirmToRemoveTasks() || (configManager->confirmToRemoveTasks() && messageBoxConfirmation->exec() == QMessageBox::Yes)))
    {
        ui->treeWidget_taskList->setSortingEnabled(false);
        for (QList<QTreeWidgetItem *>::const_iterator i = selectedItems.begin(); i != selectedItems.end(); ++i)
        {
            QTreeWidgetItem *taskListEntry = *i;
            Task *task = taskListEntry->data(0, Qt::UserRole).value<Task *>();
            tasks.remove(tasks.indexOf(task));
            task->deleteTaskFile();
            ui->treeWidget_taskList->takeTopLevelItem(ui->treeWidget_taskList->indexOfTopLevelItem(taskListEntry));
        }
        if (tasks.isEmpty())
        {
            killTimer(timerID);
            ui->treeWidget_taskList->setVisible(false);
        }
        else
            std::make_heap(tasks.begin(), tasks.end(), taskCompare());
        ui->treeWidget_taskList->setSortingEnabled(true);
    }
}

void MainWindow::on_actionSelectAll_triggered()
{
    ui->treeWidget_taskList->selectAll();
}

void MainWindow::on_actionSelectNone_triggered()
{
    ui->treeWidget_taskList->clearSelection();
}

void MainWindow::on_actionConfiguration_triggered()
{
    configDialog->exec();
}

void MainWindow::on_actionUserManual_triggered()
{
    // user manual
    QDesktopServices::openUrl(QUrl::fromLocalFile(tr("Task Automator User Manual - English (US).pdf", "relevant")));
}

void MainWindow::on_actionAbout_triggered()
{
    // about
    aboutDialog->exec();
}

void MainWindow::on_actionRestore_triggered()
{
    setWindowState(windowState() & ~Qt::WindowMinimized | Qt::WindowActive);
    show();
    activateWindow();
}

void MainWindow::on_actionExit_triggered()
{
    messageBoxConfirmation->setDefaultButton(QMessageBox::Yes);
    messageBoxConfirmation->setText(closeConfirmationMessage);
    if (configManager->confirmToExitProgram() && messageBoxConfirmation->exec() == QMessageBox::No)
        return;
    qApp->quit();
}

void MainWindow::on_treeWidget_taskList_itemSelectionChanged()
{
    int selectionCount = ui->treeWidget_taskList->selectedItems().count();
    if (selectionCount == 0)
    {
        // no task is selected, can't edit nor remove
        ui->actionEdit->setEnabled(false);
        ui->actionRemove->setEnabled(false);
    }
    if (selectionCount == 1)
    {
        // one task is selected, can edit and remove
        ui->actionEdit->setEnabled(true);
        ui->actionRemove->setEnabled(true);
    }
    else if (selectionCount > 1)
    {
        // multiple tasks are selected, can't edit multiple tasks but can remove them all
        ui->actionEdit->setEnabled(false);
        ui->actionRemove->setEnabled(true);
    }
}
