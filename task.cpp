#include "task.h"

Task::Task(QObject *parent) :
    QObject(parent),
    m_taskListEntry(0)
{
    connect(this, SIGNAL(nextOccurrenceUpdated()), this, SLOT(updateTaskListEntry()));
    connect(this, SIGNAL(nameUpdated()), this, SLOT(updateTaskListEntry()));
}

Task::Task(const Task &task)
{
    m_creationDateTime = task.m_creationDateTime;
    m_lastPerformance = task.m_lastPerformance;
    m_nextOccurrence = task.m_nextOccurrence;
    m_taskListEntry = task.m_taskListEntry;
    m_isBeingEdited = task.m_isBeingEdited;
    m_name = task.m_name;
    m_action = task.m_action;
    m_date = task.m_date;
    m_specifiedDate = task.m_specifiedDate;
    m_monthlyDays = task.m_monthlyDays;
    m_weeklyDays = task.m_weeklyDays;
    m_time = task.m_time;
    m_specifiedTime = task.m_specifiedTime;
    m_hoursFromNow = task.m_hoursFromNow;
    m_minutesFromNow = task.m_minutesFromNow;
    m_intervalHours = task.m_intervalHours;
    m_intervalMinutes = task.m_intervalMinutes;
    m_message = task.m_message;
    m_website = task.m_website;
    m_file = task.m_file;
    m_program = task.m_program;
    m_arguments = task.m_arguments;
    connect(this, SIGNAL(nextOccurrenceUpdated()), this, SLOT(updateTaskListEntry()));
    connect(this, SIGNAL(nameUpdated()), this, SLOT(updateTaskListEntry()));
}

Task::~Task()
{
}

QString Task::encodeNameToSave(const QString &str)
{
    return QString(str).replace("&", "&amp;", Qt::CaseInsensitive)
            .replace("\\", "&bslash;", Qt::CaseInsensitive)
            .replace("/", "&fslash;", Qt::CaseInsensitive)
            .replace(":", "&colon;", Qt::CaseInsensitive)
            .replace("*", "&asterisk;", Qt::CaseInsensitive)
            .replace("?", "&qmark;", Qt::CaseInsensitive)
            .replace("<", "&lt;", Qt::CaseInsensitive)
            .replace(">", "&gt;", Qt::CaseInsensitive)
            .replace("|", "&vbar;", Qt::CaseInsensitive);
}

QString Task::decodeNameToDisplay(const QString &str)
{
    return QString(str).replace("&amp;", "&", Qt::CaseInsensitive)
            .replace("&bslash;", "\\", Qt::CaseInsensitive)
            .replace("&fslash;", "/", Qt::CaseInsensitive)
            .replace("&colon;", ":", Qt::CaseInsensitive)
            .replace("&asterisk;", "*", Qt::CaseInsensitive)
            .replace("&qmark;", "?", Qt::CaseInsensitive)
            .replace("&lt;", "<", Qt::CaseInsensitive)
            .replace("&gt;", ">", Qt::CaseInsensitive)
            .replace("&vbar;", "|", Qt::CaseInsensitive);
}

