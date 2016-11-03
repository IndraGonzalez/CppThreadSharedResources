#pragma once

#include <QObject>
#include <QThread>

class Reader : public QThread
{
	Q_OBJECT

public:
	Reader(QObject *parent);

private:
	bool stopReading;
	struct Value
	{
		double time;
		double spinX;
		double spinY;
		double spinZ;
		double speedX;
		double speedY;
		double speedZ;
	};
	QList<Value> values;
	void writeDataFile();

protected:
	void run() Q_DECL_OVERRIDE;

};


