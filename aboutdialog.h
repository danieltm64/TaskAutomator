#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include "globals.h"
#include "configurationmanager.h"

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

protected:
    void showEvent(QShowEvent *);

private:
    Ui::AboutDialog *ui;
    ConfigurationManager *configManager;
};

#endif // ABOUTDIALOG_H
