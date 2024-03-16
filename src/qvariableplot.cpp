#include "qvariableplot.h"

QVariablePlot::QVariablePlot()
{

}

void QVariablePlot::currentPlotChanged(int idx)
{
    Q_UNUSED(idx);
    qDebug() << "Plot changed";
}

void QVariablePlot::fftSizeChanged(int idx)
{
    Q_UNUSED(idx);
    qDebug() << "FFT Size Changed";
}