void Task::saveTaskFile()
{
    QFile f("tasks/" + encodeNameToSave(m_name) + ".task");
    f.open(QIODevice::WriteOnly | QIODevice::Text);
    if (!f.isOpen())
        return;
    QJsonDocument j_document;
    QJsonObject j_object;
    j_object.insert("TaskFormatVersion", QJsonValue(QString("0.01")));
    j_object.insert("Action", m_action);
    switch (m_action)
    {
    case remindTheUser:
        j_object.insert("Message", m_message);
        break;
    case visitAWebsite:
        j_object.insert("Website", m_website);
        break;
    case openAFile:
        j_object.insert("File", m_file);
        break;
    case runAProgram:
        j_object.insert("Program", m_program);
        j_object.insert("Arguments", m_arguments);
        break;
    case logTheUserOff:
    case shutDownTheComputer:
    case restartTheComputer:
        break;
    }
    j_object.insert("Date", m_date);
    QJsonArray j_days;
    switch (m_date)
    {
    case specificDate:
        j_object.insert("SpecifiedDate", m_specifiedDate.toString("dd MM yyyy"));
        break;
    case monthly:
        for (int i = 0; i < 31; ++i)
            if (m_monthlyDays[i])
                j_days.append(QJsonValue(i + 1));
        j_object.insert("MonthlyDays", QJsonValue(j_days));
        break;
    case weekly:
        for (int i = 0; i < 7; ++i)
            if (m_weeklyDays[i])
                j_days.append(QJsonValue(i + 1));
        j_object.insert("WeeklyDays", QJsonValue(j_days));
        break;
    case daily:
        break;
    }
    j_object.insert("Time", m_time);
    switch (m_time)
    {
    case specificTime:
        j_object.insert("SpecifiedTime", QJsonValue(m_specifiedTime.toString("hh:mm:ss")));
        break;
    case timer:
        j_object.insert("HoursFromNow", QJsonValue(m_hoursFromNow));
        j_object.insert("MinutesFromNow", QJsonValue(m_minutesFromNow));
        break;
    case repetitive:
        j_object.insert("IntervalHours", QJsonValue(m_intervalHours));
        j_object.insert("IntervalMinutes", QJsonValue(m_intervalMinutes));
        j_object.insert("RunCount", QJsonValue(m_runCount));
        break;
    }
    j_object.insert("CreationDateTime", QJsonValue(m_creationDateTime.toString("dd MM yyyy hh:mm:ss")));
    j_object.insert("LastPerformance", QJsonValue(m_lastPerformance.toString("dd MM yyyy hh:mm:ss")));
    j_document.setObject(j_object);
    f.write(j_document.toJson());
    f.close();
}

void Task::loadTaskFile(const QString &fileName)
{
    QFile f("tasks/" + fileName);
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!f.isOpen())
        return;
    QString name = fileName;
    m_name = decodeNameToDisplay(name.remove(name.size() - 5, 5));
    QJsonDocument j_document = QJsonDocument::fromJson(f.readAll());
    QJsonObject j_object = j_document.object();
    m_action = (action)(int)(j_object.value("Action").toDouble());
    switch (m_action)
    {
    case remindTheUser:
        m_message = j_object.value("Message").toString();
        break;
    case visitAWebsite:
        m_website = j_object.value("Website").toString();
        break;
    case openAFile:
        m_file = j_object.value("File").toString();
        break;
    case runAProgram:
        m_program = j_object.value("Program").toString();
        m_arguments = j_object.value("Arguments").toString();
        break;
    }
    m_date = (dateKind)(int)(j_object.value("Date").toDouble());
    QJsonArray days;
    switch (m_date)
    {
    case specificDate:
        m_specifiedDate = QDate::fromString(j_object.value("SpecifiedDate").toString(), "dd MM yyyy");
        break;
    case today:
    case tomorrow:
        break;
    case monthly:
        days = j_object.value("MonthlyDays").toArray();
        m_monthlyDays = QVector<bool>(31, false);
        for (int i = 0; i < days.size(); ++i)
            m_monthlyDays[(int)(days[i].toDouble() - 1)] = true;
        break;
    case weekly:
        days = j_object.value("WeeklyDays").toArray();
        m_weeklyDays = QVector<bool>(7, false);
        for (int i = 0; i < days.size(); ++i)
            m_weeklyDays[(int)(days[i].toDouble() - 1)] = true;
        break;
    }
    m_time = (timeKind)(int)(j_object.value("Time").toDouble());
    switch (m_time)
    {
    case specificTime:
        m_specifiedTime = QTime::fromString(j_object.value("SpecifiedTime").toString(), "hh:mm:ss");
        break;
    case timer:
        m_hoursFromNow = (int)(j_object.value("HoursFromNow").toDouble());
        m_minutesFromNow = (int)(j_object.value("MinutesFromNow").toDouble());
        break;
    case repetitive:
        m_intervalHours = (int)(j_object.value("IntervalHoursNow").toDouble());
        m_intervalMinutes = (int)(j_object.value("IntervalMinutesNow").toDouble());
        m_runCount = (int)(j_object.value("RunCount").toDouble());
        break;
    }
    m_creationDateTime = QDateTime::fromString(j_object.value("CreationDateTime").toString(), "dd MM yyyy hh:mm:ss");
    m_lastPerformance = QDateTime::fromString(j_object.value("LastPerformance").toString(), "dd MM yyyy hh:mm:ss");
    f.close();
}

