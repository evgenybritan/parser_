#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "parser/parser.h"
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>

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
void MainWindow::on_open_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                QString::fromUtf8("Открыть файsл"),
                                QDir::currentPath(),
                                "Hex (*.hex);;All files (*.*)");
    ui->path->setText(fileName);
}

void MainWindow::on_start_clicked()
{

    QString filename =ui->path->text();

    Parser::parse(filename /*, QByteArray byte_input*/);


}

