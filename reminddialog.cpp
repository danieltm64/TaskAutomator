#include "reminddialog.h"
#include "ui_reminddialog.h"

RemindDialog::RemindDialog(QWidget *parent, const QString &taskName, const QString &message) :
    QDialog(parent),
    ui(new Ui::RemindDialog)
{
    ui->setupUi(this);
    // make the window adjust its size based on whether there is a message to remind the user with
    window()->layout()->setSizeConstraint(QLayout::SetFixedSize);
    // setting up the user-visible text
    if (message.isEmpty())
    {
        ui->label->setText(tr("Task Automator was configured to remind you of the following task.<br />It is now %1.<br />Task: <i>%2</i>.").arg(QTime::currentTime().toString("hh:mm")).arg(taskName));
        ui->plainTextEdit->setVisible(false);
    }
    else
    {
        ui->label->setText(tr("Task Automator was configured to remind you with the following message.<br />It is now %1.<br />Task: <i>%2</i>.").arg(QTime::currentTime().toString("hh:mm")).arg(taskName));
        ui->plainTextEdit->setPlainText(message);
    }
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    exec();
}

RemindDialog::~RemindDialog()
{
    delete ui;
}
