#ifndef ROBOT_HAND_UI_H
#define ROBOT_HAND_UI_H

#include <QMainWindow>
#include "tcpcommunication_hand.h"
#include <QDebug>
#include <QPixmap>
#include <QBitmap>
#include "switch_button.h"
#include <QButtonGroup>
#include <QTimer>




QT_BEGIN_NAMESPACE
namespace Ui { class Robot_Hand_Ui; }
QT_END_NAMESPACE

static HumanHandParam hand_position;

class Robot_Hand_Ui : public QMainWindow
{
    Q_OBJECT

public:
    Robot_Hand_Ui(QWidget *parent = nullptr);
    ~Robot_Hand_Ui();

private:
    void judge_hand();
    void delay_1(int msec);
    void hand_9deg_dataUpdate(HumanHandParam hand_position);

    void hand_10deg_dataUpdate(HumanHandParam hand_position);

    void hand_16deg_dataUpdate(HumanHandParam hand_position);



private slots:
    void on_TCP_Connect_Start_clicked();

    void on_TCP_Connect_Stop_clicked();

    void on_Hand_Open_clicked();

    void on_Hand_Close_clicked();

    void on_read_data_clicked();



    void on_button_thumb_roll_clicked();

    void on_button_thumb_straight_clicked();

    void on_button_index_roll_clicked();

    void on_button_index_straight_clicked();

    void on_button_middle_roll_clicked();

    void on_button_middle_straight_clicked();

    void on_button_third_roll_clicked();

    void on_button_third_straight_clicked();

    void on_button_pinkie_roll_clicked();

    void on_button_pinkie_straight_clicked();

    void on_button_middle_swing_in_clicked();
    
    void on_button_thumb_swing_in_clicked();
    
    void on_button_thumb_swing_out_clicked();
    
    void on_button_index_swing_in_clicked();
    
    void on_button_index_swing_out_clicked();
    
    void on_button_middle_swing_out_clicked();
    
    void on_button_third_swing_in_clicked();
    
    void on_button_third_swing_out_clicked();
    
    void on_button_pinkie_swing_in_clicked();
    
    void on_button_pinkie_swing_out_clicked();



    void on_verticalSlider_thumb_swing_sliderMoved(int position);

    void on_verticalSlider_index_swing_sliderMoved(int position);

    void on_verticalSlider_middle_swing_sliderMoved(int position);

    void on_verticalSlider_third_swing_sliderMoved(int position);

    void on_verticalSlider_pinkie_swing_sliderMoved(int position);

    void on_verticalSlider_thumb_roll_sliderMoved(int position);

    void on_verticalSlider_index_roll_sliderMoved(int position);

    void on_verticalSlider_middle_roll_sliderMoved(int position);

    void on_verticalSlider_third_roll_sliderMoved(int position);

    void on_verticalSlider_pinkie_roll_sliderMoved(int position);

    void clickedSlot_switchBtn_left(bool state_bool, QString state_str);
    void clickedSlot_switchBtn_right(bool state_bool, QString state_str);
    void clickedSlot_switchBtn_9deg(bool state_bool, QString state_str);
    void clickedSlot_switchBtn_10deg(bool state_bool, QString state_str);
    void clickedSlot_switchBtn_16deg(bool state_bool, QString state_str);



    void on_verticalSlider_thumb_tip_sliderMoved(int position);

    void on_verticalSlider_index_tip_sliderMoved(int position);

    void on_verticalSlider_middle_tip_sliderMoved(int position);

    void on_verticalSlider_third_tip_sliderMoved(int position);

    void on_verticalSlider_pinkie_tip_sliderMoved(int position);

    void on_verticalSlider_thumb_rotation_sliderMoved(int position);

private:
    Ui::Robot_Hand_Ui *ui;
    TCPCommunication_Hand *Hand_Control = nullptr;
    QStringList columnheaders;
    QStringList rowheaders;
    bool hand_left;
    bool hand_right;
    bool hand_9deg;
    bool hand_10deg;
    bool hand_16deg;
    QWidget* switchBtn_left = nullptr;
    QWidget* switchBtn_right = nullptr;
    QWidget* switchBtn_9deg = nullptr;
    QWidget* switchBtn_10deg = nullptr;
    QWidget* switchBtn_16deg = nullptr;
    QTimer *timer = nullptr;

signals:






};
#endif // ROBOT_HAND_UI_H
