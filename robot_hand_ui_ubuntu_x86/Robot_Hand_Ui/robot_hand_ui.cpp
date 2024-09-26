#include "robot_hand_ui.h"
#include "ui_robot_hand_ui.h"

Robot_Hand_Ui::Robot_Hand_Ui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Robot_Hand_Ui)
{
    ui->setupUi(this);

    hand_left  = false;
    hand_right = false;
    hand_9deg  = false;
    hand_10deg = false;
    hand_16deg = false;
    ///创建TCP连接类对象
    Hand_Control = new TCPCommunication_Hand(this);

    //ui->verticalLayout_2->addSpacing(40);
    //ui->verticalLayout->addSpacing(20);

    //按钮外观设置
    QPixmap pix_allfinger_roll;
    pix_allfinger_roll.load(":/res/pic/slices/pic_left.png");
    ui->Hand_Close->setFixedSize(pix_allfinger_roll.size());
    ui->Hand_Close->setMask(pix_allfinger_roll.mask());

    QPixmap pix_allfinger_straight;
    pix_allfinger_straight.load(":/res/pic/slices/pic_right.png");
    ui->Hand_Open->setFixedSize(pix_allfinger_straight.size());
    ui->Hand_Open->setMask(pix_allfinger_straight.mask());

    ui->label_thumb->setStyleSheet("color: white");

    QPixmap pix_thumb_roll;
    pix_thumb_roll.load(":/res/pic/slices/pic_left.png");
    ui->button_thumb_roll->setFixedSize(pix_thumb_roll.size());
    ui->button_thumb_roll->setMask(pix_thumb_roll.mask());

    QPixmap pix_thumb_straight;
    pix_thumb_straight.load(":/res/pic/slices/pic_right.png");
    ui->button_thumb_straight->setFixedSize(pix_thumb_straight.size());
    ui->button_thumb_straight->setMask(pix_thumb_straight.mask());

    ui->label_thumb->setStyleSheet("color: white");

    QPixmap pix_index_roll;
    pix_index_roll.load(":/res/pic/slices/pic_left.png");
    ui->button_index_roll->setFixedSize(pix_index_roll.size());
    ui->button_index_roll->setMask(pix_index_roll.mask());

    QPixmap pix_index_straight;
    pix_index_straight.load(":/res/pic/slices/pic_right.png");
    ui->button_index_straight->setFixedSize(pix_index_straight.size());
    ui->button_index_straight->setMask(pix_index_straight.mask());

    QPixmap pix_middle_roll;
    pix_middle_roll.load(":/res/pic/slices/pic_left.png");
    ui->button_middle_roll->setFixedSize(pix_middle_roll.size());
    ui->button_middle_roll->setMask(pix_middle_roll.mask());

    QPixmap pix_middle_straight;
    pix_middle_straight.load(":/res/pic/slices/pic_right.png");
    ui->button_middle_straight->setFixedSize(pix_middle_straight.size());
    ui->button_middle_straight->setMask(pix_middle_straight.mask());

    QPixmap pix_third_roll;
    pix_third_roll.load(":/res/pic/slices/pic_left.png");
    ui->button_third_roll->setFixedSize(pix_third_roll.size());
    ui->button_third_roll->setMask(pix_third_roll.mask());

    QPixmap pix_third_straight;
    pix_third_straight.load(":/res/pic/slices/pic_right.png");
    ui->button_third_straight->setFixedSize(pix_third_straight.size());
    ui->button_third_straight->setMask(pix_third_straight.mask());


    QPixmap pix_pinkie_roll;
    pix_pinkie_roll.load(":/res/pic/slices/pic_left.png");
    ui->button_pinkie_roll->setFixedSize(pix_pinkie_roll.size());
    ui->button_pinkie_roll->setMask(pix_pinkie_roll.mask());

    QPixmap pix_pinkie_straight;
    pix_pinkie_straight.load(":/res/pic/slices/pic_right.png");
    ui->button_pinkie_straight->setFixedSize(pix_pinkie_straight.size());
    ui->button_pinkie_straight->setMask(pix_pinkie_straight.mask());

    ui->label_allfinger->setStyleSheet("color: white");
    ui->label_thumb->setStyleSheet("color: white");
    ui->label_index->setStyleSheet("color: white");
    ui->label_middle->setStyleSheet("color: white");
    ui->label_third->setStyleSheet("color: white");
    ui->label_pinkie->setStyleSheet("color: white");

    QPixmap pix_thumb_swing_in;
    pix_thumb_swing_in.load(":/res/pic/slices/pic_left.png");
    ui->button_thumb_swing_in->setFixedSize(pix_thumb_swing_in.size());
    ui->button_thumb_swing_in->setMask(pix_thumb_swing_in.mask());


    QPixmap pix_thumb_swing_out;
    pix_thumb_swing_out.load(":/res/pic/slices/pic_right.png");
    ui->button_thumb_swing_out->setFixedSize(pix_thumb_swing_out.size());
    ui->button_thumb_swing_out->setMask(pix_thumb_swing_out.mask());


    QPixmap pix_finger_swing_in;
    pix_finger_swing_in.load(":/res/pic/slices/pic_left.png");
    ui->button_index_swing_in->setFixedSize(pix_finger_swing_in.size());
    ui->button_index_swing_in->setMask(pix_finger_swing_in.mask());

    QPixmap pix_finger_swing_out;
    pix_finger_swing_out.load(":/res/pic/slices/pic_right.png");
    ui->button_index_swing_out->setFixedSize(pix_finger_swing_out.size());
    ui->button_index_swing_out->setMask(pix_finger_swing_out.mask());

    QPixmap pix_middle_swing_in;
    pix_middle_swing_in.load(":/res/pic/slices/pic_left.png");
    ui->button_middle_swing_in->setFixedSize(pix_middle_swing_in.size());
    ui->button_middle_swing_in->setMask(pix_middle_swing_in.mask());

    QPixmap pix_middle_swing_out;
    pix_middle_swing_out.load(":/res/pic/slices/pic_right.png");
    ui->button_middle_swing_out->setFixedSize(pix_middle_swing_out.size());
    ui->button_middle_swing_out->setMask(pix_middle_swing_out.mask());

    QPixmap pix_third_swing_in;
    pix_third_swing_in.load(":/res/pic/slices/pic_left.png");
    ui->button_third_swing_in->setFixedSize(pix_third_swing_in.size());
    ui->button_third_swing_in->setMask(pix_third_swing_in.mask());

    QPixmap pix_third_swing_out;
    pix_third_swing_out.load(":/res/pic/slices/pic_right.png");
    ui->button_third_swing_out->setFixedSize(pix_third_swing_out.size());
    ui->button_third_swing_out->setMask(pix_third_swing_out.mask());

    QPixmap pix_pinkie_swing_in;
    pix_pinkie_swing_in.load(":/res/pic/slices/pic_left.png");
    ui->button_pinkie_swing_in->setFixedSize(pix_pinkie_swing_in.size());
    ui->button_pinkie_swing_in->setMask(pix_pinkie_swing_in.mask());

    QPixmap pix_pinkie_swing_out;
    pix_pinkie_swing_out.load(":/res/pic/slices/pic_right.png");
    ui->button_pinkie_swing_out->setFixedSize(pix_pinkie_swing_out.size());
    ui->button_pinkie_swing_out->setMask(pix_pinkie_swing_out.mask());

    ///滑动条标签设置
    ui->label_thumb_swing->setStyleSheet("color: white");
    ui->label_index_swing->setStyleSheet("color: white");
    ui->label_middle_swing->setStyleSheet("color: white");
    ui->label_third_swing->setStyleSheet("color: white");
    ui->label_pinkie_swing->setStyleSheet("color: white");

    ui->label_thumb_swing_slider->setStyleSheet("color: white");
    ui->label_index_swing_slider->setStyleSheet("color: white");
    ui->label_middle_swing_slider->setStyleSheet("color: white");
    ui->label_third_swing_slider->setStyleSheet("color: white");
    ui->label_pinkie_swing_slider->setStyleSheet("color: white");

    ui->label_thumb_roll_slider->setStyleSheet("color: white");
    ui->label_index_roll_slider->setStyleSheet("color: white");
    ui->label_middle_roll_slider->setStyleSheet("color: white");
    ui->label_third_roll_slider->setStyleSheet("color: white");
    ui->label_pinkie_roll_slider->setStyleSheet("color: white");

    ui->label_thumb_tip_slider->setStyleSheet("color: white");
    ui->label_index_tip_slider->setStyleSheet("color: white");
    ui->label_middle_tip_slider->setStyleSheet("color: white");
    ui->label_third_tip_slider->setStyleSheet("color: white");
    ui->label_pinkie_tip_slider->setStyleSheet("color: white");

    ui->label_thumb_rotation_slider->setStyleSheet("color: white");

    ///滑动条外观设置
    ui->verticalSlider_thumb_roll->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#FFAB4F;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );
    ui->verticalSlider_index_roll->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#FFAB4F;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );
    ui->verticalSlider_middle_roll->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#FFAB4F;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );
    ui->verticalSlider_third_roll->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#FFAB4F;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );
    ui->verticalSlider_pinkie_roll->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#FFAB4F;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );

    ui->verticalSlider_thumb_swing->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#1F8EFA;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );
    ui->verticalSlider_index_swing->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#1F8EFA;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );
    ui->verticalSlider_middle_swing->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#1F8EFA;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );
    ui->verticalSlider_third_swing->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#1F8EFA;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );
    ui->verticalSlider_pinkie_swing->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#1F8EFA;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );
    ui->verticalSlider_thumb_tip->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#1F8EFA;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );
    ui->verticalSlider_index_tip->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#1F8EFA;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );
    ui->verticalSlider_middle_tip->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#1F8EFA;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );
    ui->verticalSlider_third_tip->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#1F8EFA;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );
    ui->verticalSlider_pinkie_tip->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#1F8EFA;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );
    ui->verticalSlider_thumb_rotation->setStyleSheet(
                                                 "QSlider::handle:vertical {"
                                                                "background: #FFFFFF;"
                                                                "border: 1px solid #FFAB4F;"
                                                                "width: 13px;"
                                                                "margin-left: -2px;"
                                                                "margin-right: -2px;"
                                                                "margin-bottom: 1px;"
                                                                "margin-top: 2px;"
                                                                "height: 13px;"
                                                                "border-radius: 4.5px;"
                                                                "border-style: outset;"
                                                                 "}"
                                                 "QSlider::groove{"
                                                                  "background-color:black;"
                                                                  "border: 1px solid #000;"
                                                                  "width: 9px;"
                                                                  "height: 168px;"
                                                                  "border-radius: 4.5px;"
                                                                 "}"
                                                 "QSlider::add-page:vertical {"
                                                                 "border-radius :4.5;"
                                                                 "background-color:#1F8EFA;"
                                                                 "}"
                                                 "QSlider::sub-page:vertical {"
                                                                 "border-radius :5;"
                                                                 "background-color:black;"
                                                                 "}"
                                                 );

    ///switch按钮对象创建，外观，位置设置
    switchBtn_left = new switch_Button("btn_value",ui->label_left_switch);
    switchBtn_left->show();
    switchBtn_left->move(68,15);
    connect(switchBtn_left, SIGNAL(clicked(bool,QString)), this, SLOT(clickedSlot_switchBtn_left(bool, QString)));


    switchBtn_right = new switch_Button("btn_value",ui->label_right_switch);
    switchBtn_right->show();
    switchBtn_right->move(68,15);
    connect(switchBtn_right, SIGNAL(clicked(bool,QString)), this, SLOT(clickedSlot_switchBtn_right(bool, QString)));

    switchBtn_9deg = new switch_Button("btn_value",ui->label_9deg_switch);
    switchBtn_9deg->show();
    switchBtn_9deg->move(90,15);
    connect(switchBtn_9deg, SIGNAL(clicked(bool,QString)), this, SLOT(clickedSlot_switchBtn_9deg(bool, QString)));

    switchBtn_10deg = new switch_Button("btn_value",ui->label_10deg_switch);
    switchBtn_10deg->show();
    switchBtn_10deg->move(90,15);
    connect(switchBtn_10deg, SIGNAL(clicked(bool,QString)), this, SLOT(clickedSlot_switchBtn_10deg(bool, QString)));

    switchBtn_16deg = new switch_Button("btn_value",ui->label_16deg_switch);
    switchBtn_16deg->show();
    switchBtn_16deg->move(90,15);
    connect(switchBtn_16deg, SIGNAL(clicked(bool,QString)), this, SLOT(clickedSlot_switchBtn_16deg(bool, QString)));


    ///switch按钮标签设置
    ui->label_left_switch->setStyleSheet("QLabel{border-image: url(:/res/pic/slices/switch_selected.png);}"
                                        "QLabel{color:#70889E}");
    ui->label_right_switch->setStyleSheet("QLabel{border-image: url(:/res/pic/slices/switch_selected.png);}"
                                        "QLabel{color:#70889E}");
    ui->label_9deg_switch->setStyleSheet("QLabel{border-image: url(:/res/pic/slices/switch_selected.png);}"
                                        "QLabel{color:#70889E}");
    ui->label_10deg_switch->setStyleSheet("QLabel{border-image: url(:/res/pic/slices/switch_selected.png);}"
                                        "QLabel{color:#70889E}");
    ui->label_16deg_switch->setStyleSheet("QLabel{border-image: url(:/res/pic/slices/switch_selected.png);}"
                                        "QLabel{color:#70889E}");
    ui->label_connect_state->setStyleSheet("QLabel{border-image: url(:/res/pic/slices/switch_selected.png);}"
                                        "QLabel{color:#70889E}");

    ///表格行数，列数，表头，外观设置
    ui->tableWidget_hand_data->setRowCount(4);
    ui->tableWidget_hand_data->setColumnCount(5);

    columnheaders<<"大拇指"<<"食指"<<"中指"<<"无名指"<<"小手指";
    rowheaders<<"弯曲位置参数"<<"侧摆位置参数"<<"指尖位置参数"<<"拇指纵摆参数";

    ui->tableWidget_hand_data->setHorizontalHeaderLabels(columnheaders);
    ui->tableWidget_hand_data->setVerticalHeaderLabels(rowheaders);

    ui->tableWidget_hand_data->setColumnWidth(0,115);
    ui->tableWidget_hand_data->setColumnWidth(1,115);
    ui->tableWidget_hand_data->setColumnWidth(2,115);
    ui->tableWidget_hand_data->setColumnWidth(3,115);
    ui->tableWidget_hand_data->setColumnWidth(4,115);

    ui->tableWidget_hand_data->setRowHeight(0,50);
    ui->tableWidget_hand_data->setRowHeight(1,50);
    ui->tableWidget_hand_data->setRowHeight(2,50);
    ui->tableWidget_hand_data->setRowHeight(3,50);
    ui->tableWidget_hand_data->setShowGrid(false);
    ui->tableWidget_hand_data->setStyleSheet("QTableWidget{border: 1px solid #2F3B52;}"
                                             "QTableView::item {border-bottom: 1px solid #20293C;}"
                                             "QHeaderView::section{background:#2F3B52;color:#70889E;}"
                                             "QTableView::item{background:#2F3B52; color:#FFFFFF}"
                                             "QHeaderView::section{border-top: none;border-left: none;border-right: none;border-bottom: 1px solid #20293C;}"
                                             "QHeaderView::section:horizontal {border-bottom:none}"
                                             );
    ///取消表格纵向和横向滑动条
    ui->tableWidget_hand_data->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget_hand_data->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    timer = new QTimer(this);
    QObject::connect(timer, &QTimer::timeout, [&] () {ui->label_connect_state->setHidden(! ui->label_connect_state->isHidden());
    delay_1(500);
    ui->label_connect_state->setHidden(false);
    });

    ui->frame->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_2->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_3->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_4->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_5->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_6->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_7->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_8->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_9->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_10->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_11->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_12->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_13->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_14->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_15->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_16->setStyleSheet("border: 2px solid #242E42;");
    ui->frame_17->setStyleSheet("border: 2px solid #242E42;");
    ui->label_thumb->setStyleSheet("border: 2px solid #2F3B52;color: white");
    ui->label_index->setStyleSheet("border: 2px solid #2F3B52;color: white");
    ui->label_middle->setStyleSheet("border: 2px solid #2F3B52;color: white");
    ui->label_third->setStyleSheet("border: 2px solid #2F3B52;color: white");
    ui->label_pinkie->setStyleSheet("border: 2px solid #2F3B52;color: white");
    ui->label_thumb_swing->setStyleSheet("border: 2px solid #2F3B52;color: white");
    ui->label_index_swing->setStyleSheet("border: 2px solid #2F3B52;color: white");
    ui->label_middle_swing->setStyleSheet("border: 2px solid #2F3B52;color: white");
    ui->label_third_swing->setStyleSheet("border: 2px solid #2F3B52;color: white");
    ui->label_pinkie_swing->setStyleSheet("border: 2px solid #2F3B52;color: white");
    ui->label_allfinger->setStyleSheet("border: 2px solid #2F3B52;color: white");

}

