/********************************************************************************
** Form generated from reading UI file 'robot_hand_ui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOT_HAND_UI_H
#define UI_ROBOT_HAND_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Robot_Hand_Ui
{
public:
    QWidget *frame_background;
    QGridLayout *gridLayout;
    QFrame *frame_background_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_16;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *verticalSpacer_13;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QGridLayout *gridLayout_3;
    QLabel *label_index_swing_slider;
    QSpacerItem *verticalSpacer_15;
    QLabel *label_pinkie_swing_slider;
    QLabel *label_thumb_swing_slider;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_third_swing_slider;
    QSpacerItem *verticalSpacer_14;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_middle_swing_slider;
    QFrame *frame_12;
    QSlider *verticalSlider_thumb_swing;
    QSlider *verticalSlider_index_swing;
    QSlider *verticalSlider_middle_swing;
    QSlider *verticalSlider_third_swing;
    QSlider *verticalSlider_pinkie_swing;
    QVBoxLayout *verticalLayout;
    QFrame *frame_7;
    QLabel *label_thumb_swing;
    QPushButton *button_thumb_swing_out;
    QPushButton *button_thumb_swing_in;
    QFrame *frame_8;
    QLabel *label_index_swing;
    QPushButton *button_index_swing_out;
    QPushButton *button_index_swing_in;
    QFrame *frame_9;
    QPushButton *button_middle_swing_in;
    QPushButton *button_middle_swing_out;
    QLabel *label_middle_swing;
    QFrame *frame_10;
    QPushButton *button_third_swing_in;
    QPushButton *button_third_swing_out;
    QLabel *label_third_swing;
    QFrame *frame_11;
    QLabel *label_pinkie_swing;
    QPushButton *button_pinkie_swing_out;
    QPushButton *button_pinkie_swing_in;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_11;
    QFrame *frame_6;
    QPushButton *Hand_Close;
    QPushButton *Hand_Open;
    QLabel *label_allfinger;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame;
    QPushButton *button_thumb_straight;
    QPushButton *button_thumb_roll;
    QLabel *label_thumb;
    QSpacerItem *verticalSpacer_6;
    QFrame *frame_2;
    QLabel *label_index;
    QPushButton *button_index_roll;
    QPushButton *button_index_straight;
    QSpacerItem *verticalSpacer_7;
    QFrame *frame_3;
    QPushButton *button_middle_roll;
    QPushButton *button_middle_straight;
    QLabel *label_middle;
    QSpacerItem *verticalSpacer_8;
    QFrame *frame_4;
    QPushButton *button_third_roll;
    QLabel *label_third;
    QPushButton *button_third_straight;
    QSpacerItem *verticalSpacer_9;
    QFrame *frame_5;
    QPushButton *button_pinkie_roll;
    QLabel *label_pinkie;
    QPushButton *button_pinkie_straight;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *horizontalSpacer_6;
    QFrame *frame_15;
    QLabel *label_left_switch;
    QLabel *label_right_switch;
    QLabel *label_9deg_switch;
    QLabel *label_16deg_switch;
    QLabel *label_10deg_switch;
    QLabel *label_connect_state;
    QGridLayout *gridLayout_4;
    QLabel *label_index_roll_slider;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_thumb_roll_slider;
    QLabel *label_middle_roll_slider;
    QSpacerItem *verticalSpacer_17;
    QLabel *label_third_roll_slider;
    QFrame *frame_13;
    QSlider *verticalSlider_thumb_roll;
    QSlider *verticalSlider_index_roll;
    QSlider *verticalSlider_middle_roll;
    QSlider *verticalSlider_third_roll;
    QSlider *verticalSlider_pinkie_roll;
    QLabel *label_pinkie_roll_slider;
    QFrame *frame_16;
    QSlider *verticalSlider_thumb_tip;
    QSlider *verticalSlider_index_tip;
    QSlider *verticalSlider_middle_tip;
    QSlider *verticalSlider_third_tip;
    QSlider *verticalSlider_pinkie_tip;
    QLabel *label_thumb_tip_slider;
    QLabel *label_index_tip_slider;
    QLabel *label_middle_tip_slider;
    QLabel *label_third_tip_slider;
    QLabel *label_pinkie_tip_slider;
    QFrame *frame_17;
    QSlider *verticalSlider_thumb_rotation;
    QLabel *label_thumb_rotation_slider;
    QFrame *frame_14;
    QTableWidget *tableWidget_hand_data;
    QPushButton *read_data;
    QHBoxLayout *horizontalLayout;
    QPushButton *TCP_Connect_Stop;
    QPushButton *TCP_Connect_Start;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;

    void setupUi(QMainWindow *Robot_Hand_Ui)
    {
        if (Robot_Hand_Ui->objectName().isEmpty())
            Robot_Hand_Ui->setObjectName(QString::fromUtf8("Robot_Hand_Ui"));
        Robot_Hand_Ui->resize(1800, 1227);
        Robot_Hand_Ui->setMouseTracking(true);
        Robot_Hand_Ui->setFocusPolicy(Qt::StrongFocus);
        frame_background = new QWidget(Robot_Hand_Ui);
        frame_background->setObjectName(QString::fromUtf8("frame_background"));
        gridLayout = new QGridLayout(frame_background);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame_background_2 = new QFrame(frame_background);
        frame_background_2->setObjectName(QString::fromUtf8("frame_background_2"));
        frame_background_2->setFrameShape(QFrame::StyledPanel);
        frame_background_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_background_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_16 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_16, 3, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 2, 5, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_12, 1, 6, 1, 1);

        verticalSpacer_13 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_13, 6, 6, 1, 1);

        verticalSpacer = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 8, 6, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_4, 0, 6, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_3->setContentsMargins(-1, -1, -1, 0);
        label_index_swing_slider = new QLabel(frame_background_2);
        label_index_swing_slider->setObjectName(QString::fromUtf8("label_index_swing_slider"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        label_index_swing_slider->setFont(font);

        gridLayout_3->addWidget(label_index_swing_slider, 2, 2, 1, 1);

        verticalSpacer_15 = new QSpacerItem(20, 70, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_15, 0, 1, 1, 1);

        label_pinkie_swing_slider = new QLabel(frame_background_2);
        label_pinkie_swing_slider->setObjectName(QString::fromUtf8("label_pinkie_swing_slider"));
        label_pinkie_swing_slider->setFont(font);

        gridLayout_3->addWidget(label_pinkie_swing_slider, 2, 5, 1, 1);

        label_thumb_swing_slider = new QLabel(frame_background_2);
        label_thumb_swing_slider->setObjectName(QString::fromUtf8("label_thumb_swing_slider"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_thumb_swing_slider->sizePolicy().hasHeightForWidth());
        label_thumb_swing_slider->setSizePolicy(sizePolicy);
        label_thumb_swing_slider->setMinimumSize(QSize(0, 0));
        label_thumb_swing_slider->setMaximumSize(QSize(16777215, 20));
        label_thumb_swing_slider->setSizeIncrement(QSize(0, 0));
        label_thumb_swing_slider->setFont(font);

        gridLayout_3->addWidget(label_thumb_swing_slider, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 6, 1, 1);

        label_third_swing_slider = new QLabel(frame_background_2);
        label_third_swing_slider->setObjectName(QString::fromUtf8("label_third_swing_slider"));
        label_third_swing_slider->setFont(font);

        gridLayout_3->addWidget(label_third_swing_slider, 2, 4, 1, 1);

        verticalSpacer_14 = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_14, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(390, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        label_middle_swing_slider = new QLabel(frame_background_2);
        label_middle_swing_slider->setObjectName(QString::fromUtf8("label_middle_swing_slider"));
        label_middle_swing_slider->setFont(font);

        gridLayout_3->addWidget(label_middle_swing_slider, 2, 3, 1, 1);

        frame_12 = new QFrame(frame_background_2);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setMinimumSize(QSize(0, 170));
        frame_12->setMaximumSize(QSize(16777215, 170));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        verticalSlider_thumb_swing = new QSlider(frame_12);
        verticalSlider_thumb_swing->setObjectName(QString::fromUtf8("verticalSlider_thumb_swing"));
        verticalSlider_thumb_swing->setEnabled(true);
        verticalSlider_thumb_swing->setGeometry(QRect(420, 0, 20, 166));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(verticalSlider_thumb_swing->sizePolicy().hasHeightForWidth());
        verticalSlider_thumb_swing->setSizePolicy(sizePolicy1);
        verticalSlider_thumb_swing->setMinimumSize(QSize(0, 0));
        verticalSlider_thumb_swing->setMaximumSize(QSize(20, 200));
        verticalSlider_thumb_swing->setSizeIncrement(QSize(0, 0));
        verticalSlider_thumb_swing->setBaseSize(QSize(0, 0));
        verticalSlider_thumb_swing->setFocusPolicy(Qt::NoFocus);
        verticalSlider_thumb_swing->setLayoutDirection(Qt::LeftToRight);
        verticalSlider_thumb_swing->setMaximum(250);
        verticalSlider_thumb_swing->setOrientation(Qt::Vertical);
        verticalSlider_thumb_swing->setTickPosition(QSlider::NoTicks);
        verticalSlider_index_swing = new QSlider(frame_12);
        verticalSlider_index_swing->setObjectName(QString::fromUtf8("verticalSlider_index_swing"));
        verticalSlider_index_swing->setGeometry(QRect(500, 0, 20, 166));
        sizePolicy1.setHeightForWidth(verticalSlider_index_swing->sizePolicy().hasHeightForWidth());
        verticalSlider_index_swing->setSizePolicy(sizePolicy1);
        verticalSlider_index_swing->setMaximumSize(QSize(20, 200));
        verticalSlider_index_swing->setMaximum(250);
        verticalSlider_index_swing->setOrientation(Qt::Vertical);
        verticalSlider_middle_swing = new QSlider(frame_12);
        verticalSlider_middle_swing->setObjectName(QString::fromUtf8("verticalSlider_middle_swing"));
        verticalSlider_middle_swing->setGeometry(QRect(590, 0, 20, 166));
        sizePolicy1.setHeightForWidth(verticalSlider_middle_swing->sizePolicy().hasHeightForWidth());
        verticalSlider_middle_swing->setSizePolicy(sizePolicy1);
        verticalSlider_middle_swing->setMaximumSize(QSize(20, 200));
        verticalSlider_middle_swing->setMaximum(250);
        verticalSlider_middle_swing->setOrientation(Qt::Vertical);
        verticalSlider_third_swing = new QSlider(frame_12);
        verticalSlider_third_swing->setObjectName(QString::fromUtf8("verticalSlider_third_swing"));
        verticalSlider_third_swing->setGeometry(QRect(680, 0, 20, 166));
        sizePolicy1.setHeightForWidth(verticalSlider_third_swing->sizePolicy().hasHeightForWidth());
        verticalSlider_third_swing->setSizePolicy(sizePolicy1);
        verticalSlider_third_swing->setMaximumSize(QSize(20, 200));
        verticalSlider_third_swing->setMaximum(250);
        verticalSlider_third_swing->setOrientation(Qt::Vertical);
        verticalSlider_pinkie_swing = new QSlider(frame_12);
        verticalSlider_pinkie_swing->setObjectName(QString::fromUtf8("verticalSlider_pinkie_swing"));
        verticalSlider_pinkie_swing->setGeometry(QRect(780, 0, 20, 166));
        sizePolicy1.setHeightForWidth(verticalSlider_pinkie_swing->sizePolicy().hasHeightForWidth());
        verticalSlider_pinkie_swing->setSizePolicy(sizePolicy1);
        verticalSlider_pinkie_swing->setMaximumSize(QSize(20, 200));
        verticalSlider_pinkie_swing->setMaximum(250);
        verticalSlider_pinkie_swing->setOrientation(Qt::Vertical);

        gridLayout_3->addWidget(frame_12, 1, 0, 1, 7);


        gridLayout_2->addLayout(gridLayout_3, 2, 2, 1, 3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_7 = new QFrame(frame_background_2);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        sizePolicy.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy);
        frame_7->setMinimumSize(QSize(0, 60));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        label_thumb_swing = new QLabel(frame_7);
        label_thumb_swing->setObjectName(QString::fromUtf8("label_thumb_swing"));
        label_thumb_swing->setGeometry(QRect(170, 20, 54, 31));
        QFont font1;
        font1.setPointSize(9);
        label_thumb_swing->setFont(font1);
        label_thumb_swing->setAlignment(Qt::AlignCenter);
        button_thumb_swing_out = new QPushButton(frame_7);
        button_thumb_swing_out->setObjectName(QString::fromUtf8("button_thumb_swing_out"));
        button_thumb_swing_out->setGeometry(QRect(100, 10, 325, 12));
        button_thumb_swing_out->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        button_thumb_swing_in = new QPushButton(frame_7);
        button_thumb_swing_in->setObjectName(QString::fromUtf8("button_thumb_swing_in"));
        button_thumb_swing_in->setGeometry(QRect(100, 10, 325, 12));
        button_thumb_swing_in->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        button_thumb_swing_out->raise();
        button_thumb_swing_in->raise();
        label_thumb_swing->raise();

        verticalLayout->addWidget(frame_7);

        frame_8 = new QFrame(frame_background_2);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        sizePolicy.setHeightForWidth(frame_8->sizePolicy().hasHeightForWidth());
        frame_8->setSizePolicy(sizePolicy);
        frame_8->setMinimumSize(QSize(0, 60));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        label_index_swing = new QLabel(frame_8);
        label_index_swing->setObjectName(QString::fromUtf8("label_index_swing"));
        label_index_swing->setGeometry(QRect(170, 20, 54, 31));
        label_index_swing->setFont(font1);
        label_index_swing->setAlignment(Qt::AlignCenter);
        button_index_swing_out = new QPushButton(frame_8);
        button_index_swing_out->setObjectName(QString::fromUtf8("button_index_swing_out"));
        button_index_swing_out->setGeometry(QRect(100, 10, 325, 12));
        button_index_swing_out->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        button_index_swing_in = new QPushButton(frame_8);
        button_index_swing_in->setObjectName(QString::fromUtf8("button_index_swing_in"));
        button_index_swing_in->setGeometry(QRect(100, 10, 325, 12));
        button_index_swing_in->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        button_index_swing_out->raise();
        button_index_swing_in->raise();
        label_index_swing->raise();

        verticalLayout->addWidget(frame_8);

        frame_9 = new QFrame(frame_background_2);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        sizePolicy.setHeightForWidth(frame_9->sizePolicy().hasHeightForWidth());
        frame_9->setSizePolicy(sizePolicy);
        frame_9->setMinimumSize(QSize(0, 60));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        button_middle_swing_in = new QPushButton(frame_9);
        button_middle_swing_in->setObjectName(QString::fromUtf8("button_middle_swing_in"));
        button_middle_swing_in->setGeometry(QRect(100, 10, 325, 12));
        button_middle_swing_in->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        button_middle_swing_out = new QPushButton(frame_9);
        button_middle_swing_out->setObjectName(QString::fromUtf8("button_middle_swing_out"));
        button_middle_swing_out->setGeometry(QRect(100, 10, 325, 12));
        button_middle_swing_out->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        label_middle_swing = new QLabel(frame_9);
        label_middle_swing->setObjectName(QString::fromUtf8("label_middle_swing"));
        label_middle_swing->setGeometry(QRect(170, 20, 54, 31));
        label_middle_swing->setFont(font1);
        label_middle_swing->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(frame_9);

        frame_10 = new QFrame(frame_background_2);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        sizePolicy.setHeightForWidth(frame_10->sizePolicy().hasHeightForWidth());
        frame_10->setSizePolicy(sizePolicy);
        frame_10->setMinimumSize(QSize(0, 60));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        button_third_swing_in = new QPushButton(frame_10);
        button_third_swing_in->setObjectName(QString::fromUtf8("button_third_swing_in"));
        button_third_swing_in->setGeometry(QRect(100, 10, 325, 12));
        button_third_swing_in->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        button_third_swing_out = new QPushButton(frame_10);
        button_third_swing_out->setObjectName(QString::fromUtf8("button_third_swing_out"));
        button_third_swing_out->setGeometry(QRect(100, 10, 325, 12));
        button_third_swing_out->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        label_third_swing = new QLabel(frame_10);
        label_third_swing->setObjectName(QString::fromUtf8("label_third_swing"));
        label_third_swing->setGeometry(QRect(170, 20, 54, 31));
        label_third_swing->setFont(font1);
        label_third_swing->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(frame_10);

        frame_11 = new QFrame(frame_background_2);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        sizePolicy.setHeightForWidth(frame_11->sizePolicy().hasHeightForWidth());
        frame_11->setSizePolicy(sizePolicy);
        frame_11->setMinimumSize(QSize(0, 60));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        label_pinkie_swing = new QLabel(frame_11);
        label_pinkie_swing->setObjectName(QString::fromUtf8("label_pinkie_swing"));
        label_pinkie_swing->setGeometry(QRect(170, 20, 54, 31));
        label_pinkie_swing->setFont(font1);
        label_pinkie_swing->setAlignment(Qt::AlignCenter);
        button_pinkie_swing_out = new QPushButton(frame_11);
        button_pinkie_swing_out->setObjectName(QString::fromUtf8("button_pinkie_swing_out"));
        button_pinkie_swing_out->setGeometry(QRect(100, 10, 325, 12));
        button_pinkie_swing_out->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        button_pinkie_swing_in = new QPushButton(frame_11);
        button_pinkie_swing_in->setObjectName(QString::fromUtf8("button_pinkie_swing_in"));
        button_pinkie_swing_in->setGeometry(QRect(100, 10, 325, 12));
        button_pinkie_swing_in->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        button_pinkie_swing_out->raise();
        button_pinkie_swing_in->raise();
        label_pinkie_swing->raise();

        verticalLayout->addWidget(frame_11);


        gridLayout_2->addLayout(verticalLayout, 2, 6, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(100, 0, -1, 0);
        verticalSpacer_11 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_11);

        frame_6 = new QFrame(frame_background_2);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        sizePolicy.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy);
        frame_6->setMinimumSize(QSize(0, 60));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        Hand_Close = new QPushButton(frame_6);
        Hand_Close->setObjectName(QString::fromUtf8("Hand_Close"));
        Hand_Close->setGeometry(QRect(0, 10, 325, 12));
        Hand_Close->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        Hand_Open = new QPushButton(frame_6);
        Hand_Open->setObjectName(QString::fromUtf8("Hand_Open"));
        Hand_Open->setGeometry(QRect(0, 10, 325, 12));
        Hand_Open->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        label_allfinger = new QLabel(frame_6);
        label_allfinger->setObjectName(QString::fromUtf8("label_allfinger"));
        label_allfinger->setGeometry(QRect(70, 20, 54, 31));
        label_allfinger->setFont(font1);
        label_allfinger->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(frame_6);

        verticalSpacer_2 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        frame = new QFrame(frame_background_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(0, 60));
        frame->setFont(font1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        button_thumb_straight = new QPushButton(frame);
        button_thumb_straight->setObjectName(QString::fromUtf8("button_thumb_straight"));
        button_thumb_straight->setGeometry(QRect(0, 10, 325, 12));
        button_thumb_straight->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        button_thumb_roll = new QPushButton(frame);
        button_thumb_roll->setObjectName(QString::fromUtf8("button_thumb_roll"));
        button_thumb_roll->setGeometry(QRect(0, 10, 325, 12));
        button_thumb_roll->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        label_thumb = new QLabel(frame);
        label_thumb->setObjectName(QString::fromUtf8("label_thumb"));
        label_thumb->setGeometry(QRect(70, 20, 54, 31));
        label_thumb->setFont(font1);
        label_thumb->setAlignment(Qt::AlignCenter);
        button_thumb_roll->raise();
        button_thumb_straight->raise();
        label_thumb->raise();

        verticalLayout_2->addWidget(frame);

        verticalSpacer_6 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_6);

        frame_2 = new QFrame(frame_background_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(0, 60));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_index = new QLabel(frame_2);
        label_index->setObjectName(QString::fromUtf8("label_index"));
        label_index->setGeometry(QRect(70, 20, 54, 31));
        label_index->setFont(font1);
        label_index->setAlignment(Qt::AlignCenter);
        button_index_roll = new QPushButton(frame_2);
        button_index_roll->setObjectName(QString::fromUtf8("button_index_roll"));
        button_index_roll->setGeometry(QRect(0, 10, 325, 12));
        button_index_roll->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        button_index_straight = new QPushButton(frame_2);
        button_index_straight->setObjectName(QString::fromUtf8("button_index_straight"));
        button_index_straight->setGeometry(QRect(0, 10, 325, 12));
        button_index_straight->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        button_index_roll->raise();
        button_index_straight->raise();
        label_index->raise();

        verticalLayout_2->addWidget(frame_2);

        verticalSpacer_7 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_7);

        frame_3 = new QFrame(frame_background_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setMinimumSize(QSize(0, 60));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        button_middle_roll = new QPushButton(frame_3);
        button_middle_roll->setObjectName(QString::fromUtf8("button_middle_roll"));
        button_middle_roll->setGeometry(QRect(0, 10, 325, 12));
        button_middle_roll->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        button_middle_straight = new QPushButton(frame_3);
        button_middle_straight->setObjectName(QString::fromUtf8("button_middle_straight"));
        button_middle_straight->setGeometry(QRect(0, 10, 325, 12));
        button_middle_straight->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        label_middle = new QLabel(frame_3);
        label_middle->setObjectName(QString::fromUtf8("label_middle"));
        label_middle->setGeometry(QRect(70, 20, 54, 31));
        label_middle->setFont(font1);
        label_middle->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(frame_3);

        verticalSpacer_8 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_8);

        frame_4 = new QFrame(frame_background_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setMinimumSize(QSize(0, 60));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        button_third_roll = new QPushButton(frame_4);
        button_third_roll->setObjectName(QString::fromUtf8("button_third_roll"));
        button_third_roll->setGeometry(QRect(0, 10, 325, 12));
        button_third_roll->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        label_third = new QLabel(frame_4);
        label_third->setObjectName(QString::fromUtf8("label_third"));
        label_third->setGeometry(QRect(70, 20, 54, 31));
        label_third->setFont(font1);
        label_third->setAlignment(Qt::AlignCenter);
        button_third_straight = new QPushButton(frame_4);
        button_third_straight->setObjectName(QString::fromUtf8("button_third_straight"));
        button_third_straight->setGeometry(QRect(0, 10, 325, 12));
        button_third_straight->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        button_third_roll->raise();
        button_third_straight->raise();
        label_third->raise();

        verticalLayout_2->addWidget(frame_4);

        verticalSpacer_9 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_9);

        frame_5 = new QFrame(frame_background_2);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setMinimumSize(QSize(0, 60));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        button_pinkie_roll = new QPushButton(frame_5);
        button_pinkie_roll->setObjectName(QString::fromUtf8("button_pinkie_roll"));
        button_pinkie_roll->setGeometry(QRect(0, 10, 325, 12));
        button_pinkie_roll->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        label_pinkie = new QLabel(frame_5);
        label_pinkie->setObjectName(QString::fromUtf8("label_pinkie"));
        label_pinkie->setGeometry(QRect(70, 20, 54, 31));
        label_pinkie->setFont(font1);
        label_pinkie->setAlignment(Qt::AlignCenter);
        button_pinkie_straight = new QPushButton(frame_5);
        button_pinkie_straight->setObjectName(QString::fromUtf8("button_pinkie_straight"));
        button_pinkie_straight->setGeometry(QRect(0, 10, 325, 12));
        button_pinkie_straight->setStyleSheet(QString::fromUtf8("QPushButton{border-image:url(:/res/pic/slices/pic_background.png)}"));
        button_pinkie_roll->raise();
        button_pinkie_straight->raise();
        label_pinkie->raise();

        verticalLayout_2->addWidget(frame_5);

        verticalSpacer_10 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_10);


        gridLayout_2->addLayout(verticalLayout_2, 4, 6, 2, 1);

        horizontalSpacer_6 = new QSpacerItem(240, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 2, 1, 1, 1);

        frame_15 = new QFrame(frame_background_2);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        label_left_switch = new QLabel(frame_15);
        label_left_switch->setObjectName(QString::fromUtf8("label_left_switch"));
        label_left_switch->setGeometry(QRect(110, 25, 128, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setWeight(50);
        label_left_switch->setFont(font2);
        label_left_switch->setScaledContents(false);
        label_left_switch->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_left_switch->setWordWrap(false);
        label_left_switch->setMargin(0);
        label_left_switch->setIndent(28);
        label_right_switch = new QLabel(frame_15);
        label_right_switch->setObjectName(QString::fromUtf8("label_right_switch"));
        label_right_switch->setGeometry(QRect(263, 25, 128, 50));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font3.setPointSize(8);
        label_right_switch->setFont(font3);
        label_right_switch->setMargin(0);
        label_right_switch->setIndent(30);
        label_9deg_switch = new QLabel(frame_15);
        label_9deg_switch->setObjectName(QString::fromUtf8("label_9deg_switch"));
        label_9deg_switch->setGeometry(QRect(110, 100, 128, 50));
        label_9deg_switch->setFont(font3);
        label_9deg_switch->setIndent(20);
        label_16deg_switch = new QLabel(frame_15);
        label_16deg_switch->setObjectName(QString::fromUtf8("label_16deg_switch"));
        label_16deg_switch->setGeometry(QRect(416, 100, 128, 50));
        label_16deg_switch->setFont(font3);
        label_16deg_switch->setIndent(20);
        label_10deg_switch = new QLabel(frame_15);
        label_10deg_switch->setObjectName(QString::fromUtf8("label_10deg_switch"));
        label_10deg_switch->setGeometry(QRect(263, 100, 128, 50));
        label_10deg_switch->setFont(font3);
        label_10deg_switch->setIndent(20);
        label_connect_state = new QLabel(frame_15);
        label_connect_state->setObjectName(QString::fromUtf8("label_connect_state"));
        label_connect_state->setGeometry(QRect(416, 25, 128, 50));
        label_connect_state->setFont(font3);
        label_connect_state->setMargin(0);
        label_connect_state->setIndent(30);

        gridLayout_2->addWidget(frame_15, 7, 3, 2, 2);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_index_roll_slider = new QLabel(frame_background_2);
        label_index_roll_slider->setObjectName(QString::fromUtf8("label_index_roll_slider"));
        sizePolicy.setHeightForWidth(label_index_roll_slider->sizePolicy().hasHeightForWidth());
        label_index_roll_slider->setSizePolicy(sizePolicy);
        label_index_roll_slider->setFont(font);

        gridLayout_4->addWidget(label_index_roll_slider, 1, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_7, 1, 6, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 1, 0, 1, 1);

        label_thumb_roll_slider = new QLabel(frame_background_2);
        label_thumb_roll_slider->setObjectName(QString::fromUtf8("label_thumb_roll_slider"));
        sizePolicy.setHeightForWidth(label_thumb_roll_slider->sizePolicy().hasHeightForWidth());
        label_thumb_roll_slider->setSizePolicy(sizePolicy);
        label_thumb_roll_slider->setMinimumSize(QSize(0, 10));
        label_thumb_roll_slider->setMaximumSize(QSize(16777215, 20));
        label_thumb_roll_slider->setFont(font);

        gridLayout_4->addWidget(label_thumb_roll_slider, 1, 1, 1, 1);

        label_middle_roll_slider = new QLabel(frame_background_2);
        label_middle_roll_slider->setObjectName(QString::fromUtf8("label_middle_roll_slider"));
        sizePolicy.setHeightForWidth(label_middle_roll_slider->sizePolicy().hasHeightForWidth());
        label_middle_roll_slider->setSizePolicy(sizePolicy);
        label_middle_roll_slider->setFont(font);

        gridLayout_4->addWidget(label_middle_roll_slider, 1, 3, 1, 1);

        verticalSpacer_17 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_17, 2, 2, 1, 1);

        label_third_roll_slider = new QLabel(frame_background_2);
        label_third_roll_slider->setObjectName(QString::fromUtf8("label_third_roll_slider"));
        sizePolicy.setHeightForWidth(label_third_roll_slider->sizePolicy().hasHeightForWidth());
        label_third_roll_slider->setSizePolicy(sizePolicy);
        label_third_roll_slider->setFont(font);

        gridLayout_4->addWidget(label_third_roll_slider, 1, 4, 1, 1);

        frame_13 = new QFrame(frame_background_2);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_13->sizePolicy().hasHeightForWidth());
        frame_13->setSizePolicy(sizePolicy2);
        frame_13->setMinimumSize(QSize(0, 210));
        frame_13->setMaximumSize(QSize(16777215, 200));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        verticalSlider_thumb_roll = new QSlider(frame_13);
        verticalSlider_thumb_roll->setObjectName(QString::fromUtf8("verticalSlider_thumb_roll"));
        verticalSlider_thumb_roll->setGeometry(QRect(130, 40, 20, 166));
        verticalSlider_thumb_roll->setStyleSheet(QString::fromUtf8(""));
        verticalSlider_thumb_roll->setMaximum(250);
        verticalSlider_thumb_roll->setOrientation(Qt::Vertical);
        verticalSlider_index_roll = new QSlider(frame_13);
        verticalSlider_index_roll->setObjectName(QString::fromUtf8("verticalSlider_index_roll"));
        verticalSlider_index_roll->setGeometry(QRect(210, 40, 20, 166));
        verticalSlider_index_roll->setMaximum(250);
        verticalSlider_index_roll->setOrientation(Qt::Vertical);
        verticalSlider_middle_roll = new QSlider(frame_13);
        verticalSlider_middle_roll->setObjectName(QString::fromUtf8("verticalSlider_middle_roll"));
        verticalSlider_middle_roll->setGeometry(QRect(300, 40, 20, 166));
        verticalSlider_middle_roll->setMaximum(250);
        verticalSlider_middle_roll->setOrientation(Qt::Vertical);
        verticalSlider_third_roll = new QSlider(frame_13);
        verticalSlider_third_roll->setObjectName(QString::fromUtf8("verticalSlider_third_roll"));
        verticalSlider_third_roll->setGeometry(QRect(390, 40, 20, 166));
        verticalSlider_third_roll->setMaximum(250);
        verticalSlider_third_roll->setOrientation(Qt::Vertical);
        verticalSlider_pinkie_roll = new QSlider(frame_13);
        verticalSlider_pinkie_roll->setObjectName(QString::fromUtf8("verticalSlider_pinkie_roll"));
        verticalSlider_pinkie_roll->setGeometry(QRect(490, 40, 20, 166));
        QFont font4;
        font4.setFamily(QString::fromUtf8("ADMUI3Lg"));
        verticalSlider_pinkie_roll->setFont(font4);
        verticalSlider_pinkie_roll->setMaximum(250);
        verticalSlider_pinkie_roll->setOrientation(Qt::Vertical);

        gridLayout_4->addWidget(frame_13, 0, 0, 1, 6);

        label_pinkie_roll_slider = new QLabel(frame_background_2);
        label_pinkie_roll_slider->setObjectName(QString::fromUtf8("label_pinkie_roll_slider"));
        sizePolicy.setHeightForWidth(label_pinkie_roll_slider->sizePolicy().hasHeightForWidth());
        label_pinkie_roll_slider->setSizePolicy(sizePolicy);
        label_pinkie_roll_slider->setFont(font);

        gridLayout_4->addWidget(label_pinkie_roll_slider, 1, 5, 1, 1);

        frame_16 = new QFrame(frame_background_2);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_16->sizePolicy().hasHeightForWidth());
        frame_16->setSizePolicy(sizePolicy3);
        frame_16->setMinimumSize(QSize(540, 200));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        verticalSlider_thumb_tip = new QSlider(frame_16);
        verticalSlider_thumb_tip->setObjectName(QString::fromUtf8("verticalSlider_thumb_tip"));
        verticalSlider_thumb_tip->setGeometry(QRect(130, 0, 20, 166));
        verticalSlider_thumb_tip->setOrientation(Qt::Vertical);
        verticalSlider_index_tip = new QSlider(frame_16);
        verticalSlider_index_tip->setObjectName(QString::fromUtf8("verticalSlider_index_tip"));
        verticalSlider_index_tip->setGeometry(QRect(210, 0, 20, 166));
        verticalSlider_index_tip->setOrientation(Qt::Vertical);
        verticalSlider_middle_tip = new QSlider(frame_16);
        verticalSlider_middle_tip->setObjectName(QString::fromUtf8("verticalSlider_middle_tip"));
        verticalSlider_middle_tip->setGeometry(QRect(300, 0, 20, 166));
        verticalSlider_middle_tip->setOrientation(Qt::Vertical);
        verticalSlider_third_tip = new QSlider(frame_16);
        verticalSlider_third_tip->setObjectName(QString::fromUtf8("verticalSlider_third_tip"));
        verticalSlider_third_tip->setGeometry(QRect(390, 0, 20, 166));
        verticalSlider_third_tip->setOrientation(Qt::Vertical);
        verticalSlider_pinkie_tip = new QSlider(frame_16);
        verticalSlider_pinkie_tip->setObjectName(QString::fromUtf8("verticalSlider_pinkie_tip"));
        verticalSlider_pinkie_tip->setGeometry(QRect(490, 0, 20, 166));
        verticalSlider_pinkie_tip->setOrientation(Qt::Vertical);
        label_thumb_tip_slider = new QLabel(frame_16);
        label_thumb_tip_slider->setObjectName(QString::fromUtf8("label_thumb_tip_slider"));
        label_thumb_tip_slider->setGeometry(QRect(110, 175, 91, 20));
        label_thumb_tip_slider->setFont(font);
        label_index_tip_slider = new QLabel(frame_16);
        label_index_tip_slider->setObjectName(QString::fromUtf8("label_index_tip_slider"));
        label_index_tip_slider->setGeometry(QRect(190, 175, 91, 20));
        label_index_tip_slider->setFont(font);
        label_middle_tip_slider = new QLabel(frame_16);
        label_middle_tip_slider->setObjectName(QString::fromUtf8("label_middle_tip_slider"));
        label_middle_tip_slider->setGeometry(QRect(290, 175, 91, 20));
        label_middle_tip_slider->setFont(font);
        label_third_tip_slider = new QLabel(frame_16);
        label_third_tip_slider->setObjectName(QString::fromUtf8("label_third_tip_slider"));
        label_third_tip_slider->setGeometry(QRect(370, 175, 111, 20));
        label_third_tip_slider->setFont(font);
        label_pinkie_tip_slider = new QLabel(frame_16);
        label_pinkie_tip_slider->setObjectName(QString::fromUtf8("label_pinkie_tip_slider"));
        label_pinkie_tip_slider->setGeometry(QRect(470, 175, 111, 20));
        label_pinkie_tip_slider->setFont(font);

        gridLayout_4->addWidget(frame_16, 3, 0, 1, 6);

        frame_17 = new QFrame(frame_background_2);
        frame_17->setObjectName(QString::fromUtf8("frame_17"));
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);
        verticalSlider_thumb_rotation = new QSlider(frame_17);
        verticalSlider_thumb_rotation->setObjectName(QString::fromUtf8("verticalSlider_thumb_rotation"));
        verticalSlider_thumb_rotation->setGeometry(QRect(50, 0, 16, 166));
        verticalSlider_thumb_rotation->setOrientation(Qt::Vertical);
        label_thumb_rotation_slider = new QLabel(frame_17);
        label_thumb_rotation_slider->setObjectName(QString::fromUtf8("label_thumb_rotation_slider"));
        label_thumb_rotation_slider->setGeometry(QRect(15, 175, 111, 20));
        label_thumb_rotation_slider->setFont(font);

        gridLayout_4->addWidget(frame_17, 3, 6, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 4, 3, 2, 2);

        frame_14 = new QFrame(frame_background_2);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame_14->sizePolicy().hasHeightForWidth());
        frame_14->setSizePolicy(sizePolicy4);
        frame_14->setMinimumSize(QSize(750, 0));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        tableWidget_hand_data = new QTableWidget(frame_14);
        tableWidget_hand_data->setObjectName(QString::fromUtf8("tableWidget_hand_data"));
        tableWidget_hand_data->setGeometry(QRect(20, 20, 661, 221));
        sizePolicy3.setHeightForWidth(tableWidget_hand_data->sizePolicy().hasHeightForWidth());
        tableWidget_hand_data->setSizePolicy(sizePolicy3);
        tableWidget_hand_data->setMinimumSize(QSize(661, 221));
        tableWidget_hand_data->setMaximumSize(QSize(661, 221));
        tableWidget_hand_data->setFont(font);
        read_data = new QPushButton(frame_14);
        read_data->setObjectName(QString::fromUtf8("read_data"));
        read_data->setGeometry(QRect(20, 20, 121, 41));

        gridLayout_2->addWidget(frame_14, 0, 0, 3, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        TCP_Connect_Stop = new QPushButton(frame_background_2);
        TCP_Connect_Stop->setObjectName(QString::fromUtf8("TCP_Connect_Stop"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(164);
        sizePolicy5.setVerticalStretch(164);
        sizePolicy5.setHeightForWidth(TCP_Connect_Stop->sizePolicy().hasHeightForWidth());
        TCP_Connect_Stop->setSizePolicy(sizePolicy5);
        TCP_Connect_Stop->setMinimumSize(QSize(164, 164));
        TCP_Connect_Stop->setMaximumSize(QSize(164, 164));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Adobe \351\273\221\344\275\223 Std R"));
        font5.setPointSize(16);
        TCP_Connect_Stop->setFont(font5);
        TCP_Connect_Stop->setStyleSheet(QString::fromUtf8("##background-color:rgb(47,49,82);"));

        horizontalLayout->addWidget(TCP_Connect_Stop);

        TCP_Connect_Start = new QPushButton(frame_background_2);
        TCP_Connect_Start->setObjectName(QString::fromUtf8("TCP_Connect_Start"));
        sizePolicy5.setHeightForWidth(TCP_Connect_Start->sizePolicy().hasHeightForWidth());
        TCP_Connect_Start->setSizePolicy(sizePolicy5);
        TCP_Connect_Start->setMinimumSize(QSize(164, 164));
        TCP_Connect_Start->setMaximumSize(QSize(164, 164));
        TCP_Connect_Start->setFont(font5);
        TCP_Connect_Start->setStyleSheet(QString::fromUtf8("##background-color:rgb(47,49,82);"));

        horizontalLayout->addWidget(TCP_Connect_Start);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Ignored, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout, 7, 6, 1, 1);


        gridLayout->addWidget(frame_background_2, 0, 0, 1, 1);

        Robot_Hand_Ui->setCentralWidget(frame_background);
        menubar = new QMenuBar(Robot_Hand_Ui);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1800, 22));
        Robot_Hand_Ui->setMenuBar(menubar);

        retranslateUi(Robot_Hand_Ui);

        QMetaObject::connectSlotsByName(Robot_Hand_Ui);
    } // setupUi

    void retranslateUi(QMainWindow *Robot_Hand_Ui)
    {
        Robot_Hand_Ui->setWindowTitle(QApplication::translate("Robot_Hand_Ui", "Robot_Hand_Ui", nullptr));
        label_index_swing_slider->setText(QApplication::translate("Robot_Hand_Ui", "\351\243\237\346\214\207\344\276\247\346\221\206", nullptr));
        label_pinkie_swing_slider->setText(QApplication::translate("Robot_Hand_Ui", "\345\260\217\346\211\213\346\214\207\344\276\247\346\221\206", nullptr));
        label_thumb_swing_slider->setText(QApplication::translate("Robot_Hand_Ui", "\346\213\207\346\214\207\344\276\247\346\221\206", nullptr));
        label_third_swing_slider->setText(QApplication::translate("Robot_Hand_Ui", "\346\227\240\345\220\215\346\214\207\344\276\247\346\221\206", nullptr));
        label_middle_swing_slider->setText(QApplication::translate("Robot_Hand_Ui", "\344\270\255\346\214\207\344\276\247\346\221\206", nullptr));
        label_thumb_swing->setText(QApplication::translate("Robot_Hand_Ui", "\346\213\207\346\214\207", nullptr));
        button_thumb_swing_out->setText(QString());
        button_thumb_swing_in->setText(QString());
        label_index_swing->setText(QApplication::translate("Robot_Hand_Ui", "\351\243\237\346\214\207", nullptr));
        button_index_swing_out->setText(QString());
        button_index_swing_in->setText(QString());
        button_middle_swing_in->setText(QString());
        button_middle_swing_out->setText(QString());
        label_middle_swing->setText(QApplication::translate("Robot_Hand_Ui", "\344\270\255\346\214\207", nullptr));
        button_third_swing_in->setText(QString());
        button_third_swing_out->setText(QString());
        label_third_swing->setText(QApplication::translate("Robot_Hand_Ui", "\346\227\240\345\220\215\346\214\207", nullptr));
        label_pinkie_swing->setText(QApplication::translate("Robot_Hand_Ui", "\345\260\217\346\211\213\346\214\207", nullptr));
        button_pinkie_swing_out->setText(QString());
        button_pinkie_swing_in->setText(QString());
        Hand_Close->setText(QString());
        Hand_Open->setText(QString());
        label_allfinger->setText(QApplication::translate("Robot_Hand_Ui", "\344\272\224\346\214\207", nullptr));
        button_thumb_straight->setText(QString());
        button_thumb_roll->setText(QString());
        label_thumb->setText(QApplication::translate("Robot_Hand_Ui", "\346\213\207\346\214\207", nullptr));
        label_index->setText(QApplication::translate("Robot_Hand_Ui", "\351\243\237\346\214\207", nullptr));
        button_index_roll->setText(QString());
        button_index_straight->setText(QString());
        button_middle_roll->setText(QString());
        button_middle_straight->setText(QString());
        label_middle->setText(QApplication::translate("Robot_Hand_Ui", "\344\270\255\346\214\207", nullptr));
        button_third_roll->setText(QString());
        label_third->setText(QApplication::translate("Robot_Hand_Ui", "\346\227\240\345\220\215\346\214\207", nullptr));
        button_third_straight->setText(QString());
        button_pinkie_roll->setText(QString());
        label_pinkie->setText(QApplication::translate("Robot_Hand_Ui", "\345\260\217\346\211\213\346\214\207", nullptr));
        button_pinkie_straight->setText(QString());
        label_left_switch->setText(QApplication::translate("Robot_Hand_Ui", "\345\267\246\346\211\213", nullptr));
        label_right_switch->setText(QApplication::translate("Robot_Hand_Ui", "\345\217\263\346\211\213", nullptr));
        label_9deg_switch->setText(QApplication::translate("Robot_Hand_Ui", "9\350\207\252\347\224\261\345\272\246", nullptr));
        label_16deg_switch->setText(QApplication::translate("Robot_Hand_Ui", "16\350\207\252\347\224\261\345\272\246", nullptr));
        label_10deg_switch->setText(QApplication::translate("Robot_Hand_Ui", "10\350\207\252\347\224\261\345\272\246", nullptr));
        label_connect_state->setText(QApplication::translate("Robot_Hand_Ui", "\350\277\236\346\216\245\347\212\266\346\200\201", nullptr));
        label_index_roll_slider->setText(QApplication::translate("Robot_Hand_Ui", "\351\243\237\346\214\207\345\274\257\346\233\262", nullptr));
        label_thumb_roll_slider->setText(QApplication::translate("Robot_Hand_Ui", "\346\213\207\346\214\207\345\274\257\346\233\262", nullptr));
        label_middle_roll_slider->setText(QApplication::translate("Robot_Hand_Ui", "\344\270\255\346\214\207\345\274\257\346\233\262", nullptr));
        label_third_roll_slider->setText(QApplication::translate("Robot_Hand_Ui", "\346\227\240\345\220\215\346\214\207\345\274\257\346\233\262", nullptr));
        label_pinkie_roll_slider->setText(QApplication::translate("Robot_Hand_Ui", "\345\260\217\346\211\213\346\214\207\345\274\257\346\233\262", nullptr));
        label_thumb_tip_slider->setText(QApplication::translate("Robot_Hand_Ui", "\346\213\207\346\214\207\345\260\226", nullptr));
        label_index_tip_slider->setText(QApplication::translate("Robot_Hand_Ui", "\351\243\237\346\214\207\345\260\226", nullptr));
        label_middle_tip_slider->setText(QApplication::translate("Robot_Hand_Ui", "\344\270\255\346\214\207\345\260\226", nullptr));
        label_third_tip_slider->setText(QApplication::translate("Robot_Hand_Ui", "\346\227\240\345\220\215\346\214\207\345\260\226", nullptr));
        label_pinkie_tip_slider->setText(QApplication::translate("Robot_Hand_Ui", "\345\260\217\346\211\213\346\214\207\345\260\226", nullptr));
        label_thumb_rotation_slider->setText(QApplication::translate("Robot_Hand_Ui", "\346\213\207\346\214\207\347\272\265\346\221\206", nullptr));
        read_data->setText(QApplication::translate("Robot_Hand_Ui", "\350\257\273\345\217\226\346\225\260\346\215\256", nullptr));
        TCP_Connect_Stop->setText(QApplication::translate("Robot_Hand_Ui", "\345\201\234\346\255\242", nullptr));
        TCP_Connect_Start->setText(QApplication::translate("Robot_Hand_Ui", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Robot_Hand_Ui: public Ui_Robot_Hand_Ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOT_HAND_UI_H