void Task::deleteTaskFile()
{
    QFile f("tasks/" + encodeNameToSave(m_name) + ".task");
    f.remove();
}

QDateTime Task::creationDateTime() const
{
    return m_creationDateTime;
}

void Task::setCreationDateTime(const QDateTime &dt)
{
    m_creationDateTime = dt;
}

QDateTime Task::lastPerformance() const
{
    return m_lastPerformance;
}

void Task::setLastPerformance(const QDateTime &dt)
{
    m_lastPerformance = dt;
}

QDateTime Task::nextOccurrence() const
{
    return m_nextOccurrence;
}

QTreeWidgetItem *Task::taskListEntry() const
{
    return m_taskListEntry;
}

void Task::setTaskListEntry(QTreeWidgetItem *item)
{
    m_taskListEntry = item;
}

bool Task::isBeingEdited() const
{
    return m_isBeingEdited;
}

void Task::setBeingEdited(bool b)
{
    m_isBeingEdited = b;
}

bool Task::isValid() const
{
    /*
    if (m_time == specificTime)
        switch (m_date)
        {
        case specificDate:
            return m_nextOccurrence > QDateTime::currentDateTime();
        case today:
            //return m_nextOccurrence.date() == m_creationDateTime.date() && m_nextOccurrence.time() >= QTime::currentTime();
            return m_creationDateTime.date() == QDate::currentDate() && m_nextOccurrence.time() > QTime::currentTime();
        case tomorrow:
            //return m_nextOccurrence.date() == m_creationDateTime.date() || (m_nextOccurrence.date() == m_creationDateTime.date().addDays(1) && m_nextOccurrence.time() >= QTime::currentTime());
            return m_creationDateTime.date() == QDate::currentDate() || (QDate::currentDate() == m_creationDateTime.date().addDays(1) && m_nextOccurrence.time() > QTime::currentTime());
        case monthly:
        case weekly:
        case daily:
            return true;
        }
    else if (m_time == timer || m_time == repetitive)
        return m_nextOccurrence > QDateTime::currentDateTime();
    return true;
    */
    return m_nextOccurrence > QDateTime::currentDateTime();
}

/*
// this function used to be useful but is no longer used
bool Task::isSingleShot() const
{
    if (m_time == specificTime)
    {
        if (m_date == specificDate || m_date == today || m_date == tomorrow)
            return true;
        return false;
    }
    if (m_time == timer)
        return true;
    return false;
}
*/

QString Task::name() const
{
    return m_name;
}

void Task::setName(const QString &n)
{
    if (m_name != n)
    {
        m_name = n;
        emit nameUpdated();
    }
}

action Task::taskAction() const
{
    return m_action;
}

void Task::setTaskAction(action a)
{
    m_action = a;
}

dateKind Task::taskDate() const
{
    return m_date;
}

void Task::setTaskDate(dateKind d)
{
    m_date = d;
}

QDate Task::specifiedDate() const
{
    return m_specifiedDate;
}

void Task::setSpecifiedDate(const QDate &d)
{
    m_specifiedDate = d;
}

QVector<bool> Task::monthlyDays() const
{
    return m_monthlyDays;
}

void Task::setMonthlyDays(const QVector<bool> &d)
{
    m_monthlyDays = d;
}

QVector<bool> Task::weeklyDays() const
{
    return m_weeklyDays;
}

void Task::setWeeklyDays(const QVector<bool> &d)
{
    m_weeklyDays = d;
}

timeKind Task::taskTime() const
{
    return m_time;
}

void Task::setTaskTime(timeKind t)
{
    m_time = t;
}

QTime Task::specifiedTime() const
{
    return m_specifiedTime;
}

void Task::setSpecifiedTime(const QTime &t)
{
    m_specifiedTime = t;
}

int Task::hoursFromNow() const
{
    return m_hoursFromNow;
}

void Task::setHoursFromNow(int h)
{
    m_hoursFromNow = h;
}

int Task::minutesFromNow() const
{
    return m_minutesFromNow;
}

void Task::setMinutesFromNow(int m)
{
    m_minutesFromNow = m;
}

int Task::runCount() const
{
    return m_runCount;
}

void Task::setRunCount(int count)
{
    m_runCount = count;
}

