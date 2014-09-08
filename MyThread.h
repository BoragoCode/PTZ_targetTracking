#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <stdio.h>
#include <QtGlobal>
#include"info.h"
/*********************************/
/***********������*****************/
//ͨ���̳�QThread����ʵ���ڵ����߳����д��ڵĲ���
//��дrun����ʵ��
class MyThread : public QThread
{
	Q_OBJECT
public:
    MyThread();
    ~MyThread();
    QByteArray requestData;//�յ��Ļظ�����
    QByteArray TxData;//��������
    volatile bool rx_event;
    QString portnum;
    info information;
	void setMessage(const QString &message);
	void setPortnum(const QString &num);
	void stop();
	void startCom();
	void changeTxState(bool stat);
	void changeRxState(bool stat);
	void changeComState(bool stat);

signals:
	void request(const QString &s);
	void comRecive();



protected:
	void run();

private:
	QString messageStr;

	volatile bool com_opened;
	volatile bool stopped;
	volatile bool tx_event;

};

#endif // MYTHREAD_H
