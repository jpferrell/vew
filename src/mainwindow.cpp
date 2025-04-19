#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_dummyWidget(new QWidget())
    , m_overallLayout(new QHBoxLayout())
    , m_plotsLayout(new QVBoxLayout())
    , m_optionsWidget(std::make_unique<QOptionsWidget>())
    , m_plotOptionsWidget(std::make_unique<QPlotOptionsWidget>())
    , m_spectrogramPlot(new QSpectrogram())
    , m_variablePlot(new QVariablePlot())
    , m_menubar(new QMenuBar(parent))
    , m_fileMenu(new QMenu("File"))
    , m_editMenu(new QMenu("Edit"))
    , m_file(NULL)
    , m_filename()
{
    ui->setupUi(this);

    _setupMenuBars();
    _setupLayouts();

    this->setMenuBar(m_menubar);

    // Connections
    //connect(m_plotComboBox, &QComboBox::currentIndexChanged, m_variablePlot, &QVariablePlot::currentPlotChanged);
    //connect(m_fftComboBox, &QComboBox::currentIndexChanged, m_variablePlot, &QVariablePlot::fftSizeChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_fileMenu;
    delete m_editMenu;
    delete m_menubar;
}

void MainWindow::openFile()
{
    m_filename = QFileDialog::getOpenFileName(this, tr("Open File"));
}

void MainWindow::_setupLayouts()
{
    m_plotsLayout->addWidget(m_spectrogramPlot);
    m_plotsLayout->addWidget(m_variablePlot);

    //m_overallLayout->addLayout(m_optionsLayout, 10);
    m_overallLayout->addWidget(m_plotOptionsWidget.get(), 10);
    m_overallLayout->addLayout(m_plotsLayout, 80);
    m_overallLayout->addWidget(m_optionsWidget.get());
    m_dummyWidget->setLayout(m_overallLayout);
    setCentralWidget(m_dummyWidget);
}

void MainWindow::_setupMenuBars()
{
    QAction *fileOpenAction = new QAction(tr("&Open"));
    QAction *fileCloseAction = new QAction(tr("&Close"));
    QAction *appExitAction = new QAction(tr("&Exit"));

    QAction *preferenceAction = new QAction(tr("&Preferences"));

    m_fileMenu->addAction(fileOpenAction);
    m_fileMenu->addAction(fileCloseAction);
    m_fileMenu->addAction(appExitAction);

    m_editMenu->addAction(preferenceAction);

    m_menubar->addMenu(m_fileMenu);
    m_menubar->addMenu(m_editMenu);

    this->setMenuBar(m_menubar);

    connect(appExitAction, &QAction::triggered, this, &QApplication::quit);
    connect(fileOpenAction, &QAction::triggered, this, &MainWindow::openFile);
}

void MainWindow::_setupSliders()
{

}

void MainWindow::_setupButtons()
{

}

void MainWindow::_setupLineEdits()
{

}
