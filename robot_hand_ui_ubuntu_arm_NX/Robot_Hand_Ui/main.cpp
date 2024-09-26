#include "robot_hand_ui.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file(":/res/qss/style-1.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    a.setStyleSheet(stylesheet);
    if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
      QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling,true);
    Robot_Hand_Ui w;
    //w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();
    return a.exec();
}
