#ifndef CONFIGURATIONDIALOG_H
#define CONFIGURATIONDIALOG_H

#include <QDialog>
#include <QPushButton>
#include "configurationmanager.h"

namespace Ui {
class ConfigurationDialog;
}

class ConfigurationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigurationDialog(QWidget *parent = 0);
    ~ConfigurationDialog();
    void setDisplayToolbarChecked(bool checked);

private slots:
    void updateAllSettings();
    void restoreDefaultSettings();
    void on_buttonBox_accepted();

private:
    Ui::ConfigurationDialog *ui;
    QPushButton *restoreDefaultSettingsButton;
    ConfigurationManager *configManager;
};

#endif // CONFIGURATIONDIALOG_H
