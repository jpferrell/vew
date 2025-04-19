#include "qplotoptionswidget.h"

QPlotOptionsWidget::QPlotOptionsWidget(QWidget *parent)
    : QWidget{parent}
    , m_overallLayout(std::make_unique<QVBoxLayout>())
    , m_fftSizeLabel(std::make_unique<QLabel>(parent))
    , m_fftSizeComboBox(std::make_unique<QComboBox>(parent))
    , m_plotTypeLabel(std::make_unique<QLabel>(parent))
    , m_plotTypeComboBox(std::make_unique<QComboBox>(parent))
{
    this->setLayout(m_overallLayout.get());

    _InitializeLayouts();
    _InitializeComboBoxes();
    _InitializeLabels();
}

void QPlotOptionsWidget::_InitializeLayouts()
{
    m_overallLayout->addWidget(m_fftSizeLabel.get());
    m_overallLayout->addWidget(m_fftSizeComboBox.get());
    m_overallLayout->addWidget(m_plotTypeLabel.get());
    m_overallLayout->addWidget(m_plotTypeComboBox.get());
}

void QPlotOptionsWidget::_InitializeLabels()
{
    m_fftSizeLabel->setText(tr("FFT Size"));
    m_fftSizeLabel->setAlignment(Qt::AlignBottom);
    m_plotTypeLabel->setText(tr("Plot Type"));
    m_plotTypeLabel->setAlignment(Qt::AlignBottom);
}

void QPlotOptionsWidget::_InitializeComboBoxes()
{
    for (int i = MIN_FFT_POWER_SIZE; i < MAX_FFT_POWER_SIZE+1; i++) {
        m_fftSizeComboBox->addItem(QString::number(qPow(2, i)));
    }

    QList<QString> plotTypeList{tr("Time Series"), tr("FFT")};
    m_plotTypeComboBox->addItems(plotTypeList);
}
