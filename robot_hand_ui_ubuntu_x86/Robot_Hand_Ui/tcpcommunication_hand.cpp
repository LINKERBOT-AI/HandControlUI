#include "tcpcommunication_hand.h"
#include <QTimer>
#include <QEventLoop>

TCPCommunication_Hand::TCPCommunication_Hand(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    senddata.Hand_Freedom = 0;

    senddata.Set_Force_LeftHand.Joint1 = 0;
    senddata.Set_Force_LeftHand.Joint2 = 0;
    senddata.Set_Force_LeftHand.Joint3 = 0;
    senddata.Set_Force_LeftHand.Joint4 = 0;
    senddata.Set_Force_LeftHand.Joint5 = 0;

    senddata.Set_Force_RightHand.Joint1 = 0;
    senddata.Set_Force_RightHand.Joint2 = 0;
    senddata.Set_Force_RightHand.Joint3 = 0;
    senddata.Set_Force_RightHand.Joint4 = 0;
    senddata.Set_Force_RightHand.Joint5 = 0;

    senddata.Set_Speed_LeftHand.Joint1 = 0;
    senddata.Set_Speed_LeftHand.Joint2 = 0;
    senddata.Set_Speed_LeftHand.Joint3 = 0;
    senddata.Set_Speed_LeftHand.Joint4 = 0;
    senddata.Set_Speed_LeftHand.Joint5 = 0;
    senddata.Set_Speed_LeftHand.Joint6 = 0;
    senddata.Set_Speed_LeftHand.Joint7 = 0;
    senddata.Set_Speed_LeftHand.Joint8 = 0;
    senddata.Set_Speed_LeftHand.Joint9 = 0;
    senddata.Set_Speed_LeftHand.Joint1_tip = 0;
    senddata.Set_Speed_LeftHand.Joint2_tip = 0;
    senddata.Set_Speed_LeftHand.Joint3_tip = 0;
    senddata.Set_Speed_LeftHand.Joint4_tip = 0;
    senddata.Set_Speed_LeftHand.Joint5_tip = 0;
    senddata.Set_Speed_LeftHand.Joint1_rotation = 0;
    senddata.Set_Speed_LeftHand.Joint3_raw = 0;

    senddata.Set_Speed_RightHand.Joint1 = 0;
    senddata.Set_Speed_RightHand.Joint2 = 0;
    senddata.Set_Speed_RightHand.Joint3 = 0;
    senddata.Set_Speed_RightHand.Joint4 = 0;
    senddata.Set_Speed_RightHand.Joint5 = 0;
    senddata.Set_Speed_RightHand.Joint6 = 0;
    senddata.Set_Speed_RightHand.Joint7 = 0;
    senddata.Set_Speed_RightHand.Joint8 = 0;
    senddata.Set_Speed_RightHand.Joint9 = 0;
    senddata.Set_Speed_RightHand.Joint1_tip = 0;
    senddata.Set_Speed_RightHand.Joint2_tip = 0;
    senddata.Set_Speed_RightHand.Joint3_tip = 0;
    senddata.Set_Speed_RightHand.Joint4_tip = 0;
    senddata.Set_Speed_RightHand.Joint5_tip = 0;
    senddata.Set_Speed_RightHand.Joint1_rotation = 0;
    senddata.Set_Speed_RightHand.Joint3_raw = 0;

    senddata.Set_Point_LeftHand.Joint1 = 0;
    senddata.Set_Point_LeftHand.Joint2 = 0;
    senddata.Set_Point_LeftHand.Joint3 = 0;
    senddata.Set_Point_LeftHand.Joint4 = 0;
    senddata.Set_Point_LeftHand.Joint5 = 0;
    senddata.Set_Point_LeftHand.Joint6 = 0;
    senddata.Set_Point_LeftHand.Joint7 = 0;
    senddata.Set_Point_LeftHand.Joint8 = 0;
    senddata.Set_Point_LeftHand.Joint9 = 0;
    senddata.Set_Point_LeftHand.Joint1_tip = 0;
    senddata.Set_Point_LeftHand.Joint2_tip = 0;
    senddata.Set_Point_LeftHand.Joint3_tip = 0;
    senddata.Set_Point_LeftHand.Joint4_tip = 0;
    senddata.Set_Point_LeftHand.Joint5_tip = 0;
    senddata.Set_Point_LeftHand.Joint1_rotation = 0;
    senddata.Set_Point_LeftHand.Joint3_raw = 0;

    senddata.Set_Point_RightHand.Joint1 = 0;
    senddata.Set_Point_RightHand.Joint2 = 0;
    senddata.Set_Point_RightHand.Joint3 = 0;
    senddata.Set_Point_RightHand.Joint4 = 0;
    senddata.Set_Point_RightHand.Joint5 = 0;
    senddata.Set_Point_RightHand.Joint6 = 0;
    senddata.Set_Point_RightHand.Joint7 = 0;
    senddata.Set_Point_RightHand.Joint8 = 0;
    senddata.Set_Point_RightHand.Joint9 = 0;
    senddata.Set_Point_RightHand.Joint1_tip = 0;
    senddata.Set_Point_RightHand.Joint2_tip = 0;
    senddata.Set_Point_RightHand.Joint3_tip = 0;
    senddata.Set_Point_RightHand.Joint4_tip = 0;
    senddata.Set_Point_RightHand.Joint5_tip = 0;
    senddata.Set_Point_RightHand.Joint1_rotation = 0;
    senddata.Set_Point_RightHand.Joint3_raw = 0;

}

