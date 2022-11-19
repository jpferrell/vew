#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qcustomplot.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize()
{
    // Create the FFT size options
    for (int i = 8; i < 15; i++) {
        ui->fftSizeComboBox->addItem(QString::number(pow(2, i)));
    }
    // Disable the FFT Size option until a file has been opened
    ui->fftSizeComboBox->setDisabled(true);
    QCPColorMap *colorMap = new QCPColorMap(ui->spectrogramPlotWidget->xAxis, ui->spectrogramPlotWidget->yAxis);
    colorMap->data()->setSize(50,50);
    colorMap->data()->setRange(QCPRange(0,2), QCPRange(0,2));
    //spell out VEW in the spectrogram
    for (int x = 0; x < 8; x++) {
        int y = -(50/8)*x + 49;
        colorMap->data()->setCell(x, y, 1);
    }
    for (int x = 8; x < 16; x++) {
        int y = (50/8)*(x-8);
        colorMap->data()->setCell(x, y, 1);
    }
    for (int y = 2; y < 48; y++) {
        colorMap->data()->setCell(19, y, 1);
    }
    for (int x = 19; x < 31; x++) {
        colorMap->data()->setCell(x, 48, 1);
        colorMap->data()->setCell(x, 2, 1);
        colorMap->data()->setCell(x, 25, 1);
    }
    for (int x = 33; x < 37; x++) {
        int y = -(50/4)*(x-33) + 49;
        colorMap->data()->setCell(x, y, 1);
    }
    for (int x = 37; x < 41; x++) {
        int y = (25/4)*(x-37);
        colorMap->data()->setCell(x, y, 1);
    }
    for (int x = 41; x < 45; x++) {
        int y = -(25/4)*(x-41) + 25;
        colorMap->data()->setCell(x, y, 1);
    }
    for (int x = 45; x < 49; x++) {
        int y = (50/4)*(x-45);
        colorMap->data()->setCell(x, y, 1);
    }
    colorMap->setGradient(QCPColorGradient::gpPolar);
    colorMap->rescaleDataRange(true);
    ui->spectrogramPlotWidget->rescaleAxes();
    ui->spectrogramPlotWidget->replot();

    ui->plotTypeComboBox->addItem("Time Domain (Real)");
    ui->plotTypeComboBox->addItem("Time Domain (Imag)");
    ui->plotTypeComboBox->addItem("FM Baud Rate");
    ui->plotTypeComboBox->addItem("FFT Squared");

}
