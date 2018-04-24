
#include "uidemo5.h"
#include "appinit.h"
#include "quiwidget.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QFont("Microsoft Yahei", 9));
    a.setWindowIcon(QIcon(":/main.ico"));
    AppInit::Instance()->start();
    UIDemo5 w;
    QUIWidget::setStyle(QUIWidget::Style_Black);
    w.show();

    return a.exec();
}
