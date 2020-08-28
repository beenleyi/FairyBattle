#ifndef BATTLEFORM_H
#define BATTLEFORM_H

#include <QWidget>

namespace Ui {
class battleForm;
}

class battleForm : public QWidget
{
    Q_OBJECT

public:
    explicit battleForm(QWidget *parent = 0);
    ~battleForm();

private slots:
    void on_upgradeBattle_pushButton_clicked();

    void on_signOut_pushButton_clicked();

private:
    Ui::battleForm *ui;
signals:
    void showSignInForm();
};

#endif // BATTLEFORM_H
