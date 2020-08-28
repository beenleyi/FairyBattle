#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include "signup.h"
#include "battleform.h"
#include <QMainWindow>
extern client* user;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_signIn_pushButton_clicked();


    void on_signUp_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    signup *signUpForm;
    battleForm *myBattleForm;
public slots:
    void showForm();
};

#endif // MAINWINDOW_H
