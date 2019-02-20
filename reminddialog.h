#ifndef REMINDDIALOG_H
#define REMINDDIALOG_H

#include <QDialog>
#include <QTime>

namespace Ui {
class RemindDialog;
}

class RemindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemindDialog(QWidget *parent, const QString &taskName, const QString &message);
    ~RemindDialog();

private:
    Ui::RemindDialog *ui;
};

#endif // REMINDDIALOG_H
