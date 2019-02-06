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
    QByteArray input_buffer;
    QString out_result,out_type;


    QString filename =ui->path->text();
    QFile fileIn(filename);
            if(fileIn.open(QIODevice::ReadOnly))
            {

                bool ok;
                int i=0;
                QString Byte;
                Byte=fileIn.read(2);
                input_buffer[0]=Byte.toInt(&ok,16);
                i++;

                   while (!fileIn.atEnd())
                   {
                       Byte=fileIn.read(3);
                       input_buffer[i]=Byte.toInt(&ok,16);
                       i++;

                   }

            }
            else{

                QString buffer = ui->buffer_input->text();
                input_buffer = QByteArray::fromHex(buffer.toUtf8());

            }





    Parser::parse(input_buffer, out_result, out_type);
    Parser::parse_json(input_buffer);
    ui->pac_type->setText(out_type);
    ui->result->setText(out_result);


}

