#include "mainwindow.h"
#include <QApplication>
client *user;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    user=new client;
    if(!user->connectToHost()) return 0;
    MainWindow w;
    w.show();

    return a.exec();
}
