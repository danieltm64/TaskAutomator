#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QDateTime>
#include <QDate>
#include <QTime>
#include <QTimer>
#include <QVector>
#include <QUrl>
#include <QProcess>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QApplication>
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <QDesktopServices>
#include <QSound>
#include "globals.h"
#include "actionstarter.h"
#include "reminddialog.h"

class Task : public QObject
{
    Q_OBJECT

public:
    QString m_firstLine; // just for testing the save/load
    explicit Task(QObject *parent = 0);
    Task(const Task &task);
    ~Task();
    static QString encodeNameToSave(const QString &str);
    static QString decodeNameToDisplay(const QString &str);
    void saveTaskFile();
    void loadTaskFile(const QString &fileName);
    void deleteTaskFile();
    QDateTime creationDateTime() const;
    void setCreationDateTime(const QDateTime &dt);
    QDateTime lastPerformance() const;
    void setLastPerformance(const QDateTime &dt);
    QDateTime nextOccurrence() const;
    QTreeWidgetItem *taskListEntry() const;
    void setTaskListEntry(QTreeWidgetItem *item);
    bool isBeingEdited() const;
    void setBeingEdited(bool b);
    bool isValid() const;
    // bool isSingleShot() const; // this function used to be useful but is no longer used
    QString name() const;
    void setName(const QString &n);
    action taskAction() const;
    void setTaskAction(action a);
    dateKind taskDate() const;
    void setTaskDate(dateKind d);
    QDate specifiedDate() const;
    void setSpecifiedDate(const QDate &d);
    QVector<bool> monthlyDays() const;
    void setMonthlyDays(const QVector<bool> &d);
    QVector<bool> weeklyDays() const;
    void setWeeklyDays(const QVector<bool> &d);
    timeKind taskTime() const;
    void setTaskTime(timeKind t);
    QTime specifiedTime() const;
    void setSpecifiedTime(const QTime &t);
    int hoursFromNow() const;
    void setHoursFromNow(int h);
    int minutesFromNow() const;
    void setMinutesFromNow(int m);
    int runCount() const;
    void setRunCount(int count);
    QTime startingTime() const;
    void setStartingTime(const QTime &t);
    int intervalHours() const;
    void setIntervalHours(int h);
    int intervalMinutes() const;
    void setIntervalMinutes(int m);
    QString message() const;
    void setMessage(const QString &msg);
    QString website() const;
    void setWebsite(const QString &site);
    QString file() const;
    void setFile(const QString &f);
    QString program() const;
    void setProgram(const QString &prog);
    QString arguments() const;
    void setArguments(const QString &args);
    bool operator <(const Task &other) const;
    bool operator >(const Task &other) const;
    // Task &operator =(const Task &other); // this function used to be useful but is no longer used
    operator QVariant() const;

signals:
    void nextOccurrenceUpdated();
    void nameUpdated();
    void finished();

public slots:
    void do_remindTheUser(QString taskName, QString msg);
    void do_visitAWebsite(QString address);
    void do_openAFile(QString taskFile);
    void do_runAProgram(QString taskProgram, QString taskArguments);
    void do_logTheUserOff();
    void do_shutDownTheComputer();
    void do_restartTheComputer();
    void performNow();
    void updateNextOccurrence();
    void updateTaskListEntry();

private:
    QDateTime m_creationDateTime;
    QDateTime m_lastPerformance;
    QDateTime m_nextOccurrence;
    QTreeWidgetItem *m_taskListEntry;
    bool m_isBeingEdited;
    QString m_name;
    action m_action;
    dateKind m_date;
    QDate m_specifiedDate;
    QVector<bool> m_monthlyDays;
    QVector<bool> m_weeklyDays;
    timeKind m_time;
    QTime m_specifiedTime;
    int m_hoursFromNow;
    int m_minutesFromNow;
    int m_runCount;
    QTime m_startingTime;
    int m_intervalHours;
    int m_intervalMinutes;
    QString m_message;
    QString m_website;
    QString m_file;
    QString m_program;
    QString m_arguments;
    QDate nextMonthlyDay(QDate tday) const;
    QDate nextWeeklyDay(QDate tday) const;
};

Q_DECLARE_METATYPE(Task)

#endif // TASK_H
