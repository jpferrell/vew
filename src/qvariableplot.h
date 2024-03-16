#ifndef QVARIABLEPLOT_H
#define QVARIABLEPLOT_H

#include <QDebug>

#include <qcustomplot.h>
#include <qtimeseriesplot.h>

class QVariablePlot : public QCustomPlot
{
    Q_OBJECT
public:
    QVariablePlot();

public slots:

    void currentPlotChanged(int);
    void fftSizeChanged(int);

signals:

protected:

private:

    QTimeSeriesPlot *m_fftPlot;
    QTimeSeriesPlot *m_realPlot;
    QTimeSeriesPlot *m_imagPlot;
    QTimeSeriesPlot *m_powerPlot;
    QTimeSeriesPlot *m_constellationPlot;

};

#endif // QVARIABLEPLOT_H