Robot_Hand_Ui::~Robot_Hand_Ui()
{
    delete Hand_Control;
    delete switchBtn_9deg;
    delete switchBtn_10deg;
    delete switchBtn_16deg;
    delete switchBtn_left;
    delete switchBtn_right;
    delete timer;


    Hand_Control = nullptr;
    switchBtn_9deg = nullptr;
    switchBtn_10deg = nullptr;
    switchBtn_16deg = nullptr;
    switchBtn_left = nullptr;
    switchBtn_right = nullptr;
    timer = nullptr;

    delete ui;
}

void Robot_Hand_Ui::delay_1(int msec)//延时函数
{
    QEventLoop loop;//定义一个新的事件循环
    QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}

void Robot_Hand_Ui::hand_9deg_dataUpdate(HumanHandParam hand_position) {
    ui->verticalSlider_thumb_roll->setValue(hand_position.Joint1);
    ui->verticalSlider_index_roll->setValue(hand_position.Joint3);
    ui->verticalSlider_middle_roll->setValue(hand_position.Joint4);
    ui->verticalSlider_third_roll->setValue(hand_position.Joint5);
    ui->verticalSlider_pinkie_roll->setValue(hand_position.Joint6);

    ui->verticalSlider_thumb_swing->setValue(hand_position.Joint2);
    ui->verticalSlider_index_swing->setValue(hand_position.Joint7);
    ui->verticalSlider_third_swing->setValue(hand_position.Joint8);
    ui->verticalSlider_pinkie_swing->setValue(hand_position.Joint9);

    ui->tableWidget_hand_data->setItem(0,0,new QTableWidgetItem(QString::number(hand_position.Joint1,'f',0)+"(joint1)"));
    ui->tableWidget_hand_data->setItem(0,1,new QTableWidgetItem(QString::number(hand_position.Joint3,'f',0)+"(joint3)"));
    ui->tableWidget_hand_data->setItem(0,2,new QTableWidgetItem(QString::number(hand_position.Joint4,'f',0)+"(joint4)"));
    ui->tableWidget_hand_data->setItem(0,3,new QTableWidgetItem(QString::number(hand_position.Joint5,'f',0)+"(joint5)"));
    ui->tableWidget_hand_data->setItem(0,4,new QTableWidgetItem(QString::number(hand_position.Joint6,'f',0)+"(joint6)"));
    ui->tableWidget_hand_data->setItem(1,0,new QTableWidgetItem(QString::number(hand_position.Joint2,'f',0)+"(joint2)"));
    ui->tableWidget_hand_data->setItem(1,1,new QTableWidgetItem(QString::number(hand_position.Joint7,'f',0)+"(joint7)"));
    ui->tableWidget_hand_data->setItem(1,3,new QTableWidgetItem(QString::number(hand_position.Joint8,'f',0)+"(joint8)"));
    ui->tableWidget_hand_data->setItem(1,4,new QTableWidgetItem(QString::number(hand_position.Joint9,'f',0)+"(joint9)"));


}

void Robot_Hand_Ui::hand_10deg_dataUpdate(HumanHandParam hand_position) {
    ui->verticalSlider_thumb_roll->setValue(hand_position.Joint1);
    ui->verticalSlider_index_roll->setValue(hand_position.Joint3);
    ui->verticalSlider_middle_roll->setValue(hand_position.Joint4);
    ui->verticalSlider_third_roll->setValue(hand_position.Joint5);
    ui->verticalSlider_pinkie_roll->setValue(hand_position.Joint6);

    ui->verticalSlider_thumb_swing->setValue(hand_position.Joint2);
    ui->verticalSlider_index_swing->setValue(hand_position.Joint7);
    ui->verticalSlider_third_swing->setValue(hand_position.Joint8);
    ui->verticalSlider_pinkie_swing->setValue(hand_position.Joint9);
    ui->verticalSlider_thumb_rotation->setValue(hand_position.Joint1_rotation);

    ui->tableWidget_hand_data->setItem(0,0,new QTableWidgetItem(QString::number(hand_position.Joint1,'f',0)+"(joint1)"));
    ui->tableWidget_hand_data->setItem(0,1,new QTableWidgetItem(QString::number(hand_position.Joint3,'f',0)+"(joint3)"));
    ui->tableWidget_hand_data->setItem(0,2,new QTableWidgetItem(QString::number(hand_position.Joint4,'f',0)+"(joint4)"));
    ui->tableWidget_hand_data->setItem(0,3,new QTableWidgetItem(QString::number(hand_position.Joint5,'f',0)+"(joint5)"));
    ui->tableWidget_hand_data->setItem(0,4,new QTableWidgetItem(QString::number(hand_position.Joint6,'f',0)+"(joint6)"));
    ui->tableWidget_hand_data->setItem(1,0,new QTableWidgetItem(QString::number(hand_position.Joint2,'f',0)+"(joint2)"));
    ui->tableWidget_hand_data->setItem(1,1,new QTableWidgetItem(QString::number(hand_position.Joint7,'f',0)+"(joint7)"));
    ui->tableWidget_hand_data->setItem(1,3,new QTableWidgetItem(QString::number(hand_position.Joint8,'f',0)+"(joint8)"));
    ui->tableWidget_hand_data->setItem(1,4,new QTableWidgetItem(QString::number(hand_position.Joint9,'f',0)+"(joint9)"));
    ui->tableWidget_hand_data->setItem(3,0,new QTableWidgetItem(QString::number(hand_position.Joint1_rotation,'f',0)+"(joint10)"));
}

void Robot_Hand_Ui::hand_16deg_dataUpdate(HumanHandParam hand_position) {
    ui->verticalSlider_thumb_roll->setValue(hand_position.Joint1);
    ui->verticalSlider_index_roll->setValue(hand_position.Joint3);
    ui->verticalSlider_middle_roll->setValue(hand_position.Joint4);
    ui->verticalSlider_third_roll->setValue(hand_position.Joint5);
    ui->verticalSlider_pinkie_roll->setValue(hand_position.Joint6);

    ui->verticalSlider_thumb_swing->setValue(hand_position.Joint2);
    ui->verticalSlider_index_swing->setValue(hand_position.Joint7);
    ui->verticalSlider_third_swing->setValue(hand_position.Joint8);
    ui->verticalSlider_pinkie_swing->setValue(hand_position.Joint9);
    ui->verticalSlider_thumb_rotation->setValue(hand_position.Joint1_rotation);

    ui->verticalSlider_thumb_tip->setValue(hand_position.Joint1_tip);
    ui->verticalSlider_index_tip->setValue(hand_position.Joint2_tip);
    ui->verticalSlider_middle_tip->setValue(hand_position.Joint3_tip);
    ui->verticalSlider_third_tip->setValue(hand_position.Joint4_tip);
    ui->verticalSlider_pinkie_tip->setValue(hand_position.Joint5_tip);

    ui->verticalSlider_middle_swing->setValue(hand_position.Joint3_raw);

    ui->tableWidget_hand_data->setItem(0,0,new QTableWidgetItem(QString::number(hand_position.Joint1,'f',0)+"(joint1)"));
    ui->tableWidget_hand_data->setItem(0,1,new QTableWidgetItem(QString::number(hand_position.Joint3,'f',0)+"(joint3)"));
    ui->tableWidget_hand_data->setItem(0,2,new QTableWidgetItem(QString::number(hand_position.Joint4,'f',0)+"(joint4)"));
    ui->tableWidget_hand_data->setItem(0,3,new QTableWidgetItem(QString::number(hand_position.Joint5,'f',0)+"(joint5)"));
    ui->tableWidget_hand_data->setItem(0,4,new QTableWidgetItem(QString::number(hand_position.Joint6,'f',0)+"(joint6)"));
    ui->tableWidget_hand_data->setItem(1,0,new QTableWidgetItem(QString::number(hand_position.Joint2,'f',0)+"(joint2)"));
    ui->tableWidget_hand_data->setItem(1,1,new QTableWidgetItem(QString::number(hand_position.Joint7,'f',0)+"(joint7)"));
    ui->tableWidget_hand_data->setItem(1,3,new QTableWidgetItem(QString::number(hand_position.Joint8,'f',0)+"(joint8)"));
    ui->tableWidget_hand_data->setItem(1,4,new QTableWidgetItem(QString::number(hand_position.Joint9,'f',0)+"(joint9)"));
    ui->tableWidget_hand_data->setItem(3,0,new QTableWidgetItem(QString::number(hand_position.Joint1_rotation,'f',0)+"(joint10)"));
    ui->tableWidget_hand_data->setItem(2,0,new QTableWidgetItem(QString::number(hand_position.Joint1_tip,'f',0)+"(tip1)"));
    ui->tableWidget_hand_data->setItem(2,1,new QTableWidgetItem(QString::number(hand_position.Joint2_tip,'f',0)+"(tip2)"));
    ui->tableWidget_hand_data->setItem(2,2,new QTableWidgetItem(QString::number(hand_position.Joint3_tip,'f',0)+"(tip3)"));
    ui->tableWidget_hand_data->setItem(2,3,new QTableWidgetItem(QString::number(hand_position.Joint4_tip,'f',0)+"(tip4)"));
    ui->tableWidget_hand_data->setItem(2,4,new QTableWidgetItem(QString::number(hand_position.Joint5_tip,'f',0)+"(tip5)"));
    ui->tableWidget_hand_data->setItem(1,2,new QTableWidgetItem(QString::number(hand_position.Joint3_raw,'f',0)+"(joint3_raw)"));
}


void Robot_Hand_Ui::judge_hand() {
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

}

void Robot_Hand_Ui::clickedSlot_switchBtn_left(bool state_bool, QString state_str) {
    qDebug() << "ok"<< state_bool << state_str +"left";
    hand_left = state_bool;
    if (state_bool == true) {
        switchBtn_right->setEnabled(false);

    } else if (state_bool == false) {
        switchBtn_right->setEnabled(true);
    }
}

void Robot_Hand_Ui::clickedSlot_switchBtn_right(bool state_bool, QString state_str) {
    qDebug() << "ok"<< state_bool << state_str + "right";
    hand_right = state_bool;
    if (state_bool == true) {
        switchBtn_left->setEnabled(false);

    } else if (state_bool == false) {
        switchBtn_left->setEnabled(true);
    }
}

void Robot_Hand_Ui::clickedSlot_switchBtn_9deg(bool state_bool, QString state_str) {
    qDebug() << "ok"<< state_bool << state_str + "9";
    hand_9deg = state_bool;
    if (state_bool == true) {
        switchBtn_10deg->setEnabled(false);
        switchBtn_16deg->setEnabled(false);
    } else if (state_bool == false) {
        switchBtn_10deg->setEnabled(true);
        switchBtn_16deg->setEnabled(true);
    }
}

void Robot_Hand_Ui::clickedSlot_switchBtn_10deg(bool state_bool, QString state_str) {
    qDebug() << "ok"<< state_bool << state_str + "10";
    hand_10deg = state_bool;
    if (state_bool == true) {
        switchBtn_9deg->setEnabled(false);
        switchBtn_16deg->setEnabled(false);
    } else if (state_bool == false) {
        switchBtn_9deg->setEnabled(true);
        switchBtn_16deg->setEnabled(true);
    }
}

void Robot_Hand_Ui::clickedSlot_switchBtn_16deg(bool state_bool, QString state_str) {
    qDebug() << "ok"<< state_bool << state_str+ "16";
    hand_16deg = state_bool;
    if (state_bool == true) {
        switchBtn_9deg->setEnabled(false);
        switchBtn_10deg->setEnabled(false);
    } else if (state_bool == false) {
        switchBtn_9deg->setEnabled(true);
        switchBtn_10deg->setEnabled(true);
    }
}