QTime Task::startingTime() const
{
    return m_startingTime;
}

void Task::setStartingTime(const QTime &t)
{
    m_startingTime = t;
}

int Task::intervalHours() const
{
    return m_intervalHours;
}

void Task::setIntervalHours(int h)
{
    m_intervalHours = h;
}

int Task::intervalMinutes() const
{
    return m_intervalMinutes;
}

void Task::setIntervalMinutes(int m)
{
    m_intervalMinutes = m;
}

QString Task::message() const
{
    return m_message;
}

void Task::setMessage(const QString &msg)
{
    m_message = msg;
}

QString Task::website() const
{
    return m_website;
}

void Task::setWebsite(const QString &site)
{
    m_website = site;
}

QString Task::file() const
{
    return m_file;
}

void Task::setFile(const QString &f)
{
    m_file = f;
}

QString Task::program() const
{
    return m_program;
}

void Task::setProgram(const QString &prog)
{
    m_program = prog;
}

QString Task::arguments() const
{
    return m_arguments;
}

void Task::setArguments(const QString &args)
{
    m_arguments = args;
}

bool Task::operator <(const Task &other) const
{
    return m_nextOccurrence < other.m_nextOccurrence;
}

bool Task::operator >(const Task &other) const
{
    return m_nextOccurrence > other.m_nextOccurrence;
}

/*
// this function used to be useful but is no longer used
Task &Task::operator =(const Task &task)
{
    m_creationDateTime = task.m_creationDateTime;
    m_lastPerformance = task.m_lastPerformance;
    m_nextOccurrence = task.m_nextOccurrence;
    m_taskListEntry = task.m_taskListEntry;
    m_isBeingEdited = task.m_isBeingEdited;
    m_name = task.m_name;
    m_action = task.m_action;
    m_date = task.m_date;
    m_specifiedDate = task.m_specifiedDate;
    m_monthlyDays = task.m_monthlyDays;
    m_weeklyDays = task.m_weeklyDays;
    m_time = task.m_time;
    m_specifiedTime = task.m_specifiedTime;
    m_hoursFromNow = task.m_hoursFromNow;
    m_minutesFromNow = task.m_minutesFromNow;
    m_intervalHours = task.m_intervalHours;
    m_intervalMinutes = task.m_intervalMinutes;
    m_message = task.m_message;
    m_website = task.m_website;
    m_file = task.m_file;
    m_program = task.m_program;
    m_arguments = task.m_arguments;
    connect(this, SIGNAL(nextOccurrenceUpdated()), this, SLOT(updateTaskListEntry()));
    connect(this, SIGNAL(nameUpdated()), this, SLOT(updateTaskListEntry()));
    return *this;
}
*/

Task::operator QVariant() const
{
    return QVariant::fromValue(*this);
}

void Task::do_remindTheUser(QString taskName, QString msg)
{
    QString file;
    switch (QSysInfo::WindowsVersion)
    {
    case QSysInfo::WV_XP:
        file = "C:/WINDOWS/Media/Windows XP Ringin.wav";
        break;
    case QSysInfo::WV_VISTA:
    case QSysInfo::WV_WINDOWS7:
    case QSysInfo::WV_WINDOWS8:
    case QSysInfo::WV_WINDOWS8_1:
        file = "C:/Windows/Media/Windows Ringin.wav";
        break;
    }
    QSound alert(file);
    alert.setLoops(3);
    alert.play();
    RemindDialog remindDialog(0, taskName, msg);
}

void Task::do_visitAWebsite(QString address)
{
    QUrl url(address);
    if (url.scheme().isEmpty())
    {
        url.setUrl("http://" + address);
        QDesktopServices::openUrl(url);
    }
    else if (url.scheme() == "http" || url.scheme() == "https")
        QDesktopServices::openUrl(url);
}

void Task::do_openAFile(QString taskFile)
{
    QUrl url(QDir::fromNativeSeparators(taskFile));
    url.setUrl("file:///" + taskFile);
    QDesktopServices::openUrl(url);
}

void Task::do_runAProgram(QString taskProgram, QString taskArguments)
{
    QProcess *process = new QProcess;
    connect(process, SIGNAL(finished(int)), process, SLOT(deleteLater()));
    process->start(taskProgram, taskArguments.split(' '));
}

