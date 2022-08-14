#include "configurationmanager.h"

ConfigurationManager *ConfigurationManager::onlyInstance = nullptr;

ConfigurationManager::ConfigurationManager(QObject *parent) :
    QObject(parent),
    m_monthlyDays(31),
    m_weeklyDays(7),
    m_settings(QSettings::IniFormat, QSettings::UserScope, qApp->organizationName(), qApp->applicationName())
{
    // setting things up for the singleton design pattern
    onlyInstance = this;
    // setting up the default settings
    m_defaultSettings["language"] = "English (US)";
    m_defaultSettings["applicationStyle"] = 0;
    m_defaultSettings["displayToolbar"] = true;
    m_defaultSettings["alternateBackgroundColor"] = false;
    m_defaultSettings["confirmToRemoveTasks"] = true;
    m_defaultSettings["confirmToExitProgram"] = false;
    m_defaultSettings["minimizeToSystemTray"] = true;
    m_defaultSettings["closeToSystemTray"] = false;
    m_defaultSettings["startAutomatically"] = false;
    // stop setting up the default settings
    // start retrieving general settings
    m_settings.beginGroup("generalSettings");
    m_language = m_settings.value("language", m_defaultSettings["language"]).toString();
    m_applicationStyle = (styleName)(m_settings.value("applicationStyle", m_defaultSettings["applicationStyle"]).toInt());
    m_displayToolbar = m_settings.value("displayToolbar", m_defaultSettings["displayToolbar"]).toBool();
    m_alternateBackgroundColor = m_settings.value("alternateBackgroundColor", m_defaultSettings["alternateBackgroundColor"]).toBool();
    m_confirmToRemoveTasks = m_settings.value("confirmToRemoveTasks", m_defaultSettings["confirmToRemoveTasks"]).toBool();
    m_confirmToExitProgram = m_settings.value("confirmToExitProgram", m_defaultSettings["confirmToExitProgram"]).toBool();
    m_minimizeToSystemTray = m_settings.value("minimizeToSystemTray", m_defaultSettings["minimizeToSystemTray"]).toBool();
    m_closeToSystemTray = m_settings.value("closeToSystemTray", m_defaultSettings["closeToSystemTray"]).toBool();
    m_startAutomatically = m_settings.value("startAutomatically", m_defaultSettings["startAutomatically"]).toBool();
    // stop retrieving general settings
    m_settings.endGroup();
    updateStartAutomaticallySetting();
}

