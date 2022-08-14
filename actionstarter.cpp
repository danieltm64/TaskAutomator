#include "actionstarter.h"

ActionStarter::ActionStarter(QObject *parent) :
    QThread(parent)
{
}

void ActionStarter::setName(QString name)
{
    m_name = name;
}

void ActionStarter::setAction(action a)
{
    m_action = a;
}

void ActionStarter::setString1(QString str)
{
    m_string1 = str;
}

void ActionStarter::setString2(QString str)
{
    m_string2 = str;
}

void ActionStarter::run()
{
    switch (m_action)
    {
    case remindTheUser:
        emit do_remindTheUser(m_name, m_string1);
        break;
    case visitAWebsite:
        emit do_visitAWebsite(m_string1);
        break;
    case openAFile:
        emit do_openAFile(m_string1);
        break;
    case runAProgram:
        emit do_runAProgram(m_string1, m_string2);
        break;
    case logTheUserOff:
        emit do_logTheUserOff();
        break;
    case shutDownTheComputer:
        emit do_shutDownTheComputer();
        break;
    case restartTheComputer:
        emit do_restartTheComputer();
        break;
    }
}
