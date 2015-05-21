#include "qduino.h"
#include "ui_qduino.h"

Qduino::Qduino(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Qduino)
{
    ui->setupUi(this);
    arduino = new QSerialPort(this);
    baudRateList << "1200" << "2400" << "4800" << "9600" << "19200" << "38400" << "57600" << "115200";
    ports = QSerialPortInfo::availablePorts();
    QListIterator <QSerialPortInfo> iter(ports);
    QListIterator <QString> baudIter(baudRateList);
    while (iter.hasNext()){
        ui->comportBox->addItem(iter.next().portName());
    }

    while (baudIter.hasNext()){
        ui->baudrateBox->addItem(baudIter.next());
    }

    ui->baudrateBox->setCurrentText("9600");
    connect(ui->comportBox, SIGNAL(currentTextChanged(QString)), this, SLOT(setPortName()));
    connect(ui->baudrateBox, SIGNAL(currentTextChanged(QString)),this, SLOT(setBaudRate()));
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(connectArduino()));
    arduino->setPortName(currentPort);

}

Qduino::~Qduino()
{
    delete ui;
}


void Qduino::setPortName()
{
    currentPort = ui->comportBox->currentText();
    arduino->setPortName(currentPort);
}

void Qduino::setBaudRate()
{
    baudRate = (ui->baudrateBox->currentText()).toInt();
    //Debugging Purpose
    //QMessageBox::information(this, "Hello", ui->baudrateBox->currentText());
}

void Qduino::sendText()
{
    if (ui->textArea->text() == NULL) QMessageBox::information(this, "Empty Text Box", "Add some text then press button");
    if (!arduino->isOpen()) QMessageBox::information(this, "Connection Error", "The port is closed! Try again");
    else {
        text = ui->textArea->text().toLatin1();
        arduino->write(text);

    }

}




void Qduino::connectArduino()
{
    arduino->close();
    if (arduino->open(QIODevice::ReadWrite)){
        arduino->setBaudRate(baudRate);
        // 8bit mode
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        // Skipping hw/sw control
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        QMessageBox::information(this, "Connection Successful", "Successfully connected to " + currentPort);

    }
    else {
        QMessageBox::warning(this, "Failed", "Connection Failed");
    }
}


void Qduino::on_pushButton_clicked()
{
    sendText();
}

void Qduino::on_pushButton_2_clicked()
{
    if (arduino->isOpen()){
        arduino->write("c");
        ui->textArea->clear();
    }
}