TCPCommunication_Hand::~TCPCommunication_Hand() {
    socket->close();
    delete socket;
    socket = nullptr;
}

void TCPCommunication_Hand::delay_1(int msec)//延时函数
{
    QEventLoop loop;//定义一个新的事件循环
    QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}

QString TCPCommunication_Hand::Tcp_Connect(const QString IP, int port) {

    socket->connectToHost(IP, port);
    if (socket->waitForConnected(3000)) {
        qDebug() << "Connect_successful";
        switch(socket->state()) {
            case QTcpSocket::UnconnectedState:
                qDebug() << "Unconnected";
                break;
            case QTcpSocket::HostLookupState:
                qDebug() << "HostLookup";
                break;
            case QTcpSocket::ConnectingState:
                qDebug() << "Connecting";
                break;
            case QTcpSocket::ConnectedState:
                qDebug() << "Connected";
                return "Connect_successful";
                break;
            case QTcpSocket::ListeningState:
                qDebug() << "Listening";
                break;
            case QTcpSocket::ClosingState:
                qDebug() << "Closing";
                break;
            default:
                qDebug() << "Unknown";
                break;
        }

    } else {
        switch(socket->state()) {
            case QTcpSocket::UnconnectedState:
                qDebug() << "Unconnected";
                return "Connect_false";
                break;
            case QTcpSocket::HostLookupState:
                qDebug() << "HostLookup";
                break;
            case QTcpSocket::ConnectingState:
                qDebug() << "Connecting";
                break;
            case QTcpSocket::ConnectedState:
                qDebug() << "Connected";
                break;
            case QTcpSocket::ListeningState:
                qDebug() << "Listening";
                break;
            case QTcpSocket::ClosingState:
                qDebug() << "Closing";
                break;
            default:
                qDebug() << "Unknown";
                break;
        }
        return "Connect_Failed";
    }
    return NULL;
}

