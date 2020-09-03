#include "signInForm.h"
#include <QApplication>
#include "client.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    client user;
    if(!user.connectToHost()) return 0;
    return a.exec();
}
