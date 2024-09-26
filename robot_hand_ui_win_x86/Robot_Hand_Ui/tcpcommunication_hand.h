#ifndef TCPCOMMUNICATION_HAND_H
#define TCPCOMMUNICATION_HAND_H

#include <QObject>
#include <QTcpSocket>
#include <QDataStream>


typedef struct HumanHandParam  {
    float Joint1;  // 拇指1
    float Joint2;  // 拇指2
    float Joint3;  // 食指
    float Joint4;  // 中指
    float Joint5;  // 无名指
    float Joint6;  // 小拇指
    float Joint7;  // 食指和中指
    float Joint8;  // 中指和无名指
    float Joint9;  // 无名指和小拇指

    float Joint1_rotation; // 拇指旋转 —— 10自由度多余部分

    float Joint3_raw; // 中指左右运动 —— 16自由度多余部分
    float Joint1_tip; // 拇指末端弯曲度
    float Joint2_tip; // 食指末端弯曲度
    float Joint3_tip; // 中指末端弯曲度
    float Joint4_tip; // 无名指末端弯曲度
    float Joint5_tip; // 小拇指末端弯曲度
}HumanHandParam;

typedef struct HandForceParam
{
    float Joint1;
    float Joint2;
    float Joint3;
    float Joint4;
    float Joint5;
}HandForceParam;

typedef struct Hand_SendStruct
{
    uint8_t PowerOn;
    uint8_t Work_Mode;
    uint8_t Control_Mode;
    uint8_t Move_Control;

    uint8_t Hand_Freedom; // 机械手自由度
    uint8_t Retain1;
    uint8_t Retain2;
    uint8_t Retain3;

    HumanHandParam  Set_Point_RightHand;
    HumanHandParam  Set_Speed_RightHand;
    HumanHandParam  Set_Point_LeftHand;
    HumanHandParam  Set_Speed_LeftHand;
    HandForceParam  Set_Force_RightHand;
    HandForceParam  Set_Force_LeftHand;
}Hand_SendStruct;

typedef struct Hand_RecvStruct
{
    uint8_t       PowerOn_State;
    uint8_t       Work_State;
    uint8_t       Control_State;
    uint8_t       Retain;

    uint8_t       RightHand_MoveState;
    uint8_t       LeftHand_MoveState;
    uint16_t      Error_State;

    HumanHandParam  Get_CurrentPoint_RightHand;
    HumanHandParam  Get_CurrentPoint_LeftHand;

    HandForceParam  Get_CurrentForce_RightHand;
    HandForceParam  Get_CurrentForce_LeftHand;

    HumanHandParam  Get_CurrentPoint_RightGlove;
    HumanHandParam  Get_CurrentPoint_LeftGlove;
}Hand_RecvStruct;

typedef struct TCP_Hand_RecvData
{
    uint8_t       PowerOn_State;
    std::string   Work_State;
    std::string   Control_State;

    std::string   RightHand_MoveState;
    std::string   LeftHand_MoveState;
    uint16_t      Error_State;

    HumanHandParam  Get_CurrentPoint_RightHand;
    HumanHandParam  Get_CurrentPoint_LeftHand;

    HandForceParam  Get_CurrentForce_RightHand;
    HandForceParam  Get_CurrentForce_LeftHand;

    HumanHandParam  Get_CurrentPoint_RightGlove;
    HumanHandParam  Get_CurrentPoint_LeftGlove;
}TCP_Hand_RecvData;

/**
 *机械手通讯类：TCPCommunication_Hand
 * socket:TCP连接
 * force：设置机械手力
 * speed：设置机械手速度
 * position：设置机械手位置
 * senddata:发送控制机械手的数据
 */

class TCPCommunication_Hand : public QObject
{
    Q_OBJECT
public:
    explicit TCPCommunication_Hand(QObject *parent = nullptr);

    ~TCPCommunication_Hand();

public:
    ///TCP通讯连接
    QString Tcp_Connect(const QString IP, int port);
    ///TCP通讯断开
    bool Tcp_Disconnect();
    ///发送机械手自由度，类型，力，速度，位置
    void Hand_SendStructDataDeal(uint8_t Hand_Freedom, QString hand_type, HandForceParam force, HumanHandParam speed, HumanHandParam point);
    ///读取关节值
    Hand_RecvStruct read_hand_data(QString hand);
    ///延时函数
    void delay_1(int msec);
    uint8_t Hand_Freedom;
    HandForceParam force;
    HumanHandParam speed;
    HumanHandParam point;
    Hand_SendStruct senddata;
    Hand_RecvStruct readdata;
    TCP_Hand_RecvData readdata2;
    //TCP_Hand_RecvData readdata;
private:
    QTcpSocket *socket;


signals:

};

#endif // TCPCOMMUNICATION_HAND_H
