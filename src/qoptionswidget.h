#ifndef QOPTIONSWIDGET_H
#define QOPTIONSWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>

#include <memory>

class QOptionsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QOptionsWidget(QWidget *parent = nullptr);
    QOptionsWidget(QOptionsWidget &src)=delete;
    QOptionsWidget operator=(QOptionsWidget &src)=delete;


signals:

private:

    std::unique_ptr<QVBoxLayout> m_overallLayout;

    std::unique_ptr<QLabel> m_datatypeLabel;
    std::unique_ptr<QComboBox> m_datatypeComboBox;
    std::unique_ptr<QLabel> m_realCplxLabel;
    std::unique_ptr<QComboBox> m_realCplxComboBox;
    std::unique_ptr<QLabel> m_endianLabel;
    std::unique_ptr<QComboBox> m_endianComboBox;

    void _InitializeLayouts();
    void _InitializeLabels();
    void _InitializeComboBoxes();
};

#endif // QOPTIONSWIDGET_H
