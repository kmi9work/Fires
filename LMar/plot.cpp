#include "plot.h"

Plot::Plot(QWidget *parent):
    QwtPlot( parent )
{
    setAutoFillBackground( true );
    setPalette( QPalette( QColor( 165, 193, 228 ) ) );
    updateGradient();

    setTitle( "График аппроксимации" );
    insertLegend( new QwtLegend(), QwtPlot::RightLegend );

    // axes
    setAxisTitle( xBottom, "Температура -->" );
    setAxisScale( xBottom, 0.0, 10.0 );

    setAxisTitle( yLeft, "Функция принадлежности -->" );
    setAxisScale( yLeft, 0, 2 );

    // canvas
    QwtPlotCanvas *canvas = new QwtPlotCanvas();
    canvas->setLineWidth( 1 );
    canvas->setFrameStyle( QFrame::Box | QFrame::Plain );
    canvas->setBorderRadius( 15 );

    QPalette canvasPalette( Qt::white );
    canvasPalette.setColor( QPalette::Foreground, QColor( 133, 190, 232 ) );
    canvas->setPalette( canvasPalette );

    setCanvas( canvas );

    // panning with the left mouse button
    ( void ) new QwtPlotPanner( canvas );

    // zoom in/out with the wheel
    ( void ) new QwtPlotMagnifier( canvas );

    //  ...a horizontal line at y = 0...
    QwtPlotMarker *mY = new QwtPlotMarker();
    mY->setLabel( QString::fromLatin1( "y = 0" ) );
    mY->setLabelAlignment( Qt::AlignRight | Qt::AlignTop );
    mY->setLineStyle( QwtPlotMarker::HLine );
    mY->setYValue( 0.0 );
    mY->attach( this );

    //  ...a vertical line at x = 0
    QwtPlotMarker *mX = new QwtPlotMarker();
    mX->setLabel( QString::fromLatin1( "x = 0" ) );
    mX->setLabelAlignment( Qt::AlignLeft | Qt::AlignBottom );
    mX->setLabelOrientation( Qt::Vertical );
    mX->setLineStyle( QwtPlotMarker::VLine );
    mX->setLinePen( Qt::black, 0, Qt::DashDotLine );
    mX->setXValue( 0 );
    mX->attach( this );
}

double func_normal(double x, double n, double k){
    return 1-(fabs(x-n))/k;
}

double func_gauss(double x, double m){
    return exp(-M_PI *(x-m)*(x-m));
}

class NormData: public QwtSyntheticPointData
{
public:
    NormData(double nn, double kk): k(kk), n(nn), QwtSyntheticPointData(100){}
    virtual double y(double x) const
    {
        return 1-(fabs(x-n))/k;
    }
    double n,k;

};

class GaussData: public QwtSyntheticPointData
{
public:
    GaussData(double mm, double aa): m(mm), a(aa), QwtSyntheticPointData(100){}
    virtual double y(double x) const
    {
        return exp(-(x-m)*(x-m)/(2*a*a));
    }
    double m,a;

};

class ExpData: public QwtSyntheticPointData
{
public:
    ExpData(double mm, double aa): m(mm), a(aa), QwtSyntheticPointData(100){}
    virtual double y(double x) const
    {
        return 1/(1 + exp(-a*(x - m)));
    }
    double m,a;

};
/*
class NewData: public QwtSyntheticPointData
{
public:
    NewData(double mm, double aa): m(mm), a(aa), QwtSyntheticPointData(100){}
    virtual double y(double x) const
    {
        return 1/(1+fabs(pow((x-m)/a,2*a)));
    }
    double m,a;
};
*/

