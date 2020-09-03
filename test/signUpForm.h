#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QWidget>
#include <QJsonObject>
#include <QMessageBox>

namespace Ui {
class signUpForm;
}

class signUpForm : public QWidget
{
    Q_OBJECT

public:
    explicit signUpForm(QWidget *parent = 0);
    ~signUpForm();

private slots:
    void on_signIn_pushButton_clicked();
    void on_signUp_pushButton_clicked();
    void signUp_usernameExisted();

private:
    Ui::signUpForm *ui;
signals:
    void showSignInFormReq();
    void sendMessageReq(QJsonObject*);
};

#endif // SIGNUPFORM_H
