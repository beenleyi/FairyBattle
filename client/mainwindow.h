#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include <QMainWindow>
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

    void on_signUp_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    client *user;
};

#endif // MAINWINDOW_H
