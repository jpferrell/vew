#include "qoptionswidget.h"

QOptionsWidget::QOptionsWidget(QWidget *parent)
    : QWidget{parent}
    , m_overallLayout(std::make_unique<QVBoxLayout>())
    , m_datatypeLabel(std::make_unique<QLabel>(parent))
    , m_datatypeComboBox(std::make_unique<QComboBox>(parent))
    , m_realCplxLabel(std::make_unique<QLabel>(parent))
    , m_realCplxComboBox(std::make_unique<QComboBox>(parent))
    , m_endianLabel(std::make_unique<QLabel>(parent))
    , m_endianComboBox(std::make_unique<QComboBox>(parent))
{
    this->setLayout(m_overallLayout.get());

    _InitializeLayouts();
    _InitializeComboBoxes();
    _InitializeLabels();
}

void QOptionsWidget::_InitializeLayouts()
{
    m_overallLayout->addWidget(m_datatypeLabel.get());
    m_overallLayout->addWidget(m_datatypeComboBox.get());
    m_overallLayout->addWidget(m_realCplxLabel.get());
    m_overallLayout->addWidget(m_realCplxComboBox.get());
    m_overallLayout->addWidget(m_endianLabel.get());
    m_overallLayout->addWidget(m_endianComboBox.get());
}

void QOptionsWidget::_InitializeLabels()
{
    m_datatypeLabel->setText(tr("Datatype"));
    m_datatypeLabel->setAlignment(Qt::AlignBottom);
    m_realCplxLabel->setText(tr("Real or Complex?"));
    m_realCplxLabel->setAlignment(Qt::AlignBottom);
    m_endianLabel->setText(tr("Endianness"));
    m_endianLabel->setAlignment(Qt::AlignBottom);
}

void QOptionsWidget::_InitializeComboBoxes()
{
    QList<QString> datatypeList{"32f", "64f", "8u", "16u", "32u", "64u", "8i", "16i", "32i", "64i"};
    QList<QString> realCplxList{"Complex", "Real"};
    QList<QString> endianList{"Big Endian", "Little Endian"};

    m_datatypeComboBox->addItems(datatypeList);
    m_realCplxComboBox->addItems(realCplxList);
    m_endianComboBox->addItems(endianList);
}
