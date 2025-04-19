#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QFileDialog>

#include <memory>

#include <qspectrogram.h>
#include <qvariableplot.h>
#include <qplotoptionswidget.h>
#include <qoptionswidget.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void openFile();

signals:



private:
    Ui::MainWindow *ui;

    // Layouts
    QWidget *m_dummyWidget; // Dummy widget that is set to central widget to hold layout
    QHBoxLayout *m_overallLayout;
    QVBoxLayout *m_plotsLayout;
    std::unique_ptr<QOptionsWidget> m_optionsWidget;
    std::unique_ptr<QPlotOptionsWidget> m_plotOptionsWidget;

    //Plots
    QSpectrogram *m_spectrogramPlot;
    QVariablePlot *m_variablePlot;

    // Menu Bars
    QMenuBar *m_menubar;
    QMenu *m_fileMenu;
    QMenu *m_editMenu;

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