bool TCPCommunication_Hand::Tcp_Disconnect() {
    //socket->close();
    /*socket->waitForDisconnected(30000);
    bool state = socket->disconnect();
    qDebug() << "state" << state;
    return state;*/
    socket->disconnectFromHost();
    if(socket->waitForDisconnected(30000)) {
        qDebug() << "Disconnected!";
    } else {
        qDebug() << "Disconnection failed!";

    }
    switch(socket->state()) {
        case QTcpSocket::UnconnectedState:
            qDebug() << "Unconnected";
            return true;
            break;
        case QTcpSocket::HostLookupState:
            qDebug() << "HostLookup";
            break;
        case QTcpSocket::ConnectingState:
            qDebug() << "Connecting";
            break;
        case QTcpSocket::ConnectedState:
            qDebug() << "Connected";

            break;
        case QTcpSocket::ListeningState:
            qDebug() << "Listening";
            break;
        case QTcpSocket::ClosingState:
            qDebug() << "Closing";
            break;
        default:
            qDebug() << "Unknown";
            break;
    }
    return false;
}
void TCPCommunication_Hand::Hand_SendStructDataDeal(uint8_t Hand_Freedom, QString hand_type,
                                                      HandForceParam force, HumanHandParam speed,
                                                     HumanHandParam point) {

  if (hand_type == "Left_Hand") {
      senddata.Hand_Freedom = Hand_Freedom;
      senddata.Set_Force_LeftHand = force;
      senddata.Set_Speed_LeftHand = speed;
      senddata.Set_Point_LeftHand = point;

      socket->write((const char*)&senddata, sizeof(Hand_SendStruct));

      socket -> waitForBytesWritten(3000);
      //socket -> waitForReadyRead(3000);
      QString response = socket -> readAll();
      qDebug() << "Received:" << response;
      if(socket->waitForReadyRead()) {
          qDebug() << "Data received!";
      } else {
          qDebug() << "No data received!";
      }

  }
  if (hand_type == "Right_Hand") {
      senddata.Hand_Freedom = Hand_Freedom;
      senddata.Set_Force_RightHand = force;
      senddata.Set_Speed_RightHand = speed;
      senddata.Set_Point_RightHand = point;

      socket->write((const char*)&senddata, sizeof(Hand_SendStruct));

      socket -> waitForBytesWritten(3000);
      //socket -> waitForReadyRead(3000);
      QString response = socket -> readAll();
      qDebug() << "Received:" << response;
      if(socket->waitForReadyRead()) {
          qDebug() << "Data received!";
      } else {
          qDebug() << "No data received!";
      }
  }

}