void ConfigurationManager::updateStartAutomaticallySetting()
{
    // the following implementation of the "Start automatically when I log in" setting update is Windows-specific
    switch (QSysInfo::WindowsVersion)
    {
    case QSysInfo::WV_WINDOWS8:
    case QSysInfo::WV_WINDOWS8_1:
        if (m_startAutomatically)
            QFile::link(qApp->applicationFilePath(), QStandardPaths::standardLocations(QStandardPaths::ApplicationsLocation).first() + "/Startup/Task Automator.lnk");
        else
            QFile::remove(QStandardPaths::standardLocations(QStandardPaths::ApplicationsLocation).first() + "/Startup/Task Automator.lnk");
        break;
    default:
        QSettings registry("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
        if (m_startAutomatically)
            registry.setValue(qApp->applicationName() + '-' + qApp->organizationName(), '\"' + QDir::toNativeSeparators(qApp->applicationFilePath()) + "\" -startmin");
        else
            registry.remove(qApp->applicationName() + '-' + qApp->organizationName());
        break;
    }
}

ConfigurationManager *ConfigurationManager::instance()
{
    if (!onlyInstance)
        onlyInstance = new ConfigurationManager;
    return onlyInstance;
}

void ConfigurationManager::startChanging()
{
    m_isChanging = true;
}

bool ConfigurationManager::isChanging()
{
    return m_isChanging;
}

void ConfigurationManager::stopChanging()
{
    if (m_isChanging)
    {
        m_isChanging = false;
        emit configurationChanged("<group>");
    }
}

void ConfigurationManager::saveConfiguration()
{
    // saving only the "dirty" settings
    // start saving the general settings
    m_settings.beginGroup("generalSettings");
    if (m_dirtySettings.value("language", false))
        m_settings.setValue("language", m_language);
    if (m_dirtySettings.value("applicationStyle", false))
        m_settings.setValue("applicationStyle", (int)(m_applicationStyle));
    if (m_dirtySettings.value("displayToolbar", false))
        m_settings.setValue("displayToolbar", m_displayToolbar);
    if (m_dirtySettings.value("alternateBackgroundColor", false))
        m_settings.setValue("alternateBackgroundColor", m_alternateBackgroundColor);
    if (m_dirtySettings.value("confirmToRemoveTasks", false))
        m_settings.setValue("confirmToRemoveTasks", m_confirmToRemoveTasks);
    if (m_dirtySettings.value("confirmToExitProgram", false))
        m_settings.setValue("confirmToExitProgram", m_confirmToExitProgram);
    if (m_dirtySettings.value("minimizeToSystemTray", false))
        m_settings.setValue("minimizeToSystemTray", m_minimizeToSystemTray);
    if (m_dirtySettings.value("closeToSystemTray", false))
        m_settings.setValue("closeToSystemTray", m_closeToSystemTray);
    if (m_dirtySettings.value("startAutomatically", false))
        m_settings.setValue("startAutomatically", m_startAutomatically);
    // stop saving the general settings
    m_settings.endGroup();
    // committing changes
    m_settings.sync();
    updateStartAutomaticallySetting();
    // resetting the "dirty" state of the general settings
    m_dirtySettings["language"] = false;
    m_dirtySettings["applicationStyle"] = false;
    m_dirtySettings["displayToolbar"] = false;
    m_dirtySettings["alternateBackgroundColor"] = false;
    m_dirtySettings["confirmToRemoveTasks"] = false;
    m_dirtySettings["confirmToExitProgram"] = false;
    m_dirtySettings["minimizeToSystemTray"] = false;
    m_dirtySettings["closeToSystemTray"] = false;
    m_dirtySettings["startAutomatically"] = false;
}

QString ConfigurationManager::fileName() const
{
    return m_settings.fileName();
}

QVariant ConfigurationManager::defaultSetting(const QString &s) const
{
    return m_defaultSettings[s];
}

void ConfigurationManager::restoreDefaultSettings()
{
    // start restoring general settings
    setLanguage(m_defaultSettings["language"].toString());
    setApplicationStyle((styleName)(m_defaultSettings["applicationStyle"].toInt()));
    setDisplayToolbar(m_defaultSettings["displayToolbar"].toBool());
    setAlternateBackgroundColor(m_defaultSettings["alternateBackgroundColor"].toBool());
    setConfirmToRemoveTasks(m_defaultSettings["confirmToRemoveTasks"].toBool());
    setConfirmToExitProgram(m_defaultSettings["confirmToExitProgram"].toBool());
    setMinimizeToSystemTray(m_defaultSettings["minimizeToSystemTray"].toBool());
    setCloseToSystemTray(m_defaultSettings["closeToSystemTray"].toBool());
    setStartAutomatically(m_defaultSettings["startAutomatically"].toBool());
    updateStartAutomaticallySetting();
    stopChanging();
}

QString ConfigurationManager::language() const
{
    return m_language;
}

void ConfigurationManager::setLanguage(const QString &lang)
{
    if (m_language != lang)
    {
        m_language = lang;
        m_dirtySettings["language"] = true;
        if (!m_isChanging)
            emit configurationChanged("language");
    }
}

styleName ConfigurationManager::applicationStyle() const
{
    return m_applicationStyle;
}

void ConfigurationManager::setApplicationStyle(styleName appStyle)
{
    if (m_applicationStyle != appStyle)
    {
        m_applicationStyle = appStyle;
        m_dirtySettings["applicationStyle"] = true;
        if (!m_isChanging)
            emit configurationChanged("applicationStyle");
    }
}

bool ConfigurationManager::displayToolbar() const
{
    return m_displayToolbar;
}

void ConfigurationManager::setDisplayToolbar(bool display)
{
    if (m_displayToolbar != display)
    {
        m_displayToolbar = display;
        m_dirtySettings["displayToolbar"] = true;
        if (!m_isChanging)
            emit configurationChanged("displayToolbar");
    }
}

bool ConfigurationManager::alternateBackgroundColor() const
{
    return m_alternateBackgroundColor;
}

void ConfigurationManager::setAlternateBackgroundColor(bool alternate)
{
    if (m_alternateBackgroundColor != alternate)
    {
        m_alternateBackgroundColor = alternate;
        m_dirtySettings["alternateBackgroundColor"] = true;
        if (!m_isChanging)
            emit configurationChanged("alternateBackgroundColor");
    }
}

bool ConfigurationManager::confirmToRemoveTasks() const
{
    return m_confirmToRemoveTasks;
}

void ConfigurationManager::setConfirmToRemoveTasks(bool confirm)
{
    if (m_confirmToRemoveTasks != confirm)
    {
        m_confirmToRemoveTasks = confirm;
        m_dirtySettings["confirmToRemoveTasks"] = true;
        if (!m_isChanging)
            emit configurationChanged("confirmToRemoveTasks");
    }
}

bool ConfigurationManager::confirmToExitProgram() const
{
    return m_confirmToExitProgram;
}

void ConfigurationManager::setConfirmToExitProgram(bool confirm)
{
    if (m_confirmToExitProgram != confirm)
    {
        m_confirmToExitProgram = confirm;
        m_dirtySettings["confirmToExitProgram"] = true;
        if (!m_isChanging)
            emit configurationChanged("confirmToExitProgram");
    }
}

bool ConfigurationManager::minimizeToSystemTray() const
{
    return m_minimizeToSystemTray;
}

void ConfigurationManager::setMinimizeToSystemTray(bool minimize)
{
    if (m_minimizeToSystemTray != minimize)
    {
        m_minimizeToSystemTray = minimize;
        m_dirtySettings["minimizeToSystemTray"] = true;
        if (!m_isChanging)
            emit configurationChanged("minimizeToSystemTray");
    }
}

bool ConfigurationManager::closeToSystemTray() const
{
    return m_closeToSystemTray;
}

void ConfigurationManager::setCloseToSystemTray(bool close)
{
    if (m_closeToSystemTray != close)
    {
        m_closeToSystemTray = close;
        m_dirtySettings["closeToSystemTray"] = true;
        if (!m_isChanging)
            emit configurationChanged("closeToSystemTray");
    }
}

bool ConfigurationManager::startAutomatically() const
{
    return m_startAutomatically;
}

void ConfigurationManager::setStartAutomatically(bool start)
{
    if (m_startAutomatically != start)
    {
        m_startAutomatically = start;
        m_dirtySettings["startAutomatically"] = true;
        if (!m_isChanging)
            emit configurationChanged("startAutomatically");
    }
}
