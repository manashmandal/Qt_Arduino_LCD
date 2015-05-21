#ifndef QDUINO_H
#define QDUINO_H

#include <QDialog>
#include <QtSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QString>
#include <QDebug>
#include <QList>
#include <QByteArray>
#include <QEvent>
#include <QKeyEvent>
#include <QMessageBox>


namespace Ui {
class Qduino;
}

class Qduino : public QDialog
{
    Q_OBJECT

public:
    explicit Qduino(QWidget *parent = 0);
    ~Qduino();


public slots:
    void setPortName();
    void setBaudRate();
    void connectArduino();
    void sendText();




private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Qduino *ui;
    QSerialPort *arduino;
    QString currentPort;
    QList <QString> baudRateList;
    QList <QSerialPortInfo> ports;
    QByteArray text;

   // void keyPressEvent(QKeyEvent *event);
    //void keyReleaseEvent(QKeyEvent *e);


    int baudRate;

};

#endif // QDUINO_H
