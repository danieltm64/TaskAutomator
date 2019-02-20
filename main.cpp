#include <QtWidgets/QApplication>
#include <QtCore/QTranslator>
#include "mainwindow.h"
#include "configurationmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("danieltm64");
    //a.setOrganizationDomain("danieltm64.com");
    a.setApplicationName("TaskAutomator");
    //a.setApplicationDisplayName("Task Automator");
    a.setApplicationVersion("1.0");
    a.setQuitOnLastWindowClosed(false);
    a.setWindowIcon(QIcon(":/resources/TaskAutomator16x16.png"));
    QDir::setCurrent(a.applicationDirPath());

    MainWindow w;

    if (!a.arguments().contains("-startmin", Qt::CaseSensitive))
        w.show();

    return a.exec();
}