Hand_RecvStruct TCPCommunication_Hand::read_hand_data(QString hand) {
    if (hand == "Left_hand") {
        socket->write((const char*)&readdata, sizeof(Hand_RecvStruct));
        socket -> waitForBytesWritten();
        QByteArray dataArray = socket -> readAll();
        const Hand_RecvStruct* pData = (Hand_RecvStruct*)(dataArray.data());

        if(socket->waitForReadyRead(3000)) {
            qDebug() << "Data received!";
            qDebug() << "Received:" << dataArray;
            qDebug() << pData->Get_CurrentPoint_LeftHand.Joint1;
            qDebug() << pData->Get_CurrentPoint_LeftHand.Joint2;
            qDebug() << pData->Get_CurrentPoint_LeftHand.Joint3;
            qDebug() << pData->Get_CurrentPoint_LeftHand.Joint4;
            qDebug() << pData->Get_CurrentPoint_LeftHand.Joint5;
            qDebug() << pData->Get_CurrentPoint_LeftHand.Joint6;
            qDebug() << pData->Get_CurrentPoint_LeftHand.Joint7;
            qDebug() << pData->Get_CurrentPoint_LeftHand.Joint8;
            qDebug() << pData->Get_CurrentPoint_LeftHand.Joint9;
            qDebug() << pData->Get_CurrentPoint_LeftHand.Joint1_rotation;
        } else {
            qDebug() << "No data received!";

        }
        delay_1(100);
        socket->write((const char*)&readdata, sizeof(Hand_RecvStruct));
        socket -> waitForBytesWritten();
        QByteArray dataArray2 = socket -> readAll();
        const Hand_RecvStruct* pData2 = (Hand_RecvStruct*)(dataArray2.data());

        if(socket->waitForReadyRead(3000)) {
            qDebug() << "Data received!";
            qDebug() << "Received:" << dataArray;
            qDebug() << pData2->Get_CurrentPoint_LeftHand.Joint1;
            qDebug() << pData2->Get_CurrentPoint_LeftHand.Joint2;
            qDebug() << pData2->Get_CurrentPoint_LeftHand.Joint3;
            qDebug() << pData2->Get_CurrentPoint_LeftHand.Joint4;
            qDebug() << pData2->Get_CurrentPoint_LeftHand.Joint5;
            qDebug() << pData2->Get_CurrentPoint_LeftHand.Joint6;
            qDebug() << pData2->Get_CurrentPoint_LeftHand.Joint7;
            qDebug() << pData2->Get_CurrentPoint_LeftHand.Joint8;
            qDebug() << pData2->Get_CurrentPoint_LeftHand.Joint9;
            qDebug() << pData2->Get_CurrentPoint_LeftHand.Joint1_rotation;
        } else {
            qDebug() << "No data received!";

        }
        return *pData2;
    }
    if (hand == "Right_hand") {
        socket->write((const char*)&readdata, sizeof(Hand_RecvStruct));
        socket -> waitForBytesWritten();
        QByteArray dataArray = socket -> readAll();
        const Hand_RecvStruct* pData = (Hand_RecvStruct*)(dataArray.data());

        if(socket->waitForReadyRead(3000)) {
            qDebug() << "Data received!";
            qDebug() << "Received:" << dataArray;
            qDebug() << pData->Get_CurrentPoint_RightHand.Joint1;
            qDebug() << pData->Get_CurrentPoint_RightHand.Joint2;
            qDebug() << pData->Get_CurrentPoint_RightHand.Joint3;
            qDebug() << pData->Get_CurrentPoint_RightHand.Joint4;
            qDebug() << pData->Get_CurrentPoint_RightHand.Joint5;
            qDebug() << pData->Get_CurrentPoint_RightHand.Joint6;
            qDebug() << pData->Get_CurrentPoint_RightHand.Joint7;
            qDebug() << pData->Get_CurrentPoint_RightHand.Joint8;
            qDebug() << pData->Get_CurrentPoint_RightHand.Joint9;
            qDebug() << pData->Get_CurrentPoint_RightHand.Joint1_rotation;
        } else {
            qDebug() << "No data received!";

        }
        delay_1(100);
        socket->write((const char*)&readdata, sizeof(Hand_RecvStruct));
        socket -> waitForBytesWritten();
        QByteArray dataArray2 = socket -> readAll();
        const Hand_RecvStruct* pData2 = (Hand_RecvStruct*)(dataArray2.data());

        if(socket->waitForReadyRead(3000)) {
            qDebug() << "Data received!";
            qDebug() << "Received:" << dataArray;
            qDebug() << pData2->Get_CurrentPoint_RightHand.Joint1;
            qDebug() << pData2->Get_CurrentPoint_RightHand.Joint2;
            qDebug() << pData2->Get_CurrentPoint_RightHand.Joint3;
            qDebug() << pData2->Get_CurrentPoint_RightHand.Joint4;
            qDebug() << pData2->Get_CurrentPoint_RightHand.Joint5;
            qDebug() << pData2->Get_CurrentPoint_RightHand.Joint6;
            qDebug() << pData2->Get_CurrentPoint_RightHand.Joint7;
            qDebug() << pData2->Get_CurrentPoint_RightHand.Joint8;
            qDebug() << pData2->Get_CurrentPoint_RightHand.Joint9;
            qDebug() << pData2->Get_CurrentPoint_RightHand.Joint1_rotation;
        } else {
            qDebug() << "No data received!";

        }
        return *pData2;
    }
}


