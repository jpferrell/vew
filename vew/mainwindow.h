#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QFileDialog>

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

    void OpenFile();

signals:



private:
    Ui::MainWindow *ui;

    QMenuBar *m_menubar;
    QMenu *m_fileMenu;
    QMenu *m_editMenu;

    QString m_filename;

    void _SetupMenuBars();
};
#endif // MAINWINDOW_H
