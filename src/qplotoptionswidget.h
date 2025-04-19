#ifndef QPLOTOPTIONSWIDGET_H
#define QPLOTOPTIONSWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>

#include <memory>

class QPlotOptionsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QPlotOptionsWidget(QWidget *parent = nullptr);
    QPlotOptionsWidget(QPlotOptionsWidget &src)=delete;
    QPlotOptionsWidget& operator=(QPlotOptionsWidget &src)=delete;

    const qint8 MIN_FFT_POWER_SIZE = 4;
    const qint8 MAX_FFT_POWER_SIZE = 12;

signals:

private:

    std::unique_ptr<QVBoxLayout> m_overallLayout;

    std::unique_ptr<QLabel> m_fftSizeLabel;
    std::unique_ptr<QComboBox> m_fftSizeComboBox;
    std::unique_ptr<QLabel> m_plotTypeLabel;
    std::unique_ptr<QComboBox> m_plotTypeComboBox;

    void _InitializeLayouts();
    void _InitializeLabels();
    void _InitializeComboBoxes();
};

#endif // QPLOTOPTIONSWIDGET_H
