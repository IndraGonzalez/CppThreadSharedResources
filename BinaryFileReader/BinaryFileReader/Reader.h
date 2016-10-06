#pragma once

#include <QObject>
#include <QThread>

class Reader : public QThread
{
	Q_OBJECT

public:
	Reader(QObject *parent);
	~Reader();

private:
	bool stopReading;
	struct Value
	{
		double time;
		int spinX;
		int spinY;
		int spinZ;
		int speedX;
		int speedY;
		int speedZ;
	};
	QList<Value> values;

protected:
	void run() Q_DECL_OVERRIDE;

public slots:
	void stop();
};


