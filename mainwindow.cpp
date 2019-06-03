#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // lambda expression
    [](const QString& fileBatch) -> int
    {
        QProcess process;

        auto command = QString("cmd.exe");
        QStringList arguments;
        arguments << "/c" << "start /min" << fileBatch;

        process.startDetached(command, arguments);
        process.waitForFinished(-1);

        return process.exitCode();
    } ("test.bat");
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}
