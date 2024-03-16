#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QFileDialog>
#include <qspectrogram.h>
#include <qvariableplot.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    const int MAX_FFT_POWER = 16;
    const int MIN_FFT_POWER = 8;

public slots:

    void openFile();

signals:



private:
    Ui::MainWindow *ui;

    // Layouts
    QWidget *m_dummyWidget; // Dummy widget that is set to central widget to hold layout
    QHBoxLayout *m_overallLayout;
    QVBoxLayout *m_plotsLayout;
    QVBoxLayout *m_optionsLayout;

    //Plots
    QSpectrogram *m_spectrogramPlot;
    QVariablePlot *m_variablePlot;

    // Menu Bars
    QMenuBar *m_menubar;
    QMenu *m_fileMenu;
    QMenu *m_editMenu;

    // Combo Boxes
    QComboBox *m_fftComboBox;
    QComboBox *m_plotComboBox;

    // Labels
    QLabel *m_fftLabel;
    QLabel *m_plotLabel;

    QFile *m_file;
    QString m_filename;

    void _setupLayouts();
    void _setupMenuBars();
    void _setupComboBoxes();
    void _setupSliders();
    void _setupButtons();
    void _setupLineEdits();
    void _setupLabels();
};
#endif // MAINWINDOW_H
