#ifndef PLOT_H
#define PLOT_H
#include <qlayout.h>
#include <qwt_plot.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_curve.h>
#include <qwt_legend.h>
#include <qwt_point_data.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_text.h>
#include <qwt_symbol.h>
#include <qwt_math.h>
#include <math.h>
#include <QVector>


class ArrowSymbol: public QwtSymbol
{
public:
    ArrowSymbol()
    {
        QPen pen( Qt::black, 0 );
        pen.setJoinStyle( Qt::MiterJoin );

        setPen( pen );
        setBrush( Qt::red );

        QPainterPath path;
        path.moveTo( 0, 8 );
        path.lineTo( 0, 5 );
        path.lineTo( -3, 5 );
        path.lineTo( 0, 0 );
        path.lineTo( 3, 5 );
        path.lineTo( 0, 5 );

        QTransform transform;
        transform.rotate( -30.0 );
        path = transform.map( path );

        setPath( path );
        setPinPoint( QPointF( 0, 0 ) );

        setSize( 10, 14 );
    }
};

class Plot : public QwtPlot
{
public:
    Plot(QWidget *parent = NULL);
    void drawGauss(double m, double a, int type, int i);
    //void drawDots(QVector<QVector<struct numCluster> > data, double n, double k, int index, int size, int number);
    void clear();
    void drawDots(QVector< QVector<double> > data, int index);
protected:
    virtual void resizeEvent( QResizeEvent * );

private:
    void updateGradient();
};

#endif // PLOT_H
