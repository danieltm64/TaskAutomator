#ifndef CONFIGURATIONMANAGER_H
#define CONFIGURATIONMANAGER_H

#include <QObject>
#include <QCoreApplication>
#include <QSettings>
#include <QDir>
#include <QVector>
#include <QDate>
#include <QTime>
#include <QStandardPaths>
#include "globals.h"

#include <QMessageBox>

class ConfigurationManager : public QObject
{
    Q_OBJECT

public:
    static ConfigurationManager *instance();

    void startChanging();
    bool isChanging();
    void stopChanging();

    void saveConfiguration();

    QString fileName() const;

    QVariant defaultSetting(const QString &s) const;
    void restoreDefaultSettings();

    QString language() const;
    void setLanguage(const QString &lang);

    styleName applicationStyle() const;
    void setApplicationStyle(styleName appStyle);

    bool displayToolbar() const;
    void setDisplayToolbar(bool display);

    bool alternateBackgroundColor() const;
    void setAlternateBackgroundColor(bool alternate);

    bool confirmToRemoveTasks() const;
    void setConfirmToRemoveTasks(bool confirm);

    bool confirmToExitProgram() const;
    void setConfirmToExitProgram(bool confirm);

    bool minimizeToSystemTray() const;
    void setMinimizeToSystemTray(bool minimize);

    bool closeToSystemTray() const;
    void setCloseToSystemTray(bool close);

    bool startAutomatically() const;
    void setStartAutomatically(bool start);

signals:
    void configurationChanged(const QString &setting);

private:
    explicit ConfigurationManager(QObject *parent = 0);
    void updateStartAutomaticallySetting();
    static ConfigurationManager *onlyInstance;
    QSettings m_settings;
    bool m_isChanging;
    QHash<QString, QVariant> m_defaultSettings;
    QHash<QString, bool> m_dirtySettings;
    action m_defaultAction;
    dateKind m_defaultDate;
    QDate m_specifiedDate;
    QVector<bool> m_monthlyDays;
    QVector<bool> m_weeklyDays;
    timeKind m_defaultTime;
    QTime m_specifiedTime;
    int m_hoursFromNow;
    int m_minutesFromNow;
    int m_runCount;
    QTime m_startingTime;
    int m_intervalHours;
    int m_intervalMinutes;
    QString m_language;
    styleName m_applicationStyle;
    QPalette m_standardFusionPalette;
    bool m_displayToolbar;
    bool m_alternateBackgroundColor;
    bool m_confirmToRemoveTasks;
    bool m_confirmToExitProgram;
    bool m_minimizeToSystemTray;
    bool m_closeToSystemTray;
    bool m_startAutomatically;
};

#endif // CONFIGURATIONMANAGER_H
