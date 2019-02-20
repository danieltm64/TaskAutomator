#include "configurationdialog.h"
#include "ui_configurationdialog.h"
#include "globals.h"

ConfigurationDialog::ConfigurationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigurationDialog)
{
    ui->setupUi(this);
    // add the restore default settings button to the button box
    restoreDefaultSettingsButton = ui->buttonBox->addButton(tr("Restore Default Settings"), QDialogButtonBox::ResetRole);
    // connecting to the click signal of the restore default settings button
    connect(restoreDefaultSettingsButton, SIGNAL(clicked()), this, SLOT(restoreDefaultSettings()));
    // set up the window so the user can't resize it and so that it adapts to the layout in case it gets resized programmatically
    window()->layout()->setSizeConstraint(QLayout::SetFixedSize);
    // making the reject button revert the configuration dialog to its previous state
    connect(this, SIGNAL(rejected()), this, SLOT(updateAllSettings()));
    // getting a pointer to the configuration manager
    configManager = ConfigurationManager::instance();
    // updating the configuration dialog according to the settings stored in the configuration manager
    updateAllSettings();
    // disabling user-visible options for default task settings
    /*
    ui->label_defaultTaskSettings->setVisible(false);
    ui->groupBox_defaultAction->setVisible(false);
    ui->groupBox_defaultDate->setVisible(false);
    ui->groupBox_defaultTime->setVisible(false);
    ui->label_generalSettings->setVisible(false);
    */
}

ConfigurationDialog::~ConfigurationDialog()
{
    delete ui;
}

void ConfigurationDialog::setDisplayToolbarChecked(bool checked)
{
    ui->checkBox_displayToolbar->setChecked(checked);
}

void ConfigurationDialog::updateAllSettings()
{
    // general settings
    ui->comboBox_language->setCurrentText(configManager->language());
    ui->comboBox_style->setCurrentIndex((int)(configManager->applicationStyle()));
    ui->checkBox_displayToolbar->setChecked(configManager->displayToolbar());
    ui->checkBox_alternateBackgroundColor->setChecked(configManager->alternateBackgroundColor());
    ui->checkBox_confirmToRemoveTasks->setChecked(configManager->confirmToRemoveTasks());
    ui->checkBox_confirmToExitProgram->setChecked(configManager->confirmToExitProgram());
    ui->checkBox_minimizeToSystemTray->setChecked(configManager->minimizeToSystemTray());
    ui->checkBox_closeToSystemTray->setChecked(configManager->closeToSystemTray());
    ui->checkBox_startAutomatically->setChecked(configManager->startAutomatically());
}

void ConfigurationDialog::restoreDefaultSettings()
{
    configManager->restoreDefaultSettings();
    updateAllSettings();
}

void ConfigurationDialog::on_buttonBox_accepted()
{
    configManager->startChanging();
    configManager->setLanguage(ui->comboBox_language->currentText());
    configManager->setApplicationStyle((styleName)(ui->comboBox_style->currentIndex()));
    configManager->setDisplayToolbar(ui->checkBox_displayToolbar->isChecked());
    configManager->setAlternateBackgroundColor(ui->checkBox_alternateBackgroundColor->isChecked());
    configManager->setConfirmToRemoveTasks(ui->checkBox_confirmToRemoveTasks->isChecked());
    configManager->setConfirmToExitProgram(ui->checkBox_confirmToExitProgram->isChecked());
    configManager->setMinimizeToSystemTray(ui->checkBox_minimizeToSystemTray->isChecked());
    configManager->setCloseToSystemTray(ui->checkBox_closeToSystemTray->isChecked());
    configManager->setStartAutomatically(ui->checkBox_startAutomatically->isChecked());
    configManager->saveConfiguration(); // TODO Check the order (a)
    configManager->stopChanging(); // TODO Check the order (b)
}
