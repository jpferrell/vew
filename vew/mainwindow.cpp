#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_menubar(new QMenuBar(parent))
    , m_fileMenu(new QMenu("File"))
    , m_editMenu(new QMenu("Edit"))
    , m_filename()
{
    ui->setupUi(this);

    _SetupMenuBars();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_fileMenu;
    delete m_editMenu;
    delete m_menubar;
}

void MainWindow::OpenFile()
{
    m_filename = QFileDialog::getOpenFileName(this, tr("Open File"));
}

void MainWindow::_SetupMenuBars()
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
    connect(fileOpenAction, &QAction::triggered, this, &MainWindow::OpenFile);
}