void Robot_Hand_Ui::on_TCP_Connect_Start_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }
    if (hand_left_9deg == true || hand_left_10deg == true || hand_left_16deg == true
            || hand_right_9deg == true || hand_right_10deg == true || hand_right_16deg == true) {
        QString connect_result = Hand_Control->Tcp_Connect("192.168.11.40", 20008);
        qDebug() << "connect_result" << connect_result;
        if (connect_result == "Connect_successful") {
            ui->label_connect_state->setText("连接成功");
        } else {
            ui->label_connect_state->setText("连接失败");
            return;
        }
    } else {
        ui->label_connect_state->setText("请先选择手");
        timer->start();
        delay_1(100);
        timer->stop();
        ui->label_connect_state->setText("请先选择手");
        return;
    }


    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point = Hand_Control->read_hand_data("Left_hand");
        hand_position.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        hand_position.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        hand_position.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        hand_position.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        hand_position.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        hand_position.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        hand_position.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        hand_position.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        hand_position.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;

        ui->verticalSlider_thumb_roll->setValue(hand_position.Joint1);
        ui->verticalSlider_index_roll->setValue(hand_position.Joint3);
        ui->verticalSlider_middle_roll->setValue(hand_position.Joint4);
        ui->verticalSlider_third_roll->setValue(hand_position.Joint5);
        ui->verticalSlider_pinkie_roll->setValue(hand_position.Joint6);

        ui->verticalSlider_thumb_swing->setValue(hand_position.Joint2);
        ui->verticalSlider_index_swing->setValue(hand_position.Joint7);
        ui->verticalSlider_third_swing->setValue(hand_position.Joint8);
        ui->verticalSlider_pinkie_swing->setValue(hand_position.Joint9);

        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        ui->tableWidget_hand_data->setItem(0,0,new QTableWidgetItem(QString::number(hand_position.Joint1,'f',0)+"(joint1)"));
        ui->tableWidget_hand_data->setItem(0,1,new QTableWidgetItem(QString::number(hand_position.Joint3,'f',0)+"(joint3)"));
        ui->tableWidget_hand_data->setItem(0,2,new QTableWidgetItem(QString::number(hand_position.Joint4,'f',0)+"(joint4)"));
        ui->tableWidget_hand_data->setItem(0,3,new QTableWidgetItem(QString::number(hand_position.Joint5,'f',0)+"(joint5)"));
        ui->tableWidget_hand_data->setItem(0,4,new QTableWidgetItem(QString::number(hand_position.Joint6,'f',0)+"(joint6)"));
        ui->tableWidget_hand_data->setItem(1,0,new QTableWidgetItem(QString::number(hand_position.Joint2,'f',0)+"(joint2)"));
        ui->tableWidget_hand_data->setItem(1,1,new QTableWidgetItem(QString::number(hand_position.Joint7,'f',0)+"(joint7)"));
        ui->tableWidget_hand_data->setItem(1,3,new QTableWidgetItem(QString::number(hand_position.Joint8,'f',0)+"(joint8)"));
        ui->tableWidget_hand_data->setItem(1,4,new QTableWidgetItem(QString::number(hand_position.Joint9,'f',0)+"(joint9)"));

    }
    if (hand_right_9deg == true) {
        Hand_RecvStruct thumb_point = Hand_Control->read_hand_data("Right_hand");
        hand_position.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
        hand_position.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
        hand_position.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
        hand_position.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
        hand_position.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
        hand_position.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
        hand_position.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
        hand_position.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
        hand_position.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;

        ui->verticalSlider_thumb_roll->setValue(hand_position.Joint1);
        ui->verticalSlider_index_roll->setValue(hand_position.Joint3);
        ui->verticalSlider_middle_roll->setValue(hand_position.Joint4);
        ui->verticalSlider_third_roll->setValue(hand_position.Joint5);
        ui->verticalSlider_pinkie_roll->setValue(hand_position.Joint6);

        ui->verticalSlider_thumb_swing->setValue(hand_position.Joint2);
        ui->verticalSlider_index_swing->setValue(hand_position.Joint7);
        ui->verticalSlider_third_swing->setValue(hand_position.Joint8);
        ui->verticalSlider_pinkie_swing->setValue(hand_position.Joint9);

        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;

        ui->tableWidget_hand_data->setItem(0,0,new QTableWidgetItem(QString::number(hand_position.Joint1,'f',0)+"(joint1)"));
        ui->tableWidget_hand_data->setItem(0,1,new QTableWidgetItem(QString::number(hand_position.Joint3,'f',0)+"(joint3)"));
        ui->tableWidget_hand_data->setItem(0,2,new QTableWidgetItem(QString::number(hand_position.Joint4,'f',0)+"(joint4)"));
        ui->tableWidget_hand_data->setItem(0,3,new QTableWidgetItem(QString::number(hand_position.Joint5,'f',0)+"(joint5)"));
        ui->tableWidget_hand_data->setItem(0,4,new QTableWidgetItem(QString::number(hand_position.Joint6,'f',0)+"(joint6)"));
        ui->tableWidget_hand_data->setItem(1,0,new QTableWidgetItem(QString::number(hand_position.Joint2,'f',0)+"(joint2)"));
        ui->tableWidget_hand_data->setItem(1,1,new QTableWidgetItem(QString::number(hand_position.Joint7,'f',0)+"(joint7)"));
        ui->tableWidget_hand_data->setItem(1,3,new QTableWidgetItem(QString::number(hand_position.Joint8,'f',0)+"(joint8)"));
        ui->tableWidget_hand_data->setItem(1,4,new QTableWidgetItem(QString::number(hand_position.Joint9,'f',0)+"(joint9)"));

    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point = Hand_Control->read_hand_data("Left_hand");
        hand_position.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        hand_position.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        hand_position.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        hand_position.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        hand_position.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        hand_position.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        hand_position.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        hand_position.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        hand_position.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        hand_position.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        ui->verticalSlider_thumb_roll->setValue(hand_position.Joint1);
        ui->verticalSlider_index_roll->setValue(hand_position.Joint3);
        ui->verticalSlider_middle_roll->setValue(hand_position.Joint4);
        ui->verticalSlider_third_roll->setValue(hand_position.Joint5);
        ui->verticalSlider_pinkie_roll->setValue(hand_position.Joint6);

        ui->verticalSlider_thumb_swing->setValue(hand_position.Joint2);
        ui->verticalSlider_index_swing->setValue(hand_position.Joint7);
        ui->verticalSlider_third_swing->setValue(hand_position.Joint8);
        ui->verticalSlider_pinkie_swing->setValue(hand_position.Joint9);
        ui->verticalSlider_thumb_rotation->setValue(hand_position.Joint1_rotation);

        ui->tableWidget_hand_data->setItem(0,0,new QTableWidgetItem(QString::number(hand_position.Joint1,'f',0)+"(joint1)"));
        ui->tableWidget_hand_data->setItem(0,1,new QTableWidgetItem(QString::number(hand_position.Joint3,'f',0)+"(joint3)"));
        ui->tableWidget_hand_data->setItem(0,2,new QTableWidgetItem(QString::number(hand_position.Joint4,'f',0)+"(joint4)"));
        ui->tableWidget_hand_data->setItem(0,3,new QTableWidgetItem(QString::number(hand_position.Joint5,'f',0)+"(joint5)"));
        ui->tableWidget_hand_data->setItem(0,4,new QTableWidgetItem(QString::number(hand_position.Joint6,'f',0)+"(joint6)"));
        ui->tableWidget_hand_data->setItem(1,0,new QTableWidgetItem(QString::number(hand_position.Joint2,'f',0)+"(joint2)"));
        ui->tableWidget_hand_data->setItem(1,1,new QTableWidgetItem(QString::number(hand_position.Joint7,'f',0)+"(joint7)"));
        ui->tableWidget_hand_data->setItem(1,3,new QTableWidgetItem(QString::number(hand_position.Joint8,'f',0)+"(joint8)"));
        ui->tableWidget_hand_data->setItem(1,4,new QTableWidgetItem(QString::number(hand_position.Joint9,'f',0)+"(joint9)"));
        ui->tableWidget_hand_data->setItem(3,0,new QTableWidgetItem(QString::number(hand_position.Joint1_rotation,'f',0)+"(joint10)"));
    }
    if (hand_right_10deg == true) {
        Hand_RecvStruct thumb_point = Hand_Control->read_hand_data("Right_hand");
        hand_position.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
        hand_position.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
        hand_position.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
        hand_position.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
        hand_position.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
        hand_position.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
        hand_position.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
        hand_position.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
        hand_position.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
        hand_position.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

        ui->verticalSlider_thumb_roll->setValue(hand_position.Joint1);
        ui->verticalSlider_index_roll->setValue(hand_position.Joint3);
        ui->verticalSlider_middle_roll->setValue(hand_position.Joint4);
        ui->verticalSlider_third_roll->setValue(hand_position.Joint5);
        ui->verticalSlider_pinkie_roll->setValue(hand_position.Joint6);

        ui->verticalSlider_thumb_swing->setValue(hand_position.Joint2);
        ui->verticalSlider_index_swing->setValue(hand_position.Joint7);
        ui->verticalSlider_third_swing->setValue(hand_position.Joint8);
        ui->verticalSlider_pinkie_swing->setValue(hand_position.Joint9);
        ui->verticalSlider_thumb_rotation->setValue(hand_position.Joint1_rotation);

        ui->tableWidget_hand_data->setItem(0,0,new QTableWidgetItem(QString::number(hand_position.Joint1,'f',0)+"(joint1)"));
        ui->tableWidget_hand_data->setItem(0,1,new QTableWidgetItem(QString::number(hand_position.Joint3,'f',0)+"(joint3)"));
        ui->tableWidget_hand_data->setItem(0,2,new QTableWidgetItem(QString::number(hand_position.Joint4,'f',0)+"(joint4)"));
        ui->tableWidget_hand_data->setItem(0,3,new QTableWidgetItem(QString::number(hand_position.Joint5,'f',0)+"(joint5)"));
        ui->tableWidget_hand_data->setItem(0,4,new QTableWidgetItem(QString::number(hand_position.Joint6,'f',0)+"(joint6)"));
        ui->tableWidget_hand_data->setItem(1,0,new QTableWidgetItem(QString::number(hand_position.Joint2,'f',0)+"(joint2)"));
        ui->tableWidget_hand_data->setItem(1,1,new QTableWidgetItem(QString::number(hand_position.Joint7,'f',0)+"(joint7)"));
        ui->tableWidget_hand_data->setItem(1,3,new QTableWidgetItem(QString::number(hand_position.Joint8,'f',0)+"(joint8)"));
        ui->tableWidget_hand_data->setItem(1,4,new QTableWidgetItem(QString::number(hand_position.Joint9,'f',0)+"(joint9)"));
        ui->tableWidget_hand_data->setItem(3,0,new QTableWidgetItem(QString::number(hand_position.Joint1_rotation,'f',0)+"(joint10)"));
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point = Hand_Control->read_hand_data("Left_hand");
        hand_position.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        hand_position.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        hand_position.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        hand_position.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        hand_position.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        hand_position.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        hand_position.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        hand_position.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        hand_position.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        hand_position.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        hand_position.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        hand_position.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        hand_position.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        hand_position.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        hand_position.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        hand_position.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        ui->verticalSlider_thumb_roll->setValue(hand_position.Joint1);
        ui->verticalSlider_index_roll->setValue(hand_position.Joint3);
        ui->verticalSlider_middle_roll->setValue(hand_position.Joint4);
        ui->verticalSlider_third_roll->setValue(hand_position.Joint5);
        ui->verticalSlider_pinkie_roll->setValue(hand_position.Joint6);

        ui->verticalSlider_thumb_swing->setValue(hand_position.Joint2);
        ui->verticalSlider_index_swing->setValue(hand_position.Joint7);
        ui->verticalSlider_third_swing->setValue(hand_position.Joint8);
        ui->verticalSlider_pinkie_swing->setValue(hand_position.Joint9);
        ui->verticalSlider_thumb_rotation->setValue(hand_position.Joint1_rotation);

        ui->verticalSlider_thumb_tip->setValue(hand_position.Joint1_tip);
        ui->verticalSlider_index_tip->setValue(hand_position.Joint2_tip);
        ui->verticalSlider_middle_tip->setValue(hand_position.Joint3_tip);
        ui->verticalSlider_third_tip->setValue(hand_position.Joint4_tip);
        ui->verticalSlider_pinkie_tip->setValue(hand_position.Joint5_tip);

        ui->verticalSlider_middle_swing->setValue(hand_position.Joint3_raw);

        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        qDebug() << "joint1_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        qDebug() << "joint2_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        qDebug() << "joint3_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        qDebug() << "joint4_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        qDebug() << "joint5_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        qDebug() << "joint3_raw" << thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        ui->tableWidget_hand_data->setItem(0,0,new QTableWidgetItem(QString::number(hand_position.Joint1,'f',0)+"(joint1)"));
        ui->tableWidget_hand_data->setItem(0,1,new QTableWidgetItem(QString::number(hand_position.Joint3,'f',0)+"(joint3)"));
        ui->tableWidget_hand_data->setItem(0,2,new QTableWidgetItem(QString::number(hand_position.Joint4,'f',0)+"(joint4)"));
        ui->tableWidget_hand_data->setItem(0,3,new QTableWidgetItem(QString::number(hand_position.Joint5,'f',0)+"(joint5)"));
        ui->tableWidget_hand_data->setItem(0,4,new QTableWidgetItem(QString::number(hand_position.Joint6,'f',0)+"(joint6)"));
        ui->tableWidget_hand_data->setItem(1,0,new QTableWidgetItem(QString::number(hand_position.Joint2,'f',0)+"(joint2)"));
        ui->tableWidget_hand_data->setItem(1,1,new QTableWidgetItem(QString::number(hand_position.Joint7,'f',0)+"(joint7)"));
        ui->tableWidget_hand_data->setItem(1,3,new QTableWidgetItem(QString::number(hand_position.Joint8,'f',0)+"(joint8)"));
        ui->tableWidget_hand_data->setItem(1,4,new QTableWidgetItem(QString::number(hand_position.Joint9,'f',0)+"(joint9)"));
        ui->tableWidget_hand_data->setItem(3,0,new QTableWidgetItem(QString::number(hand_position.Joint1_rotation,'f',0)+"(joint10)"));
        ui->tableWidget_hand_data->setItem(2,0,new QTableWidgetItem(QString::number(hand_position.Joint1_tip,'f',0)+"(tip1)"));
        ui->tableWidget_hand_data->setItem(2,1,new QTableWidgetItem(QString::number(hand_position.Joint2_tip,'f',0)+"(tip2)"));
        ui->tableWidget_hand_data->setItem(2,2,new QTableWidgetItem(QString::number(hand_position.Joint3_tip,'f',0)+"(tip3)"));
        ui->tableWidget_hand_data->setItem(2,3,new QTableWidgetItem(QString::number(hand_position.Joint4_tip,'f',0)+"(tip4)"));
        ui->tableWidget_hand_data->setItem(2,4,new QTableWidgetItem(QString::number(hand_position.Joint5_tip,'f',0)+"(tip5)"));
        ui->tableWidget_hand_data->setItem(1,2,new QTableWidgetItem(QString::number(hand_position.Joint3_raw,'f',0)+"(joint3_raw)"));

    }
    if (hand_right_16deg == true) {
        Hand_RecvStruct thumb_point = Hand_Control->read_hand_data("Right_hand");
        hand_position.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
        hand_position.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
        hand_position.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
        hand_position.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
        hand_position.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
        hand_position.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
        hand_position.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
        hand_position.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
        hand_position.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
        hand_position.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        hand_position.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
        hand_position.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
        hand_position.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
        hand_position.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
        hand_position.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
        hand_position.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
        qDebug() << "joint1_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
        qDebug() << "joint2_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
        qDebug() << "joint3_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
        qDebug() << "joint4_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
        qDebug() << "joint5_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
        qDebug() << "joint3_raw" << thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

        ui->verticalSlider_thumb_roll->setValue(hand_position.Joint1);
        ui->verticalSlider_index_roll->setValue(hand_position.Joint3);
        ui->verticalSlider_middle_roll->setValue(hand_position.Joint4);
        ui->verticalSlider_third_roll->setValue(hand_position.Joint5);
        ui->verticalSlider_pinkie_roll->setValue(hand_position.Joint6);

        ui->verticalSlider_thumb_swing->setValue(hand_position.Joint2);
        ui->verticalSlider_index_swing->setValue(hand_position.Joint7);
        ui->verticalSlider_third_swing->setValue(hand_position.Joint8);
        ui->verticalSlider_pinkie_swing->setValue(hand_position.Joint9);
        ui->verticalSlider_thumb_rotation->setValue(hand_position.Joint1_rotation);

        ui->verticalSlider_thumb_tip->setValue(hand_position.Joint1_tip);
        ui->verticalSlider_index_tip->setValue(hand_position.Joint2_tip);
        ui->verticalSlider_middle_tip->setValue(hand_position.Joint3_tip);
        ui->verticalSlider_third_tip->setValue(hand_position.Joint4_tip);
        ui->verticalSlider_pinkie_tip->setValue(hand_position.Joint5_tip);

        ui->verticalSlider_middle_swing->setValue(hand_position.Joint3_raw);

        ui->tableWidget_hand_data->setItem(0,0,new QTableWidgetItem(QString::number(hand_position.Joint1,'f',0)+"(joint1)"));
        ui->tableWidget_hand_data->setItem(0,1,new QTableWidgetItem(QString::number(hand_position.Joint3,'f',0)+"(joint3)"));
        ui->tableWidget_hand_data->setItem(0,2,new QTableWidgetItem(QString::number(hand_position.Joint4,'f',0)+"(joint4)"));
        ui->tableWidget_hand_data->setItem(0,3,new QTableWidgetItem(QString::number(hand_position.Joint5,'f',0)+"(joint5)"));
        ui->tableWidget_hand_data->setItem(0,4,new QTableWidgetItem(QString::number(hand_position.Joint6,'f',0)+"(joint6)"));
        ui->tableWidget_hand_data->setItem(1,0,new QTableWidgetItem(QString::number(hand_position.Joint2,'f',0)+"(joint2)"));
        ui->tableWidget_hand_data->setItem(1,1,new QTableWidgetItem(QString::number(hand_position.Joint7,'f',0)+"(joint7)"));
        ui->tableWidget_hand_data->setItem(1,3,new QTableWidgetItem(QString::number(hand_position.Joint8,'f',0)+"(joint8)"));
        ui->tableWidget_hand_data->setItem(1,4,new QTableWidgetItem(QString::number(hand_position.Joint9,'f',0)+"(joint9)"));
        ui->tableWidget_hand_data->setItem(3,0,new QTableWidgetItem(QString::number(hand_position.Joint1_rotation,'f',0)+"(joint10)"));
        ui->tableWidget_hand_data->setItem(2,0,new QTableWidgetItem(QString::number(hand_position.Joint1_tip,'f',0)+"(tip1)"));
        ui->tableWidget_hand_data->setItem(2,1,new QTableWidgetItem(QString::number(hand_position.Joint2_tip,'f',0)+"(tip2)"));
        ui->tableWidget_hand_data->setItem(2,2,new QTableWidgetItem(QString::number(hand_position.Joint3_tip,'f',0)+"(tip3)"));
        ui->tableWidget_hand_data->setItem(2,3,new QTableWidgetItem(QString::number(hand_position.Joint4_tip,'f',0)+"(tip4)"));
        ui->tableWidget_hand_data->setItem(2,4,new QTableWidgetItem(QString::number(hand_position.Joint5_tip,'f',0)+"(tip5)"));
        ui->tableWidget_hand_data->setItem(1,2,new QTableWidgetItem(QString::number(hand_position.Joint3_raw,'f',0)+"(joint3_raw)"));
    }
}


