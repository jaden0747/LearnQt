#include "AnalogClockWindow.h"

AnalogClockWindow::AnalogClockWindow()
{
    setTitle("Analog Clock");
    resize(200, 200);
    m_timerId = startTimer(1000);
}


void AnalogClockWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_timerId) {
        renderLater();
    }
}


void AnalogClockWindow::render(QPainter *p)
{
    static const QPoint hourHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, 40)
    };

    static const QPoint minuteHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70)
    };

    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191); // 191 / 255 = 75% opaque

    // turn on antialiasing, makes drawing of diagonal lines much smoother
    p->setRenderHint(QPainter::Antialiasing);

    // moves the origin to the center of the window
    p->translate(width() / 2, height() / 2);

    // window size is 200x200, scale factor make sure that the clock 
    // fit within the length of the window's shortest side
    int side = qMin(width(), height());
    p->scale(side / 200.0, side / 200.0);

    // painter take care of the tranformations made during the rendering

    //* draw hour hand
    // set the pen to be `Qt::NoPen` because we don't want any outline
    p->setPen(Qt::NoPen);
    // brushes are used when filling in polygons and other geometric shapes
    p->setBrush(hourColor);

    QTime time = QTime::currentTime();

    // we save and restore the transformation matrix before and after the
    // rotation because we want to place the minute hand without having to 
    // take into account any previous rotations
    p->save();
    p->rotate(30.0 * ((time.hour() + time.minute() / 60)));
    p->drawConvexPolygon(hourHand, 3);
    p->restore();

    // draw markers around the edge of the clock for each hour
    // draw each marker then rotate the coordinate system so that the
    // painter is ready for the next one
    p->setPen(hourColor);
    for (int i = 0; i < 12; i++) {
        p->drawLine(88, 0, 96, 0);
        p->rotate(30.0);
    }

    p->setPen(Qt::NoPen);
    p->setBrush(minuteColor);
    p->save();
    p->rotate(6.0 * (time.minute() + time.second() / 60));
    p->drawConvexPolygon(minuteHand, 3);
    p->restore();

    p->setPen(minuteColor);

    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0) {
            p->drawLine(92, 0, 96, 0);
        }
        p->rotate(6.0);
    }
}