void Task::do_logTheUserOff()
{
    QProcess *process = new QProcess;
    connect(process, SIGNAL(finished(int)), process, SLOT(deleteLater()));
    process->start("shutdown", QStringList() << "/l");
}

void Task::do_shutDownTheComputer()
{
    QProcess *process = new QProcess;
    connect(process, SIGNAL(finished(int)), process, SLOT(deleteLater()));
    process->start("shutdown", QStringList() << "/s" << "/t" << "0");
}

void Task::do_restartTheComputer()
{
    QProcess *process = new QProcess;
    connect(process, SIGNAL(finished(int)), process, SLOT(deleteLater()));
    process->start("shutdown", QStringList() << "/r" << "/t" << "0");
}

void Task::performNow()
{
    ActionStarter *a = new ActionStarter(this);
    a->setName(m_name);
    a->setAction(m_action);
    switch (m_action)
    {
    case remindTheUser:
        a->setString1(m_message);
        break;
    case visitAWebsite:
        a->setString1(m_website);
        break;
    case openAFile:
        a->setString1(m_file);
        break;
    case runAProgram:
        a->setString1(m_program);
        a->setString2(m_arguments);
        break;
    case logTheUserOff:
    case shutDownTheComputer:
    case restartTheComputer:
        break;
    }
    connect(a, SIGNAL(finished()), this, SIGNAL(finished()));
    connect(a, SIGNAL(finished()), a, SLOT(deleteLater()));
    connect(a, SIGNAL(do_remindTheUser(QString,QString)), this, SLOT(do_remindTheUser(QString,QString)));
    connect(a, SIGNAL(do_visitAWebsite(QString)), this, SLOT(do_visitAWebsite(QString)));
    connect(a, SIGNAL(do_openAFile(QString)), this, SLOT(do_openAFile(QString)));
    connect(a, SIGNAL(do_runAProgram(QString,QString)), this, SLOT(do_runAProgram(QString,QString)));
    connect(a, SIGNAL(do_logTheUserOff()), this, SLOT(do_logTheUserOff()));
    connect(a, SIGNAL(do_shutDownTheComputer()), this, SLOT(do_shutDownTheComputer()));
    connect(a, SIGNAL(do_restartTheComputer()), this, SLOT(do_restartTheComputer()));
    m_lastPerformance = QDateTime::currentDateTime();
    updateNextOccurrence();
    a->start();
}

