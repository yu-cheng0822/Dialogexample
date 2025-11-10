#include "byterconver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ByterConver w;
    w.setWindowTitle("數系轉換器");
    w.show();
    return a.exec();
}
