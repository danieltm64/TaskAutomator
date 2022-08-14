#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    // getting a pointer to the configuration manager
    configManager = ConfigurationManager::instance();
    // set up the window so the user can't resize it and so that it adapts to the layout in case it gets resized programmatically
    window()->layout()->setSizeConstraint(QLayout::SetFixedSize);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::showEvent(QShowEvent *)
{
    QString color = (configManager->applicationStyle() == standardStyle || configManager->applicationStyle() == fusionStyle) ? "blue" : "white";
    ui->label->setText(tr("<html><head><style type=\"text/css\">a{color:%1;}</style><head/><body><img src=\":/resources/TaskAutomator96x96.png\" style=\"float:left;\"/><div style=\"margin-left:108px;\">Task Automator %2<br />(C) 2010-2019 Daniel Telles McGinnis<br /><a href=\"%3\">%3</a><br /><br /><b>License</b><br />Refraction Visualizer is free and open source software available under the GNU Affero General Public License version 3 as published by the Free Software Foundation. <a href=\"agplv3.html\">View full license</a><br /><br /><b>Credits</b><br />Developed by Daniel McGinnis. Special thanks to my brother Kevin McGinnis for the initial concept behind Task Automator as well as his invaluable feedback during the development process.</body></html>").arg(color).arg(qApp->applicationVersion()).arg("https://github.com/danieltm64"));
}