void Task::updateNextOccurrence()
{
    QDateTime next;
    if (m_time == specificTime)
    {
        if (m_date == specificDate)
            next = QDateTime(m_specifiedDate, m_specifiedTime);
        else if (m_date == today)
            next = QDateTime(m_creationDateTime.date(), m_specifiedTime);
        else if (m_date == tomorrow)
            next = QDateTime(m_creationDateTime.addDays(1).date(), m_specifiedTime);
        else if (m_date == monthly)
        {
            next = QDateTime(nextMonthlyDay(QDate::currentDate()), m_specifiedTime);
            if (next < QDateTime::currentDateTime())
                next.setDate(nextMonthlyDay(QDate::currentDate().addDays(1)));
        }
        else if (m_date == weekly)
        {
            next = QDateTime(nextWeeklyDay(QDate::currentDate()), m_specifiedTime);
            if (next < QDateTime::currentDateTime())
                next.setDate(nextWeeklyDay(QDate::currentDate().addDays(1)));
        }
        else if (m_date == daily)
        {
            next = QDateTime(QDate::currentDate(), m_specifiedTime);
            if (next < QDateTime::currentDateTime())
                next = next.addDays(1);
        }
    }
    else if (m_time == timer)
        next = QDateTime(m_creationDateTime).addSecs(60 * m_minutesFromNow + 3600 * m_hoursFromNow);
    else if (m_time == repetitive)
    {
        QDateTime currentDateTime = QDateTime::currentDateTime();
        int total = m_runCount - 1;
        if (m_date == specificDate)
        {
            next = QDateTime(m_specifiedDate, m_startingTime);
            for (int i = 0; i < total; i++)
            {
                if (next >= currentDateTime)
                    break;
                next = next.addSecs(60 * m_intervalMinutes + 3600 * m_intervalHours);
            }
        }
        else if (m_date == today)
        {
            next = QDateTime(m_creationDateTime.date(), m_startingTime);
            for (int i = 0; i < total; i++)
            {
                if (next >= currentDateTime)
                    break;
                next = next.addSecs(60 * m_intervalMinutes + 3600 * m_intervalHours);
            }
        }
        else if (m_date == tomorrow)
        {
            next = QDateTime(m_creationDateTime.addDays(1).date(), m_startingTime);
            for (int i = 0; i < total; i++)
            {
                if (next >= currentDateTime)
                    break;
                next = next.addSecs(60 * m_intervalMinutes + 3600 * m_intervalHours);
            }
        }
        else if (m_date == monthly)
        {
            next = QDateTime(nextMonthlyDay(QDate::currentDate()), m_startingTime);
            if (next < QDateTime::currentDateTime())
                next.setDate(nextMonthlyDay(QDate::currentDate().addDays(1)));
            for (int i = 0; i < total; i++)
            {
                if (next >= currentDateTime)
                    break;
                next = next.addSecs(60 * m_intervalMinutes + 3600 * m_intervalHours);
            }
        }
        else if (m_date == weekly)
        {
            next = QDateTime(nextWeeklyDay(QDate::currentDate()), m_startingTime);
            if (next < QDateTime::currentDateTime())
                next.setDate(nextWeeklyDay(QDate::currentDate().addDays(1)));
            for (int i = 0; i < total; i++)
            {
                if (next >= currentDateTime)
                    break;
                next = next.addSecs(60 * m_intervalMinutes + 3600 * m_intervalHours);
            }
        }
        else if (m_date == daily)
        {
            next = QDateTime(QDate::currentDate(), m_startingTime);
            if (next < QDateTime::currentDateTime())
                next = next.addDays(1);
            for (int i = 0; i < total; i++)
            {
                if (next >= currentDateTime)
                    break;
                next = next.addSecs(60 * m_intervalMinutes + 3600 * m_intervalHours);
            }
        }
    }
    m_nextOccurrence = next;
    emit nextOccurrenceUpdated();
}

void Task::updateTaskListEntry()
{
    if (m_taskListEntry)
    {
        m_taskListEntry->setText(0, m_nextOccurrence.toString(Qt::SystemLocaleShortDate));
        m_taskListEntry->setText(1, m_name);
    }
}

// helper method for determining the next occurrence of a monthly task
QDate Task::nextMonthlyDay(QDate tday) const
{
    /*
    loop through m_monthlyDays starting from today
        set year=current, month=current day=(loop counter + 1)
        if there is no such day in the current month, get the next occurrence in the next month
    if the loop counter surpassed the length of m_monthlyDays, then get the next occurrence in the next month
    */
    int i;
    for (i = tday.day() - 1; i < m_monthlyDays.count(); ++i)
        if (m_monthlyDays[i])
            break;
    bool tryNextMonth = false;
    if (i == 31 || tday.daysInMonth() < i + 1)
        tryNextMonth = true;
    if (!tryNextMonth)
        tday.setDate(tday.year(), tday.month(), i + 1);
    else
        while (tryNextMonth)
        {
            tday = tday.addMonths(1);
            tday.setDate(tday.year(), tday.month(), 1);
            int j;
            for (j = 0; j < m_monthlyDays.count(); ++j)
                if (m_monthlyDays[j])
                    break;
            if (tday.daysInMonth() >= j + 1)
            {
                tday.setDate(tday.year(), tday.month(), j + 1);
                tryNextMonth = false;
            }
        }
    return tday;
}

// helper method for determining the next occurrence of a weekly task
QDate Task::nextWeeklyDay(QDate tday) const
{
    /*
    loop through m_weeklyDays starting from today
    if the loop counter surpassed the length of m_weeklyDays, then get the next occurrence in the next week
    */
    int i;
    for (i = tday.dayOfWeek() % 7; i < m_weeklyDays.count(); ++i, tday = tday.addDays(1))
        if (m_weeklyDays[i])
            break;
    if (i == 7)
    {
        while (tday.dayOfWeek() != 7)
            tday = tday.addDays(1);
        for (i = 0; i < m_weeklyDays.count(); ++i, tday = tday.addDays(1))
            if (m_weeklyDays[i])
                break;
    }
    return tday;
}
