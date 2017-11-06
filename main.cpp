#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setWindowIcon(QIcon(QPixmap(":/img/images/favicon.png")));

    QFile styleF;
    styleF.setFileName(":/qss/misc/style.css");
    styleF.open(QFile::ReadOnly);
    QString qssStr = styleF.readAll();
    qApp->setStyleSheet(qssStr);

    MainWindow w;
    w.show();

    return a.exec();
}
