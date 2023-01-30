#pragma once

#include <QtGui>

/**
 * @brief details in
 * https://doc.qt.io/qt-5/qtgui-rasterwindow-example.html
 */
class RasterWindow : public QWindow
{
    Q_OBJECT

public:
    explicit RasterWindow(QWindow *parent=0);
    
    /**
     * @brief QPainter provides highly optimized functions to do most of the drawing GUI
     * program require. It can draw everything from simple lines to complex shapes like pies
     * and chords. It can also draw aligned text and pixmaps.
     * 
     * - Normally it draws in a "natural" coordinate system, but it can also do view and world
     * transformation
     * 
     * - QPainter can operate on any object that inheris the `QPaintDevice` class
     * 
     * - The common use of `QPainter` is inside a widget's paint event: Construct and customize
     * (e.g. set the pen or the brush) the painter, then draw.
     * 
     * - Core functionality of `QPainter` is drawing, but the class also provide several functions that
     * allows you to customize `QPainter`'s settings and its rendering quality, and others that enable
     * clipping.
     * 
     * - The `isActive()` function indicates whether the painter is active. A painter is activated by the
     * `begin()` function and the constructor that takes a `QPaintDevice` argument. 
     * 
     * - The `end()` function, and the destructor, deactivates it
     * @param painter QPainter
     */
    virtual void render(QPainter *painter);

public slots:
    void renderLater();
    void renderNow();

protected:
    bool event(QEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;
    void exposeEvent(QExposeEvent *event) override;

private:
    /**
     * @brief a QBackingStore contains a buffered representation of the window contents, and thus
     * supports partial updates by using `QPainter` to only update a sub region of the window contents 
     */
    QBackingStore *m_backingStore;
};