void Plot::drawDots(QVector< QVector<double> > data, int index)
{
    int j, l;
    QPolygonF points;
    QwtPlotCurve *curve;
    QwtSymbol *symbol;

    curve = new QwtPlotCurve("y = norm(x)");
    curve->setStyle( QwtPlotCurve::Dots );
    for (l = 0; l < data.size(); l++){
        points << QPointF(data[l][0], data[l][1]);
    }
    curve->setSamples(points);
    switch (index % 5){
    case 0:
        symbol = new QwtSymbol( QwtSymbol::Ellipse,
                                QBrush( Qt::yellow ), QPen( Qt::red, 1 ), QSize( 8, 8 ) );
        curve->setSymbol(symbol);
        break;
    case 1:
        symbol = new QwtSymbol( QwtSymbol::Ellipse,
                                QBrush( Qt::green ), QPen( Qt::red, 1 ), QSize( 8, 8 ) );
        curve->setSymbol(symbol);
        break;
    case 2:
        symbol = new QwtSymbol( QwtSymbol::Ellipse,
                                QBrush( Qt::cyan ), QPen( Qt::red, 1 ), QSize( 8, 8 ) );
        curve->setSymbol(symbol);
        break;
    case 3:
        symbol = new QwtSymbol( QwtSymbol::Ellipse,
                                QBrush( Qt::magenta ), QPen( Qt::red, 1 ), QSize( 8, 8 ) );
        curve->setSymbol(symbol);
        break;
    case 4:
        symbol = new QwtSymbol( QwtSymbol::Ellipse,
                                QBrush( Qt::gray ), QPen( Qt::red, 1 ), QSize( 8, 8 ) );
        curve->setSymbol(symbol);
        break;
    default:
        break;
    }
    curve->attach(this);
    this->replot();
}


void Plot::clear()
{
    this->detachItems();

    QwtPlotMarker *mY = new QwtPlotMarker();
    mY->setLabel( QString::fromLatin1( "y = 0" ) );
    mY->setLabelAlignment( Qt::AlignRight | Qt::AlignTop );
    mY->setLineStyle( QwtPlotMarker::HLine );
    mY->setYValue( 0.0 );
    mY->attach( this );

    //  ...a vertical line at x = 0
    QwtPlotMarker *mX = new QwtPlotMarker();
    mX->setLabel( QString::fromLatin1( "x = 0" ) );
    mX->setLabelAlignment( Qt::AlignLeft | Qt::AlignBottom );
    mX->setLabelOrientation( Qt::Vertical );
    mX->setLineStyle( QwtPlotMarker::VLine );
    mX->setLinePen( Qt::black, 0, Qt::DashDotLine );
    mX->setXValue( 0 );
    mX->attach( this );
}

void Plot::drawGauss(double m, double a, int type, int i)
{
    // Insert new curves
    int j;
    QwtPlotCurve *curve = new QwtPlotCurve("y = gauss(x)");
    if (type == 0){
        curve->setData(new GaussData(m, a));
    }else if (type == 1){
        curve->setData(new ExpData(m, a));
    }else{
        curve->setData(new ExpData(m, -a));
    }


    switch (i % 5) {
    case 0:
        curve->setPen(Qt::red);
        break;
    case 1:
        curve->setPen(Qt::green);
        break;
    case 2:
        curve->setPen(Qt::blue);
        break;
    case 3:
        curve->setPen(Qt::magenta);
        break;
    case 4:
        curve->setPen(Qt::cyan);
        break;
    default:
        break;
    }
    curve->attach(this);

    this->replot();
}

void Plot::updateGradient()
{
    QPalette pal = palette();

    const QColor buttonColor = pal.color( QPalette::Button );

    QLinearGradient gradient( rect().topLeft(), rect().bottomLeft() );
    gradient.setColorAt( 0.0, Qt::white );
    gradient.setColorAt( 0.7, buttonColor );
    gradient.setColorAt( 1.0, buttonColor );

    pal.setBrush( QPalette::Window, gradient );
    setPalette( pal );
}

void Plot::resizeEvent( QResizeEvent *event )
{
    QwtPlot::resizeEvent( event );
    // Qt 4.7.1: QGradient::StretchToDeviceMode is buggy on X11
    updateGradient();
}
