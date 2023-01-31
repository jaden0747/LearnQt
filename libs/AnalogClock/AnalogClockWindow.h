#pragma once
#include "RasterWindow.h"

class AnalogClockWindow : public RasterWindow
{
public:
    AnalogClockWindow();

protected:
    void timerEvent(QTimerEvent *event) override;
    void render(QPainter *p) override;

private:
    int m_timerId;
};