void Robot_Hand_Ui::on_TCP_Connect_Stop_clicked()
{
    bool state = Hand_Control->Tcp_Disconnect();
    if (state == true) {
        qDebug() << "disconnect_successful";
        ui->label_connect_state->setText("断开成功");
    }



}

void Robot_Hand_Ui::on_Hand_Open_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {

        Hand_Control->Hand_Freedom = 9;

        Hand_Control->force.Joint1 = 240;
        Hand_Control->force.Joint2 = 240;
        Hand_Control->force.Joint3 = 240;
        Hand_Control->force.Joint4 = 240;
        Hand_Control->force.Joint5 = 240;

        Hand_Control->speed.Joint1 = 1;
        Hand_Control->speed.Joint2 = 1;
        Hand_Control->speed.Joint3 = 1;
        Hand_Control->speed.Joint4 = 1;
        Hand_Control->speed.Joint5 = 1;
        Hand_Control->speed.Joint6 = 1;
        Hand_Control->speed.Joint7 = 1;
        Hand_Control->speed.Joint8 = 1;
        Hand_Control->speed.Joint9 = 1;
        Hand_Control->speed.Joint1_tip = 1;
        Hand_Control->speed.Joint2_tip = 1;
        Hand_Control->speed.Joint3_tip = 1;
        Hand_Control->speed.Joint4_tip = 1;
        Hand_Control->speed.Joint5_tip = 1;
        Hand_Control->speed.Joint1_rotation = 1;
        Hand_Control->speed.Joint3_raw = 1;

        Hand_Control->point.Joint1 = 240;
        Hand_Control->point.Joint2 = 240;
        Hand_Control->point.Joint3 = 240;
        Hand_Control->point.Joint4 = 240;
        Hand_Control->point.Joint5 = 240;
        Hand_Control->point.Joint6 = 240;
        Hand_Control->point.Joint7 = 240;
        Hand_Control->point.Joint8 = 240;
        Hand_Control->point.Joint9 = 240;
        Hand_Control->point.Joint1_tip = 240;
        Hand_Control->point.Joint2_tip = 240;
        Hand_Control->point.Joint3_tip = 240;
        Hand_Control->point.Joint4_tip = 240;
        Hand_Control->point.Joint5_tip = 240;
        Hand_Control->point.Joint1_rotation = 240;
        Hand_Control->point.Joint3_raw = 240;

        hand_position = Hand_Control->point;


        Hand_Control->Hand_SendStructDataDeal(Hand_Control -> Hand_Freedom, "Left_Hand", Hand_Control -> force, Hand_Control -> speed, Hand_Control -> point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {

        Hand_Control->Hand_Freedom = 9;

        Hand_Control->force.Joint1 = 240;
        Hand_Control->force.Joint2 = 240;
        Hand_Control->force.Joint3 = 240;
        Hand_Control->force.Joint4 = 240;
        Hand_Control->force.Joint5 = 240;

        Hand_Control->speed.Joint1 = 1;
        Hand_Control->speed.Joint2 = 1;
        Hand_Control->speed.Joint3 = 1;
        Hand_Control->speed.Joint4 = 1;
        Hand_Control->speed.Joint5 = 1;
        Hand_Control->speed.Joint6 = 1;
        Hand_Control->speed.Joint7 = 1;
        Hand_Control->speed.Joint8 = 1;
        Hand_Control->speed.Joint9 = 1;
        Hand_Control->speed.Joint1_tip = 1;
        Hand_Control->speed.Joint2_tip = 1;
        Hand_Control->speed.Joint3_tip = 1;
        Hand_Control->speed.Joint4_tip = 1;
        Hand_Control->speed.Joint5_tip = 1;
        Hand_Control->speed.Joint1_rotation = 1;
        Hand_Control->speed.Joint3_raw = 1;

        Hand_Control->point.Joint1 = 240;
        Hand_Control->point.Joint2 = 240;
        Hand_Control->point.Joint3 = 240;
        Hand_Control->point.Joint4 = 240;
        Hand_Control->point.Joint5 = 240;
        Hand_Control->point.Joint6 = 240;
        Hand_Control->point.Joint7 = 240;
        Hand_Control->point.Joint8 = 240;
        Hand_Control->point.Joint9 = 240;
        Hand_Control->point.Joint1_tip = 240;
        Hand_Control->point.Joint2_tip = 240;
        Hand_Control->point.Joint3_tip = 240;
        Hand_Control->point.Joint4_tip = 240;
        Hand_Control->point.Joint5_tip = 240;
        Hand_Control->point.Joint1_rotation = 240;
        Hand_Control->point.Joint3_raw = 240;

        hand_position = Hand_Control->point;

        Hand_Control->Hand_SendStructDataDeal(Hand_Control -> Hand_Freedom, "Right_Hand", Hand_Control -> force, Hand_Control -> speed, Hand_Control -> point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {

        Hand_Control->Hand_Freedom = 10;

        Hand_Control->force.Joint1 = 240;
        Hand_Control->force.Joint2 = 240;
        Hand_Control->force.Joint3 = 240;
        Hand_Control->force.Joint4 = 240;
        Hand_Control->force.Joint5 = 240;

        Hand_Control->speed.Joint1 = 1;
        Hand_Control->speed.Joint2 = 1;
        Hand_Control->speed.Joint3 = 1;
        Hand_Control->speed.Joint4 = 1;
        Hand_Control->speed.Joint5 = 1;
        Hand_Control->speed.Joint6 = 1;
        Hand_Control->speed.Joint7 = 1;
        Hand_Control->speed.Joint8 = 1;
        Hand_Control->speed.Joint9 = 1;
        Hand_Control->speed.Joint1_tip = 1;
        Hand_Control->speed.Joint2_tip = 1;
        Hand_Control->speed.Joint3_tip = 1;
        Hand_Control->speed.Joint4_tip = 1;
        Hand_Control->speed.Joint5_tip = 1;
        Hand_Control->speed.Joint1_rotation = 1;
        Hand_Control->speed.Joint3_raw = 1;

        Hand_Control->point.Joint1 = 240;
        Hand_Control->point.Joint2 = 240;
        Hand_Control->point.Joint3 = 240;
        Hand_Control->point.Joint4 = 240;
        Hand_Control->point.Joint5 = 240;
        Hand_Control->point.Joint6 = 240;
        Hand_Control->point.Joint7 = 240;
        Hand_Control->point.Joint8 = 240;
        Hand_Control->point.Joint9 = 240;
        Hand_Control->point.Joint1_tip = 240;
        Hand_Control->point.Joint2_tip = 240;
        Hand_Control->point.Joint3_tip = 240;
        Hand_Control->point.Joint4_tip = 240;
        Hand_Control->point.Joint5_tip = 240;
        Hand_Control->point.Joint1_rotation = 240;
        Hand_Control->point.Joint3_raw = 240;

        hand_position = Hand_Control->point;

        Hand_Control->Hand_SendStructDataDeal(Hand_Control -> Hand_Freedom, "Left_Hand", Hand_Control -> force, Hand_Control -> speed, Hand_Control -> point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {

        Hand_Control->Hand_Freedom = 10;

        Hand_Control->force.Joint1 = 240;
        Hand_Control->force.Joint2 = 240;
        Hand_Control->force.Joint3 = 240;
        Hand_Control->force.Joint4 = 240;
        Hand_Control->force.Joint5 = 240;

        Hand_Control->speed.Joint1 = 1;
        Hand_Control->speed.Joint2 = 1;
        Hand_Control->speed.Joint3 = 1;
        Hand_Control->speed.Joint4 = 1;
        Hand_Control->speed.Joint5 = 1;
        Hand_Control->speed.Joint6 = 1;
        Hand_Control->speed.Joint7 = 1;
        Hand_Control->speed.Joint8 = 1;
        Hand_Control->speed.Joint9 = 1;
        Hand_Control->speed.Joint1_tip = 1;
        Hand_Control->speed.Joint2_tip = 1;
        Hand_Control->speed.Joint3_tip = 1;
        Hand_Control->speed.Joint4_tip = 1;
        Hand_Control->speed.Joint5_tip = 1;
        Hand_Control->speed.Joint1_rotation = 1;
        Hand_Control->speed.Joint3_raw = 1;

        Hand_Control->point.Joint1 = 240;
        Hand_Control->point.Joint2 = 240;
        Hand_Control->point.Joint3 = 240;
        Hand_Control->point.Joint4 = 240;
        Hand_Control->point.Joint5 = 240;
        Hand_Control->point.Joint6 = 240;
        Hand_Control->point.Joint7 = 240;
        Hand_Control->point.Joint8 = 240;
        Hand_Control->point.Joint9 = 240;
        Hand_Control->point.Joint1_tip = 240;
        Hand_Control->point.Joint2_tip = 240;
        Hand_Control->point.Joint3_tip = 240;
        Hand_Control->point.Joint4_tip = 240;
        Hand_Control->point.Joint5_tip = 240;
        Hand_Control->point.Joint1_rotation = 240;
        Hand_Control->point.Joint3_raw = 240;

        hand_position = Hand_Control->point;

        Hand_Control->Hand_SendStructDataDeal(Hand_Control -> Hand_Freedom, "Right_Hand", Hand_Control -> force, Hand_Control -> speed, Hand_Control -> point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {

        Hand_Control->Hand_Freedom = 16;

        Hand_Control->force.Joint1 = 240;
        Hand_Control->force.Joint2 = 240;
        Hand_Control->force.Joint3 = 240;
        Hand_Control->force.Joint4 = 240;
        Hand_Control->force.Joint5 = 240;

        Hand_Control->speed.Joint1 = 1;
        Hand_Control->speed.Joint2 = 1;
        Hand_Control->speed.Joint3 = 1;
        Hand_Control->speed.Joint4 = 1;
        Hand_Control->speed.Joint5 = 1;
        Hand_Control->speed.Joint6 = 1;
        Hand_Control->speed.Joint7 = 1;
        Hand_Control->speed.Joint8 = 1;
        Hand_Control->speed.Joint9 = 1;
        Hand_Control->speed.Joint1_tip = 1;
        Hand_Control->speed.Joint2_tip = 1;
        Hand_Control->speed.Joint3_tip = 1;
        Hand_Control->speed.Joint4_tip = 1;
        Hand_Control->speed.Joint5_tip = 1;
        Hand_Control->speed.Joint1_rotation = 1;
        Hand_Control->speed.Joint3_raw = 1;

        Hand_Control->point.Joint1 = 240;
        Hand_Control->point.Joint2 = 240;
        Hand_Control->point.Joint3 = 240;
        Hand_Control->point.Joint4 = 240;
        Hand_Control->point.Joint5 = 240;
        Hand_Control->point.Joint6 = 240;
        Hand_Control->point.Joint7 = 240;
        Hand_Control->point.Joint8 = 240;
        Hand_Control->point.Joint9 = 240;
        Hand_Control->point.Joint1_tip = 240;
        Hand_Control->point.Joint2_tip = 240;
        Hand_Control->point.Joint3_tip = 240;
        Hand_Control->point.Joint4_tip = 240;
        Hand_Control->point.Joint5_tip = 240;
        Hand_Control->point.Joint1_rotation = 240;
        Hand_Control->point.Joint3_raw = 240;

        hand_position = Hand_Control->point;

        Hand_Control->Hand_SendStructDataDeal(Hand_Control -> Hand_Freedom, "Left_Hand", Hand_Control -> force, Hand_Control -> speed, Hand_Control -> point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {

        Hand_Control->Hand_Freedom = 16;

        Hand_Control->force.Joint1 = 240;
        Hand_Control->force.Joint2 = 240;
        Hand_Control->force.Joint3 = 240;
        Hand_Control->force.Joint4 = 240;
        Hand_Control->force.Joint5 = 240;

        Hand_Control->speed.Joint1 = 1;
        Hand_Control->speed.Joint2 = 1;
        Hand_Control->speed.Joint3 = 1;
        Hand_Control->speed.Joint4 = 1;
        Hand_Control->speed.Joint5 = 1;
        Hand_Control->speed.Joint6 = 1;
        Hand_Control->speed.Joint7 = 1;
        Hand_Control->speed.Joint8 = 1;
        Hand_Control->speed.Joint9 = 1;
        Hand_Control->speed.Joint1_tip = 1;
        Hand_Control->speed.Joint2_tip = 1;
        Hand_Control->speed.Joint3_tip = 1;
        Hand_Control->speed.Joint4_tip = 1;
        Hand_Control->speed.Joint5_tip = 1;
        Hand_Control->speed.Joint1_rotation = 1;
        Hand_Control->speed.Joint3_raw = 1;

        Hand_Control->point.Joint1 = 240;
        Hand_Control->point.Joint2 = 240;
        Hand_Control->point.Joint3 = 240;
        Hand_Control->point.Joint4 = 240;
        Hand_Control->point.Joint5 = 240;
        Hand_Control->point.Joint6 = 240;
        Hand_Control->point.Joint7 = 240;
        Hand_Control->point.Joint8 = 240;
        Hand_Control->point.Joint9 = 240;
        Hand_Control->point.Joint1_tip = 240;
        Hand_Control->point.Joint2_tip = 240;
        Hand_Control->point.Joint3_tip = 240;
        Hand_Control->point.Joint4_tip = 240;
        Hand_Control->point.Joint5_tip = 240;
        Hand_Control->point.Joint1_rotation = 240;
        Hand_Control->point.Joint3_raw = 240;

        hand_position = Hand_Control->point;

        Hand_Control->Hand_SendStructDataDeal(Hand_Control -> Hand_Freedom, "Right_Hand", Hand_Control -> force, Hand_Control -> speed, Hand_Control -> point);
        hand_16deg_dataUpdate(hand_position);
    }

}

void Robot_Hand_Ui::on_Hand_Close_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_Control->Hand_Freedom = 9;

        Hand_Control->force.Joint1 = 240;
        Hand_Control->force.Joint2 = 240;
        Hand_Control->force.Joint3 = 240;
        Hand_Control->force.Joint4 = 240;
        Hand_Control->force.Joint5 = 240;

        Hand_Control->speed.Joint1 = 1;
        Hand_Control->speed.Joint2 = 1;
        Hand_Control->speed.Joint3 = 1;
        Hand_Control->speed.Joint4 = 1;
        Hand_Control->speed.Joint5 = 1;
        Hand_Control->speed.Joint6 = 1;
        Hand_Control->speed.Joint7 = 1;
        Hand_Control->speed.Joint8 = 1;
        Hand_Control->speed.Joint9 = 1;
        Hand_Control->speed.Joint1_tip = 1;
        Hand_Control->speed.Joint2_tip = 1;
        Hand_Control->speed.Joint3_tip = 1;
        Hand_Control->speed.Joint4_tip = 1;
        Hand_Control->speed.Joint5_tip = 1;
        Hand_Control->speed.Joint1_rotation = 1;
        Hand_Control->speed.Joint3_raw = 1;

        Hand_Control->point.Joint1 = 100;
        Hand_Control->point.Joint2 = 100;
        Hand_Control->point.Joint3 = 100;
        Hand_Control->point.Joint4 = 100;
        Hand_Control->point.Joint5 = 100;
        Hand_Control->point.Joint6 = 100;
        Hand_Control->point.Joint7 = 100;
        Hand_Control->point.Joint8 = 100;
        Hand_Control->point.Joint9 = 100;
        Hand_Control->point.Joint1_tip = 100;
        Hand_Control->point.Joint2_tip = 100;
        Hand_Control->point.Joint3_tip = 100;
        Hand_Control->point.Joint4_tip = 100;
        Hand_Control->point.Joint5_tip = 100;
        Hand_Control->point.Joint1_rotation = 100;
        Hand_Control->point.Joint3_raw = 100;

        hand_position = Hand_Control->point;

        Hand_Control->Hand_SendStructDataDeal(Hand_Control -> Hand_Freedom, "Left_Hand", Hand_Control -> force, Hand_Control -> speed, Hand_Control -> point);
        hand_9deg_dataUpdate(hand_position);
    }
     if (hand_right_9deg == true) {
         Hand_Control->Hand_Freedom = 9;

         Hand_Control->force.Joint1 = 240;
         Hand_Control->force.Joint2 = 240;
         Hand_Control->force.Joint3 = 240;
         Hand_Control->force.Joint4 = 240;
         Hand_Control->force.Joint5 = 240;

         Hand_Control->speed.Joint1 = 1;
         Hand_Control->speed.Joint2 = 1;
         Hand_Control->speed.Joint3 = 1;
         Hand_Control->speed.Joint4 = 1;
         Hand_Control->speed.Joint5 = 1;
         Hand_Control->speed.Joint6 = 1;
         Hand_Control->speed.Joint7 = 1;
         Hand_Control->speed.Joint8 = 1;
         Hand_Control->speed.Joint9 = 1;
         Hand_Control->speed.Joint1_tip = 1;
         Hand_Control->speed.Joint2_tip = 1;
         Hand_Control->speed.Joint3_tip = 1;
         Hand_Control->speed.Joint4_tip = 1;
         Hand_Control->speed.Joint5_tip = 1;
         Hand_Control->speed.Joint1_rotation = 1;
         Hand_Control->speed.Joint3_raw = 1;

         Hand_Control->point.Joint1 = 100;
         Hand_Control->point.Joint2 = 100;
         Hand_Control->point.Joint3 = 100;
         Hand_Control->point.Joint4 = 100;
         Hand_Control->point.Joint5 = 100;
         Hand_Control->point.Joint6 = 100;
         Hand_Control->point.Joint7 = 100;
         Hand_Control->point.Joint8 = 100;
         Hand_Control->point.Joint9 = 100;
         Hand_Control->point.Joint1_tip = 100;
         Hand_Control->point.Joint2_tip = 100;
         Hand_Control->point.Joint3_tip = 100;
         Hand_Control->point.Joint4_tip = 100;
         Hand_Control->point.Joint5_tip = 100;
         Hand_Control->point.Joint1_rotation = 100;
         Hand_Control->point.Joint3_raw = 100;

         hand_position = Hand_Control->point;

         Hand_Control->Hand_SendStructDataDeal(Hand_Control -> Hand_Freedom, "Right_Hand", Hand_Control -> force, Hand_Control -> speed, Hand_Control -> point);
         hand_9deg_dataUpdate(hand_position);
     }

    if (hand_left_10deg == true) {
        Hand_Control->Hand_Freedom = 10;

        Hand_Control->force.Joint1 = 240;
        Hand_Control->force.Joint2 = 240;
        Hand_Control->force.Joint3 = 240;
        Hand_Control->force.Joint4 = 240;
        Hand_Control->force.Joint5 = 240;

        Hand_Control->speed.Joint1 = 1;
        Hand_Control->speed.Joint2 = 1;
        Hand_Control->speed.Joint3 = 1;
        Hand_Control->speed.Joint4 = 1;
        Hand_Control->speed.Joint5 = 1;
        Hand_Control->speed.Joint6 = 1;
        Hand_Control->speed.Joint7 = 1;
        Hand_Control->speed.Joint8 = 1;
        Hand_Control->speed.Joint9 = 1;
        Hand_Control->speed.Joint1_tip = 1;
        Hand_Control->speed.Joint2_tip = 1;
        Hand_Control->speed.Joint3_tip = 1;
        Hand_Control->speed.Joint4_tip = 1;
        Hand_Control->speed.Joint5_tip = 1;
        Hand_Control->speed.Joint1_rotation = 1;
        Hand_Control->speed.Joint3_raw = 1;

        Hand_Control->point.Joint1 = 100;
        Hand_Control->point.Joint2 = 100;
        Hand_Control->point.Joint3 = 100;
        Hand_Control->point.Joint4 = 100;
        Hand_Control->point.Joint5 = 100;
        Hand_Control->point.Joint6 = 100;
        Hand_Control->point.Joint7 = 100;
        Hand_Control->point.Joint8 = 100;
        Hand_Control->point.Joint9 = 100;
        Hand_Control->point.Joint1_tip = 100;
        Hand_Control->point.Joint2_tip = 100;
        Hand_Control->point.Joint3_tip = 100;
        Hand_Control->point.Joint4_tip = 100;
        Hand_Control->point.Joint5_tip = 100;
        Hand_Control->point.Joint1_rotation = 100;
        Hand_Control->point.Joint3_raw = 100;

        hand_position = Hand_Control->point;

        Hand_Control->Hand_SendStructDataDeal(Hand_Control -> Hand_Freedom, "Left_Hand", Hand_Control -> force, Hand_Control -> speed, Hand_Control -> point);
        hand_10deg_dataUpdate(hand_position);
    }
     if (hand_right_10deg == true) {
         Hand_Control->Hand_Freedom = 10;

         Hand_Control->force.Joint1 = 240;
         Hand_Control->force.Joint2 = 240;
         Hand_Control->force.Joint3 = 240;
         Hand_Control->force.Joint4 = 240;
         Hand_Control->force.Joint5 = 240;

         Hand_Control->speed.Joint1 = 1;
         Hand_Control->speed.Joint2 = 1;
         Hand_Control->speed.Joint3 = 1;
         Hand_Control->speed.Joint4 = 1;
         Hand_Control->speed.Joint5 = 1;
         Hand_Control->speed.Joint6 = 1;
         Hand_Control->speed.Joint7 = 1;
         Hand_Control->speed.Joint8 = 1;
         Hand_Control->speed.Joint9 = 1;
         Hand_Control->speed.Joint1_tip = 1;
         Hand_Control->speed.Joint2_tip = 1;
         Hand_Control->speed.Joint3_tip = 1;
         Hand_Control->speed.Joint4_tip = 1;
         Hand_Control->speed.Joint5_tip = 1;
         Hand_Control->speed.Joint1_rotation = 1;
         Hand_Control->speed.Joint3_raw = 1;

         Hand_Control->point.Joint1 = 100;
         Hand_Control->point.Joint2 = 100;
         Hand_Control->point.Joint3 = 100;
         Hand_Control->point.Joint4 = 100;
         Hand_Control->point.Joint5 = 100;
         Hand_Control->point.Joint6 = 100;
         Hand_Control->point.Joint7 = 100;
         Hand_Control->point.Joint8 = 100;
         Hand_Control->point.Joint9 = 100;
         Hand_Control->point.Joint1_tip = 100;
         Hand_Control->point.Joint2_tip = 100;
         Hand_Control->point.Joint3_tip = 100;
         Hand_Control->point.Joint4_tip = 100;
         Hand_Control->point.Joint5_tip = 100;
         Hand_Control->point.Joint1_rotation = 100;
         Hand_Control->point.Joint3_raw = 100;

         hand_position = Hand_Control->point;

         Hand_Control->Hand_SendStructDataDeal(Hand_Control -> Hand_Freedom, "Right_Hand", Hand_Control -> force, Hand_Control -> speed, Hand_Control -> point);
         hand_10deg_dataUpdate(hand_position);
     }

     if (hand_left_16deg == true) {
         Hand_Control->Hand_Freedom = 16;

         Hand_Control->force.Joint1 = 240;
         Hand_Control->force.Joint2 = 240;
         Hand_Control->force.Joint3 = 240;
         Hand_Control->force.Joint4 = 240;
         Hand_Control->force.Joint5 = 240;

         Hand_Control->speed.Joint1 = 1;
         Hand_Control->speed.Joint2 = 1;
         Hand_Control->speed.Joint3 = 1;
         Hand_Control->speed.Joint4 = 1;
         Hand_Control->speed.Joint5 = 1;
         Hand_Control->speed.Joint6 = 1;
         Hand_Control->speed.Joint7 = 1;
         Hand_Control->speed.Joint8 = 1;
         Hand_Control->speed.Joint9 = 1;
         Hand_Control->speed.Joint1_tip = 1;
         Hand_Control->speed.Joint2_tip = 1;
         Hand_Control->speed.Joint3_tip = 1;
         Hand_Control->speed.Joint4_tip = 1;
         Hand_Control->speed.Joint5_tip = 1;
         Hand_Control->speed.Joint1_rotation = 1;
         Hand_Control->speed.Joint3_raw = 1;

         Hand_Control->point.Joint1 = 100;
         Hand_Control->point.Joint2 = 100;
         Hand_Control->point.Joint3 = 100;
         Hand_Control->point.Joint4 = 100;
         Hand_Control->point.Joint5 = 100;
         Hand_Control->point.Joint6 = 100;
         Hand_Control->point.Joint7 = 100;
         Hand_Control->point.Joint8 = 100;
         Hand_Control->point.Joint9 = 100;
         Hand_Control->point.Joint1_tip = 100;
         Hand_Control->point.Joint2_tip = 100;
         Hand_Control->point.Joint3_tip = 100;
         Hand_Control->point.Joint4_tip = 100;
         Hand_Control->point.Joint5_tip = 100;
         Hand_Control->point.Joint1_rotation = 100;
         Hand_Control->point.Joint3_raw = 100;

         hand_position = Hand_Control->point;

         Hand_Control->Hand_SendStructDataDeal(Hand_Control -> Hand_Freedom, "Left_Hand", Hand_Control -> force, Hand_Control -> speed, Hand_Control -> point);
         hand_16deg_dataUpdate(hand_position);
     }
      if (hand_right_16deg == true) {
          Hand_Control->Hand_Freedom = 16;

          Hand_Control->force.Joint1 = 240;
          Hand_Control->force.Joint2 = 240;
          Hand_Control->force.Joint3 = 240;
          Hand_Control->force.Joint4 = 240;
          Hand_Control->force.Joint5 = 240;

          Hand_Control->speed.Joint1 = 1;
          Hand_Control->speed.Joint2 = 1;
          Hand_Control->speed.Joint3 = 1;
          Hand_Control->speed.Joint4 = 1;
          Hand_Control->speed.Joint5 = 1;
          Hand_Control->speed.Joint6 = 1;
          Hand_Control->speed.Joint7 = 1;
          Hand_Control->speed.Joint8 = 1;
          Hand_Control->speed.Joint9 = 1;
          Hand_Control->speed.Joint1_tip = 1;
          Hand_Control->speed.Joint2_tip = 1;
          Hand_Control->speed.Joint3_tip = 1;
          Hand_Control->speed.Joint4_tip = 1;
          Hand_Control->speed.Joint5_tip = 1;
          Hand_Control->speed.Joint1_rotation = 1;
          Hand_Control->speed.Joint3_raw = 1;

          Hand_Control->point.Joint1 = 100;
          Hand_Control->point.Joint2 = 100;
          Hand_Control->point.Joint3 = 100;
          Hand_Control->point.Joint4 = 100;
          Hand_Control->point.Joint5 = 100;
          Hand_Control->point.Joint6 = 100;
          Hand_Control->point.Joint7 = 100;
          Hand_Control->point.Joint8 = 100;
          Hand_Control->point.Joint9 = 100;
          Hand_Control->point.Joint1_tip = 100;
          Hand_Control->point.Joint2_tip = 100;
          Hand_Control->point.Joint3_tip = 100;
          Hand_Control->point.Joint4_tip = 100;
          Hand_Control->point.Joint5_tip = 100;
          Hand_Control->point.Joint1_rotation = 100;
          Hand_Control->point.Joint3_raw = 100;

          hand_position = Hand_Control->point;

          Hand_Control->Hand_SendStructDataDeal(Hand_Control -> Hand_Freedom, "Right_Hand", Hand_Control -> force, Hand_Control -> speed, Hand_Control -> point);
          hand_16deg_dataUpdate(hand_position);
      }


}

void Robot_Hand_Ui::on_read_data_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point = Hand_Control->read_hand_data("Left_hand");
        hand_position.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        hand_position.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        hand_position.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        hand_position.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        hand_position.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        hand_position.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        hand_position.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        hand_position.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        hand_position.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;

        ui->verticalSlider_thumb_roll->setValue(hand_position.Joint1);
        ui->verticalSlider_index_roll->setValue(hand_position.Joint3);
        ui->verticalSlider_middle_roll->setValue(hand_position.Joint4);
        ui->verticalSlider_third_roll->setValue(hand_position.Joint5);
        ui->verticalSlider_pinkie_roll->setValue(hand_position.Joint6);

        ui->verticalSlider_thumb_swing->setValue(hand_position.Joint2);
        ui->verticalSlider_index_swing->setValue(hand_position.Joint7);
        ui->verticalSlider_third_swing->setValue(hand_position.Joint8);
        ui->verticalSlider_pinkie_swing->setValue(hand_position.Joint9);

        ui->tableWidget_hand_data->setItem(0,0,new QTableWidgetItem(QString::number(hand_position.Joint1,'f',0)+"(joint1)"));
        ui->tableWidget_hand_data->setItem(0,1,new QTableWidgetItem(QString::number(hand_position.Joint3,'f',0)+"(joint3)"));
        ui->tableWidget_hand_data->setItem(0,2,new QTableWidgetItem(QString::number(hand_position.Joint4,'f',0)+"(joint4)"));
        ui->tableWidget_hand_data->setItem(0,3,new QTableWidgetItem(QString::number(hand_position.Joint5,'f',0)+"(joint5)"));
        ui->tableWidget_hand_data->setItem(0,4,new QTableWidgetItem(QString::number(hand_position.Joint6,'f',0)+"(joint6)"));
        ui->tableWidget_hand_data->setItem(1,0,new QTableWidgetItem(QString::number(hand_position.Joint2,'f',0)+"(joint2)"));
        ui->tableWidget_hand_data->setItem(1,1,new QTableWidgetItem(QString::number(hand_position.Joint7,'f',0)+"(joint7)"));
        ui->tableWidget_hand_data->setItem(1,3,new QTableWidgetItem(QString::number(hand_position.Joint8,'f',0)+"(joint8)"));
        ui->tableWidget_hand_data->setItem(1,4,new QTableWidgetItem(QString::number(hand_position.Joint9,'f',0)+"(joint9)"));

    }

    if (hand_right_9deg == true) {
        Hand_RecvStruct thumb_point = Hand_Control->read_hand_data("Right_hand");
        hand_position.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
        hand_position.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
        hand_position.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
        hand_position.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
        hand_position.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
        hand_position.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
        hand_position.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
        hand_position.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
        hand_position.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;

        ui->verticalSlider_thumb_roll->setValue(hand_position.Joint1);
        ui->verticalSlider_index_roll->setValue(hand_position.Joint3);
        ui->verticalSlider_middle_roll->setValue(hand_position.Joint4);
        ui->verticalSlider_third_roll->setValue(hand_position.Joint5);
        ui->verticalSlider_pinkie_roll->setValue(hand_position.Joint6);

        ui->verticalSlider_thumb_swing->setValue(hand_position.Joint2);
        ui->verticalSlider_index_swing->setValue(hand_position.Joint7);
        ui->verticalSlider_third_swing->setValue(hand_position.Joint8);
        ui->verticalSlider_pinkie_swing->setValue(hand_position.Joint9);

        ui->tableWidget_hand_data->setItem(0,0,new QTableWidgetItem(QString::number(hand_position.Joint1,'f',0)+"(joint1)"));
        ui->tableWidget_hand_data->setItem(0,1,new QTableWidgetItem(QString::number(hand_position.Joint3,'f',0)+"(joint3)"));
        ui->tableWidget_hand_data->setItem(0,2,new QTableWidgetItem(QString::number(hand_position.Joint4,'f',0)+"(joint4)"));
        ui->tableWidget_hand_data->setItem(0,3,new QTableWidgetItem(QString::number(hand_position.Joint5,'f',0)+"(joint5)"));
        ui->tableWidget_hand_data->setItem(0,4,new QTableWidgetItem(QString::number(hand_position.Joint6,'f',0)+"(joint6)"));
        ui->tableWidget_hand_data->setItem(1,0,new QTableWidgetItem(QString::number(hand_position.Joint2,'f',0)+"(joint2)"));
        ui->tableWidget_hand_data->setItem(1,1,new QTableWidgetItem(QString::number(hand_position.Joint7,'f',0)+"(joint7)"));
        ui->tableWidget_hand_data->setItem(1,3,new QTableWidgetItem(QString::number(hand_position.Joint8,'f',0)+"(joint8)"));
        ui->tableWidget_hand_data->setItem(1,4,new QTableWidgetItem(QString::number(hand_position.Joint9,'f',0)+"(joint9)"));

    }


    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point = Hand_Control->read_hand_data("Left_hand");
        hand_position.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        hand_position.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        hand_position.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        hand_position.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        hand_position.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        hand_position.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        hand_position.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        hand_position.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        hand_position.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        hand_position.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        ui->verticalSlider_thumb_roll->setValue(hand_position.Joint1);
        ui->verticalSlider_index_roll->setValue(hand_position.Joint3);
        ui->verticalSlider_middle_roll->setValue(hand_position.Joint4);
        ui->verticalSlider_third_roll->setValue(hand_position.Joint5);
        ui->verticalSlider_pinkie_roll->setValue(hand_position.Joint6);

        ui->verticalSlider_thumb_swing->setValue(hand_position.Joint2);
        ui->verticalSlider_index_swing->setValue(hand_position.Joint7);
        ui->verticalSlider_third_swing->setValue(hand_position.Joint8);
        ui->verticalSlider_pinkie_swing->setValue(hand_position.Joint9);
        ui->verticalSlider_thumb_rotation->setValue(hand_position.Joint1_rotation);

        ui->tableWidget_hand_data->setItem(0,0,new QTableWidgetItem(QString::number(hand_position.Joint1,'f',0)+"(joint1)"));
        ui->tableWidget_hand_data->setItem(0,1,new QTableWidgetItem(QString::number(hand_position.Joint3,'f',0)+"(joint3)"));
        ui->tableWidget_hand_data->setItem(0,2,new QTableWidgetItem(QString::number(hand_position.Joint4,'f',0)+"(joint4)"));
        ui->tableWidget_hand_data->setItem(0,3,new QTableWidgetItem(QString::number(hand_position.Joint5,'f',0)+"(joint5)"));
        ui->tableWidget_hand_data->setItem(0,4,new QTableWidgetItem(QString::number(hand_position.Joint6,'f',0)+"(joint6)"));
        ui->tableWidget_hand_data->setItem(1,0,new QTableWidgetItem(QString::number(hand_position.Joint2,'f',0)+"(joint2)"));
        ui->tableWidget_hand_data->setItem(1,1,new QTableWidgetItem(QString::number(hand_position.Joint7,'f',0)+"(joint7)"));
        ui->tableWidget_hand_data->setItem(1,3,new QTableWidgetItem(QString::number(hand_position.Joint8,'f',0)+"(joint8)"));
        ui->tableWidget_hand_data->setItem(1,4,new QTableWidgetItem(QString::number(hand_position.Joint9,'f',0)+"(joint9)"));
        ui->tableWidget_hand_data->setItem(3,0,new QTableWidgetItem(QString::number(hand_position.Joint1_rotation,'f',0)+"(joint10)"));
    }

    if (hand_right_10deg == true) {
        Hand_RecvStruct thumb_point = Hand_Control->read_hand_data("Right_hand");
        hand_position.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
        hand_position.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
        hand_position.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
        hand_position.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
        hand_position.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
        hand_position.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
        hand_position.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
        hand_position.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
        hand_position.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
        hand_position.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

        ui->verticalSlider_thumb_roll->setValue(hand_position.Joint1);
        ui->verticalSlider_index_roll->setValue(hand_position.Joint3);
        ui->verticalSlider_middle_roll->setValue(hand_position.Joint4);
        ui->verticalSlider_third_roll->setValue(hand_position.Joint5);
        ui->verticalSlider_pinkie_roll->setValue(hand_position.Joint6);

        ui->verticalSlider_thumb_swing->setValue(hand_position.Joint2);
        ui->verticalSlider_index_swing->setValue(hand_position.Joint7);
        ui->verticalSlider_third_swing->setValue(hand_position.Joint8);
        ui->verticalSlider_pinkie_swing->setValue(hand_position.Joint9);
        ui->verticalSlider_thumb_rotation->setValue(hand_position.Joint1_rotation);

        ui->tableWidget_hand_data->setItem(0,0,new QTableWidgetItem(QString::number(hand_position.Joint1,'f',0)+"(joint1)"));
        ui->tableWidget_hand_data->setItem(0,1,new QTableWidgetItem(QString::number(hand_position.Joint3,'f',0)+"(joint3)"));
        ui->tableWidget_hand_data->setItem(0,2,new QTableWidgetItem(QString::number(hand_position.Joint4,'f',0)+"(joint4)"));
        ui->tableWidget_hand_data->setItem(0,3,new QTableWidgetItem(QString::number(hand_position.Joint5,'f',0)+"(joint5)"));
        ui->tableWidget_hand_data->setItem(0,4,new QTableWidgetItem(QString::number(hand_position.Joint6,'f',0)+"(joint6)"));
        ui->tableWidget_hand_data->setItem(1,0,new QTableWidgetItem(QString::number(hand_position.Joint2,'f',0)+"(joint2)"));
        ui->tableWidget_hand_data->setItem(1,1,new QTableWidgetItem(QString::number(hand_position.Joint7,'f',0)+"(joint7)"));
        ui->tableWidget_hand_data->setItem(1,3,new QTableWidgetItem(QString::number(hand_position.Joint8,'f',0)+"(joint8)"));
        ui->tableWidget_hand_data->setItem(1,4,new QTableWidgetItem(QString::number(hand_position.Joint9,'f',0)+"(joint9)"));
        ui->tableWidget_hand_data->setItem(3,0,new QTableWidgetItem(QString::number(hand_position.Joint1_rotation,'f',0)+"(joint10)"));
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point = Hand_Control->read_hand_data("Left_hand");
        hand_position.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        hand_position.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        hand_position.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        hand_position.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        hand_position.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        hand_position.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        hand_position.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        hand_position.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        hand_position.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        hand_position.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        hand_position.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        hand_position.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        hand_position.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        hand_position.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        hand_position.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        hand_position.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        ui->verticalSlider_thumb_roll->setValue(hand_position.Joint1);
        ui->verticalSlider_index_roll->setValue(hand_position.Joint3);
        ui->verticalSlider_middle_roll->setValue(hand_position.Joint4);
        ui->verticalSlider_third_roll->setValue(hand_position.Joint5);
        ui->verticalSlider_pinkie_roll->setValue(hand_position.Joint6);

        ui->verticalSlider_thumb_swing->setValue(hand_position.Joint2);
        ui->verticalSlider_index_swing->setValue(hand_position.Joint7);
        ui->verticalSlider_third_swing->setValue(hand_position.Joint8);
        ui->verticalSlider_pinkie_swing->setValue(hand_position.Joint9);
        ui->verticalSlider_thumb_rotation->setValue(hand_position.Joint1_rotation);

        ui->verticalSlider_thumb_tip->setValue(hand_position.Joint1_tip);
        ui->verticalSlider_index_tip->setValue(hand_position.Joint2_tip);
        ui->verticalSlider_middle_tip->setValue(hand_position.Joint3_tip);
        ui->verticalSlider_third_tip->setValue(hand_position.Joint4_tip);
        ui->verticalSlider_pinkie_tip->setValue(hand_position.Joint5_tip);

        ui->verticalSlider_middle_swing->setValue(hand_position.Joint3_raw);

        ui->tableWidget_hand_data->setItem(0,0,new QTableWidgetItem(QString::number(hand_position.Joint1,'f',0)+"(joint1)"));
        ui->tableWidget_hand_data->setItem(0,1,new QTableWidgetItem(QString::number(hand_position.Joint3,'f',0)+"(joint3)"));
        ui->tableWidget_hand_data->setItem(0,2,new QTableWidgetItem(QString::number(hand_position.Joint4,'f',0)+"(joint4)"));
        ui->tableWidget_hand_data->setItem(0,3,new QTableWidgetItem(QString::number(hand_position.Joint5,'f',0)+"(joint5)"));
        ui->tableWidget_hand_data->setItem(0,4,new QTableWidgetItem(QString::number(hand_position.Joint6,'f',0)+"(joint6)"));
        ui->tableWidget_hand_data->setItem(1,0,new QTableWidgetItem(QString::number(hand_position.Joint2,'f',0)+"(joint2)"));
        ui->tableWidget_hand_data->setItem(1,1,new QTableWidgetItem(QString::number(hand_position.Joint7,'f',0)+"(joint7)"));
        ui->tableWidget_hand_data->setItem(1,3,new QTableWidgetItem(QString::number(hand_position.Joint8,'f',0)+"(joint8)"));
        ui->tableWidget_hand_data->setItem(1,4,new QTableWidgetItem(QString::number(hand_position.Joint9,'f',0)+"(joint9)"));
        ui->tableWidget_hand_data->setItem(3,0,new QTableWidgetItem(QString::number(hand_position.Joint1_rotation,'f',0)+"(joint10)"));
        ui->tableWidget_hand_data->setItem(2,0,new QTableWidgetItem(QString::number(hand_position.Joint1_tip,'f',0)+"(tip1)"));
        ui->tableWidget_hand_data->setItem(2,1,new QTableWidgetItem(QString::number(hand_position.Joint2_tip,'f',0)+"(tip2)"));
        ui->tableWidget_hand_data->setItem(2,2,new QTableWidgetItem(QString::number(hand_position.Joint3_tip,'f',0)+"(tip3)"));
        ui->tableWidget_hand_data->setItem(2,3,new QTableWidgetItem(QString::number(hand_position.Joint4_tip,'f',0)+"(tip4)"));
        ui->tableWidget_hand_data->setItem(2,4,new QTableWidgetItem(QString::number(hand_position.Joint5_tip,'f',0)+"(tip5)"));
        ui->tableWidget_hand_data->setItem(1,2,new QTableWidgetItem(QString::number(hand_position.Joint3_raw,'f',0)+"(joint3_raw)"));

    }

    if (hand_right_16deg == true) {
        Hand_RecvStruct thumb_point = Hand_Control->read_hand_data("Right_hand");
        hand_position.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
        hand_position.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
        hand_position.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
        hand_position.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
        hand_position.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
        hand_position.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
        hand_position.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
        hand_position.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
        hand_position.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
        hand_position.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
        hand_position.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
        hand_position.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
        hand_position.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
        hand_position.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
        hand_position.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
        hand_position.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;
        ui->tableWidget_hand_data->setItem(0,0,new QTableWidgetItem(QString::number(hand_position.Joint1,'f',0)+"(joint1)"));
        ui->tableWidget_hand_data->setItem(0,1,new QTableWidgetItem(QString::number(hand_position.Joint3,'f',0)+"(joint3)"));
        ui->tableWidget_hand_data->setItem(0,2,new QTableWidgetItem(QString::number(hand_position.Joint4,'f',0)+"(joint4)"));
        ui->tableWidget_hand_data->setItem(0,3,new QTableWidgetItem(QString::number(hand_position.Joint5,'f',0)+"(joint5)"));
        ui->tableWidget_hand_data->setItem(0,4,new QTableWidgetItem(QString::number(hand_position.Joint6,'f',0)+"(joint6)"));
        ui->tableWidget_hand_data->setItem(1,0,new QTableWidgetItem(QString::number(hand_position.Joint2,'f',0)+"(joint2)"));
        ui->tableWidget_hand_data->setItem(1,1,new QTableWidgetItem(QString::number(hand_position.Joint7,'f',0)+"(joint7)"));
        ui->tableWidget_hand_data->setItem(1,3,new QTableWidgetItem(QString::number(hand_position.Joint8,'f',0)+"(joint8)"));
        ui->tableWidget_hand_data->setItem(1,4,new QTableWidgetItem(QString::number(hand_position.Joint9,'f',0)+"(joint9)"));
        ui->tableWidget_hand_data->setItem(3,0,new QTableWidgetItem(QString::number(hand_position.Joint1_rotation,'f',0)+"(joint10)"));
        ui->tableWidget_hand_data->setItem(2,0,new QTableWidgetItem(QString::number(hand_position.Joint1_tip,'f',0)+"(tip1)"));
        ui->tableWidget_hand_data->setItem(2,1,new QTableWidgetItem(QString::number(hand_position.Joint2_tip,'f',0)+"(tip2)"));
        ui->tableWidget_hand_data->setItem(2,2,new QTableWidgetItem(QString::number(hand_position.Joint3_tip,'f',0)+"(tip3)"));
        ui->tableWidget_hand_data->setItem(2,3,new QTableWidgetItem(QString::number(hand_position.Joint4_tip,'f',0)+"(tip4)"));
        ui->tableWidget_hand_data->setItem(2,4,new QTableWidgetItem(QString::number(hand_position.Joint5_tip,'f',0)+"(tip5)"));
        ui->tableWidget_hand_data->setItem(1,2,new QTableWidgetItem(QString::number(hand_position.Joint3_raw,'f',0)+"(joint3_raw)"));

        ui->verticalSlider_thumb_roll->setValue(hand_position.Joint1);
        ui->verticalSlider_index_roll->setValue(hand_position.Joint3);
        ui->verticalSlider_middle_roll->setValue(hand_position.Joint4);
        ui->verticalSlider_third_roll->setValue(hand_position.Joint5);
        ui->verticalSlider_pinkie_roll->setValue(hand_position.Joint6);

        ui->verticalSlider_thumb_swing->setValue(hand_position.Joint2);
        ui->verticalSlider_index_swing->setValue(hand_position.Joint7);
        ui->verticalSlider_third_swing->setValue(hand_position.Joint8);
        ui->verticalSlider_pinkie_swing->setValue(hand_position.Joint9);
        ui->verticalSlider_thumb_rotation->setValue(hand_position.Joint1_rotation);

        ui->verticalSlider_thumb_tip->setValue(hand_position.Joint1_tip);
        ui->verticalSlider_index_tip->setValue(hand_position.Joint2_tip);
        ui->verticalSlider_middle_tip->setValue(hand_position.Joint3_tip);
        ui->verticalSlider_third_tip->setValue(hand_position.Joint4_tip);
        ui->verticalSlider_pinkie_tip->setValue(hand_position.Joint5_tip);

        ui->verticalSlider_middle_swing->setValue(hand_position.Joint3_raw);
    }


}



void Robot_Hand_Ui::on_button_thumb_roll_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1 - 20;
       point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;


       if (point.Joint1 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1 - 20;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;


       if (point.Joint1 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }


    if (hand_left_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1 - 20;
       point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

       if (point.Joint1 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1 - 20;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint1 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
       qDebug() << "joint1_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
       qDebug() << "joint2_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
       qDebug() << "joint3_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
       qDebug() << "joint4_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
       qDebug() << "joint5_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
       qDebug() << "joint3_raw" << thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1 - 20;
       point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

       if (point.Joint1 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       qDebug() << "joint1_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       qDebug() << "joint2_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       qDebug() << "joint3_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       qDebug() << "joint4_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       qDebug() << "joint5_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       qDebug() << "joint3_raw" << thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1 - 20;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       if (point.Joint1 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }



}

void Robot_Hand_Ui::on_button_thumb_straight_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1 + 20;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        if (point.Joint1 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1 + 20;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;


       if (point.Joint1 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }


    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1 + 20;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint1 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1 + 20;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint1 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        qDebug() << "joint1_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        qDebug() << "joint2_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        qDebug() << "joint3_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        qDebug() << "joint4_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        qDebug() << "joint5_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        qDebug() << "joint3_raw" << thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1 + 20;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        if (point.Joint1 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       qDebug() << "joint1_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       qDebug() << "joint2_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       qDebug() << "joint3_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       qDebug() << "joint4_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       qDebug() << "joint5_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       qDebug() << "joint3_raw" << thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1 + 20;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;


       if (point.Joint1 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }

}

void Robot_Hand_Ui::on_button_index_roll_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3 - 20;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        if (point.Joint3 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3 - 20;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;


       if (point.Joint3 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3 - 20;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        if (point.Joint3 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3 - 20;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       if (point.Joint3 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        qDebug() << "joint1_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        qDebug() << "joint2_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        qDebug() << "joint3_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        qDebug() << "joint4_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        qDebug() << "joint5_tip" << thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        qDebug() << "joint3_raw" << thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3 - 20;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        if (point.Joint3 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       qDebug() << "joint1_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       qDebug() << "joint2_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       qDebug() << "joint3_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       qDebug() << "joint4_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       qDebug() << "joint5_tip" << thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       qDebug() << "joint3_raw" << thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3 - 20;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       if (point.Joint3 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_index_straight_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3 + 20;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        if (point.Joint3 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3 + 20;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;

        qDebug() << "ok";
       if (point.Joint3 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3 + 20;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint3 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3 + 20;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
        qDebug() << "ok";
       if (point.Joint3 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3 + 20;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        if (point.Joint3 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3 + 20;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;
        qDebug() << "ok";
       if (point.Joint3 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_middle_roll_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4 - 20;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        if (point.Joint4 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4 - 20;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;


       if (point.Joint4 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4 - 20;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint4 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4 - 20;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint4 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4 - 20;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        if (point.Joint4 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4 - 20;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       if (point.Joint4 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_middle_straight_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4 + 20;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint4 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4 + 20;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;


       if (point.Joint4 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4 + 20;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint4 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4 + 20;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint4 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4 + 20;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        if (point.Joint4 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4 + 20;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       if (point.Joint4 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_third_roll_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5 - 20;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        if (point.Joint5 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5 - 20;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;


       if (point.Joint5 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5 - 20;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint5 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5 - 20;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint5 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5 - 20;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        if (point.Joint5 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5 - 20;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       if (point.Joint5 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_third_straight_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5 + 20;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        if (point.Joint5 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5 + 20;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;


       if (point.Joint5 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5 + 20;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint5 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5 + 20;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint5 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5 + 20;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        if (point.Joint5 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5 + 20;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       if (point.Joint5 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_pinkie_roll_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6 - 20;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        if (point.Joint6 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6 - 20;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;


       if (point.Joint6 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6 - 20;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint6 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6 - 20;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint6 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6 - 20;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        if (point.Joint6 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6 - 20;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       if (point.Joint6 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_pinkie_straight_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6 + 20;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        if (point.Joint6 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6 + 20;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;


       if (point.Joint6 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6 + 20;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint6 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6 + 20;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint6 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6 + 20;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint6 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6 + 20;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       if (point.Joint6 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_thumb_swing_in_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2 - 20;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        if (point.Joint2 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2 - 20;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;


       if (point.Joint2 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2 - 20;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint2 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2 - 20;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint2 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2 - 20;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        if (point.Joint2 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2 - 20;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       if (point.Joint2 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }


}

void Robot_Hand_Ui::on_button_thumb_swing_out_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2 + 20;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        if (point.Joint2 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2 + 20;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;


       if (point.Joint2 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2 + 20;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint2 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2 + 20;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint2 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2 + 20;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        if (point.Joint2 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2 + 20;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       if (point.Joint2 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_index_swing_in_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7 - 20;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        if (point.Joint7 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7 - 20;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;


       if (point.Joint7 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7 - 20;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint7 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7 - 20;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint7 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7 - 20;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        if (point.Joint7 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7 - 20;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       if (point.Joint7 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_index_swing_out_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7 + 20;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        if (point.Joint7 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7 + 20;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;


       if (point.Joint7 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7 + 20;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint7 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7 + 20;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint7 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7 + 20;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw;

        if (point.Joint7  >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7 + 20;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw;

       if (point.Joint7  >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_middle_swing_in_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw - 20;

        if (point.Joint3_raw  <= 0) {
            return;
        }

        if (point.Joint8 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw - 20;

       if (point.Joint3_raw  <= 0) {
           return;
       }
       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_middle_swing_out_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;
        point.Joint1_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint1_tip;
        point.Joint2_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint2_tip;
        point.Joint3_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint3_tip;
        point.Joint4_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint4_tip;
        point.Joint5_tip = thumb_point.Get_CurrentPoint_LeftHand.Joint5_tip;
        point.Joint3_raw = thumb_point.Get_CurrentPoint_LeftHand.Joint3_raw + 20;

        if (point.Joint3_raw  >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       speed.Joint1_tip = 1;
       speed.Joint2_tip = 1;
       speed.Joint3_tip = 1;
       speed.Joint4_tip = 1;
       speed.Joint5_tip = 1;
       speed.Joint3_raw = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;
       point.Joint1_tip = thumb_point.Get_CurrentPoint_RightHand.Joint1_tip;
       point.Joint2_tip = thumb_point.Get_CurrentPoint_RightHand.Joint2_tip;
       point.Joint3_tip = thumb_point.Get_CurrentPoint_RightHand.Joint3_tip;
       point.Joint4_tip = thumb_point.Get_CurrentPoint_RightHand.Joint4_tip;
       point.Joint5_tip = thumb_point.Get_CurrentPoint_RightHand.Joint5_tip;
       point.Joint3_raw = thumb_point.Get_CurrentPoint_RightHand.Joint3_raw - 20;

       if (point.Joint3_raw <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_third_swing_in_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8 - 20;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        if (point.Joint8 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8 - 20;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;


       if (point.Joint8 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8 - 20;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint8 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8 - 20;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint8 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8 - 20;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint8 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       speed.Joint1_tip = 1;
       speed.Joint2_tip = 1;
       speed.Joint3_tip = 1;
       speed.Joint4_tip = 1;
       speed.Joint5_tip = 1;
       speed.Joint3_raw = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8 - 20;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint8 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_third_swing_out_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8 + 20;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        if (point.Joint8 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8 + 20;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;


       if (point.Joint8 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8 + 20;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint8 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8 + 20;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint8 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8 + 20;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint8 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       speed.Joint1_tip = 1;
       speed.Joint2_tip = 1;
       speed.Joint3_tip = 1;
       speed.Joint4_tip = 1;
       speed.Joint5_tip = 1;
       speed.Joint3_raw = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8 + 20;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint8 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_pinkie_swing_in_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9 - 20;


        if (point.Joint9 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9 - 20;


       if (point.Joint9 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9 - 20;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint9 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9 - 20;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint9 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9 - 20;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint9 <= 0) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       speed.Joint1_tip = 1;
       speed.Joint2_tip = 1;
       speed.Joint3_tip = 1;
       speed.Joint4_tip = 1;
       speed.Joint5_tip = 1;
       speed.Joint3_raw = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9 - 20;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint9 <= 0) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_button_pinkie_swing_out_clicked()
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;


        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9 + 20;


        if (point.Joint9 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;


       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9 + 20;


       if (point.Joint9 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
       hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9 + 20;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint9 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9 + 20;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint9 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
       hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Left_hand");
        qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_LeftHand.Joint9;
        qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;
        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = thumb_point.Get_CurrentPoint_LeftHand.Joint1;
        point.Joint2 = thumb_point.Get_CurrentPoint_LeftHand.Joint2;
        point.Joint3 = thumb_point.Get_CurrentPoint_LeftHand.Joint3;
        point.Joint4 = thumb_point.Get_CurrentPoint_LeftHand.Joint4;
        point.Joint5 = thumb_point.Get_CurrentPoint_LeftHand.Joint5;
        point.Joint6 = thumb_point.Get_CurrentPoint_LeftHand.Joint6;
        point.Joint7 = thumb_point.Get_CurrentPoint_LeftHand.Joint7;
        point.Joint8 = thumb_point.Get_CurrentPoint_LeftHand.Joint8;
        point.Joint9 = thumb_point.Get_CurrentPoint_LeftHand.Joint9 + 20;
        point.Joint1_rotation = thumb_point.Get_CurrentPoint_LeftHand.Joint1_rotation;

        if (point.Joint9 >= 250) {
            return;
        }
        hand_position = point;
        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
       Hand_RecvStruct thumb_point =  Hand_Control->read_hand_data("Right_hand");
       qDebug() << "joint1"<<thumb_point.Get_CurrentPoint_RightHand.Joint1;
       qDebug() << "joint2"<<thumb_point.Get_CurrentPoint_RightHand.Joint2;
       qDebug() << "joint3"<<thumb_point.Get_CurrentPoint_RightHand.Joint3;
       qDebug() << "joint4"<<thumb_point.Get_CurrentPoint_RightHand.Joint4;
       qDebug() << "joint5"<<thumb_point.Get_CurrentPoint_RightHand.Joint5;
       qDebug() << "joint6"<<thumb_point.Get_CurrentPoint_RightHand.Joint6;
       qDebug() << "joint7"<<thumb_point.Get_CurrentPoint_RightHand.Joint7;
       qDebug() << "joint8"<<thumb_point.Get_CurrentPoint_RightHand.Joint8;
       qDebug() << "joint9"<<thumb_point.Get_CurrentPoint_RightHand.Joint9;
       qDebug() << "joint10"<<thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       HandForceParam force;
       force.Joint1 = 240;
       force.Joint2 = 240;
       force.Joint3 = 240;
       force.Joint4 = 240;
       force.Joint5 = 240;
       HumanHandParam speed;
       speed.Joint1 = 1;
       speed.Joint2 = 1;
       speed.Joint3 = 1;
       speed.Joint4 = 1;
       speed.Joint5 = 1;
       speed.Joint6 = 1;
       speed.Joint7 = 1;
       speed.Joint8 = 1;
       speed.Joint9 = 1;
       speed.Joint1_rotation = 1;
       speed.Joint1_tip = 1;
       speed.Joint2_tip = 1;
       speed.Joint3_tip = 1;
       speed.Joint4_tip = 1;
       speed.Joint5_tip = 1;
       speed.Joint3_raw = 1;

       HumanHandParam point;
       point.Joint1 = thumb_point.Get_CurrentPoint_RightHand.Joint1;
       point.Joint2 = thumb_point.Get_CurrentPoint_RightHand.Joint2;
       point.Joint3 = thumb_point.Get_CurrentPoint_RightHand.Joint3;
       point.Joint4 = thumb_point.Get_CurrentPoint_RightHand.Joint4;
       point.Joint5 = thumb_point.Get_CurrentPoint_RightHand.Joint5;
       point.Joint6 = thumb_point.Get_CurrentPoint_RightHand.Joint6;
       point.Joint7 = thumb_point.Get_CurrentPoint_RightHand.Joint7;
       point.Joint8 = thumb_point.Get_CurrentPoint_RightHand.Joint8;
       point.Joint9 = thumb_point.Get_CurrentPoint_RightHand.Joint9 + 20;
       point.Joint1_rotation = thumb_point.Get_CurrentPoint_RightHand.Joint1_rotation;

       if (point.Joint9 >= 250) {
           return;
       }

       hand_position = point;
       Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
       hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_verticalSlider_thumb_swing_sliderMoved(int position)
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = position;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;

        hand_position.Joint2 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);;
    }

    if (hand_right_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = position;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;


        hand_position.Joint2 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = position;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;

        hand_position.Joint2 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = position;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;

        hand_position.Joint2 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = position;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint2 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = position;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint2 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }


}

void Robot_Hand_Ui::on_verticalSlider_index_swing_sliderMoved(int position)
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = position;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;


        hand_position.Joint7 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = position;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;


        hand_position.Joint7 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = position;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;

        hand_position.Joint7 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = position;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;

        hand_position.Joint7 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = position;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint7 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = position;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = position;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint7 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_verticalSlider_middle_swing_sliderMoved(int position)
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }
    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = position;

        hand_position.Joint3_raw = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = position;

        hand_position.Joint3_raw = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_verticalSlider_third_swing_sliderMoved(int position)
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = position;
        point.Joint9 = hand_position.Joint9;


        hand_position.Joint8 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = position;
        point.Joint9 = hand_position.Joint9;


        hand_position.Joint8 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = position;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;

        hand_position.Joint8 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = position;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;

        hand_position.Joint8 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = position;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint8 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = position;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint8 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_verticalSlider_pinkie_swing_sliderMoved(int position)
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = position;


        hand_position.Joint9 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = position;


        hand_position.Joint9 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = position;
        point.Joint1_rotation = hand_position.Joint1_rotation;

        hand_position.Joint9 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = position;
        point.Joint1_rotation = hand_position.Joint1_rotation;

        hand_position.Joint9 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = position;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint9 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = position;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint9 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_verticalSlider_thumb_roll_sliderMoved(int position)
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = position;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;


        hand_position.Joint1 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = position;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;


        hand_position.Joint1 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = position;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;

        hand_position.Joint1 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = position;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;

        hand_position.Joint1 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = position;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint1 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = position;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint1 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_verticalSlider_index_roll_sliderMoved(int position)
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = position;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;


        hand_position.Joint3 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = position;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;


        hand_position.Joint3 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = position;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;


        hand_position.Joint3 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = position;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;


        hand_position.Joint3 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = position;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;


        hand_position.Joint3 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = position;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;


        hand_position.Joint3 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_verticalSlider_middle_roll_sliderMoved(int position)
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = position;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;


        hand_position.Joint4 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = position;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;


        hand_position.Joint4 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = position;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;


        hand_position.Joint4 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = position;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;


        hand_position.Joint4 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = position;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint4 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = position;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint4 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_verticalSlider_third_roll_sliderMoved(int position)
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = position;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;


        hand_position.Joint5 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = position;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;


        hand_position.Joint5 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = position;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;

        hand_position.Joint5 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = position;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;

        hand_position.Joint5 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = position;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint5 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = position;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint5 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_verticalSlider_pinkie_roll_sliderMoved(int position)
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = position;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;


        hand_position.Joint6 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Left_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_right_9deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;


        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = position;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;


        hand_position.Joint6 = position;

        Hand_Control->Hand_SendStructDataDeal(9, "Right_Hand",force, speed, point);
        hand_9deg_dataUpdate(hand_position);
    }

    if (hand_left_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = position;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;

        hand_position.Joint6 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = position;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;

        hand_position.Joint6 = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = position;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint6 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = position;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint6 = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }
}



void Robot_Hand_Ui::on_verticalSlider_thumb_tip_sliderMoved(int position)
{

    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = position;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint1_tip = position;
        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = position;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint1_tip = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_verticalSlider_index_tip_sliderMoved(int position)
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = position;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint2_tip = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = position;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint2_tip = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_verticalSlider_middle_tip_sliderMoved(int position)
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = position;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint3_tip = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = position;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint3_tip = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_verticalSlider_third_tip_sliderMoved(int position)
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = position;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint4_tip = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = position;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint4_tip = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_verticalSlider_pinkie_tip_sliderMoved(int position)
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = position;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint5_tip = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = hand_position.Joint1_rotation;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = position;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint5_tip = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }
}

void Robot_Hand_Ui::on_verticalSlider_thumb_rotation_sliderMoved(int position)
{
    bool hand_left_9deg = false;
    bool hand_left_10deg = false;
    bool hand_left_16deg = false;
    bool hand_right_9deg = false;
    bool hand_right_10deg = false;
    bool hand_right_16deg = false;
    if (hand_9deg == true) {
        if (hand_left == true) {
            hand_left_9deg = true;
        }
    }

    if (hand_9deg == true) {
        if (hand_right == true) {
            hand_right_9deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_left == true) {
            hand_left_10deg = true;
        }
    }

    if (hand_10deg == true) {
        if (hand_right == true) {
            hand_right_10deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_left == true) {
            hand_left_16deg = true;
        }
    }

    if (hand_16deg == true) {
        if (hand_right == true) {
            hand_right_16deg = true;
        }
    }

    if (hand_left_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = position;

        hand_position.Joint1_rotation = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Left_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }

    if (hand_right_10deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = position;

        hand_position.Joint1_rotation = position;

        Hand_Control->Hand_SendStructDataDeal(10, "Right_Hand",force, speed, point);
        hand_10deg_dataUpdate(hand_position);
    }


    if (hand_left_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = position;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint1_rotation = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Left_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }

    if (hand_right_16deg == true) {
        HandForceParam force;
        force.Joint1 = 240;
        force.Joint2 = 240;
        force.Joint3 = 240;
        force.Joint4 = 240;
        force.Joint5 = 240;

        HumanHandParam speed;
        speed.Joint1 = 1;
        speed.Joint2 = 1;
        speed.Joint3 = 1;
        speed.Joint4 = 1;
        speed.Joint5 = 1;
        speed.Joint6 = 1;
        speed.Joint7 = 1;
        speed.Joint8 = 1;
        speed.Joint9 = 1;
        speed.Joint1_rotation = 1;
        speed.Joint1_tip = 1;
        speed.Joint2_tip = 1;
        speed.Joint3_tip = 1;
        speed.Joint4_tip = 1;
        speed.Joint5_tip = 1;
        speed.Joint3_raw = 1;

        HumanHandParam point;
        point.Joint1 = hand_position.Joint1;
        point.Joint2 = hand_position.Joint2;
        point.Joint3 = hand_position.Joint3;
        point.Joint4 = hand_position.Joint4;
        point.Joint5 = hand_position.Joint5;
        point.Joint6 = hand_position.Joint6;
        point.Joint7 = hand_position.Joint7;
        point.Joint8 = hand_position.Joint8;
        point.Joint9 = hand_position.Joint9;
        point.Joint1_rotation = position;
        point.Joint1_tip = hand_position.Joint1_tip;
        point.Joint2_tip = hand_position.Joint2_tip;
        point.Joint3_tip = hand_position.Joint3_tip;
        point.Joint4_tip = hand_position.Joint4_tip;
        point.Joint5_tip = hand_position.Joint5_tip;
        point.Joint3_raw = hand_position.Joint3_raw;

        hand_position.Joint1_rotation = position;

        Hand_Control->Hand_SendStructDataDeal(16, "Right_Hand",force, speed, point);
        hand_16deg_dataUpdate(hand_position);
    }
}
