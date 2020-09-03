#ifndef SIGNINFORM_H
#define SIGNINFORM_H
#include <QMessageBox>
#include <QJsonObject>
namespace Ui {
class signInForm;
}

class signInForm : public QWidget
{
    Q_OBJECT

public:
    explicit signInForm(QWidget *parent = 0);
    ~signInForm();
    QString* getUserName();
private slots:
    void on_signIn_pushButton_clicked();
    void on_signUp_pushButton_2_clicked();
    void signIn_passwordErr();
    void signIn_accountNotExist();
private:
    Ui::signInForm *ui;

public slots:
    void showForm();

signals:
    void sendMessageReq(QJsonObject*);
    void signUpReq();
};

#endif // MAINWINDOW_H
