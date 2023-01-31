#include <QtCore>
#include <QDebug>
#include <QGuiApplication>

#include "libs/AnalogClock/RasterWindow.h"
#include "libs/AnalogClock/AnalogClockWindow.h"

int main(int argc, char **argv)
{
    qInfo() << "Application started...";

    QGuiApplication app(argc, argv);

    AnalogClockWindow window;
    window.show();

    return app.exec();
}