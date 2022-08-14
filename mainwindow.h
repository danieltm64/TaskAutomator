#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QStyleFactory>
#include <QPainter>
#include <QKeyEvent>
#include <QDesktopServices>
#include <QVector>
#include <QTranslator>
#include <algorithm> // for heap functionality
#include "taskdialog.h"
#include "aboutdialog.h"
#include "configurationdialog.h"
#include "configurationmanager.h"
#include "task.h"

struct taskCompare
{
    bool operator ()(const Task *task1, const Task *task2) const {return *task1 > *task2;}
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);
    void mouseDoubleClickEvent(QMouseEvent *);
    void closeEvent(QCloseEvent *ev);
    void changeEvent(QEvent *ev);
    void timerEvent(QTimerEvent *);
    void paintEvent(QPaintEvent *ev);

private slots:
    void retranslateUi();
    void updateConfigurationChanges(const QString &setting);
    void minimizeToSystemTray();
    void restoreFromSystemTray(QSystemTrayIcon::ActivationReason reason);
    void setApplicationLanguage(const QString &appLanguage);
    void setApplicationStyle(styleName appStyle);
    void on_actionAdd_triggered();
    void on_actionEdit_triggered();
    void on_actionRemove_triggered();
    void on_actionSelectAll_triggered();
    void on_actionSelectNone_triggered();
    void on_actionConfiguration_triggered();
    void on_actionUserManual_triggered();
    void on_actionAbout_triggered();
    void on_actionRestore_triggered();
    void on_actionExit_triggered();
    void on_treeWidget_taskList_itemSelectionChanged();

private:
    Ui::MainWindow *ui;
    QTranslator translator;
    QTranslator translatorQt;
    QString currentAppLanguage;
    styleName currentAppStyle;
    QSystemTrayIcon *systemTrayIcon;
    QToolButton *helpToolButton;
    QAction *helpContextMenuAction;
    QString expiredTasksMessage;
    QString welcomeLine1;
    QString welcomeLine2;
    QString welcomeLine3;
    QString closeConfirmationMessage;
    QMessageBox *messageBoxConfirmation;
    TaskDialog *taskDialog;
    AboutDialog *aboutDialog;
    ConfigurationDialog *configDialog;
    ConfigurationManager *configManager;
    QVector<Task *> tasks;
    int timerID;
};

#endif // MAINWINDOW_H
