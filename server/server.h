#include <QTcpServer>
#include "socket.h"
class myTcpServer:public QTcpServer{
    Q_OBJECT
public:
    myTcpServer();
    //listen and return the connection num
    int startListen();
protected:
    virtual void incomingConnection(int socketDescriptor);
private:
    QList<myTcpSocket*> tcpSocketConnectedList;
private slots:
    void processDisconnect();
};
