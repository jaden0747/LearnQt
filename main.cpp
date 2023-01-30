#include <QtCore>
#include <QDebug>
#include <QGuiApplication>

#include "libs/AnalogClock/RasterWindow.h"

int main(int argc, char **argv)
{
    qInfo() << "Application started...";

    QGuiApplication app(argc, argv);

    RasterWindow window;
    window.show();

    return app.exec();
}