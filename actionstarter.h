#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include "globals.h"

class ActionStarter : public QThread
{
    Q_OBJECT

public:
    explicit ActionStarter(QObject *parent = 0);
    void setName(QString name);
    void setAction(action a);
    void setString1(QString str);
    void setString2(QString str);

protected:
    void run();

signals:
    void do_remindTheUser(QString name, QString msg);
    void do_visitAWebsite(QString address);
    void do_openAFile(QString file);
    void do_runAProgram(QString program, QString arguments);
    void do_logTheUserOff();
    void do_shutDownTheComputer();
    void do_restartTheComputer();

private:
    QString m_name;
    action m_action;
    QString m_string1;
    QString m_string2;
};

#endif // MYTHREAD_H
